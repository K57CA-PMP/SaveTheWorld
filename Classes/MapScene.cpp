//
//  MapScene.cpp
//  SaveTheWorld
//
//  Created by Giap Nguyen on 5/8/14.
//
//

#include "MapScene.h"

USING_NS_CC;



MapScene* MapScene::create()
{
	CCLOG("+++++++++++=");
  MapScene *pRet = new MapScene();
  if (pRet && pRet->init())
  {
    pRet->autorelease();
    return pRet;
  }
  else
  {
    CC_SAFE_DELETE(pRet);
    return NULL;
  }
}

bool MapScene::init()
{
  if (!Scene::init())
  {
    return false;
  }
  
  SpriteFrameCache::getInstance()->addSpriteFramesWithFile("city_selectors.plist");
  mMapLayer = MapLayer::create();
  addChild(mMapLayer);
  
  return true;
}
