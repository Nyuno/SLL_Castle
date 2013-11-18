//
//  CSSettingScene.cpp
//  CSSettingScene
//
//  Created by 신 현호 on 13. 11. 3..
//
//

#include "CSSettingScene.h"
#include "CSGameScene.h"

//CCScene* CSSettingScene::scene(const UIDATA& ui){
//    CCScene* scene = CCScene::create();
//    CSSettingScene* layer = CSSettingScene::create(ui);
//    scene->addChild(layer);
//    return scene;
//}

//CSSettingScene* CSSettingScene::create(const UIDATA &ui){
//    CSSettingScene *pRet = new CSSettingScene();
//    if (pRet && pRet->init())
//    {
//        pRet->mUIData = ui;
//        pRet->autorelease();
//        return pRet;
//    }
//    else
//    {
//        delete pRet;
//        pRet = NULL;
//        return NULL;
//    }
//}

bool CSSettingScene::init(){
    if(!CCLayer::init()){
        return false;
    }
    
    this->mIsEnd = false;
    
    
    CCMenuItemFont::setFontName("Munro Small");
    CCMenuItemFont::setFontSize(18);
    
    SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic(SOUND_SETTING_SCENE::RESOURCE_SOUND[SOUND_SETTING_SCENE::SOUND_BGM]);
    SimpleAudioEngine::sharedEngine()->playBackgroundMusic(SOUND_SETTING_SCENE::RESOURCE_SOUND[SOUND_SETTING_SCENE::SOUND_BGM], true);
    
     CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("SettingScene/SettingScene.plist");
    
    this->mIndex = 0;
    this->mState = STATE_READY;
    
    this->setTouchEnabled(true);
    
    this->schedule(schedule_selector(CSSettingScene::update));
    
    
    CCSprite* sprite = GetSprite(IMAGE_SETTING_SCENE::RESOURCE_IMAGE[IMAGE_SETTING_SCENE::IMG_TITLE]);
    sprite->setPosition(ccp(160.0f, 284));
    this->addChild(sprite);
    
    sprite = GetSprite(IMAGE_SETTING_SCENE::RESOURCE_IMAGE[IMAGE_SETTING_SCENE::IMG_PLAYER_TITLE]);
    sprite->setPosition(ccp(160.0f - 1.0f, 384.0f + 1.0f));
    sprite->setTag(TAG_SIT);
    this->addChild(sprite);
    
    // Test Princess Sprite
    sprite = GetSprite(IMAGE_SETTING_SCENE::RESOURCE_IMAGE[IMAGE_SETTING_SCENE::IMG_PRINCESS_1]);
    sprite->setPosition(ccp(160.0f + 30.0f, 384.0f));
    this->addChild(sprite);
    sprite = GetSprite(IMAGE_SETTING_SCENE::RESOURCE_IMAGE[IMAGE_SETTING_SCENE::IMG_PRINCESS_2]);
    sprite->setPosition(ccp(160.0f + 60.0f, 384.0f));
    this->addChild(sprite);
    sprite = GetSprite(IMAGE_SETTING_SCENE::RESOURCE_IMAGE[IMAGE_SETTING_SCENE::IMG_PRINCESS_3]);
    sprite->setPosition(ccp(160.0f - 30.0f, 384.0f));
    this->addChild(sprite);
    sprite = GetSprite(IMAGE_SETTING_SCENE::RESOURCE_IMAGE[IMAGE_SETTING_SCENE::IMG_PRINCESS_4]);
    sprite->setPosition(ccp(160.0f - 60.0f, 384.0f));
    this->addChild(sprite);
    
    sprite = GetSprite(IMAGE_SETTING_SCENE::RESOURCE_IMAGE[IMAGE_SETTING_SCENE::IMG_TITLE_TEXT_JAPAN]);
    sprite->setPosition(ccp(160.0f, 510.0f));
    this->addChild(sprite);

    //Shop Test
    /*
    for(int i = 0; i < 4; ++i){
        sprite = GetSprite(IMAGE_SETTING_SCENE::RESOURCE_IMAGE[IMAGE_SETTING_SCENE::IMG_INVENTORY_BASIC]);
        sprite->setPosition(ccp(80 * (i + 1) - 40.0f, 568.0f - 40.0f - 44.0f));
        this->addChild(sprite);
    }
    sprite = GetSprite(IMAGE_SETTING_SCENE::RESOURCE_IMAGE[IMAGE_SETTING_SCENE::IMG_UI]);
    sprite->setPosition(ccp(160.0f, 568.0f - 22.0f));
    this->addChild(sprite);
    
    CCLabelTTF* label = CCLabelTTF::create("SHOP", "Munro Small", 20);
    label->setPosition(ccp(160.0f, 568.0f - 22.0f));
    this->addChild(label);
    */
    
    CCMenuItemFont* font = CCMenuItemFont::create("GameStart", this, menu_selector(CSSettingScene::nextScene));
    CCMenu* menu = CCMenu::create(font, NULL);
    menu->setPosition(ccp(160.0f, 540.0f));
    this->addChild(menu);
    
    
    
    return true;
}

