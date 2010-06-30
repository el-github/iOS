#import "SynthViewController.h"

@implementation SynthViewController


#pragma mark -
#pragma mark Object lifecycle
 // Implement viewDidLoad to do additional setup after loading the view, typically from a nib.
 - (void)viewDidLoad
{
	remoteOutput = [ [ RemoteOutput alloc ] init];
	[super viewDidLoad];
}


- (void)dealloc {
	[remoteOutput release];
    [super dealloc];
}


#pragma mark -
#pragma mark UI

- (IBAction)play:(id)sender
{
	[remoteOutput play];
}


- (IBAction)stop:(id)sender
{
	[remoteOutput stop];
}


- (IBAction)setFreq:(UISlider *)sender
{
	remoteOutput.targetFreq = sender.value;
}


#pragma mark -
#pragma mark Others

- (void)didReceiveMemoryWarning {
	// Releases the view if it doesn't have a superview.
    [super didReceiveMemoryWarning];
	
	// Release any cached data, images, etc that aren't in use.
}

- (void)viewDidUnload {
	// Release any retained subviews of the main view.
	// e.g. self.myOutlet = nil;
}




@end
