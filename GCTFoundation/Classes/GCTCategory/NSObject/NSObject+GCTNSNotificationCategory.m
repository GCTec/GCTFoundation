//
//  NSObject+GCTNSNotificationCategory.m
//  GCTFoundationDemo
//
//  Created by Later on 2018/3/13.
//  Copyright © 2018年 GEEKCODE.In. All rights reserved.
//

#import "NSObject+GCTNSNotificationCategory.h"
#import <objc/runtime.h>

@interface _GCTNSNotificationBlockTarget : NSObject
@property (nonatomic, copy) void(^block)(NSNotification *notification);
@end

@implementation _GCTNSNotificationBlockTarget
- (instancetype)initWithObserveBlock:(void(^)(NSNotification *))observeBlock {
    if (self = [super init]) {
        self.block = observeBlock;
    }
    return self;
}
- (void)_gct_notificationObjectDoNotification:(NSNotification *)notification{
    !self.block ?: self.block(notification);
}
@end
static NSString *const kGCTNSNotificationTargetBlocks = @"com.geekcode.kGCTNSNotificationTargetBlocks";

@implementation NSObject (GCTNSNotificationCategory)

-(void)gct_addObserverBlock:(void(^)(NSNotification *))observerBlock name:(NSString *)name object:(id)object{
    _GCTNSNotificationBlockTarget *notificationObject = [[_GCTNSNotificationBlockTarget alloc] initWithObserveBlock:observerBlock];
    NSMutableDictionary *dic = [self _gct_allObserverObjects];
    NSMutableArray *arr = dic[name];
    if (!arr) {
        arr = [NSMutableArray new];
        dic[name] = arr;
    }
    [arr addObject:notificationObject];
    [[NSNotificationCenter defaultCenter] removeObserver:notificationObject name:name object:object];
    [[NSNotificationCenter defaultCenter] addObserver:notificationObject selector:@selector(_gct_notificationObjectDoNotification:) name:name object:object];
}

#pragma mark post

-(void)gct_postNotification:(NSNotification *)notification {
    [[NSNotificationCenter defaultCenter] postNotification:notification];
}

-(void)gct_postNotificationName:(NSString *)name object:(id)object {
    [[NSNotificationCenter defaultCenter] postNotificationName:name object:object];
}

-(void)gct_postNotificationName:(NSString *)name object:(id)object userInfo:(NSDictionary *)userInfo {
    [[NSNotificationCenter defaultCenter] postNotificationName:name object:object userInfo:userInfo];
}

#pragma mark remove

-(void)gct_removeObservers {
    NSMutableDictionary *dic = [self _gct_allObserverObjects];
    [dic enumerateKeysAndObjectsUsingBlock:^(id  _Nonnull key, id  _Nonnull obj, BOOL * _Nonnull stop) {
        [obj enumerateObjectsUsingBlock:^(id  _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
            [[NSNotificationCenter defaultCenter] removeObserver:obj];
            
        }];
    }];
}

-(void)gct_removeObserverWithName:(NSString *)name object:(id)object {
    NSMutableDictionary *dic = [self _gct_allObserverObjects];
    NSMutableArray *arr = dic[name];
    [arr enumerateObjectsUsingBlock:^(id  _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
        [[NSNotificationCenter defaultCenter] removeObserver:obj name:name object:object];
    }];
}

#pragma mark private method

- (NSMutableDictionary *)_gct_allObserverObjects {
    NSMutableDictionary *objects = objc_getAssociatedObject(self, &kGCTNSNotificationTargetBlocks);
    if (!objects) {
        objects = [NSMutableDictionary new];
        objc_setAssociatedObject(self, &kGCTNSNotificationTargetBlocks, objects, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
    }
    return objects;
}
@end
