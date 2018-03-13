//
//  GCTFoundationConstants.h
//  GCTFoundationDemo
//
//  Created by Later on 2018/3/13.
//  Copyright © 2018年 GEEKCODE.In. All rights reserved.
//

#import <Foundation/Foundation.h>

#ifndef GCT_DEPRECATED
#define GCT_DEPRECATED(explain) __attribute__((deprecated(explain)))
#endif

#ifndef GCT_EXTERN
#define GCT_EXTERN extern
#endif

#define GCT_EXPORT  GCT_EXTERN

/**
 Synthsize a dynamic object property in @implementation scope.
 It allows us to add custom properties to existing classes in categories.
 
 @param association  ASSIGN / RETAIN / COPY / RETAIN_NONATOMIC / COPY_NONATOMIC
 @warning #import <objc/runtime.h>
 *******************************************************************************
 Example:
 @interface NSObject (MyAdd)
 @property (nonatomic, retain) UIColor *myColor;
 @end
 
 #import <objc/runtime.h>
 @implementation NSObject (MyAdd)
 GCTSYNTH_DYNAMIC_PROPERTY_OBJECT(myColor, setMyColor, RETAIN, UIColor *)
 @end
 */
#ifndef GCTSYNTH_DYNAMIC_PROPERTY_OBJECT
#define GCTSYNTH_DYNAMIC_PROPERTY_OBJECT(_getter_, _setter_, _association_, _type_) \
- (void)_setter_ : (_type_)object { \
[self willChangeValueForKey:@#_getter_]; \
objc_setAssociatedObject(self, _cmd, object, OBJC_ASSOCIATION_ ## _association_); \
[self didChangeValueForKey:@#_getter_]; \
} \
- (_type_)_getter_ { \
return objc_getAssociatedObject(self, @selector(_setter_:)); \
}
#endif

/**
 Synthsize a dynamic c type property in @implementation scope.
 It allows us to add custom properties to existing classes in categories.
 
 @warning #import <objc/runtime.h>
 *******************************************************************************
 Example:
 @interface NSObject (MyAdd)
 @property (nonatomic, retain) CGPoint myPoint;
 @end
 
 #import <objc/runtime.h>
 @implementation NSObject (MyAdd)
 GCTSYNTH_DYNAMIC_PROPERTY_CTYPE(myPoint, setMyPoint, CGPoint)
 @end
 */
#ifndef GCTSYNTH_DYNAMIC_PROPERTY_CTYPE
#define GCTSYNTH_DYNAMIC_PROPERTY_CTYPE(_getter_, _setter_, _type_) \
- (void)_setter_ : (_type_)object { \
[self willChangeValueForKey:@#_getter_]; \
NSValue *value = [NSValue value:&object withObjCType:@encode(_type_)]; \
objc_setAssociatedObject(self, _cmd, value, OBJC_ASSOCIATION_RETAIN); \
[self didChangeValueForKey:@#_getter_]; \
} \
- (type)_getter_ { \
_type_ cValue = { 0 }; \
NSValue *value = objc_getAssociatedObject(self, @selector(_setter_:)); \
[value getValue:&cValue]; \
return cValue; \
}
#endif

#pragma mark weakify strongify
/** weakify strongify */
/**
 *  @author Later, 16-03-27
 *
 *  typdef weakly and strongly
 *
 *  @param objc_arc
 *
 *  Example:
 @weakify(self);
 [self actionBlock^{
 @strongify(self);
 if(!self) return;
 ...
 *  }];
 *
 */
#ifndef weakify
#if DEBUG
#if __has_feature(objc_arc)
#define weakify(object) autoreleasepool{} __weak __typeof__(object) weak##_##object = object;
#else
#define weakify(object) autoreleasepool{} __block __typeof__(object) block##_##object = object;
#endif
#else
#if __has_feature(objc_arc)
#define weakify(object) try{} @finally{} {} __weak __typeof__(object) weak##_##object = object;
#else
#define weakify(object) try{} @finally{} {} __block __typeof__(object) block##_##object = object;
#endif
#endif
#endif

#ifndef strongify
#if DEBUG
#if __has_feature(objc_arc)
#define strongify(object) autoreleasepool{} __typeof__(object) object = weak##_##object;
#else
#define strongify(object) autoreleasepool{} __typeof__(object) object = block##_##object;
#endif
#else
#if __has_feature(objc_arc)
#define strongify(object) try{} @finally{} __typeof__(object) object = weak##_##object;
#else
#define strongify(object) try{} @finally{} __typeof__(object) object = block##_##object;
#endif
#endif
#endif

#pragma mark Assert
/** Assert */
#ifndef GCTAssertNil
#define GCTAssertNil(condition, description, ...) NSAssert(!(condition), (description), ##__VA__ARGS__)
#endif
#ifndef GCTAssertNotNol
#define GCTAssertNotNil(condition, description, ...) NSAssert((condition), (description), ##__VA_ARGS__)
#endif
#ifndef GCTAssertMainThread
#define GCTAssertMainThread() NSAssert([NSThread isMainThread], @"主线程调用")
#endif

/**
 是否允许使用继承创建子类
 在创建类的时候，如果不希望其他类继承与该类，则在类的"@interface"前声明该宏定义
 
 @example
 
 GCT_SUBCLASS_RESTRICTED
 @interface SubClassResricted : NSObject
 @end
 */
#ifndef GCT_SUBCLASS_RESTRICTED
#define GCT_SUBCLASS_RESTRICTED __attribute__((objc_subclassing_restricted))
#endif

/**
 方法后面追加后，子类实现该方法，若没有调用"super"，则给出编译警告

 @example
 
 @interface Father : NSObject
 - (void)hello GCT_REQUIRES_SUPER;
 @end
 @implementation Father
 - (void)hello {
 NSLog(@"Hello!");
 }
 @end
 
 @interface Son : Father
 @end
 @implementation Son
 - (void)hailHydra {
 } // <--- Warning missing [super hello]
 @end
 */
#ifndef GCT_REQUIRES_SUPER
#define GCT_REQUIRES_SUPER NS_REQUIRES_SUPER //__attribute__((objc_requires_super))
#endif

/**
 *  @author Later, 16-05-28
 *
 *  @description:
 *  如果想对一个struct/union/NSValue对象使用语法糖，则可使用该宏定义进行定义
 *
 *  @example:
 typedef struct GCT_BOXABLE {
 CGFloat x, y, width, height;
 } GCTRect;
 既这样使用了box
 CGRect rect1 = {1, 2, 3, 4};
 NSValue *value1 = @(rect1); // X
 XXRect rect2 = {1, 2, 3, 4};
 NSValue *value2 = @(rect2); // √
 */
#ifndef GCT_BOXABLE
#define GCT_BOXABLE __attribute__((objc_boxable))
#endif

/**
 构造器和析构器。GCT_CONSTRUCTOR:构造器，在main函数前执行；GCT_DESTRUCTOR:析构器，在main函数执行后执行

 @example:
 GCT_CONSTRUCTOR
 static void beforeMain(void) {
 NSLog(@"beforeMain");
 }
 GCT_DESTRUCTOR
 static void afterMain(void) {
 NSLog(@"afterMain");
 }
 int main(int argc, const char * argv[]) {
 NSLog(@"main");
 return 0;
 }
 执行顺序："beforeMain" -> "main" -> "afterMain"
 */
#ifndef GCT_CONSTRUCTOR
#define GCT_CONSTRUCTOR __attribute__((constructor))
#endif
#ifndef GCT_DESTRUCTOR
#define GCT_DESTRUCTOR __attribute__((destructor))
#endif

/**
 *  @author Later, 16-05-28
 *
 *  @description:
 *  用于 @interface 或者 @protocol，将类或者协议的名字在编译时指定成另一个（混淆名字）
 *
 *  @example:
 GCT_OBJC_RUNTIME_NAME("40ea43d7629d01e4b8d6289a132482d0dd5df4fa")))
 @interface GCTSafeObject : NSObject
 @end
 */

/**
 用于 @interface 或者 @protocol，将类或者协议的名字在编译时指定成另一个（混淆名字）

 @example:
 GCT_OBJC_RUNTIME_NAME("40ea43d7629d01e4b8d6289a132482d0dd5df4fa")))
 @interface GCTSafeObject : NSObject
 @end
 */
#ifndef GCT_OBJC_RUNTIME_NAME
#define GCT_OBJC_RUNTIME_NAME(var) __attribute__((objc_runtime_name(var)))
#endif

/**
 用于修饰变量，表示在其作用于结束时，自动执行一个指定的方法

 @param method 指定的方法

 @example:
 // 指定一个cleanup方法，注意入参是所修饰变量的地址，类型要一样
 // 对于指向objc对象的指针(id *)，如果不强制声明__strong默认是__autoreleasing，造成类型不匹配
 static void stringCleanUp(__strong NSString **string) {
 NSLog(@"%@", *string);
 }
 // 在某个方法中：
 {
 __strong NSString *string __attribute__((cleanup(stringCleanUp))) = @"sunnyxx";
 } // 当运行到这个作用域结束时，自动调用stringCleanUp
 @example2:
 定义一个作用于里使用的block，则在最后执行该block
 __strong void(^block)(void) __attribute__((cleanup(blockCleanUp), unused)) = ^{
 NSLog(@"I'm dying...");
 };
 #define onExit __strong void(^block)(void) __attribute__((cleanup(blockCleanUp), unused)) = ^{
 NSLog(@"I'm dying...");
 }
 使用：
 这样的写法可以将成对出现的代码写在一起，比如说一个lock：
 
 NSRecursiveLock *aLock = [[NSRecursiveLock alloc] init];
 [aLock lock];
 // 这里
 //     有
 //        100多万行
 [aLock unlock]; // 看到这儿的时候早忘了和哪个lock对应着了
 
 用了onExit之后，代码更集中了：
 
 NSRecursiveLock *aLock = [[NSRecursiveLock alloc] init];
 [aLock lock];
 onExit {
 [aLock unlock]; // 妈妈再也不用担心我忘写后半段了
 };
 // 这里
 //    爱多少行
 //           就多少行
 */
#ifndef GCT_CLEAN_UP
#define GCT_CLEAN_UP(method)  __attribute__((cleanup(method)))
#endif

#pragma mark About Block

/**
 void block
 */
typedef void (^GCTVoidBlock)(void);
typedef void (^GCTVoidCallBack)(void);
typedef void (^GCTVoidCompletionHandle)(void);

/**
 bool block
 */
typedef void (^GCTBooleanBlock)(BOOL succeeded);
typedef void (^GCTBooleanCallBack)(BOOL succeeded);
typedef void (^GCTBooleanCompletionHandle)(BOOL succeeded);

typedef void (^GCTBooleanErrorCallBack)(BOOL succeeded,  NSError * _Nullable error);
typedef void (^GCTBooleanErrorCompletionHandle)(BOOL succeeded,  NSError * _Nullable error);

/**
 id block
 */
typedef void (^GCTIdBlock)(id _Nullable object);
typedef void (^GCTIdCallBack)(id _Nullable object);
typedef void (^GCTIdCompletionHandle)(id _Nullable object);
typedef void (^GCTIdErrorCallBack)(id _Nullable object, NSError * _Nullable error);
typedef void (^GCTIdErrorCompletionHandle)(id _Nullable object, NSError * _Nullable error);

/**
 object block
 */
typedef void (^GCTNSObjectBlock)(NSObject * _Nullable object);
typedef void (^GCTNSObjectCallBack)(NSObject * _Nullable object);
typedef void (^GCTNSObjectCompletionHandle)(NSObject * _Nullable object);
typedef void (^GCTNSObjectErrorCallBack)(NSObject * _Nullable object, NSError * _Nullable error);
typedef void (^GCTNSObjectErrorCompletionHandle)(NSObject * _Nullable object, NSError * _Nullable error);

/**
 number blcok
 */
typedef void (^GCTNSNumberBlock)(NSNumber * _Nullable number);
typedef void (^GCTNSNumberCallBack)(NSNumber * _Nullable number);
typedef void (^GCTNSNumberCompletionHandle)(NSNumber * _Nullable number);
typedef void (^GCTNSNumberErrorCallBack)(NSNumber * _Nullable number, NSError * _Nullable error);
typedef void (^GCTNSNumberErrorCompletionHandle)(NSNumber * _Nullable number, NSError * _Nullable error);

/**
 string block
 */
typedef void (^GCTNSStringBlock)(NSString * _Nullable string);
typedef void (^GCTNSStringCallBack)(NSString * _Nullable string);
typedef void (^GCTNSStringCompletionHandle)(NSString * _Nullable string);
typedef void (^GCTNSStringErrorCallBack)(NSString * _Nullable string, NSError * _Nullable error);
typedef void (^GCTNSStringErrorCompletionHandle)(NSString * _Nullable string, NSError * _Nullable error);

/**
 array block
 */
typedef void (^GCTNSArrayBlock)(NSArray * _Nullable objects);
typedef void (^GCTNSArrayCallBack)(NSArray * _Nullable objects);
typedef void (^GCTNSArrayCompletionHandle)(NSArray * _Nullable objects);
typedef void (^GCTNSArrayErrorCallBack)(NSArray * _Nullable objects, NSError * _Nullable error);
typedef void (^GCTNSArrayErrorCompletionHandle)(NSArray * _Nullable objects, NSError * _Nullable error);

/**
 dictionary block
 */
typedef void (^GCTNSDictionaryBlock)(NSDictionary * _Nullable dict);
typedef void (^GCTNSDictionaryCallBack)(NSDictionary * _Nullable dict);
typedef void (^GCTNSDictionaryCompletionHandle)(NSDictionary * _Nullable dict);
typedef void (^GCTNSDictionaryErrorCallBack)(NSDictionary * _Nullable dict, NSError * _Nullable error);
typedef void (^GCTNSDictionaryErrorCompletionHandle)(NSDictionary * _Nullable dict, NSError * _Nullable error);

/**
 set block
 */
typedef void (^GCTNSSetBlock)(NSSet * _Nullable channels);
typedef void (^GCTNSSetCallBack)(NSSet * _Nullable channels);
typedef void (^GCTNSSetCompletionHandle)(NSSet * _Nullable channels);
typedef void (^GCTNSSetErrorCallBack)(NSSet * _Nullable channels, NSError * _Nullable error);
typedef void (^GCTNSSetErrorCompletionHandle)(NSSet * _Nullable channels, NSError * _Nullable error);

/**
 data block
 */
typedef void (^GCTNSDataBlock)(NSData * _Nullable data);
typedef void (^GCTNSDataCallBack)(NSData * _Nullable data);
typedef void (^GCTNSDataCompletionHandle)(NSData * _Nullable data);
typedef void (^GCTNSDataErrorCallBack)(NSData * _Nullable data, NSError * _Nullable error);
typedef void (^GCTNSDataErrorCompletionHandle)(NSData * _Nullable data, NSError * _Nullable error);

/**
 stream block
 */
typedef void (^GCTNSDataStreamBlock)(NSInputStream * _Nullable stream);
typedef void (^GCTNSDataStreamCallBack)(NSInputStream * _Nullable stream);
typedef void (^GCTNSDataStreamCompletionHandle)(NSInputStream * _Nullable stream);
typedef void (^GCTNSDataStreamErrorCallBack)(NSInputStream * _Nullable stream, NSError * _Nullable error);
typedef void (^GCTNSDataStreamErrorCompletionHandle)(NSInputStream * _Nullable stream, NSError * _Nullable error);

/**
 progress
 */
typedef void (^GCTProgressBlock)(NSInteger percentDone);
typedef void (^GCTProgressCallBack)(NSInteger percentDone);
typedef void (^GCTProgressCompletionHandle)(NSInteger percentDone);

/**
 NSNotification
 */
typedef void (^GCTNSNotificationBlock)(NSNotification * _Nullable notification);
typedef void (^GCTNSNotificationCallBack)(NSNotification * _Nullable notification);
typedef void (^GCTNSNotificationCompletionHandle)(NSNotification * _Nullable notification);


#pragma mark About GCD
#pragma mark About GCD -- Async

//异步
void GCTAsyncGCDInHighQueue(_Nullable GCTVoidCallBack block);
void GCTAsyncGCDInDefaultQueue(_Nullable GCTVoidCallBack block);
void GCTAsyncGCDInLowQueue(_Nullable GCTVoidCallBack block);
void GCTAsyncGCDInBackgroundQueue(_Nullable GCTVoidCallBack block);
void GCTAsyncGCDInMainQueue(_Nullable GCTVoidCallBack block);

#pragma mark About GCD -- Sync

//同步
void GCTSyncGCDInHighQueue(_Nullable GCTVoidCallBack block);
void GCTSyncGCDInDefaultQueue(_Nullable GCTVoidCallBack block);
void GCTSyncGCDInLowQueue(_Nullable GCTVoidCallBack block);
void GCTSyncGCDInBackgroundQueue(_Nullable GCTVoidCallBack block);
void GCTSyncGCDInMainQueue(_Nullable GCTVoidCallBack block);

#pragma mark About GCD -- After

//延时
void GCTAfterGCDInMainQeue(NSInteger delayInSeconds, _Nullable GCTVoidCallBack block);


