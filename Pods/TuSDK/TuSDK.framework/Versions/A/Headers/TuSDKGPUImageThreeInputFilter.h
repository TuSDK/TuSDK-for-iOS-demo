//
//  TuSDKGPUImageThreeInputFilter.h
//  TuSDK
//
//  Created by Yanlin Qiu on 22/03/2017.
//  Copyright © 2017 tusdk.com. All rights reserved.
//

#import "TuSDKGPUImageTwoInputFilter.h"

extern NSString *const lsqGPUThreeInputStickerVextexShaderString;

@interface TuSDKGPUImageThreeInputFilter : TuSDKGPUImageTwoInputFilter
{
    GPUImageFramebuffer *thirdInputFramebuffer;
    
    GLint filterThirdTextureCoordinateAttribute;
    GLint filterInputTextureUniform3;
    GPUImageRotationMode inputRotation3;
    GLuint filterSourceTexture3;
    CMTime thirdFrameTime;
    
    BOOL hasSetSecondTexture, hasReceivedThirdFrame, thirdFrameWasVideo;
    BOOL thirdFrameCheckDisabled;
}

- (void)disableThirdFrameCheck;
@end