void CSSettingScene::update(float dt){
    if(this->mIsEnd){
        CCScene* scene = CSGameScene::scene(this->mUIRef->getUIData());
        CCDirector::sharedDirector()->replaceScene(scene);
    }
    if(this->getChildByTag(TAG_GAMBLE) &&
       this->getChildByTag(TAG_GAMBLE_CLOSE) == NULL &&
       this->mGambleRef->isEnd() == true &&
       this->mGambleRef->chanceUsed() == true ){
        CCMenuItemFont* font = CCMenuItemFont::create("Close Gamble <- Click", this, menu_selector(CSSettingScene::closeGamble));
        CCMenu* menu = CCMenu::create(font, NULL);
        menu->setTag(TAG_GAMBLE_CLOSE);
        menu->setPosition(ccp(160.0f, 500.0f));
        this->addChild(menu);
    }
}


void CSSettingScene::ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent)
{
    CCSetIterator iter = pTouches->begin();
    for (; iter != pTouches->end(); iter++)
    {
        CCTouch* pTouch = (CCTouch*)(*iter);
        CCPoint point   = pTouch->getLocation();
        switch(this->mState){
            case STATE_READY:{
                break;
            }
            case STATE_SETTING: {
                if( (point.y - 44.0f) >= 0.0f &&
                   (point.y) <= 364.0f){
                    int x = (int)(point.x / 80.0f);
                    int y = abs(3 - (int)((point.y - 44.0f) / 80.0f));
                    this->mIndex = x + (y * 4);
                    CCLog("Touch Down %d : %d, index : %d", x, y, this->mIndex);
                    
                    this->mInventoryRef->selectItem(this->mIndex);
                }
                break;
            }
            case STATE_GAMBLE:{
                if( point.x >= POINT_GAMBLE.x &&
                   point.x <= POINT_GAMBLE.x + 240.0f &&
                   point.y >= POINT_GAMBLE.y &&
                   point.y <= POINT_GAMBLE.y + 400.0f){
                    int x = (int)((point.x - POINT_GAMBLE.x) / 80.0f);
                    int y = abs(4 - (int)((point.y - POINT_GAMBLE.y) / 80.0f));
                    int index = x + y * 3;
                    this->mGambleRef->clickDownCard(index);
                    
                    CCLOG("Gamble x : %d y : %d index : %d", x, y, index);
                }
                break;
            }
        }
    }
}

void CSSettingScene::onExit(){
    SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
    this->unscheduleUpdate();
    
    CCLayer::onExit();
}

void CSSettingScene::ccTouchesMoved(CCSet *pTouches, CCEvent *pEvent)
{
    CCSetIterator iter = pTouches->begin();
    for (; iter != pTouches->end(); iter++)
    {
        CCTouch* pTouch = (CCTouch*)(*iter);
        CCPoint point   = pTouch->getLocation();
        switch(this->mState){
            case STATE_READY:{
                break;
            }
            case STATE_SETTING: {
                this->mInventoryRef->setItemPosition(point);
                break;
            }
            case STATE_GAMBLE:{
                break;
            }
        }
    }
}

