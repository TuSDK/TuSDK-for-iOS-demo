//
//  TuSDKGPUBaseView.h
//  TuSDK
//
//  Created by Clear Hu on 16/4/10.
//  Copyright © 2016年 tusdk.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <GPUImage/GPUImage.h>

/**
 *  GPU Base View 
 */
@interface TuSDKGPUBaseView : UIView<GPUImageInput>
{
    GLProgram *displayProgram;
    CGSize inputImageSize;
    GPUImageRotationMode inputRotation;
}

/** This calculates the current display size, in pixels, taking into account Retina scaling factors
 */
@property(readonly, nonatomic) CGSize sizeInPixels;

@property(nonatomic) BOOL enabled;

- (void)setFragmentShader:(NSString *)fragmentShader;
- (void)setVertexShader:(NSString *)vertexShader fragmentShader:(NSString *)fragmentShader;

/** Handling fill mode
 
 @param redComponent Red component for background color
 @param greenComponent Green component for background color
 @param blueComponent Blue component for background color
 @param alphaComponent Alpha component for background color
 */
- (void)setBackgroundColorRed:(GLfloat)redComponent green:(GLfloat)greenComponent blue:(GLfloat)blueComponent alpha:(GLfloat)alphaComponent;

- (void)setCurrentlyReceivingMonochromeInput:(BOOL)newValue;

- (void)initView;

- (void)recalculateViewGeometry;
@end
