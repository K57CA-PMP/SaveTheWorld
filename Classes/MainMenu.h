//
//  MainMenu.h
//  SaveTheWorld
//
//  Created by Giap Nguyen on 5/10/14.
//
//

#ifndef __SaveTheWorld__MainMenu__
#define __SaveTheWorld__MainMenu__


#include "cocos2d.h"
#include "Constant.h"
#include "MapScene.h"

class MainMenu : public cocos2d::Layer
{
private:
  
public:
  static cocos2d::Scene* createScene();
  
  virtual bool init();
  
  CREATE_FUNC(MainMenu);
  
  void goToStartScene(cocos2d::Ref* pSender);
  
};
#endif /* defined(__SaveTheWorld__MainMenu__) */
