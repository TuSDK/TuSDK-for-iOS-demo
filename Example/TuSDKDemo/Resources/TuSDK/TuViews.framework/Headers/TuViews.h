//
//  TuViews.h
//  TuViews
//
//  Created by abbeyant on 2021/3/3.
//

#import <Foundation/Foundation.h>

//! Project version number for TuViews.
FOUNDATION_EXPORT double TuViewsVersionNumber;

//! Project version string for TuViews.
FOUNDATION_EXPORT const unsigned char TuViewsVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <TuViews/PublicHeader.h>


#import <TuViews/TuStickerOnlineControllerBase.h>
#import <TuViews/TuStackFilterTableView.h>
#import <TuViews/TuPaintDrawViewBase.h>
#import <TuViews/TuCameraFilterGroupViewBase.h>
#import <TuViews/TuStackFilterBarBase.h>
#import <TuViews/TuFocusTouchViewBase.h>
#import <TuViews/TuEmptyView.h>
#import <TuViews/TuStickerLocalGridViewBase.h>
#import <TuViews/TuEditMultipleControllerBase.h>
#import <TuViews/TuImageResultOptions.h>
#import <TuViews/TuPagerView.h>
#import <TuViews/TuFilterStickerView.h>
#import <TuViews/TuStickerLocalControllerBase.h>
#import <TuViews/TuCameraPreviewControllerBase.h>
#import <TuViews/TuCameraViewControllerBase.h>
#import <TuViews/TuAlbumViewControllerBase.h>
#import <TuViews/TuStickerBarViewBase.h>
#import <TuViews/TuAlbumMultipleViewControllerBase.h>
#import <TuViews/TuPhotoPreviewControllerBase.h>
#import <TuViews/TuAlbumMultipleComponentBase.h>
#import <TuViews/TuTouchImageView.h>
#import <TuViews/TuEditCuterControllerBase.h>
#import <TuViews/TuEditTurnAndCutViewControllerBase.h>
#import <TuViews/TuEditStickerControllerBase.h>
#import <TuViews/TuSmudgeViewBase.h>
#import <TuViews/TuEditWipeAndFilterControllerBase.h>
#import <TuViews/TuFilterResultController.h>
#import <TuViews/TuGestureRecognizerView.h>
#import <TuViews/TuEditApertureControllerBase.h>
#import <TuViews/TuEditTabBarControllerBase.h>
#import <TuViews/TuEditFilterGroupViewBase.h>
#import <TuViews/TuEditFilterControllerBase.h>
#import <TuViews/TuEditSkinControllerBase.h>
#import <TuViews/TuBrushTableItemCellBase.h>
#import <TuViews/TuBrushBarViewBase.h>
#import <TuViews/TuEditSmudgeControllerBase.h>
#import <TuViews/TuEditAdjustControllerBase.h>
#import <TuViews/TuPhotoEditMultipleComponentBase.h>
#import <TuViews/TuAlertView.h>
#import <TuViews/TuFilterOnlineControllerBase.h>
#import <TuViews/TuCAEAGLView.h>
#import <TuViews/TuFilterConfigView.h>
#import <TuViews/TuResultViewController.h>

#import <TuViews/TuPhotosViewControllerBase.h>
#import <TuViews/TuEditVignetteControllerBase.h>
#import <TuViews/TuTextStickerView.h>
#import <TuViews/TuEditTextControllerBase.h>
#import <TuViews/TuEditSharpnessControllerBase.h>
#import <TuViews/TuEditHolyLightControllerBase.h>
#import <TuViews/TuEditHDRControllerBase.h>
#import <TuViews/TuEditEntryControllerBase.h>
#import <TuViews/TuAlbumComponentBase.h>
#import <TuViews/TuPhotoEditComponentBase.h>
#import <TuViews/TuImageResultController.h>
#import <TuViews/TuNavigationController.h>
#import <TuViews/TuPopupMessageInterface.h>
#import <TuViews/TuViewsConfigs.h>
#import <TuViews/TuCameraShower.h>
#import <TuViews/TuCameraShowerImpl.h>

/**
 *  SDK版本
 */
extern NSString * const lsqViewsVersion;

/**
 *  SDK打包时间
 */
extern NSString * const lsqViewsPackageTime;

@interface TuViews : NSObject
@property (nonatomic, retain) id<TuPopupMessageInterface> messageHub;

+ (TuViews *)shared;


@end
