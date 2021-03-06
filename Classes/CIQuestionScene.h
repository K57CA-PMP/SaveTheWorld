//
//  CIQuestionScene.h
//  SaveTheWorld
//
//  Created by Tuan TQ on 5/11/14.
//
//

#ifndef __SaveTheWorld__CIQuestionScene__
#define __SaveTheWorld__CIQuestionScene__

#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"
#include "Constant.h"
#include "CIGameManager.h"
#include "HelloWorldScene.h"
#include "MapScene.h"
USING_NS_CC;
USING_NS_CC_EXT;

class CIQuestionScene : cocos2d::Layer
{
private:
  Size _visibleSize;
  Point _visibleOrigin;

  Sprite* _background;
  EditBox* _question;
  
  MenuItemImage* _menu1;
  MenuItemImage* _menu2;
  MenuItemImage* _menu3;
  
  Menu* _answer1;
  Menu* _answer2;
  Menu* _answer3;
  Menu* _win;
  Menu* _replayBtn;
  Menu* _backBtn;
  Sprite* _gameOver;
  
  int _answerTouchedID;

public:
  static cocos2d::Scene* createScene();
  virtual bool init();
  CREATE_FUNC(CIQuestionScene);
  
  void addBackground();
  void addQuestion();
  void addAnswers();
  void answer1Touched(Ref* pSender);
  void answer2Touched(Ref* pSender);
  void answer3Touched(Ref* pSender);
  void checkAnswer();
  void addWin();
  void winTouched(Ref* pSender);
  void addGameOver();
  void addReplayBtn();
  void replayBtnTouched(Ref* pSender);
  void addBackBtn();
  void backBtnTouched(Ref* pSender);
  void injectAnswers();
};

#endif /* defined(__SaveTheWorld__CIQuestionScene__) */
