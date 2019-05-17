//
//  BadgeView.h
//  BadgeViewDemo
//
//  Created by AoChen on 2019/5/17.
//  Copyright © 2019 Ac. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

//枚举类型 规定badgeView位于父View的相对位置 默认TopLeft
typedef NS_ENUM(NSUInteger, BadgeViewAlignment)
{
    BadgeViewAlignmentTopLeft = 0,
    BadgeViewAlignmentTopRight,
    BadgeViewAlignmentTopCenter,
    BadgeViewAlignmentCenter,
    BadgeViewAlignmentCenterLeft,
    BadgeViewAlignmentCenterRight,
    BadgeViewAlignmentBottomLeft,
    BadgeViewAlignmentBottomRight,
    BadgeViewAlignmentBottomCenter
};

@interface BadgeView : UIView<UIAppearance>

/**
 *  显示文字
 */
@property (nonatomic, copy) NSString *badgeText;


/**
 *  BadgeView 拖动的最大距离 默认为100
 *
 *  maxDistance of BadgeView can pan. Default is 100
 */
@property (nonatomic) CGFloat maxDistance;


@property (nonatomic) BOOL panable;

#pragma mark - Customization 自定义外观类型

/**
 *  badgeView 位于父View位置  默认TopLeft
 */
@property (nonatomic) BadgeViewAlignment badgeViewAlignment
UI_APPEARANCE_SELECTOR;

/**
 *  BadgeView 圆角角度  默认为 self.bounds.width/2
 *
 *  cornerRadius of BadgeView.layer. Default is self.bounds.width/2
 */
@property (nonatomic) CGFloat badgeViewCornerRadius UI_APPEARANCE_SELECTOR;

/**
 *  badge文字颜色 默认为[UIColor whiteColor]
 *
 *  textColor of badgeText. Default is [UIColor whiteColor]
 *
 */
@property (nonatomic, strong) UIColor *badgeTextColor UI_APPEARANCE_SELECTOR;

/**
 *  badge文字字体 默认为[UIFont systemFontOfSize:12.0f]
 *
 *  textFont of badgeText. Default is [UIFont systemFontOfSize:12.0f]
 *
 */
@property (nonatomic, strong) UIFont *badgeTextFont UI_APPEARANCE_SELECTOR;

/**
 *  badge背景色 默认为 [UIColor redColor]
 *
 *  backgroundColor of badgeView. Default is [UIColor redColor]
 *
 */
@property (nonatomic, strong) UIColor *badgeBackgroundColor UI_APPEARANCE_SELECTOR;


/**
 *  badgeText 阴影大小  默认 CGSizeZero
 *
 *  offset of badgeTextShadow. Default is CGSizeZero
 *
 */
@property (nonatomic, assign) CGSize badgeTextShadowSize UI_APPEARANCE_SELECTOR;

/**
 *  badgeText 阴影颜色  默认 [UIColor whiteColor]
 *
 *  shadowColor of badgeText. Default is [UIColor whiteColor]
 *
 */
@property (nonatomic, strong) UIColor *badgeTextShadowColor UI_APPEARANCE_SELECTOR;

/**
 *  badgeShadowColor  badgeView 阴影颜色. 默认透明黑色
 *
 *  Color of the badge shadow. Default is semi-transparent black.
 */
@property (nonatomic, strong) UIColor *badgeShadowColor UI_APPEARANCE_SELECTOR;

/**
 *  badgeView 阴影大小 默认CGSizeZero.
 *
 *  Offset of the badge shadow. Default is CGSizeZero.
 */
@property (nonatomic, assign) CGSize badgeShadowSize UI_APPEARANCE_SELECTOR;

/**
 *  badgeView边框宽度 默认0.0f
 *
 *  Width of the circle around the badge. Default is 0.0 points.
 */
@property (nonatomic, assign) CGFloat badgeStrokeWidth UI_APPEARANCE_SELECTOR;

/**
 *  badgeView边框颜色  默认 [UIColor whiteColor]
 *
 *  Color of the circle around the badge. Default is [UIColor whiteColor].
 */
@property (nonatomic, strong) UIColor *badgeStrokeColor UI_APPEARANCE_SELECTOR;

/**
 *  badgeView自适应调节X,Y轴位置
 *
 *  Allows to shift the badge by x and y points.
 */
@property (nonatomic, assign) CGPoint badgePositionAdjustment UI_APPEARANCE_SELECTOR;

/**
 *
 * BadgeView 最小宽度,避免使用过小字体时 badgeView过小
 *
 * The minimum width of a badge circle. We need this to avoid elipse shapes when using small fonts.
 */
@property (nonatomic, assign) CGFloat badgeMinWidth UI_APPEARANCE_SELECTOR;


/**
 *  实例化一个BadgeView
 *
 *  @param parentView 显示BadgeView的父View
 *  @param alignment
 *
 *  使用此方法,默认BadgeView不可拖动删除
 *
 *  FIXME 重新设置panable=YES 可以打开 ,但是有bug,如果badgeView位于四周会导致只有处于父view四周,会导致只有父类view内部的badgeView具有点击效果,超出父类的无法拖动,本人无法解决
 *  @return 一个BadgeView实例
 */
- (instancetype)initWithParentView:(UIView *)parentView alignment:(BadgeViewAlignment)alignment;

/**
 *  实例化一个BadgeView
 *
 *  @param attachView 依附的view
 *  @param alignment  依附view的相对位置
 *
 *  使用此方法默认BadgeView可以拖动删除
 *  @return 一个BadgeView实例
 */
- (instancetype)initWithAttachView:(UIView *)attachView alignment:(BadgeViewAlignment)alignment;



@end

NS_ASSUME_NONNULL_END
