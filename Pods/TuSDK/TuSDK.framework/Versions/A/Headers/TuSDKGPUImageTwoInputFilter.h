//
//  TuSDKGPUImageTwoInputFilter.h
//  TuSDK
//
//  Created by Yanlin Qiu on 22/03/2017.
//  Copyright © 2017 tusdk.com. All rights reserved.
//

#import "TuSDKGPUImageFilter.h"

extern NSString *const lsqGPUTwoInputStickerVextexShaderString;

@interface TuSDKGPUImageTwoInputFilter : TuSDKGPUImageFilter
{
    GPUImageFramebuffer *secondInputFramebuffer;
    
    GLint filterSecondTextureCoordinateAttribute;
    GLint filterInputTextureUniform2;
    GPUImageRotationMode inputRotation2;
    CMTime firstFrameTime, secondFrameTime;
    
    BOOL hasSetFirstTexture, hasReceivedFirstFrame, hasReceivedSecondFrame, firstFrameWasVideo, secondFrameWasVideo;
    BOOL firstFrameCheckDisabled, secondFrameCheckDisabled;
}

- (void)disableFirstFrameCheck;
- (void)disableSecondFrameCheck;
@end
