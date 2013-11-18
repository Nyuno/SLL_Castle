//
//  CSUserInterface.h
//  SettingScene
//
//  Created by 신 현호 on 13. 11. 3..
//
//

#ifndef __SettingScene__CSUserInterface__
#define __SettingScene__CSUserInterface__

#include "cocos2d.h"
using namespace cocos2d;
using namespace std;

#include "CSResources.h"

enum{
    TAG_GOLD = 0,
    TAG_POWER,
    TAG_HEART,
    TAG_LEVEL,
    TAG_EFFECT = 1000,
};

#define POINT_POWER         ccp(70.0f, 23.0f)
#define POINT_GOLD          ccp(320.0f - 60.0f, 23.0f)
#define POINT_EFFECT_GOLD   ccp(POINT_GOLD.x    + 20.0f, POINT_GOLD.y   + 10.0f)
#define POINT_EFFECT_POWER  ccp(POINT_POWER.x   + 20.0f, POINT_POWER.y  + 10.0f)

typedef struct _effect{
    CCLabelTTF* mLabelRef;
    float       mTime;
    int         mId;
    int         mType;
    
    _effect(CCLabelTTF* labelRef, float time, int _id, int type){
        mLabelRef       = labelRef;
        mTime           = time;
        mId             = _id;
        mType           = type;
    }
    ~_effect(){
        mLabelRef       = NULL;
        mTime           = 0.0f;;
        mId             = 0;
        mType           = 0;
    }
}EFFECT;

typedef struct uidata{
    int mGold;
    int mPower;
    int mHeart;
    int mLevel;
}UIDATA;


class CSUserInterface : public CCNode{
public:
    CSUserInterface();
    ~CSUserInterface();
    virtual bool init();
    virtual void update(float dt);
    virtual void onExit();
    
    CREATE_FUNC(CSUserInterface);
    static CSUserInterface* create(const UIDATA &ui);
    
    void    setGold(int gold);
    int     getGold();
    void    setPower(int power);
    int     getPower();
    void    setHeart(int heart);
    int     getHeart();
    void    setLevel(int level);
    int     getLevel();
    UIDATA  getUIData();
    
    typedef vector<EFFECT*> EffectTable;
    
private:
    int mGold;
    int mPower;
    int mHeart;
    int mLevel;
    int mId;
    
    EffectTable mContainer;
    
    void testGold(CCObject* pSender);
    void testPower(CCObject* pSender);
};

#endif /* defined(__SettingScene__UI__) */
