#import <UIKit/UIKit.h>

@interface PerformSelectorViewController : UIViewController {
	// Associated with the label in the view
	UILabel *label;
}

@property (nonatomic, retain) IBOutlet UILabel *label;

// Associated with the button in the view
- (IBAction)setLabel;

@end

