
//
//  NSString+GCTCategory.m
//  GCTFoundationDemo
//
//  Created by Later on 2018/3/13.
//  Copyright © 2018年 GEEKCODE.In. All rights reserved.
//

#import "NSString+GCTCategory.h"
#import <UIKit/UIKit.h>

@implementation NSString (GCTCategory)

/**
 是否为空
 */
- (BOOL)gct_isEmpty {
    return [self length] > 0 ? NO : YES;
}

/**
 判断是否为整形
 */
- (BOOL)gct_isInteger {
    NSScanner* scan = [NSScanner scannerWithString:self];
    int val;
    return[scan scanInt:&val] && [scan isAtEnd];
    
}

/**
 判断是否为浮点形
 */
- (BOOL)gct_isFloat {
    NSScanner* scan = [NSScanner scannerWithString:self];
    float val;
    return[scan scanFloat:&val] && [scan isAtEnd];
}

/**
 判断是否有特殊字符
 */
- (BOOL)gct_hasSpecialcharacters {
    NSString *  englishNameRule = @"^[(A-Za-z0-9)*(\u4e00-\u9fa5)*(,|\\.|，|。|\\:|;|：|；|!|！|\\*|\\×|\\(|\\)|\\（|\\）|#|#|\\$|&#|\\$|&|\\^|@|&#|\\$|&|\\^|@|＠|＆|\\￥|\\……)*]+$";
    
    NSPredicate * englishpredicate = [NSPredicate predicateWithFormat:@"SELF MATCHES %@", englishNameRule];
    
    if ([englishpredicate evaluateWithObject:self] == YES) {
        return YES;
    }else{
        return NO;
        
    }
}

/**
 判断是否含有数字
 */
- (BOOL)gct_hasNumder {
    NSString *  englishNameRule = @"[A-Za-z]{2,}|[\u4e00-\u9fa5]{1,}[A-Za-z]+$";
    NSString * chineseNameRule =@"^[\u4e00-\u9fa5]{2,}$";
    
    NSPredicate * englishpredicate = [NSPredicate predicateWithFormat:@"SELF MATCHES %@", englishNameRule];
    NSPredicate *chinesepredicate = [NSPredicate predicateWithFormat:@"SELF MATCHES %@", chineseNameRule];
    
    if ([englishpredicate evaluateWithObject:self] == YES||[chinesepredicate evaluateWithObject:self] == YES) {
        return YES;
    }else{
        return NO;
    }
    
}

/**
 匹配Email
 */
- (BOOL)gct_isEmail {
    NSString *regex = @"[A-Z0-9a-z._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,4}";
    NSPredicate *pred = [NSPredicate predicateWithFormat:@"SELF MATCHES %@", regex];
    return [pred evaluateWithObject:self];
}

/**
 匹配URL
 */
- (BOOL)gct_isUrl {
    NSString *regex = @"http(s)?:\\/\\/([\\w-]+\\.)+[\\w-]+(\\/[\\w- .\\/?%&=]*)?";
    NSPredicate *pred = [NSPredicate predicateWithFormat:@"SELF MATCHES %@", regex];
    return [pred evaluateWithObject:self];
}

/**
 匹配电话号码
 */
