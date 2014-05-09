
//  City.cpp
//  SaveTheWorld
//
//  Created by Giap Nguyen on 5/9/14.
//
//

#include "City.h"
#include "MapLayer.h"

USING_NS_CC;

//City* City::create(const char *pName, MapLayer *pMapLayer, eCityStatus pCityStatus)
//{
//  City *pobSprite = new City();
//  
//  if (pobSprite && pobSprite->init(pName,
//                                   pMapLayer,
//                                   pCityStatus))
//  {
//    pobSprite->autorelease();
//    return pobSprite;
//  }
//  CC_SAFE_DELETE(pobSprite);
//  return NULL;
//}


//bool City::init(const char *pName, MapLayer *pMapLayer, eCityStatus pCityStatus)
//{
//  if (!Sprite::init())
//  {
//    return false;
//  }
//  mMapLayer = pMapLayer;
//  mInnerCircle = CCSprite::createWithSpriteFrameName("city_selector_inner.png");
//  mOuterCircle = CCSprite::createWithSpriteFrameName("city_selector_outer.png");
//  this->addChild(mInnerCircle);
//  this->addChild(mOuterCircle);
//  mInnerCircle->setRotation(rand()%360);
//  mOuterCircle->setRotation(rand()%360);
//  mInnerCircle->runAction(CCRepeatForever::create(CCRotateBy::create(8, -360)));
//  mOuterCircle->runAction(CCRepeatForever::create(CCRotateBy::create(8, 360)));
//  mName = pName;
//  
//  // Adjustments so CCLayer positioning behaves like a sprite
//  this->setContentSize(mOuterCircle->boundingBox().size);
//  
//  return true;
//}
