
//
//  NSArray+GCTCategory.m
//  GCTFoundationDemo
//
//  Created by Later on 2018/3/13.
//  Copyright © 2018年 GEEKCODE.In. All rights reserved.
//

#import "NSArray+GCTQueueCategory.h"

@implementation NSArray (GCTQueueCategory)

- (void)gct_enumObjectsInQueue:(dispatch_queue_t)queue block:(void(^)(id object, NSUInteger idx))block {
    if (queue) {
        dispatch_apply(self.count, queue, ^(size_t i) {
            block([self objectAtIndex:i], i);
        });
    }
    else {
        [self enumerateObjectsUsingBlock:^(__strong id obj, NSUInteger idx, BOOL *stop) {
            block(obj, idx);
        }];
    }
}

- (NSArray *)gct_mapObjectsInQueue:(dispatch_queue_t)queue block:(id(^)(id object, NSUInteger idx))block {
    NSMutableArray *mutableArray = [NSMutableArray arrayWithCapacity:self.count];
    if (queue) {
        for (NSUInteger i=0; i < self.count; i++) {
            [mutableArray addObject:[NSNull null]];
        }
        dispatch_semaphore_t itemLock = dispatch_semaphore_create(1);
        dispatch_apply(self.count, queue, ^(size_t i) {
            id o = block([self objectAtIndex:i], i);
            dispatch_semaphore_wait(itemLock, DISPATCH_TIME_FOREVER);
            [mutableArray replaceObjectAtIndex:i withObject:o];
            dispatch_semaphore_signal(itemLock);
        });
    }
    else {
        for (id obj in self) {
            NSUInteger idx = [self indexOfObject:obj];
            [mutableArray addObject:block(obj, idx)];
        }
    }
    return [NSArray arrayWithArray:mutableArray];
}

- (NSObject *)gct_reduceObjectsWithInitialMemo:(__strong id)memo block:(id(^)(id memo, id object))block {
    for (id obj in self) {
        memo = block(memo, obj);
    }
    return memo;
}

- (NSArray *)gct_filterObjectsInQueue:(dispatch_queue_t)queue block:(BOOL(^)(id object))block {
    if (queue) {
        NSMutableArray *nilArray = [NSMutableArray arrayWithCapacity:self.count];
        for (NSUInteger i=0; i < self.count; i++) {
            [nilArray addObject:[NSNull null]];
        }
        dispatch_semaphore_t itemLock = dispatch_semaphore_create(1);
        dispatch_apply(self.count, queue, ^(size_t i) {
            BOOL keep = block([self objectAtIndex:i]);
            if (keep) {
                dispatch_semaphore_wait(itemLock, DISPATCH_TIME_FOREVER);
                [nilArray replaceObjectAtIndex:i withObject:[self objectAtIndex:i]];
                dispatch_semaphore_signal(itemLock);
            }
        });
        [nilArray removeObjectIdenticalTo:[NSNull null]];
        return [NSArray arrayWithArray:nilArray];
    }
    else {
        NSMutableArray *mutArr = [NSMutableArray array];
        for (id obj in self) {
            if (block(obj)) [mutArr addObject:obj];
        }
        return [NSArray arrayWithArray:mutArr];
    }
}

- (NSArray *)gct_rejectObjectsInQueue:(dispatch_queue_t)queue block:(BOOL(^)(id object))block {
    if (queue) {
        NSMutableArray *nilArray = [NSMutableArray arrayWithCapacity:self.count];
        for (NSUInteger i=0; i < self.count; i++) {
            [nilArray addObject:[NSNull null]];
        }
        dispatch_semaphore_t itemLock = dispatch_semaphore_create(1);
        dispatch_apply(self.count, queue, ^(size_t i) {
            BOOL keep = !block([self objectAtIndex:i]);
            if (keep) {
                dispatch_semaphore_wait(itemLock, DISPATCH_TIME_FOREVER);
                [nilArray replaceObjectAtIndex:i withObject:[self objectAtIndex:i]];
                dispatch_semaphore_signal(itemLock);
            }
        });
        [nilArray removeObjectIdenticalTo:[NSNull null]];
        return [NSArray arrayWithArray:nilArray];
    }
    else {
        NSMutableArray *mutArr = [NSMutableArray array];
        for (id obj in self) {
            if (!block(obj))
                [mutArr addObject:obj];
        }
        return [NSArray arrayWithArray:mutArr];
    }
}

