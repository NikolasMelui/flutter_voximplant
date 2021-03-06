/*
* Copyright (c) 2011-2020, Zingaya, Inc. All rights reserved.
*/

#import <Flutter/Flutter.h>
#import <VoxImplant/VoxImplant.h>

@interface VoximplantUtils : NSObject 

+ (NSString *)convertLoginErrorToString:(VILoginErrorCode)code;
+ (NSString *)getErrorDescriptionForLoginError:(VILoginErrorCode)code;
+ (NSString *)convertCallErrorToString:(VICallErrorCode)code;
+ (NSString *)getErrorDescriptionForCallError:(VICallErrorCode)code;
+ (NSString *)convertMessagingErrorToString:(VIErrorEvent *)error;
+ (NSString *)convertAudioFileErrorToString:(VIAudioFileErrorCode)audioFileError;
+ (NSDictionary *)convertAuthParamsToDictionary:(VIAuthParams *)authParams;
+ (NSNumber *)convertVideoStreamTypeToNumber:(VIVideoStreamType)type;
+ (int)convertVideoRotationToInt:(RTCVideoRotation)rotation;
+ (BOOL)isBackCameraByCameraType:(NSNumber *)cameraType;

@end


typedef NSString *VIMethodType NS_TYPED_ENUM;
static VIMethodType const VIMethodTypeMessaging = @"Messaging";
static VIMethodType const VIMethodTypeClient= @"Client";
static VIMethodType const VIMethodTypeAudioDevice = @"AudioDevice";
static VIMethodType const VIMethodTypeAudioFile = @"AudioFile";
static VIMethodType const VIMethodTypeCall = @"Call";
static VIMethodType const VIMethodTypeCamera = @"Camera";
static VIMethodType const VIMethodTypeVideoStream = @"VideoStream";


@interface FlutterMethodCall (MethodType)

- (BOOL)isMethodCallOfType:(VIMethodType)type;
- (FlutterMethodCall *)excludingType;

@end

@interface NSNumber (FromTimeInterval)

+ (instancetype)fromTimeInterval:(NSTimeInterval)timeInterval;

@end
