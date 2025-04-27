#import <Metal/Metal.h>
#import <MetalKit/MetalKit.h>
#import <Foundation/Foundation.h>
#import <mach-o/dyld.h>
#import <mach/mach.h>
#import <mach/mach_traps.h>

#import <thread>

#import "imgui.h"
#import "imgui_internal.h"

#import "antisocial.h"
#import "util/backend/imgui_impl_metal.h"

#import "memory_manager/memory_manager.hpp"

#import "globals.hpp"
#import "interface/interface.hpp"

#import "game/sdk/il2cpp/il2cpp.hpp"
#import "game/entities/entities.hpp"

#import "fonts/fonts.hpp"

#import "game/hooks/hooks.hpp"

#import "game/features/ragebot/ragebot.hpp"

#define is_ipa

#ifdef is_ipa
#import "dobby/dobby.hpp"
#import "dobby/dependencies/h5gg_hook.h"
#import "dobby/dependencies/mem.h"
#else
#import <substrate.h>
#endif

#pragma region cpp_defs
globals_t* g_ctx = new globals_t( );

uintptr_t memory_manager::get_base( )
{
    for ( int i = 0; i < _dyld_image_count( ); i++ )
    {
        const char* name = _dyld_get_image_name( i );
        if ( std::strstr( name, "UnityFramework.framework/UnityFramework" ) )
        {
            return static_cast< uintptr_t >( _dyld_get_image_vmaddr_slide( i ) );
        }
    }

    std::this_thread::sleep_for( std::chrono::milliseconds( 100 ) );

    return 0;
}

#ifdef is_ipa
#define static_inline_hook( x, y, z )                                                                                              \
    NSString* result_##y = StaticInlineHookPatch( "Frameworks/UnityFramework.framework/UnityFramework", x, nullptr, ( void* ) y ); \
    if ( result_##y )                                                                                                              \
    {                                                                                                                              \
        NSLog( @"hk result: %s", result_##y.UTF8String );                                                                          \
        void* result = StaticInlineHookFunction( "Frameworks/UnityFramework.framework/UnityFramework", x, ( void* ) y );           \
        NSLog( @"hk result %p", result );                                                                                          \
        *( void** ) ( z ) = ( void* ) result;                                                                                      \
    }
#endif

void memory_manager::hook( uintptr_t relative, void* hk, void** og )
{
    // relative cause ipa hooks finds it by itself
#ifdef is_ipa
    static_inline_hook( relative, hk, og );
#else
    // dobby is fucked up
    MSHookFunction( reinterpret_cast< void* >( memory_manager::get_absolute( relative ) ), hk, og );
#endif
}
#pragma endregion

@interface antisocial ( ) < MTKViewDelegate >
@property ( nonatomic, strong ) id< MTLDevice > device;
@property ( nonatomic, strong ) id< MTLCommandQueue > commandQueue;
@end

@implementation antisocial

- ( instancetype )initWithNibName:( nullable NSString* )nibNameOrNil bundle:( nullable NSBundle* )nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];

    _device = MTLCreateSystemDefaultDevice( );
    _commandQueue = [_device newCommandQueue];

    if ( !self.device )
        abort( );

    IMGUI_CHECKVERSION( );
    ImGui::CreateContext( );

    ImGui::StyleColorsClassic( );

    g_ctx->fonts->initialize( );

    ImGui_ImplMetal_Init( _device );

    g_ctx->interface->init( );
    g_ctx->features.init( );

    g_ctx->interface->m_queue.push_back( [] {
        c_players_database::get( )->update( );
    } );

    return self;
}

+ ( void )set_presented:( BOOL )value
{
    g_ctx->is_presented = value;
}

- ( MTKView* )mtkView
{
    return ( MTKView* ) self.view;
}

- ( void )loadView
{
    CGFloat w = [UIApplication sharedApplication].windows[ 0 ].rootViewController.view.frame.size.width;
    CGFloat h = [UIApplication sharedApplication].windows[ 0 ].rootViewController.view.frame.size.height;
    self.view = [[MTKView alloc] initWithFrame:CGRectMake( 0, 0, w, h )];
}

