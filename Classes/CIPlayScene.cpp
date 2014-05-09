//
//  CIPlayScene.cpp
//  SaveTheWorld
//
//  Created by Tuan TQ on 5/9/14.
//
//

#include "CIPlayScene.h"
#include "cocos2d.h"
#include <math.h>
USING_NS_CC;

Scene* CIPlayScene::createScene()
{
  auto scene = Scene::create();
  auto layer = CIPlayScene::create();
  scene->addChild(layer);
  return scene;
}

bool CIPlayScene::init()
{
  if (!Layer::init()) {
    return false;
  }
  
  _visibleSize = Director::getInstance()->getVisibleSize();
  _origin = Director::getInstance()->getVisibleOrigin();
  _state = ROTATE;
  
  addBackground();
  addBoy();
  addItems();
  addHooks();
  hookRotateAnimation();
  handleTouch();
  
  _rotateAction->retain();
  _isHookRotating = false;
  
  schedule(schedule_selector(CIPlayScene::update));
  
  return true;
}

void CIPlayScene::addBackground()
{
  _background = Sprite::create("CollectItems/background.png");
  _background->setScale(1.45);
  _background->setAnchorPoint(Point::ZERO);
  _background->setPosition(_origin);
  this->addChild(_background, 0);
}

void CIPlayScene::addBoy()
{
  _boy = Sprite::create("CollectItems/boy.png");
  _boy->setScale(0.45);
  _boy->setPosition(Point(_visibleSize.width/2 - 180,
                          _visibleSize.height - _boy->getContentSize().height/2 - 15));
  this->addChild(_boy, 5);
}

void CIPlayScene::addItems()
{
  Sprite* food = Sprite::create("CollectItems/food.png");
  food->setScale(0.5);
  food->setPosition(Point(_visibleSize.width/3, _visibleSize.height/3));
  this->addChild(food, 5);
}

void CIPlayScene::addHooks()
{
  Sprite* staticHook = Sprite::create("CollectItems/hook.png");
  staticHook->setPosition(_visibleSize.width/2 + 27,
                          _visibleSize.height - 60);
  this->addChild(staticHook, 10);
  
  _hook = Sprite::create("CollectItems/hook.png");
  _hook->setAnchorPoint(Point(0.5, 1));
  _hook->setPosition(HOOK_POSTITION);
  this->addChild(_hook, 10);
}

void CIPlayScene::hookRotateAnimation()
{
  Animation* rotation = Animation::create();
  rotation->addSpriteFrameWithFile("CollectItems/hook.png");
  
  Animate* rotate = Animate::create(rotation);
  ActionInterval* left = RotateBy::create(ROTATION_DELAY, LIMITED_ANGLE);
  ActionInterval* right = RotateBy::create(ROTATION_DELAY, -LIMITED_ANGLE);
  ActionInterval* sequence = Sequence::create(right, right, left, left, NULL);
  _hook->setRotation(LIMITED_ANGLE);
  
  Spawn* spawn = Spawn::create(sequence, rotate, NULL);
  _rotateAction = RepeatForever::create(spawn);
}

void CIPlayScene::hookLaunchAnimation()
{
  Animation* launching = Animation::create();
  launching->addSpriteFrameWithFile("CollectItems/hook_long.png");

  float dstX = _hook->getPositionX() * (1 - tan(_hook->getRotation() * PI/180));
  float dstY = _origin.y;
  if (_hook->getRotation() > 45)
  {
    dstX = _origin.x;
    dstY = _hook->getPositionY() - (_hook->getPositionX() /
                                    tan(_hook->getRotation() * PI/180));
  }
  else if (_hook->getRotation() < -45)
  {
    dstX = _visibleSize.width;
    dstY = _hook->getPositionY() - (_hook->getPositionX() /
                                    tan(-_hook->getRotation() * PI/180));
  }
  Animate* launch = Animate::create(launching);
  ActionInterval* action = MoveTo::create(LAUNCHING_DELAY, Point(dstX, dstY));
  ActionInterval* sequence = Sequence::create(action, NULL);
  _launchAction = Spawn::create(sequence, launch, NULL);
  _launchAction->retain();
  _hook->runAction(_launchAction);
}

void CIPlayScene::

void CIPlayScene::handleTouch()
{
  auto listener = EventListenerTouchOneByOne::create();
  listener->setSwallowTouches(true);
  
  listener->onTouchBegan = [=](Touch* pTouch, Event* pEvent)
  {
    _state = LAUNCH;
    _hook->stopAllActions();
    this->hookLaunchAnimation();
    return false;
  };
  
  _eventDispatcher->addEventListenerWithSceneGraphPriority(listener,
                                                           _background);
}

void CIPlayScene::update(float pDT)
{
  if (_state == ROTATE && !_isHookRotating)
  {
    _hook->setRotation(LIMITED_ANGLE);
    _hook->runAction(_rotateAction);
    _isHookRotating = true;
  }
  else if (_state == LAUNCH)
  {
//    _hook->stopAction(_rotateAction);
//    _hook->runAction(_launchAction);
    if (_launchAction->isDone())
    {
      _hook->setPosition(HOOK_POSTITION);
      _state = RETRIEVE;
    }
    _isHookRotating = false;
  }
  else if (_state == RETRIEVE)
  {
    
    
    _state = ROTATE;
  }
}