- (BOOL)gct_isTelephone {
    NSString * MOBILE = @"^1(3[0-9]|47|5[0-35-9]|8[025-9])\\d{8}$";
    NSString * CM = @"^((13[4-9])|(147)|(15[0-2,7-9])|(178)|(18[2-4,7-8]))\\d{8}|(1705)\\d{7}$";;
    NSString * CU = @"^((13[0-2])|(145)|(15[5-6])|(176)|(18[5,6]))\\d{8}|(1709)\\d{7}$";
    NSString * CT = @"^((133)|(153)|(177)|(18[0,1,9]))\\d{8}$";
    NSString * PHS = @"^0(10|2[0-5789]|\\d{3})\\d{7,8}$";
    NSPredicate *regextestmobile = [NSPredicate predicateWithFormat:@"SELF MATCHES %@", MOBILE];
    NSPredicate *regextestcm = [NSPredicate predicateWithFormat:@"SELF MATCHES %@", CM];
    NSPredicate *regextestcu = [NSPredicate predicateWithFormat:@"SELF MATCHES %@", CU];
    NSPredicate *regextestct = [NSPredicate predicateWithFormat:@"SELF MATCHES %@", CT];
    NSPredicate *regextestphs = [NSPredicate predicateWithFormat:@"SELF MATCHES %@", PHS];
    
    return  [regextestmobile evaluateWithObject:self]   ||
    [regextestphs evaluateWithObject:self]      ||
    [regextestct evaluateWithObject:self]       ||
    [regextestcu evaluateWithObject:self]       ||
    [regextestcm evaluateWithObject:self];
}
- (BOOL)gct_isIdCard {
    //长度不为18的都排除掉
    if (self.length!=18) {
        return NO;
    }
    
    //校验格式
    NSString *regex2 = @"^(^[1-9]\\d{7}((0\\d)|(1[0-2]))(([0|1|2]\\d)|3[0-1])\\d{3}$)|(^[1-9]\\d{5}[1-9]\\d{3}((0\\d)|(1[0-2]))(([0|1|2]\\d)|3[0-1])((\\d{4})|\\d{3}[Xx])$)$";
    NSPredicate *identityCardPredicate = [NSPredicate predicateWithFormat:@"SELF MATCHES %@",regex2];
    BOOL flag = [identityCardPredicate evaluateWithObject:self];
    
    if (!flag) {
        return flag;    //格式错误
    }else {
        //格式正确在判断是否合法
        
        //将前17位加权因子保存在数组里
        NSArray * idCardWiArray = @[@"7", @"9", @"10", @"5", @"8", @"4", @"2", @"1", @"6", @"3", @"7", @"9", @"10", @"5", @"8", @"4", @"2"];
        
        //这是除以11后，可能产生的11位余数、验证码，也保存成数组
        NSArray * idCardYArray = @[@"1", @"0", @"10", @"9", @"8", @"7", @"6", @"5", @"4", @"3", @"2"];
        
        //用来保存前17位各自乖以加权因子后的总和
        NSInteger idCardWiSum = 0;
        for(int i = 0;i < 17;i++)
        {
            NSInteger subStrIndex = [[self substringWithRange:NSMakeRange(i, 1)] integerValue];
            NSInteger idCardWiIndex = [[idCardWiArray objectAtIndex:i] integerValue];
            
            idCardWiSum+= subStrIndex * idCardWiIndex;
            
        }
        
        //计算出校验码所在数组的位置
        NSInteger idCardMod=idCardWiSum%11;
        
        //得到最后一位身份证号码
        NSString * idCardLast= [self substringWithRange:NSMakeRange(17, 1)];
        
        //如果等于2，则说明校验码是10，身份证号码最后一位应该是X
        if(idCardMod==2)
        {
            if([idCardLast isEqualToString:@"X"]||[idCardLast isEqualToString:@"x"])
            {
                return YES;
            }else
            {
                return NO;
            }
        }else{
            //用计算出的验证码与最后一位身份证号码匹配，如果一致，说明通过，否则是无效的身份证号码
            if([idCardLast isEqualToString: [idCardYArray objectAtIndex:idCardMod]])
            {
                return YES;
            }
            else
            {
                return NO;
            }
        }
    }
}
- (BOOL)gct_isValidZipcode {
    const char *cvalue = [self UTF8String];
    
    long len = strlen(cvalue);
    if (len != 6) {
        return NO;
    }
    for (int i = 0; i < len; i++)
    {
        if (!(cvalue[i] >= '0' && cvalue[i] <= '9'))
        {
            return NO;
        }
    }
    return YES;
}

/**
 匹配数字
 */
- (BOOL)gct_isNumbers {
    NSString *regEx = @"^-?\\d+.?\\d?";
    NSPredicate *pred= [NSPredicate predicateWithFormat:@"SELF MATCHES %@", regEx];
    return [pred evaluateWithObject:self];
}

/**
 匹配英文字母
 */
- (BOOL)gct_isLetter {
    NSString *regEx = @"^[A-Za-z]+$";
    NSPredicate *pred = [NSPredicate predicateWithFormat:@"SELF MATCHES %@", regEx];
    return [pred evaluateWithObject:self];
}

/**
 匹配大写英文字母
 */
- (BOOL)gct_isCapitalLetter {
    NSString *regEx = @"^[A-Z]+$";
    NSPredicate *pred = [NSPredicate predicateWithFormat:@"SELF MATCHES %@", regEx];
    return [pred evaluateWithObject:self];
}

/**
 匹配小写英文字母
 */
- (BOOL)gct_isSmallLetter {
    NSString *regEx = @"^[a-z]+$";
    NSPredicate *pred = [NSPredicate predicateWithFormat:@"SELF MATCHES %@", regEx];
    return [pred evaluateWithObject:self];
}

