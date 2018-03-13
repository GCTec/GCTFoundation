//
//  GCTAutoPurgeCache.m
//  GCTFoundationDemo
//
//  Created by Later on 2018/3/13.
//  Copyright © 2018年 GEEKCODE.In. All rights reserved.
//

#import "GCTAutoPurgeCache.h"
#import <UIKit/UIKit.h>

@implementation GCTAutoPurgeCache

- (instancetype)init {
    if (self = [super init]) {
        [self addNotification];
    }
    return self;
}
- (void)addNotification {
    [self removeNotification];
    //添加观察者
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(removeAllObjects) name:UIApplicationDidReceiveMemoryWarningNotification object:nil];
}
- (void)removeNotification {
    //添加之前删除所有的观察者
    [[NSNotificationCenter defaultCenter] removeObserver:self name:UIApplicationDidReceiveMemoryWarningNotification object:nil];
}
- (void)dealloc {
    [self removeNotification];
}
@end
