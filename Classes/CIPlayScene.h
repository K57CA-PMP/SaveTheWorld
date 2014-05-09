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
  
public:
  static cocos2d::Scene* createScene();
  virtual bool init();
  CREATE_FUNC(CIPlayScene);
  
  void addBackground();
  
  void update(float pDT);
};

#endif /* defined(__SaveTheWorld__CIPlayScene__) */
