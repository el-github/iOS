#import "PerformSelectorViewController.h"

@implementation PerformSelectorViewController

@synthesize label;


// ----------------
// Clear the text of label
// ----------------
- (void)clearLabel {
	label.text = @"";
}


// ----------------
// Called when the button in the view is pressed.
// ----------------
- (IBAction)setLabel {
	label.text = @"This text is deleted after 2 seonds";
	[self performSelector:@selector(clearLabel) withObject:nil afterDelay:2.0];
}


- (void)didReceiveMemoryWarning {
	// Releases the view if it doesn't have a superview.
    [super didReceiveMemoryWarning];
	
	// Release any cached data, images, etc that aren't in use.
}


- (void)viewDidUnload {
	self.label = nil;
}


- (void)dealloc {
	[label release];
    [super dealloc];
}

@end
