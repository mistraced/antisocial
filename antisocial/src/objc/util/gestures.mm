
#import "gestures.h"
#import <UIKit/UIKit.h>

#import "../antisocial.h"

#import "game/features/misc/peek_assist/peek_assist.hpp"

#import "globals.hpp"

@interface gestures ( )
@property ( nonatomic, strong ) antisocial* antisocial_view;
@end

@implementation gestures

static bool ui_toggled = true;

static gestures* extra_info;
static UIWindow* main_window;

+ ( void )load
{
    [super load];

    dispatch_after( dispatch_time( DISPATCH_TIME_NOW, ( int64_t ) ( 3 * NSEC_PER_SEC ) ), dispatch_get_main_queue( ), ^{
      main_window = [UIApplication sharedApplication].keyWindow;
      extra_info = [gestures new];
      [extra_info init_menu_gesture];
      [extra_info init_menu_logic];
      [extra_info init_peek_gesture];
      [extra_info init_peek_logic];
    } );
}

- ( void )init_menu_gesture
{
    UITapGestureRecognizer* tap = [[UITapGestureRecognizer alloc] init];
    tap.numberOfTapsRequired = 2;
    tap.numberOfTouchesRequired = 3;

    UIViewController* rootViewController = [UIApplication sharedApplication].keyWindow.rootViewController;
    [rootViewController.view addGestureRecognizer:tap];

    [tap addTarget:self action:@selector( init_menu_logic )];
}

- ( void )init_menu_logic
{
    ui_toggled = !ui_toggled;

    if ( !_antisocial_view )
    {
        antisocial* vc = [[antisocial alloc] init];
        _antisocial_view = vc;
    }

    [antisocial set_presented:ui_toggled];
    [[UIApplication sharedApplication].windows[ 0 ].rootViewController.view addSubview:_antisocial_view.view];
}

- ( void )init_peek_gesture
{
    UITapGestureRecognizer* tap = [[UITapGestureRecognizer alloc] init];
    tap.numberOfTapsRequired = 2;
    tap.numberOfTouchesRequired = 2;

    UIViewController* rootViewController = [UIApplication sharedApplication].keyWindow.rootViewController;
    [rootViewController.view addGestureRecognizer:tap];

    [tap addTarget:self action:@selector( init_peek_logic )];
}

- ( void )init_peek_logic
{
    g_ctx->features.peek_assist->m_peeking = !g_ctx->features.peek_assist->m_peeking;
}
@end
