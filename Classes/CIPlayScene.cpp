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
#include "Constant.h"
#include "CIGameManager.h"
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
  addGameOver();
  addReplayButton();
  addWin();
  addBackBtn();
  hookRotateAnimation();
  handleTouch();
  
  _rotateAction->retain();
  _isHookRotating = false;
  _ItemCollected = false;
  _indexOfCollectedItem = 0;
  _hooktail = CCArray::create();
  _hooktail->retain();
  _score = 0;
  _nItems = 0;
  switch (CIGameManager::getGameLevel())
  {
    case 1:
      _timeLimit = 20;
      break;
    case 2:
      _timeLimit = 25;
      break;
    case 3:
      _timeLimit = 29;
      break;
    case 4:
      _timeLimit = 32;
      break;
    case 5:
      _timeLimit = 5;
      break;
    default:
      break;
  }
  addLbls();
  
  schedule(schedule_selector(CIPlayScene::update));
  schedule(schedule_selector(CIPlayScene::countdown), 1);
  
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
  _itemsArray = CCArray::createWithCapacity(5);
  _itemsArray->retain();
  _nItems = CIGameManager::getGameLevel() + 2;
  for (int i = 0; i < _nItems;  i++)
  {
    CCString* itemName = CCString::createWithFormat("CollectItems/item%i.png", i);
    Sprite* item = Sprite::create(itemName->getCString());
    switch (i)
    {
      case 0:
        item->setPosition(ITEM1_POS * 1.45);
        break;
      case 1:
        item->setPosition(ITEM2_POS * 1.45);
        break;
      case 2:
        item->setPosition(ITEM3_POS * 1.45);
        break;
      case 3:
        item->setPosition(ITEM4_POS * 1.45);
        break;
      case 4:
        item->setPosition(ITEM5_POS * 1.45);
        break;
      case 5:
        item->setPosition(ITEM6_POS * 1.45);
        break;
      case 6:
        item->setPosition(ITEM7_POS * 1.45);
        break;
      default:
        break;
    }
    this->addChild(item, 5);
    _itemsArray->addObject(item);
  }
}

void CIPlayScene::addHooks()
{
  Sprite* staticHook = Sprite::create("CollectItems/hook.png");
  staticHook->setPosition(_visibleSize.width/2 + 27,
                          _visibleSize.height - 60);
  this->addChild(staticHook, 3);
  
  _hook = Sprite::create("CollectItems/hook.png");
  _hook->setAnchorPoint(Point(0.5, 1));
  _hook->setPosition(HOOK_POSITION);
  this->addChild(_hook, 4);
}

void CIPlayScene::addLbls()
{
  _scoreLbl = CCLabelTTF::create("0", "ordin", 50);
  _scoreLbl->setHorizontalAlignment(kCCTextAlignmentCenter);
  _scoreLbl->setVerticalAlignment(kCCVerticalTextAlignmentCenter);
  _scoreLbl->setColor(Color3B(255, 255, 255));
  _scoreLbl->setPosition(SCORE_LBL_POS * 1.45);
  this->addChild(_scoreLbl, 10);
  
  CCString* timeStart = CCString::createWithFormat("00:%i", _timeLimit);
  _timeLbl = CCLabelTTF::create(timeStart->getCString(), "ordin", 50);
  _timeLbl->setHorizontalAlignment(kCCTextAlignmentCenter);
  _timeLbl->setVerticalAlignment(kCCVerticalTextAlignmentCenter);
  _timeLbl->setColor(Color3B(255, 255, 255));
  _timeLbl->setPosition(TIME_LBL_POS * 1.45);
  this->addChild(_timeLbl, 10);
}

void CIPlayScene::addGameOver()
{
  _gameOver = Sprite::create("CollectItems/gameOver.png");
  _gameOver->setScale(2);
  _gameOver->setPosition(SCREEN_SIZE.width/2, SCREEN_SIZE.height/1.5);
  _gameOver->setVisible(false);
  this->addChild(_gameOver, 11);
}

void CIPlayScene::addReplayButton()
{
  auto menu = MenuItemImage::create("CollectItems/replay.png",
                                    "CollectItems/replay.png",
                                    CC_CALLBACK_1(CIPlayScene::replayBtnTouched, this));
  menu->setScale(0.5);
  menu->setPosition(SCREEN_SIZE.width/2, SCREEN_SIZE.height/2.5);
  _replayBtn = Menu::create(menu, NULL);
  _replayBtn->setPosition(Point::ZERO);
  _replayBtn->setVisible(false);
  this->addChild(_replayBtn, 11);
}

