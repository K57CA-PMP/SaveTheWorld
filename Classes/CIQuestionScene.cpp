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
  addWin();
  addReplayBtn();
  addBackBtn();
  addGameOver();
  injectAnswers();
  _answerTouchedID = 0;
  
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
  switch (CIGameManager::getQuestionIndex())
  {
    case 1:
      // add answer1
      _menu1 = MenuItemImage::create("CollectItems/a1_q1.png",
                                    "CollectItems/a1_q1.png",
                                      CC_CALLBACK_1(CIQuestionScene::answer1Touched, this));
      _menu1->setPosition(Point(SCREEN_SIZE.width/4, SCREEN_SIZE.height/3));
      _answer1 = Menu::create(_menu1, NULL);
      _answer1->setPosition(Point::ZERO);
      // add answer2
      _menu2 = MenuItemImage::create("CollectItems/a2_q1.png",
                                     "CollectItems/a2_q1.png",
                                      CC_CALLBACK_1(CIQuestionScene::answer2Touched, this));
      _menu2->setPosition(Point(SCREEN_SIZE.width/2, SCREEN_SIZE.height/3));
      _answer2 = Menu::create(_menu2, NULL);
      _answer2->setPosition(Point::ZERO);
      // add answer3
      _menu3 = MenuItemImage::create("CollectItems/a3_q1.png",
                                     "CollectItems/a3_q1.png",
                                     CC_CALLBACK_1(CIQuestionScene::answer3Touched, this));
      _menu3->setPosition(Point(SCREEN_SIZE.width/1.3, SCREEN_SIZE.height/3));
      _answer3 = Menu::create(_menu3, NULL);
      _answer3->setPosition(Point::ZERO);
      break;
    case 2:
      // add answer1
      _menu1 = MenuItemImage::create("CollectItems/a1_q2.png",
                                     "CollectItems/a1_q2.png",
                                     CC_CALLBACK_1(CIQuestionScene::answer1Touched, this));
      _menu1->setPosition(Point(SCREEN_SIZE.width/4, SCREEN_SIZE.height/3));
      _answer1 = Menu::create(_menu1, NULL);
      _answer1->setPosition(Point::ZERO);
      // add answer2
      _menu2 = MenuItemImage::create("CollectItems/a2_q2.png",
                                     "CollectItems/a2_q2.png",
                                     CC_CALLBACK_1(CIQuestionScene::answer2Touched, this));
      _menu2->setPosition(Point(SCREEN_SIZE.width/2, SCREEN_SIZE.height/3));
      _answer2 = Menu::create(_menu2, NULL);
      _answer2->setPosition(Point::ZERO);
      // add answer3
      _menu3 = MenuItemImage::create("CollectItems/a3_q2.png",
                                     "CollectItems/a3_q2.png",
                                     CC_CALLBACK_1(CIQuestionScene::answer3Touched, this));
      _menu3->setPosition(Point(SCREEN_SIZE.width/1.3, SCREEN_SIZE.height/3));
      _answer3 = Menu::create(_menu3, NULL);
      _answer3->setPosition(Point::ZERO);
      break;
    case 3:
      // add answer1
      _menu1 = MenuItemImage::create("CollectItems/a1_q3.png",
                                     "CollectItems/a1_q3.png",
                                     CC_CALLBACK_1(CIQuestionScene::answer1Touched, this));
      _menu1->setPosition(Point(SCREEN_SIZE.width/4, SCREEN_SIZE.height/3));
      _answer1 = Menu::create(_menu1, NULL);
      _answer1->setPosition(Point::ZERO);
      // add answer2
      _menu2 = MenuItemImage::create("CollectItems/a2_q3.png",
                                     "CollectItems/a2_q3.png",
                                     CC_CALLBACK_1(CIQuestionScene::answer2Touched, this));
      _menu2->setPosition(Point(SCREEN_SIZE.width/2, SCREEN_SIZE.height/3));
      _answer2 = Menu::create(_menu2, NULL);
      _answer2->setPosition(Point::ZERO);
      // add answer3
      _menu3 = MenuItemImage::create("CollectItems/a3_q3.png",
                                     "CollectItems/a3_q3.png",
                                     CC_CALLBACK_1(CIQuestionScene::answer3Touched, this));
      _menu3->setPosition(Point(SCREEN_SIZE.width/1.37, SCREEN_SIZE.height/3));
      _answer3 = Menu::create(_menu3, NULL);
      _answer3->setPosition(Point::ZERO);
      break;
    case 4:
      // add answer1
      _menu1 = MenuItemImage::create("CollectItems/a1_q4.png",
                                     "CollectItems/a1_q4.png",
                                     CC_CALLBACK_1(CIQuestionScene::answer1Touched, this));
      _menu1->setPosition(Point(SCREEN_SIZE.width/4, SCREEN_SIZE.height/3));
      _answer1 = Menu::create(_menu1, NULL);
      _answer1->setPosition(Point::ZERO);
      // add answer2
      _menu2 = MenuItemImage::create("CollectItems/a2_q4.png",
                                     "CollectItems/a2_q4.png",
                                     CC_CALLBACK_1(CIQuestionScene::answer2Touched, this));
      _menu2->setPosition(Point(SCREEN_SIZE.width/2, SCREEN_SIZE.height/3));
      _answer2 = Menu::create(_menu2, NULL);
      _answer2->setPosition(Point::ZERO);
      // add answer3
      _menu3 = MenuItemImage::create("CollectItems/a3_q4.png",
                                     "CollectItems/a3_q4.png",
                                     CC_CALLBACK_1(CIQuestionScene::answer3Touched, this));
      _menu3->setPosition(Point(SCREEN_SIZE.width/1.3, SCREEN_SIZE.height/3));
      _answer3 = Menu::create(_menu3, NULL);
      _answer3->setPosition(Point::ZERO);
      break;
    case 5:
      // add answer1
      _menu1 = MenuItemImage::create("CollectItems/a1_q5.png",
                                     "CollectItems/a1_q5.png",
                                     CC_CALLBACK_1(CIQuestionScene::answer1Touched, this));
      _menu1->setPosition(Point(SCREEN_SIZE.width/4, SCREEN_SIZE.height/3));
      _answer1 = Menu::create(_menu1, NULL);
      _answer1->setPosition(Point::ZERO);
      // add answer2
      _menu2 = MenuItemImage::create("CollectItems/a2_q5.png",
                                     "CollectItems/a2_q5.png",
                                     CC_CALLBACK_1(CIQuestionScene::answer2Touched, this));
      _menu2->setPosition(Point(SCREEN_SIZE.width/2, SCREEN_SIZE.height/3));
      _answer2 = Menu::create(_menu2, NULL);
      _answer2->setPosition(Point::ZERO);
      // add answer3
      _menu3 = MenuItemImage::create("CollectItems/a3_q5.png",
                                     "CollectItems/a3_q5.png",
                                     CC_CALLBACK_1(CIQuestionScene::answer3Touched, this));
      _menu3->setPosition(Point(SCREEN_SIZE.width/1.35, SCREEN_SIZE.height/3));
      _answer3 = Menu::create(_menu3, NULL);
      _answer3->setPosition(Point::ZERO);
      break;
    default:
      break;
  }
  this->addChild(_answer1, 3);
  this->addChild(_answer2, 3);
  this->addChild(_answer3, 3);
}

