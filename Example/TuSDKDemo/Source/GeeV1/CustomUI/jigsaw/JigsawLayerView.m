//
//  JigsawLayerView.m
//  TuSDKDemo
//
//  Created by 言有理 on 2021/7/21.
//  Copyright © 2021 tusdk.com. All rights reserved.
//

#import "JigsawLayerView.h"
#import <TuSDKPulseFilter/TuSDKPulseFilter.h>
#import "JigsawLayerItemView.h"
@interface JigsawLayerView ()<JigsawLayerItemDelegate>
@property(nonatomic, strong) NSMutableArray <JigsawLayerItemView *> *items;
@property(nonatomic, strong) UIView *interactionView;
@property(nonatomic, strong) TUPFPJigsawFilter_PropertyBuilder *builder;
@end

@implementation JigsawLayerView
- (instancetype)initWithFrame:(CGRect)frame {
    self = [super initWithFrame:frame];
    if (self) {
        _interactionView = [[UIView alloc] init];
        _interactionView.frame = CGRectMake(0, 0, frame.size.width, frame.size.height);
        [self addSubview:_interactionView];
    }
    return self;
}

- (void)updateWithBuilder:(TUPFPJigsawFilter_PropertyBuilder *)builder interactionRect:(CGRect)interactionR {
    _builder = builder;
    _interactionView.frame = interactionR;
    [_interactionView.subviews makeObjectsPerformSelector:@selector(removeFromSuperview)];
    _items = [NSMutableArray array];
    for (int i = 0; i<builder.holder.layerInfos.count; i++) {
        TUPFPJigsawFilter_ImageLayerInfo *info = builder.holder.layerInfos[i];
        
        JigsawLayerItemView *view = [[JigsawLayerItemView alloc] initWithFrame:CGRectMake(interactionR.size.width * info.dsc_rect.origin.x,
                                                                interactionR.size.height * info.dsc_rect.origin.y,
                                                                interactionR.size.width * (info.dsc_rect.size.width - info.dsc_rect.origin.x),
                                                                interactionR.size.height * (info.dsc_rect.size.height - info.dsc_rect.origin.y))];
        view.index = info.index;
        view.rotation = info.rotation;
        view.delegate = self;
        view.isSelected = (i == 0);
        view.layer.borderColor = UIColor.redColor.CGColor;
        [_items addObject:view];
        [_interactionView addSubview:view];
    }
}

- (void)updateRotationWithIndex:(NSInteger)index {
    if (!_builder || _builder.holder.layerInfos.count < index) {
        return;
    }
    _items[index].rotation = _builder.holder.layerInfos[index].rotation;
}
// MARK: - 贴纸切换
- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
    // 获取点击点的坐标
    CGPoint touchPoint = [[touches anyObject] locationInView:self];
    JigsawLayerItemView *selectedItemView = nil;
    for (UIView *subview in _interactionView.subviews) {
        if (![subview isKindOfClass:[JigsawLayerItemView classForCoder]]) {
            continue;
        }
        JigsawLayerItemView *itemView = (JigsawLayerItemView *)subview;
        // 判断点是否在view rect范围内
        BOOL isInside = [itemView pointInside:[itemView convertPoint:touchPoint fromView:self] withEvent:nil];
        if (isInside) {
            selectedItemView = itemView;
        }
    }
    [self updateSeletedView:selectedItemView];
}
- (void)updateSeletedView:(nullable JigsawLayerItemView *)itemView {
    for (JigsawLayerItemView *subview in _interactionView.subviews) {
        if ([subview isEqual:itemView]) {
            if (!subview.isSelected) {
                subview.isSelected = YES;
                if (self.updateIndexBlock) {
                    self.updateIndexBlock(subview.index);
                }
            }
        } else {
            subview.isSelected = NO;
        }
    }
}
- (void)itemView:(JigsawLayerItemView *)itemView scale:(CGFloat)scale angle:(CGFloat)angle {
    for (TUPFPJigsawFilter_ImageLayerInfo *info in _builder.holder.layerInfos) {
        if (info.index == itemView.index) {
            info.scale = scale;
            //info.rotation = angle;            
            if (self.updatePropertyBlock) {
                self.updatePropertyBlock();
            }
            break;
        }
    }
}
- (void)itemView:(JigsawLayerItemView *)itemView center:(CGPoint)center {
    for (TUPFPJigsawFilter_ImageLayerInfo *info in _builder.holder.layerInfos) {
        if (info.index == itemView.index) {
            info.offset = CGPointMake(center.x/_interactionView.frame.size.width, center.y/_interactionView.frame.size.height);
            if (self.updatePropertyBlock) {
                self.updatePropertyBlock();
            }
            break;
        }
    }
}
@end
