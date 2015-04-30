//
//  SimpleDefineCamera.m
//  TuSDKDemo
//
//  Created by Clear Hu on 15/4/24.
//  Copyright (c) 2015年 Lasque. All rights reserved.
//

#import "SimpleDefineCamera.h"
#import "SimpleCameraViewController.h"

/**
 *  自定义相机范例
 */
@implementation SimpleDefineCamera
- (instancetype)init;
{
    self = [super initWithGroupId:4 title:NSLocalizedString(@"simple_DefineCamera", @"自定义相机")];
    return self;
}

/**
 *  显示范例
 *
 *  @param controller 启动控制器
 */
- (void)showSimpleWithController:(UIViewController *)controller;
{
    if (!controller) return;
    self.controller = controller;
    
    [self.controller presentViewController:[[SimpleCameraViewController alloc] init] animated:YES completion:nil];
}
@end
