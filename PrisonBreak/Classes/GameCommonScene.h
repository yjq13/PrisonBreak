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
class Game : public cocos2d::Layer{
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    // a selector callback
    void setUI();
    
    // implement the "static create()" method manually
    CREATE_FUNC(Game);
};
#endif /* defined(__PrisonBreak__GameCommonScene__) */

