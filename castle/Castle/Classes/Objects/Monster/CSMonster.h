//
//  CSMonster.h
//  Castle
//
//  Created by Lee Byung Cheol on 2013. 11. 10..
//
//

#ifndef __Castle__CSMonster__
#define __Castle__CSMonster__

#include "cocos2d.h"

using namespace cocos2d;

enum{
    MONSTER_STATE_STAND = 0,
    MONSTER_STATE_CRASH,
    MONSTER_STATE_DIE,
};

class Goblin : public CCNode{
public:
    virtual bool init();
    virtual void update(float dt);
    virtual void onExit();
    
    CREATE_FUNC(Goblin);
    
    void addGoblin();
    void crash();
private:
    int mFirstFrame;
    int mCurrentFrame;
    int mState;
    int mLife;
    float mFrameTime;
    
    CCLabelTTF* mLabelRef;
    CCSprite*   mSpriteRef;
};

class GoblinFloor : public CCNode{
public:
    virtual bool init();
    
    CREATE_FUNC(GoblinFloor);
    
    CCRect*     getBoundingBox();
    int         getGoblinNum();
    
    void        crashGoblin(int num, int power);
private:
    Goblin*     mGoblinRef[3];
    int         mGoblinNum;
};

class CSMonster : public CCNode {
public:
	virtual bool init();
    virtual void update(float dt);
    virtual void onExit();
	
	CREATE_FUNC(CSMonster);
	
	CCRect* getBoundingBox();
    void    crashMonster(int num, int power);
	
	void jump();
	
private:
    int             mFloor;
    GoblinFloor*    mFloorRef[6];
};


#endif /* defined(__Castle__CSMonster__) */
