//
//  CSUserInterface.cpp
//  SettingScene
//
//  Created by 신 현호 on 13. 11. 3..
//
//

#include "CSUserInterface.h"

static std::string fontList[] = { "Munro Small" };

CSUserInterface::CSUserInterface(){
    
}

CSUserInterface::~CSUserInterface(){
    CCLog("CSUserInterface OUT");
}

CSUserInterface* CSUserInterface::create(const UIDATA &ui){
    CSUserInterface *pRet = new CSUserInterface();
    if (pRet && pRet->init())
    {
        pRet->setGold(ui.mGold);
        pRet->setPower(ui.mPower);
        pRet->setHeart(ui.mHeart);
        pRet->setLevel(ui.mLevel);
        pRet->autorelease();
        return pRet;
    }
    else
    {
        delete pRet;
        pRet = NULL;
        return NULL;
    }
}

bool CSUserInterface::init(){
    if(!CCNode::init()){
        return false;
    }
    this->schedule(schedule_selector(CSUserInterface::update));
    
    this->mGold     = 50;
    this->mPower    = 10;
    this->mHeart    = 5;
    this->mLevel    = 1;
    this->mId       = TAG_EFFECT;
    
    CCSprite* sprite = GetSprite(IMAGE_SETTING_SCENE::RESOURCE_IMAGE[IMAGE_SETTING_SCENE::IMG_UI]);
    sprite->setPosition(ccp(160.0f, 22.0f));
    this->addChild(sprite);
    
    // Heart♥︎♡
    
    // Power
    char str[256];
    sprintf(str, "%d", this->mPower);
    CCLabelTTF *label       = CCLabelTTF::create(str, "Munro Small", 24);
    label->setAnchorPoint(ccp(0, 0.5));
    label->setColor(ccc3(0.0f, 100.0f, 255.0f));
    label->setPosition(POINT_POWER);
    label->setTag(TAG_POWER);
    this->addChild(label);
    
    // Gold
    sprintf(str, "%d", this->mGold);
    label = CCLabelTTF::create(str, "Munro Small", 24);
    label->setAnchorPoint(ccp(0, 0.5));
    label->setColor(ccc3(250.0f, 250.0f, 100.0f));
    label->setPosition(POINT_GOLD);
    label->setTag(TAG_GOLD);
    this->addChild(label);
    
    // Test Menu;
    CCMenuItemFont::setFontName(fontList[0].c_str());
    CCMenuItemFont::setFontSize(18);
    CCMenuItemFont* font = CCMenuItemFont::create("+Gold", this, menu_selector(CSUserInterface::testGold));
    font->setColor(ccc3(0.0f, 255.0f, 0.0f));
    CCMenuItemFont* font2 = CCMenuItemFont::create("+Power", this, menu_selector(CSUserInterface::testPower));
    font2->setColor(ccc3(0.0f, 100.0f, 255.0f));
    font2->setPosition(ccp(0.0f, 20.0f));
    CCMenu* menu = CCMenu::create(font, font2, NULL);
    menu->setPosition(160.0f, 22.0f);
    this->addChild(menu);
    
    
    return true;
}

void CSUserInterface::update(float dt){
    for(CSUserInterface::EffectTable::iterator itr = this->mContainer.begin(); itr != this->mContainer.end(); ){
        EFFECT* effect = (*itr);
        effect->mTime += dt;
        if(effect->mTime >= 1.0f){
            if(this->getChildByTag(effect->mId))
                this->removeChildByTag(effect->mId);
            effect->mLabelRef = NULL;
            CSUserInterface::EffectTable::iterator itr2 = itr - 1;
            if((*(itr))){
                delete (*(itr));
            }
            this->mContainer.erase(itr);
            itr = itr2 + 1;
        }
        else{
            effect->mLabelRef->setOpacity(255.0f - (255.0f * effect->mTime));
            switch(effect->mType){
                case TAG_GOLD:
                    effect->mLabelRef->setPosition(ccp(POINT_EFFECT_GOLD.x, POINT_EFFECT_GOLD.y + (20.0f * effect->mTime)));
                    break;
                case TAG_POWER:
                    effect->mLabelRef->setPosition(ccp(POINT_EFFECT_POWER.x, POINT_EFFECT_POWER.y + (20.0f * effect->mTime)));
                    break;
                case TAG_HEART:
                    break;
                case TAG_LEVEL:
                    break;
            }
            ++itr;
        }
    }
    
}