void CIPlayScene::addWin()
{
  auto menu = MenuItemImage::create("CollectItems/win.png",
                                    "CollectItems/win.png",
                                    CC_CALLBACK_1(CIPlayScene::winTouched, this));
  menu->setPosition(Point(SCREEN_SIZE.width/2, SCREEN_SIZE.height/2));
  _win = Menu::create(menu, NULL);
  _win->setScale(0.7);
  _win->setPosition(Point::ZERO);
  _win->setVisible(false);
  this->addChild(_win, 11);
}

void CIPlayScene::addBackBtn()
{
  auto menu = MenuItemImage::create("CollectItems/back.png",
                                    "CollectItems/back.png",
                                    CC_CALLBACK_1(CIPlayScene::backBtnTouched, this));
  menu->setPosition(Point(_origin.x + menu->getContentSize().width/2, _origin.y + menu->getContentSize().height/2));
  menu->setScale(0.7);
  _backBtn = Menu::create(menu, _backBtn);
  _backBtn->setPosition(Point::ZERO);
  _backBtn->setVisible(false);
  this->addChild(_backBtn, 11);
}

void CIPlayScene::replayBtnTouched(Ref* pSender)
{
  auto scene = CCTransitionCrossFade::create(0.5, CIPlayScene::createScene());
  Director::getInstance()->sharedDirector()->replaceScene(scene);
}

void CIPlayScene::winTouched(Ref* pSender)
{
  auto scene = CCTransitionCrossFade::create(0.5, HelloWorld::createScene());
  Director::getInstance()->sharedDirector()->replaceScene(scene);
}

void CIPlayScene::backBtnTouched(Ref* pSender)
{
  auto scene = CCTransitionCrossFade::create(0.5, HelloWorld::createScene());
  Director::getInstance()->sharedDirector()->replaceScene(scene);
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
  _launchAction = Spawn::create(action, launch, NULL);
  _launchAction->retain();
  _hook->runAction(_launchAction);
}

void CIPlayScene::hookRetrieveAnimation()
{
  Animation* retrieving = Animation::create();
  retrieving->addSpriteFrameWithFile("CollectItems/hook_long.png");
  
  Animate* retrieve = Animate::create(retrieving);
  ActionInterval* action;
  if (_ItemCollected)
  {
    action = MoveTo::create(RETRIEVING_DELAY * 3, HOOK_POSITION);
  }
  else
  {
    action = MoveTo::create(RETRIEVING_DELAY, HOOK_POSITION);
  }
  _retrieveAction = Spawn::create(action, retrieve, NULL);
  _retrieveAction->retain();
  _hook->runAction(_retrieveAction);
}

void CIPlayScene::itemRetrieveAnimation()
{
  Animation* retrieving = Animation::create();
  retrieving->addSpriteFrameWithFile("CollectItems/food.png");
  
  Sprite* item = ((Sprite*)(_itemsArray->objectAtIndex(_indexOfCollectedItem)));
  float dstX = HOOK_POSITION.x - sin(_hook->getRotation() * PI/180) * _hook->getContentSize().height;
  float dstY = HOOK_POSITION.y - cos(_hook->getRotation() * PI/180) * _hook->getContentSize().height;
  Animate* retrieve = Animate::create(retrieving);
  ActionInterval* action = MoveTo::create(RETRIEVING_DELAY * 3,
                                          Point(dstX, dstY));
  _itemRetrieveAction = Spawn::create(action, retrieve, NULL);
  _itemRetrieveAction->retain();
  ((Sprite*)(_itemsArray->objectAtIndex(_indexOfCollectedItem)))->runAction(_itemRetrieveAction);
}

void CIPlayScene::drawHookTail()
{
  Sprite* tail = Sprite::create("CollectItems/hook_tail_short.png");
  tail->setPosition(_hook->getPosition());
  tail->setRotation(_hook->getRotation());
  this->addChild(tail, 4);
  _hooktail->addObject(tail);
}

