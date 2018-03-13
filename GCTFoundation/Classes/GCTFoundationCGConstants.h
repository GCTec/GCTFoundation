//
//  GCTFoundationCGConstants.h
//  GCTFoundationDemo
//
//  Created by Later on 2018/3/13.
//  Copyright © 2018年 GEEKCODE.In. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#pragma mark - C对象、结构操作

/**
 基于指定的倍数，对传进来的 floatValue 进行像素取整。若指定倍数为0，则表示以当前设备的屏幕倍数为准。

 @param floatValue 需要处理的像素值
 @param scale 倍数
 @return 处理后的像素值
 
 @eg 例如传进来 “2.1”，在 2x 倍数下会返回 2.5（0.5pt 对应 1px），在 3x 倍数下会返回 2.333（0.333pt 对应 1px）。
 */
CG_INLINE CGFloat
flatSpecificScale(CGFloat floatValue, CGFloat scale) {
    scale = scale == 0 ? [[UIScreen mainScreen] scale] : scale;
    CGFloat flattedValue = ceil(floatValue * scale) / scale;
    return flattedValue;
}

/**
 基于当前设备的屏幕倍数，对传进来的 floatValue 进行像素取整。
 
 @warning 如果在 Core Graphic 绘图里使用时，要注意当前画布的倍数是否和设备屏幕倍数一致，若不一致，不可使用 flat() 函数，而应该用 flatSpecificScale

 @param floatValue 需要处理的像素值
 @return 处理后的像素值
 */
CG_INLINE CGFloat
flat(CGFloat floatValue) {
    return flatSpecificScale(floatValue, 0);
}

/**
 类似flat()，只不过 flat 是向上取整，而 floorInPixel 是向下取整

 @param floatValue 需要向下取整的数值
 @return 向下取整的数值
 */
CG_INLINE CGFloat
floorInPixel(CGFloat floatValue) {
    CGFloat resultValue = floor(floatValue * [[UIScreen mainScreen] scale]) / [[UIScreen mainScreen] scale];
    return resultValue;
}

/**
 判定数值是否在某个区间（不包含）

 @param minimumValue 最小值区间
 @param value 判定数值
 @param maximumValue 最大值区间
 @return 判定是否在数值区间范围内
 */
CG_INLINE BOOL
between(CGFloat minimumValue, CGFloat value, CGFloat maximumValue) {
    return minimumValue < value && value < maximumValue;
}

/**
  判定数值是否在某个区间（包含）

 @param minimumValue 最小值区间
 @param value 判定数值
 @param maximumValue 最大值区间
 @return 判定是否在数值区间范围内
 */
CG_INLINE BOOL
betweenOrEqual(CGFloat minimumValue, CGFloat value, CGFloat maximumValue) {
    return minimumValue <= value && value <= maximumValue;
}

#pragma mark - CGFloat

/**
 数值居中运算
 */
CG_INLINE CGFloat
CGFloatGetCenter(CGFloat parent, CGFloat child) {
    return flat((parent - child) / 2.0);
}

#pragma mark - CGPoint

/**
 两个点相加

 @param point1 点1
 @param point2 点2
 @return 点相加返回点
 */
CG_INLINE CGPoint
CGPointUnion(CGPoint point1, CGPoint point2) {
    return CGPointMake(flat(point1.x + point2.x), flat(point1.y + point2.y));
}

/**
 根据Rect获取范围区间中心点

 @param rect 范围区间
 @return 中心店
 */
CG_INLINE CGPoint
CGPointGetCenterWithRect(CGRect rect) {
    return CGPointMake(flat(CGRectGetMidX(rect)), flat(CGRectGetMidY(rect)));
}

/**
 根据Size获取区间大小中心店

 @param size 尺寸大小
 @return 中心点
 */
CG_INLINE CGPoint
CGPointGetCenterWithSize(CGSize size) {
    return CGPointMake(flat(size.width / 2.0), flat(size.height / 2.0));
}

#pragma mark - UIEdgeInsets

/**
 获取EdgeInsets在水平方向上的值
 */
CG_INLINE CGFloat
UIEdgeInsetsGetHorizontalValue(UIEdgeInsets insets) {
    return insets.left + insets.right;
}

/**
 获取UIEdgeInsets在垂直方向上的值
 */
CG_INLINE CGFloat
UIEdgeInsetsGetVerticalValue(UIEdgeInsets insets) {
    return insets.top + insets.bottom;
}

/**
 合并UIEdgeInsets
 */
