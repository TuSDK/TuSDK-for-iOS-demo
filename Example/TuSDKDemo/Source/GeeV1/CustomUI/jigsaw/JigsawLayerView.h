//
//  JigsawLayerView.h
//  TuSDKDemo
//
//  Created by 言有理 on 2021/7/21.
//  Copyright © 2021 tusdk.com. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
@class TUPFPJigsawFilter_PropertyBuilder;
@interface JigsawLayerView : UIView
@property(nonatomic, copy) void(^updatePropertyBlock)();
@property(nonatomic, copy) void(^updateIndexBlock)(NSInteger index);
- (void)updateWithBuilder:(TUPFPJigsawFilter_PropertyBuilder *)builder interactionRect:(CGRect)interactionR;
- (void)updateRotationWithIndex:(NSInteger)index;
@end

NS_ASSUME_NONNULL_END
