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



USING_NS_CC;
USING_NS_CC_EXT;



bool Stage1Scene::init()
{
	if (!Scene::init())
	{
		return false;
	}
	questionIndex = UserDefault::getInstance()->getIntegerForKey("CurrentCityNo");
	loadImageAnswer();
	
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
	submitItem->setPosition(Point(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 6));
	auto menu = Menu::create(submitItem, NULL);
	menu->setPosition(Point::ZERO);
	mStage1Layer->addChild(menu,1);
	//

	//set Edit Box

	auto answerBoxSize = Size(visibleSize.width / 3, visibleSize.height / 10);
	mAnswerBox = EditBox::create(answerBoxSize,Scale9Sprite::create());
	mAnswerBox->setPosition(Point(visibleSize.width/2,visibleSize.height/3));
	mAnswerBox->setPlaceHolder("Please enter the answer");
	mAnswerBox->setText("tienhoangna");
	mAnswerBox->setFontSize(14);
	mAnswerBox->setFontColor(cocos2d::Color3B::MAGENTA);
	
	mStage1Layer->addChild(mAnswerBox,2);

	//set First Image

	
	
	return true;
}

void Stage1Scene::menuSubmitCallback(Ref* pSender)
{
	currentAnswer = mAnswerBox->getText();
	CCLOG("%s",currentAnswer.c_str());
	
	if (currentAnswer != answer[questionIndex] ) {
		
		pictureIndex++;
		if (pictureIndex >= 5) {
			CCLOG("fuck");
			Director::getInstance()->replaceScene(MapScene::create());
		}
	}
	else {
		UserDefault::getInstance()->setIntegerForKey("CurrentCityNo",questionIndex+1);
		UserDefault::getInstance()->setStringForKey("CurrentCityName", __String::createWithFormat("city0%d", questionIndex + 1)->getCString());
		Director::getInstance()->replaceScene(MapScene::create());
	}
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();
	auto cluePicture = Sprite::create(__String::createWithFormat("%s%d.jpg", cluePictures[questionIndex].c_str(), pictureIndex)->getCString());
	cluePicture->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y+visibleSize.height/5));
	cluePicture->setScaleX(visibleSize.width / 2 / cluePicture->getContentSize().width);
	cluePicture->setScaleY(visibleSize.height / 2 / cluePicture->getContentSize().height);
	// add the sprite as a child to this layer
	mStage1Layer->addChild(cluePicture);
	currentAnswer = "sai";
}

void Stage1Scene::showpicture(){
	
}

void Stage1Scene::loadImageAnswer(){
	cluePictures[1] = "stage1/flood";
	cluePictures[2] = "stage1/chay";
	cluePictures[3] = "stage1/drought";
	cluePictures[4] = "stage1/earthquake";
	cluePictures[5] = "stage1/storm";
	cluePictures[6] = "stage1/tsunami";
	
	answer[1] = "flood";
	answer[2] = "wildfire";
	answer[3] = "drought";
	answer[4] = "earthquake";
	answer[5] = "storm";
	answer[6] = "tsunami";

}

