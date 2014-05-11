//
//  CIGameManager.cpp
//  SaveTheWorld
//
//  Created by Tuan TQ on 5/10/14.
//
//

#include "CIGameManager.h"

int CIGameManager::_gameLevel = 1;
int CIGameManager::getGameLevel()
{
  return _gameLevel;
}
void CIGameManager::setGameLevel(int pLevel)
{
  _gameLevel = pLevel;
}

int CIGameManager::_dialogState = 1;
int CIGameManager::getDialogState()
{
  return _dialogState;
}
void CIGameManager::setDialogState(int pState)
{
  _dialogState = pState;
}

int CIGameManager::_questionIndex = 1;
int CIGameManager::getQuestionIndex()
{
  return _questionIndex;
}
void CIGameManager::setQuestionIndex(int pIndex)
{
  _questionIndex = pIndex;
}

int CIGameManager::_answersArray[6];
int CIGameManager::getAnswer(int pIndex)
{
  return _answersArray[pIndex];
}
void CIGameManager::setAnswer(int pIndex, int pAnswer)
{
  _answersArray[pIndex] = pAnswer;
}
