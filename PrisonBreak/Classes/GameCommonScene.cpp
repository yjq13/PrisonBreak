//
//  GameCommonScene.cpp
//  PrisonBreak
//
//  Created by yjq131250077 on 15/9/11.
//
//

#include "GameCommonScene.h"
USING_NS_CC;

Scene* Game :: createScene(){
    auto scene=Scene::create();
    auto layer=Game::create();
    scene->addChild(layer);
    return scene;
}
bool Game::init(){
    if(!Layer::init()){
        return false;
    }
    setUI();
    return true;
}
void Game::setUI(){
    
//测试在界面上放置组件
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    auto gameLabel=Label::createWithTTF("GAME", "fonts/Marker Felt.ttf", 24);
    gameLabel->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - gameLabel->getContentSize().height));
    this->addChild(gameLabel);
    
    auto image1=MenuItemImage::create("01.jpg", "01.jpg");
    image1->setPosition(100, 100);
    auto menu=Menu::create(image1,NULL);
    menu->setPosition(100,100);
    this->addChild(menu,1);
    
    //下面 测试节点的运动
    auto moveTo=MoveTo::create(3.0f, Vec2(origin.x + visibleSize.width/2,
                                          origin.y + visibleSize.height - gameLabel->getContentSize().height-200));
    auto action=Sequence::create(moveTo,Spawn::create(RotateBy::create(1.0f,360),ScaleTo::create(1.0f,1.2f),NULL),Blink::create(1,5),FadeOut::create(0.5f), NULL);
    
    image1->runAction(action);
    
    //下面测试动画的实现
    
    
    //下面测试触控
    sprite=CCSprite::create("03.jpg");
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    sprite->setScale(1, 0.5);
    this->addChild(sprite,1);
    
    
    auto listener=EventListenerTouchAllAtOnce::create();
    listener->onTouchesMoved=CC_CALLBACK_2(Game::onTouchesMoved, this);
    listener->onTouchesBegan=CC_CALLBACK_2(Game::onTouchesBegan, this);
    listener->onTouchesEnded=CC_CALLBACK_2(Game::onTouchesEnded, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    
}

void Game::onTouchesMoved(const std::vector<Touch *> &touches, cocos2d::Event *event){
    CCLOG("asdasdasdasd");
}