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


#import "TuStickerOnlineControllerBase.h"
#import "TuStackFilterTableView.h"
#import "TuPaintDrawViewBase.h"
#import "TuCameraFilterGroupViewBase.h"
#import "TuStackFilterBarBase.h"
#import "TuFocusTouchViewBase.h"
#import "TuEmptyView.h"
#import "TuStickerLocalGridViewBase.h"
#import "TuEditMultipleControllerBase.h"
#import "TuImageResultOptions.h"
#import "TuPagerView.h"
#import "TuFilterStickerView.h"
#import "TuStickerLocalControllerBase.h"
#import "TuCameraPreviewControllerBase.h"
#import "TuCameraViewControllerBase.h"
#import "TuAlbumViewControllerBase.h"
#import "TuStickerBarViewBase.h"
#import "TuAlbumMultipleViewControllerBase.h"
#import "TuPhotoPreviewControllerBase.h"
#import "TuAlbumMultipleComponentBase.h"
#import "TuTouchImageView.h"
#import "TuEditCuterControllerBase.h"
#import "TuEditTurnAndCutViewControllerBase.h"
#import "TuEditStickerControllerBase.h"
#import "TuSmudgeViewBase.h"
#import "TuEditWipeAndFilterControllerBase.h"
#import "TuFilterResultController.h"
#import "TuGestureRecognizerView.h"
#import "TuEditApertureControllerBase.h"
#import "TuEditTabBarControllerBase.h"
#import "TuEditFilterGroupViewBase.h"
#import "TuEditFilterControllerBase.h"
#import "TuEditSkinControllerBase.h"
#import "TuBrushTableItemCellBase.h"
#import "TuBrushBarViewBase.h"
#import "TuEditSmudgeControllerBase.h"
#import "TuEditAdjustControllerBase.h"
#import "TuPhotoEditMultipleComponentBase.h"
#import "TuAlertView.h"
#import "TuFilterOnlineControllerBase.h"
#import "TuCAEAGLView.h"
#import "TuFilterConfigView.h"
#import "TuResultViewController.h"

#import "TuPhotosViewControllerBase.h"
#import "TuEditVignetteControllerBase.h"
#import "TuTextStickerView.h"
#import "TuEditTextControllerBase.h"
#import "TuEditSharpnessControllerBase.h"
#import "TuEditHolyLightControllerBase.h"
#import "TuEditHDRControllerBase.h"
#import "TuEditEntryControllerBase.h"
#import "TuAlbumComponentBase.h"
#import "TuPhotoEditComponentBase.h"
#import "TuImageResultController.h"
#import "TuNavigationController.h"
#import "TuPopupMessageInterface.h"
#import "TuViewsConfigs.h"
#import "TuCameraShower.h"
#import "TuCameraShowerImpl.h"


@interface TuViews : NSObject
@property (nonatomic, retain) id<TuPopupMessageInterface> messageHub;

+ (TuViews *)shared;


@end
