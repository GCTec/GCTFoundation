//
//  NSObject+GCTKVOCategory.h
//  GCTFoundationDemo
//
//  Created by Later on 2018/3/13.
//  Copyright © 2018年 GEEKCODE.In. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@interface NSObject (GCTKVOCategory)

/**
 给对象添加一个 kvo 观察者响应的 block
 
 @param keyPath 观察者注册对应的键值，不能为 nil
 @param block 键值对应 value 发生改变时，做出响应的 block 回调
 */
- (void)gct_addObserverBlockForKeyPath:(NSString*)keyPath block:(void (^)(id _Nonnull obj, _Nullable id oldVal, _Nullable id newVal))block;

/**
 移除所有 keyPath 注册的响应 block
 
 @param keyPath 观察者注册的对应的键值，不能为 nil
 */
- (void)gct_removeObserverBlocksForKeyPath:(NSString*)keyPath;

/**
 移除已经注册的所有 kvo block
 */
- (void)gct_removeObserverBlocks;
@end
NS_ASSUME_NONNULL_END
