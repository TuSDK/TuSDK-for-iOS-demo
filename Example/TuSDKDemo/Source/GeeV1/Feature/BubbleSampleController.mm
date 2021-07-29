//
//  BubbleSampleController.m
//  TuSDKDemo
//
//  Created by tusdk on 2021/2/19.
//  Copyright © 2021 tusdk.com. All rights reserved.
//

#import "BubbleSampleController.h"

//#import <TuSDKPulseFilter/TUPFilterPipe.h>
//#import <TuSDKPulseFilter/TUPFPDisplayView.h>
//#import <TuSDKPulseFilter/TUPFPImage.h>
//#import <TuSDKPulseFilter/TUPFPFilter.h>
//#import <TuSDKPulseFilter/TUPFPBubbleTextFilter.h>
#import <TuSDKPulseFilter/TuSDKPulseFilter.h>
#import "TuBubbleView.h"
#import "TUPFPBubbleTextFilter_Info.h"
#import "FCFileManager.h"
#import "JMBubbleFilter.h"
@interface BubbleSampleController()<TuBubbleViewDelegate, UITextViewDelegate>
{

    // 底部动作栏
    TuSDKPFEditFilterBottomBar *_bottomBar;
    
    TUPFPDisplayView *_displayView;
    TUPFilterPipe *_filterPipe;
    TuBubbleView *_bubbleView;
    //输入图片
    UIImage *_bubbleImage;
    //当前builder
    TUPFPBubbleTextFilter_Info *_currentBuilder;
    //当前选中的textIndex
    NSInteger _selectIndex;
    //当前的texts
    NSArray *_currentTexts;
}
/**
 用于编辑文字的文字域
 */
@property(nonatomic, strong) UITextView *textView;
@property(nonatomic, assign) BOOL isMove;
@property(nonatomic, strong) TuSDKPFEditFilterBottomBar *tabBar;
/// 显示图层
@property(nonatomic, strong) TUPFPDisplayView *displayView;
/// 交互图层
@property(nonatomic, strong) TuBubbleView *bubbleContentView;

@property(nonatomic, assign) BOOL isFirst;
@property(nonatomic, assign) NSInteger filterLastIndex;
@end

@implementation BubbleSampleController



- (NSString *)copyFileFromResourceTOSandbox:(NSString *)sourceFilename suffix:(NSString *)suffix outFilename:(NSString *)outFilename
{
    
    //文件类型
    NSString *path = [[NSBundle mainBundle] pathForResource:sourceFilename ofType:suffix];

    // 沙盒Documents目录
    NSString * appDir = [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) lastObject];
    
    NSFileManager *fileManager = [NSFileManager defaultManager];
    NSString *filePath = [appDir stringByAppendingPathComponent:outFilename];
    if(![fileManager fileExistsAtPath:filePath]) //如果不存在
    {
        BOOL filesPresent = [self copyMissingFile:path toPath:appDir];
        if (filesPresent) {
            NSLog(@"Copy Success");
        }
        else
        {
            NSLog(@"Copy Fail");
        }
    }
    else
    {
        NSLog(@"文件已存在");
    }
    
    return  filePath;
}

/**
 *    @brief    把Resource文件夹下的area.db拷贝到沙盒
 *
 *    @param     sourcePath     Resource文件路径
 *    @param     toPath     把文件拷贝到XXX文件夹
 *
 *    @return    BOOL
 */
- (BOOL)copyMissingFile:(NSString *)sourcePath toPath:(NSString *)toPath
{
    BOOL retVal = YES; // If the file already exists, we'll return success…
    NSString * finalLocation = [toPath stringByAppendingPathComponent:[sourcePath lastPathComponent]];
    if (![[NSFileManager defaultManager] fileExistsAtPath:finalLocation])
    {
        retVal = [[NSFileManager defaultManager] copyItemAtPath:sourcePath toPath:finalLocation error:NULL];
    }
    return retVal;
}

