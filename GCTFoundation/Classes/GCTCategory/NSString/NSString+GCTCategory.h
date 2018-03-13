//
//  NSString+GCTCategory.h
//  GCTFoundationDemo
//
//  Created by Later on 2018/3/13.
//  Copyright © 2018年 GEEKCODE.In. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, GCTNSStringSubstringRoundOptision) {
    GCTNSStringSubstringRoundOptisionUp,
    GCTNSStringSubstringRoundOptisionDown
};

NS_ASSUME_NONNULL_BEGIN

@interface NSString (GCTCategory)

/**
 是否为空
 */
- (BOOL)gct_isEmpty;

/**
 判断是否为整形
 */
- (BOOL)gct_isInteger;

/**
 判断是否为浮点形
 */
- (BOOL)gct_isFloat;

/**
 判断是否有特殊字符
 */
- (BOOL)gct_hasSpecialcharacters;

/**
 判断是否含有数字
 */
- (BOOL)gct_hasNumder;

/**
 匹配Email
 */
- (BOOL)gct_isEmail;

/**
 匹配URL
 */
- (BOOL)gct_isUrl;

/**
 匹配电话号码
 */
- (BOOL)gct_isTelephone;

/**
 匹配身份证号码
 */
- (BOOL)gct_isIdCard;

/**
 是否支持Zip编码
 */
- (BOOL)gct_isValidZipcode;

/**
 匹配数字
 */
- (BOOL)gct_isNumbers;

/**
 匹配英文字母
 */
- (BOOL)gct_isLetter;

/**
 匹配大写英文字母
 */
- (BOOL)gct_isCapitalLetter;

/**
 匹配小写英文字母
 */
- (BOOL)gct_isSmallLetter;

/**
 匹配小写英文字母
 */
- (BOOL)gct_isLetterAndNumbers;

/**
 匹配中文，英文字母和数字及_
 */
- (BOOL)gct_isChineseAndLetterAndNumberAndBelowLine;

/**
 匹配中文，英文字母和数字及_ 并限制字数
 */
- (BOOL)gct_isChineseAndLetterAndNumberAndBelowLine4to10;

/**
 匹配含有汉字、数字、字母、下划线不能以下划线开头和结尾
 */
- (BOOL)gct_isChineseAndLetterAndNumberAndBelowLineNotFirstOrLast;

/**
 清除表情
 */
- (NSString *)gct_removeEmoji;

/**
 是否包含emoji表情
 */
- (BOOL)gct_containsEmoji;

/**
 判断是否包含某个子字符串
 
 @param string 子字符串
 */
- (BOOL)gct_hasIncludeString:(NSString *)string;

/**
 去掉头尾的空白字符
 */
- (NSString *)gct_stringByTrimmingWhitespaceAndNewlineCharacters;

/**
 去掉整段的所有空白字符（包括换行符）
 */
- (NSString *)gct_stringByTrimingAllWhiteSpace;

/**
 将文字中的换行符替换为空格
 */
- (NSString *)gct_stringByTrimingLineBreakCharacter;

/**
 * 用正则表达式匹配的方式去除字符串里一些特殊字符，避免UI上的展示问题
 */
- (NSString *)gct_removeMagicalChar;

/**
 计算文本长度
 @tag:
 中文 2 个字符
 英文 1 个字符
 */
- (NSUInteger)gct_length;

/**
 从指定的 index 开始裁剪字符串（不会将 emoji 等拆散）
 
 @eg:"🍎🍌"，长度为4，如调用 [string gct_substringFromIndex:1 roundOption:GCTNSStringSubstringRoundOptisionUp ASCIICharacterAsTwo:NO]，将返回 "🍎🍌"
 若调用系统的 [string substringFromIndex:1]，将返回“？🍌”，第一个 emoji 从中间被裁减
 
 @param index 裁剪开始 index
 @param roundOption 裁剪长度 向上取整，还是向下取整
 @param ASCIICharacterAsTwo 是否按照 英文 1 个字符长度，中文 2 个字符串度的方式裁剪
 @return 裁剪结束的字符
 */
