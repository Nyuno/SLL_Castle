//
//  CSGameUILayer.cpp
//  Castle
//
//  Created by Lee Byung Cheol on 2013. 11. 10..
//
//

#include "CSGameUILayer.h"

bool CSGameUILayer::init()
{
	if (!CCLayer::init()) {
		return false;
	}
	
	this->schedule(schedule_selector(CSGameUILayer::update));
    
    
    return true;
}

void CSGameUILayer::update(float dt)
{
//	CCLog("update GameUILayer %f", dt);
}

void CSGameUILayer::onExit()
{
	this->unscheduleUpdate();
    CCLayer::onExit();
}