-(void) addBubble:(UIButton *)sender
{
    NSLog(@"hecc--addBubble");
    
    NSString *filePath = [NSString stringWithFormat:@"TuSDKPulse.bundle/bt/lsq_bubble_%ld", (long)sender.tag];
    NSString *fileName = [NSString stringWithFormat:@"lsq_bubble_%ld.bt", (long)sender.tag];
    
    NSString *sdkBundle = [[NSBundle mainBundle] pathForResource:@"TuSDKPulse" ofType:@"bundle"];
    NSString *fontPath = [sdkBundle stringByAppendingPathComponent:@"bubbleFont"];
    
    TUPFPFilter *bubbleText = [[TUPFPFilter alloc]init:[_filterPipe getContext] withName:TUPFPBubbleTextFilter_TYPE_NAME];
    TUPConfig *config = [[TUPConfig alloc] init];
    NSString *bubbleSourcePath = [self copyFileFromResourceTOSandbox:filePath suffix:@"bt" outFilename:fileName];
    [config setString:bubbleSourcePath forKey:TUPFPBubbleTextFilter_CONFIG_MODEL];
//    NSString *fontPath = [self copyFileFromResourceTOSandbox:@"TuSDKPulse.bundle/bt/SourceHanSansSC-Normal" suffix:@"ttf" outFilename:@"SourceHanSansSC-Normal.ttf"];
    [config setString:fontPath forKey:TUPFPBubbleTextFilter_CONFIG_FONT_DIR];
    [bubbleText setConfig:config];
    
    
    
    long bubble_Index = 50 + sender.tag;
    BOOL ret = [_filterPipe addFilter:bubbleText at:bubble_Index];
    
    if (ret) {
        self.isMove = NO;
        [self updateBubbleImage];
        
        TUPFPBubbleTextFilter_PropertyBuilder *builder = [[TUPFPBubbleTextFilter_PropertyBuilder alloc] init];
        builder.scale = 0.7;
        builder.posX = 0.5;
        builder.posY = 0.5;
        builder.rotate = 0;
        [bubbleText setProperty:builder.makeProperty forKey:TUPFPBubbleTextFilter_PROP_PARAM];

        [self updateBubbleImage];
            
        TUPFPBubbleTextFilter_InteractionInfo *interactionInfo = [[TUPFPBubbleTextFilter_InteractionInfo alloc]init:[bubbleText getProperty:TUPFPBubbleTextFilter_PROP_INTERACTION_INFO]];
        
        TUPFPBubbleTextFilter_Info *filterInfo = [[TUPFPBubbleTextFilter_Info alloc] init];

        filterInfo.scale = builder.scale;
        filterInfo.rotate = interactionInfo.rotate;
        filterInfo.posX = interactionInfo.posX;
        filterInfo.posY = interactionInfo.posY;
        filterInfo.width = interactionInfo.width;
        filterInfo.height = interactionInfo.height;
        filterInfo.rects = interactionInfo.rects;
        filterInfo.bubbleIndex = bubble_Index;
        
        _bubbleView.posInfo = filterInfo;
        
        [_bubbleView appendBubbleSticker:_bubbleImage];
    }

}

/**
 *  编辑图片完成按钮动作
 */
- (void)onImageCompleteAtion
{
    NSLog(@"hecc--onImageCompleteAtion");

}

