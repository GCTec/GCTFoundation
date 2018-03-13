//
//  GCTLog.h
//  GCTFoundationDemo
//
//  Created by Later on 2018/3/13.
//  Copyright © 2018年 GEEKCODE.In. All rights reserved.
//


/**
 打印样式：打印一个错误信息
 
 ***************** GCTLog [BEGAIN] **********************
 GCTLogLevel : 📣 [UNKNOW] 📣
 GCTLogClass : ViewController.m
 GCTLogLine : [Line 31]
 GCTLogFunc : -[ViewController viewDidLoad]
 GCTLogMessage : 错误
 
 */

#import <Foundation/Foundation.h>

#ifndef GCTLog
//自定义打印
#define GCTLog(...) [GCTLog logWithFile:__FILE__ line:__LINE__ func:__FUNCTION__ level:GCTLogLevelAll message:__VA_ARGS__]

//打印错误
#define GCTLogError(...) [GCTLog logWithFile:__FILE__ line:__LINE__ func:__FUNCTION__ level:GCTLogLevelError message:__VA_ARGS__]

//打印消息
#define GCTLogInfo(...) [GCTLog logWithFile:__FILE__ line:__LINE__ func:__FUNCTION__ level:GCTLogLevelInfo message:__VA_ARGS__]

//打印Debug
#define RRCLogDebug(...) [GCTLog logWithFile:__FILE__ line:__LINE__ func:__FUNCTION__ level:GCTLogLevelDebug message:__VA_ARGS__]

#endif



/**
 打印level，默认在Debug环境为 RRCNSLogLevelAll 全部打印
 
 - GCTLogLevelNone: 不打印任何信息
 - GCTLogLevelInfo: 只打印 Info 类型
 - GCTLogLevelDebug: 只打印 Debug 类型
 - GCTLogLevelError: 只打印 Error 类型
 - GCTLogLevelAll: Debug 模式，全部打印
 */
typedef NS_OPTIONS(NSUInteger, GCTLogLevel) {
    GCTLogLevelNone = 0,
    GCTLogLevelInfo = 1 << 0,
    GCTLogLevelDebug = 1 << 1,
    GCTLogLevelError = 1 << 2,
    GCTLogLevelAll = GCTLogLevelInfo | GCTLogLevelDebug | GCTLogLevelError
};

#import <Foundation/Foundation.h>

@interface GCTLog : NSObject

/**
 设置 Debug 环境下，打印类型
 */
+ (void)setLogLevel:(GCTLogLevel)logLevel;

/**
 设置不同打印类型下的mask标志
 
 默认：
 GCTLogLevelNone  :   @"📣 [UNKNOW] 📣"
 GCTLogLevelInfo  :   @"✉️️ [INFO] ✉️️"
 GCTLogLevelDebug :   @"⚠️️ [BUG] ⚠️️"
 GCTLogLevelError :   @"🐞 [ERROR] 🐞"
 GCTLogLevelAll   :   @"📣 [UNKNOW] 📣"
 */
+ (void)setLevelMark:(NSString *)mark forLevel:(GCTLogLevel)level;

/**
 打印，包含信息：所在 文件、行、方法、log等级、信息
 */
+ (void)logWithFile:(const char *)file line:(int)line func:(const char *)func level:(GCTLogLevel)level message:(NSString *)fmt, ...;
@end
