//
//  NSString+GCTPinyinCategory.h
//  GCTFoundationDemo
//
//  Created by Later on 2018/3/13.
//  Copyright © 2018年 GEEKCODE.In. All rights reserved.
//


/**
 汉字转拼音，带音标、不带音标，大写的首字母，小写的首字母
 举个栗子：“汉字”
 转拼音，带音标：[@"汉字" gct_pinyinWithPhoneticSymbol];
 return: hàn zì
 转拼音，不带音标：[@"汉字" gct_pinyin];
 return: han zi
 大写的首字母：[@"汉字" gct_uppercaseFirstLetter];
 return: H
 小写的首字母：[@"汉字" gct_lowercaseFirstLetter];
 return: h
 */
#import <Foundation/Foundation.h>

@interface NSString (GCTPinyinCategory)

/**
 汉字转拼音，带音标
 
 @return 拼音带音标
 */
- (NSString *)gct_pinyinWithPhoneticSymbol;

/**
 汉字转拼音，不带音标

 @return 汉字转拼音，不带音标
 */
- (NSString *)gct_pinyin;

/**
 首字母大写
 
 @return 大写的首字母
 */
- (NSString *)gct_uppercaseFirstLetter;

/**
 首字母小写
 
 @return 小写的首字母
 */
- (NSString *)gct_lowercaseFirstLetter;
@end
