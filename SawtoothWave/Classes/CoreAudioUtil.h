#ifndef __CoreAudioUtil_h__
#define __CoreAudioUtil_h__

#include <AudioToolbox/AudioToolbox.h>

// Define an CanonicalASBD according to the args, and return it.
extern AudioStreamBasicDescription CanonicalASBD(Float64 sampleRate, 
                                                 UInt32 channel);

// Change the current buffer size
void changeBufferSize(Float64 sampleRate, int newSize);

#endif

