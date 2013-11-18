//
//  CSSettingScene.h
//  CSSettingScene
//
//  Created by 신 현호 on 13. 11. 3..
//
//

#ifndef __CSSettingScene__CSSettingScene__
#define __CSSettingScene__CSSettingScene__

#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "CSResources.h"
#include "CSConstants.h"
#include "CSUserInterface.h"
#include "CSInventory.h"
#include "CSGamble.h"
using namespace cocos2d;
using namespace CocosDenshion;

#define POINT_GAMBLE ccp(30.0f, 40.0f)


class CSSettingScene : public CCLayer{
public:
    virtual bool init();
    virtual void update(float dt);
    virtual void onExit();
    
    CREATE_WITH_UIDATA_FUNC(CSSettingScene);
    SCENE_WITH_UIDATA_FUNC(CSSettingScene);
//    static CCScene* scene(const UIDATA& ui);
//    static CSSettingScene* create(const UIDATA& ui);
    CREATE_FUNC(CSSettingScene);
    
    
    
    virtual void ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);
    virtual void ccTouchesMoved(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);
    virtual void ccTouchesEnded(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);
    virtual void ccTouchesCancelled(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);
    
private:
    bool                mIsEnd;
    int                 mIndex;
    int                 mState;
    CSInventory*        mInventoryRef;
    CSUserInterface*    mUIRef;
    UIDATA              mUIData;
    Gamble*             mGambleRef;
    
    void settingInit();
    void createGamble(CCObject *pSender);
    void closeGamble(CCObject *pSender);
    void nextScene(CCObject *pSender);
};

#endif /* defined(__CSSettingScene__CSSettingScene__) */
