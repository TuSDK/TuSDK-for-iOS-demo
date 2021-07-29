//
//  JigsawLayerItemView.h
//  TuSDKDemo
//
//  Created by 言有理 on 2021/7/21.
//  Copyright © 2021 tusdk.com. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
@class JigsawLayerItemView;
@protocol JigsawLayerItemDelegate <NSObject>

// 视图变换回调 偏移量 缩放比例 旋转角度
- (void)itemView:(JigsawLayerItemView *)itemView center:(CGPoint)center;
- (void)itemView:(JigsawLayerItemView *)itemView scale:(CGFloat)scale angle:(CGFloat)angle;

@end

@interface JigsawLayerItemView : UIView
@property(nonatomic, weak) id<JigsawLayerItemDelegate> delegate;
@property(nonatomic, assign) int index; // 索引
@property(nonatomic, assign) BOOL isSelected;
@property(nonatomic, assign) int rotation;
@end

NS_ASSUME_NONNULL_END
