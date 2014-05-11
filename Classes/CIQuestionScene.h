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
USING_NS_CC;

class CIQuestionScene : cocos2d::Layer
{
private:
  Size _visibleSize;
  Point _visibleOrigin;

  Sprite* _background;
  
public:
  static cocos2d::Scene* createScene();
  virtual bool init();
  CREATE_FUNC(CIQuestionScene);
  
  void addBackground();
  void addQuestion();
  void addAnswers();
};

#endif /* defined(__SaveTheWorld__CIQuestionScene__) */
