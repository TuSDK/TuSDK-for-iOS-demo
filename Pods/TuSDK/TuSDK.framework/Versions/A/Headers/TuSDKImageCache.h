//
//  TuSDKImageCache.h
//  TuSDK
//
//  Created by Jimmy Zhao on 16/11/14.
//  Copyright © 2016年 tusdk.com. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface TuSDKImageCache : NSObject
/**
 * The maximum "total cost" of the in-memory image cache. The cost function is the number of pixels held in memory. default 10M
 */
@property (assign, nonatomic) NSUInteger maxMemoryCost;

/**
 * The maximum number of objects the cache should hold.default 20
 */
@property (assign, nonatomic) NSUInteger maxMemoryCountLimit;

/**
 * Returns global shared cache instance
 *
 * @return TuSDKImageCache global instance
 */
+ (TuSDKImageCache *)sharedImageCache;

/**
 * Store an image into memory at the given key.
 *
 * @param image The image to store
 * @param key   The unique image cache key
 */
- (void)storeImage:(UIImage *)image forKey:(NSString *)key;

/**
 * Query the memory cache synchronously.
 *
 * @param key The unique key used to store the wanted image
 */
- (UIImage *)imageFromMemoryCacheForKey:(NSString *)key;

/**
 * Remove the image from memory synchronously
 *
 * @param key The unique image cache key
 */
- (void)removeImageForKey:(NSString *)key;

/**
 * Clear all memory cached images
 */
- (void)clearMemory;

@end
