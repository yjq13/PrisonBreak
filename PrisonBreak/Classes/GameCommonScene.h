//
//  GameCommonScene.h
//  PrisonBreak
//
//  Created by yjq131250077 on 15/9/11.
//
//

#ifndef __PrisonBreak__GameCommonScene__
#define __PrisonBreak__GameCommonScene__

#include "cocos2d.h"
USING_NS_CC;
class Game : public Layer{
public:
    static Scene* createScene();
    
    virtual bool init();
    
    // a selector callback
    void setUI();
    
    //触屏测试
    CCSprite* sprite;
    //重载触控函数
//    void onTouchesBegan(const std::vector<Touch*>& touches, cocos2d::Event  *event);
    void onTouchesMoved(const std::vector<Touch*>& touches, cocos2d::Event  *event);
//    void onTouchesEnded(const std::vector<Touch*>& touches, cocos2d::Event  *event);
//    void onTouchesCancelled(const std::vector<Touch*>& touches, cocos2d::Event  *event);
    
    // implement the "static create()" method manually
    CREATE_FUNC(Game);
};
#endif /* defined(__PrisonBreak__GameCommonScene__) */

