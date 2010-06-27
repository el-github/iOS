#ifndef SYNTH_H
#define SYNTH_H


#include <AudioUnit/AudioUnit.h>
#include <AudioToolbox/AudioToolbox.h>


typedef struct WaveInfo {
	double phase;
    
	Float64 sampleRate;
	
	//Target frequency that is set by a slider UI
    double targetFreq;
	
	//Interval between samples for the current frequency
    double currentUnit;
} WaveInfo;


extern OSStatus genSawtoothWave(void*                       inRefCon,
							AudioUnitRenderActionFlags* ioActionFlags,
							const AudioTimeStamp*       inTimeStamp,
							UInt32                      inBusNumber,
							UInt32                      inNumberFrames,
							AudioBufferList*            ioData);

#endif