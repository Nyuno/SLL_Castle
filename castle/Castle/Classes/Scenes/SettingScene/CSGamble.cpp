//
//  CSGamble.cpp
//  SettingSceneTest
//
//  Created by Shin Hyun-Ho on 2013. 11. 11..
//
//

#include "CSGamble.h"

bool Gamble::init(){
    if(!CCNode::init()){
        return false;
    }
    
    srand(time(NULL));
    
    this->schedule(schedule_selector(Gamble::update));
    this->setAnchorPoint(ccp(0, 0));
    
    for(int i = 0; i < 15; ++i) {
        if(i == 14)
            this->mCard[i] = CARD_JACKPOT;
        else
            this->mCard[i] = i%3;
        
        CCSprite* sprite = GetSprite(IMAGE_SETTING_SCENE::RESOURCE_IMAGE[IMAGE_SETTING_SCENE::IMG_INVENTORY_BASIC]);
        sprite->setTag(i);
        sprite->setPosition(ccp((80 * (i % 3 + 1) - 40.0f), 400.0f - 40.0f - (80 * (i / 3))));
        this->addChild(sprite, Z_ORDER_BASIC);
        
        CCLabelTTF* label;
        switch (this->mCard[i]) {
            case CARD_MONEY_SMALL:
                label = CCLabelTTF::create("$Small$", "Munro Small", 18);
                break;
            case CARD_MONEY_BIG:
                label = CCLabelTTF::create("$Big$", "Munro Small", 18);
                break;
            case CARD_DOWN:
                label = CCLabelTTF::create("!!Down!!", "Munro Small", 18);
                break;
            case CARD_JACKPOT:
                label = CCLabelTTF::create("$$$$$$$$$$\n$JACKPOT$\n$$$$$$$$$$", "Munro Small", 18);
                break;
        }
        this->mCard[i] = i + 15;
        label->setTag(i + 15);
        label->setPosition(ccp((80 * (i % 3 + 1) - 40.0f), 400.0f - 40.0f - (80 * (i / 3))));
        this->addChild(label, Z_ORDER_CARD);
    }
    
    this->mLevel        = 0;
    this->mSelect       = CARD_IS_NOT_SELECTED;
    this->mChanceUsed   = false;
    this->mIsEnd        = false;
    this->mIsRandoming  = false;
    this->mIsVisible    = true;
    this->mTime         = 3.0f;
    this->mTime2        = 0.0f;
    
    CCLabelTTF* label   = CCLabelTTF::create("3", "Munro Small", 18);
    label->setTag(30);
    label->setPosition(POINT_MESSAGE);
    this->addChild(label);
    
    label = CCLabelTTF::create("Gamble Message : ", "Munro Small", 20);
    label->setPosition(ccp(POINT_MESSAGE.x - 100.0f, POINT_MESSAGE.y));
    this->addChild(label);
    
    return true;
}

void Gamble::onExit(){
    this->unscheduleUpdate();
    
    CCNode::onExit();
}

void Gamble::update(float dt){
    if(this->mLevel == 0){
        if(this->mTime >= 0.0f){
            this->mTime -= dt;
            CCLabelTTF* label = (CCLabelTTF*)this->getChildByTag(30);
            label->setColor(ccc3(rand() % 255, rand() % 255, rand() % 255));
            if(this->mTime >= 1.0f &&
               this->mTime <= 2.0f){
                label->setString("2");
            }
            else if(this->mTime >= 0.0f &&
                    this->mTime <= 1.0f){
                label->setString("1");
            }
        }
        else{
            this->mTime = 0.0f;
            this->mLevel++;
            this->random(NULL);
        }
    }
    
    if(this->mIsRandoming){
        int index = this->mLevel - 1;
        
        if(this->mTime >= 0.5f){
            
            if(this->mTime2 == 0.0f){
                this->mTime     = 0.5f;
                this->mTime2    += dt;
                this->getChildByTag(0 + (index * 3))->setPosition(ccp(120.0f    ,400.0f - 40.0f - (80 * index)));
                this->getChildByTag(2 + (index * 3))->setPosition(ccp(120.0f    ,400.0f - 40.0f - (80 * index)));
            }
            else if(this->mTime2 < 0.5f){
                this->mTime2 += dt;
            }
            else{
                this->mTime += dt;
                
            }
        }
        else{
            this->mTime     += dt;
        }
        
        if(this->mTime > 1.0f){
            this->mIsRandoming  = false;
            this->mTime         = 0.0f;
            this->mTime2        = 0.0f;
            this->viewCard();
            
            this->getChildByTag(0 + (index * 3))->setPosition(ccp(40.0f     ,400.0f - 40.0f - (80 * index)));
            this->getChildByTag(2 + (index * 3))->setPosition(ccp(200.0f    ,400.0f - 40.0f - (80 * index)));
        }
        else{
            this->getChildByTag(0 + (index * 3))->setPosition(ccp(40.0f     + (160.0f * this->mTime)    ,400.0f - 40.0f - (80 * index)));
            this->getChildByTag(2 + (index * 3))->setPosition(ccp(200.0f    - (160.0f * this->mTime)    ,400.0f - 40.0f - (80 * index)));
        }
    }
    
    for(int i = this->mLevel - 1 ; i < 5; ++i){
        CCLabelTTF* label = (CCLabelTTF*)this->getChildByTag(17 + (i * 3));
        if(this->mLevel == i + 1)
            label->setColor(ccc3(255, 255, 255));
        else
            label->setColor(ccc3(rand()%255, rand()%255, rand()%255));
    }
}

