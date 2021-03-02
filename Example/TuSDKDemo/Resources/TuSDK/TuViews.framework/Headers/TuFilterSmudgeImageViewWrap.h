//
//  TuFilterSmudgeImageViewWrap.h
//  TuSDK
//
//  Created by Yanlin on 12/3/15.
//  Copyright © 2015 tusdk.com. All rights reserved.
//

#import "TuSmudgeImageViewWrap.h"
#import "TuSDKPulseCore/cx/seles/extend/SelesParameters.h"

@interface TuFilterSmudgeImageViewWrap : TuSmudgeImageViewWrap

@property (nonatomic, strong) SelesParameters *filterParams;

@end
