//
//  TUPFPBubbleTextFilter_Info.h
//  TuSDKDemo
//
//  Created by 刘鹏程 on 2021/2/26.
//  Copyright © 2021 tusdk.com. All rights reserved.
//

#import <TuSDKPulseFilter/TuSDKPulseFilter.h>

NS_ASSUME_NONNULL_BEGIN

@interface TUPFPBubbleTextFilter_Info : TUPFPBubbleTextFilter_InteractionInfo

/**缩放*/
@property(nonatomic) double scale;
/**bubbleID*/
@property (nonatomic, assign) NSInteger bubbleIndex;
/**文本*/
@property(nonatomic) NSArray<NSString *>* texts;
/**背景*/
@property (nonatomic, assign) CGRect bubbleImageFrame;
@end

NS_ASSUME_NONNULL_END
