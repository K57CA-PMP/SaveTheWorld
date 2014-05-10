//
//  CIGameManager.h
//  SaveTheWorld
//
//  Created by Tuan TQ on 5/10/14.
//
//

#ifndef __SaveTheWorld__CIGameManager__
#define __SaveTheWorld__CIGameManager__

#include <iostream>
#include "cocos2d.h"
USING_NS_CC;

class CIGameManager
{
private:
  static int _gameLevel;
public:
  static int getGameLevel();
  static void setGameLevel(int pLevel);
};

#endif /* defined(__SaveTheWorld__CIGameManager__) */
