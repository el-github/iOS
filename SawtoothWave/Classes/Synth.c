#include "Synth.h"

OSStatus genSawtoothWave(void* inRefCon,
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
	int numOfHarmonics = 100;
	
	//Calcultate an interval between samples for "targetFreq"
    float targetUnit = targetFreq * 2.0 * M_PI / waveInfo->sampleRate;
	
	
	AudioSampleType *out = ioData->mBuffers[0].mData;	
	
	
	// For each of the frames, calculate a value of the sample
	// and store it to the buffer
	for (int i = 0; i< inNumberFrames; i++)
	{
		float wave = 0.0f;
		for(int j = 1; j < numOfHarmonics + 1; j++)
		{
			wave += (0.1/j) * sin( (phase * j) );
		}
		
		
		AudioSampleType sample = wave * 32767;
		// L
		*out++ = sample;
		// R
		*out++ = sample;
		
		phase = phase + currentUnit;
		
		//Icrease "currentUnit" to approach "targetUnit"
		currentUnit = 0.001 * targetUnit + 0.999 * currentUnit;
	}
	
	waveInfo->currentUnit = currentUnit;
    waveInfo->phase = phase;

    return noErr;
}