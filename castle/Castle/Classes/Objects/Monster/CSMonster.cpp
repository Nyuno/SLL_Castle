//
//  CSMonster.cpp
//  Castle
//
//  Created by Lee Byung Cheol on 2013. 11. 10..
//
//

#include "CSMonster.h"

#include "CSConstants.h"
#include "CSResources.h"

bool Goblin::init(){
    if(!CCNode::init()){
        return false;
    }
    
    this->schedule(schedule_selector(Goblin::update));
    
    this->mState        = MONSTER_STATE_STAND;
    this->mFirstFrame   = IMAGE_GROUND_STAGE::IMG_MONSTER_01;
    this->mCurrentFrame = 0;
    this->mLife         = 40 + rand() % 15;
    
    CCSprite* sprite    = GetSprite(IMAGE_GROUND_STAGE::RESOURCE_IMAGE[IMAGE_GROUND_STAGE::IMG_MONSTER_01]);
    sprite->setTag(TAG_SPRITE);
    this->addChild(sprite);
    
    return true;
}

void Goblin::update(float dt){
    
}

void Goblin::onExit(){
    this->unscheduleUpdate();
    CCNode::onExit();
}

bool CSMonster::init()
{
	if (!CCNode::create()) {
		return false;
	}
    
	this->schedule(schedule_selector(CSMonster::update));
	
	return true;
}

void CSMonster::update(float dt)
{
	
}

void CSMonster::onExit()
{
	this->unscheduleUpdate();
	CCNode::onExit();
}

CCRect* CSMonster::getBoundingBox()
{
	CCRect rect;
    
//	rect.setRect(this->getPositionX(), this->getPositionY(), mSpriteRef->getContentSize().width, mSpriteRef->getContentSize().height);
	
	return NULL;
}