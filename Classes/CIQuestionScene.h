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
USING_NS_CC;
USING_NS_CC_EXT;

class CIQuestionScene : cocos2d::Layer
{
private:
  Size _visibleSize;
  Point _visibleOrigin;

  Sprite* _background;
  EditBox* _question;
  
public:
  static cocos2d::Scene* createScene();
  virtual bool init();
  CREATE_FUNC(CIQuestionScene);
  
  void addBackground();
  void addQuestion();
  void addAnswers();
};

#endif /* defined(__SaveTheWorld__CIQuestionScene__) */
