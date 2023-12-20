
#import <GLKit/GLKit.h>
#import <CoreGraphics/CGGeometry.h>
#import "TUPPlayer.h"

NS_ASSUME_NONNULL_BEGIN

@interface TUPDisplayView : GLKView


- (EAGLContext*) getEAGLContext;


//- (instancetype) init:(EAGLContext*)glctx;
//- (void) dealloc;


- (BOOL)setup:(EAGLContext* _Nullable)glctx;
- (void)teardown;


- (BOOL) attachPlayer:(TUPPlayer*)player;


- (CGRect) getInteractionRect:(CGSize)size;

/**
 * 添加背景颜色
 * @param clearColor 背景颜色
 */
- (void)setClearColor:(UIColor *)clearColor;


@end

NS_ASSUME_NONNULL_END
