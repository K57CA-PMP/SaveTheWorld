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
  _background = Sprite::create("CollectItems/start1.png");
  _background->setScale(3);
  _background->setOpacity(100);
  _background->setPosition(SCREEN_SIZE.width/2, SCREEN_SIZE.height/2);
  this->addChild(_background, 0);
}

void CIQuestionScene::addQuestion()
{
  switch (CIGameManager::getQuestionIndex())
  {
    case 1:
      _question = EditBox::create(Size(_visibleSize.width/1, _visibleSize.height/9), Scale9Sprite::create());
      _question->setPosition(Point(_visibleOrigin.x + _visibleSize.width/1.8, _visibleOrigin.y + _visibleSize.height/1.5));
      _question->setFontColor(Color3B(255, 255, 255));
      _question->setFont("Arial", 45);
      _question->setText(QUESTION1);
      break;
    case 2:
      _question = EditBox::create(Size(_visibleSize.width/1, _visibleSize.height/9), Scale9Sprite::create());
      _question->setPosition(Point(_visibleOrigin.x + _visibleSize.width/1.45, _visibleOrigin.y + _visibleSize.height/1.5));
      _question->setFontColor(Color3B(255, 255, 255));
      _question->setFont("Arial", 45);
      _question->setText(QUESTION2);
      break;
    case 3:
      _question = EditBox::create(Size(_visibleSize.width/1, _visibleSize.height/9), Scale9Sprite::create());
      _question->setPosition(Point(_visibleOrigin.x + _visibleSize.width/1.8, _visibleOrigin.y + _visibleSize.height/1.5));
      _question->setFontColor(Color3B(255, 255, 255));
      _question->setFont("Arial", 45);
      _question->setText(QUESTION3);
      break;
    case 4:
      _question = EditBox::create(Size(_visibleSize.width/1, _visibleSize.height/9), Scale9Sprite::create());
      _question->setPosition(Point(_visibleOrigin.x + _visibleSize.width/1.3, _visibleOrigin.y + _visibleSize.height/1.5));
      _question->setFontColor(Color3B(255, 255, 255));
      _question->setFont("Arial", 45);
      _question->setText(QUESTION4);
      break;
    case 5:
      _question = EditBox::create(Size(_visibleSize.width/1, _visibleSize.height/9), Scale9Sprite::create());
      _question->setPosition(Point(_visibleOrigin.x + _visibleSize.width/1.35, _visibleOrigin.y + _visibleSize.height/1.5));
      _question->setFontColor(Color3B(255, 255, 255));
      _question->setFont("Arial", 45);
      _question->setText(QUESTION5);
      break;
    default:
      break;
  }
  this->addChild(_question, 3);
}

void CIQuestionScene::addAnswers()
{
  
}
