//
//  City.cpp
//  SaveTheWorld
//
//  Created by Giap Nguyen on 5/9/14.
//
//

#include "City.h"

USING_NS_CC;

City* City::create(const char *pName, eCityStatus pCityStatus)
{
  City *pobSprite = new City();
  
  if (pobSprite && pobSprite->init(pName,
                                   pCityStatus))
  {
    pobSprite->autorelease();
    return pobSprite;
  }
  CC_SAFE_DELETE(pobSprite);
  return NULL;
}


bool City::init(const char *pName, eCityStatus pCityStatus)
{
  if (!Sprite::init())
  {
    return false;
  }

  mInnerCircle = Sprite::createWithSpriteFrameName("city_selector_inner.png");
  mOuterCircle = Sprite::createWithSpriteFrameName("city_selector_outer.png");
  this->addChild(mInnerCircle);
  this->addChild(mOuterCircle);
  this->setContentSize(mOuterCircle->boundingBox().size);
  
  mCleared = Sprite::createWithSpriteFrameName("city_cleared.png");
  mCleared->setVisible(false);

  mArrow = Sprite::createWithSpriteFrameName("city_selector_arrow.png");
  mArrow->setVisible(true);
  
  //Positions
  mInnerCircle->setPosition(Point(mOuterCircle->boundingBox().size.width/2,
                                mOuterCircle->boundingBox().size.height/2));
  mOuterCircle->setPosition(Point(mOuterCircle->boundingBox().size.width/2,
                                mOuterCircle->boundingBox().size.height/2));
  mArrowCircle = NULL;
  
  if (mArrowCircle)
  {
    mArrowCircle->setPosition(Point(mOuterCircle->boundingBox().size.width/2,
                                  mOuterCircle->boundingBox().size.height/2));
    mArrowCircle->setRotation(rand()%360);
    mArrowCircle->runAction(CCRepeatForever::create(CCRotateBy::create(16, -360)));
    this->addChild(mArrowCircle);
  }
  
  // clearedPosition point needs to be calculated
  // before starting rotation of the circles,
  // because the center changes with rotation
  mClearedPosition = Point(mOuterCircle->boundingBox().size.width/2 + 0*1,
                         mOuterCircle->boundingBox().size.height/2 + 2*1);
  mCleared->setPosition(mClearedPosition);
  
  mArrow->setPosition(Point(mOuterCircle->boundingBox().size.width/2 + 0*1,
                          mOuterCircle->boundingBox().size.height/2 + 32*1));
  mInnerCircle->setRotation(rand()%360);
  mOuterCircle->setRotation(rand()%360);
  
  mArrow->runAction(
    CCRepeatForever::create(
      CCSequence::create(
         CCEaseInOut::create(CCMoveBy::create(0.6, Point(0, -5*1)), 2.0),
         CCEaseInOut::create(CCMoveBy::create(0.6, Point(0, 5*1)), 2.0),
         NULL)));
  mInnerCircle->runAction(CCRepeatForever::create(CCRotateBy::create(8, -360)));
  mOuterCircle->runAction(CCRepeatForever::create(CCRotateBy::create(8, 360)));
  this->addChild(mCleared);
  this->addChild(mArrow);
  
  mName = pName;
  mStatus = pCityStatus;
  
  return true;
}

