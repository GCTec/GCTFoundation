//
//  NSString+GCTDigestCategory.m
//  GCTFoundationDemo
//
//  Created by Later on 2018/3/13.
//  Copyright © 2018年 GEEKCODE.In. All rights reserved.
//

#import "NSString+GCTDigestCategory.h"
#import "NSData+GCTDigestCategory.h"

@implementation NSString (GCTDigestCategory)

#pragma mark MD
- (NSString *)gct_md2String {
    return [[self dataUsingEncoding:NSUTF8StringEncoding] gct_md2String];
}

- (NSString *)gct_md4String {
    return [[self dataUsingEncoding:NSUTF8StringEncoding] gct_md4String];
}

- (NSString *)gct_md5String {
    return [[self dataUsingEncoding:NSUTF8StringEncoding] gct_md5String];
}
#pragma mark sha
- (NSString *)gct_sha1String {
    return [[self dataUsingEncoding:NSUTF8StringEncoding] gct_sha1String];
}

- (NSString *)gct_sha224String {
    return [[self dataUsingEncoding:NSUTF8StringEncoding] gct_sha224String];
}

- (NSString *)gct_sha256String {
    return [[self dataUsingEncoding:NSUTF8StringEncoding] gct_sha256String];
}

- (NSString *)gct_sha384String {
    return [[self dataUsingEncoding:NSUTF8StringEncoding] gct_sha384String];
}

- (NSString *)gct_sha512String {
    return [[self dataUsingEncoding:NSUTF8StringEncoding] gct_sha512String];
}

#pragma mark hmac
- (NSString *)gct_hmacMD5StringWithKey:(NSString *)key {
    return [[self dataUsingEncoding:NSUTF8StringEncoding]
            gct_hmacMD5StringWithKey:key];
}

- (NSString *)gct_hmacSHA1StringWithKey:(NSString *)key {
    return [[self dataUsingEncoding:NSUTF8StringEncoding]
            gct_hmacSHA1StringWithKey:key];
}

- (NSString *)gct_hmacSHA224StringWithKey:(NSString *)key {
    return [[self dataUsingEncoding:NSUTF8StringEncoding]
            gct_hmacSHA224StringWithKey:key];
}

- (NSString *)gct_hmacSHA256StringWithKey:(NSString *)key {
    return [[self dataUsingEncoding:NSUTF8StringEncoding]
            gct_hmacSHA256StringWithKey:key];
}

- (NSString *)gct_hmacSHA384StringWithKey:(NSString *)key {
    return [[self dataUsingEncoding:NSUTF8StringEncoding]
            gct_hmacSHA384StringWithKey:key];
}

- (NSString *)gct_hmacSHA512StringWithKey:(NSString *)key {
    return [[self dataUsingEncoding:NSUTF8StringEncoding]
            gct_hmacSHA512StringWithKey:key];
}
#pragma mark base64
- (NSString *)gct_base64EncodedString {
    return [[self dataUsingEncoding:NSUTF8StringEncoding] gct_base64EncodedString];
}

- (NSString *)gct_base64DecodedString{
    NSData *data = [NSData gct_dataWithBase64EncodedString:self];
    return [[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding];
}
#pragma mark URL
- (NSString *)gct_URLEncodeString {
    if ([self respondsToSelector:@selector(stringByAddingPercentEncodingWithAllowedCharacters:)]) {
        return [self stringByAddingPercentEncodingWithAllowedCharacters:[NSCharacterSet URLQueryAllowedCharacterSet]];
    } else {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
        CFStringEncoding cfEncoding = CFStringConvertNSStringEncodingToEncoding(NSUTF8StringEncoding);
        NSString *encoded = (__bridge_transfer NSString *)
        CFURLCreateStringByAddingPercentEscapes(
                                                kCFAllocatorDefault,
                                                (__bridge CFStringRef)self,
                                                NULL,
                                                CFSTR("!#$&'()*+,/:;=?@[]"),
                                                cfEncoding);
        return encoded;
#pragma clang diagnostic pop
    }
}

- (NSString *)gct_URLDecodeString {
    if ([self respondsToSelector:@selector(stringByRemovingPercentEncoding)]) {
        return [self stringByRemovingPercentEncoding];
    } else {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
        CFStringEncoding en = CFStringConvertNSStringEncodingToEncoding(NSUTF8StringEncoding);
        NSString *decoded = [self stringByReplacingOccurrencesOfString:@"+"
                                                            withString:@" "];
        decoded = (__bridge_transfer NSString *)
        CFURLCreateStringByReplacingPercentEscapesUsingEncoding(
                                                                NULL,
                                                                (__bridge CFStringRef)decoded,
                                                                CFSTR(""),
                                                                en);
        return decoded;
#pragma clang diagnostic pop
    }
}
@end
