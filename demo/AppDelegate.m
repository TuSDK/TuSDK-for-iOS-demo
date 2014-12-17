//
//  AppDelegate.m
//  demo
//
//  Created by idealhack on 14/11/15.
//  Copyright (c) 2014年 idealhack. All rights reserved.
//

#import "AppDelegate.h"
#import "TuSDK/TuSDK.h"
#import "DemoRootViewController.h"

@interface AppDelegate ()

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    
    // 可选: 设置日志输出级别 (默认不输出)
    [TuSDK setLogLevel:lsqLogLevelDEBUG];
    
    // 初始化SDK (请前往 http://tusdk.com 申请秘钥)
    [TuSDK initSdkWithAppKey:@"e922e6526eadf559-00"];
    
    // 可选: 初始化滤镜预览图列表 (默认使用 [TuSDK.filterManager configSampleTaskWithSDK])
    [TuSDK.filterManager configSampleTaskWithVersion:lasFilterVersion
                                         filterNames:@[@"Normal", @"Artistic", @"Brilliant", @"Cheerful", @"Clear", @"Fade", @"Forest", @"Gloss", @"Harmony", @"Instant", @"Lightup", @"Morning", @"Newborn", @"Noir", @"Relaxed", @"Rough", @"Thick", @"Vintage"]
                                          originPath:[TuSDK uiBundlePathWithName:lasFilterSampleDefaultOriginImage]];
    
    
    self.window = [[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]];
    self.window.backgroundColor = [UIColor clearColor];
    
    // 初始化根控制器
    self.window.rootViewController = [[TuSDKICNavigationController alloc]initWithRootViewController:[DemoRootViewController controller]];
    [self.window makeKeyAndVisible];
    
    return YES;
}

- (void)applicationWillResignActive:(UIApplication *)application {
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
}

- (void)applicationDidEnterBackground:(UIApplication *)application {
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}

- (void)applicationWillEnterForeground:(UIApplication *)application {
    // Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering the background.
}

- (void)applicationDidBecomeActive:(UIApplication *)application {
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}

- (void)applicationWillTerminate:(UIApplication *)application {
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}

@end
