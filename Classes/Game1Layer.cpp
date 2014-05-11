//
//  Game1Layer.cpp
//  SaveTheWorld
//
//  Created by Peter Nguyen on 10 May 2014
//
//

#include "Game1Layer.h"
#include "MapScene.h"
#include "vietnamese.h"
#include "Fact.h"
#include "Constant.h"

USING_NS_CC;

bool Game1Layer::init()
{
	if (!LayerColor::initWithColor(cocos2d::Color4B::GRAY))
	{
		return false;
	}

	auto backgroundpic = Sprite::create("stage1/background2.png",
		CCRectMake(0,0,Director::getInstance()->getVisibleSize().width,Director::getInstance()->getVisibleSize().height));
	backgroundpic->setPosition(Director::getInstance()->getVisibleSize().width/2, Director::getInstance()->getVisibleSize().height/2);
	this->addChild(backgroundpic,0);
	//Starting game
	questionIndex = UserDefault::getInstance()->getIntegerForKey("CurrentCityNo");
	
	//Start button
	startButton = MenuItemImage::create(
		"stage1/start.png",
		"stage1/startselected.png",
		CC_CALLBACK_1(Game1Layer::menuStartCallback, this));	
	startButton->setPosition(Director::getInstance()->getVisibleSize().width / 2, Director::getInstance()->getVisibleSize().height / 5);
	startButton->setScale(Director::getInstance()->getVisibleSize().width/startButton->getContentSize().width/6,
		Director::getInstance()->getVisibleSize().height / startButton->getContentSize().height / 4);
	auto menu = Menu::create(startButton, NULL);
	menu->setPosition(Point::ZERO);
	this->addChild(menu, 1);
	//
	//Guide 
	
	guideBox = CCLabelTTF::create(GAMEGUIDE, "Arial", 25, 
		Size(Director::getInstance()->getVisibleSize().width /5*3, Director::getInstance()->getVisibleSize().height / 2));
	guideBox->setPosition(Point(Director::getInstance()->getVisibleSize().width / 2, Director::getInstance()->getVisibleSize().height / 5*3));
	guideBox->setHorizontalAlignment(TextHAlignment::LEFT);
	this->addChild(guideBox,1);
	auto guideBoxBackground = Sprite::create("stage1/background1.jpg", CCRectMake(0,0,guideBox->getContentSize().width,guideBox->getContentSize().height));
	guideBoxBackground->setPosition(guideBox->getContentSize().width/2, guideBox->getContentSize().height/2);
	guideBox->addChild(guideBoxBackground,-1);
	//

	return true;
}

void Game1Layer::menuStartCallback(Ref* pSender){
	((MenuItemImage*)pSender)->runAction(FadeOut::create(0.5f));
	guideBox->runAction(Sequence::create(FadeOut::create(0.5f), DelayTime::create(0.5f),
		CallFuncN::create(CC_CALLBACK_1(Game1Layer::questionUI,this)),NULL  ));
	
}

void Game1Layer::questionUI(Node* node){
	//arrangement
	loadImageAnswer();
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();
	cluePoint = Point(visibleSize.width*3/10,visibleSize.height*2/3.3);
	answerPoint = Point(visibleSize.width * 3 / 10, visibleSize.height * 2 / 10);
	submitPoint = Point(visibleSize.width * 7.7f / 10, visibleSize.height * 2 / 10);
	nextPoint = Point(visibleSize.width * 7.7f / 10, visibleSize.height * 4 / 10);
	resultPoint = Point(visibleSize.width * 7.7f / 10, visibleSize.height * 2 / 10);
	guidePoint = Point(visibleSize.width * 7.7f / 10, visibleSize.height * 7.5f / 10);

	//submit and next button
	auto submitItem = MenuItemImage::create(
		"stage1/submit1.png",
		"stage1/submit1.png",
		CC_CALLBACK_1(Game1Layer::menuSubmitCallback, this));
	submitItem->setPosition(submitPoint);
	submitItem->setScale(visibleSize.width / submitItem->getContentSize().width / 3, visibleSize.height / submitItem->getContentSize().height/ 6);
	auto nextItem = MenuItemImage::create(
		"stage1/nextclue.png",
		"stage1/nextclue.png",
		CC_CALLBACK_1(Game1Layer::menuNextCallback, this));
	nextItem->setPosition(nextPoint);
	nextItem->setScale(visibleSize.width / nextItem->getContentSize().width / 3, visibleSize.height / nextItem->getContentSize().height / 6);
	CCLOG("tienhoangna");
	menu = Menu::create(submitItem,nextItem, NULL);
	menu->setPosition(Point::ZERO);
	this->addChild(menu, 2);
	//
	//Add Successful Box and Guide Box
	ingameGuide = CCLabelTTF::create(GAMEGUIDE, "Arial",20,
		Size(visibleSize.width *2/5, visibleSize.height  / 5*2));
	ingameGuide->setPosition(guidePoint);
	this->addChild(ingameGuide);
	ingameGuide->setColor(Color3B::BLUE);
	ingameGuide->setHorizontalAlignment(TextHAlignment::LEFT);

	inform = CCLabelTTF::create("", "Arial", 25,
		Size(visibleSize.width  / 5 * 2, visibleSize.height  / 5 * 2));
	inform->setPosition(guidePoint);
	
	this->addChild(inform,5);
	inform->setOpacity(0);
	inform->setColor(Color3B::BLUE);
	inform->setHorizontalAlignment(TextHAlignment::LEFT);
	//
	//Add answer box to game
	auto answerBoxSize = Size(visibleSize.width *2/5 , visibleSize.height / 12);
	answerBox = EditBox::create(answerBoxSize, Scale9Sprite::create("stage1/tb.png"));
	answerBox->setPosition(answerPoint);
	answerBox->setPlaceHolder("Please enter the answer");
	answerBox->setFont("Arial", 37);
	answerBox->setText("answer here!");
	answerBox->setFontColor(cocos2d::Color3B::MAGENTA);
	//answerBox->setDelegate(this);

	this->addChild(answerBox,2);
	//
	openQuestion();
}

