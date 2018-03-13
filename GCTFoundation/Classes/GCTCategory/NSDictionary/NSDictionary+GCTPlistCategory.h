//
//  NSDictionary+GCTPlistCategory.h
//  GCTFoundationDemo
//
//  Created by Later on 2018/3/13.
//  Copyright © 2018年 GEEKCODE.In. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSDictionary (GCTPlistCategory)

/**
 从 plist data 获取 dic

 @param plist plist 文件二进制
 @return dic
 */
+ (NSDictionary *)gct_dictionaryWithPlistData:(NSData *)plist;

/**
 从 plist string 获取 dic

 @param plist plist 字符串
 @return dic
 */
+ (NSDictionary *)gct_dictionaryWithPlistString:(NSString *)plist;

/**
 将 dic 转变为 plist data 二进制

 @return plist 二进制
 */
- (NSData *)gct_plistData;

/**
 将 dic 转变为 plist string

 @return plist string
 */
- (NSString *)gct_plistString;
@end
