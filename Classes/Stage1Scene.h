//
//  Stage1Scene.h
//  SaveTheWorld
//
//  Created by Peter Nguyen 09/04/2014
//

#ifndef __SaveTheWorld__Stage1Scene__
#define __SaveTheWorld__Stage1Scene__

#include "cocos2d.h"
#include "Stage1Layer.h"
#include "cocos-ext.h"

USING_NS_CC_EXT;

class Stage1Scene : public cocos2d::Scene
{
public:
	virtual bool init();
	CREATE_FUNC(Stage1Scene);
	void menuSubmitCallback(cocos2d::Ref* pSender);
private:
	std::string cluePictures[8];
	std::string answer[8];
	int questionIndex = 1;
	int pictureIndex = 0;
	Stage1Layer * mStage1Layer;
	void showpicture();
	std::string currentAnswer="wrong";
	EditBox* mAnswerBox;
	void loadImageAnswer();
};

#endif /* defined(__SaveTheWorld__MapScene__) */
