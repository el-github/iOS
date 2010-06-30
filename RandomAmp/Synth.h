#ifndef SYNTH_H
#define SYNTH_H


#include <AudioUnit/AudioUnit.h>
#include <AudioToolbox/AudioToolbox.h>


typedef struct WaveInfo {
	Float64 sampleRate;
	
	double phase;
	//Target frequency that is set by a slider UI
    double targetFreq;
	//Interval between samples for the current frequency
    double currentUnit;
	
	double ampPhase;
	double ampTargetFreq;
	double ampCurrentUnit;	
} WaveInfo;


extern OSStatus genSineWave(void*                       inRefCon,
                               AudioUnitRenderActionFlags* ioActionFlags,
                               const AudioTimeStamp*       inTimeStamp,
                               UInt32                      inBusNumber,
                               UInt32                      inNumberFrames,
                               AudioBufferList*            ioData);

#endif