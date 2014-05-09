////
////  MapLayer.cpp
////  SaveTheWorld
////
////  Created by Giap Nguyen on 5/8/14.
////
////
//
//#include "MapLayer.h"
//
//USING_NS_CC;
//
//bool MapLayer::init()
//{
//  if (!Layer::init())
//  {
//    return false;
//  }
//  
//  map = Sprite::create("map.jpg");
//  map->setPosition(Point::ZERO);
//  map->setAnchorPoint(Point::ANCHOR_BOTTOM_LEFT);
//  addChild(map);
//  
//  addCities();
//  
//  auto touchListener = EventListenerTouchOneByOne::create();
//  touchListener->onTouchBegan = CC_CALLBACK_2(MapLayer::onTouchBegan, this);
//  touchListener->onTouchMoved = CC_CALLBACK_2(MapLayer::onTouchMoved, this);
//  _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
//  
//
//  return true;
//}
//
//void MapLayer::addCities()
//{
//  __String* path = __String::createWithFormat("Plist/Maps/map01.plist");
//  std::string fullpath = FileUtils::getInstance()->fullPathForFilename(path->getCString());
//  __Dictionary* mapDictionary = Dictionary::createWithContentsOfFileThreadSafe(fullpath.c_str());
//  
//  // References
//  __Dictionary* mapCitiesDictionary = (__Dictionary*)mapDictionary->objectForKey("Cities");
//  
//  // Create cities on map
//  __Dictionary* iCityDictionary = NULL;
//  //for (NSString* cityKey in [mapDictionary objectForKey:@"CitiesOrder"])
//  Ref* child;
//  
//  mCitiesBatchNode = CCSpriteBatchNode::create("city_selectors.pvr.ccz", 201);
//  //mCitiesBatchNode.setVisible(false);
//  mCitiesArray = __Array::create();
//  mCitiesArray->retain();
//
//  CCARRAY_FOREACH((__Array*)mapDictionary->objectForKey("CitiesOrder"), child)
//  {
//    __String* cityKey = (__String*)child;
//    iCityDictionary = (__Dictionary*)mapCitiesDictionary->objectForKey(cityKey->getCString());
//    
//    City *city = City::create(cityKey->getCString(),
//                              this,
//                              CITY_STATUS_CLEARED);
//    
//    city->setPosition(PointFromString(((__String*)iCityDictionary->objectForKey("Position"))->getCString()));
//    
//    this->addChild(city, Z_MAP_CITIES);
//    
//    iCityDictionary->setObject(city, "Object");
//    
//    mCitiesArray->addObject((Ref*) city);
//  }
//  
//  CCARRAY_FOREACH(mCitiesArray, child)
//  {
//    City *pCity = (City*)child;
//    
//    iCityDictionary = (__Dictionary*)mapCitiesDictionary->objectForKey(pCity->getName());
//    __Array *pCityNeighbourArray = __Array::create();
//    
//    CCObject *pChild;
//    CCARRAY_FOREACH((__Array*)iCityDictionary->objectForKey("NeighbourCities"), pChild)
//    {
//      __String *pNeighbourCityName = (__String*)pChild;
//      pCityNeighbourArray->addObject(((CCDictionary*)mapCitiesDictionary->objectForKey(pNeighbourCityName->getCString()))->objectForKey("Object"));
//    }
//    
//    pCity->setNeighBours(pCityNeighbourArray);
//  }
//  
////  if (pCurrentCityName == NULL || strcmp(pCurrentCityName, "") == 0)
////  {
////    pCurrentCityName = mapDictionary->valueForKey("StartCity")->getCString();
////  }
//  
////  mCurrentCity = (City*)((CCDictionary*)mapCitiesDictionary->objectForKey(pCurrentCityName))->objectForKey("Object");
////  mCurrentCity->makeCurrent();
////  mCurrentCity->unlock();
////  this->scrollToPoint(mCurrentCity->getPosition());
//}
//
//bool MapLayer::onTouchBegan(cocos2d::Touch *pTouch, cocos2d::Event *pEvent)
//{
//  mBeginLocation = pTouch->getLocation();
////  mBeginLocation = convertToNodeSpace(mBeginLocation);
//  return true;
//}
//
//void MapLayer::onTouchMoved(cocos2d::Touch *pTouch, cocos2d::Event *pEvent)
//{
//  Point touchLocation = pTouch->getLocation();
////  touchLocation = convertToNodeSpace(touchLocation);
//  
//  float offsetX = touchLocation.x - mBeginLocation.x;
//  float offsetY = touchLocation.y - mBeginLocation.y;
//  
//  moveMap(offsetX, offsetY);
//  
//  mBeginLocation = touchLocation;
//  return;
//}
//  
//void MapLayer::moveMap(float pDeltaX, float pDeltaY)
//{
//  float posX = getPosition().x + pDeltaX;
//  float posY = getPosition().y + pDeltaY;
//  
//  if (posX > 0)
//    posX = 0;
//  if (posX < getBound().x)
//    posX = getBound().x;
//  if (posY > 0)
//    posY = 0;
//  if (posY < getBound().y)
//  {
//    posY = getBound().y;
//  }
//
//  setPosition(posX, posY);
//}
//
//cocos2d::Point MapLayer::getBound()
//{
//  float mapWidth = map->getContentSize().width;
//  float mapHeight = map->getContentSize().height;
//  
//  return Point(SCREEN_SIZE.width - mapWidth, SCREEN_SIZE.height - mapHeight);
//}
