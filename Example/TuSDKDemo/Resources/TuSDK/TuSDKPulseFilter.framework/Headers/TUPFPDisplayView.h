//
//  TUPFPDisplayView.h
//  PulseFilterDemo
//
//  Created by tutu on 2020/11/30.
//

#import <Foundation/Foundation.h>
#import <GLKit/GLKit.h>

#import "TUPFPImage.h"

NS_ASSUME_NONNULL_BEGIN

@interface TUPFPDisplayView : GLKView


- (EAGLContext*) getEAGLContext;


//- (instancetype) init:(EAGLContext*)glctx;
//- (void) dealloc;

//- (BOOL)setup:(EAGLContext* _Nullable)glctx;

- (BOOL)setup;
- (void)teardown;

- (void)setClearColor:(UIColor *)clearColor;
- (BOOL)update:(TUPFPImage*) image;
- (BOOL)update:(TUPFPImage*) image atRect:(CGRect) rect;

- (CGRect)getInteractionRect:(CGSize)size;

@end

NS_ASSUME_NONNULL_END
