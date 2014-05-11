//
//  Stage1Scene.cpp
//  SaveTheWorld
//
//  Created by Peter 09/05/2014
//
//

#include "Game1Scene.h"
#include "Constant.h"
#include "MapScene.h"



USING_NS_CC;
USING_NS_CC_EXT;



bool Game1Scene::init()
{
	if (!Scene::init())
	{
		return false;
	}
	
	mGame1Layer = Game1Layer::create();
	addChild(mGame1Layer);

	return true;
}