- (NSString *)gct_substringFromIndex:(NSUInteger)index roundOption:(GCTNSStringSubstringRoundOptision)roundOption ASCIICharacterAsTwo:(BOOL)ASCIICharacterAsTwo;

/**
 相当于 `gct_substringFromIndex: roundOption:GCTNSStringSubstringRoundOptisionDown` ASCIICharacterAsTwo:NO
 
 @see gct_substringFromIndex:roundOption:ASCIICharacterAsTwo:
 */
- (NSString *)gct_substringFromIndex:(NSUInteger)index;

/**
 从字符串开始裁剪到指定inde，裁剪会取整，避免将 emoji 裁剪才散
 
 @eg:
 例如对于字符串“😊😞”，它的长度为4，若调用 [string gct_substringToIndex:1]，将返回“😊”;
 若调用系统的 [string substringToIndex:1]，将返回“?”。
 
 @param index 要裁剪到哪个 index
 @param roundOption 向上取整 或 想先去整
 @param ASCIICharacterAsTwo 是否按照 英文 1 个字符长度、中文 2 个字符长度的方式来裁剪
 @return 裁剪结束的字符串
 */
- (NSString *)gct_substringToIndex:(NSUInteger)index roundOption:(GCTNSStringSubstringRoundOptision)roundOption ASCIICharacterAsTwo:(BOOL)ASCIICharacterAsTwo;

/**
 相当于 `gct_substringToIndex:roundOption:GCTNSStringSubstringRoundOptisionDown` ASCIICharacterAsTwo:NO
 
 @see gct_substringToIndex:roundOption:ASCIICharacterAsTwo:
 */
- (NSString *)gct_substringToIndex:(NSUInteger)index;

/**
 将字符串里指定 range 的子字符串裁剪出来，裁剪会取整，避免将 emoji 裁剪才散
 
 @eg:
 例如对于字符串“😊😞”，它的长度为4，裁剪 (0, 1) 得到的是空字符串，若调用系统的方法，得到的是空字符串，若是 [string gct_substringWithRange:]，将返回“😊”;
 
 @param range 要裁剪的文字位置
 @param roundOption 向上取整 或 想先去整
 @param ASCIICharacterAsTwo 是否按照 英文 1 个字符长度、中文 2 个字符长度的方式来裁剪
 @return 裁剪结束的字符串
 */
- (NSString *)gct_substringWithRange:(NSRange)range roundOption:(GCTNSStringSubstringRoundOptision)roundOption ASCIICharacterAsTwo:(BOOL)ASCIICharacterAsTwo;

/**
 相当于 `gct_substringWithRange:roundOption:GCTNSStringSubstringRoundOptisionDown` ASCIICharacterAsTwo:NO
 
 @see gct_substringWithRange:roundOption:ASCIICharacterAsTwo:
 */
- (NSString *)gct_substringWithRange:(NSRange)range;

/**
 移除指定位置的字符，可兼容emoji表情的情况（一个emoji表情占1-4个length）
 
 @param index 要删除的位置
 */
- (NSString *)gct_stringByRemoveCharacterAtIndex:(NSUInteger)index;

/**
 移除最后一个字符，可兼容emoji表情的情况（一个emoji表情占1-4个length）
 
 @see `gct_stringByRemoveCharacterAtIndex:`
 */
- (NSString *)gct_stringByRemoveLastCharacter;

/**
 将十进制数字转换成十六进制的数字的字符串
 eg:"10" -> "A"
 */
+ (NSString *)gct_hexStringWithInteger:(NSInteger)integer;


/**
 字符串转 NSNumber，兼容性：
 @"true" :   @(YES),
 @"yes" :    @(YES),
 @"false" :  @(NO),
 @"no" :     @(NO),
 @"nil" :    [NSNull null],
 @"null" :   [NSNull null],
 @"<null>

 @return 字符串对应 Number
 */
- (NSNumber *)gct_toNumber;
@end
NS_ASSUME_NONNULL_END
