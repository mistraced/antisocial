#import <Metal/Metal.h>
#import <MetalKit/MetalKit.h>
#import <Foundation/Foundation.h>

#import "imgui.h"
#import "imgui_internal.h"

#import "antisocial.h"
#import "util/backend/imgui_impl_metal.h"

@interface antisocial ( ) < MTKViewDelegate >
@property ( nonatomic, strong ) id< MTLDevice > device;
@property ( nonatomic, strong ) id< MTLCommandQueue > commandQueue;
@end

@implementation antisocial

static bool is_present = true;

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

    ImGui_ImplMetal_Init( _device );

    return self;
}

+ ( void )set_presented:( BOOL )value
{
    is_present = value;
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

    BOOL hasActiveTouch = NO;
    for ( UITouch* touch in event.allTouches )
    {
        if ( touch.phase != UITouchPhaseEnded && touch.phase != UITouchPhaseCancelled )
        {
            hasActiveTouch = YES;
            break;
        }
    }

    io.MouseDown[ 0 ] = hasActiveTouch;
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

    [self.view setUserInteractionEnabled:is_present];

    MTLRenderPassDescriptor* render_pass_descriptor = view.currentRenderPassDescriptor;
    if ( command_buffer != nil )
    {
        id< MTLRenderCommandEncoder > render_encoder = [command_buffer renderCommandEncoderWithDescriptor:command_buffer];
        [render_encoder pushDebugGroup:@"ImGui Jane"];

        ImGui_ImplMetal_NewFrame( command_buffer );

        ImGui::NewFrame( );

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
