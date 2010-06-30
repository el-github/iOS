#include "CoreAudioUtil.h"

// Define an CanonicalASBD according to the args, and return it.
AudioStreamBasicDescription CanonicalASBD(Float64 sampleRate, 
                                          UInt32 channel)
{
    AudioStreamBasicDescription audioFormat;
    audioFormat.mSampleRate         = sampleRate;
    audioFormat.mFormatID           = kAudioFormatLinearPCM;
    audioFormat.mFormatFlags        = kAudioFormatFlagsCanonical;
    audioFormat.mChannelsPerFrame   = channel;
    audioFormat.mBytesPerPacket     = sizeof(AudioSampleType) * channel;
    audioFormat.mBytesPerFrame      = sizeof(AudioSampleType) * channel;
    audioFormat.mFramesPerPacket    = 1;
    audioFormat.mBitsPerChannel     = 8 * sizeof(AudioSampleType);
    audioFormat.mReserved           = 0;
    return audioFormat;
}


// Change the current buffer size
void changeBufferSize(Float64 sampleRate, int newSize)
{
	AudioSessionInitialize(NULL, NULL, NULL,NULL);
	Float32 currentDuration;
	UInt32 size = sizeof(Float32);
	
	//Get the current buffer size in seconds
	AudioSessionGetProperty(kAudioSessionProperty_CurrentHardwareIOBufferDuration, 
							&size, 
							&currentDuration);
	printf("currentDuration = %f\n",currentDuration);
	
	//the buffer size in the number of samples
	printf("frame size = %f\n", sampleRate * currentDuration);
	
	// Calculate a desired buffer size in seconds
	Float32 newDuration = newSize / sampleRate;
	printf("duration = %f\n", newDuration);

	// Set the buffer size
	size = sizeof(Float32);
	AudioSessionSetProperty(kAudioSessionProperty_PreferredHardwareIOBufferDuration, 
							size,
							&newDuration);
}