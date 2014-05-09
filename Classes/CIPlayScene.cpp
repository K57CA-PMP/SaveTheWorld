//
//  CIPlayScene.cpp
//  SaveTheWorld
//
//  Created by Tuan TQ on 5/9/14.
//
//

#include "CIPlayScene.h"
#include "cocos2d.h"
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
  
  addBackground();
  addBoy();
  addItems();
  addHooks();
  hookRotateAnimation();
  
  schedule(schedule_selector(CIPlayScene::update));
  
  return true;
}

void CIPlayScene::addBackground()
{
  _background = Sprite::create("CollectItems/background.png");
  _background->setScale(1.45);
  _background->setAnchorPoint(_origin);
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
  _hook->setPosition(Point(_visibleSize.width/2 - 20,
                           _visibleSize.height - 30));
  this->addChild(_hook, 10);
}

void CIPlayScene::hookRotateAnimation()
{
  Animation* rotation = Animation::create();
  rotation->setDelayPerUnit(0.5);
  rotation->addSpriteFrameWithFile("CollectItems/hook.png");
  
  Animate* rotate = Animate::create(rotation);
  ActionInterval* left = RotateBy::create(1, 80);
  ActionInterval* right = RotateBy::create(1, -80);
  ActionInterval* sequence = Sequence::create(left, right, right, left, NULL);
  
  Spawn* spawn = Spawn::create(sequence, rotate, NULL);
  RepeatForever* rotateForever = RepeatForever::create(spawn);
  _hook->runAction(rotateForever);
}

void CIPlayScene::update(float pDT)
{
  
}