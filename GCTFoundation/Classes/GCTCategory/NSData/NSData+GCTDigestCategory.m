//
//  NSData+GCTDigestCategory.m
//  GCTFoundationDemo
//
//  Created by Later on 2018/3/13.
//  Copyright © 2018年 GEEKCODE.In. All rights reserved.
//

#import "NSData+GCTDigestCategory.h"
#import <CommonCrypto/CommonCrypto.h>

static const char base64EncodingTable[64]
= "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
static const short base64DecodingTable[256] = {
    -2, -2, -2, -2, -2, -2, -2, -2, -2, -1, -1, -2,  -1,  -1, -2, -2,
    -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2,  -2,  -2, -2, -2,
    -1, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, 62,  -2,  -2, -2, 63,
    52, 53, 54, 55, 56, 57, 58, 59, 60, 61, -2, -2,  -2,  -2, -2, -2,
    -2, 0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10,  11,  12, 13, 14,
    15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, -2,  -2,  -2, -2, -2,
    -2, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36,  37,  38, 39, 40,
    41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, -2,  -2,  -2, -2, -2,
    -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2,  -2,  -2, -2, -2,
    -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2,  -2,  -2, -2, -2,
    -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2,  -2,  -2, -2, -2,
    -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2,  -2,  -2, -2, -2,
    -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2,  -2,  -2, -2, -2,
    -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2,  -2,  -2, -2, -2,
    -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2,  -2,  -2, -2, -2,
    -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2,  -2,  -2, -2, -2
};
@implementation NSData (GCTDigestCategory)