- (void)viewDidLoad
{
    NSLog(@"hecc--viewDidLoad");
    self.saveToAlbum = YES;
    self.waterMarkOption = [self waterMarkOption];
    [super viewDidLoad];
    [self registerNotifications];
    self.view.backgroundColor = [UIColor grayColor];
    
    _currentBuilder = [[TUPFPBubbleTextFilter_Info alloc] init];
    // 滤镜处理引擎
    
    if (_filterPipe == nil) {
        _filterPipe = [[TUPFilterPipe alloc] init];
        [_filterPipe open];
    }
    
    CGFloat safeBottom = 0;
    if ([UIDevice lsqIsDeviceiPhoneX]) {
        safeBottom = 20;
    }
    
    // 底部动作栏
    _bottomBar = [TuSDKPFEditFilterBottomBar initWithFrame:CGRectMake(0, [self.view lsqGetSizeHeight] - 49 - safeBottom, self.view.lsqGetSizeWidth, 49)];
    [self.view addSubview:_bottomBar];
    [_bottomBar.cancelButton addTouchUpInsideTarget:self action:@selector(lsqBackActionHadAnimated)];
    [_bottomBar.completeButton addTouchUpInsideTarget:self action:@selector(saveAction)];
    
    NSArray *array = @[@"message", @"带劲", @"快乐水"];
    for (int i = 0; i < array.count; i++) {
        
        NSString *imageName = [array[i] stringByAppendingString:@".png"];
        UIButton *bubbleBtn = [UIButton buttonWithType:UIButtonTypeCustom];
        bubbleBtn.frame = CGRectMake(i * 90, [self.view lsqGetSizeHeight] - 100 - safeBottom, 80, 40);
        [bubbleBtn setImage:[UIImage imageNamed:imageName] forState:0];
        bubbleBtn.imageView.contentMode = UIViewContentModeScaleAspectFit;
        bubbleBtn.tag = i + 5;
        [bubbleBtn setTitleColor:[UIColor redColor] forState:0];
        [bubbleBtn addTarget:self action:@selector(addBubble:) forControlEvents:UIControlEventTouchUpInside];
        [self.view addSubview:bubbleBtn];
    }

    // 图片层
    TUPFPDisplayView* displayView = [[TUPFPDisplayView alloc] init];
    displayView.frame = CGRectMake(0, 0, [self.view lsqGetSizeWidth], [self.view lsqGetSizeHeight] - safeBottom - 120);
    displayView.translatesAutoresizingMaskIntoConstraints = NO;
    
    [self.view addSubview:displayView];
//    [displayView.leadingAnchor constraintEqualToAnchor:self.view.leadingAnchor].active = YES;
//    [displayView.trailingAnchor constraintEqualToAnchor:self.view.trailingAnchor].active = YES;
//    [displayView.topAnchor constraintEqualToAnchor:self.view.topAnchor].active = YES;
//    [displayView.bottomAnchor constraintEqualToAnchor:self.view.bottomAnchor].active = YES;
//    [self.view sendSubviewToBack:displayView];
    
    _displayView = displayView;
    [_displayView setup];
    
    _bubbleView = [[TuBubbleView alloc] initWithFrame:_displayView.frame];
    _bubbleView.delegate = self;
    [self.view addSubview:_bubbleView];
    
    [self updateBubbleImage];
}

//注册通知
- (void)registerNotifications
{
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(updateBubbleInfo:) name:@"TuBubbleViewTextChange" object:nil];
    // 监听键盘弹出与隐藏状态
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(keyboardWillShow:) name:UIKeyboardWillShowNotification object:nil];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(keyboardWillHide:) name:UIKeyboardWillHideNotification object:nil];
}

//更新图片
- (void)updateBubbleImage
{
    // 显示示例图片
    UIImage *inputImage = [UIImage imageNamed:@"sample_photo.jpg"];
    TUPFPImage *image = [[TUPFPImage alloc]initWithUIImage:inputImage];
    TUPFPImage *outputImage = [_filterPipe process:image];
    if (!self.isMove) {
        _bubbleImage = [outputImage getUIImage];
    }
    
    bool ret = [_displayView update:outputImage];
}



- (void)dealloc
{
    NSLog(@"hecc--dealloc");
    //[self destory];
    [[NSNotificationCenter defaultCenter] removeObserver:self];
    
    if ([NSThread isMainThread])
    {
        if (_filterPipe)
        {
            [_filterPipe clearFilters];
            [_filterPipe close];
            _filterPipe = nil;
        }
        
        if (_displayView)
        {
            [_displayView teardown];
            _displayView = nil;
        }

    }
    else
    {
        dispatch_sync(dispatch_get_main_queue(), ^{
            if (_filterPipe)
            {
                [_filterPipe clearFilters];
                [_filterPipe close];
                _filterPipe = nil;
            }
            
            if (_displayView)
            {
                [_displayView teardown];
                _displayView = nil;
            }
            
            [_displayView teardown];
            _displayView = nil;

        });
    }
}


#pragma mark - TuBubbleItemViewDelegate
/**气泡文字贴纸删除*/
- (void)onClosedBubbleTextItemView:(int)bubbleIndex
{
    if (!bubbleIndex) return;
    if (!_filterPipe) return;
    [_filterPipe deleteFilterAt:bubbleIndex];
    [self updateBubbleImage];
}

- (void)tuBubbleView:(TuBubbleView *)view onMoveBubbleSticker:(TUPFPBubbleTextFilter_Info *)filterInfo
{
    [self reloadBubbleTextSticker:filterInfo];
}

- (void)onCancelAllSelectedView:(TuBubbleView *)view
{
    //隐藏键盘
    [_textView resignFirstResponder];
    _textView.text = nil;
}

