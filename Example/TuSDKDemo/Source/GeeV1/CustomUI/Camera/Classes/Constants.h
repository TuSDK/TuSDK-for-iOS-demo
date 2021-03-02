//
//  Constants.h
//  TuSDKVideoDemo
//
//  Created by bqlin on 2018/6/28.
//  Copyright © 2018年 TuSDK. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TuSDKFramework.h"

// 注意事项: 以 s 结尾的宏都是一些散列值，使用时需进行封包；而以 Array、Dictionary 结尾的则是可直接使用的数组和字典。

#pragma mark - 普通滤镜（Array）

// 视频编辑器滤镜的 filterCode
#define kVideoFilterCodes @"Olympus_1", @"Leica_1", @"Gold_1", @"Cheerful_1", @"White_1", @"s1950_1", @"Blurred_1", @"Newborn_1", @"Fade_1", @"NewYork_1"
// 录制相机普通滤镜的 filterCode
#define kCameraNormalFilterCodes  @"SkinLotus_1",@"SkinNatural_1", @"SkinFair_1", @"SkinBeckoning_1", @"SkinTender_1", @"SkinLeisurely_1", @"SkinRose_1", @"SkinWarm_1", @"SkinClear_1", @"SkinConfession_1", @"SkinJapanese_1",@"SkinExtraordinary_1",@"SkinHoney_1",@"SkinButter_1",@"SkinDawn_1",@"SkinSummer_1",@"SkinSweet_1",@"SkinPlain_1",@"SkinDusk_1",@"SkinNostalgia_1",@"gaosi_01"

// 录制相机漫画滤镜 filterCode
#define kCameraComicsFilterCodes @"CHComics_Video", @"USComics_Video", @"JPComics_Video", @"Lightcolor_Video", @"Ink_Video", @"Monochrome_Video"
// 美颜滤镜参数名称
#define kBeautySkinKeys @"skin_default",@"smooth",@"whiten",@"sharpen"
// 美型（微整形）滤镜参数名称
#define kBeautyFaceKeys @"eyeSize",@"chinSize",@"noseSize",@"mouthWidth",@"lips", @"archEyebrow", @"browPosition", @"jawSize",@"eyeAngle" ,@"eyeDis",  @"forehead"

/**
 是否为漫画滤镜

 @param filterCode 滤镜码
 @return 是否为漫画滤镜
 */
NS_INLINE BOOL isComicsFilterCode(NSString *filterCode) {
    return [@[kCameraComicsFilterCodes] containsObject:filterCode];
}

#pragma mark - 声音变调（Array）

// 声音变调名称
#define kPitchTitles NSLocalizedStringFromTable(@"tu_怪兽", @"VideoDemo", @"怪兽"), NSLocalizedStringFromTable(@"tu_大叔", @"VideoDemo", @"大叔"), NSLocalizedStringFromTable(@"tu_正常", @"VideoDemo", @"正常"), NSLocalizedStringFromTable(@"tu_女生", @"VideoDemo", @"女生"), NSLocalizedStringFromTable(@"tu_萝莉", @"VideoDemo", @"萝莉")


#pragma mark - MV（Dictionary）

// MV 配对音频名
#define kMVEffectAudioDictionary @{@(1420):@"sound_cat",\
@(1427):@"sound_crow",\
@(1432):@"sound_tangyuan",\
@(1446):@"sound_children",\
@(1470):@"sound_oldmovie",\
@(1469):@"sound_relieve",\
}


#pragma mark - 配乐（Array）

// 配乐缩略图
#define kMusicThumbnailArray @[@"lsq_audio_thumb_lively.jpg", @"lsq_audio_thumb_oldmovie.jpg", @"lsq_audio_thumb_relieve.jpg"]
// 配乐名称
#define kMusicTitleArray @[NSLocalizedStringFromTable(@"lsq_audio_lively", @"TuSDKConstants", @"欢快"), NSLocalizedStringFromTable(@"lsq_audio_oldmovie", @"TuSDKConstants", @"老电影"), NSLocalizedStringFromTable(@"lsq_audio_relieve", @"TuSDKConstants", @"舒缓")]
// 配乐文件名
#define kMusicFileNameArray @[@"sound_lively", @"sound_oldmovie", @"sound_relieve"]


#pragma mark - 场景特效（Array）

// 场景特效code
#define kSceneEffectCodeArray @[@"LiveShake01",@"LiveMegrim01",@"EdgeMagic01",@"LiveFancy01_1",@"LiveSoulOut01",@"LiveSignal01",@"LiveLightning01",@"LiveXRay01",@"LiveHeartbeat01", @"LiveMirrorImage01", @"LiveSlosh01", @"LiveOldTV01"]
// 场景特效颜色
#define kSceneEffectColorArray @[lsqRGBA(250, 118, 82, 0.7), lsqRGBA(244, 161, 26, 0.7), lsqRGBA(255, 253, 80, 0.7),lsqRGBA(91, 242, 84, 0.7), lsqRGBA(22, 206, 252, 0.7), lsqRGBA(110, 160, 242, 0.7), lsqRGBA(110, 160, 17, 0.7), lsqRGBA(255, 155, 224, 0.7), lsqRGBA(110, 17, 242, 0.7), lsqRGBA(153, 225, 17, 0.7), lsqRGBA(255, 239, 255, 0.7), lsqRGBA(110, 254, 238, 0.7)]


#pragma mark - 时间特效（Array）

// 时间特效code
#define kTimeEffectCodeArray @[@"repeat", @"slow", @"reverse"]


#pragma mark - 魔法特效（Array）

// 粒子特效code
#define kParticleEffectCodeArray @[@"snow01", @"Love", @"Bubbles", @"Music", @"Star", @"Surprise", @"Flower", @"Magic", @"Money", @"Burning", @"Fireball"]
// 粒子特效颜色
#define kParticleEffectColorArray @[\
lsqRGBA(255, 255, 255, 0.7),\
lsqRGBA(254, 15, 15, 0.7),\
lsqRGBA(170, 170, 170, 0.7),\
lsqRGBA(54, 101, 255, 0.7),\
lsqRGBA(95, 250, 197, 0.7),\
lsqRGBA(148, 123, 255, 0.7),\
lsqRGBA(255, 155, 190, 0.7),\
lsqRGBA(100, 253, 253, 0.7),\
lsqRGBA(252, 231, 123, 0.7),\
lsqRGBA(255, 145, 91, 0.7),\
lsqRGBA(255, 203, 91, 0.7)]


// 转场特效
#define kTransitionTypesArray @[@(0),@(1),@(2),@(3),@(4),@(5),@(6),@(7),@(8),@(9),@(10),@(11),@(12)]

#define kTransitionEffectColorArray @[\
lsqRGBA(250, 118, 82, 0.7),\
lsqRGBA(244, 161, 26, 0.7),\
lsqRGBA(255, 253, 80, 0.7),\
lsqRGBA(91, 242, 84, 0.7), \
lsqRGBA(22, 206, 252, 0.7), \
lsqRGBA(110, 160, 242, 0.7), \
lsqRGBA(110, 160, 17, 0.7), \
lsqRGBA(255, 155, 224, 0.7), \
lsqRGBA(110, 17, 242, 0.7),\
lsqRGBA(255, 145, 91, 0.7),\
lsqRGBA(252, 231, 123, 0.7),\
lsqRGBA(100, 253, 253, 0.7),\
lsqRGBA(255, 203, 91, 0.7)]

