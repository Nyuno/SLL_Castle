//
//  CSGameLayer.h
//  Castle
//
//  Created by Lee Byung Cheol on 2013. 11. 10..
//
//

#ifndef __Castle__CSGameLayer__
#define __Castle__CSGameLayer__

#include "cocos2d.h"

#include <vector>
#include "CSPlayer.h"
#include "CSFloor.h"

using namespace cocos2d;

class CSGameLayer : public CCLayer {
public:
	virtual bool init();
	virtual void update(float dt);
    virtual void onExit();
	virtual void ccTouchesBegan(CCSet *pTouches, CCEvent* event);
    virtual void ccTouchesEnded(CCSet *pTouches, CCEvent* event);
	
	CREATE_FUNC(CSGameLayer);
    
    
	CSFloor* mFloorRef;
	
private:
	CSPlayer* player;
	std::vector<CSMonster *> monsters;

	void checkCollision();
	
};

#endif /* defined(__Castle__CSGameLayer__) */
