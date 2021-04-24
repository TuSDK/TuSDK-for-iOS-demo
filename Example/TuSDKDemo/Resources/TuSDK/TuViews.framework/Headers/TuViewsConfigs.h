#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/**
 *  组件错误类型
 */
typedef NS_ENUM(NSInteger, lsqRecordError)
{
    /** 未知 */
    lsqRecordVideoErrorUnknow,
    
    /** 存储空间不足 */
    lsqRecordVideoErrorNotEnoughSpace,
    
    /** 小于最小录制时长 */
    lsqRecordVideoErrorLessMinDuration,
    
    /** 大于最大录制时长 */
    lsqRecordVideoErrorMoreMaxDuration,
    
    /** 文件保存失败 */
    lsqRecordVideoErrorSaveFailed,
};


/**
 录制状态
 */
typedef NS_ENUM(NSInteger,lsqRecordState)
{
    lsqRecordStateNotStart,
    
    lsqRecordStatePrepare,

    /** 正在录制 */
    lsqRecordStateRecording,
    
    /** 录制完成 */
    lsqRecordStateRecordingCompleted,
    
    /** 正在保存 */
    lsqRecordStateSaveing,
    
    /** 保存完成 */
    lsqRecordStateSaveingCompleted,
        
    /** 已暂停 */
    lsqRecordStatePaused,
    
    /** 已取消 */
    lsqRecordStateCanceled,
};


/**
 录制模式
 */
typedef NS_ENUM(NSInteger, lsqRecordMode)
{
    /** 正常模式 */
    lsqRecordModeNormal,
    
    /** 续拍模式 */
    lsqRecordModeKeep,
};


/**
 录制速度模式
 */
typedef NS_ENUM(NSInteger,lsqSpeedMode)
{
    /** 标准模式 速度大小1.0 */
    lsqSpeedMode_Normal,
    
    /** 快速模式 速度大小1.5 */
    lsqSpeedMode_Fast1,
    
    /** 极快模式 速度大小2.0 */
    lsqSpeedMode_Fast2,
    
    /** 慢速模式 速度大小0.7 */
    lsqSpeedMode_Slow1,
    
    /** 极慢模式  速度大小0.5 */
    lsqSpeedMode_Slow2,
};

/**
 * 录制变声类型
 *
 * @since v3.0.1
 */
typedef NS_ENUM(NSUInteger, lsqSoundPitch) {
    // 正常
    lsqSoundPitchNormal,
    // 怪兽
    lsqSoundPitchMonster,
    // 大叔
    lsqSoundPitchUncle,
    // 女生
    lsqSoundPitchGirl,
    // 萝莉
    lsqSoundPitchLolita,
};




typedef NS_ENUM(NSInteger, TuSkinFaceType)
{
    TuSkinFaceTypeNatural = 0,  // 自然美颜
    TuSkinFaceTypeMoist,        // 极致美颜
    TuSkinFaceTypeBeauty        // 新美颜
};



typedef NS_ENUM(NSInteger,CosmeticEyePartType) {
    COSMETIC_EYESHADOW_TYPE,    // 眼影
    COSMETIC_EYELINE_TYPE,      // 眼线
    COSMETIC_EYELASH_TYPE       // 睫毛
};

typedef NS_ENUM(NSInteger ,CosmeticLipType){
    COSMETIC_WUMIAN_TYPE,   // 雾面
    COSMETIC_ZIRUN_TYPE,    // 滋润
    COSMETIC_SHUIRUN_TYPE   // 水润
};


/**
 特效数据类型
 
 - TuSDKMediaEffectDataTypeFilter: 滤镜特效
 - TuSDKMediaEffectDataTypeAudio: 音频特效
 - TuSDKMediaEffectDataTypeSticker: 贴纸特效
 - TuSDKMediaEffectDataTypeStickerAudio: 贴纸+音效
 - TuSDKMediaEffectDataTypeScene: 场景特效
 - TuSDKMediaEffectDataTypeParticle: 粒子特效
 - TuSDKMediaEffectDataTypeStickerText: 字幕贴纸特效
 - TuSDKMediaEffectDataTypeStickerImage: 图片贴纸特效
 - TuSDKMediaEffectDataTypeComic : 漫画特效
 - TuSDKMediaEffectDataTypePlasticFace : 微整形 v1 大眼廋脸
 - TuSDKMediaEffectDataTypeSkinFace : 美肤特效
 - TuSDKMediaEffectDataTypeMonsterFace : 哈哈镜特效
 - TuSDKMediaEffectDataTypeTransition : 转场
 - TuSDKMediaEffectDataTypeTransition : 绿幕特效
 - TuSDKMediaEffectDataTypeCosmetic : 美妆特效
 - TuSDKMediaEffectDataTypeReshape: 微整形 v2 白牙祛皱

 */
typedef NS_ENUM(NSUInteger,TuSDKMediaEffectDataType)
{
    TuSDKMediaEffectDataTypeFilter = 0,
    TuSDKMediaEffectDataTypeAudio ,
    TuSDKMediaEffectDataTypeSticker,
    TuSDKMediaEffectDataTypeStickerAudio,
    TuSDKMediaEffectDataTypeScene,
    TuSDKMediaEffectDataTypeParticle,
    TuSDKMediaEffectDataTypeStickerText,
    TuSDKMediaEffectDataTypeStickerImage,
    TuSDKMediaEffectDataTypeComic,
    TuSDKMediaEffectDataTypePlasticFace,
    TuSDKMediaEffectDataTypeSkinFace,
    TuSDKMediaEffectDataTypeMonsterFace,
    TuSDKMediaEffectDataTypeTransition,
    TuSDKMediaEffectDataTypeScreenKeying,
    TuSDKMediaEffectDataTypeCosmetic,
    TuSDKMediaEffectDataTypeReshape,

};

/**
 哈哈镜类型
 @since v3.3.0
 */
typedef NS_ENUM(NSUInteger,TuSDKMonsterFaceType) {
    /** 哈哈镜 - 大鼻子  @since v3.3.0 */
    TuSDKMonsterFaceTypeBigNose,
    /** 哈哈镜 - 大饼脸 @since v3.3.0 */
    TuSDKMonsterFaceTypePieFace,
    /** 哈哈镜 - 国字脸 @since v3.3.0 */
    TuSDKMonsterFaceTypeSquareFace,
    /** 哈哈镜 - 厚嘴唇 @since v3.3.0 */
    TuSDKMonsterFaceTypeThickLips,
    /** 哈哈镜 - 眯眯眼 @since v3.3.0 */
    TuSDKMonsterFaceTypeSmallEyes,
    /** 哈哈镜 - 木瓜脸 @since v3.3.0 */
    TuSDKMonsterFaceTypePapayaFace,
    /** 哈哈镜 - 蛇精脸 @since v3.3.0 */
    TuSDKMonsterFaceTypeSnakeFace,
};



typedef NS_ENUM(NSUInteger, TuSDKSoundPitchType) {
    // 正常
    TuSDKSoundPitchNormal,
    // 怪兽
    TuSDKSoundPitchMonster,
    // 大叔
    TuSDKSoundPitchUncle,
    // 女生
    TuSDKSoundPitchGirl,
    // 萝莉
    TuSDKSoundPitchLolita,
};






















NS_ASSUME_NONNULL_END
