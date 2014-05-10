//
//  MapScene.cpp
//  SaveTheWorld
//
//  Created by Giap Nguyen on 5/8/14.
//
//

#include "MapScene.h"

USING_NS_CC;



MapScene* MapScene::create()
{
	CCLOG("+++++++++++=");
  MapScene *pRet = new MapScene();
  if (pRet && pRet->init())
  {
    pRet->autorelease();
    return pRet;
  }
  else
  {
    CC_SAFE_DELETE(pRet);
    return NULL;
  }
}

bool MapScene::init()
{
  if (!Scene::init())
  {
    return false;
  }
  
  SpriteFrameCache::getInstance()->addSpriteFramesWithFile("city_selectors.plist");

  SpriteFrameCache::getInstance()->addSpriteFramesWithFile("map_ui.plist");
  
  mMapLayer = MapLayer::create(UserDefault::getInstance()->getStringForKey("CurrentCityName").c_str()); //GameManager::getCurrentCityName());
  CCLOG("MapScene: %s %d", UserDefault::getInstance()->getStringForKey("CurrentCityName").c_str(), UserDefault::getInstance()->getIntegerForKey("CurrentCityNo"));
  addChild(mMapLayer);
  
  
  Sprite* normal = Sprite::createWithSpriteFrameName("map_button_battle.png");
  Sprite* selected = Sprite::createWithSpriteFrameName("map_button_battle.png");
  MenuItemSprite* item = MenuItemSprite::create(normal,
                                                selected,
                                                CC_CALLBACK_1(MapScene::play, this));
  Point pos = Point(SCREEN_SIZE.width - (normal->getContentSize().width/2)- 1.0*1 - 10,
                  (normal->getContentSize().height/2) + 1.0*1 + 10);

  item->setPosition(pos);
  Menu* menu = Menu::create(item, NULL);
  menu->setPosition(Point::ZERO);
  addChild(menu, 1);
//  menu->setAnchorPoint(Point::ANCHOR_BOTTOM_RIGHT);
//  menu->runAction(CCRepeatForever::create(CCRotateBy::create(0.8, 360)));
  return true;
}

void MapScene::play(Ref* pSender)
{
  CCLOG("play!!!!. cur: %s", UserDefault::getInstance()->getStringForKey("CurrentCityName").c_str());
  Director::getInstance()->replaceScene(TransitionFade::create(0.5f, HelloWorld::createScene(), Color3B::BLACK));
}
