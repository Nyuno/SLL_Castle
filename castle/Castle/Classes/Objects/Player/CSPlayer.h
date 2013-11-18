//
//  CSPlayer.h
//  Castle
//
//  Created by Lee Byung Cheol on 2013. 11. 10..
//
//

#ifndef __Castle__CSPlayer__
#define __Castle__CSPlayer__

#include <string>
#include "cocos2d.h"




#define JUMP_VELOCITY 30

enum {
	STATE_RUN = 0,
	STATE_JUMP,
	STATE_JUMP_STOP,
	STATE_DOUBLE_JUMP
};

enum {
	DIRECTION_LEFT = -1,
	DIRECTION_RIGHT = 1
};


using namespace std;
using namespace cocos2d;

class PlayerPiece : public CCNode{
public:
    virtual bool init();
    
    CREATE_FUNC(PlayerPiece);
    
//    void set
    void isRight(bool IsRight);
    void setFrame(int frame);
    void initFrame(int frame);
    
private:
    bool    mIsRight;
    int     mFirstFrame;
    
};

class CSPlayer : public CCNode {
public:
	virtual bool init();
    virtual void update(float dt);
    virtual void onExit();
	
	CREATE_FUNC(CSPlayer);
	
	CCRect getBoundingBox();
	bool isDown();
	void jump();
	
private:
    int mFrame;
	int mState;
	int mDirection;
	CCPoint mPosition;
	CCPoint mVelocity;
	float mJumpTime;
    float mFrameTime;
    bool mIsRight;
	
	void updatePosition(float dt);
    void updateAnimation(float dt);
	
	// test
    int             mTexCount;
    PlayerPiece*    mPieceRef[3];
};

#endif /* defined(__Castle__CSPlayer__) */
