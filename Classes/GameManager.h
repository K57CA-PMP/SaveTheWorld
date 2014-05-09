//
//  GameManager.h
//  SaveTheWorld
//
//  Created by Giap Nguyen on 5/9/14.
//
//

#ifndef __SaveTheWorld__GameManager__
#define __SaveTheWorld__GameManager__

#include "cocos2d.h"
#include "Constant.h"

class GameManager
{
private:
  static const char* mCurrentCityName;
public:
  static void setCurrentCityName(const char* pCurrentCityName);
  static const char* getCurrentCityName();
};

#endif /* defined(__SaveTheWorld__GameManager__) */
