//
//  NSDictionary+GCTSortedCategory.h
//  GCTFoundation
//
//  Created by Later on 2018/3/13.
//  Copyright © 2018年 GEEKCODE.In. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSDictionary<ObjectType, id> (GCTSortedCategory)

/**
 将所有的keys 排序，排序方式为“sel:”
 
 @return 排序好的 keys
 */
- (NSArray<ObjectType> *)gct_allKeysSortedUsingSelector:(SEL)sel;

/**
 将所有的values 排序，排序方式按照keys "sel:"
 
 @return  排序好的 valus
 */
- (NSArray<ObjectType> *)gct_allValuesSortedByKeysUsingSelector:(SEL)sel;

/**
 按照keys sel 排序所有的key values
 
 @return 排序好的 key values
 */
- (NSDictionary<ObjectType, id> *)gct_sortedByKeysUsingSelector:(SEL)sel;

/**
 按照 NSComparator 排序所有的keys

 @param cmptr 比较回调block
 @return 排序好的keys
 */
- (NSArray<ObjectType> *)gct_allKeysSortedUsingComparator:(NSComparator NS_NOESCAPE)cmptr;

/**
 按照 NSComparator 排序所有的keys，获取排序后的 values

 @param cmptr 比较回调 block
 @return 排序好的 values
 */
- (NSArray<ObjectType> *)gct_allValuesSortedByKeysUsingComparator:(NSComparator NS_NOESCAPE)cmptr;

/**
 按照 NSComparator 排序所有的keys，获取排序后的 keyValues

 @param cmptr cmptr 比较回调 block
 @return 排序好的 keyValues
 */
- (NSDictionary<ObjectType, id> *)gct_sortedByKeysUsingComparator:(NSComparator NS_NOESCAPE)cmptr;
@end
