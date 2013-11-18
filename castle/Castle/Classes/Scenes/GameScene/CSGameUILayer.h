//
//  CSGameUILayer.h
//  Castle
//
//  Created by Lee Byung Cheol on 2013. 11. 10..
//
//

#ifndef __Castle__CSGameUILayer__
#define __Castle__CSGameUILayer__

#include "cocos2d.h"
#include "CSUserInterface.h"

using namespace cocos2d;

class CSGameUILayer : public CCLayer {
public:
	virtual bool init();
	virtual void update(float dt);
    virtual void onExit();
	
	CREATE_FUNC(CSGameUILayer);

private:
	CSUserInterface* mUIRef;
	
};

#endif /* defined(__Castle__CSGameUILayer__) */
