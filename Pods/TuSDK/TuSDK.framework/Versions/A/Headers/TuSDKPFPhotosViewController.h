//
//  TuSDKPFPhotosViewController.h
//  TuSDK
//
//  Created by Clear Hu on 14/11/1.
//  Copyright (c) 2014年 Lasque. All rights reserved.
//

#import <AssetsLibrary/AssetsLibrary.h>
#import "TuSDKICViewController.h"
#import "TuSDKPFPhotosView.h"

@class TuSDKPFPhotosViewController;

/**
 *  相册照片列表控制器委托
 */
@protocol TuSDKPFPhotosDelegate <NSObject>

/**
 *  选中相片
 *
 *  @param controller 相册照片列表控制器
 *  @param asset      相片
 */
- (void)onTuSDKPFPhotos:(TuSDKPFPhotosViewController *)controller selectedAsset:(ALAsset *)asset;
@end

/**
 *  相册照片列表控制器
 */
@interface TuSDKPFPhotosViewController : TuSDKICViewController<TuSDKPFPhotosCellProtocol>{
@protected
    /**
     *  默认样式视图
     */
    TuSDKPFPhotosView *_defaultStyleView;
}
/**
 *  相册照片列表控制器委托
 */
@property (nonatomic, assign) id<TuSDKPFPhotosDelegate> delegate;

/**
 *  系统相册组
 */
@property (nonatomic, retain) ALAssetsGroup *group;

/**
 *  默认样式视图 (如果覆盖 buildDefaultStyleView 方法，实现了自己的视图，defaultStyleView == nil)
 */
@property (nonatomic, readonly) TuSDKPFPhotosView *defaultStyleView;

/**
 *  创建默认样式视图 (如需创建自定义视图，请覆盖该方法，并创建自己的视图类)
 */
- (void)buildDefaultStyleView;

/**
 *  通知获取一个相片
 *
 *  @param asset 相片
 */
- (void)notifySelectedAsset:(ALAsset *)asset;
@end