/**
 匹配小写英文字母
 */
- (BOOL)gct_isLetterAndNumbers {
    NSString *regEx = @"^[A-Za-z0-9]+$";
    NSPredicate *pred = [NSPredicate predicateWithFormat:@"SELF MATCHES %@", regEx];
    return [pred evaluateWithObject:self];
}

/**
 匹配中文，英文字母和数字及_
 */
- (BOOL)gct_isChineseAndLetterAndNumberAndBelowLine {
    NSString *regEx = @"^[\u4e00-\u9fa5_a-zA-Z0-9]+$";
    NSPredicate *pred = [NSPredicate predicateWithFormat:@"SELF MATCHES %@", regEx];
    return [pred evaluateWithObject:self];
}

/**
 匹配中文，英文字母和数字及_ 并限制字数
 */
- (BOOL)gct_isChineseAndLetterAndNumberAndBelowLine4to10 {
    NSString *regEx = @"[\u4e00-\u9fa5_a-zA-Z0-9_]{4,10}";
    NSPredicate *pred = [NSPredicate predicateWithFormat:@"SELF MATCHES %@", regEx];
    return [pred evaluateWithObject:self];
}

/**
 匹配含有汉字、数字、字母、下划线不能以下划线开头和结尾
 */
- (BOOL)gct_isChineseAndLetterAndNumberAndBelowLineNotFirstOrLast {
    NSString *regEx = @"^(?!_)(?!.*?_$)[a-zA-Z0-9_\u4e00-\u9fa5]+$";
    NSPredicate *pred = [NSPredicate predicateWithFormat:@"SELF MATCHES %@", regEx];
    return [pred evaluateWithObject:self];
}
#pragma mark -- NSString剔除emoji表情
- (NSString *)gct_removeEmoji {
    __block NSMutableString *temp = [NSMutableString string];
    [self enumerateSubstringsInRange:NSMakeRange(0, self.length) options:NSStringEnumerationByComposedCharacterSequences usingBlock:^(NSString * _Nullable substring, NSRange substringRange, NSRange enclosingRange, BOOL * _Nonnull stop) {
        const unichar hs = [substring characterAtIndex: 0];
        if (0xd800 <= hs && hs <= 0xdbff) {const unichar ls = [substring characterAtIndex: 1];
            const int uc = ((hs - 0xd800) * 0x400) + (ls - 0xdc00) + 0x10000;
            [temp appendString: (0x1d000 <= uc && uc <= 0x1f77f)? @"": substring]; // U+1D000-1F77F
        }else{
            [temp appendString: (0x2100 <= hs && hs <= 0x26ff)? @"": substring]; // U+2100-26FF
            
        }
        
    }];
    return temp;
}
//是否含有表情
- (BOOL)gct_containsEmoji
{
    __block BOOL returnValue = NO;
    
    [self enumerateSubstringsInRange:NSMakeRange(0, [self length])
                             options:NSStringEnumerationByComposedCharacterSequences
                          usingBlock:^(NSString *substring, NSRange substringRange, NSRange enclosingRange, BOOL *stop) {
                              const unichar hs = [substring characterAtIndex:0];
                              if (0xd800 <= hs && hs <= 0xdbff) {
                                  if (substring.length > 1) {
                                      const unichar ls = [substring characterAtIndex:1];
                                      const int uc = ((hs - 0xd800) * 0x400) + (ls - 0xdc00) + 0x10000;
                                      if (0x1d000 <= uc && uc <= 0x1f77f) {
                                          returnValue = YES;
                                      }
                                  }
                              } else if (substring.length > 1) {
                                  const unichar ls = [substring characterAtIndex:1];
                                  if (ls == 0x20e3) {
                                      returnValue = YES;
                                  }
                              } else {
                                  if (0x2100 <= hs && hs <= 0x27ff) {
                                      returnValue = YES;
                                  } else if (0x2B05 <= hs && hs <= 0x2b07) {
                                      returnValue = YES;
                                  } else if (0x2934 <= hs && hs <= 0x2935) {
                                      returnValue = YES;
                                  } else if (0x3297 <= hs && hs <= 0x3299) {
                                      returnValue = YES;
                                  } else if (hs == 0xa9 || hs == 0xae || hs == 0x303d || hs == 0x3030 || hs == 0x2b55 || hs == 0x2b1c || hs == 0x2b1b || hs == 0x2b50) {
                                      returnValue = YES;
                                  }
                              }
                          }];
    
    return returnValue;
}
- (BOOL)gct_hasIncludeString:(NSString *)string {
    if (!string || string.length <= 0) {
        return NO;
    }
    
    if ([self respondsToSelector:@selector(containsString:)]) {
        return [self containsString:string];
    }
    
    return [self rangeOfString:string].location != NSNotFound;
}

