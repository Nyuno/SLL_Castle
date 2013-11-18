//
//  CSGamble.h
//  SettingSceneTest
//
//  Created by Shin Hyun-Ho on 2013. 11. 11..
//
//

#ifndef __SettingSceneTest__CSGamble__
#define __SettingSceneTest__CSGamble__

#include "cocos2d.h"
#include "CSResources.h"

using namespace cocos2d;

#define POINT_MESSAGE ccp(160.0f, 410.0f)

enum{
    CARD_MONEY_SMALL = 0,
    CARD_MONEY_BIG,
    CARD_DOWN,
    CARD_JACKPOT,
    CARD_IS_NOT_SELECTED = 100,
    
    Z_ORDER_BASIC = 0,
    Z_ORDER_CARD,
    Z_ORDER_MESSAGE,
};

class Gamble : public CCNode{
public:
    virtual bool init();
    virtual void update(float dt);
    virtual void onExit();
    
    bool    selectCard(int index);
    bool    getRandom();
    bool    isEnd();
    bool    chanceUsed();
    int     getLevel();
    int     getMoney();
    void    clickDownCard(int index);
    void    clickUpCard(int index);
    
    CREATE_FUNC(Gamble);
    
private:
    int     mLevel;
    int     mSelect;
    int     mCard[15];
    int     mMoney;
    bool    mChanceUsed;
    bool    mIsEnd;
    bool    mIsRandoming;
    bool    mIsVisible;
    float   mTime;
    float   mTime2;
    
    void    random(CCObject *pSender);
    void    hideCard();
    void    viewCard();
    void    chance(CCObject *pSender);
    void    gameover(CCObject *pSender);
    
    CCLabelTTF* mLabelRef[15];
    
};


#endif /* defined(__SettingSceneTest__CSGamble__) */