void CIQuestionScene::answer1Touched(Ref *pSender)
{
  _answerTouchedID = 1;
  checkAnswer();
}

void CIQuestionScene::answer2Touched(Ref *pSender)
{
  _answerTouchedID = 2;
  checkAnswer();
}

void CIQuestionScene::answer3Touched(Ref *pSender)
{
  _answerTouchedID = 3;
  checkAnswer();
}

void CIQuestionScene::checkAnswer()
{
  switch (CIGameManager::getQuestionIndex())
  {
    case 1:
      if (_answerTouchedID == CIGameManager::getAnswer(1))
      {
        _win->setVisible(true);
      }
      else
      {
        _gameOver->setVisible(true);
        _replayBtn->setVisible(true);
      }
      break;
    case 2:
      if (_answerTouchedID == CIGameManager::getAnswer(2))
      {
        _win->setVisible(true);
      }
      else
      {
        _gameOver->setVisible(true);
        _replayBtn->setVisible(true);
      }
      break;
    case 3:
      if (_answerTouchedID == CIGameManager::getAnswer(3))
      {
        _win->setVisible(true);
      }
      else
      {
        _gameOver->setVisible(true);
        _replayBtn->setVisible(true);
      }
      break;
    case 4:
      if (_answerTouchedID == CIGameManager::getAnswer(4))
      {
        _win->setVisible(true);
      }
      else
      {
        _gameOver->setVisible(true);
        _replayBtn->setVisible(true);
      }
      break;
    case 5:
      if (_answerTouchedID == CIGameManager::getAnswer(5))
      {
        _win->setVisible(true);
      }
      else
      {
        _gameOver->setVisible(true);
        _replayBtn->setVisible(true);
      }
      break;
    default:
      break;
  }
}

