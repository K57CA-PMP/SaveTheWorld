//
//  City.h
//  SaveTheWorld
//
//  Created by Giap Nguyen on 5/9/14.
//
//

#ifndef __SaveTheWorld__City__
#define __SaveTheWorld__City__

#include "cocos2d.h"
#include "Constant.h"
#include "MapLayer.h"

typedef enum eCityStatusEnum
{
  CITY_STATUS_LOCKED = 0,
  CITY_STATUS_UNLOCKED = 4,
  CITY_STATUS_CLEARED = 10,
} eCityStatus;

class City: public cocos2d::Sprite
{
private:
  MapLayer* mMapLayer;
  cocos2d::Sprite *mInnerCircle, *mOuterCircle, *mArrowCircle;
  cocos2d::Sprite *mCleared, *mArrow;
  CC_SYNTHESIZE_READONLY(const char*, mName, Name);
  eCityStatus mStatus;
  
public:
  virtual bool init(const char* pNqame, MapLayer* pMapLayer, eCityStatus pCityStatus);
  static City* create(const char* pName, MapLayer* pMapLayer, eCityStatus pCityStatus);
};

#endif /* defined(__SaveTheWorld__City__) */
