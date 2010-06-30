#import <AudioUnit/AudioUnit.h>
#import <AudioToolbox/AudioToolbox.h>
#import "CoreAudioUtil.h"
#import "Synth.h"


@interface RemoteOutput : NSObject {
    AudioUnit audioUnit;
    BOOL isPlaying;
	WaveInfo waveInfo;
}


@property (nonatomic) double targetFreq;


- (void)play;
- (void)stop;
- (void)prepareAudioUnit;

@end