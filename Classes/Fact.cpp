//
//  Stage1Scene.cpp
//  SaveTheWorld
//
//  Created by Peter 09/05/2014
//
//

#include "Fact.h"
#include "MapScene.h"
#include "vietnamese.h"
#include "Constant.h"



USING_NS_CC;



bool Fact::init()
{
	if (!Scene::init())
	{
		return false;
	}
	questionNo = UserDefault::getInstance()->getIntegerForKey("CurrentCityNo");
	Size visibleSize = Director::getInstance()->getVisibleSize();
	information = CCLabelTTF::create("", "Arial", 30,
		Size(visibleSize.width * 4/5, visibleSize.height *4/5));
	information->setPosition(visibleSize.width /2, visibleSize.height /2);
	information->setHorizontalAlignment(TextHAlignment::LEFT);
	this->addChild(information,2);

	auto skipItem = MenuItemImage::create(
		"stage1/start.png",
		"stage1/start.png",
		CC_CALLBACK_1(Fact::menuSkipCallback, this));
	skipItem->setPosition(visibleSize.width-skipItem->getContentSize().width/2,skipItem->getContentSize().height/2);
	skipItem->setScale(visibleSize.width / skipItem->getContentSize().width / 8, visibleSize.height / skipItem->getContentSize().height / 6 );
	auto menu = Menu::create(skipItem, NULL);
	menu->setPosition(Point::ZERO);
	this->addChild(menu, 2);
	chooseBackground();


	return true;
}

void Fact::menuSkipCallback(Ref* pSender){
	Director::getInstance()->replaceScene(MapScene::create());
}


void Fact::chooseBackground(){
	Size visibleSize = Director::getInstance()->getVisibleSize();
	std::string linkanh = "", content = "";
	switch (questionNo-1) {
	case 1:
		content = fact1;
		linkanh = "stage1/flood1.jpg";
		break;
	case 2:
		content = fact2;
		linkanh = "stage1/chay1.jpg";
		break;
	case 3:
		content = fact3;
		linkanh = "stage1/drought1.jpg";
		break;
	case 4:
		content = fact4;
		linkanh = "stage1/earthquake1.jpg";
		break;
	case 5:
		content = fact5;
		linkanh = "stage1/storm1.jpg";
		break;
	case 6:
		content = fact6;
		linkanh = "stage1/tsunami1.jpg";
		break;
	default:
		linkanh = "";
	}
	bg = Sprite::create(linkanh) ;
	bg->setScale(visibleSize.width/bg->getContentSize().width,visibleSize.height/bg->getContentSize().height);
	bg->setOpacity(100);
	bg->setPosition(visibleSize.width/2,visibleSize.height/2);
	addChild(bg,0);
	information->setString(content);
}
