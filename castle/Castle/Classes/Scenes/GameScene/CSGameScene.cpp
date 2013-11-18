//
//  CSGameScene.cpp
//  Castle
//
//  Created by Lee Byung Cheol on 2013. 11. 9..
//
//

#include "CSGameScene.h"

#include "CSConstants.h"
#include "CSResources.h"
#include "CSSettingScene.h"

bool CSGameScene::init()
{
    if (!CCLayer::init()) {
        return false;
    }
    
    srand((unsigned)time(NULL));
	
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("GameStage/HD/GameStage.plist");
    
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("GameStage/GroundStage/GroundStage.plist");
    
    // Add Notification
    CCNotificationCenter::sharedNotificationCenter()->addObserver(this, callfuncO_selector(CSGameScene::scrollDown), NOTIFICATION_SCROLL_DOWN, NULL);
    CCNotificationCenter::sharedNotificationCenter()->addObserver(this, callfuncO_selector(CSGameScene::scrollUp), NOTIFICATION_SCROLL_UP, NULL);

	// add layers
	CSGameLayer* layer = CSGameLayer::create();
    layer->setTag(TAG_GAME_LAYER);
	this->addChild(layer);
    
    // UI Layer
    CSUserInterface* ui = CSUserInterface::create();
    ui->setTag(TAG_UI);
    this->addChild(ui);
    
    this->mGameLayerRef = (CSGameLayer*)this->getChildByTag(TAG_GAME_LAYER);
    this->mUIRef = (CSUserInterface*)this->getChildByTag(TAG_UI);
    
	this->setPosition(0, 0);
	
    this->schedule(schedule_selector(CSGameScene::update));
    
    
    CCMenuItemFont* font = CCMenuItemFont::create("PopScene", this, menu_selector(CSGameScene::testScene));
    CCMenu* menu = CCMenu::create(font, NULL);
    menu->setPosition(ccp(160.0f, 500.0f));
    this->addChild(menu);
	
    return true;
}

void CSGameScene::update(float dt)
{
    if(this->mIsScrolling){
        this->mScrollTime += dt;
        if(this->mScrollTime >= 1.0f){
            this->mScrollTime   = 0.0f;
            this->mIsScrolling  = false;
            this->mScrollY      = this->mScrollAdd - 153.0f;
            this->mScrollAdd    = 0.0f;
            this->mGameLayerRef->mFloorRef->addFloor();
        }
        else{
            this->mScrollY      = this->mScrollAdd - (153.0f * this->mScrollTime);
        }
        
        this->mGameLayerRef->setPosition(ccp(0, this->mScrollY));
    }
	
}

void CSGameScene::scrollDown(cocos2d::CCObject *pParam){
    this->mScrollAdd    = this->mScrollY;
    this->mIsScrolling  = true;
}

void CSGameScene::scrollUp(cocos2d::CCObject *pParam){
    
}

void CSGameScene::onExit()
{
    // Remove Notification
    CCNotificationCenter::sharedNotificationCenter()->removeObserver(this, NOTIFICATION_SCROLL_DOWN);
    CCNotificationCenter::sharedNotificationCenter()->removeObserver(this, NOTIFICATION_SCROLL_UP);
    this->unscheduleUpdate();
    CCLayer::onExit();
    
}

void CSGameScene::testScene(cocos2d::CCObject *pSender){
    CCDirector::sharedDirector()->replaceScene(CSSettingScene::scene(this->mUIRef->getUIData()));
}
