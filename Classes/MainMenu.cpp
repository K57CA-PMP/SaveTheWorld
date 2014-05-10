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
  
  Sprite* normal = Sprite::create("startButton.png");
  Sprite* selected = Sprite::create("startButton.png");
  selected->setColor(Color3B::GRAY);
  MenuItemSprite* item = MenuItemSprite::create(normal,
                                                selected,
                                                CC_CALLBACK_1(MainMenu::goToStartScene, this));
  Point pos = Point(SCREEN_SIZE.width/4, SCREEN_SIZE.height/4);
  item->setPosition(pos);
  item->setScale(0.5f);

  Menu* menu = Menu::create(item, NULL);
  menu->setPosition(Point::ZERO);
  
  addChild(menu, 1);
  
  return true;
}

void MainMenu::goToStartScene(Ref* pSender)
{
  
}