//
//  CSGameScene.h
//  Castle
//
//  Created by Lee Byung Cheol on 2013. 11. 9..
//
//

#ifndef __Castle__CSGameScene__
#define __Castle__CSGameScene__

#include "cocos2d.h"
#include "SimpleAudioEngine.h"

#include "CSConstants.h"
#include "CSGameLayer.h"
#include "CSGameUILayer.h"
#include "CSUserInterface.h"

using namespace cocos2d;

class CSGameScene : public CCLayer{
public:
    virtual bool init();
	virtual void update(float dt);
    virtual void onExit();
    
    CREATE_FUNC(CSGameScene);
    CREATE_WITH_UIDATA_INIT_FUNC(CSGameScene);
    SCENE_WITH_UIDATA_FUNC(CSGameScene);
    
    void scrollDown(CCObject* pParam);
    void scrollUp(CCObject* pParam);
    
private:
	CSGameLayer*        mGameLayerRef;
    CSUserInterface*    mUIRef;
//	CSGameUILayer *uiLayer;
    
    float   mScrollY;
    float   mScrollAdd;
    float   mScrollTime;
    bool    mIsScrolling;
    
    void testScene(CCObject* pSender);

};


#endif /* defined(__Castle__CSGameScene__) */
