//
//  GPUImageSixthInputFilter.h
//  mgushi
//
//  Created by Clear Hu on 13-9-10.
//  Copyright (c) 2013年 Lasque. All rights reserved.
//

#import "GPUImageFiveInputFilter.h"

extern NSString *const kGPUImageSixInputTextureVertexShaderString;

@interface GPUImageSixInputFilter : GPUImageFiveInputFilter
{
    GPUImageFramebuffer *sixInputFramebuffer;

    GLint filterSixthTextureCoordinateAttribute;
    GLint filterInputTextureUniform6;
    GPUImageRotationMode inputRotation6;
    GLuint filterSourceTexture6;
    CMTime sixthFrameTime;

    BOOL hasSetFifthTexture, hasReceivedSixthFrame, sixthFrameWasVideo;
    BOOL sixthFrameCheckDisabled;
}
- (void)disableSixthFrameCheck;
@end
