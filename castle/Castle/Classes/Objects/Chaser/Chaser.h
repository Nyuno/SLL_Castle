//
//  Chaser.h
//  Castle
//
//  Created by 이 대성 on 13. 10. 17..
//
//

#ifndef __Castle__Chaser__
#define __Castle__Chaser__

#include "cocos2d.h"
#include "TestResource.h"
#define CHASER_HEIGHT 50
#define CHASER_WIDTH  60

using namespace cocos2d;
namespace CHASER_CONST
{
    enum{
        STATE_RUN_LEFT = -1,
        STATE_JUMP_LEFT = -2,
        STATE_RUN_RIGHT = 1,
        STATE_JUMP_RIGHT,

        STATE_LIGHT_NULL,
        STATE_LIGHT_FRONT,
        STATE_LIGHT_BACK,
        
        ID_SPRITE,
        ID_SPRITE_LIGHT,
        
        DIRECTION_LEFT = -1,
        DIRECTION_RIGHT= 1,
    };
}

class ChaseMonster : public CCNode{
private:
    CCPoint mPos;
    int mDirection;
    int mFloor;
    int mFirstIndex;
    int mFrameMax;
public:
    virtual bool init();
    virtual void update(float dt);
    virtual void OnExit();
    CREATE_FUNC(ChaseMonster);
};


class Chaser : public CCNode{
private:
    CCPoint mPos;
    int mV;
    int mChaserNum;
    ChaseMonster* recentMonster;
public:
    virtual bool init();
    virtual void update(float dt);
    virtual void onExit();
    CCRect getBounding();
    CREATE_FUNC(Chaser);
    
    ChaseMonster* addChaser();
    
};


#endif /* defined(__Castle__Chaser__) */
