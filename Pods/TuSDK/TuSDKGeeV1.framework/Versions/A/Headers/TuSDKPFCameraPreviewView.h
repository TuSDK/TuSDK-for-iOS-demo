//
//  TuSDKPFCameraPreviewView.h
//  TuSDKGeeV1
//
//  Created by wen on 14/09/2017.
//  Copyright © 2017 tusdk.com. All rights reserved.
//

#import <UIKit/UIKit.h>

@class TuSDKPFCameraPreviewView;

#pragma mark - TuSDKPFCameraPreviewViewDelegate
/**
 拍照预览View 事件代理
 */
@protocol TuSDKPFCameraPreviewViewDelegate <NSObject>

@optional

/**
 删除事件回调

 @param preview 预览View对象
 */
- (void)onTuSDKPFCameraPreviewViewDeleteEvent:(TuSDKPFCameraPreviewView *)preview;

/**
 确认事件回调

 @param preview 预览View对象
 */
- (void)onTuSDKPFCameraPreviewViewConfirmEvent:(TuSDKPFCameraPreviewView *)preview;

@end


#pragma mark - TuSDKPFCameraPreviewView
/**
 拍照预览View
 */
@interface TuSDKPFCameraPreviewView : UIView

/**
 *  事件委托
 */
@property (nonatomic, weak) id<TuSDKPFCameraPreviewViewDelegate> eventDelegate;

// 显示图片路径 
@property (nonatomic, strong) NSString *imagePath;
// 显示图片
@property (nonatomic, strong) UIImage *image;

@end