bool Gamble::selectCard(int index){
    if(this->mIsRandoming   == true ||
       this->mLevel         == 0)
        return false;
    
    if( (index / 3 + 1) == this->mLevel){
        
        
        return true;
    }
    else{
        return false;
    }
}

void Gamble::random(CCObject *pSender){
    if(!this->mIsRandoming){
        this->hideCard();
        this->mIsRandoming      = true;
        this->mMoney            = 0;
        this->mTime             = 0.0f;
        this->mTime2            = 0.0f;
//        this->mLevel            = 1;
        
        if(this->getChildByTag(30))
            this->removeChildByTag(30);
        
        CCLabelTTF* label = CCLabelTTF::create("Game Start!", "Munro Small", 18);
        label->setTag(30);
        label->setPosition(ccp(POINT_MESSAGE.x + 10.0f, POINT_MESSAGE.y));
        this->addChild(label);
        
        int level               = (this->mLevel - 1) * 3;
        int temp                = this->mCard[level + 0];
        int rannum              = rand() %3;
        
        if(rannum == 0)
            return;
        
        this->mCard[level + 0]          = this->mCard[level + rannum];
        this->mCard[level + rannum]     = this->mCard[level + 3 - rannum];
        this->mCard[level + 3 - rannum] = temp;
        
        if(this->getChildByTag(this->mCard[level + 0]))
            this->getChildByTag(this->mCard[level + 0])->setPosition(ccp((80 * 1 - 40.0f), 400.0f - 40.0f - (80 * (this->mLevel - 1))));
        if(this->getChildByTag(this->mCard[level + 1]))
            this->getChildByTag(this->mCard[level + 1])->setPosition(ccp((80 * 2 - 40.0f), 400.0f - 40.0f - (80 * (this->mLevel - 1))));
        if(this->getChildByTag(this->mCard[level + 2]))
            this->getChildByTag(this->mCard[level + 2])->setPosition(ccp((80 * 3 - 40.0f), 400.0f - 40.0f - (80 * (this->mLevel - 1))));
    }
}

void Gamble::hideCard(){
    this->mIsVisible        = false;
    
    for(int i = 0; i < 3; ++i) {
        if(this->getChildByTag(15 + (this->mLevel - 1) * 3 + i))
            this->getChildByTag(15 + (this->mLevel - 1) * 3 + i)->setVisible(this->mIsVisible);
    }
}

void Gamble::viewCard(){
    this->mIsVisible        = true;
    CCLabelTTF* label;
    
    for(int i = 0; i < 3; ++i){
        int index   = this->mCard[(this->mLevel - 1) * 3 + i];
        label = (CCLabelTTF*)this->getChildByTag(index);
        label->setVisible(this->mIsVisible);
        if(!this->mIsEnd){
            label->setString("Click");
            if(this->mLevel > 1){
                int index2  = this->mCard[(this->mLevel - 2) * 3 + i];
                label = (CCLabelTTF*)this->getChildByTag(index2);
                switch(index2 % 3){
                    case CARD_MONEY_SMALL:
                        label->setString("$Small$");
                        break;
                    case CARD_MONEY_BIG:
                        label->setString("$Big$");
                        break;
                    case CARD_DOWN:
                    label->setString("!!Down!!");
                        break;
                }
            }
        }
        else{
            label = (CCLabelTTF*)this->getChildByTag(index);
            switch(index % 3){
                case CARD_MONEY_SMALL:
                    label->setString("$Small$");
                    break;
                case CARD_MONEY_BIG:
                    label->setString("$Big$");
                    break;
                case CARD_DOWN:
                    if(this->mLevel == 5)
                        label->setString("$$$$$$$$$\n$JACKPOT$\n$$$$$$$$$$");
                    else
                        label->setString("!!Down!!");
                    break;
            }
        }
    }
}

