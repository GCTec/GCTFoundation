//
//  NSArray+GCTQueueCategory.h
//  GCTFoundationDemo
//
//  Created by Later on 2018/3/13.
//  Copyright © 2018年 GEEKCODE.In. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSArray (GCTQueueCategory)
- (void)gct_enumObjectsInQueue:(dispatch_queue_t)queue block:(void(^)(id object, NSUInteger idx))block;
- (NSArray *)gct_mapObjectsInQueue:(dispatch_queue_t)queue block:(id(^)(id object, NSUInteger idx))block;
- (NSObject *)gct_reduceObjectsWithInitialMemo:(__strong id)memo block:(id(^)(id memo, id object))block;
- (NSArray *)gct_filterObjectsInQueue:(dispatch_queue_t)queue block:(BOOL(^)(id object))block;
- (NSArray *)gct_rejectObjectsInQueue:(dispatch_queue_t)queue block:(BOOL(^)(id object))block;
- (BOOL)gct_validAllObjectsInQueue:(dispatch_queue_t)queue block:(BOOL(^)(id object))block;
- (BOOL)gct_validAnyObjectsInQueue:(dispatch_queue_t)queue block:(BOOL(^)(id object))block;
- (NSNumber *)gct_countObjectsInQueue:(dispatch_queue_t)queue block:(BOOL(^)(id object))block;
- (id)gct_maxObjectWithComparisonBlock:(NSComparisonResult(^)(id a, id b))block;
- (id)gct_minObjectWithComparisonBlock:(NSComparisonResult(^)(id a, id b))block;
- (NSDictionary *)gct_groupObjectswithBlock:(id(^)(id obj))block;
- (NSArray *)gct_dropObjectsWhileBlock:(BOOL(^)(id obj))block;

@end