void CIPlayScene::checkCollision()
{
  Rect hookRect = _hook->boundingBox();
  for (int i = 0; i < _itemsArray->count(); i++)
  {
    Sprite* itemShadow = Sprite::create("CollectItems/itemShadow.png");
    itemShadow->setScale(1.5);
    itemShadow->setPosition(((Sprite*)(_itemsArray->objectAtIndex(i)))->getPosition());
    itemShadow->setVisible(false);
    Rect itemRect = itemShadow->getBoundingBox();
    if (hookRect.intersectsRect(itemRect))
    {
      _hook->stopAllActions();
      _state = ITEM_COLLECTED;
      _ItemCollected = true;
      _indexOfCollectedItem = i;
      ((Sprite*)(_itemsArray->objectAtIndex(_indexOfCollectedItem)))->setScale(2);
      break;
    }
  }
}

void CIPlayScene::handleTouch()
{
  auto listener = EventListenerTouchOneByOne::create();
  listener->setSwallowTouches(true);
  
  listener->onTouchBegan = [=](Touch* pTouch, Event* pEvent)
  {
    if (_state == ROTATE) {
      _hook->stopAllActions();
      this->hookLaunchAnimation();
      _state = LAUNCH;
    }
    return false;
  };
  
  _eventDispatcher->addEventListenerWithSceneGraphPriority(listener,
                                                           _background);
}

void CIPlayScene::update(float pDT)
{
  if (_itemsArray->count() == 6)
  {
    if (CIGameManager::getGameLevel() == 5)
    {
      _state = WIN;
    }
    else
    {
      _state = NEXT_LEVEL;
    }
  }
  
  if (_state == ROTATE && !_isHookRotating)
  {
    while (_hooktail->count() > 0)
    {
      ((Sprite*)(_hooktail->objectAtIndex(_hooktail->count()-1)))->setVisible(false);
      _hooktail->removeLastObject();
    }
    _hook->setRotation(LIMITED_ANGLE);
    _hook->runAction(_rotateAction);
    _isHookRotating = true;
  }
  else if (_state == LAUNCH)
  {
    drawHookTail();
    this->checkCollision();
    if (_launchAction->isDone())
    {
      this->hookRetrieveAnimation();
      _state = RETRIEVE;
    }
  }
  else if (_state == RETRIEVE)
  {
    if (_hooktail->count() > 0)
    {
      Sprite* last = ((Sprite*)(_hooktail->objectAtIndex(_hooktail->count()-1)));
      if (last->getPositionY() < _hook->getPositionY())
      {
        last->setVisible(false);
        _hooktail->removeLastObject();
      }
    }
    if (_retrieveAction->isDone())
    {
      if (_ItemCollected)
      {
        ((Sprite*)(_itemsArray->objectAtIndex(_indexOfCollectedItem)))->setVisible(false);
        _itemsArray->removeObjectAtIndex(_indexOfCollectedItem);
        _score++;
        sprintf(_scoreBuffer, "%i", _score);
        _scoreLbl->setString(_scoreBuffer);
        _ItemCollected = false;
      }
      _isHookRotating = false;
      _state = ROTATE;
    }
  }
  else if (_state == ITEM_COLLECTED)
  {
    this->hookRetrieveAnimation();
    this->itemRetrieveAnimation();
    _state = RETRIEVE;
  }
  else if (_state == GAME_OVER)
  {
    _hook->stopAllActions();
    if (_indexOfCollectedItem >= 0) {
      ((Sprite*)(_itemsArray->objectAtIndex(_indexOfCollectedItem)))->stopAllActions();
    }
    _gameOver->setVisible(true);
    _replayBtn->setVisible(true);
    _backBtn->setVisible(true);
  }
  else if (_state == NEXT_LEVEL)
  {
//    this->release();
    CIGameManager::setGameLevel(CIGameManager::getGameLevel() + 1);
    auto scene = CCTransitionCrossFade::create(0.5, CIPlayScene::createScene());
    Director::getInstance()->sharedDirector()->replaceScene(scene);
  }
  else if (_state == WIN)
  {
    _win->setVisible(true);
  }
}

void CIPlayScene::countdown(float pDT)
{
  if (_timeLimit > 0)
  {
    if (_timeLimit <= 10)
    {
      _timeLbl->setColor(Color3B(198, 68, 56));
    }
    _timeLimit--;
    sprintf(_timeBuffer, "00:%i", _timeLimit);
    _timeLbl->setString(_timeBuffer);
  }
  else
  {
    _state = GAME_OVER;
  }
}

void CIPlayScene::release()
{
  _itemsArray->release();
  _rotateAction->release();
  _hooktail->release();
  _launchAction->release();
  _retrieveAction->release();
  _itemRetrieveAction->release();
}