- (BOOL)gct_validAllObjectsInQueue:(dispatch_queue_t)queue block:(BOOL(^)(id object))block {
    __block BOOL validForAll = true;
    
    if (queue) {
        dispatch_apply(self.count, queue, ^(size_t i) {
            if (!validForAll) return;
            validForAll = (validForAll && block([self objectAtIndex:i]));
        });
    }
    else {
        for (id obj in self) {
            validForAll = (validForAll && block(obj));
            if (!validForAll) break;
        }
    }
    return validForAll;
}
- (BOOL)gct_validAnyObjectsInQueue:(dispatch_queue_t)queue block:(BOOL(^)(id object))block {
    __block BOOL validForAny = false;
    
    if (queue) {
        dispatch_apply(self.count, queue, ^(size_t i) {
            if (validForAny) return;
            validForAny = (validForAny || block([self objectAtIndex:i]));
        });
    }
    else {
        for (id obj in self) {
            validForAny = (validForAny || block(obj));
            if (validForAny) break;
        }
    }
    return validForAny;
}
- (NSNumber *)gct_countObjectsInQueue:(dispatch_queue_t)queue block:(BOOL(^)(id object))block {
    __block NSInteger ctr = 0;
    
    if (queue) {
        dispatch_apply(self.count, queue, ^(size_t i) {
            if (block([self objectAtIndex:i]))
                ctr++;
        });
    }
    else {
        for (id obj in self) {
            if(block(obj))
                ctr++;
        }
    }
    return [NSNumber numberWithInteger:ctr];
}
- (id)gct_maxObjectWithComparisonBlock:(NSComparisonResult(^)(id a, id b))block {
    if (self.count<1) return NULL;
    
    id biggest = [self objectAtIndex:0];
    for (id obj in self) {
        if (block(biggest, obj) == NSOrderedAscending)
            biggest = obj;
    }
    return biggest;
}
- (id)gct_minObjectWithComparisonBlock:(NSComparisonResult(^)(id a, id b))block {
    if (self.count<1) return NULL;
    
    id smallest = [self objectAtIndex:0];
    for (id obj in self) {
        if (block(smallest, obj) == NSOrderedDescending)
            smallest = obj;
    }
    return smallest;
}
- (NSDictionary *)gct_groupObjectswithBlock:(id(^)(id obj))block {
    NSMutableDictionary *mutDictOfMutArrays = [NSMutableDictionary dictionary];
    for (id obj in self) {
        id transformed = block(obj);
        if ([mutDictOfMutArrays objectForKey:transformed]==nil) {
            [mutDictOfMutArrays setObject:[NSMutableArray array] forKey:transformed];
        }
        NSMutableArray *itemsInThisGroup = [mutDictOfMutArrays objectForKey:transformed];
        [itemsInThisGroup addObject:obj];
    }
    
    NSMutableDictionary *mutDictOfArrays = [NSMutableDictionary dictionary];
    for (id key in mutDictOfMutArrays) {
        
        NSMutableArray *mutArr = (NSMutableArray *) [mutDictOfMutArrays objectForKey:key];
        [mutDictOfArrays setObject:[NSArray arrayWithArray:mutArr] forKey:key];
    }
    return [NSDictionary dictionaryWithDictionary:mutDictOfArrays];
}

- (NSArray *)gct_dropObjectsWhileBlock:(BOOL(^)(id obj)) block {
    NSMutableArray *mutArray = [NSMutableArray array];
    NSUInteger i = 0;
    for (i = 0; i < self.count; i++) {
        if (!block([self objectAtIndex:i])) break;
    }
    for (NSUInteger j=i; j < self.count; j++) {
        [mutArray addObject:[self objectAtIndex:j]];
    }
    return [NSArray arrayWithArray:mutArray];
}
@end
