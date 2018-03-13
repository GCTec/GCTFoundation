//
//  NSString+GCTPinyinCategory.m
//  GCTFoundationDemo
//
//  Created by Later on 2018/3/13.
//  Copyright © 2018年 GEEKCODE.In. All rights reserved.
//

#import "NSString+GCTPinyinCategory.h"

@implementation NSString (GCTPinyinCategory)

- (NSString *)gct_pinyinWithPhoneticSymbol {
    NSMutableString *cString = [self mutableCopy];
    if (CFStringTransform((__bridge CFMutableStringRef)cString, 0, kCFStringTransformMandarinLatin, NO)) {
        return cString;
    }
    return nil;
}

- (NSString *)gct_pinyin {
    NSMutableString *cString = [[self gct_pinyinWithPhoneticSymbol] mutableCopy];
    if (CFStringTransform((__bridge CFMutableStringRef)cString, 0, kCFStringTransformStripDiacritics, NO)) {
        return cString;
    }
    return nil;
}

- (NSString *)gct_uppercaseFirstLetter {
    NSString *pinyin = [self gct_Pinyin];
    char cFirstLetter = [pinyin characterAtIndex:0];
    return [[NSString stringWithFormat:@"%c", cFirstLetter] uppercaseString];
}

/**
 首字母小写
 
 @return 小写的首字母
 */
- (NSString *)gct_lowercaseFirstLetter {
    NSString *pinyin = [self gct_Pinyin];
    char cFirstLetter = [pinyin characterAtIndex:0];
    return [[NSString stringWithFormat:@"%c", cFirstLetter] lowercaseString];
}
@end
