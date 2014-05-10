//
//  MainMenu.cpp
//  SaveTheWorld
//
//  Created by Giap Nguyen on 5/10/14.
//
//

#include "MainMenu.h"

USING_NS_CC;

Scene* MainMenu::createScene()
{
  // 'scene' is an autorelease object
  auto scene = Scene::create();
  
  // 'layer' is an autorelease object
  auto layer = MainMenu::create();
  
  // add layer as a child to scene
  scene->addChild(layer);
  
  // return the scene
  return scene;
}

// on "init" you need to initialize your instance
bool MainMenu::init()
{
  if ( !Layer::init() )
  {
    return false;
  }
  
  Sprite* background = Sprite::create("mainbg.jpg");
  background->setPosition(SCREEN_SIZE.width/2, SCREEN_SIZE.height/2);
  setScale(SCREEN_SIZE.width/background->getContentSize().width,
           SCREEN_SIZE.height/background->getContentSize().height);
  
  addChild(background);
  
  Sprite* normalS = Sprite::create("startButton.png");
  Sprite* selectedS = Sprite::create("startButton.png");
  selectedS->setColor(Color3B::GRAY);
  MenuItemSprite* start = MenuItemSprite::create(normalS,
                                                selectedS,
                                                CC_CALLBACK_1(MainMenu::goToStartScene, this));
  Point posStart = Point(SCREEN_SIZE.width/2, SCREEN_SIZE.height/4 + 10);
  start->setPosition(posStart);
  start->setScale(0.5f);
  
  Sprite* normalE = Sprite::create("emergencyButton.png");
  normalE->setColor(Color3B::RED);
  Sprite* selectedE = Sprite::create("emergencyButton.png");
  selectedE->setColor(Color3B::GRAY);
  MenuItemSprite* emergency = MenuItemSprite::create(normalE,
                                                     selectedE,
                                                     CC_CALLBACK_1(MainMenu::goToStartScene, this));
  Point posEmer = Point(SCREEN_SIZE.width/3 + 10, SCREEN_SIZE.height/4 + 10);
  emergency->setPosition(posEmer);
  emergency->setScale(0.5f);
  
  Sprite* normalSe = Sprite::create("settingButton.png");
  Sprite* selectedSe = Sprite::create("settingButton.png");
  selectedSe->setColor(Color3B::GRAY);
  MenuItemSprite* settings = MenuItemSprite::create(normalSe,
                                                    selectedSe,
                                                    CC_CALLBACK_1(MainMenu::goToStartScene, this));
  Point posSe = Point(2 * SCREEN_SIZE.width/3 - 10, SCREEN_SIZE.height/4 + 10);
  settings->setPosition(posSe);
  settings->setScale(0.5f);


  Menu* menu = Menu::create(start, emergency, settings, NULL);
  menu->setPosition(Point::ZERO);
  
  addChild(menu, 1);
  
  return true;
}

void MainMenu::goToStartScene(Ref* pSender)
{
  Director::getInstance()->replaceScene(MapScene::create());
}
