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
#define HOOK_POSTITION Point(_visibleSize.width/2 - 20, _visibleSize.height - 30)
#define LIMITED_ANGLE 80
#define ROTATION_DELAY 1
#define LAUNCHING_DELAY 1
#define RETRIEVING_DELAY 0.7
#define PI 3.14159265

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
  
  Sprite* food;
  
public:
  static cocos2d::Scene* createScene();
  virtual bool init();
  CREATE_FUNC(CIPlayScene);
  
  void addBackground();
  void addBoy();
  void addItems();
  void addHooks();
  
  void hookRotateAnimation();
  void hookLaunchAnimation();
  void hookRetrieveAnimation();
  void itemRetrieveAnimation();
  
  void checkCollision();
  
  void handleTouch();
  
  void update(float pDT);
};

#endif /* defined(__SaveTheWorld__CIPlayScene__) */
