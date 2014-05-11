//
//  CIStartScene.cpp
//  SaveTheWorld
//
//  Created by Tuan TQ on 5/10/14.
//
//

#include "CIStartScene.h"
USING_NS_CC;

Scene* CIStartScene::createScene()
{
  auto layer = CIStartScene::create();
  auto scene = Scene::create();
  scene->addChild(layer);
  return scene;
}

bool CIStartScene::init()
{
  if (!Layer::init())
  {
    return false;
  }
  
  _visibleSize = Director::getInstance()->getVisibleSize();
  _visibleOrigin = Director::getInstance()->getVisibleOrigin();
  
  addBackground();
  if (CIGameManager::getDialogState() < 5)
  {
    addDialogs();
    addNextBtn();
    addBackBtn();
  }
  else if (CIGameManager::getDialogState() == 5)
  {
    addStartBtn();
  }
  
  return true;
}

void CIStartScene::addBackground()
{
  switch (CIGameManager::getDialogState())
  {
    case 1:
      _background = Sprite::create("CollectItems/start1.png");
      _background->setScale(2);
      _background->setOpacity(100);
      break;
    case 2:
      _background = Sprite::create("CollectItems/start2.png");
      _background->setScale(2);
      _background->setOpacity(100);
      break;
    case 3:
      _background = Sprite::create("CollectItems/start3.png");
      _background->setScale(3);
      _background->setOpacity(100);
      break;
    case 4:
      _background = Sprite::create("CollectItems/start4.png");
      _background->setScale(3);
      _background->setOpacity(100);
      break;
    case 5:
      _background = Sprite::create("CollectItems/start5.png");
      _background->setScale(1.5);
      break;
    default:
      break;
  }
  _background->setPosition(SCREEN_SIZE.width/2, SCREEN_SIZE.height/2);
  this->addChild(_background, 0);
}

void CIStartScene::addDialogs()
{
  switch (CIGameManager::getDialogState())
  {
    case 1:
      _dialog = EditBox::create(Size(_visibleSize.width/1, _visibleSize.height/9), Scale9Sprite::create());
      _dialog->setPosition(Point(_visibleOrigin.x + _visibleSize.width/1.6, _visibleOrigin.y + _visibleSize.height/2));
      _dialog->setFontColor(Color3B(255, 255, 255));
      _dialog->setFont("Arial", 50);
      _dialog->setText(DIALOG1);
      break;
    case 2:
      _dialog = EditBox::create(Size(_visibleSize.width/1, _visibleSize.height/9), Scale9Sprite::create());
      _dialog->setPosition(Point(_visibleOrigin.x + _visibleSize.width/1.75, _visibleOrigin.y + _visibleSize.height/2));
      _dialog->setFontColor(Color3B(255, 255, 255));
      _dialog->setFont("Arial", 50);
      _dialog->setText(DIALOG2);
      break;
    case 3:
      _dialog = EditBox::create(Size(_visibleSize.width/1.5, _visibleSize.height/9), Scale9Sprite::create());
      _dialog->setPosition(Point(_visibleOrigin.x + _visibleSize.width/1.7, _visibleOrigin.y + _visibleSize.height/2));
      _dialog->setFontColor(Color3B(255, 255, 255));
      _dialog->setFont("Arial", 50);
      _dialog->setText(DIALOG3);
      break;
    case 4:
      _dialog = EditBox::create(Size(_visibleSize.width/1, _visibleSize.height/9), Scale9Sprite::create());
      _dialog->setPosition(Point(_visibleOrigin.x + _visibleSize.width/1.93, _visibleOrigin.y + _visibleSize.height/2));
      _dialog->setFontColor(Color3B(255, 255, 255));
      _dialog->setFont("Arial", 50);
      _dialog->setText(DIALOG4);
      break;
    default:
      addAnswers();
      break;
  }
  _dialog->setMaxLength(20);
  _dialog->setEnabled(false);
  this->addChild(_dialog, 3);
}

void CIStartScene::addNextBtn()
{
  auto menu = MenuItemImage::create("CollectItems/next.png",
                                    "CollectItems/next.png",
                                    CC_CALLBACK_1(CIStartScene::nextBtnTouched, this));
  menu->setPosition(Point(_visibleSize.width - menu->getContentSize().width, _visibleOrigin.y + menu->getContentSize().height));
  _nextBtn = Menu::create(menu, NULL);
  _nextBtn->setPosition(Point::ZERO);
  this->addChild(_nextBtn, 3);
}

void CIStartScene::nextBtnTouched(Ref* pSender)
{
  CIGameManager::setDialogState(CIGameManager::getDialogState() + 1);
  Scene* scene = CCTransitionCrossFade::create(0.5, CIStartScene::createScene());
  Director::getInstance()->sharedDirector()->replaceScene(scene);
}

void CIStartScene::addBackBtn()
{
  if (CIGameManager::getDialogState() != 1)
  {
    auto menu = MenuItemImage::create("CollectItems/back.png",
                                      "CollectItems/back.png",
                                      CC_CALLBACK_1(CIStartScene::backBtnTouched, this));
    menu->setPosition(Point(_visibleOrigin.x + menu->getContentSize().width, _visibleOrigin.y + menu->getContentSize().height));
    _backBtn = Menu::create(menu, NULL);
    _backBtn->setPosition(Point::ZERO);
    this->addChild(_backBtn, 3);
  }
}

void CIStartScene::backBtnTouched(Ref* pSender)
{
  CIGameManager::setDialogState(CIGameManager::getDialogState() - 1);
  Scene* scene = CCTransitionCrossFade::create(0.5, CIStartScene::createScene());
  Director::getInstance()->sharedDirector()->replaceScene(scene);
}

void CIStartScene::addStartBtn()
{
  auto menu = MenuItemImage::create("CollectItems/startButton.png",
                                    "CollectItems/startButton.png",
                                    CC_CALLBACK_1(CIStartScene::startBtnTouched, this));
  menu->setPosition(Point(SCREEN_SIZE.width/2, SCREEN_SIZE.height/3*2));
  _startBtn = Menu::create(menu, NULL);
  _startBtn->setPosition(Point::ZERO);
  this->addChild(_startBtn, 5);
}

void CIStartScene::startBtnTouched(Ref* pSender)
{
  Scene* scene = CCTransitionJumpZoom::create(1, CIPlayScene::createScene());
  Director::getInstance()->sharedDirector()->replaceScene(scene);
}

void CIStartScene::addAnswers()
{
  CIGameManager::setAnswer(1, 1);
  CIGameManager::setAnswer(2, 1);
  CIGameManager::setAnswer(3, 1);
  CIGameManager::setAnswer(4, 3);
  CIGameManager::setAnswer(5, 2);
}