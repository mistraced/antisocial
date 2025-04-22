
#import "gestures.h"
#import <UIKit/UIKit.h>

#import "../antisocial.h"

@interface gestures ( )
@property ( nonatomic, strong ) antisocial* antisocial_view;
@end

@implementation gestures

static gestures* extra_info;
static UIWindow* main_window;

+ ( void )load
{
    [super load];

    dispatch_after( dispatch_time( DISPATCH_TIME_NOW, ( int64_t ) ( 3 * NSEC_PER_SEC ) ), dispatch_get_main_queue( ), ^{
      main_window = [UIApplication sharedApplication].keyWindow;
      extra_info = [gestures new];
      [extra_info init_open_gesture];
      [extra_info init_open_logic];
      [extra_info init_close_gesture];
      [extra_info init_close_logic];
    } );
}

- ( void )init_open_gesture
{
    UITapGestureRecognizer* tap = [[UITapGestureRecognizer alloc] init];
    tap.numberOfTapsRequired = 2;
    tap.numberOfTouchesRequired = 3;

    UIViewController* rootViewController = [UIApplication sharedApplication].keyWindow.rootViewController;
    [rootViewController.view addGestureRecognizer:tap];

    [tap addTarget:self action:@selector( init_open_logic )];
}

- ( void )init_close_gesture
{
    UITapGestureRecognizer* tap = [[UITapGestureRecognizer alloc] init];
    tap.numberOfTapsRequired = 2;
    tap.numberOfTouchesRequired = 2;

    UIViewController* rootViewController = [UIApplication sharedApplication].keyWindow.rootViewController;
    [rootViewController.view addGestureRecognizer:tap];

    [tap addTarget:self action:@selector( init_close_logic )];
}

- ( void )init_open_logic
{
    if ( !_antisocial_view )
    {
        antisocial* vc = [[antisocial alloc] init];
        _antisocial_view = vc;
    }

    [antisocial set_presented:true];
    [[UIApplication sharedApplication].windows[ 0 ].rootViewController.view addSubview:_antisocial_view.view];
}

- ( void )init_close_logic
{
    if ( !_antisocial_view )
    {
        antisocial* vc = [[antisocial alloc] init];
        _antisocial_view = vc;
    }

    [antisocial set_presented:false];
    [[UIApplication sharedApplication].windows[ 0 ].rootViewController.view addSubview:_antisocial_view.view];
}
@end
