//
//  GameManager.cpp
//  SaveTheWorld
//
//  Created by Giap Nguyen on 5/9/14.
//
//

#include "GameManager.h"

const char* GameManager::mCurrentCityName = NULL;

void GameManager::setCurrentCityName(const char* pCurrentCityName)
{
  mCurrentCityName = pCurrentCityName;
}

const char* GameManager::getCurrentCityName()
{
  return mCurrentCityName;
}