//
//  JigsawSampleController.m
//  TuSDKDemo
//
//  Created by 言有理 on 2021/7/19.
//  Copyright © 2021 tusdk.com. All rights reserved.
//

#import "JigsawSampleController.h"
#import <TuSDKPulseFilter/TuSDKPulseFilter.h>
#import <TuSDKPulseCore/TuSDKPulseCore.h>
#import <TuSDKGeeV1/TuSDKCPFilterResultView.h>
#import <SSZipArchive.h>
#import "FCFileManager.h"
#import <TuSDKGeeV1/TuSDKGeeV1.h>
#import "JigsawLayerView.h"
static int const kFilterIndex = 100;
@interface JigsawSampleController ()
@property(nonatomic, strong) TuSDKPFEditFilterBottomBar *tabBar;
/// 显示图层
@property(nonatomic, strong) TUPFPDisplayView *displayView;
@property(nonatomic, strong) TUPFilterPipe *pipe;
@property(nonatomic, strong) NSArray<NSString *> *sandboxPaths;
@property(nonatomic, strong) TUPThread *pipeThread;
@property(nonatomic, strong) TUPFPImage *inputImage;
@property(nonatomic, assign) CGSize mCurrentRenderSize;

@property(nonatomic, strong) TUPFPJigsawFilter_PropertyBuilder *mCurrentBuilder;
@property(nonatomic, assign) NSInteger mCurrentLayerIndex;
@property(nonatomic, strong) TuSDKCPAlbumComponent *albumComponent;
@property(nonatomic, strong) UIView *menuView;
@property(nonatomic, strong) UIButton *ratioButton;
@property(nonatomic, strong) UIButton *borderButton;
@property(nonatomic, assign) TTRatioType mCurrentRatioType;
@property(nonatomic, strong) JigsawLayerView *mLayerView;
@property(nonatomic, strong) NSArray <NSString *> *borderItems;
@property(nonatomic, assign) NSInteger borderIndex;
@end

@implementation JigsawSampleController

