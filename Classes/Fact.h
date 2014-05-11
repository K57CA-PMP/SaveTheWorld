//
//  Game1Scene.h
//  SaveTheWorld
//
//  Created by Peter Nguyen 10/04/2014
//

#ifndef __SaveTheWorld__Fact__
#define __SaveTheWorld__Fact__

#include "cocos2d.h"
#include "vietnamese.h"

USING_NS_CC;

class Fact : public cocos2d::Scene
{
public:
	virtual bool init();
	CREATE_FUNC(Fact);
	void menuSkipCallback(Ref* pSender);
	Sprite* bg;
	void chooseBackground();
private:
	int questionNo;
	CCLabelTTF* information;
	

};

#endif /* defined(__SaveTheWorld__Fact__) */