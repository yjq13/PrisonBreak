#import <UIKit/UIKit.h>

@class RootViewController;
//测试能否提交
@interface AppController : NSObject <UIApplicationDelegate> {
    UIWindow *window;
}

@property(nonatomic, readonly) RootViewController* viewController;

@end

