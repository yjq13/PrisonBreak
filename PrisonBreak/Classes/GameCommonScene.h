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
    PointArray* points;//=PointArray::create(10000);//手指画出来的点集
    
    bool onTouchBegan(Touch* touch,Event* event);
    void onTouchMoved(Touch* touch,Event* event);
    void onTouchEnded(Touch* touch,Event* event);
    void addPoint(Vec2 p);
   // void onTouchCancel(Touch* touch,Event* event);
    //测试用数组
    
    // implement the "static create()" method manually
    CREATE_FUNC(Game);
};
#endif /* defined(__PrisonBreak__GameCommonScene__) */

