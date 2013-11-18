//
//  CSFloor.cpp
//  Castle
//
//  Created by Lee Byung Cheol on 2013. 11. 10..
//
//

#include "CSFloor.h"
#include "CSConstants.h"
#include "CSResources.h"

bool GroundFloor::init(){
    if(!CCNode::init()){
        return false;
    }
    
    // Sky
    CCSprite* sprite = GetSprite(IMAGE_GROUND_STAGE::RESOURCE_IMAGE[IMAGE_GROUND_STAGE::IMG_BG_SKY]);
    sprite->setTag(TAG_SKY);
    this->addChild(sprite, Z_ORDER_SKY);
    
    initFloor();
    
    // Label
    CCLabelTTF* label = CCLabelTTF::create("0F", "Munro Small", 18);
    label->setTag(TAG_LABEL);
    label->setAnchorPoint(ccp(0, 0.5));
    label->setPosition(ccp(-160.0f + 3.0f, -(153.0f / 2.0f) + 11.0f));
    label->setColor(ccc3(140.0f, 140.0f, 140.0f));
    this->addChild(label, Z_ORDER_LABEL);
    
    this->mFloorTestRef = ((CCLabelTTF*)this->getChildByTag(TAG_LABEL));
    
    return true;
}

void GroundFloor::reset(int floor){
    SAFE_REMOVE_CHILD(TAG_FURNITURE);
    SAFE_REMOVE_CHILD(TAG_BG);
    
    this->initFloor();
    this->setFloor(floor);
}

void GroundFloor::setFloor(int floor){
    char str[256];
    sprintf(str, "%dF", floor);
    this->mFloorTestRef->setString(str);
}

void GroundFloor::initFloor(){
    
    CCSprite* sprite;
    // Floor
    int ranNum = rand() % 4;
    sprite = GetSprite(IMAGE_GROUND_STAGE::RESOURCE_IMAGE[IMAGE_GROUND_STAGE::IMG_BG_FLOOR_1 + ranNum]);
    sprite->setTag(TAG_BG);
    this->addChild(sprite, Z_ORDER_FLOOR);
    
    // Furniture
    ranNum = rand() % 4;
    CCSprite* furnitureSprite = NULL;
    switch (ranNum) {
        case 0:
            furnitureSprite = GetSprite(IMAGE_GROUND_STAGE::RESOURCE_IMAGE[IMAGE_GROUND_STAGE::IMG_BG_DRAWER]);
            break;
        case 1:
            furnitureSprite = GetSprite(IMAGE_GROUND_STAGE::RESOURCE_IMAGE[IMAGE_GROUND_STAGE::IMG_BG_DRESSING_TABLE]);
            break;
        case 2:
            furnitureSprite = GetSprite(IMAGE_GROUND_STAGE::RESOURCE_IMAGE[IMAGE_GROUND_STAGE::IMG_BG_WARDROBE]);
            break;
    }
    
    if(furnitureSprite){
        furnitureSprite->setTag(TAG_FURNITURE);
        furnitureSprite->setAnchorPoint(ccp(0.5, 0));
        furnitureSprite->setPosition(ccp( 50.0f + rand() % 250, -(153.0f / 2.0f) + 22.0f));
        this->addChild(furnitureSprite, Z_ORDER_FURNITURE);
    }
}

bool CSFloor::init()
{
	if (!CCNode::init()) {
		return false;
	}
    
    this->mFloor = 0;
    
    for(int i = 0; i < 5; ++i) {
        GroundFloor* floor = GroundFloor::create();
        floor->setFloor(i);
        floor->setPosition(ccp(0, -CENTER_POINT.y + (153.0f / 2.0f) + (i * 153)));
        floor->setTag(TAG_FLOOR_1 + i);
        this->addChild(floor);
        this->mGroundFloorRef[i] = (GroundFloor*)this->getChildByTag(TAG_FLOOR_1 + i);
    }
	
	this->schedule(schedule_selector(CSFloor::update));
	
	return true;
}

void CSFloor::update(float dt)
{
}

void CSFloor::addFloor(){
    this->mGroundFloorRef[this->mFloor % 5]->reset(5 + this->mFloor);
    this->mGroundFloorRef[this->mFloor % 5]->setPosition(ccp(0, -CENTER_POINT.y + (153.0f / 2.0f) + (this->mFloor + 5) * 153));
    this->mFloor++;
}

void CSFloor::onExit()
{
	this->unscheduleUpdate();
    CCNode::onExit();
}