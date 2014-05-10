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

#define ROTATE 0
#define LAUNCH 1
#define RETRIEVE 2
#define ITEM_COLLECTED 3
#define HOOK_POSITION Point(_visibleSize.width/2 - 20, _visibleSize.height - 30)
#define ITEM_DST_POS Point(_visibleSize.width/2 - 20, _visibleSize.height - 100)
#define LIMITED_ANGLE 80
#define ROTATION_DELAY 1
#define LAUNCHING_DELAY 1
#define RETRIEVING_DELAY 1
#define PI 3.14159265

#define NUM_OF_ITEMS 7
#define ITEM1_POS Point(150, 250)
#define ITEM2_POS Point(85, 140)
#define ITEM3_POS Point(220, 80)
#define ITEM4_POS Point(360, 180)
#define ITEM5_POS Point(540, 60)
#define ITEM6_POS Point(640, 220)
#define ITEM7_POS Point(740, 80)

#define SCORE_LBL_POS Point(150, 400)
#define TIME_LBL_POS Point(50, 400)

class CIPlayScene : cocos2d::Layer
{
private:
  Size _visibleSize;
  Point _origin;
  
  Sprite* _background;
  Sprite* _boy;
  Sprite* _hook;
  
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
  
  void hookRotateAnimation();
  void hookLaunchAnimation();
  void hookRetrieveAnimation();
  void itemRetrieveAnimation();
  void drawHookTail();
  void removeHookTail();
  
  void checkCollision();
  
  void handleTouch();
  
  void update(float pDT);
};

#endif /* defined(__SaveTheWorld__CIPlayScene__) */
