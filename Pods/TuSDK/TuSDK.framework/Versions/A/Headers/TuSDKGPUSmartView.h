//
//  TuSDKGPUSmartView.h
//  TuSDK
//
//  Created by Clear Hu on 15/10/13.
//  Copyright © 2015年 tusdk.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <GPUImage/GPUImage.h>

/**
 *  GPU智能视图
 */
@interface TuSDKGPUSmartView : UIView <GPUImageInput>
{
    GPUImageRotationMode inputRotation;
}

/** This calculates the current display size, in pixels, taking into account Retina scaling factors
 */
@property(readonly, nonatomic) CGSize sizeInPixels;

/**
 *  显示区域(百分比)
 */
@property(nonatomic) CGRect displayRect;

@property(nonatomic) BOOL enabled;

/** Handling fill mode
 
 @param redComponent Red component for background color
 @param greenComponent Green component for background color
 @param blueComponent Blue component for background color
 @param alphaComponent Alpha component for background color
 */
- (void)setBackgroundColorRed:(GLfloat)redComponent green:(GLfloat)greenComponent blue:(GLfloat)blueComponent alpha:(GLfloat)alphaComponent;

- (void)setCurrentlyReceivingMonochromeInput:(BOOL)newValue;
@end
