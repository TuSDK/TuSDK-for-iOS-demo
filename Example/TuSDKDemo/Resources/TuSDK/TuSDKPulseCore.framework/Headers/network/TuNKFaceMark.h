//
//  TuNKFaceMark.h
//  TuSDK
//
//  Created by Jimmy Zhao on 16/8/18.
//  Copyright © 2016年 tusdk.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <TuSDKPulseCore/TuDataJson.h>

#pragma mark - 人脸标点5
@interface TuNKFaceMark5FaceResult : TuDataJson

@property (nonatomic) NSInteger count;
@property (nonatomic, retain) NSArray<NSValue *> *points;

@end

#pragma mark - TuNKFaceMark
/**
 *  Image Analysis processed type
 */
typedef NS_ENUM(NSInteger, lsqFaceMarkType)
{
    /**
     * Unknow
     */
    lsqFaceMarkTypeUnknow,
    /**
     * Succeed
     */
    lsqFaceMarkTypeSucceed,
    /**
     * Not Input Image Object
     */
    lsqFaceMarkTypeNotInputImage,
    /**
     * Service Failed
     */
    lsqFaceMarkTypeServiceFailed,
    /**
     * No face is detected
     */
    lsqFaceMarkTypeNoFaceDetected,
    
    /**
     * No access
     */
    lsqFaceMarkTypeNoAccess
};
/**
 * Image Analysis Block
 *
 *  @param result  Image online analysis result
 *  @param type    Image Analysis processed type
 */
typedef void (^TuSDKNKFaceMarkBlock)(id result, lsqFaceMarkType type);
/**
 *  Image online analysis
 */
@interface TuNKFaceMark : NSObject
/**
 *  Input face Image
 */
@property (nonatomic, retain) UIImage *faceImage;

/**
 *  analysis face mark5 arguments
 *
 *  @param block Image Analysis Block
 */
- (void)analysisFaceMark5WithBlock:(TuSDKNKFaceMarkBlock)block;

/**
 *  cancel analysis
 */
- (void)cancel;
@end
