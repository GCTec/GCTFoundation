//
//  NSDictionary+GCTSortedCategory.m
//  GCTFoundation
//
//  Created by Later on 2018/3/13.
//  Copyright © 2018年 GEEKCODE.In. All rights reserved.
//

#import "NSDictionary+GCTSortedCategory.h"

@implementation NSDictionary (GCTSortedCategory)

- (NSArray *)gct_allKeysSortedUsingSelector:(SEL)sel {
      return [[self allKeys] sortedArrayUsingSelector:sel];
}

- (NSArray *)gct_allValuesSortedByKeysUsingSelector:(SEL)sel {
    NSArray *sortedKeys = [self gct_allKeysSortedUsingSelector:sel];
    NSMutableArray *arr = [[NSMutableArray alloc] init];
    for (id key in sortedKeys) {
        [arr addObject:self[key]];
    }
    return [arr copy];
}
- (NSDictionary *)gct_sortedByKeysUsingSelector:(SEL)sel {
    NSArray *sortedKeys = [self gct_allKeysSortedUsingSelector:sel];
    NSMutableDictionary *sortedKeyValues = [[NSMutableDictionary alloc] init];
    for (id key in sortedKeys) {
        [sortedKeyValues setObject:self[key] forKey:key];
    }
    return [sortedKeyValues copy];
}

- (NSArray *)gct_allKeysSortedUsingComparator:(NSComparator NS_NOESCAPE)cmptr {
    NSArray * keys = self.allKeys;
    [keys sortedArrayUsingComparator:cmptr];
    return keys;
}

- (NSArray *)gct_allValuesSortedByKeysUsingComparator:(NSComparator NS_NOESCAPE)cmptr {
    NSArray *sortedKeys = [self gct_allKeysSortedUsingComparator:cmptr];
    NSMutableArray *arr = [[NSMutableArray alloc] init];
    for (id key in sortedKeys) {
        [arr addObject:self[key]];
    }
    return [arr copy];
}

- (NSDictionary *)gct_sortedByKeysUsingComparator:(NSComparator NS_NOESCAPE)cmptr {
    NSArray *sortedKeys = [self gct_allKeysSortedUsingComparator:cmptr];
    NSMutableDictionary *sortedKeyValues = [[NSMutableDictionary alloc] init];
    for (id key in sortedKeys) {
        [sortedKeyValues setObject:self[key] forKey:key];
    }
    return [sortedKeyValues copy];
}
@end