CG_INLINE UIEdgeInsets
UIEdgeInsetsConcat(UIEdgeInsets insets1, UIEdgeInsets insets2) {
    insets1.top += insets2.top;
    insets1.left += insets2.left;
    insets1.bottom += insets2.bottom;
    insets1.right += insets2.right;
    return insets1;
}


/**
 设置UIEdgeInsets的顶部边
 */
CG_INLINE UIEdgeInsets
UIEdgeInsetsSetTop(UIEdgeInsets insets, CGFloat top) {
    insets.top = flat(top);
    return insets;
}

/**
 设置UIEdgeInsets的左部边
 */
CG_INLINE UIEdgeInsets
UIEdgeInsetsSetLeft(UIEdgeInsets insets, CGFloat left) {
    insets.left = flat(left);
    return insets;
}

/**
 设置UIEdgeInsets的底部边
 */
CG_INLINE UIEdgeInsets
UIEdgeInsetsSetBottom(UIEdgeInsets insets, CGFloat bottom) {
    insets.bottom = flat(bottom);
    return insets;
}


/**
 设置UIEdgeInsets的右部边
 */
CG_INLINE UIEdgeInsets
UIEdgeInsetsSetRight(UIEdgeInsets insets, CGFloat right) {
    insets.right = flat(right);
    return insets;
}

#pragma mark - CGSize

/**
 判断一个size是否为空（宽或高为0）
 */
CG_INLINE BOOL
CGSizeIsEmpty(CGSize size) {
    return size.width <= 0 || size.height <= 0;
}

/**
 将一个CGSize像素对齐
 */
CG_INLINE CGSize
CGSizeFlatted(CGSize size) {
    return CGSizeMake(flat(size.width), flat(size.height));
}

/**
 将一个 CGSize 以 pt 为单位向上取整
 */
CG_INLINE CGSize
CGSizeCeil(CGSize size) {
    return CGSizeMake(ceil(size.width), ceil(size.height));
}

/**
 将一个 CGSize 以 pt 为单位向下取整
 */
CG_INLINE CGSize
CGSizeFloor(CGSize size) {
    return CGSizeMake(floor(size.width), floor(size.height));
}

#pragma mark - CGRect

/**
 判断一个CGRect是否存在NaN
 */
CG_INLINE BOOL
CGRectIsNaN(CGRect rect) {
    return isnan(rect.origin.x) || isnan(rect.origin.y) || isnan(rect.size.width) || isnan(rect.size.height);
}

/**
 创建一个像素对齐的CGRect
 */
CG_INLINE CGRect
CGRectFlatMake(CGFloat x, CGFloat y, CGFloat width, CGFloat height) {
    return CGRectMake(flat(x), flat(y), flat(width), flat(height));
}

/**
 对CGRect的x/y、width/height都调用一次flat，以保证像素对齐
 */
CG_INLINE CGRect
CGRectFlatted(CGRect rect) {
    return CGRectMake(flat(rect.origin.x), flat(rect.origin.y), flat(rect.size.width), flat(rect.size.height));
}

/**
 为一个CGRect叠加scale计算
 */
CG_INLINE CGRect
CGRectApplyScale(CGRect rect, CGFloat scale) {
    return CGRectFlatted(CGRectMake(CGRectGetMinX(rect) * scale, CGRectGetMinY(rect) * scale, CGRectGetWidth(rect) * scale, CGRectGetHeight(rect) * scale));
}

/**
 计算view的水平居中，传入父view和子view的frame，返回子view在水平居中时的x值
 */
CG_INLINE CGFloat
CGRectGetMinXHorizontallyCenterInParentRect(CGRect parentRect, CGRect childRect) {
    return flat((CGRectGetWidth(parentRect) - CGRectGetWidth(childRect)) / 2.0);
}

/**
 计算view的垂直居中，传入父view和子view的frame，返回子view在垂直居中时的y值
 */
CG_INLINE CGFloat
CGRectGetMinYVerticallyCenterInParentRect(CGRect parentRect, CGRect childRect) {
    return flat((CGRectGetHeight(parentRect) - CGRectGetHeight(childRect)) / 2.0);
}

/**
 返回值：同一个坐标系内，想要layoutingRect和已布局完成的referenceRect保持垂直居中时，layoutingRect的originY
 */
CG_INLINE CGFloat
CGRectGetMinYVerticallyCenter(CGRect referenceRect, CGRect layoutingRect) {
    return CGRectGetMinY(referenceRect) + CGRectGetMinYVerticallyCenterInParentRect(referenceRect, layoutingRect);
}

