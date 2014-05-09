//
//  MapLayer.cpp
//  SaveTheWorld
//
//  Created by Giap Nguyen on 5/8/14.
//
//

#include "MapLayer.h"

USING_NS_CC;

bool MapLayer::init()
{
  if (!Layer::init())
  {
    return false;
  }
  
  map = Sprite::create("map.jpg");
  map->setPosition(Point::ZERO);
  map->setAnchorPoint(Point::ANCHOR_BOTTOM_LEFT);
  addChild(map);
  
  auto touchListener = EventListenerTouchOneByOne::create();
  touchListener->onTouchBegan = CC_CALLBACK_2(MapLayer::onTouchBegan, this);
  touchListener->onTouchMoved = CC_CALLBACK_2(MapLayer::onTouchMoved, this);
  _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
  

  return true;
}

bool MapLayer::onTouchBegan(cocos2d::Touch *pTouch, cocos2d::Event *pEvent)
{
  mBeginLocation = pTouch->getLocation();
//  mBeginLocation = convertToNodeSpace(mBeginLocation);
  return true;
}

void MapLayer::onTouchMoved(cocos2d::Touch *pTouch, cocos2d::Event *pEvent)
{
  Point touchLocation = pTouch->getLocation();
//  touchLocation = convertToNodeSpace(touchLocation);
  
  float offsetX = touchLocation.x - mBeginLocation.x;
  float offsetY = touchLocation.y - mBeginLocation.y;
  
  moveMap(offsetX, offsetY);
  
  mBeginLocation = touchLocation;
  return;
}
  
void MapLayer::moveMap(float pDeltaX, float pDeltaY)
{
  float posX = getPosition().x + pDeltaX;
  float posY = getPosition().y + pDeltaY;
  
  if (posX > 0)
    posX = 0;
  if (posX < getBound().x)
    posX = getBound().x;
  if (posY > 0)
    posY = 0;
  if (posY < getBound().y)
  {
    posY = getBound().y;
  }

  setPosition(posX, posY);
}

cocos2d::Point MapLayer::getBound()
{
  float mapWidth = map->getContentSize().width;
  float mapHeight = map->getContentSize().height;
  
  return Point(SCREEN_SIZE.width - mapWidth, SCREEN_SIZE.height - mapHeight);
}
