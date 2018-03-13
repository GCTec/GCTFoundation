//
//  NSObject+GCTRuntimeCategory.m
//  GCTFoundationDemo
//
//  Created by Later on 2018/3/13.
//  Copyright © 2018年 GEEKCODE.In. All rights reserved.
//

#import "NSObject+GCTRuntimeCategory.h"
#import <objc/runtime.h>

/**
 *  动态绑定对象使用的绑定策略
 */
typedef struct _GCT_ObjectAssociationPolicy {
    uintptr_t association;
} GCTObjectAssociationPolicy;
static const GCTObjectAssociationPolicy GCTObjectAssociationPolicyArray[] = {
    OBJC_ASSOCIATION_ASSIGN,                    // GCTFoundationObjectAssociationPolicyTypeAssign
    OBJC_ASSOCIATION_RETAIN_NONATOMIC,          // GCTFoundationObjectAssociationPolicyTypeRetainNonatomic
    OBJC_ASSOCIATION_COPY_NONATOMIC,            // GCTFoundationObjectAssociationPolicyTypeCopyNonatomic
    OBJC_ASSOCIATION_RETAIN,                    // GCTFoundationObjectAssociationPolicyTypeRetain
    OBJC_ASSOCIATION_COPY                       // GCTFoundationObjectAssociationPolicyTypeCopy
};
@implementation NSObject (GCTRuntimeCategory)

+ (BOOL)gct_swizzleInstanceMethod:(SEL)originalSelector with:(SEL)newSelector {
    
    Method originalMethod = class_getInstanceMethod(self, originalSelector);
    Method swizzledMethod = class_getInstanceMethod(self, newSelector);
    BOOL didAddMethod =
    class_addMethod(self,
                    originalSelector,
                    method_getImplementation(swizzledMethod),
                    method_getTypeEncoding(swizzledMethod));
    
    if (didAddMethod) {
        class_replaceMethod(self,
                            newSelector,
                            method_getImplementation(originalMethod),
                            method_getTypeEncoding(originalMethod));
    } else {
        method_exchangeImplementations(originalMethod, swizzledMethod);
    }
    return YES;
}

+ (BOOL)gct_swizzleClassMethod:(SEL)originalSelector with:(SEL)newSelector {
    Class class = object_getClass(self);
    Method originalMethod = class_getInstanceMethod(class, originalSelector);
    Method newMethod = class_getInstanceMethod(class, newSelector);
    if (!originalMethod || !newMethod) return NO;
    method_exchangeImplementations(originalMethod, newMethod);
    return YES;
}

+ (void)gct_addInstanceMethod:(SEL)seletor {
    Method newMethod = class_getInstanceMethod(self, seletor);
    class_addMethod(self, seletor, method_getImplementation(newMethod), method_getTypeEncoding(newMethod));
}

- (void)gct_addInstanceMethod:(SEL)seletor {
    [object_getClass(self) gct_addInstanceMethod:seletor];
}

- (void)gct_setAssociateValue:(id)value forKey:(void *)key withAssociationType:(GCTFoundationObjectAssociationPolicyType)associationPolicyType{
    objc_setAssociatedObject(self, key, value, GCTObjectAssociationPolicyArray[associationPolicyType].association);
}

- (id)gct_associatedValueForKey:(void *)key {
    return objc_getAssociatedObject(self, key);
}

- (void)gct_removeAssociatedValueForKey:(void *)key {
    objc_setAssociatedObject(self, key, nil, GCTObjectAssociationPolicyArray[0].association);
}

- (void)gct_removeAssociatedObjects {
    objc_removeAssociatedObjects(self);
}

- (NSString *)gct_className{
    return [NSString stringWithUTF8String:object_getClassName(self)];
}

+ (NSString *)gct_className{
    return NSStringFromClass(self);
}

+ (NSArray *)gct_propertyNames {
    NSMutableArray *array = [NSMutableArray new];
    uint count;
    objc_property_t *properties = class_copyPropertyList(self, &count);
    for (NSInteger i = 0; i<count; i++) {
        objc_property_t property = properties[i];
        NSString *name = @(property_getName(property));
        [array addObject:name];
    }
    free(properties);
    return array;
}

- (NSDictionary *)gct_propertyKeyValues {
    
    /** 声明一个字典 */
    NSMutableDictionary *dictionary = [NSMutableDictionary dictionary];
    
    /** 得到当前class的所有属性 */
    uint count;
    objc_property_t *properties = class_copyPropertyList([self class], &count);
    
    /** 循环并用KVC得到每个属性的值 */
    for (NSInteger i = 0; i<count; i++) {
        objc_property_t property = properties[i];
        NSString *name = @(property_getName(property));
        id value = [self valueForKey:name]?:@"nil";
        [dictionary setObject:value forKey:name];
    }
    /** 释放 */
    free(properties);
    return dictionary;
}
@end
