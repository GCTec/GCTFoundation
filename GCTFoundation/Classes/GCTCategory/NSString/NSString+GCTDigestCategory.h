//
//  NSString+GCTDigestCategory.h
//  GCTFoundationDemo
//
//  Created by Later on 2018/3/13.
//  Copyright © 2018年 GEEKCODE.In. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSString (GCTDigestCategory)

#pragma mark MD

/**
 md2
 */
- (NSString *)gct_md2String;

/**
 md4
 */
- (NSString *)gct_md4String;

/**
 md5
 */
- (NSString *)gct_md5String;

#pragma mark sha

/**
 sha1
 */
- (NSString *)gct_sha1String;

/**
 sha224
 */
- (NSString *)gct_sha224String;

/**
 sha256
 */
- (NSString *)gct_sha256String;

/**
 sha384
 */
- (NSString *)gct_sha384String;

/**
 sha512
 */
- (NSString *)gct_sha512String;

#pragma mark hmac

/**
 hamcMD5
 
 @param key 加密密码
 @return 加密后字符串
 */
- (NSString *)gct_hmacMD5StringWithKey:(NSString *)key;

/**
 hmacSHA1
 
 @param key 加密密码
 @return 加密后字符串
 */
- (NSString *)gct_hmacSHA1StringWithKey:(NSString *)key;

/**
 hmacSHA224
 
 @param key 加密密码
 @return 加密后字符串
 */
- (NSString *)gct_hmacSHA224StringWithKey:(NSString *)key;

/**
 hmacSHA256
 
 @param key 加密密码
 @return 加密后字符串
 */
- (NSString *)gct_hmacSHA256StringWithKey:(NSString *)key;

/**
 hmacSHA384
 
 @param key 加密密码
 @return 加密后字符串
 */
- (NSString *)gct_hmacSHA384StringWithKey:(NSString *)key;

/**
 hmacSHA512
 
 @param key 加密密码
 @return 加密后字符串
 */
- (NSString *)gct_hmacSHA512StringWithKey:(NSString *)key;

#pragma mark base64

/**
 base64编码
 */
- (NSString *)gct_base64EncodedString;

/**
 base64解码
 */
- (NSString *)gct_base64DecodedString;

#pragma mark URL

/**
 url编码
 */
- (NSString *)gct_URLEncodeString;

/**
 url界面
 */
- (NSString *)gct_URLDecodeString;
@end
