//
//  Animation.cpp
//  Castle
//
//  Created by 신 현호 on 13. 9. 14..
//
//

#include "Animation.h"

bool Animation::init(){
    if(!CCNode::init()){
        return false;
    }
    
    mSpriteNameRef  = NULL;
    mStartFrame     = 0;
    mMaxFrame       = 0;
    mCurrentFrame   = 0;
    mFrameTime      = 0.0f;
    mCurrentTime    = 0.0f;
    mLoop           = 0;
    mPosition       = ccp(0, 0);
    
    this->schedule(schedule_selector(Animation::update));

    return true;
}

void Animation::update(float dt){
    if(mLoop == 0)
        return;
    
    this->mCurrentTime += dt;
    
    if(this->mCurrentTime >= this->mFrameTime){
        this->mCurrentFrame++;
        
        if(this->mStartFrame + this->mCurrentFrame > this->mMaxFrame){
            if(this->mLoop == ONCE){
                this->removeChildByTag(TAG_SPRITE);
                this->mLoop = 0;
                this->mCurrentTime = 0.0f;
            }
        }
    }
}

void Animation::onExit(){
    this->unscheduleUpdate();
    
    CCNode::onExit();
}

void Animation::setAnimation(char* spriteRef, int startFrame, int maxFrame, float time, int loop){
    this->mSpriteNameRef    = spriteRef;
    this->mStartFrame       = startFrame;
    this->mMaxFrame         = maxFrame;
    this->mFrameTime        = time;
    this->mLoop             = loop;
    
    CCSprite* sprite        = GetSprite(spriteRef + startFrame);
    sprite->setTag(TAG_SPRITE);
    this->addChild(sprite);
}