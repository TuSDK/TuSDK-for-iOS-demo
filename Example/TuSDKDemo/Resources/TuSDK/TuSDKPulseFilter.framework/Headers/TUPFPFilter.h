
#import <Foundation/Foundation.h>
#import <TuSDKPulse/TUPBase.h>
#import <TuSDKPulse/TUPConfig.h>
#import <TuSDKPulse/TUPProperty.h>

#import "TUPFilterCtx.h"

NS_ASSUME_NONNULL_BEGIN

@interface TUPFPFilter : TUPBase
{
    @package
    void* _pimpl;
}




- (instancetype) init:(TUPFilterCtx*) ctx withName:(NSString*) name;
- (instancetype) init:(TUPFilterCtx*) ctx withImpl:(void*) impl;


- (BOOL) setConfig:(TUPConfig*) config;
- (TUPConfig*) getConfig;

/**
 * 滤镜开关，是否加载滤镜效果
 * @param enable  默认为YES
 */
- (void)setEnable:(BOOL)enable;


- (BOOL) setProperty:(TUPProperty*) prop forKey:(NSString*) key;
- (TUPProperty* _Nullable) getProperty:(NSString*) key;



@end

NS_ASSUME_NONNULL_END
