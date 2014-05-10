////
////  MapLayer.cpp
////  SaveTheWorld
////
////  Created by Giap Nguyen on 5/8/14.
////
////


#include "MapLayer.h"

USING_NS_CC;

MapLayer* MapLayer::create(const char *pCurrentCityName)
{
  MapLayer *pobSprite = new MapLayer();
  
  if (pobSprite && pobSprite->init(pCurrentCityName));
  {
    pobSprite->autorelease();
    return pobSprite;
  }
  CC_SAFE_DELETE(pobSprite);
  return NULL;
}


bool MapLayer::init(const char* pCurrentCityName)
{
  if (!Layer::init())
  {
    return false;
  }
  
  map = Sprite::create("map.jpg");
  map->setPosition(Point::ZERO);
  map->setAnchorPoint(Point::ANCHOR_BOTTOM_LEFT);
  addChild(map);
  
  
  addCities(pCurrentCityName);
  
  auto touchListener = EventListenerTouchOneByOne::create();
  touchListener->onTouchBegan = CC_CALLBACK_2(MapLayer::onTouchBegan, this);
  touchListener->onTouchMoved = CC_CALLBACK_2(MapLayer::onTouchMoved, this);
  _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
  
  return true;
}

void MapLayer::addCities(const char* pCurrentCityName)
{
  __String* path = __String::createWithFormat("map01.plist");
  std::string fullpath = FileUtils::getInstance()->fullPathForFilename(path->getCString());
  __Dictionary* mapDictionary = Dictionary::createWithContentsOfFileThreadSafe(fullpath.c_str());
  
  if (pCurrentCityName == NULL || strcmp(pCurrentCityName, "") == 0)
  {
    pCurrentCityName = mapDictionary->valueForKey("StartCity")->getCString();
  }
  
//  GameManager::setCurrentCityName(pCurrentCityName);
  UserDefault::getInstance()->setStringForKey("CurrentCityName", pCurrentCityName);
  std::string name = pCurrentCityName;
  UserDefault::getInstance()->setIntegerForKey("CurrentCityNo", __String::create(name.substr(4, 2))->intValue());
  
  // References
  __Dictionary* mapCitiesDictionary = (__Dictionary*)mapDictionary->objectForKey("Cities");
  
  // Create cities on map
  __Dictionary* iCityDictionary = NULL;
  //for (NSString* cityKey in [mapDictionary objectForKey:@"CitiesOrder"])
  Ref* child;
  
  mCitiesBatchNode = CCSpriteBatchNode::create("city_selectors.pvr.ccz", 201);
  //mCitiesBatchNode.setVisible(false);
  mCitiesArray = __Array::create();
  mCitiesArray->retain();

  CCARRAY_FOREACH((__Array*)mapDictionary->objectForKey("CitiesOrder"), child)
  {
    __String* cityKey = (__String*)child;
    iCityDictionary = (__Dictionary*)mapCitiesDictionary->objectForKey(cityKey->getCString());
    
    City *city = City::create(cityKey->getCString(), CITY_STATUS_LOCKED);
    
    city->setPosition(ccpAdd(PointFromString(((__String*)iCityDictionary->objectForKey("Position"))->getCString()), ccp(380, 300)));
    city->setScale(1.5f);
    if (cityKey->compare(pCurrentCityName) == 0)
    {
      city->updateCurrentSprite();
    }
    
    if (UserDefault::getInstance()->getStringForKey(cityKey->getCString()) == "win")
    {
      city->updateClearedSprite();
    }

    this->addChild(city, Z_MAP_CITIES);
    
    iCityDictionary->setObject(city, "Object");
    
    mCitiesArray->addObject((Ref*) city);
  }
//  CCARRAY_FOREACH(mCitiesArray, child)
//  {
//    City *city = (City*)child;
//    
//    iCityDictionary = (__Dictionary*)mapCitiesDictionary->objectForKey(city->getName());
//    __Array *pCityNeighbourArray = __Array::create();
//    
//    Ref *pChild;
//    CCARRAY_FOREACH((__Array*)iCityDictionary->objectForKey("NeighbourCities"), pChild)
//    {
//      __String *pNeighbourCityName = (__String*)pChild;
//      pCityNeighbourArray->addObject(((__Dictionary*)mapCitiesDictionary->objectForKey(pNeighbourCityName->getCString()))->objectForKey("Object"));
//    }
//    
////    pCity->setNeighBours(pCityNeighbourArray);
//  }

//  mCurrentCity = (City*)((__Dictionary*)mapCitiesDictionary->objectForKey(pCurrentCity))->objectForKey("Object");
////  mCurrentCity->makeCurrent();
////  mCurrentCity->unlock();
  this->scrollToPoint(ccpAdd(ccp(380, 300), PointFromString(((__String*)((__Dictionary*)mapCitiesDictionary->objectForKey(UserDefault::getInstance()->getStringForKey("CurrentCityName").c_str()))->objectForKey("Position"))->getCString())));
}

