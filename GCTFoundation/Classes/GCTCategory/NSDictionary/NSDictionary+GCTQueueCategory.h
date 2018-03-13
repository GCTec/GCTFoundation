//
//  NSDictionary+GCTQueueCategory.h
//  GCTFoundationDemo
//
//  Created by Later on 2018/3/13.
//  Copyright © 2018年 GEEKCODE.In. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSDictionary (GCTQueueCategory)

/**
 enum
 */
- (void)gct_enumKeyValuesInQueue:(dispatch_queue_t)queue block:(void(^)(id key, id value))block;

/**
 map
 */
- (NSDictionary *)gct_mapKeyValuesInQueue:(dispatch_queue_t)queue block:(id(^)(id key, id value))block;

/**
 reduce
 */
- (NSObject *)gct_reduceKeyValuesWithInitialMemo:(__strong id)memo block:(id(^)(id memo, id object, id Key))block;

/**
 filter
 */
- (NSDictionary *)gct_filterKeyValuesInQueue:(dispatch_queue_t)queue block:(BOOL(^)(id key, id value))block;

/**
 reject
 */
- (NSDictionary *)gct_rejectKeyValuesInQueue:(dispatch_queue_t)queue block:(BOOL(^)(id key, id value))block;

/**
 valid all
 */
- (BOOL)gct_validAllKeyValuesInQueue:(dispatch_queue_t)queue block:(BOOL(^)(id key, id value))block;

/**
 valid any
 */
- (BOOL)gct_validAnyKeyValuesInQueue:(dispatch_queue_t)queue block:(BOOL(^)(id key, id value))block;

/**
 count
 */
- (NSNumber *)gct_countKeyValuesInQueue:(dispatch_queue_t)queue block:(BOOL(^)(id key, id value))block;

/**
 max
 */
- (id)gct_maxKeyValueWithComparisonBlock:(NSComparisonResult(^)(id k1, id v1 , id k2, id v2))block;

/**
 min
 */
- (id)gct_minKeyValueWithComparisonBlock:(NSComparisonResult(^)(id k1, id v1 , id k2, id v2))block;
@end