- ( void )viewDidLoad
{
    [super viewDidLoad];

    self.mtkView.device = self.device;
    self.mtkView.delegate = self;
    self.mtkView.clearColor = MTLClearColorMake( 0, 0, 0, 0 );
    self.mtkView.backgroundColor = [UIColor colorWithRed:0 green:0 blue:0 alpha:0];
    self.mtkView.clipsToBounds = YES;
    self.mtkView.preferredFramesPerSecond = 120;
}

#pragma mark - Interaction

- ( void )updateIOWithTouchEvent:( UIEvent* )event
{
    UITouch* any_touch = event.allTouches.anyObject;
    CGPoint touch_location = [any_touch locationInView:self.view];
    ImGuiIO& io = ImGui::GetIO( );
    io.MousePos = ImVec2( touch_location.x, touch_location.y );

    BOOL has_active_touch = NO;
    for ( UITouch* touch in event.allTouches )
    {
        if ( touch.phase != UITouchPhaseEnded && touch.phase != UITouchPhaseCancelled )
        {
            has_active_touch = YES;
            break;
        }
    }

    io.MouseDown[ 0 ] = has_active_touch;
}

- ( void )touchesBegan:( NSSet< UITouch* >* )touches withEvent:( UIEvent* )event
{
    [self updateIOWithTouchEvent:event];
}

- ( void )touchesMoved:( NSSet< UITouch* >* )touches withEvent:( UIEvent* )event
{
    [self updateIOWithTouchEvent:event];
}

- ( void )touchesCancelled:( NSSet< UITouch* >* )touches withEvent:( UIEvent* )event
{
    [self updateIOWithTouchEvent:event];
}

- ( void )touchesEnded:( NSSet< UITouch* >* )touches withEvent:( UIEvent* )event
{
    [self updateIOWithTouchEvent:event];
}

#pragma mark - MTKViewDelegate

- ( void )drawInMTKView:( MTKView* )view
{
    ImGuiIO& io = ImGui::GetIO( );

    io.DisplaySize.x = view.bounds.size.width;
    io.DisplaySize.y = view.bounds.size.height;

    CGFloat framebuffer_scale = view.window.screen.scale ?: UIScreen.mainScreen.scale;
    io.DisplayFramebufferScale = ImVec2( framebuffer_scale, framebuffer_scale );
    io.DeltaTime = 1 / float( view.preferredFramesPerSecond ?: 120 );

    id< MTLCommandBuffer > command_buffer = [self.commandQueue commandBuffer];

    [self.view setUserInteractionEnabled:g_ctx->is_presented];

    static dispatch_once_t init_token;
    dispatch_once( &init_token, ^{
      memory_manager::base = memory_manager::get_base( );
      if ( !memory_manager::base )
          init_token = 0;

      g_ctx->features.ragebot->m_doubletap_time_point = std::chrono::steady_clock::now( );

      g_ctx->il2cpp->initialize( );

      g_ctx->hooks->hook( );
    } );

    MTLRenderPassDescriptor* render_pass_descriptor = view.currentRenderPassDescriptor;
    if ( command_buffer != nil )
    {
        id< MTLRenderCommandEncoder > render_encoder = [command_buffer renderCommandEncoderWithDescriptor:render_pass_descriptor];
        [render_encoder pushDebugGroup:@"ImGui Jane"];

        ImGui_ImplMetal_NewFrame( render_pass_descriptor );

        ImGui::NewFrame( );

        g_ctx->interface->render( );

        ImGui::Render( );

        ImDrawData* draw_data = ImGui::GetDrawData( );
        ImGui_ImplMetal_RenderDrawData( draw_data, command_buffer, render_encoder );

        [render_encoder popDebugGroup];
        [render_encoder endEncoding];

        [command_buffer presentDrawable:view.currentDrawable];
    }

    [command_buffer commit];
}

- ( void )mtkView:( MTKView* )view drawableSizeWillChange:( CGSize )size
{
}

@end
