//
//  Game1Scene.h
//  SaveTheWorld
//
//  Created by Peter Nguyen 10/04/2014
//

#ifndef __SaveTheWorld__Game1Scene__
#define __SaveTheWorld__Game1Scene__

#include "cocos2d.h"
#include "Game1Layer.h"
#include "cocos-ext.h"

USING_NS_CC_EXT;

class Game1Scene : public cocos2d::Scene
{
public:
	virtual bool init();
	CREATE_FUNC(Game1Scene);
	
private:
	Game1Layer* mGame1Layer;
	
};

#endif /* defined(__SaveTheWorld__Game1Scene__) */