void CIQuestionScene::addWin()
{
  auto menu = MenuItemImage::create("CollectItems/win.png",
                                    "CollectItems/win.png",
                                    CC_CALLBACK_1(CIQuestionScene::winTouched, this));
  menu->setPosition(Point(SCREEN_SIZE.width/2, SCREEN_SIZE.height/2));
  _win = Menu::create(menu, NULL);
  _win->setScale(0.7);
  _win->setPosition(Point::ZERO);
  _win->setVisible(false);
  this->addChild(_win, 11);
}

void CIQuestionScene::winTouched(Ref* pSender)
{
  if (CIGameManager::getGameLevel() < 5)
  {
    CIGameManager::setGameLevel(CIGameManager::getGameLevel() + 1);
    auto scene = CCTransitionCrossFade::create(0.5, CIPlayScene::createScene());
    Director::getInstance()->sharedDirector()->replaceScene(scene);
  }
  else if (CIGameManager::getGameLevel() == 5)
  {
    auto scene = CCTransitionCrossFade::create(0.5, MapScene::create());
    Director::getInstance()->sharedDirector()->replaceScene(scene);
  }
}

void CIQuestionScene::addGameOver()
{
  _gameOver = Sprite::create("CollectItems/gameOver.png");
  _gameOver->setScale(2);
  _gameOver->setPosition(SCREEN_SIZE.width/2, SCREEN_SIZE.height/1.5);
  _gameOver->setVisible(false);
  this->addChild(_gameOver, 11);
}

void CIQuestionScene::addReplayBtn()
{
  auto menu = MenuItemImage::create("CollectItems/replay.png",
                                    "CollectItems/replay.png",
                                    CC_CALLBACK_1(CIQuestionScene::replayBtnTouched, this));
  menu->setScale(0.5);
  menu->setPosition(SCREEN_SIZE.width/2, SCREEN_SIZE.height/2.5);
  _replayBtn = Menu::create(menu, NULL);
  _replayBtn->setPosition(Point::ZERO);
  _replayBtn->setVisible(false);
  this->addChild(_replayBtn, 11);
}

void CIQuestionScene::replayBtnTouched(Ref* pSender)
{
  CIGameManager::setQuestionIndex(CIGameManager::getQuestionIndex() - 1);
  auto scene = CCTransitionCrossFade::create(0.5, CIPlayScene::createScene());
  Director::getInstance()->sharedDirector()->replaceScene(scene);
}

void CIQuestionScene::addBackBtn()
{
  auto menu = MenuItemImage::create("CollectItems/back.png",
                                    "CollectItems/back.png",
                                    CC_CALLBACK_1(CIQuestionScene::backBtnTouched, this));
  menu->setPosition(Point(_visibleOrigin.x + menu->getContentSize().width/2, _visibleOrigin.y + menu->getContentSize().height/2));
  menu->setScale(0.7);
  _backBtn = Menu::create(menu, _backBtn);
  _backBtn->setPosition(Point::ZERO);
  //  _backBtn->setVisible(false);
  this->addChild(_backBtn, 11);
}

void CIQuestionScene::backBtnTouched(Ref* pSender)
{
  auto scene = CCTransitionCrossFade::create(0.5, MapScene::create());
  Director::getInstance()->sharedDirector()->replaceScene(scene);
}

void CIQuestionScene::injectAnswers()
{
  CIGameManager::setAnswer(1, ANSWER1);
  CIGameManager::setAnswer(2, ANSWER2);
  CIGameManager::setAnswer(3, ANSWER3);
  CIGameManager::setAnswer(4, ANSWER4);
  CIGameManager::setAnswer(5, ANSWER5);
}