//
//  NSData+GCTDigestCategory.h
//  GCTFoundationDemo
//
//  Created by Later on 2018/3/13.
//  Copyright © 2018年 GEEKCODE.In. All rights reserved.
//

#import <Foundation/Foundation.h>


typedef NS_ENUM(NSInteger, GCTHmacAlg) {
    GCTHmacAlgSHA1,
    GCTHmacAlgMD5,
    GCTHmacAlgSHA256,
    GCTHmacAlgSHA384,
    GCTHmacAlgSHA512,
    GCTHmacAlgSHA224
};

@interface NSData (GCTDigestCategory)

#pragma mark MD2

/**
 MD2 Digest
 */
- (NSString *)gct_md2String;
- (NSData *)gct_md2Data;

#pragma mark MD4

/**
 MD4 Digest
 */
- (NSString *)gct_md4String;
- (NSData *)gct_md4Data;

#pragma mark MD5

/**
 MD5 Digest
 */
- (NSString *)gct_md5String;
- (NSData *)gct_md5Data;

#pragma mark SHA1

/**
 SHA1 Digest
 */
- (NSString *)gct_sha1String;
- (NSData *)gct_sha1Data;

#pragma mark SHA224

/**
 SHA224 Digest
 */
- (NSString *)gct_sha224String;
- (NSData *)gct_sha224Data;

#pragma mark SHA256

/**
 SHA256 Digest
 */
- (NSString *)gct_sha256String;
- (NSData *)gct_sha256Data;

#pragma mark SHA384

/**
 SHA384 Digest
 */
- (NSString *)gct_sha384String;
- (NSData *)gct_sha384Data;

#pragma mark SHA512

/**
 SHA512 Digest
 */
- (NSString *)gct_sha512String;
- (NSData *)gct_sha512Data;

#pragma mark hmacMD5

/**
 hmacMD5 Digest with key
 */
- (NSString *)gct_hmacMD5StringWithKey:(NSString *)key;
- (NSData *)gct_hmacMD5DataWithKey:(NSData *)key;

#pragma mark hmacSHA1

/**
 hmacSHA1 Digest with key
 */
- (NSString *)gct_hmacSHA1StringWithKey:(NSString *)key;
- (NSData *)gct_hmacSHA1DataWithKey:(NSData *)key;

#pragma mark hmacSHA224

/**
 hmacSHA224 Digest with key
 */
- (NSString *)gct_hmacSHA224StringWithKey:(NSString *)key;
- (NSData *)gct_hmacSHA224DataWithKey:(NSData *)key;

#pragma mark hmacSHA256

/**
 hmacSHA256 Digest with key
 */
- (NSString *)gct_hmacSHA256StringWithKey:(NSString *)key;
- (NSData *)gct_hmacSHA256DataWithKey:(NSData *)key;

#pragma mark hmacSHA384

/**
 hmacSHA384 Digest with key
 */
- (NSString *)gct_hmacSHA384StringWithKey:(NSString *)key;
- (NSData *)gct_hmacSHA384DataWithKey:(NSData *)key;

#pragma mark hmacSHA512

/**
 hmacSHA512 Digest with key
 */
- (NSString *)gct_hmacSHA512StringWithKey:(NSString *)key;
- (NSData *)gct_hmacSHA512DataWithKey:(NSData *)key;

#pragma mark aes256

/**
 aes256 Digest with key and iv(偏移量)
 */
- (NSData *)gct_aes256EncryptWithKey:(NSData *)key iv:(NSData *)iv;
- (NSData *)gct_aes256DecryptWithkey:(NSData *)key iv:(NSData *)iv;

#pragma mark UTF8

/**
 UTF8
 */
- (NSString *)gct_utf8String;

#pragma mark hex

/**
 HEX
 */
- (NSString *)gct_hexString;
+ (NSData *)gct_dataWithHexString:(NSString *)hexStr;

#pragma mark base64

/**
 base64 encode
 */
- (NSString *)gct_base64EncodedString;
+ (NSData *)gct_dataWithBase64EncodedString:(NSString *)base64EncodedString;

#pragma mark jsonValue

/**
 json decode，return array dic or string
 */
- (id)gct_jsonValueDecoded;

#pragma mark HMAC private method

/**
 hmac with GCTHmacAlg and key
 */
- (NSString *)gct_hmacStringUsingAlg:(GCTHmacAlg)alg withKey:(NSString *)key;
- (NSData *)gct_hmacDataUsingAlg:(GCTHmacAlg)alg withKey:(NSData *)key;
@end