//刷新气泡文字
- (void)reloadBubbleTextSticker:(TUPFPBubbleTextFilter_Info *)filterInfo
{
    TUPFPFilter *bubbleFilter = [_filterPipe getFilter:filterInfo.bubbleIndex];
    TUPFPBubbleTextFilter_PropertyBuilder *builder = [[TUPFPBubbleTextFilter_PropertyBuilder alloc] init];
    builder.scale = filterInfo.scale;
    builder.posX = filterInfo.posX;
    builder.posY = filterInfo.posY;
    builder.rotate = filterInfo.rotate;
    builder.texts = filterInfo.texts;
    bool ret = [bubbleFilter setProperty:builder.makeProperty forKey:TUPFPBubbleTextFilter_PROP_PARAM];
    self.isMove = YES;
    [self updateBubbleImage];
}

#pragma mark - keyboard

- (void)keyboardWillShow:(NSNotification *)notification {
    // 键盘弹出时动画呈现 textView
    CGFloat duration = [notification.userInfo[UIKeyboardAnimationDurationUserInfoKey] doubleValue];
    CGFloat endY = [notification.userInfo[UIKeyboardFrameEndUserInfoKey] CGRectValue].origin.y;
    CGRect textViewFrame = self.textView.frame;
    textViewFrame.origin.y = endY - textViewFrame.size.height;
    [UIView animateWithDuration:duration animations:^{
        self.textView.frame = textViewFrame;
        self.textView.alpha = 1;
    } completion:^(BOOL finished) {
        
    }];
}
- (void)keyboardWillHide:(NSNotification *)notification {
    // 键盘隐藏式动画隐藏 textView
    CGFloat duration = [notification.userInfo[UIKeyboardAnimationDurationUserInfoKey] doubleValue];
    CGFloat endY = [notification.userInfo[UIKeyboardFrameEndUserInfoKey] CGRectValue].origin.y;
    CGRect textViewFrame = self.textView.frame;
    textViewFrame.origin.y = endY;
    [UIView animateWithDuration:duration animations:^{
        self.textView.frame = textViewFrame;
        self.textView.alpha = 0;
    } completion:^(BOOL finished) {
        
    }];
}

#pragma mark - notification
- (void)updateBubbleInfo:(NSNotification *)notification
{
    [self.textView becomeFirstResponder];
    NSArray *dataSet = (NSArray *)notification.object;
    _currentBuilder = dataSet.firstObject;
    
    _currentTexts = _currentBuilder.texts;
    _selectIndex = [dataSet.lastObject integerValue];
}

#pragma mark - UITextViewDelegate

- (void)textViewDidChange:(UITextView *)textView
{
    NSString *text = textView.text;
    NSString *lastText = _currentTexts[_selectIndex];
    
    if ([lastText isEqualToString:text]) {
        return;
    }
    NSMutableArray *builderTexts = [NSMutableArray arrayWithArray:_currentTexts];
    [builderTexts replaceObjectAtIndex:_selectIndex withObject:text];
    _currentTexts = [builderTexts copy];
    _currentBuilder.texts = _currentTexts;
    [self reloadBubbleTextSticker:_currentBuilder];
}


- (UITextView *)textView {
    if (!_textView) {
        // text view，默认隐藏在屏幕下方，编辑文字时随键盘出现而弹出
        CGSize size = [UIScreen mainScreen].bounds.size;
        _textView = [[UITextView alloc] initWithFrame:CGRectMake(0, size.height, size.width, 55)];
        [self.view addSubview:_textView];
        _textView.alpha = 0;
        _textView.delegate = self;
    }
    return _textView;
}
- (void)saveAction {
    UIImage *inputImage1 = [UIImage imageNamed:@"sample_photo.jpg"];
    TUPFPImage *inputImage = [[TUPFPImage alloc]initWithUIImage:inputImage1];
        TUPFPImage *outputImage = [_filterPipe process:inputImage];
        UIImage *image = [outputImage getUIImage];
        TuResult *result = [TuResult result];
        result.image = [self addWaterMarkToImage:image];;
        [self saveToAlbumWithResult:result];
   
    
}
- (TuWaterMarkOption *)waterMarkOption {
    TuWaterMarkOption *option = [[TuWaterMarkOption alloc] init];
    // 设置水印图片
    option.markImage = [UIImage imageNamed:@"sample_watermark1.png"];
    // 设置水印位置 (默认: lsqWaterMarkBottomRight)
    option.markPosition = lsqWaterMarkBottomRight;
    // 设置水印距离图片边距 (默认: 6dp)
    option.markMargin = 6;
    return option;
}
@end
