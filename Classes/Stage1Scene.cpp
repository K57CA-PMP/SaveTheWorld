//
//  Stage1Scene.cpp
//  SaveTheWorld
//
//  Created by Peter 09/05/2014
//
//

#include "Stage1Scene.h"
#include "Constant.h"
#include "MapScene.h"
//#include "cocos-ext.h"


USING_NS_CC;
//USING_NS_CC_EXT;



bool Stage1Scene::init()
{
	if (!Scene::init())
	{
		return false;
	}
	cluePictures[1] = "stage1/flood";
	answer[1] = "flood";
	
	mStage1Layer = Stage1Layer::create();
	addChild(mStage1Layer);

	//Adding The Submit Button
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();
	auto submitItem = MenuItemImage::create(
		"submit1.png",
		"submit2.png",
		CC_CALLBACK_1(Stage1Scene::menuSubmitCallback, this));

	//set button
	submitItem->setPosition(Point(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 5));
	auto menu = Menu::create(submitItem, NULL);
	menu->setPosition(Point::ZERO);
	mStage1Layer->addChild(menu,1);
	//

	//set Edit Box

	//auto answerBoxSize = Size(visibleSize.width / 3, visibleSize.height / 10);
	//auto mAnswerBox = EditBox::create();
	//

	//set First Image

	
	
	return true;
}

void Stage1Scene::menuSubmitCallback(Ref* pSender)
{
	
	std::string res = "sai";
	if (res != answer[questionIndex] || (questionIndex == 1 && pictureIndex == 0)) {
		pictureIndex++;
		if (pictureIndex >= 5) {
			//Game over 
			//auto mapScene = MapScene::create();
			//Director::getInstance()->replaceScene(mapScene);
			auto mapScene2 = MapScene::create();
			Director::getInstance()->replaceScene(mapScene2);
			CCLOG("----------------");
		}
	}
	else {
		questionIndex++;
		pictureIndex = 1;
		if (questionIndex == 6) {
			auto scene = MapScene::create();
			auto director = Director::getInstance();
			director->replaceScene(scene);
		}
	}
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();
	auto cluePicture = Sprite::create(__String::createWithFormat("%s%d.jpg", cluePictures[questionIndex].c_str(), pictureIndex)->getCString());
	cluePicture->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	cluePicture->setScaleX(visibleSize.width / 2 / cluePicture->getContentSize().width);
	cluePicture->setScaleY(visibleSize.height / 2 / cluePicture->getContentSize().height);
	// add the sprite as a child to this layer
	mStage1Layer->addChild(cluePicture);
}

void Stage1Scene::showpicture(){
	
}