void CSUserInterface::onExit(){
    this->unscheduleUpdate();
    
    CCNode::onExit();
}

void CSUserInterface::setGold(int gold){
    if(this->getChildByTag(TAG_GOLD)){
        char str[256];
        sprintf(str, "+ %d", gold - this->mGold);
        CCLabelTTF* label = CCLabelTTF::create(str, fontList[0].c_str(), 20);
        label->setPosition(POINT_EFFECT_GOLD);
        label->setTag(this->mId);
        label->setColor(ccc3(250.0f, 250.0f, 100.0f));
        this->addChild(label);
        
        EFFECT* effect = new EFFECT((CCLabelTTF*)this->getChildByTag(this->mId), 0.0f, this->mId++, TAG_GOLD);
        this->mContainer.push_back(effect);
        
        this->mGold = gold;
        
        sprintf(str, "%d", this->mGold);
        ((CCLabelTTF*)this->getChildByTag(TAG_GOLD))->setString(str);
    }
    else{
        this->mGold = gold;
    }
}

int CSUserInterface::getGold(){
    return this->mGold;
}

void CSUserInterface::setPower(int power){
    if(this->getChildByTag(TAG_POWER)){
        char str[256];
        sprintf(str, "+ %d", power - this->mPower);
        CCLabelTTF* label = CCLabelTTF::create(str, fontList[0].c_str(), 20);
        label->setPosition(POINT_EFFECT_POWER);
        label->setTag(this->mId);
        label->setColor(ccc3(0.0f, 100.0f, 255.0f));
        this->addChild(label);
        
        EFFECT* effect = new EFFECT((CCLabelTTF*)this->getChildByTag(this->mId), 0.0f, this->mId++, TAG_POWER);
        this->mContainer.push_back(effect);

        this->mPower = power;
        
        sprintf(str, "%d", this->mPower);
        ((CCLabelTTF*)this->getChildByTag(TAG_POWER))->setString(str);
    }
    else{
        this->mPower = power;
    }
}

int CSUserInterface::getPower(){
    return this->mPower;
}

void CSUserInterface::setHeart(int heart){
    this->mHeart = heart;
    if(this->getChildByTag(TAG_HEART)){
        char str[256];
        sprintf(str, "%d", this->mHeart);
        ((CCLabelTTF*)this->getChildByTag(TAG_HEART))->setString(str);
    }
}

int CSUserInterface::getHeart(){
    return this->mHeart;
}

void CSUserInterface::setLevel(int level){
    this->mLevel = level;
    if(this->getChildByTag(TAG_LEVEL)){
        char str[256];
        sprintf(str, "%d", this->mLevel);
        ((CCLabelTTF*)this->getChildByTag(TAG_LEVEL))->setString(str);
    }
}

int CSUserInterface::getLevel(){
    return this->mLevel;
}

void CSUserInterface::testGold(CCObject* pSender){
    this->setGold(this->getGold() + 5);
}

void CSUserInterface::testPower(cocos2d::CCObject *pSender){
    this->setPower(this->getPower() + 5);
}

UIDATA CSUserInterface::getUIData(){
    UIDATA ui;
    ui.mPower   = this->mPower;
    ui.mHeart   = this->mHeart;
    ui.mGold    = this->mGold;
    ui.mLevel   = this->mLevel;
    return ui;
}