
#import <Foundation/Foundation.h>
#import "TUPBase.h"
NS_ASSUME_NONNULL_BEGIN

@interface TUPProperty : TUPBase {
    void* _impl;
}


- (instancetype) init NS_UNAVAILABLE;

- (instancetype) initWithNumber:(NSNumber*) num;

- (instancetype) initWithString:(NSString*) str;

- (instancetype) initWithJsonString:(NSString*) jsonStr;


//pulse::Property*
- (instancetype) initWithImpl:(void*)impl;

//pulse::Property*
- (BOOL) unwrap:(void*)impl;
- (NSString *)toString;



+ (TUPProperty*) propertyWithNumber:(NSNumber*) num;

+ (TUPProperty*) propertyWithString:(NSString*) str;

+ (TUPProperty*) propertyWithJsonString:(NSString*) json;



@end


NS_ASSUME_NONNULL_END
