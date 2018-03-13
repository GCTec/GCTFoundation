//
//  NSNumber+GCTCategory.h
//  GCTFoundationDemo
//
//  Created by Later on 2018/3/13.
//  Copyright © 2018年 GEEKCODE.In. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSNumber (GCTCategory)
- (void)gct_timesBlock:(void(^)(void)) block;
@end
