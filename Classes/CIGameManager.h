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
  static int _dialogState;
  
  static int _questionIndex;
  static int _answersArray[6];
public:
  static int getGameLevel();
  static void setGameLevel(int pLevel);
  
  static int getDialogState();
  static void setDialogState(int pState);
  
  static int getQuestionIndex();
  static void setQuestionIndex(int pIndex);
  
  static int getAnswer(int pIndex);
  static void setAnswer(int pIndex, int pAnswer);
};

#endif /* defined(__SaveTheWorld__CIGameManager__) */
