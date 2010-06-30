#import <UIKit/UIKit.h>

@class SynthViewController;

@interface SynthAppDelegate : NSObject <UIApplicationDelegate> {
    UIWindow *window;
    SynthViewController *viewController;
}

@property (nonatomic, retain) IBOutlet UIWindow *window;
@property (nonatomic, retain) IBOutlet SynthViewController *viewController;

@end

