#include "Synth.h"
#include <time.h>
#include <stdlib.h>

OSStatus genSineWave(void* inRefCon,
                               AudioUnitRenderActionFlags* ioActionFlags,
                               const AudioTimeStamp*       inTimeStamp,
                               UInt32                      inBusNumber,
                               UInt32                      inNumberFrames,
                               AudioBufferList*            ioData)
{    	
    WaveInfo* waveInfo = (WaveInfo *)inRefCon;
    
	
	double targetFreq = waveInfo->targetFreq;
	double currentUnit = waveInfo->currentUnit;
	double phase = waveInfo->phase;	
	
	double ampTargetFreq = waveInfo->ampTargetFreq;
	double ampCurrentUnit = waveInfo->ampCurrentUnit;
	double ampPhase = waveInfo->ampPhase;

	
	//Calcultate an interval between samples for "targetFreq"
    float targetUnit = targetFreq * 2.0 * M_PI / waveInfo->sampleRate;
	float ampTargetUnit = ampTargetFreq * 2.0 * M_PI / waveInfo->sampleRate;
	
	
	AudioSampleType *out = ioData->mBuffers[0].mData;	
	
	
	// For each of the frames, calculate a value of the sample
	// and store it to the buffer pointed by "out".
	for (int i = 0; i< inNumberFrames; i++){
		float wave = 0.1f * sin(phase);
		float ampWave = sin(ampPhase);

		AudioSampleType sample = wave * 32767 * ampWave;
		// L
		*out++ = sample;
		// R
		*out++ = sample;
		
	
		phase = phase + currentUnit;
		//Icrease "currentUnit" to approach "targetUnit"
		currentUnit = 0.001 * targetUnit + 0.999 * currentUnit;
		
		ampPhase = ampPhase + ampCurrentUnit;
		ampCurrentUnit = 0.001 * ampTargetUnit + 0.999 * ampCurrentUnit;
	}
	
	
	waveInfo->currentUnit = currentUnit;
    waveInfo->phase = phase;
	waveInfo->ampCurrentUnit = ampCurrentUnit;
	waveInfo->ampPhase = ampPhase;
	srand(time(NULL));
	double freq = (rand() % 1000) / 4000.0;
	waveInfo->ampTargetFreq = freq;

    return noErr;
}