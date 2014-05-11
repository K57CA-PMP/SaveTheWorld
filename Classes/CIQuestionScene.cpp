//
//  CIQuestionScene.cpp
//  SaveTheWorld
//
//  Created by Tuan TQ on 5/11/14.
//
//

#include "CIQuestionScene.h"
USING_NS_CC;

Scene* CIQuestionScene::createScene()
{
  auto layer = CIQuestionScene::create();
  auto scene = Scene::create();
  scene->addChild(layer);
  return scene;
}

bool CIQuestionScene::init()
{
  if (!Layer::init())
  {
    return false;
  }
  
  _visibleSize = Director::getInstance()->getVisibleSize();
  _visibleOrigin = Director::getInstance()->getVisibleOrigin();
  
  addBackground();
  addQuestion();
  addAnswers();
  
  return true;
}

void CIQuestionScene::addBackground()
{
  _background = Sprite::create("CollectItems/start3.png");
  _background->setScale(3);
  _background->setOpacity(100);
  this->addChild(_background, 0);
}

void CIQuestionScene::addQuestion()
{

}

void CIQuestionScene::addAnswers()
{
  
}
