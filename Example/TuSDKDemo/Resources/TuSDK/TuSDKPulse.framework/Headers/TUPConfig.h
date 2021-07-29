
#import <Foundation/Foundation.h>
#import "TUPBase.h"
NS_ASSUME_NONNULL_BEGIN

@interface TUPConfig : TUPBase {
    //TODO
    //NSMutableDictionary<NSString*, NSObject*>* _items;
    void* _pimpl;
}


- (instancetype) init;
- (instancetype) initWithImpl:(void*)config;//pulse::Config


// Config*
- (BOOL) unwrap:(void*)config;



- (BOOL) setNumber:(NSNumber*)number forKey:(NSString*)key;
- (NSNumber*) getNumber:(NSString*)key;
- (NSNumber*) getNumber:(NSString*)key or:(NSNumber*)val;


- (BOOL) setIntNumber:(NSInteger)number forKey:(NSString*)key;
- (NSInteger) getIntNumber:(NSString*)key;
- (NSInteger) getIntNumber:(NSString*)key or:(NSInteger)val;


- (BOOL) setDoubleNumber:(double)number forKey:(NSString*)key;
- (double) getDoubleNumber:(NSString*)key;
- (double) getDoubleNumber:(NSString*)key or:(double)val;



- (BOOL) setString:(NSString*)str forKey:(NSString*)key;
- (BOOL) setStringWithMarshal:(NSString*)str forKey:(NSString*)key;
- (NSString*) getString:(NSString*)key;
- (NSString*) getString:(NSString*)key or:(NSString*)val;



- (BOOL) setData:(NSData*)str forKey:(NSString*)key;
- (NSData*) getData:(NSString*)key;
//- (NSData*) getData:(NSString*)key orNil;





@end

NS_ASSUME_NONNULL_END
