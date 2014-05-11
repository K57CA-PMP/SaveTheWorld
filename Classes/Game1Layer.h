//
//  Game1Layer.h
//  SaveTheWorld
//
//  Created by PeterNguyen 10th May 2014
//
//

#ifndef __SaveTheWorld__Game1Layer__
#define __SaveTheWorld__Game1Layer__

#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

class Game1Layer : public cocos2d::LayerColor
{
private:
	MenuItemImage* startButton;
	CCLabelTTF* guideBox;
	Menu* menu;
	EditBox *answerBox;

	
	
	void loadImageAnswer();
	std::string cluePictures[8];
	std::string answer[8];
	Point cluePoint, answerPoint, submitPoint, nextPoint, guidePoint,resultPoint;
	
	CCLabelTTF* ingameGuide;
	CCLabelTTF* inform;

public:
	virtual bool init();
	CREATE_FUNC(Game1Layer);
	void questionUI(Node *node);
	void menuStartCallback(Ref* pSender);
	void openQuestion();
	void menuSubmitCallback(Ref* pSender);
	void menuNextCallback(Ref* pSender);
	void menuLoseCallback(Ref* pSender);
	void menuWinCallback(Ref* pSender);
	int questionIndex=0, pictureIndex=0;
	void loseInform();
	void successInform();

};



#endif /* defined(__SaveTheWorld__Game1Layer__) */