- (NSString *)gct_stringByTrimmingWhitespaceAndNewlineCharacters {
    return [self stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]];
}

- (NSString *)gct_stringByTrimingAllWhiteSpace {
    return [self stringByReplacingOccurrencesOfString:@"\\s" withString:@"" options:NSRegularExpressionSearch range:NSMakeRange(0, self.length)];
}

- (NSString *)gct_stringByTrimingLineBreakCharacter {
    return [self stringByReplacingOccurrencesOfString:@"[\r\n]" withString:@" " options:NSRegularExpressionSearch range:NSMakeRange(0, self.length)];
}


+ (NSString *)hexLetterStringWithInteger:(NSInteger)integer {
    NSAssert(integer < 16, @"要转换的数必须是16进制里的个位数，也即小于16，但你传给我是%@", @(integer));
    
    NSString *letter = nil;
    switch (integer) {
        case 10:
            letter = @"A";
            break;
        case 11:
            letter = @"B";
            break;
        case 12:
            letter = @"C";
            break;
        case 13:
            letter = @"D";
            break;
        case 14:
            letter = @"E";
            break;
        case 15:
            letter = @"F";
            break;
        default:
            letter = [[NSString alloc]initWithFormat:@"%@", @(integer)];
            break;
    }
    return letter;
}

- (NSString *)gct_removeMagicalChar {
    if (self.length == 0) {
        return self;
    }
    
    NSError *error = nil;
    NSRegularExpression *regex = [NSRegularExpression regularExpressionWithPattern:@"[\u0300-\u036F]" options:NSRegularExpressionCaseInsensitive error:&error];
    NSString *modifiedString = [regex stringByReplacingMatchesInString:self options:NSMatchingReportProgress range:NSMakeRange(0, self.length) withTemplate:@""];
    return modifiedString;
}

- (NSUInteger)gct_length {
    NSUInteger characterLength = 0;
    char *p = (char *)[self cStringUsingEncoding:NSUnicodeStringEncoding];
    for (NSInteger i = 0, l = [self lengthOfBytesUsingEncoding:NSUnicodeStringEncoding]; i < l; i++) {
        if (*p) {
            characterLength++;
        }
        p++;
    }
    return characterLength;
}

- (NSUInteger)transformIndexToDefaultModeWithIndex:(NSUInteger)index {
    CGFloat strlength = 0.f;
    NSInteger i = 0;
    for (i = 0; i < self.length; i++) {
        unichar character = [self characterAtIndex:i];
        if (isascii(character)) {
            strlength += 1;
        } else {
            strlength += 2;
        }
        if (strlength >= index + 1) return i;
    }
    return 0;
}

- (NSRange)transformRangeToDefaultModeWithRange:(NSRange)range {
    CGFloat strlength = 0.f;
    NSRange resultRange = NSMakeRange(NSNotFound, 0);
    NSInteger i = 0;
    for (i = 0; i < self.length; i++) {
        unichar character = [self characterAtIndex:i];
        if (isascii(character)) {
            strlength += 1;
        } else {
            strlength += 2;
        }
        if (strlength >= range.location + 1) {
            if (resultRange.location == NSNotFound) {
                resultRange.location = i;
            }
            
            if (range.length > 0 && strlength >= NSMaxRange(range)) {
                resultRange.length = i - resultRange.location + (strlength == NSMaxRange(range) ? 1 : 0);
                return resultRange;
            }
        }
    }
    return resultRange;
}

- (NSString *)gct_substringFromIndex:(NSUInteger)index roundOption:(GCTNSStringSubstringRoundOptision)roundOption ASCIICharacterAsTwo:(BOOL)ASCIICharacterAsTwo {
    index = ASCIICharacterAsTwo ? [self transformIndexToDefaultModeWithIndex:index] : index;
    NSRange range = [self rangeOfComposedCharacterSequenceAtIndex:index];
    return [self substringFromIndex:roundOption == GCTNSStringSubstringRoundOptisionDown ? NSMaxRange(range) : range.location];
}

- (NSString *)gct_substringFromIndex:(NSUInteger)index {
    return [self gct_substringFromIndex:index roundOption:GCTNSStringSubstringRoundOptisionDown ASCIICharacterAsTwo:NO];
}

