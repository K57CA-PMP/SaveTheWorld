//
//  CIGameManager.cpp
//  SaveTheWorld
//
//  Created by Tuan TQ on 5/10/14.
//
//

#include "CIGameManager.h"

int CIGameManager::_gameLevel = 5;
int CIGameManager::getGameLevel()
{
  return _gameLevel;
}
void CIGameManager::setGameLevel(int pLevel)
{
  _gameLevel = pLevel;
}