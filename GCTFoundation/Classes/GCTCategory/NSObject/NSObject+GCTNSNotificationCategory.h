//
//  NSObject+GCTNSNotificationCategory.h
//  GCTFoundationDemo
//
//  Created by Later on 2018/3/13.
//  Copyright © 2018年 GEEKCODE.In. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@interface NSObject (GCTNSNotificationCategory)

/**
 把对象注册为观察者
 
 @param observerBlock 观察者执行的block
 @param name          消息的名字
 @param object        对同名观察者过滤
 */
-(void)gct_addObserverBlock:(void(^)(NSNotification *))observerBlock name:(NSString *)name object:(id)object;

/**
 发送一个消息
 
 @param notification 消息
 */
-(void)gct_postNotification:(NSNotification *)notification;

/**
 发送一个消息
 
 @param name   消息的名字
 @param object 对同名观察者过滤
 */
-(void)gct_postNotificationName:(NSString *)name object:(id)object;

/**
 发送一个消息
 
 @param name     消息的名字
 @param object   对观察者过滤
 @param userInfo 发送消息时附带的消息上下文
 */
-(void)gct_postNotificationName:(NSString *)name object:(id)object userInfo:(NSDictionary *)userInfo;

/**
 移除观察者
 */
-(void)gct_removeObservers;

/**
 移除观察者
 
 @param name   观察者的名字
 @param object 对同名观察着过滤
 */
-(void)gct_removeObserverWithName:(NSString *)name object:(id)object;
@end
NS_ASSUME_NONNULL_END
