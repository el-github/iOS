#import "RemoteOutput.h"


#define CALLBACKFUNC genSawtoothWave

@implementation RemoteOutput


#pragma mark -
#pragma mark Object lifecycle

- (id)init{
    self = [super init];
    if (self != nil) {
		[self prepareAudioUnit];
	}
    return self;
}


- (void)dealloc{
    if(isPlaying) {
		AudioOutputUnitStop(audioUnit);
	}
    AudioUnitUninitialize(audioUnit);
    AudioComponentInstanceDispose(audioUnit);
    [super dealloc];
}


#pragma mark -
#pragma mark Preparing AudioUnit

- (void)prepareAudioUnit{    

	AudioComponentDescription cd;
    cd.componentType = kAudioUnitType_Output;
    cd.componentSubType = kAudioUnitSubType_RemoteIO; 
    cd.componentManufacturer = kAudioUnitManufacturer_Apple;
    cd.componentFlags = 0;
    cd.componentFlagsMask = 0;
    
	
    AudioComponent component = AudioComponentFindNext(NULL, &cd);
    
	
    AudioComponentInstanceNew(component, &audioUnit);
    
	
    AudioUnitInitialize(audioUnit);
    
	
	// Set a callback function
    AURenderCallbackStruct callbackStruct;
    callbackStruct.inputProc = CALLBACKFUNC;
	
	// Assign data to be referred to in the call back function
    callbackStruct.inputProcRefCon = &waveInfo;
    
	
	// Register the callback function to "audioUnit"
    AudioUnitSetProperty(audioUnit, 
                         kAudioUnitProperty_SetRenderCallback, 
                         kAudioUnitScope_Input,
                         0,
                         &callbackStruct,
                         sizeof(AURenderCallbackStruct));
	
	
	// Initialization of "waveInfo"
    waveInfo.sampleRate = 44100.0;
	waveInfo.phase = 0.0;
	[self setTargetFreq:440.0];
	waveInfo.currentUnit = 2.0 * M_PI * 440.0 / waveInfo.sampleRate;
	
	
	AudioStreamBasicDescription audioFormat;
	audioFormat = CanonicalASBD(waveInfo.sampleRate, 2);
	AudioUnitSetProperty(audioUnit,
                         kAudioUnitProperty_StreamFormat,
                         kAudioUnitScope_Input,
                         0,
                         &audioFormat,
                         sizeof(audioFormat));
	
	changeBufferSize(waveInfo.sampleRate, 256);
}


#pragma mark -
#pragma mark Play and Stop

- (void)play {
    if(!isPlaying) {
		AudioOutputUnitStart(audioUnit);
	}
    isPlaying = YES;
}


- (void)stop {
    if(isPlaying) {
		AudioOutputUnitStop(audioUnit);
	}
    isPlaying = NO;
}


#pragma mark -
#pragma mark Properties

- (BOOL)isPlaying {
    return isPlaying;
}


- (double)targetFreq {
	return waveInfo.targetFreq;
}


- (void)setTargetFreq:(double)targetFreq {
	waveInfo.targetFreq = targetFreq;
}

@end