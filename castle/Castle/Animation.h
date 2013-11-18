//
//  Animation.h
//  Castle
//
//  Created by 신 현호 on 13. 9. 14..
//
//

#ifndef __Castle__Animation__
#define __Castle__Animation__

#include "cocos2d.h"
#include "TestResource.h"

using namespace cocos2d;

class Animation : public CCNode{
public:
    virtual bool init();
    virtual void update(float dt);
    virtual void onExit();
    
    void setAnimation(char* spriteRef, int startFrame, int maxFrame, float time, int loop);
    
    CREATE_FUNC(Animation);

private:
    char*   mSpriteNameRef;
    int     mStartFrame;
    int     mMaxFrame;
    int     mCurrentFrame;
    float   mFrameTime;
    float   mCurrentTime;
    CCPoint mPosition;
    int     mLoop;
};


#endif /* defined(__Castle__Animation__) */
