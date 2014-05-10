//
//  SavingBoy.h
//  SaveTheWorld
//
//  Created by Giap Nguyen on 5/10/14.
//
//

#ifndef __SaveTheWorld__SavingBoy__
#define __SaveTheWorld__SavingBoy__

#include "cocos2d.h"
#include "Constant.h"
#include "CCLabelBMFontAnimated.h"

class SavingBoy : public cocos2d::Layer
{
public:
  static cocos2d::Scene* createScene();
  
  virtual bool init();
  
  CREATE_FUNC(SavingBoy);
  
  void animateIntro();
  void callbackRemoveWhenDidAction(cocos2d::Node * node);
  void warning(cocos2d::Node* node);
  void appearVictim(cocos2d::Node* node);
  void scaleVictim(cocos2d::Node* node);
  
  void toolTouched(cocos2d::Ref* pSender);
  void swim(cocos2d::Ref *pSender);
};


#endif /* defined(__SaveTheWorld__SavingBoy__) */
