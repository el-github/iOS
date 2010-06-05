#import <UIKit/UIKit.h>

@class PerformSelectorViewController;

@interface PerformSelectorAppDelegate : NSObject <UIApplicationDelegate> {
    UIWindow *window;
    PerformSelectorViewController *viewController;
}

@property (nonatomic, retain) IBOutlet UIWindow *window;
@property (nonatomic, retain) IBOutlet PerformSelectorViewController *viewController;

@end

