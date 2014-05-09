//
//  MapLayer.h
//  SaveTheWorld
//
//  Created by Giap Nguyen on 5/8/14.
//
//

#ifndef __SaveTheWorld__MapLayer__
#define __SaveTheWorld__MapLayer__

#include "cocos2d.h"
#include "Constant.h"
#include "City.h"
#include "GameManager.h"

class MapLayer : public cocos2d::Layer
{
private:
  cocos2d::Point mBeginLocation;
  cocos2d::Sprite* map;
  cocos2d::SpriteBatchNode* mCitiesBatchNode;
  cocos2d::__Array* mCitiesArray;
//  City* mCurrentCity;
  
public:
  virtual bool init(const char* pCurrentCityName);
  static MapLayer* create(const char* pCurrentCityName);
  
  virtual bool onTouchBegan(cocos2d::Touch* pTouch, cocos2d::Event* pEvent);
  virtual void onTouchMoved(cocos2d::Touch* pTouch, cocos2d::Event* pEvent);
  
  void moveMap(float pDeltaX, float pDeltaY);
  cocos2d::Point getBound();
  
  void addCities(const char* pCurrentCity);
};



#endif /* defined(__SaveTheWorld__MapLayer__) */
