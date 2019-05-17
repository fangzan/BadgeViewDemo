//
//  ViewController.m
//  BadgeViewDemo
//
//  Created by AoChen on 2019/5/17.
//  Copyright © 2019 Ac. All rights reserved.
//

#import "ViewController.h"
#import "BadgeView.h"
@interface ViewController ()

@property (strong, nonatomic) BadgeView *badgeView;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    
    //测试 直接从XIB中实例化 badgeView
    [self.badgeView setBadgeText:@"10"];
    [self.badgeView setBadgeViewAlignment:BadgeViewAlignmentCenterRight];
    
    //测试 直接addSubView添加到需要显示的父view
    BadgeView *badge = [[BadgeView alloc] initWithFrame:CGRectZero];
    [badge setPanable:NO];
    [badge setBadgeText:@"99+"];
    [badge setBadgeViewAlignment:BadgeViewAlignmentCenter];
    [self.view addSubview:badge];
    
    //测试使用initWithAttachView 添加badgeView
    UIView *greenView = [[UIView alloc] initWithFrame:CGRectMake(30, 80, 100, 100)];
    greenView.userInteractionEnabled = YES;
    greenView.backgroundColor = [UIColor greenColor];
    [self.view addSubview:greenView];
    
    BadgeView *greenBadgeView = [[BadgeView alloc] initWithAttachView:greenView alignment:BadgeViewAlignmentTopRight];
    [greenBadgeView setBadgeText:@"31"];
    
}


@end