bool MapLayer::onTouchBegan(cocos2d::Touch *pTouch, cocos2d::Event *pEvent)
{
  mBeginLocation = pTouch->getLocation();
//  mBeginLocation = convertToNodeSpace(mBeginLocation);
  return true;
}

void MapLayer::onTouchMoved(cocos2d::Touch *pTouch, cocos2d::Event *pEvent)
{
  Point touchLocation = pTouch->getLocation();
//  touchLocation = convertToNodeSpace(touchLocation);
  
  float offsetX = touchLocation.x - mBeginLocation.x;
  float offsetY = touchLocation.y - mBeginLocation.y;
  
  moveMap(offsetX, offsetY);
  
  mBeginLocation = touchLocation;
  return;
}

void MapLayer::scrollToPoint(const Point& pPoint)
{
  scrollToPoint(pPoint, SCROLL_DURATION, CCEIO_EASE_IN_OUT);
}

void MapLayer::scrollToPoint(const Point& pPoint, float pDuration)
{
  scrollToPoint(pPoint, pDuration, CCEIO_EASE_IN_OUT);
}

void MapLayer::scrollToPoint(const Point& pPoint, float pDuration, eCCEaseInOut pEaseInOut)
{
  stopActionByTag(TAG_SCROLL_ACTION);
  
  if (pDuration != 0)
  {
    runAction(scrollActionToPoint(pPoint, pDuration, pEaseInOut));
  }
  else
  {
    // Scale and invert axis
    Point point;
    point = ccpMult(pPoint, -1);
    point.x += SCREEN_SIZE.width/2;
    point.y += SCREEN_SIZE.height/2;
    
    mAutoScrolling = false;
    setPosition(point);
  }
}

FiniteTimeAction* MapLayer::scrollActionToPoint(const Point& pPoint)
{
  return scrollActionToPoint(pPoint, SCROLL_DURATION);
}

FiniteTimeAction* MapLayer::scrollActionToPoint(const Point& pPoint, float pDuration)
{
  return scrollActionToPoint(pPoint, pDuration, CCEIO_EASE_IN_OUT);
}

FiniteTimeAction* MapLayer::scrollActionToPoint(const Point& pPoint, float pDuration, eCCEaseInOut pEaseInOut)
{
  // Scale and invert axis
  Point point = ccpMult(pPoint, -1);
  point.x += SCREEN_SIZE.width/2;
  point.y += SCREEN_SIZE.height/2;
  
  Action *scrollAction = NULL;
  
  scrollAction = CCSequence::create(CallFunc::create(this, callfunc_selector(MapLayer::startAutoScroll)),
                                  CCEaseInOut::create(CCMoveTo::create(pDuration, point), 2),
                                  CallFunc::create(this, callfunc_selector(MapLayer::endAutoScroll)),
                                  NULL);
  
  scrollAction->setTag(TAG_SCROLL_ACTION);
  return (FiniteTimeAction*)scrollAction;
}

void MapLayer::startAutoScroll()
{
  mAutoScrolling = true;
}

void MapLayer::endAutoScroll()
{
  mAutoScrolling = true;
}


void MapLayer::moveMap(float pDeltaX, float pDeltaY)
{
  float posX = getPosition().x + pDeltaX;
  float posY = getPosition().y + pDeltaY;
  
  if (posX > 0)
    posX = 0;
  if (posX < getBound().x)
    posX = getBound().x;
  if (posY > 0)
    posY = 0;
  if (posY < getBound().y)
  {
    posY = getBound().y;
  }

  setPosition(posX, posY);
}

cocos2d::Point MapLayer::getBound()
{
  float mapWidth = map->getContentSize().width;
  float mapHeight = map->getContentSize().height;
  
  return Point(SCREEN_SIZE.width - mapWidth, SCREEN_SIZE.height - mapHeight);
}
