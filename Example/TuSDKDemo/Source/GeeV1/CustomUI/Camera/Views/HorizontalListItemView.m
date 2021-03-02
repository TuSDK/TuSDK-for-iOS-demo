//
//  HorizontalListItemView.m
//  TuSDKVideoDemo
//
//  Created by bqlin on 2018/6/27.
//  Copyright © 2018年 TuSDK. All rights reserved.
//

#import "HorizontalListItemView.h"

@interface HorizontalListItemView ()

///**
// 接收事件的按钮
// */
//@property (nonatomic, strong) UIButton *touchButton;

/**
 点击次数
 */
@property (nonatomic, assign) NSInteger tapCount;

@end

@implementation HorizontalListItemView


- (void)commonInit {
    
    self.layer.cornerRadius = 5;
    self.layer.masksToBounds = YES;
    self.backgroundColor = [UIColor colorWithWhite:1 alpha:0.15];
    
    _thumbnailView = [[UIImageView alloc] init];
    [self addSubview:_thumbnailView];
    _thumbnailView.contentMode = UIViewContentModeScaleAspectFill;
    _thumbnailView.userInteractionEnabled = NO;
    
    _titleLabel = [[UILabel alloc] init];
    [self addSubview:_titleLabel];
    _titleLabel.backgroundColor = [UIColor colorWithWhite:0 alpha:0.6];
    _titleLabel.font = [UIFont systemFontOfSize:10];
    _titleLabel.textColor = [UIColor whiteColor];
    _titleLabel.textAlignment = NSTextAlignmentCenter;
    _titleLabel.userInteractionEnabled = NO;
    
    _selectedImageView = [[UIImageView alloc] init];
    [self addSubview:_selectedImageView];
    _selectedImageView.contentMode = UIViewContentModeCenter;
    _selectedImageView.image = [UIImage imageNamed:@"ic_parameter"];
    _selectedImageView.hidden = YES;
    _selectedImageView.backgroundColor = [UIColor colorWithWhite:0 alpha:0.6];
    _selectedImageView.userInteractionEnabled = NO;
    
    // 使用按钮响应手势
//    _touchButton = [UIButton buttonWithType:UIButtonTypeCustom];
//    [self addSubview:_touchButton];
//    [_touchButton addTarget:self action:@selector(touchDownAction:) forControlEvents:UIControlEventTouchDown];
//    [_touchButton addTarget:self action:@selector(touchUpInsideAction:) forControlEvents:UIControlEventTouchUpInside];
//    [_touchButton addTarget:self action:@selector(touchEndAction:) forControlEvents:UIControlEventTouchUpOutside | UIControlEventTouchUpInside | UIControlEventTouchCancel];
}

- (void)layoutSubviews {
    CGSize size = self.bounds.size;
    _thumbnailView.frame = self.bounds;
    const CGFloat labelHeight = 16;
    _titleLabel.frame = CGRectMake(0, size.height - labelHeight, size.width, labelHeight);
    _selectedImageView.frame = self.bounds;
    _touchButton.frame = self.bounds;
}

#pragma mark - public

+ (instancetype)disableItemView {
    HorizontalListItemView *itemView = [HorizontalListItemView itemViewWithImage:[UIImage imageNamed:@"ic_nix"] title:nil];
    itemView.disableSelect = YES;
    return itemView;
}

+ (instancetype)itemViewWithImage:(UIImage *)image title:(NSString *)title {
    HorizontalListItemView *itemView = [[self.class alloc] initWithFrame:CGRectZero];
    itemView.thumbnailView.image = image;
    itemView.thumbnailView.contentMode = UIViewContentModeCenter;
    itemView.titleLabel.hidden = title.length <= 0;
    itemView.titleLabel.text = title;
    return itemView;
}

- (void)setTapCountWithSelected:(BOOL)selected {
    self.tapCount = selected ? 1 : 0;
}

#pragma mark - property

- (void)setSelected:(BOOL)selected {
    if (_disableSelect) {
        _selected = NO;
        return;
    }
    _selected = selected;
    _titleLabel.hidden = selected;
    _selectedImageView.hidden = !selected;
    [self setTapCountWithSelected:selected];
}


- (void)setThumbnailView:(UIImageView *)thumbnailView {
    [_thumbnailView removeFromSuperview];
    [self insertSubview:thumbnailView atIndex:0];
    _thumbnailView = thumbnailView;
    [self setNeedsLayout];
}

#pragma mark - HorizontalListItemViewDelegate

// 使用按钮事件实现手势
//#pragma mark action
//
//- (void)touchDownAction:(UIButton *)sender {
//    if ([self.delegate respondsToSelector:@selector(itemViewDidTouchDown:)]) {
//        [self.delegate itemViewDidTouchDown:self];
//    }
//}
//
//- (void)touchEndAction:(UIButton *)sender {
//    if ([self.delegate respondsToSelector:@selector(itemViewDidTouchUp:)]) {
//        [self.delegate itemViewDidTouchUp:self];
//    }
//}
//
//- (void)touchUpInsideAction:(UIButton *)sender {
//    if (!_disableSelect) self.tapCount += 1;
//    if ([self.delegate respondsToSelector:@selector(itemViewDidTap:)]) {
//        [self.delegate itemViewDidTap:self];
//    }
//}


@end
