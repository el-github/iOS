//
//  AppDelegate.h
//  test-oc
//
//  Created by tgmac on 2018/03/04.
//  Copyright © 2018年 tgmac. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AudioToolbox/AudioToolbox.h>

@interface AppDelegate : UIResponder <UIApplicationDelegate>

@property (strong, nonatomic) UIWindow *window;

@property (nonatomic, assign) AudioStreamBasicDescription streamFormat;
@property (nonatomic, assign) UInt32 bufferSize;
@property (nonatomic, assign) double currentFrequency;
@property (nonatomic, assign) double startingFrameCount;
@property (nonatomic, assign) AudioQueueRef	audioQueue;

-(OSStatus) fillBuffer: (AudioQueueBufferRef) buffer;

@end

#import <UIKit/UIKit.h>


//@interface CH10_iOSBackgroundingToneAppDelegate : NSObject <UIApplicationDelegate>

//@property (nonatomic, retain) IBOutlet UIWindow *window;
