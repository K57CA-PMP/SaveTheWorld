//
//  MapLayer.cpp
//  SaveTheWorld
//
//  Created by Peter Nguyen on 8 May 2014
//
//

#include "Stage1Layer.h"

USING_NS_CC;

bool Stage1Layer::init()
{
	if (!LayerColor::initWithColor(cocos2d::Color4B::GRAY))
	{
		return false;
	}

	
	return true;
}



