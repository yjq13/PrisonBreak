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
//    points->addControlPoint(Vec2(100, 100));
//    points->addControlPoint(Vec2(100, 100));
//    CCLOG("%zd",points->count());
    points=PointArray::create(1000);
    setUI();
    return true;
}
void Game::setUI(){
    //addPoint(Vec2(0, 0));
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
//    auto moveTo=MoveTo::create(3.0f, Vec2(origin.x + visibleSize.width/2,
//                                          origin.y + visibleSize.height - gameLabel->getContentSize().height-200));
    //auto action=Sequence::create(moveTo,Spawn::create(RotateBy::create(1.0f,360),ScaleTo::create(1.0f,1.2f),NULL),Blink::create(1,5),FadeOut::create(0.5f), NULL);
    
    //image1->runAction(action);
    
    //下面测试动画的实现
    
    
    //下面测试触控
    sprite=CCSprite::create("03.jpg");
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    sprite->setScale(1, 0.5);
    this->addChild(sprite,1);
    
    
    auto listener=EventListenerTouchOneByOne::create();
    listener->onTouchMoved=CC_CALLBACK_2(Game::onTouchMoved, this);
    listener->onTouchBegan=CC_CALLBACK_2(Game::onTouchBegan, this);
    listener->onTouchEnded=CC_CALLBACK_2(Game::onTouchEnded, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    
}

bool Game::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event){
    CCLOG("begin");
    return true;
}
void Game::onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event){
    //坑了爹的point竟然不能共享
        auto location=touch->getLocation();
        CCLOG("(%f,%f)",location.x,location.y);
   // point=PointArray::create(1000);
    //points->addControlPoint(touch->getLocation());
    points=PointArray::create(1000);
    points->addControlPoint(touch->getLocation());
    CCLOG("%zd",this->points->count());
    //addPoint(location);
    
}

void Game::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event){
    printf("ed");
}
void Game::addPoint(Vec2 p){
    points->addControlPoint(p);
    CCLOG("asdasd");
}