- (void)viewDidLoad {
    self.saveToAlbum = YES;
    self.waterMarkOption = [self waterMarkOption];
    [super viewDidLoad];
    
    [self setupSandbox];
    [self setupView];
    [self setupPipe];
    [self initJigsawFilter:0 updateProperty:NO];
}
- (void)dealloc {
    [self destory];
}
- (void)destory {
    [_pipeThread sync:^{
        [self.pipe clearFilters];
        [self.pipe close];
        self.pipe = nil;
    }];
    [_displayView teardown];
    _displayView = nil;
    [_pipeThread clear];
    _pipeThread = nil;
}
- (void)setupSandbox {
    NSArray *exArrs = @[@"jigsaw_ex",@"jigsaw_ex3",@"jigsaw_ex2"];
    NSMutableArray *arrs = [NSMutableArray array];
    for (NSString *name in exArrs) {
        NSString *bundlePath = [[NSBundle mainBundle] pathForResource:name ofType:@"zip"];
        NSString *sandboxDirectory = [FCFileManager pathForDocumentsDirectoryWithPath:@"jigsaw"];
        [FCFileManager createDirectoriesForPath:sandboxDirectory];
        NSString *sandboxPath = [sandboxDirectory stringByAppendingPathComponent:name];
        if (![FCFileManager existsItemAtPath:sandboxPath]) {
            [SSZipArchive unzipFileAtPath:bundlePath toDestination:sandboxPath];
        }
        [arrs addObject:sandboxPath];
    }
    self.sandboxPaths = [arrs copy];
}
- (void)setupView {
    CGFloat kTabBarHeight = 49;
    
    _tabBar = [TuSDKPFEditFilterBottomBar initWithFrame:CGRectMake(0, [self.view lsqGetSizeHeight] - kTabBarHeight - [UIDevice lsqSafeAreaBottom], self.view.lsqGetSizeWidth, kTabBarHeight)];
    [self.view addSubview:_tabBar];
    [_tabBar.cancelButton addTouchUpInsideTarget:self action:@selector(lsqBackActionHadAnimated)];
    [_tabBar.completeButton addTouchUpInsideTarget:self action:@selector(saveAction)];
    
    UIView *contentView = [[UIView alloc] initWithFrame:CGRectMake(0, CGRectGetMinY(_tabBar.frame) - (49 + 75 + 49), self.view.lsqGetSizeWidth, 49 + 75 + 49)];
    contentView.backgroundColor = [UIColor grayColor];
    [self.view addSubview:contentView];
    
    // 显示图层
    _displayView = [[TUPFPDisplayView alloc] init];
    CGFloat y = ([UIDevice lsqIsDeviceiPhoneX] ? 44 : 20);
    _displayView.frame = CGRectMake(0, y, [self.view lsqGetSizeWidth], CGRectGetMinY(contentView.frame) - y);
    _displayView.translatesAutoresizingMaskIntoConstraints = NO;
    [_displayView setup];
    [self.view addSubview:_displayView];
    
    _mLayerView = [[JigsawLayerView alloc] initWithFrame:_displayView.frame];
    __weak __typeof(self)weakSelf = self;
    _mLayerView.updatePropertyBlock = ^{
        [weakSelf updatepProperty];
    };
    _mLayerView.updateIndexBlock = ^(NSInteger index) {
        for (int i = 0; i < weakSelf.mCurrentBuilder.holder.layerInfos.count; i++) {
            if (weakSelf.mCurrentBuilder.holder.layerInfos[i].index == index) {
                weakSelf.mCurrentLayerIndex = i;
                break;
            }
        }
    };
    [self.view addSubview:_mLayerView];
    
    _menuView = [[UIView alloc] initWithFrame:CGRectMake(0, 0, contentView.frame.size.width, 49)];
    _menuView.layer.borderWidth = 1;
    _menuView.layer.borderColor = UIColor.blueColor.CGColor;
    _menuView.hidden = YES;
    [contentView addSubview:_menuView];
    
    UIButton *borderButton = [UIButton buttonWithType:UIButtonTypeCustom];
    [borderButton setTitle:@"边框" forState:UIControlStateNormal];
    borderButton.titleLabel.font = [UIFont systemFontOfSize:14];
    [borderButton setTitleColor:[UIColor whiteColor] forState:0];
    borderButton.frame = CGRectMake(0, 0, contentView.lsqGetSizeWidth/2, 49);
    [borderButton addTarget:self action:@selector(borderAction:) forControlEvents:UIControlEventTouchUpInside];
    [_menuView addSubview:borderButton];
    _borderButton = borderButton;
    
    UIButton *ratioButton = [UIButton buttonWithType:UIButtonTypeCustom];
    [ratioButton setTitle:@"1:1" forState:UIControlStateNormal];
    ratioButton.titleLabel.font = [UIFont systemFontOfSize:14];
    [ratioButton setTitleColor:[UIColor whiteColor] forState:0];
    ratioButton.frame = CGRectMake(contentView.lsqGetSizeWidth/2, 0, contentView.lsqGetSizeWidth/2, 49);
    [ratioButton addTarget:self action:@selector(ratioAction:) forControlEvents:UIControlEventTouchUpInside];
    [_menuView addSubview:ratioButton];
    _ratioButton = ratioButton;
    
    UIView *interactionView = [[UIView alloc] initWithFrame:CGRectMake(0, 49, self.view.lsqGetSizeWidth, 75)];
    [contentView addSubview:interactionView];
    NSArray *intTitles = @[@"替换",@"旋转",@"镜像",@"翻转"];
    NSArray *intImages = @[@"style_default_edit_icon_original",@"style_default_edit_button_trun_left",@"style_default_edit_button_horizontal_mirror",@"style_default_edit_button_vertical_mirror"];
    CGFloat buttonWidth1 = [contentView lsqGetSizeWidth] / 4;
    for (int i = 0; i < 4; i++) {
        UIButton *button = [UIButton buttonWithFrame:CGRectMake(i * buttonWidth1, 0, buttonWidth1, 75)
                              imageLSQBundleNamed:intImages[i]];
        [button setTitle:intTitles[i] forState:UIControlStateNormal];
        button.titleLabel.font = [UIFont systemFontOfSize:14];
        button.tag = i;
        [button setTitleColor:[UIColor whiteColor] forState:0];
        [button addTarget:self action:@selector(interactionAction:) forControlEvents:UIControlEventTouchUpInside];
        [interactionView addSubview:button];
        CGFloat offset = 10.0f;
        button.titleEdgeInsets = UIEdgeInsetsMake(0, -button.imageView.frame.size.width, -button.imageView.frame.size.height-offset/2, 0);
        // 由于iOS8中titleLabel的size为0，用上面这样设置有问题，修改一下即可
        button.imageEdgeInsets = UIEdgeInsetsMake(-button.titleLabel.intrinsicContentSize.height-offset/2, 0, 0, -button.titleLabel.intrinsicContentSize.width);
    }
    
    NSArray *array = @[@"海报", @"多格", @"拼接"];
    CGFloat buttonWidth = [contentView lsqGetSizeWidth] / array.count;
    for (int i = 0; i < array.count; i++) {
        UIButton *button = [UIButton buttonWithType:UIButtonTypeCustom];
        button.frame = CGRectMake(i * buttonWidth, CGRectGetMaxY(interactionView.frame), buttonWidth, 49);
        [button setTitle:array[i] forState:UIControlStateNormal];
        button.tag = i;
        [button setTitleColor:[UIColor whiteColor] forState:0];
        [button addTarget:self action:@selector(switchTypeAction:) forControlEvents:UIControlEventTouchUpInside];
        [contentView addSubview:button];
    }
    
}
- (void)setupPipe {
    _pipeThread = [[TUPThread alloc] init];
    [_pipeThread async:^{
        self.pipe = [[TUPFilterPipe alloc] init];
        [self.pipe open];
    }];
    UIImage *image = [UIImage imageNamed:@"sample_photo.jpg"];
    _inputImage = [[TUPFPImage alloc] initWithUIImage:image];
    _mCurrentRatioType = TTRatio_1_1;
    _mCurrentRenderSize = CGSizeMake(1080, 1080);
    _borderItems = @[@"边框",@"S",@"M",@"L"];
    _borderIndex = 0;
}
- (void)initJigsawFilter:(NSInteger)index updateProperty:(BOOL)isUpdate {
    
    [_pipeThread sync:^{
        TUPFPFilter *filter = [self.pipe getFilter:kFilterIndex];
        if (filter) {
            [self.pipe deleteFilterAt:kFilterIndex];
        }
        filter = [[TUPFPFilter alloc] init:[self.pipe getContext] withName:TUPFPJigsawFilter_TYPE_NAME];
        TUPConfig *config = [filter getConfig];
        [config setIntNumber:TUPFPJigsawFilter_MODEL_TYPE_FILE forKey:TUPFPJigsawFilter_CONFIG_MODEL_TYPE];
        [config setString:self.sandboxPaths[index] forKey:TUPFPJigsawFilter_CONFIG_MODEL_PATH];
        [config setDoubleNumber:self.mCurrentRenderSize.width forKey:TUPFPJigsawFilter_CONFIG_WIDTH];
        [config setDoubleNumber:self.mCurrentRenderSize.height forKey:TUPFPJigsawFilter_CONFIG_HEIGHT];
        [filter setConfig:config];
        [self.pipe addFilter:filter at:kFilterIndex];
        if (isUpdate) {
            [filter setProperty:[self.mCurrentBuilder makeProperty] forKey:TUPFPJigsawFilter_PROP_PARAM];
        }
        TUPFPImage *outputImage = [self.pipe process:self.inputImage];
        [self.displayView update:outputImage];
        
        TUPFPJigsawFilter_InteractionInfo *info = [[TUPFPJigsawFilter_InteractionInfo alloc] init:[filter getProperty:TUPFPJigsawFilter_PROP_INTERACTION_INFO]];
        
        if (isUpdate) {
            for (TUPFPJigsawFilter_InteractionInfo_LayerInfo *layerInfo in info.layerInfos) {
                for (TUPFPJigsawFilter_ImageLayerInfo *imageInfo in self.mCurrentBuilder.holder.layerInfos) {
                    if (imageInfo.index == layerInfo.index) {
                        imageInfo.path = layerInfo.path;
                        imageInfo.dsc_rect = layerInfo.dsc_rect;
                        break;
                    }
                }
            }
        } else {
            TUPFPJigsawFilter_PropertyHolder *holder = [[TUPFPJigsawFilter_PropertyHolder alloc] init];
            for (TUPFPJigsawFilter_InteractionInfo_LayerInfo *layerInfo in info.layerInfos) {
                TUPFPJigsawFilter_ImageLayerInfo *imageInfo = [[TUPFPJigsawFilter_ImageLayerInfo alloc] init];
                imageInfo.index = layerInfo.index;
                imageInfo.path = layerInfo.path;
                imageInfo.dsc_rect = layerInfo.dsc_rect;
                [holder.layerInfos addObject:imageInfo];
            }
            self.mCurrentBuilder = [[TUPFPJigsawFilter_PropertyBuilder alloc] initWithHolder:holder];
        }
       
        self.mCurrentLayerIndex = 0;
        
        dispatch_async(dispatch_get_main_queue(), ^{
            CGRect rect = [self.displayView getInteractionRect:self.mCurrentRenderSize];
            [self.mLayerView updateWithBuilder:self.mCurrentBuilder interactionRect:rect];
        });
    }];
    
}
- (void)switchTypeAction:(UIButton *)sender {
    NSInteger index = sender.tag;
    CGSize renderSize = CGSizeMake(1080, 1080);
    if (index == 2) {
        renderSize = CGSizeMake(1080, 2400);
    }
    _mCurrentRenderSize = renderSize;
    _menuView.hidden = YES;
    if (index == 1) {
        _menuView.hidden = NO;
        _borderIndex = 0;
        self.mCurrentRatioType = TTRatio_1_1;
        [_ratioButton setTitle:[TuRatioType format:_mCurrentRatioType] forState:UIControlStateNormal];
        [_borderButton setTitle:_borderItems[_borderIndex] forState:UIControlStateNormal];
    }
    [self initJigsawFilter:index updateProperty:NO];
    
}
- (void)interactionAction:(UIButton *)sender {
    if (!self.mCurrentBuilder) {
        return;
    }
    TUPFPJigsawFilter_ImageLayerInfo *layerInfo = self.mCurrentBuilder.holder.layerInfos[self.mCurrentLayerIndex];
    switch (sender.tag) {
        case 0:
            [self showSampleWithController];
            break;
        case 1: {
            layerInfo.rotation = ((layerInfo.rotation / 90) + 1) * 90;
            [_mLayerView updateRotationWithIndex:self.mCurrentLayerIndex];
            [self updatepProperty];
        }
            break;
        case 2: {
            layerInfo.isHorizontalFlip = !layerInfo.isHorizontalFlip;
            [self updatepProperty];
        }
            break;
        case 3:
            layerInfo.isVerticallyFlip = !layerInfo.isVerticallyFlip;
            [self updatepProperty];
            break;
        default:
            break;
    }
}
- (void)ratioAction:(UIButton *)sender {
    TTRatioType type = [TuRatioType nextRatioType:TTRatioDefault currentType:_mCurrentRatioType ignoreType:TTRatioOrgin];
    self.mCurrentRatioType = type;
    [_ratioButton setTitle:[TuRatioType format:type] forState:UIControlStateNormal];
    
    _mCurrentRenderSize = CGSizeMake(_mCurrentRenderSize.width, _mCurrentRenderSize.width / [TuRatioType ratio:type]);
    [self initJigsawFilter:1 updateProperty:YES];
}
- (void)borderAction:(UIButton *)sender {
    _borderIndex++;
    if (_borderIndex >= _borderItems.count) {
        _borderIndex = 0;
    }
    [sender setTitle:_borderItems[_borderIndex] forState:UIControlStateNormal];
    CGFloat borderW = _borderIndex * 10;
    for (TUPFPJigsawFilter_ImageLayerInfo *info in self.mCurrentBuilder.holder.layerInfos) {
        info.padding = UIEdgeInsetsMake(borderW,borderW,borderW,borderW);
    }
    [self updatepProperty];
}
- (void)updatepProperty {
    [_pipeThread sync:^{
        TUPFPFilter *filter = [self.pipe getFilter:kFilterIndex];
        [filter setProperty:[self.mCurrentBuilder makeProperty] forKey:TUPFPJigsawFilter_PROP_PARAM];
        TUPFPImage *outputImage = [self.pipe process:self.inputImage];
        [self.displayView update:outputImage];
    }];
}
- (void)showSampleWithController {
    _albumComponent = [TuSDKGeeV1 albumCommponentWithController:self
                                                  callbackBlock:^(TuResult *result, NSError *error, UIViewController *controller) {
        // 获取图片错误
        if (error) {
            lsqLError(@"album reader error: %@", error.userInfo);
            return;
        }
        
        TUPFPJigsawFilter_ImageLayerInfo *layerInfo = self.mCurrentBuilder.holder.layerInfos[self.mCurrentLayerIndex];
        NSArray *resources = [PHAssetResource assetResourcesForAsset:[result.imageAsset asset]];
        NSURL *privateFileURL = [(PHAssetResource*)resources[0] valueForKey:@"privateFileURL"];
        if (privateFileURL.absoluteString) {
            layerInfo.path = privateFileURL.absoluteString;
            [self updatepProperty];
        }
        [controller dismissViewControllerAnimated:YES completion:nil];
    }];
    
    [_albumComponent showComponent];
}
- (void)saveAction {
    [_pipeThread sync:^{
        TUPFPImage *outputImage = [self.pipe process:self.inputImage];
        UIImage *image = [outputImage getUIImage];
        TuResult *result = [TuResult result];
        result.image = [self addWaterMarkToImage:image];;
        [self saveToAlbumWithResult:result];
    }];
    
}
- (TuWaterMarkOption *)waterMarkOption {
    TuWaterMarkOption *option = [[TuWaterMarkOption alloc] init];
    // 设置水印图片
    option.markImage = [UIImage imageNamed:@"sample_watermark1.png"];
    // 设置水印位置 (默认: lsqWaterMarkBottomRight)
    option.markPosition = TTWaterMarkBottomRight;
    // 设置水印距离图片边距 (默认: 6dp)
    option.markMargin = 6;
    return option;
}
@end
