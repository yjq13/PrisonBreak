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
    auto scene=Scene::createWithPhysics();
    //scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    auto layer=Game::create();
    layer->setPhyWorld(scene->getPhysicsWorld());
    scene->addChild(layer);
    return scene;
}
bool Game::init(){
    if(!Layer::init()){
        return false;
    }
    //计数器设为0
    index=0;
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
   // this->addChild(menu,1);
    
    //下面 测试节点的运动
    //    auto moveTo=MoveTo::create(3.0f, Vec2(origin.x + visibleSize.width/2,
    //                                          origin.y + visibleSize.height - gameLabel->getContentSize().height-200));
    //auto action=Sequence::create(moveTo,Spawn::create(RotateBy::create(1.0f,360),ScaleTo::create(1.0f,1.2f),NULL),Blink::create(1,5),FadeOut::create(0.5f), NULL);
    
    //image1->runAction(action);
    
    //下面测试动画的实现
    
    
    //下面测试触控
//    sprite=CCSprite::create("03.jpg");
//    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
//    sprite->setScale(1, 0.5);
    
    
    
    auto sprite1=Sprite::create("00.jpg");
    sprite1->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    auto wallBody1=PhysicsBody::createBox(sprite1->getContentSize());
    wallBody1->setGravityEnable(false);
//    wallBody1->getShape(0)->setRestitution(1.0f);
//    wallBody1->getShape(0)->setFriction(0.0);
//    wallBody1->getShape(0)->setDensity(1.0);
//    Vect force = Vect(500000.0f, 500000.0f);
//    wallBody1->applyImpulse(force);
    //sprite1->setPhysicsBody(wallBody1);
    sprite1->setTag(1);
    this->addChild(sprite1,1);
    
    auto sprite2=Sprite::create("00.jpg");
    sprite2->setPosition(Vec2(300 , 250));
    auto wallBody2=PhysicsBody::createBox(sprite2->getContentSize());
     wallBody2->setGravityEnable(false);
    //sprite2->setPhysicsBody(wallBody2);
    sprite2->setTag(2);
    this->addChild(sprite2,2);

    
    
    auto listener=EventListenerTouchOneByOne::create();
    listener->onTouchMoved=CC_CALLBACK_2(Game::onTouchMoved, this);
    listener->onTouchBegan=CC_CALLBACK_2(Game::onTouchBegan, this);
    listener->onTouchEnded=CC_CALLBACK_2(Game::onTouchEnded, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    //下面检测碰撞
    
    auto contactListener=EventListenerPhysicsContact::create();
    contactListener->onContactBegin=CC_CALLBACK_1(Game::onContactBegin, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener, this);
    
}

bool Game::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event){
    CCLOG("begin");
    //计数器归零,数组清空
    index=0;
    for (int i=0;i<10000;i++){
        points[i]=ccp(0,0);
    }
    return true;
}
void Game::onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event){
    isMoved=true;
    points[index]=touch->getLocation();
    auto p=touch->getLocation();
    auto r=DrawNode::create();
    addChild(r);
    if(index>0){
        r->drawSegment(points[index-1], p, 10, Color4F(CCRANDOM_0_1(), CCRANDOM_0_1(), CCRANDOM_0_1(), 1));
    }
    index++;
}

void Game::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event){
    printf("ed");
    //下面是主角跟随路线移动
    auto s=Sprite::create("01.jpg");
    s->autorelease();
    s->setPosition(points[0]);
    addChild(s);
    //下面是填装动作的容器
    Vector<FiniteTimeAction*> actionVector;
    for (int i=0;i<10000;i++){
        if (i!=0&&points[i].x!=0) {
            actionVector.pushBack(MoveTo::create(ccpSub(points[i-1], points[i]).length()/100, points[i]));
        }
    }if(isMoved){
        auto allAction=Sequence::create(actionVector);
        s->runAction(allAction);
    }
    isMoved=false;
}

bool Game::onContactBegin(const cocos2d::PhysicsContact &contact){
    Sprite* spriteA = (Sprite*)contact.getShapeA()->getBody()->getNode();
    Sprite* spriteB = (Sprite*)contact.getShapeB()->getBody()->getNode();
    int tagA = spriteA->getTag();
    int tagB = spriteB->getTag();
    if ((tagA == 1 && tagB == 2)||(tagA == 2 && tagB == 1))
    {
        spriteA->removeFromParent();
        spriteB->removeFromParent();
    }
    CCLOG("asdasdasdsad");
    return true;
}