/**
 返回值：同一个坐标系内，想要layoutingRect和已布局完成的referenceRect保持水平居中时，layoutingRect的originX
 */
CG_INLINE CGFloat
CGRectGetMinXHorizontallyCenter(CGRect referenceRect, CGRect layoutingRect) {
    return CGRectGetMinX(referenceRect) + CGRectGetMinXHorizontallyCenterInParentRect(referenceRect, layoutingRect);
}

/**
 为给定的rect往内部缩小insets的大小
 */
CG_INLINE CGRect
CGRectInsetEdges(CGRect rect, UIEdgeInsets insets) {
    rect.origin.x += insets.left;
    rect.origin.y += insets.top;
    rect.size.width -= UIEdgeInsetsGetHorizontalValue(insets);
    rect.size.height -= UIEdgeInsetsGetVerticalValue(insets);
    return rect;
}

/**
 传入size，返回一个x/y为0的CGRect
 */
CG_INLINE CGRect
CGRectMakeWithSize(CGSize size) {
    return CGRectMake(0, 0, size.width, size.height);
}

/**
 设置rect的顶部边缘
 */
CG_INLINE CGRect
CGRectFloatTop(CGRect rect, CGFloat top) {
    rect.origin.y = top;
    return rect;
}

/**
 设置rect的底部边缘
 */
CG_INLINE CGRect
CGRectFloatBottom(CGRect rect, CGFloat bottom) {
    rect.origin.y = bottom - CGRectGetHeight(rect);
    return rect;
}

/**
 设置rect的右侧边缘
 */
CG_INLINE CGRect
CGRectFloatRight(CGRect rect, CGFloat right) {
    rect.origin.x = right - CGRectGetWidth(rect);
    return rect;
}

/**
 设置rect的左侧边缘
 */
CG_INLINE CGRect
CGRectFloatLeft(CGRect rect, CGFloat left) {
    rect.origin.x = left;
    return rect;
}

/**
 保持rect的左边缘不变，改变其宽度，使右边缘靠在right上
 */
CG_INLINE CGRect
CGRectLimitRight(CGRect rect, CGFloat rightLimit) {
    rect.size.width = rightLimit - rect.origin.x;
    return rect;
}

/**
 保持rect右边缘不变，改变其宽度和origin.x，使其左边缘靠在left上。只适合那种右边缘不动的view
 先改变origin.x，让其靠在offset上
 再改变size.width，减少同样的宽度，以抵消改变origin.x带来的view移动，从而保证view的右边缘是不动的
 */
CG_INLINE CGRect
CGRectLimitLeft(CGRect rect, CGFloat leftLimit) {
    CGFloat subOffset = leftLimit - rect.origin.x;
    rect.origin.x = leftLimit;
    rect.size.width = rect.size.width - subOffset;
    return rect;
}

/**
 限制rect的宽度，超过最大宽度则截断，否则保持rect的宽度不变
 */
CG_INLINE CGRect
CGRectLimitMaxWidth(CGRect rect, CGFloat maxWidth) {
    CGFloat width = CGRectGetWidth(rect);
    rect.size.width = width > maxWidth ? maxWidth : width;
    return rect;
}


/**
 向下取整设置rect的左侧边距
 */
CG_INLINE CGRect
CGRectSetX(CGRect rect, CGFloat x) {
    rect.origin.x = flat(x);
    return rect;
}

/**
 向下取整设置rect的右侧边距
 */
CG_INLINE CGRect
CGRectSetY(CGRect rect, CGFloat y) {
    rect.origin.y = flat(y);
    return rect;
}

/**
 向下取整设置rect的左侧边距和右侧边距
 */
CG_INLINE CGRect
CGRectSetXY(CGRect rect, CGFloat x, CGFloat y) {
    rect.origin.x = flat(x);
    rect.origin.y = flat(y);
    return rect;
}

/**
 向下取整设置rect的宽度
 */
CG_INLINE CGRect
CGRectSetWidth(CGRect rect, CGFloat width) {
    rect.size.width = flat(width);
    return rect;
}

/**
 向下取整设置rect的高度
 */
CG_INLINE CGRect
CGRectSetHeight(CGRect rect, CGFloat height) {
    rect.size.height = flat(height);
    return rect;
}

/**
 向下取整设置rect size
 */
CG_INLINE CGRect
CGRectSetSize(CGRect rect, CGSize size) {
    rect.size = CGSizeFlatted(size);
    return rect;
}
