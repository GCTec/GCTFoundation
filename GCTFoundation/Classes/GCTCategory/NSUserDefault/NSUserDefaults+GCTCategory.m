//
//  NSUserDefaults+GCTCategory.m
//  GCTFoundationDemo
//
//  Created by Later on 2018/3/14.
//  Copyright © 2018年 GEEKCODE.In. All rights reserved.
//

#import "NSUserDefaults+GCTCategory.h"

@implementation NSUserDefaults (GCTCategory)
- (void)gct_setObject:(nullable id)value forKey:(NSString *)defaultName {
    [self setObject:value forKey:defaultName];
    [self synchronize];
}

- (void)gct_setInteger:(NSInteger)value forKey:(NSString *)defaultName {
    [self setInteger:value forKey:defaultName];
    [self synchronize];
}

- (void)gct_setFloat:(float)value forKey:(NSString *)defaultName {
    [self setFloat:value forKey:defaultName];
    [self synchronize];
}

- (void)gct_setDouble:(double)value forKey:(NSString *)defaultName {
    [self setDouble:value forKey:defaultName];
    [self synchronize];
}

- (void)gct_setBool:(BOOL)value forKey:(NSString *)defaultName {
    [self setBool:value forKey:defaultName];
    [self synchronize];
}

- (void)gct_setURL:(nullable NSURL *)url forKey:(NSString *)defaultName {
    [self setURL:url forKey:defaultName];
    [self synchronize];
}

- (void)gct_removeObjectForKey:(NSString *)defaultName {
    [self removeObjectForKey:defaultName];
    [self synchronize];
}
@end
