//
//  CIStartScene.h
//  SaveTheWorld
//
//  Created by Tuan TQ on 5/10/14.
//
//

#ifndef __SaveTheWorld__CIStartScene__
#define __SaveTheWorld__CIStartScene__

#include <iostream>
#include "Constant.h"
#include "cocos2d.h"
#include "cocos-ext.h"
#include "CIGameManager.h"
#include "CIPlayScene.h"
USING_NS_CC;
USING_NS_CC_EXT;

class CIStartScene : cocos2d::Layer
{
private:
  Sprite* _background;
  Size _visibleSize;
  Point _visibleOrigin;
  
  EditBox* _dialog;
  char _buffer[100];
  Menu* _nextBtn;
  Menu* _backBtn;
  Menu* _startBtn;
  
public:
  static cocos2d::Scene* createScene();
  virtual bool init();
  CREATE_FUNC(CIStartScene);
  
  void addBackground();
  void addDialogs();
  void addNextBtn();
  void nextBtnTouched(Ref* pSender);
  void addBackBtn();
  void backBtnTouched(Ref* pSender);
  void addStartBtn();
  void startBtnTouched(Ref* pSender);
};

#endif /* defined(__SaveTheWorld__CIStartScene__) */
