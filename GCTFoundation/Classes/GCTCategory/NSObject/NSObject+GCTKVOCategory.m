//
//  NSObject+GCTKVOCategory.m
//  GCTFoundationDemo
//
//  Created by Later on 2018/3/13.
//  Copyright © 2018年 GEEKCODE.In. All rights reserved.
//

#import "NSObject+GCTKVOCategory.h"
#import <objc/runtime.h>

static NSString *const kGCTNSObjectKVOTargetBlocks = @"com.geekcode.kGCTNSObjectKVOTargetBlocks";

@interface _GCTNSObjectKVOBlockTarget : NSObject
@property (nonatomic, copy) void(^block)(__weak id obj, id oldValue, id newValue);
- (instancetype)initWithBlock:(void(^)(__weak id obj, id oldValue, id newValue))block;
@end

@implementation _GCTNSObjectKVOBlockTarget
- (instancetype)initWithBlock:(void(^)(__weak id obj, id oldValue, id newValue))block {
    if (self = [super init]) {
        self.block = block;
    }
    return self;
}
- (void)observeValueForKeyPath:(NSString *)keyPath ofObject:(id)object change:(NSDictionary<NSKeyValueChangeKey,id> *)change context:(void *)context {
    if (!self.block) {
        return;
    }
    
    BOOL isPrior = [[change objectForKey:NSKeyValueChangeNotificationIsPriorKey] boolValue];
    if (isPrior) {
        return;
    }
    
    NSKeyValueChange changeKind = [[change objectForKey:NSKeyValueChangeKindKey] integerValue];
    if (changeKind != NSKeyValueChangeSetting) {
        return;
    }
    
    id oldValue = [change objectForKey:NSKeyValueChangeOldKey];
    if (oldValue == [NSNull null]) {
        oldValue = nil;
    }
    
    id newValue = [change objectForKey:NSKeyValueChangeNewKey];
    if (newValue == [NSNull null]) {
        newValue = nil;
    }
    
    !self.block ?: self.block(object, oldValue, newValue);
}
@end
@implementation NSObject (GCTKVOCategory)

- (void)gct_addObserverBlockForKeyPath:(NSString*)keyPath block:(void (^)(id _Nonnull obj, _Nullable id oldVal, _Nullable id newVal))block {
    if (!keyPath || !block) {
        return;
    }
    
    _GCTNSObjectKVOBlockTarget *target = [[_GCTNSObjectKVOBlockTarget alloc] initWithBlock:block];
    NSMutableDictionary *objectObserverBlocks = [self _gct_allObjectBlocks];
    NSMutableArray *array = nil;
    if ([objectObserverBlocks.allKeys containsObject:keyPath]) {
        array = objectObserverBlocks[keyPath];
    }
    if (!array) {
        array = [[NSMutableArray alloc] init];
        [objectObserverBlocks setObject:array forKey:keyPath];
    }
    [array addObject:target];
    [self addObserver:target forKeyPath:keyPath options:NSKeyValueObservingOptionNew | NSKeyValueObservingOptionOld context:NULL];
}


- (void)gct_removeObserverBlocksForKeyPath:(NSString*)keyPath {
    if (!keyPath) {
        return;
    }
    NSMutableDictionary *objectObserverBlocks = [self _gct_allObjectBlocks];
    NSArray *targets = nil;
    if ([objectObserverBlocks.allKeys containsObject:keyPath]) {
        targets = [objectObserverBlocks objectForKey:keyPath];
        [targets enumerateObjectsUsingBlock:^(id  _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
            [self removeObserver:obj forKeyPath:keyPath];
        }];
        [objectObserverBlocks removeObjectForKey:keyPath];
    }
    
}
- (void)gct_removeObserverBlocks {
    NSMutableDictionary *objectObserverBlocks = [self _gct_allObjectBlocks];
    [objectObserverBlocks enumerateKeysAndObjectsUsingBlock:^(NSString  * _Nonnull keyPath, NSArray  * _Nonnull array, BOOL * _Nonnull stop) {
        [array enumerateObjectsUsingBlock:^(id  _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
            [self removeObserver:obj forKeyPath:keyPath];
        }];
    }];
    [objectObserverBlocks removeAllObjects];
}

- (NSMutableDictionary *)_gct_allObjectBlocks {
    NSMutableDictionary *targets = objc_getAssociatedObject(self, &kGCTNSObjectKVOTargetBlocks);
    if (!targets) {
        targets = [NSMutableDictionary new];
        objc_setAssociatedObject(self, &kGCTNSObjectKVOTargetBlocks, targets, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
    }
    return targets;
}
@end
