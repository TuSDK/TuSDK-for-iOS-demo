

#import <Foundation/Foundation.h>
#import <TuSDKPulse/TUPBase.h>
#import <TuSDKPulse/TUPConfig.h>

#import "TUPFilterCtx.h"
#import "TUPFPFilter.h"
#import "TUPFPImage.h"
#import "TUPFPDetectResult.h"

NS_ASSUME_NONNULL_BEGIN

@interface TUPFilterPipe : TUPBase


- (TUPFilterCtx*) getContext;


- (instancetype) init;

//- (instancetype) initWithImpl:(void*) impl;




- (BOOL) setConfig:(TUPConfig*) config;
- (TUPConfig*) getConfig;


- (BOOL) open;
- (void) close;


-(TUPFPFilter*) getFilter:(NSInteger)idx;

- (BOOL) addFilter:(TUPFPFilter*) filter at:(NSInteger) idx;

- (BOOL) deleteFilterAt:(NSInteger) idx;

- (void) clearFilters;



- (TUPFPImage*) process:(TUPFPImage*) image;

- (TUPFPDetectResult*) getCurrentDetectResult:(NSString*) key;


@end

NS_ASSUME_NONNULL_END