- (NSString *)gct_substringToIndex:(NSUInteger)index roundOption:(GCTNSStringSubstringRoundOptision)roundOption ASCIICharacterAsTwo:(BOOL)ASCIICharacterAsTwo {
    index = ASCIICharacterAsTwo ? [self transformIndexToDefaultModeWithIndex:index] : index;
    NSRange range = [self rangeOfComposedCharacterSequenceAtIndex:index];
    return [self substringToIndex:roundOption == GCTNSStringSubstringRoundOptisionDown ? range.location : NSMaxRange(range)];
}

- (NSString *)gct_substringToIndex:(NSUInteger)index {
    return [self gct_substringToIndex:index roundOption:GCTNSStringSubstringRoundOptisionDown ASCIICharacterAsTwo:NO];
}

- (NSString *)gct_substringWithRange:(NSRange)range roundOption:(GCTNSStringSubstringRoundOptision)roundOption ASCIICharacterAsTwo:(BOOL)ASCIICharacterAsTwo {
    range = ASCIICharacterAsTwo ? [self transformRangeToDefaultModeWithRange:range] : range;
    NSRange characterSequencesRange = roundOption == GCTNSStringSubstringRoundOptisionDown ? [self downRoundRangeOfComposedCharacterSequencesForRange:range] : [self rangeOfComposedCharacterSequencesForRange:range];
    NSString *resultString = [self substringWithRange:characterSequencesRange];
    return resultString;
}

- (NSString *)gct_substringWithRange:(NSRange)range {
    return [self gct_substringWithRange:range roundOption:GCTNSStringSubstringRoundOptisionDown ASCIICharacterAsTwo:NO];
}

- (NSRange)downRoundRangeOfComposedCharacterSequencesForRange:(NSRange)range {
    if (range.length == 0) {
        return range;
    }
    
    NSRange resultRange = [self rangeOfComposedCharacterSequencesForRange:range];
    if (NSMaxRange(resultRange) > NSMaxRange(range)) {
        return [self downRoundRangeOfComposedCharacterSequencesForRange:NSMakeRange(range.location, range.length - 1)];
    }
    return resultRange;
}

- (NSString *)gct_stringByRemoveCharacterAtIndex:(NSUInteger)index {
    NSRange rangeForRemove = [self rangeOfComposedCharacterSequenceAtIndex:index];
    NSString *resultString = [self stringByReplacingCharactersInRange:rangeForRemove withString:@""];
    return resultString;
}

- (NSString *)gct_stringByRemoveLastCharacter {
    return [self gct_stringByRemoveCharacterAtIndex:self.length - 1];
}

+ (NSString *)gct_hexStringWithInteger:(NSInteger)integer {
    NSString *hexString = @"";
    NSInteger remainder = 0;
    for (NSInteger i = 0; i < 9; i++) {
        remainder = integer % 16;
        integer = integer / 16;
        NSString *letter = [self hexLetterStringWithInteger:remainder];
        hexString = [letter stringByAppendingString:hexString];
        if (integer == 0) {
            break;
        }
        
    }
    return hexString;
}

- (NSNumber *)gct_toNumber {
    
    NSString *str = [[self gct_stringByTrimmingWhitespaceAndNewlineCharacters] lowercaseString];
    if (!str || !str.length) {
        return nil;
    }
    
    static NSDictionary *dic;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        dic = @{@"true" :   @(YES),
                @"yes" :    @(YES),
                @"false" :  @(NO),
                @"no" :     @(NO),
                @"nil" :    [NSNull null],
                @"null" :   [NSNull null],
                @"<null>" : [NSNull null]};
    });
    id num = dic[str];
    if (num) {
        if (num == [NSNull null]) return nil;
        return num;
    }
    
    // hex number
    int sign = 0;
    if ([str hasPrefix:@"0x"]) sign = 1;
    else if ([str hasPrefix:@"-0x"]) sign = -1;
    if (sign != 0) {
        NSScanner *scan = [NSScanner scannerWithString:str];
        unsigned num = -1;
        BOOL suc = [scan scanHexInt:&num];
        if (suc)
            return [NSNumber numberWithLong:((long)num * sign)];
        else
            return nil;
    }
    // normal number
    NSNumberFormatter *formatter = [[NSNumberFormatter alloc] init];
    [formatter setNumberStyle:NSNumberFormatterDecimalStyle];
    return [formatter numberFromString:self];
}

@end