void Gamble::clickDownCard(int index){
    if(this->mIsRandoming   == true ||
       this->mLevel         == 0 ||
       this->mIsEnd         == true)
        return;
    
    if( (index / 3 + 1) == this->mLevel){
        this->mSelect       = index;
        
    }
    else{
        this->mSelect       = CARD_IS_NOT_SELECTED;
    }
    
}

void Gamble::clickUpCard(int index){
    if(this->mIsRandoming   == true ||
       this->mLevel         == 0 ||
       this->mIsEnd         == true)
        return;
    
    if( (index / 3 + 1) == this->mLevel &&
        this->mSelect   == index){
        CCLabelTTF* label;
        char str[50];
        switch((this->mCard[this->mSelect] - 15) % 3){
            case CARD_MONEY_SMALL:
                this->mMoney = this->mLevel;
                sprintf(str, "%d Gold!", this->mMoney);
                this->mIsEnd = true;
                this->viewCard();
                break;
            case CARD_MONEY_BIG:
                this->mMoney = this->mLevel * 5;
                sprintf(str, "%d Gold!", this->mMoney);
                this->mIsEnd = true;
                this->viewCard();
                break;
            case CARD_DOWN:
                if(this->mLevel == 5){
                    sprintf(str, "JACKPOT!!");
                    this->mIsEnd = true;
                    this->mChanceUsed = true;
                    this->mMoney = 500;
                }
                else{
                    sprintf(str, "!Down");
                    if(this->mLevel == 4){
                        label = (CCLabelTTF*)this->getChildByTag(29);
                        label->setColor(ccc3(0, 0, 0));
                    }
                    this->mLevel++;
                    this->viewCard();
                    this->random(NULL);
                }
                break;
        }
        
        label = CCLabelTTF::create(str, "Munro Small", 18);
        label->setColor(ccc3(250, 250, 210));
        label->setTag(30);
        label->setPosition(POINT_MESSAGE);
        if(this->getChildByTag(30))
            this->removeChildByTag(30);
        this->addChild(label);
        
        if(this->mIsEnd == true &&
           this->mLevel != 5 &&
           this->mChanceUsed == false){
            label = CCLabelTTF::create("ReGame?", "Munro Small", 20);
            label->setPosition(ccp(POINT_MESSAGE.x - 100.0f, POINT_MESSAGE.y + 50.0f));
            label->setTag(31);
            this->addChild(label, Z_ORDER_MESSAGE);
            
            CCMenuItemFont* font = CCMenuItemFont::create("Yes", this, menu_selector(Gamble::chance));
            CCMenuItemFont* font2 = CCMenuItemFont::create("No", this, menu_selector(Gamble::gameover));
            font2->setPosition(ccp(30.0f, 0.0f));
            CCMenu* menu = CCMenu::create(font, font2, NULL);
            menu->setPosition(ccp(POINT_MESSAGE.x, POINT_MESSAGE.y + 50.0f));
            menu->setTag(32);
            this->addChild(menu);
        }
    }
    else{
        this->mSelect       = CARD_IS_NOT_SELECTED;
    }
    
}

bool Gamble::getRandom(){
    return this->mIsRandoming;
}

void Gamble::chance(CCObject *pSender){
    this->mIsEnd = false;
    this->mChanceUsed = true;
    this->random(NULL);
    
    for(int i = 0; i < 2; ++i){
        if(this->getChildByTag(31 + i))
            this->removeChildByTag(31 + i);
    }
}

void Gamble::gameover(CCObject *pSender){
    this->mIsEnd = true;
    this->mChanceUsed = true;
    
    for(int i = 0; i < 2; ++i){
        if(this->getChildByTag(31 + i))
            this->removeChildByTag(31 + i);
    }
}

bool Gamble::isEnd(){
    return this->mIsEnd;
}

bool Gamble::chanceUsed(){
    return this->mChanceUsed;
}

int Gamble::getLevel(){
    return this->mLevel;
}

int Gamble::getMoney(){
    return this->mMoney;
}