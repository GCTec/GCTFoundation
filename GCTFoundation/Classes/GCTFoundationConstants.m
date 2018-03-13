//
//  GCTFoundationConstants.m
//  GCTFoundationDemo
//
//  Created by Later on 2018/3/13.
//  Copyright © 2018年 GEEKCODE.In. All rights reserved.
//

#import "GCTFoundationConstants.h"


void GCTAsyncGCDInHighQueue(GCTVoidBlock block) {
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_HIGH, 0), ^(void) {
        !block ?: block();
    });
}

void GCTAsyncGCDInDefaultQueue(GCTVoidBlock block) {
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^(void) {
        !block ?: block();
    });
}

void GCTAsyncGCDInLowQueue(GCTVoidBlock block) {
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_LOW, 0), ^(void) {
        !block ?: block();
    });
}

void GCTAsyncGCDInBackgroundQueue(GCTVoidBlock block) {
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_BACKGROUND, 0), ^(void) {
        !block ?: block();
    });
}

void GCTAsyncGCDInMainQueue(GCTVoidBlock block) {
    dispatch_async(dispatch_get_main_queue(), ^(void) {
        !block ?: block();
    });
    
}

void GCTSyncGCDInHighQueue(GCTVoidBlock block) {
    dispatch_sync(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_HIGH, 0), ^(void) {
        !block ?: block();
    });
}

void GCTSyncGCDInDefaultQueue(GCTVoidBlock block) {
    dispatch_sync(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^(void) {
        !block ?: block();
    });
}

void GCTSyncGCDInLowQueue(GCTVoidBlock block) {
    dispatch_sync(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_LOW, 0), ^(void) {
        !block ?: block();
    });
}

void GCTSyncGCDInBackgroundQueue(GCTVoidBlock block) {
    dispatch_sync(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_BACKGROUND, 0), ^(void) {
        !block ?: block();
    });
}

void GCTSyncGCDInMainQueue(GCTVoidBlock block) {
    dispatch_sync(dispatch_get_main_queue(), ^(void) {
        !block ?: block();
    });
    
}

void GCTAfterGCDInMainQeue(NSInteger delayInSeconds, GCTVoidBlock block) {
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(delayInSeconds * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        !block ?: block();
    });
}



