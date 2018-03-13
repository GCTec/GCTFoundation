//
//  NSObject+GCTRuntimeCategory.h
//  GCTFoundationDemo
//
//  Created by Later on 2018/3/13.
//  Copyright © 2018年 GEEKCODE.In. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  动态绑定对象所使用的绑定策略类型
 */
typedef NS_ENUM(NSInteger, GCTFoundationObjectAssociationPolicyType) {
    GCTFoundationObjectAssociationPolicyTypeAssign,               // assion
    GCTFoundationObjectAssociationPolicyTypeRetainNonatomic,      // nonatomic, retain
    GCTFoundationObjectAssociationPolicyTypeCopyNonatomic,        // nonatomic, copy
    GCTFoundationObjectAssociationPolicyTypeRetain,               // retain
    GCTFoundationObjectAssociationPolicyTypeCopy                  // copy
};

NS_ASSUME_NONNULL_BEGIN
@interface NSObject (GCTRuntimeCategory)

/**
 动态的交换两个实例方法的实现
 
 @param originalSelector 原系统的实例方法
 @param newSelector      新的实例方法
 
 @return 动态交换实例方法是否成功
 */
+ (BOOL)gct_swizzleInstanceMethod:(SEL)originalSelector with:(SEL)newSelector;

/**
 动态的交换两个类方法的实现
 
 @param originalSelector 原系统的类方法
 @param newSelector      新类方法
 
 @return 动态交换两个类方法是否成功
 */
+ (BOOL)gct_swizzleClassMethod:(SEL)originalSelector with:(SEL)newSelector;

/**
 Class 动态添加实例方法
 
 @param seletor 要添加的实例方法对应的入口
 */
+ (void)gct_addInstanceMethod:(SEL)seletor;

/**
 object 动态添加实例方法
 
 @param seletor 要添加的实例方法对应得入口
 */
- (void)gct_addInstanceMethod:(SEL)seletor;

/**
 根据关键字动态的绑定一个对象
 
 @param value                 动态绑定的对象
 @param key                   动态绑定对象所对应的关键字
 @param associationPolicyType 动态绑定策略
 */
- (void)gct_setAssociateValue:(id)value forKey:(void *)key withAssociationType:(GCTFoundationObjectAssociationPolicyType)associationPolicyType;

/**
 根据关键字获取动态绑定的对象
 
 @param key 动态绑定对应的关键字
 
 @return 根据关键字返回动态绑定的对象
 */
- (id)gct_associatedValueForKey:(void *)key;

/**
 根据关键字移除动态绑定的对象
 
 @param key 动态绑定对象对应的关键字
 */
- (void)gct_removeAssociatedValueForKey:(void *)key;

/**
 移除所有动态绑定过的对象
 */
- (void)gct_removeAssociatedObjects;

/**
 object 获得其类名
 
 @return 对象的类名
 */
- (NSString *)gct_className;

/**
 Class 获得类型
 
 @return 类的类名
 */
+ (NSString *)gct_className;

/**
 获取某个Class的所有属性名
 
 @return 属性名
 */
+ (NSArray *)gct_propertyNames;

/**
 获取对象的属性--值键值对
 
 @return 属性--值键值对
 */
- (NSDictionary *)gct_propertyKeyValues;
@end
NS_ASSUME_NONNULL_END