void Game1Layer::openQuestion(){
	pictureIndex++;
	if (pictureIndex >= 5) {
		loseInform();
		return;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();
	auto cluePicture = Sprite::create(__String::createWithFormat("%s%d.jpg", cluePictures[questionIndex].c_str(), pictureIndex)->getCString());
	cluePicture->setPosition(cluePoint);
	cluePicture->setScaleX(visibleSize.width / cluePicture->getContentSize().width / 10 * 5.2);
	cluePicture->setScaleY(visibleSize.height / cluePicture->getContentSize().height / 10 * 6.45);
	// add the sprite as a child to this layer
	this->addChild(cluePicture,2);

}



void Game1Layer::loadImageAnswer(){
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

void Game1Layer::menuSubmitCallback(Ref* pSender){
	std::string currentAnswer = answerBox->getText();
	if (currentAnswer == answer[questionIndex]) {
		successInform();
		return;
	}
	else {
		loseInform();
	}
}

void Game1Layer::menuNextCallback(Ref* pSender){
	openQuestion();
}

void Game1Layer::loseInform(){
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();
	inform->setString("Your answer is wrong!\nYou did not complete the chapter!");
	inform->setFontSize(40);
	inform->setVerticalAlignment(TextVAlignment::CENTER);
	inform->runAction(FadeIn::create(0.5f));
	menu->setOpacity(0);
	ingameGuide->setOpacity(0);
	auto outItem = MenuItemImage::create(
		"stage1/back.png",
		"stage1/back.png",
		CC_CALLBACK_1(Game1Layer::menuLoseCallback, this));
	outItem->setPosition(nextPoint);
	outItem->setScale(visibleSize.width / outItem->getContentSize().width / 3, visibleSize.height / outItem->getContentSize().height / 6);
	menu = Menu::create(outItem, NULL);
	menu->setPosition(Point::ZERO);
	menu->setOpacity(0);
	this->addChild(menu, 3); 
	menu->runAction(FadeIn::create(0.5f));
}
void Game1Layer::successInform(){
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();
	inform->setString("Congratulation!!!");
	inform->setFontSize(40);
	inform->setVerticalAlignment(TextVAlignment::CENTER);
	inform->runAction(FadeIn::create(0.5f));
	menu->setOpacity(0);
	ingameGuide->setOpacity(0);
	auto outItem = MenuItemImage::create(
		"stage1/nextchap.png",
		"stage1/nextchap.png",
		CC_CALLBACK_1(Game1Layer::menuWinCallback, this));
	outItem->setPosition(nextPoint);
	outItem->setScale(visibleSize.width / outItem->getContentSize().width / 3, visibleSize.height / outItem->getContentSize().height / 6);
	menu = Menu::create(outItem, NULL);
	menu->setPosition(Point::ZERO);
	menu->setOpacity(0);
	this->addChild(menu, 3);
	menu->runAction(FadeIn::create(0.5f));
}
void Game1Layer::menuLoseCallback(Ref* pSender){
	Director::getInstance()->replaceScene(MapScene::create());
}

void Game1Layer::menuWinCallback(Ref* pSender){
	UserDefault::getInstance()->setIntegerForKey("CurrentCityNo", questionIndex + 1);
	UserDefault::getInstance()->setStringForKey("CurrentCityName", __String::createWithFormat("city0%d", questionIndex + 1)->getCString());
	Director::getInstance()->replaceScene(Fact::create());
}