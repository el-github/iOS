#import <UIKit/UIKit.h>
#import "RemoteOutput.h"

@interface SynthViewController : UIViewController {
	RemoteOutput *remoteOutput;
}

- (IBAction) play:(id)sender;
- (IBAction) stop:(id)sender;
- (IBAction) setFreq:(UISlider *)sender;

@end

