
//
//  NSNumber+GCTCategory.m
//  GCTFoundationDemo
//
//  Created by Later on 2018/3/13.
//  Copyright © 2018年 GEEKCODE.In. All rights reserved.
//

#import "NSNumber+GCTCategory.h"

@implementation NSNumber (GCTCategory)

- (void)gct_timesBlock:(void(^)(void)) block {
    for (int i=0; i < self.intValue; i++)
        block();
}

@end