#pragma mark MD2
- (NSString *)gct_md2String {
    unsigned char result[CC_MD2_DIGEST_LENGTH];
    CC_MD2(self.bytes, (CC_LONG)self.length, result);
    NSMutableString *hash = [NSMutableString string];
    for (NSInteger i = 0; i < 16; i++)
        [hash appendFormat:@"%02X", result[i]];
    return hash;
}
- (NSData *)gct_md2Data {
    unsigned char result[CC_MD2_DIGEST_LENGTH];
    CC_MD2(self.bytes, (CC_LONG)self.length, result);
    return [NSData dataWithBytes:result length:CC_MD2_DIGEST_LENGTH];
}
#pragma mark MD4
- (NSString *)gct_md4String {
    unsigned char result[CC_MD4_DIGEST_LENGTH];
    CC_MD4(self.bytes, (CC_LONG)self.length, result);
    NSMutableString *hash = [NSMutableString string];
    for (NSInteger i = 0; i < 16; i++)
        [hash appendFormat:@"%02X", result[i]];
    return hash;
}
- (NSData *)gct_md4Data {
    unsigned char result[CC_MD4_DIGEST_LENGTH];
    CC_MD4(self.bytes, (CC_LONG)self.length, result);
    return [NSData dataWithBytes:result length:CC_MD4_DIGEST_LENGTH];
}
#pragma mark MD5
- (NSString *)gct_md5String {
    unsigned char result[CC_MD5_DIGEST_LENGTH];
    CC_MD5(self.bytes, (CC_LONG)self.length, result);
    NSMutableString *hash = [NSMutableString string];
    for (NSInteger i = 0; i < 16; i++)
        [hash appendFormat:@"%02X", result[i]];
    return hash;
}
- (NSData *)gct_md5Data {
    unsigned char result[CC_MD5_DIGEST_LENGTH];
    CC_MD5(self.bytes, (CC_LONG)self.length, result);
    return [NSData dataWithBytes:result length:CC_MD5_DIGEST_LENGTH];
}
#pragma mark SHA1
- (NSString *)gct_sha1String {
    unsigned char result[CC_SHA1_DIGEST_LENGTH];
    CC_SHA1(self.bytes, (CC_LONG)self.length, result);
    NSMutableString *hash = [NSMutableString
                             stringWithCapacity:CC_SHA1_DIGEST_LENGTH * 2];
    for (NSInteger i = 0; i < CC_SHA1_DIGEST_LENGTH; i++) {
        [hash appendFormat:@"%02x", result[i]];
    }
    return hash;
}
- (NSData *)gct_sha1Data {
    unsigned char result[CC_SHA1_DIGEST_LENGTH];
    CC_SHA1(self.bytes, (CC_LONG)self.length, result);
    return [NSData dataWithBytes:result length:CC_SHA1_DIGEST_LENGTH];
}
#pragma mark SHA224
- (NSString *)gct_sha224String {
    unsigned char result[CC_SHA224_DIGEST_LENGTH];
    CC_SHA224(self.bytes, (CC_LONG)self.length, result);
    NSMutableString *hash = [NSMutableString
                             stringWithCapacity:CC_SHA224_DIGEST_LENGTH * 2];
    for (NSInteger i = 0; i < CC_SHA224_DIGEST_LENGTH; i++) {
        [hash appendFormat:@"%02x", result[i]];
    }
    return hash;
}
- (NSData *)gct_sha224Data {
    unsigned char result[CC_SHA224_DIGEST_LENGTH];
    CC_SHA224(self.bytes, (CC_LONG)self.length, result);
    return [NSData dataWithBytes:result length:CC_SHA224_DIGEST_LENGTH];
}
#pragma mark SHA256
- (NSString *)gct_sha256String {
    unsigned char result[CC_SHA256_DIGEST_LENGTH];
    CC_SHA256(self.bytes, (CC_LONG)self.length, result);
    NSMutableString *hash = [NSMutableString
                             stringWithCapacity:CC_SHA256_DIGEST_LENGTH * 2];
    for (NSInteger i = 0; i < CC_SHA256_DIGEST_LENGTH; i++) {
        [hash appendFormat:@"%02x", result[i]];
    }
    return hash;
}
- (NSData *)gct_sha256Data {
    unsigned char result[CC_SHA256_DIGEST_LENGTH];
    CC_SHA256(self.bytes, (CC_LONG)self.length, result);
    return [NSData dataWithBytes:result length:CC_SHA256_DIGEST_LENGTH];
}
#pragma mark SHA384
- (NSString *)gct_sha384String {
    unsigned char result[CC_SHA384_DIGEST_LENGTH];
    CC_SHA384(self.bytes, (CC_LONG)self.length, result);
    NSMutableString *hash = [NSMutableString
                             stringWithCapacity:CC_SHA384_DIGEST_LENGTH * 2];
    for (NSInteger i = 0; i < CC_SHA384_DIGEST_LENGTH; i++) {
        [hash appendFormat:@"%02x", result[i]];
    }
    return hash;
}
- (NSData *)gct_sha384Data {
    unsigned char result[CC_SHA384_DIGEST_LENGTH];
    CC_SHA384(self.bytes, (CC_LONG)self.length, result);
    return [NSData dataWithBytes:result length:CC_SHA384_DIGEST_LENGTH];
}
#pragma mark SHA512
- (NSString *)gct_sha512String {
    unsigned char result[CC_SHA512_DIGEST_LENGTH];
    CC_SHA512(self.bytes, (CC_LONG)self.length, result);
    NSMutableString *hash = [NSMutableString
                             stringWithCapacity:CC_SHA512_DIGEST_LENGTH * 2];
    for (NSInteger i = 0; i < CC_SHA512_DIGEST_LENGTH; i++) {
        [hash appendFormat:@"%02x", result[i]];
    }
    return hash;
}
- (NSData *)gct_sha512Data {
    unsigned char result[CC_SHA512_DIGEST_LENGTH];
    CC_SHA512(self.bytes, (CC_LONG)self.length, result);
    return [NSData dataWithBytes:result length:CC_SHA512_DIGEST_LENGTH];
}
#pragma mark hmacMD5
- (NSString *)gct_hmacMD5StringWithKey:(NSString *)key {
    return [self gct_hmacStringUsingAlg:kCCHmacAlgMD5 withKey:key];
}
- (NSData *)gct_hmacMD5DataWithKey:(NSData *)key {
    return [self gct_hmacDataUsingAlg:kCCHmacAlgMD5 withKey:key];
}
#pragma mark hmacSHA1
- (NSString *)gct_hmacSHA1StringWithKey:(NSString *)key {
    return [self gct_hmacStringUsingAlg:kCCHmacAlgSHA1 withKey:key];
}
- (NSData *)gct_hmacSHA1DataWithKey:(NSData *)key {
    return [self gct_hmacDataUsingAlg:kCCHmacAlgSHA1 withKey:key];
}
#pragma mark hmacSHA224
- (NSString *)gct_hmacSHA224StringWithKey:(NSString *)key {
    return [self gct_hmacStringUsingAlg:kCCHmacAlgSHA224 withKey:key];
}
- (NSData *)gct_hmacSHA224DataWithKey:(NSData *)key {
    return [self gct_hmacDataUsingAlg:kCCHmacAlgSHA224 withKey:key];
}
#pragma mark hmacSHA256
- (NSString *)gct_hmacSHA256StringWithKey:(NSString *)key {
    return [self gct_hmacStringUsingAlg:kCCHmacAlgSHA256 withKey:key];
}
- (NSData *)gct_hmacSHA256DataWithKey:(NSData *)key {
    return [self gct_hmacDataUsingAlg:kCCHmacAlgSHA256 withKey:key];
}
#pragma mark hmacSHA384
- (NSString *)gct_hmacSHA384StringWithKey:(NSString *)key {
    return [self gct_hmacStringUsingAlg:kCCHmacAlgSHA384 withKey:key];
}
- (NSData *)gct_hmacSHA384DataWithKey:(NSData *)key {
    return [self gct_hmacDataUsingAlg:kCCHmacAlgSHA384 withKey:key];
}
#pragma mark hmacSHA512
- (NSString *)gct_hmacSHA512StringWithKey:(NSString *)key {
    return [self gct_hmacStringUsingAlg:kCCHmacAlgSHA512 withKey:key];
}
- (NSData *)gct_hmacSHA512DataWithKey:(NSData *)key {
    return [self gct_hmacDataUsingAlg:kCCHmacAlgSHA512 withKey:key];
}
#pragma mark aes256
- (NSData *)gct_aes256EncryptWithKey:(NSData *)key iv:(NSData *)iv {
    if (key.length != 16 && key.length != 24 && key.length != 32) {
        return nil;
    }
    if (iv.length != 16 && iv.length != 0) {
        return nil;
    }
    
    NSData *result = nil;
    size_t bufferSize = self.length + kCCBlockSizeAES128;
    void *buffer = malloc(bufferSize);
    if (!buffer) return nil;
    size_t encryptedSize = 0;
    CCCryptorStatus cryptStatus = CCCrypt(kCCEncrypt,
                                          kCCAlgorithmAES128,
                                          kCCOptionPKCS7Padding,
                                          key.bytes,
                                          key.length,
                                          iv.bytes,
                                          self.bytes,
                                          self.length,
                                          buffer,
                                          bufferSize,
                                          &encryptedSize);
    if (cryptStatus == kCCSuccess) {
        result = [[NSData alloc]initWithBytes:buffer length:encryptedSize];
        free(buffer);
        return result;
    } else {
        free(buffer);
        return nil;
    }
}
- (NSData *)gct_aes256DecryptWithkey:(NSData *)key iv:(NSData *)iv {
    if (key.length != 16 && key.length != 24 && key.length != 32) {
        return nil;
    }
    if (iv.length != 16 && iv.length != 0) {
        return nil;
    }
    
    NSData *result = nil;
    size_t bufferSize = self.length + kCCBlockSizeAES128;
    void *buffer = malloc(bufferSize);
    if (!buffer) return nil;
    size_t encryptedSize = 0;
    CCCryptorStatus cryptStatus = CCCrypt(kCCDecrypt,
                                          kCCAlgorithmAES128,
                                          kCCOptionPKCS7Padding,
                                          key.bytes,
                                          key.length,
                                          iv.bytes,
                                          self.bytes,
                                          self.length,
                                          buffer,
                                          bufferSize,
                                          &encryptedSize);
    if (cryptStatus == kCCSuccess) {
        result = [[NSData alloc]initWithBytes:buffer length:encryptedSize];
        free(buffer);
        return result;
    } else {
        free(buffer);
        return nil;
    }
}
#pragma mark UTF8
- (NSString *)gct_utf8String {
    if (self.length > 0) {
        return [[NSString alloc] initWithData:self encoding:NSUTF8StringEncoding];
    }
    return @"";
}
#pragma mark hex
- (NSString *)gct_hexString {
    NSUInteger length = self.length;
    NSMutableString *result = [NSMutableString stringWithCapacity:length * 2];
    const unsigned char *byte = self.bytes;
    for (NSInteger i = 0; i < length; i++, byte++) {
        [result appendFormat:@"%02X", *byte];
    }
    return result;
}
+ (NSData *)gct_dataWithHexString:(NSString *)hexStr {
    hexStr = [hexStr stringByReplacingOccurrencesOfString:@" " withString:@""];
    hexStr = [hexStr lowercaseString];
    NSUInteger len = hexStr.length;
    if (!len) return nil;
    unichar *buf = malloc(sizeof(unichar) * len);
    if (!buf) return nil;
    [hexStr getCharacters:buf range:NSMakeRange(0, len)];
    
    NSMutableData *result = [NSMutableData data];
    unsigned char bytes;
    char str[3] = { '\0', '\0', '\0' };
    NSInteger i;
    for (i = 0; i < len / 2; i++) {
        str[0] = buf[i * 2];
        str[1] = buf[i * 2 + 1];
        bytes = strtol(str, NULL, 16);
        [result appendBytes:&bytes length:1];
    }
    free(buf);
    return result;
}
#pragma mark base64
- (NSString *)gct_base64EncodedString {
    NSUInteger length = self.length;
    if (length == 0)
        return @"";
    
    NSUInteger out_length = ((length + 2) / 3) * 4;
    uint8_t *output = malloc(((out_length + 2) / 3) * 4);
    if (output == NULL)
        return nil;
    
    const char *input = self.bytes;
    NSInteger i, value;
    for (i = 0; i < length; i += 3) {
        value = 0;
        for (NSInteger j = i; j < i + 3; j++) {
            value <<= 8;
            if (j < length) {
                value |= (0xFF & input[j]);
            }
        }
        NSInteger index = (i / 3) * 4;
        output[index + 0] = base64EncodingTable[(value >> 18) & 0x3F];
        output[index + 1] = base64EncodingTable[(value >> 12) & 0x3F];
        output[index + 2] = ((i + 1) < length)
        ? base64EncodingTable[(value >> 6) & 0x3F]
        : '=';
        output[index + 3] = ((i + 2) < length)
        ? base64EncodingTable[(value >> 0) & 0x3F]
        : '=';
    }
    
    NSString *base64 = [[NSString alloc] initWithBytes:output
                                                length:out_length
                                              encoding:NSASCIIStringEncoding];
    free(output);
    return base64;
}
+ (NSData *)gct_dataWithBase64EncodedString:(NSString *)base64EncodedString {
    NSInteger length = base64EncodedString.length;
    const char *string = [base64EncodedString cStringUsingEncoding:NSASCIIStringEncoding];
    if (string  == NULL)
        return nil;
    
    while (length > 0 && string[length - 1] == '=')
        length--;
    
    NSInteger outputLength = length * 3 / 4;
    NSMutableData *data = [NSMutableData dataWithLength:outputLength];
    if (data == nil)
        return nil;
    if (length == 0)
        return data;
    
    uint8_t *output = data.mutableBytes;
    NSInteger inputPoint = 0;
    NSInteger outputPoint = 0;
    while (inputPoint < length) {
        char i0 = string[inputPoint++];
        char i1 = string[inputPoint++];
        char i2 = inputPoint < length ? string[inputPoint++] : 'A';
        char i3 = inputPoint < length ? string[inputPoint++] : 'A';
        
        output[outputPoint++] = (base64DecodingTable[i0] << 2)
        | (base64DecodingTable[i1] >> 4);
        if (outputPoint < outputLength) {
            output[outputPoint++] = ((base64DecodingTable[i1] & 0xf) << 4)
            | (base64DecodingTable[i2] >> 2);
        }
        if (outputPoint < outputLength) {
            output[outputPoint++] = ((base64DecodingTable[i2] & 0x3) << 6)
            | base64DecodingTable[i3];
        }
    }
    
    return data;
}
#pragma mark jsonValue
- (id)gct_jsonValueDecoded {
    NSError *error = nil;
    id value = [NSJSONSerialization JSONObjectWithData:self options:kNilOptions error:&error];
    if (error) {
        NSLog(@"jsonValueDecoded error:%@", error);
    }
    return value;
}
#pragma mark HMAC private method
- (NSString *)gct_hmacStringUsingAlg:(GCTHmacAlg)alg withKey:(NSString *)key {
    NSAssert(key, @"hmac mast has key");
    CCHmacAlgorithm cAlg;
    size_t size;
    switch (alg) {
        case GCTHmacAlgSHA1: {
            cAlg = kCCHmacAlgSHA1;
            size = CC_SHA1_DIGEST_LENGTH;
        }
            break;
        case GCTHmacAlgMD5: {
            cAlg = kCCHmacAlgMD5;
            size = CC_MD5_DIGEST_LENGTH;
        }
            break;
        case GCTHmacAlgSHA256: {
            cAlg = kCCHmacAlgSHA256;
            size = CC_SHA256_DIGEST_LENGTH;
        }
            break;
        case GCTHmacAlgSHA384: {
            cAlg = kCCHmacAlgSHA384;
            size = CC_SHA384_DIGEST_LENGTH;
        }
            break;
        case GCTHmacAlgSHA224: {
            cAlg = kCCHmacAlgSHA224;
            size = CC_SHA224_DIGEST_LENGTH;
        }
            break;
        case GCTHmacAlgSHA512: {
            cAlg = kCCHmacAlgSHA512;
            size = CC_SHA512_DIGEST_LENGTH;
        }
            break;
        default: return nil;
    }
    
    unsigned char result[size];
    const char *cKey = [key cStringUsingEncoding:NSUTF8StringEncoding];
    CCHmac(cAlg, cKey, strlen(cKey), self.bytes, self.length, result);
    NSMutableString *hash = [NSMutableString stringWithCapacity:size * 2];
    for (NSInteger i = 0; i < size; i++) {
        [hash appendFormat:@"%02x", result[i]];
    }
    return hash;
}
- (NSData *)gct_hmacDataUsingAlg:(GCTHmacAlg)alg withKey:(NSData *)key {
    NSAssert(key, @"hmac mast has key");
    CCHmacAlgorithm cAlg;
    size_t size;
    switch (alg) {
        case GCTHmacAlgSHA1: {
            cAlg = kCCHmacAlgSHA1;
            size = CC_SHA1_DIGEST_LENGTH;
        }
            break;
        case GCTHmacAlgMD5: {
            cAlg = kCCHmacAlgMD5;
            size = CC_MD5_DIGEST_LENGTH;
        }
            break;
        case GCTHmacAlgSHA256: {
            cAlg = kCCHmacAlgSHA256;
            size = CC_SHA256_DIGEST_LENGTH;
        }
            break;
        case GCTHmacAlgSHA384: {
            cAlg = kCCHmacAlgSHA384;
            size = CC_SHA384_DIGEST_LENGTH;
        }
            break;
        case GCTHmacAlgSHA224: {
            cAlg = kCCHmacAlgSHA224;
            size = CC_SHA224_DIGEST_LENGTH;
        }
            break;
        case GCTHmacAlgSHA512: {
            cAlg = kCCHmacAlgSHA512;
            size = CC_SHA512_DIGEST_LENGTH;
        }
            break;
        default: return nil;
    }
    unsigned char result[size];
    CCHmac(cAlg, [key bytes], key.length, self.bytes, self.length, result);
    return [NSData dataWithBytes:result length:size];
}
@end
