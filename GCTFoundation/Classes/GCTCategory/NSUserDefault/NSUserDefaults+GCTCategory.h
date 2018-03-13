//
//  NSUserDefaults+GCTCategory.h
//  GCTFoundationDemo
//
//  Created by Later on 2018/3/14.
//  Copyright © 2018年 GEEKCODE.In. All rights reserved.
//

/**
 NSUserDefault 执行存储或删除，并直接执行同步操作
 */
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@interface NSUserDefaults (GCTCategory)

/**
 存储object，并且做同步操作
 */
- (void)gct_setObject:(nullable id)value forKey:(NSString *)defaultName;

/**
 存储integerValue，并且做同步操作
 */
- (void)gct_setInteger:(NSInteger)value forKey:(NSString *)defaultName;

/**
 存储floatValue，并且做同步操作
 */
- (void)gct_setFloat:(float)value forKey:(NSString *)defaultName;

/**
 存储doubleFloatValue，并且做同步操作
 */
- (void)gct_setDouble:(double)value forKey:(NSString *)defaultName;

/**
 存储boolValue，并且做同步操作
 */
- (void)gct_setBool:(BOOL)value forKey:(NSString *)defaultName;

/**
 存储url，并且做同步操作
 */
- (void)gct_setURL:(nullable NSURL *)url forKey:(NSString *)defaultName API_AVAILABLE(macos(10.6), ios(4.0), watchos(2.0), tvos(9.0));

/**
 移除defaultName的存储，并且做同步操作
 */
- (void)gct_removeObjectForKey:(NSString *)defaultName;

@end
NS_ASSUME_NONNULL_END
