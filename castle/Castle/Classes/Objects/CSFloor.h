//
//  CSFloor.h
//  Castle
//
//  Created by Lee Byung Cheol on 2013. 11. 10..
//
//

#ifndef __Castle__CSFloor__
#define __Castle__CSFloor__

#include "cocos2d.h"

#include "CSMonster.h"

#include <vector>

using namespace cocos2d;

class GroundFloor : public CCNode{
public:
    virtual bool init();
    
    CREATE_FUNC(GroundFloor);
    
    void reset(int floor);
    void setFloor(int floor);
    
private:
    CCLabelTTF*     mFloorTestRef;
    
    void initFloor();
};

class CSFloor : public CCNode {
public:
	virtual bool init();
    virtual void update(float dt);
    virtual void onExit();
    
//    void setFloor(int floor);
    void addFloor();
	
	CREATE_FUNC(CSFloor);
	
private:
    GroundFloor* mGroundFloorRef[5];
    int mFloor;
};

#endif /* defined(__Castle__CSFloor__) */
