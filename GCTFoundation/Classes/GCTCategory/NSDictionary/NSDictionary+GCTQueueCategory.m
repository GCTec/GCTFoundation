
//
//  NSDictionary+GCTQueueCategory.m
//  GCTFoundationDemo
//
//  Created by Later on 2018/3/13.
//  Copyright © 2018年 GEEKCODE.In. All rights reserved.
//

#import "NSDictionary+GCTQueueCategory.h"

@implementation NSDictionary (GCTQueueCategory)

- (void)gct_enumKeyValuesInQueue:(dispatch_queue_t)queue block:(void(^)(id key, id value))block {
    if (queue) {
        NSArray *keys = [self allKeys];
        dispatch_apply(keys.count, queue, ^(size_t i) {
            id key = [keys objectAtIndex:i];
            block(key, [self objectForKey:key]);
        });
    }
    else {
        [self enumerateKeysAndObjectsUsingBlock:^(__strong id key, __strong id obj, BOOL *stop) {
            block(key, obj);
        }];
    }
}


- (NSDictionary *)gct_mapKeyValuesInQueue:(dispatch_queue_t)queue block:(id(^)(id key, id value))block {
    NSMutableDictionary *mutDict = [NSMutableDictionary dictionaryWithCapacity:[self.allKeys count]];
    
    if (queue) {
        dispatch_semaphore_t itemLock = dispatch_semaphore_create(2);
        NSArray *keys = self.allKeys;
        dispatch_apply(keys.count, queue, ^(size_t i) {
            id key = [keys objectAtIndex:i];
            id map_o = block(key, [self objectForKey:key]);
            dispatch_semaphore_wait(itemLock, DISPATCH_TIME_FOREVER);
            [mutDict setValue:map_o forKey:key];
            dispatch_semaphore_signal(itemLock);
        });
    }
    
    else {
        for (id key in self) {
            id obj = [self objectForKey:key];
            [mutDict setValue:block(key, obj) forKey:key];
        }
    }
    return [NSDictionary dictionaryWithDictionary:mutDict];
}


- (NSObject *)gct_reduceKeyValuesWithInitialMemo:(__strong id)memo block:(id(^)(id memo, id object, id Key))block {
    for (id key in self.allKeys) {
        id obj = [self objectForKey:key];
        memo = block(memo, key, obj);
    }
    return memo;
}

- (NSDictionary *)gct_filterKeyValuesInQueue:(dispatch_queue_t)queue block:(BOOL(^)(id key, id value)) block {
    NSMutableDictionary *mutDict = [NSMutableDictionary dictionaryWithCapacity:[self.allKeys count]];
    if (queue) {
        dispatch_semaphore_t itemLock = dispatch_semaphore_create(1);
        NSArray *keys = self.allKeys;
        dispatch_apply(keys.count, queue, ^(size_t i) {
            id key = [keys objectAtIndex:i];
            BOOL keep = block(key, [self objectForKey:key]);
            if (keep) {
                dispatch_semaphore_wait(itemLock, DISPATCH_TIME_FOREVER);
                [mutDict setObject:[self objectForKey:key] forKey:key];
                dispatch_semaphore_signal(itemLock);
            }
        });
    }
    else {
        for (id key in self.allKeys) {
            if (block(key, [self objectForKey:key]))
                [mutDict setObject:[self objectForKey:key]  forKey:key];
        }
    }
    return [NSDictionary dictionaryWithDictionary:mutDict];
}

- (NSDictionary *)gct_rejectKeyValuesInQueue:(dispatch_queue_t)queue block:(BOOL(^)(id key, id value)) block {
    NSMutableDictionary *mutDict = [NSMutableDictionary dictionary];
    if (queue) {
        dispatch_semaphore_t itemLock = dispatch_semaphore_create(1);
        NSArray *keys = self.allKeys;
        dispatch_apply(keys.count, queue, ^(size_t i) {
            id key = [keys objectAtIndex:i];
            BOOL keep = !block(key, [self objectForKey:key]);
            if (keep) {
                dispatch_semaphore_wait(itemLock, DISPATCH_TIME_FOREVER);
                [mutDict setObject:[self objectForKey:key] forKey:key];
                dispatch_semaphore_signal(itemLock);
            }
        });
    }
    else {
        for (id key in self.allKeys) {
            if (!block(key, [self objectForKey:key]))
                [mutDict setObject:[self objectForKey:key]  forKey:key];
        }
    }
    return [NSDictionary dictionaryWithDictionary:mutDict];
}

- (BOOL)gct_validAllKeyValuesInQueue:(dispatch_queue_t)queue block:(BOOL(^)(id key, id value)) block {
    __block BOOL validForAll = true;
    
    if (queue) {
        NSArray *keys = self.allKeys;
        dispatch_apply(keys.count, queue, ^(size_t i) {
            if (!validForAll) return;
            id key = [keys objectAtIndex:i];
            validForAll = (validForAll && block(key, [self objectForKey:key]));
        });
    }
    else {
        for (id key in self.allKeys) {
            validForAll = (validForAll && block(key, [self objectForKey:key]));
            if (!validForAll) break;
        }
    }
    return validForAll;
}
- (BOOL)gct_validAnyKeyValuesInQueue:(dispatch_queue_t)queue block:(BOOL(^)(id key, id value)) block {
    __block BOOL validForAny = false;
    
    if (queue) {
        NSArray *keys = self.allKeys;
        dispatch_apply(keys.count, queue, ^(size_t i) {
            if (validForAny) return;
            id key = [keys objectAtIndex:i];
            validForAny = (validForAny || block(key, [self objectForKey:key]));
        });
    }
    else {
        for (id key in self.allKeys) {
            validForAny = (validForAny || block(key, [self objectForKey:key]));
            if (validForAny) break;
        }
    }
    return validForAny;
}
- (NSNumber *)gct_countKeyValuesInQueue:(dispatch_queue_t)queue block:(BOOL(^)(id key, id value))block {
    __block NSInteger ctr = 0;
    
    if (queue) {
        NSArray *keys = self.allKeys;
        dispatch_apply(keys.count, queue, ^(size_t i) {
            id key = [keys objectAtIndex:i];
            if (block(key, [self objectForKey:key])) ctr++;
        });
    }
    else {
        for (id key in self.allKeys) {
            if (block(key, [self objectForKey:key])) ctr++;
        }
    }
    return [NSNumber numberWithInteger:ctr];
}
- (id)gct_maxKeyValueWithComparisonBlock:(NSComparisonResult(^)(id k1, id v1 , id k2, id v2))block {
    if (self.count < 1) return NULL;
    
    id biggest = NULL;
    id biggestKey = @"";
    for (id key in self.allKeys) {
        if (biggest == NULL) {
            biggest = [self objectForKey:key];
            biggestKey = key;
        }
        if (block(biggestKey, biggest, key, [self objectForKey:key]) == NSOrderedAscending) {
            biggest = [self objectForKey:key];
            biggestKey = key;
        }
    }
    return biggest;
}
- (id)gct_minKeyValueWithComparisonBlock:(NSComparisonResult(^)(id k1, id v1 , id k2, id v2))block {
    if (self.count < 1) return NULL;
    
    id smallest = NULL;
    id smallestKey = @"";
    for (id key in self.allKeys) {
        if (smallest == NULL) {
            smallest = [self objectForKey:key];
            smallestKey = key;
        }
        if (block(smallestKey, smallest, key, [self objectForKey:key]) == NSOrderedDescending) {
            smallest = [self objectForKey:key];
            smallestKey = key;
        }
    }
    return smallest;
}

@end