void CSSettingScene::ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent)
{
    CCSetIterator iter = pTouches->begin();
    for (; iter != pTouches->end(); iter++)
    {
        CCTouch* TouchRef = (CCTouch*)(*iter);
        CCPoint point = TouchRef->getLocation();
        switch(this->mState){
            case STATE_READY:{
                this->mState = STATE_SETTING;
                this->settingInit();
                break;
            }
            case STATE_SETTING: {
                if( (point.y - 44.0f) >= 0.0f &&
                   (point.y) <= 364.0f){
                    int x = (int)(point.x / 80.0f);
                    int y = abs(3 - (int)((point.y - 44.0f) / 80.0f));
                    this->mIndex = x + (y * 4);
                    CCLog("Touch Up %d : %d, index : %d", x, y, this->mIndex);
                    
                    this->mInventoryRef->moveItem(this->mIndex);
                }
                else{
                    this->mInventoryRef->cancelItem();
                }
                break;
            }
            case STATE_GAMBLE:{
                if( point.x >= POINT_GAMBLE.x &&
                    point.x <= POINT_GAMBLE.x + 240.0f &&
                    point.y >= POINT_GAMBLE.y &&
                    point.y <= POINT_GAMBLE.y + 400.0f){
                    int x = (int)((point.x - POINT_GAMBLE.x) / 80.0f);
                    int y = abs(4 - (int)((point.y - POINT_GAMBLE.y) / 80.0f));
                    int index = x + y * 3;
                    this->mGambleRef->clickUpCard(index);
                    
                    CCLOG("Gamble x : %d y : %d index : %d", x, y, index);
                }
                break;
            }
        }
    }
}

void CSSettingScene::ccTouchesCancelled(CCSet *pTouches, CCEvent *pEvent)
{
    ccTouchesEnded(pTouches, pEvent);
}

void CSSettingScene::settingInit(){
    
    CSUserInterface* ui = CSUserInterface::create(this->mUIData);
    ui->setTag(TAG_UI);
    this->addChild(ui);
    this->mUIRef = (CSUserInterface*)this->getChildByTag(TAG_UI);
    
    CSInventory* inven = CSInventory::create();
    inven->setTag(TAG_INVEN);
    this->addChild(inven);
    this->mInventoryRef = (CSInventory*)this->getChildByTag(TAG_INVEN);
    
    CCMenuItemFont* font = CCMenuItemFont::create("Gamble", this, menu_selector(CSSettingScene::createGamble));
    CCMenu* menu = CCMenu::create(font, NULL);
    menu->setPosition(ccp(50.0f, 400.0f));
    this->addChild(menu);
}

void CSSettingScene::createGamble(cocos2d::CCObject *pSender){
    if(!this->getChildByTag(TAG_GAMBLE)){
        Gamble* gamble = Gamble::create();
        gamble->setPosition(POINT_GAMBLE);
        gamble->setTag(TAG_GAMBLE);
        this->addChild(gamble);
        this->mGambleRef = (Gamble*)this->getChildByTag(TAG_GAMBLE);
        this->mState = STATE_GAMBLE;
    }
}

void CSSettingScene::closeGamble(cocos2d::CCObject *pSender){
    this->mUIRef->setGold(this->mUIRef->getGold() + this->mGambleRef->getMoney());
    if(this->getChildByTag(TAG_GAMBLE)){
        this->removeChildByTag(TAG_GAMBLE);
    }
    if(this->getChildByTag(TAG_GAMBLE_CLOSE)){
        this->removeChildByTag(TAG_GAMBLE_CLOSE);
    }
    this->mState = STATE_SETTING;
}

void CSSettingScene::nextScene(cocos2d::CCObject *pSender){
    this->mIsEnd = true;
}