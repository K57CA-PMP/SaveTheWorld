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
  
  RepeatForever* _rotateAction;
  Spawn* _launchAction;
  Spawn* _retrieveAction;
  
  Spawn* _itemRetrieveAction;
  
  int _state;
  bool _isHookRotating;
  bool _ItemCollected;
  
  CCArray* _itemsArray;
  CCArray* _hooktail;
  int _indexOfCollectedItem;
  
  int _score;
  CCLabelTTF* _scoreLbl;
  CCLabelTTF* _timeLbl;
  char _scoreBuffer[2];
  char _timeBuffer[5];
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
};

#endif /* defined(__SaveTheWorld__CIPlayScene__) */
