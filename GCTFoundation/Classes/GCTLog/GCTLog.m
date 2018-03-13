//
//  GCTLog.m
//  GCTFoundationDemo
//
//  Created by Later on 2018/3/13.
//  Copyright © 2018年 GEEKCODE.In. All rights reserved.
//

#import "GCTLog.h"


#ifdef DEBUG
static GCTLogLevel aLogLevel = GCTLogLevelAll;
#else
static GCTLogLevel aLogLevel = GCTLogLevelNone;
#endif

static NSMutableDictionary *logMarkDic = nil;

@implementation GCTLog
+ (void)initialize {
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        logMarkDic = [[NSMutableDictionary alloc] init];
        [self setLevelMark:@"📣 [UNKNOW] 📣" forLevel:GCTLogLevelNone];
        [self setLevelMark:@"✉️️ [INFO] ✉️️" forLevel:GCTLogLevelInfo];
        [self setLevelMark:@"⚠️️ [BUG] ⚠️️" forLevel:GCTLogLevelDebug];
        [self setLevelMark:@"🐞 [ERROR] 🐞" forLevel:GCTLogLevelError];
        [self setLevelMark:@"📣 [UNKNOW] 📣" forLevel:GCTLogLevelAll];
    });
}

+ (void)setLogLevel:(GCTLogLevel)logLevel {
    aLogLevel = logLevel;
}
+ (void)setLevelMark:(NSString *)mark forLevel:(GCTLogLevel)level {
    if (mark) {
        [logMarkDic setObject:mark forKey:@(level)];
    }
}
+ (void)logWithFile:(const char *)file line:(int)line func:(const char *)func level:(GCTLogLevel)level message:(NSString *)fmt, ... {
    if (!fmt) {
        fmt = @"";
    }
#ifndef DEBUG
    aLogLevel = RRCNSLogLevelNone;
#endif
    if (aLogLevel & level) {
        NSString *levelString = logMarkDic[@(level)];
        va_list args;
        va_start(args, fmt);
        NSString *message = [[NSString alloc] initWithFormat:fmt arguments:args];
        va_end(args);
        fprintf(stderr,"\n***************** RRCNSLog [BEGAIN] **********************\n RRCNSLogLevel : %s \n RRCNSLogClass : %s \n RRCNSLogLine : [Line %d] \n RRCNSLogFunc : %s \n RRCNSLogMessage : %s \n", [levelString UTF8String], [[[NSString stringWithUTF8String:file] lastPathComponent] UTF8String], line, func, [message UTF8String]);
    }
}

@end
