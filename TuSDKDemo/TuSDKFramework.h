//
//  TuSDKFramework.h
//  TuSDKDemo
//
//  Created by Clear Hu on 15/4/24.
//  Copyright (c) 2015年 tusdk.com. All rights reserved.
//

/**
 * ！！！！！！！！！！！！！！！！！！！！！！！！！特别提示信息要长！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！
 * 关于TuSDK体积（SDK编译后仅为1.9MB）：
 * 1,如果您不需要使用本地贴纸功能，或仅需要使用在线贴纸功能，请删除/app/TuSDK.bundle/stickers文件夹
 * 2,如果您仅需要几款滤镜，您可以删除/app/TuSDK.bundle/textures下的*.gsce文件
 * 3,如果您不需要使用滤镜功能，请删除/app/TuSDK.bundle/textures文件夹
 * 4,TuSDK在线管理功能请访问：http://tusdk.com/
 *
 * IOS编译Framework知识：
 * Framework包含armv7,arm64等不同CPU的编译结果的集合；
 * 其中每种CPU编译结果还包含Debug以及Realse两种子结果；
 * 当集成某个Framework（假如TuSDK.Framework物理文件大小为30MB），编译成APP发布后，实际大小约为不到2MB
 *
 * 开发文档:http://tusdk.com/docs/ios/api/
 */

//#import "TuSDKGeeV1.h"
#import <TuSDKGeeV1/TuSDKGeeV1.h>

//#import "TuSDKGeeV2.h"
#import <TuSDKGeeV2/TuSDKGeeV2.h>

