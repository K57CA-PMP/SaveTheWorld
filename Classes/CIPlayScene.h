//
//  CIPlayScene.h
//  SaveTheWorld
//
//  Created by Tuan TQ on 5/9/14.
//
//

#ifndef __SaveTheWorld__CIPlayScene__
#define __SaveTheWorld__CIPlayScene__

#include <iostream>
#include "cocos2d.h"
#include "CIGameManager.h"
#include "HelloWorldScene.h"
#include "MapScene.h"
#include "CIQuestionScene.h"
USING_NS_CC;

class CIPlayScene : cocos2d::Layer
{
private:
  Size _visibleSize;
  Point _origin;
  
  Sprite* _background;
  Sprite* _boy;
  Sprite* _hook;
  Sprite* _gameOver;
  Menu* _win;
  Menu* _replayBtn;
  Menu* _backBtn;
  Menu* _nextBtn;
  
  RepeatForever* _rotateAction;
  Spawn* _launchAction;
  Spawn* _retrieveAction;
  
  Spawn* _itemRetrieveAction;
  
  int _state;
  bool _isHookRotating;
  bool _ItemCollected;
  int _nItems;
  
  CCArray* _itemsArray;
  CCArray* _hooktail;
  int _indexOfCollectedItem;
  Sprite* _currentItem;
  
  int _score;
  CCLabelTTF* _scoreLbl;
  CCLabelTTF* _timeLbl;
  int _timeLimit;
  
public:
  static cocos2d::Scene* createScene();
  virtual bool init();
  CREATE_FUNC(CIPlayScene);
  
  void addBackground();
  void addBoy();
  void addItems();
  void addHooks();
  void addLbls();
  void addGameOver();
  void addReplayButton();
  void addWin();
  void addBackBtn();
  void replayBtnTouched(Ref* pSender);
  void winTouched(Ref* pSender);
  void backBtnTouched(Ref* pSender);
  void addNextBtn();
  void nextBtnTouched(Ref* pSender);
  
  
  void hookRotateAnimation();
  void hookLaunchAnimation();
  void hookRetrieveAnimation();
  void itemRetrieveAnimation();
  void drawHookTail();
  void removeHookTail();
  
  void checkCollision();
  
  void handleTouch();
  
  void update(float pDT);
  void countdown(float pDT);
  void release();
};

#endif /* defined(__SaveTheWorld__CIPlayScene__) */
