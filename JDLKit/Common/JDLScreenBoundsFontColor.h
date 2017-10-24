//
//  JDLScreenBoundsFontColor.h
//  JDLKit
//
//  Created by 胜炫电子 on 2017/10/24.
//  Copyright © 2017年 BlueSkyer-25. All rights reserved.
//

#ifndef JDLScreenBoundsFontColor_h
#define JDLScreenBoundsFontColor_h

#pragma mark ===========颜色区===========--BlueSkyer25
//主题色 导航栏颜色
#define KThemeColor ([UIColor colorWithRed:252.0/255.0 green:252.0/255.0 blue:252.0/255.0 alpha:1.0])
//16进制颜色设置
#define KHEXColor(HexColor) [UIColor colorWithHexString:HexColor]

#define KClearColor [UIColor clearColor]
#define KWhiteColor [UIColor whiteColor]
#define KBlackColor [UIColor blackColor]
#define KGrayColor [UIColor grayColor]
#define KGray2Color [UIColor lightGrayColor]
#define KBlueColor [UIColor blueColor]
#define KRedColor [UIColor redColor]
#define KGreenColor [UIColor greenColor]
#define KYellowColor [UIColor yellowColor]
#define KPurpleColor [UIColor purpleColor]
#define KOrangeColor [UIColor orangeColor]

#define KRGBColor(r, g, b) [UIColor colorWithRed:(r)/255.0 green:(g)/255.0 blue:(b)/255.0 alpha:1.0]
#define KRGBAlphaColor(r, g, b, a) [UIColor colorWithRed:(r)/255.0 green:(g)/255.0 blue:(b)/255.0 alpha:(a)]
#define KWhiteAlphaColor(a) [[UIColor whiteColor] colorWithAlphaComponent:a];

//随机色
#define KRANDOM_COLOR [UIColor colorWithHue: (arc4random() % 256 / 256.0) saturation:((arc4random()% 128 / 256.0 ) + 0.5) brightness:(( arc4random() % 128 / 256.0 ) + 0.5) alpha:1.0]

#pragma mark ===========宽度区===========--BlueSkyer25
#define KScreenWidth   [[UIScreen mainScreen] bounds].size.width
#define KScreenHeight  [[UIScreen mainScreen] bounds].size.height
#define kScreen_Bounds [UIScreen mainScreen].bounds

#define KSCALE_WIDTH [UIScreen mainScreen].bounds.size.width/375
#define KSCALE_HEIGHT [UIScreen mainScreen].bounds.size.height/667

#define KAdaptX(x) [UIScreen mainScreen].bounds.size.width / 375 * x
#define KAdaptY(y) [UIScreen mainScreen].bounds.size.height / 667 * y
#define KHAdaptX(x) [UIScreen mainScreen].bounds.size.width / 667 * x
#define KHAdaptY(y) [UIScreen mainScreen].bounds.size.height / 375 * y

#define KLeftPadding KAdaptX(10)

#define KDeviceVersion [[UIDevice currentDevice].systemVersion floatValue]
#define KNavbarHeight ((kDeviceVersion>=7.0)? 64 :44 )
#define KIOS7DELTA   ((kDeviceVersion>=7.0)? 20 :0 )
#define KTabBarHeight 49
#define KStatusHeight 20


#pragma mark ===========机型判断 ===========--BlueSkyer25
//是否是iPhone X
#define KIS_IPHONE (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone)
#define KIS_IPHONE_X (KIS_IPHONE && [[UIScreen mainScreen] bounds].size.height == 812.0f)

#define KIS_IPAD (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)
#define KIS_IPHONE (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone)

#define KSCREEN_MAX_LENGTH (MAX(KScreenWidth, KScreenHeight))
#define KSCREEN_MIN_LENGTH (MIN(KScreenWidth, KScreenHeight))

#define IS_IPHONE4 (KIS_IPHONE && KSCREEN_MAX_LENGTH < 568.0)
#define IS_IPHONE5 (KIS_IPHONE && KSCREEN_MAX_LENGTH == 568.0)
#define IS_IPHONE6 (KIS_IPHONE && KSCREEN_MAX_LENGTH == 667.0)
#define IS_IPHONE6P (KIS_IPHONE && KSCREEN_MAX_LENGTH == 736.0)

#pragma mark ===========数据验证===========--BlueSkyer25
#define KStrValid(f) (f!=nil && [f isKindOfClass:[NSString class]] && ![f isEqualToString:@""])
#define KSafeStr(f) (KStrValid(f) ? f:@"")
#define KHasString(str,key) ([str rangeOfString:key].location!=NSNotFound)

#define KValidStr(f) KStrValid(f)
#define KValidDictionary(f) (f!=nil && [f isKindOfClass:[NSDictionary class]])
#define KValidArray(f) (f!=nil && [f isKindOfClass:[NSArray class]] && [f count]>0)
#define KValidNum(f) (f!=nil && [f isKindOfClass:[NSNumber class]])
#define KValidClass(f,cls) (f!=nil && [f isKindOfClass:[cls class]])
#define KValidData(f) (f!=nil && [f isKindOfClass:[NSData class]])

#pragma mark ===========字体区===========--BlueSkyer25
#define KBOLDSYSTEMFONT(FONTSIZE) [UIFont boldSystemFontOfSize:FONTSIZE]
#define KSYSTEMFONT(FONTSIZE)     [UIFont systemFontOfSize:FONTSIZE]
#define KFONT(NAME, FONTSIZE)     [UIFont fontWithName:(NAME) size:(FONTSIZE)]

#pragma mark ===========获取系统对象===========--BlueSkyer25

#define KApplication        [UIApplication sharedApplication]
#define KAppWindow          [UIApplication sharedApplication].delegate.window
#define KAppDelegate        [AppDelegate shareAppDelegate]
#define KRootViewController [UIApplication sharedApplication].delegate.window.rootViewController
#define KUserDefaults       [NSUserDefaults standardUserDefaults]
#define KNotificationCenter [NSNotificationCenter defaultCenter]

#pragma mark ===========通知===========--BlueSkyer25
//发送通知
#define KPostNotification(name,obj) [[NSNotificationCenter defaultCenter] postNotificationName:name object:obj];

#pragma mark ===========设置图片===========--BlueSkyer25
#define KImageName(imageName) [UIImage imageNamed:[NSString stringWithFormat:@"%@",imageName]]


#pragma mark ===========弱引用===========--BlueSkyer25
#define WEAKSELF __weak typeof(self) weakSelf = self

#pragma mark ===========字符串===========--BlueSkyer25
#define KNSStringFormat(format,...) [NSString stringWithFormat:format,##__VA_ARGS__]

#pragma mark ===========JDLLog===========--BlueSkyer25
#ifdef DEBUG
#define JDLLog(FORMAT, ...) fprintf(stderr, "%s:%zd\t%s\n", [[[NSString stringWithUTF8String: __FILE__] lastPathComponent] UTF8String], __LINE__, [[NSString stringWithFormat: FORMAT, ## __VA_ARGS__] UTF8String]);
#else
#define JDLLog(FORMAT, ...) nil
#endif

#endif /* JDLScreenBoundsFontColor_h */
