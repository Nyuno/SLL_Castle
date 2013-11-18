//
//  CSGameLayer.cpp
//  Castle
//
//  Created by Lee Byung Cheol on 2013. 11. 10..
//
//

#include "CSGameLayer.h"
#include "CSResources.h"
#include "CSSettingScene.h"
#include "CSUserInterface.h"

using namespace cocos2d;

bool CSGameLayer::init()
{
	if (!CCLayer::init()) {
		return false;
	}
	
	// add floor
	CSFloor* floor = CSFloor::create();
    floor->setPosition(ccp(CENTER_POINT.x, CENTER_POINT.y));
    floor->setTag(TAG_FLOOR);
    this->addChild(floor);
    this->mFloorRef = (CSFloor*)this->getChildByTag(TAG_FLOOR);
	
	// add monster
	for (int i = 0; i < 3; i++) {
		CSMonster *monster = CSMonster::create();
		monster->setPosition(CENTER_POINT.x - 100 + (100*i), CENTER_POINT.y - 35.0f);
		this->addChild(monster);
		monsters.push_back(monster);
	}
	
	// add player
    player = CSPlayer::create();
//    player->setPosition(ccp(CENTER_POINT.x, CENTER_POINT.y - (146.0f / 2)));
    player->setTag(TAG_PLAYER);
    this->addChild(player);
	
	this->schedule(schedule_selector(CSGameLayer::update));
	
	this->setTouchEnabled(true);
	
    return true;
}

void CSGameLayer::update(float dt)
{
	checkCollision();
//	CCLog("update GameLayer %f", dt);
}

void CSGameLayer::onExit()
{
	this->unscheduleUpdate();
    CCLayer::onExit();
}


void CSGameLayer::checkCollision()
{
//	CCRect playerBox = player->getBoundingBox();
//	
//	for (int i = 0; i < monsters.size(); i++) {
//		CCRect monsterBox = monsters[i]->getBoundingBox();
//		
//		if (playerBox.intersectsRect(monsterBox)) {
//			CCLog("%d", rand()%50);
//			if (player->isDown()) {
//				player->jump();
//			}
//		}
//	}
}

void CSGameLayer::ccTouchesBegan(CCSet *pTouches, CCEvent* event)
{
	player->jump();
}

void CSGameLayer::ccTouchesEnded(CCSet *pTouches, CCEvent* event)
{
	
}