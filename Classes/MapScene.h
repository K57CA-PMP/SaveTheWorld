//
//  MapScene.h
//  SaveTheWorld
//
//  Created by Giap Nguyen on 5/8/14.
//
//

#ifndef __SaveTheWorld__MapScene__
#define __SaveTheWorld__MapScene__

#include "cocos2d.h"
#include "MapLayer.h"

class MapScene : public cocos2d::Scene
{
private:
  MapLayer* mMapLayer;
  cocos2d::Menu* mPlayButton;

public:
  virtual bool init();  
  static MapScene* create();
  void play(cocos2d::Ref* pSender);
};

#endif /* defined(__SaveTheWorld__MapScene__) */
