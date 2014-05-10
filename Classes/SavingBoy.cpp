
//
//  SavingBoy.cpp
//  SaveTheWorld
//
//  Created by Giap Nguyen on 5/10/14.
//
//

#include "SavingBoy.h"

USING_NS_CC;

Scene* SavingBoy::createScene()
{
  // 'scene' is an autorelease object
  auto scene = Scene::create();
  
  // 'layer' is an autorelease object
  auto layer = SavingBoy::create();
  
  // add layer as a child to scene
  scene->addChild(layer);
  
  // return the scene
  return scene;
}

// on "init" you need to initialize your instance
bool SavingBoy::init()
{
  if ( !Layer::init() )
  {
    return false;
  }

  animateIntro();
  
  return true;
}

void SavingBoy::animateIntro()
{
  std::string text = "Trong chuyến phiêu lưu, anh hùng của chúng ta cần cứu 10 \n nạn nhân trong các tai nạn, thảm họa....";
  auto label = Label::createWithSystemFont(text, "Arial", 40);
  this->addChild(label);
//  Color3B color(226, 121, 7);
//  label->setColor(color);

  // move the sprite from top to position
  auto inputTextSize = label->getContentSize();
//  Point beginPos(endPos.x, Director::getInstance()->getWinSize().height - inputTextSize.height * 2);

  float duration = 0.5;
  label->setPosition( Point(SCREEN_SIZE.width/2, SCREEN_SIZE.height/2));
  label->setScale(8);

  auto seq = Sequence::create(
                              Spawn::create(
                                MoveTo::create(duration, Point(SCREEN_SIZE.width/2, SCREEN_SIZE.height/2)),
                                ScaleTo::create(duration, 1),
                                FadeIn::create(duration),
                                NULL),
                              CCDelayTime::create(2.5f),
                              FadeOut::create(1.0f),
                              CallFuncN::create(CC_CALLBACK_1(SavingBoy::callbackRemoveWhenDidAction, this)),
                              NULL);
  label->runAction(seq);
}

void SavingBoy::callbackRemoveWhenDidAction(Node * node)
{
  this->removeChild(node, true);
  std::string text = "Ngày đầu tiên .... \n \nSau khi vùng đất bị lũ, nước dâng lên cao và chảy siết ... ";
  auto label = Label::createWithSystemFont(text, "Arial", 40);
  label->setPosition(SCREEN_SIZE.width/2, SCREEN_SIZE.height/2);
  label->runAction(Sequence::create(FadeIn::create(1.5f),
                                    FadeOut::create(1.5f),
                                    DelayTime::create(0.5f),
                                    CallFuncN::create(CC_CALLBACK_1(SavingBoy::warning, this)),
                                    NULL));
  this->addChild(label);
}

void SavingBoy::warning(Node* node)
{
  std::string text = "Có người bị chết đuối,\n CẦN CỨU NGƯỜI NGAY!!!";
  auto label = Label::createWithSystemFont(text, "Arial", 40);
  label->setPosition(SCREEN_SIZE.width/2, SCREEN_SIZE.height/2);
  label->runAction(Sequence::create(//FadeIn::create(0.5f),
//                                    DelayTime::create(0.5f),
                                    ScaleTo::create(0.2, 2.0f),
                                    DelayTime::create(1.5f),
                                    CallFuncN::create(CC_CALLBACK_1(SavingBoy::appearVictim, this)),
                                    NULL));
  this->addChild(label);
  
}

void SavingBoy::appearVictim(cocos2d::Node *node)
{
  node->removeFromParent();
  
  Sprite* victim = Sprite::create("SavingBoy/victim.png");
  victim->setPosition(SCREEN_SIZE.width/2, SCREEN_SIZE.height/2);
  victim->setScale(1.5f);
  victim->runAction(
                    Sequence::create(//FadeIn::create(0.5f),
                                     MoveTo::create(0.3f, Point(SCREEN_SIZE.width/2, SCREEN_SIZE.height/4*3)),
                                     NULL));
  victim->runAction(ScaleTo::create(0.3f, 1));
  
  MenuItemSprite* tools = MenuItemSprite::create(Sprite::create("SavingBoy/tools.png"),
                                                 Sprite::create("SavingBoy/tools.png"),
                                                 CC_CALLBACK_1(SavingBoy::toolTouched, this));
  tools->setScale(0.6);
  tools->setPosition(Point(-50, SCREEN_SIZE.height/4));
  tools->runAction(CCMoveTo::create(0.3f, Point(SCREEN_SIZE.width/3, SCREEN_SIZE.height/4)));
  MenuItemSprite* swim = MenuItemSprite::create(Sprite::create("SavingBoy/swim.png"),
                                                Sprite::create("SavingBoy/swim.png"),
                                                CC_CALLBACK_1(SavingBoy::swim, this));
  swim->setScale(0.6);
  swim->setPosition(Point(1186, SCREEN_SIZE.height/4));
  swim->runAction(CCMoveTo::create(0.3f, Point(2 * SCREEN_SIZE.width/3, SCREEN_SIZE.height/4)));
  
  Menu* menu = Menu::create(tools, swim, NULL);
  menu->setPosition(Point::ZERO);
  this->addChild(menu);
  
  this->addChild(victim);

}

void SavingBoy::scaleVictim(Node* node)
{
  node->runAction(ScaleTo::create(0.5f, 0.8));
}

void SavingBoy::toolTouched(cocos2d::Ref *pSender)
{
  
}

void SavingBoy::swim(cocos2d::Ref *pSender)
{
  
}
