//
//  Chaser.cpp
//  Castle
//
//  Created by 이 대성 on 13. 10. 17..
//
//
#include "Chaser.h"

//ChaserMonster code

bool ChaseMonster::init()
{
    if(!CCNode::init())
    {
        return false;
    }
    //this->mDirection = ;
    //this->mFloor = ;
    this->schedule(schedule_selector(ChaseMonster::update));
    
    CCSprite* sprite = GetSprite(IMAGE_GAME_STAGE::RESOURCE_IMAGE[IMAGE_GAME_STAGE::MONSTER::IMG_STAND]);
    sprite->setTag(CHASER_CONST::ID_SPRITE);
    this->addChild(sprite);
    sprite->setPosition(ccp(CCRANDOM_0_1()*CHASER_WIDTH, 0));
    
    this->setPosition(0.0f, 0.0f);
    mFirstIndex     = 0;
    mFrameMax       = 0;
    return true;
}

void ChaseMonster::update(float dt)
{

}

void ChaseMonster::OnExit()
{
    this->unscheduleUpdate();
    CCNode::onExit();
}

//Chaser code

bool Chaser::init(){
    if(!CCNode::init())
    {
        return false;
    }
    
    this->schedule(schedule_selector(Chaser::update));
    this->setPosition(ccp(0,0));
    
    mPos        = ccp(-150.0f, -30.0f);
    mV          = 3;
    
    mChaserNum  = 0;
    
    return true;
}

void Chaser::update(float dt)
{
    //this->mTime += dt;
    
    this->mPos.x += this->mV;
    this->setPosition(mPos.x, mPos.y);
    //if(this->getChildByTag(TAG_SPRITE))
        //this->getChildByTag(TAG_SPRITE)->setPosition(ccp(this->mPos.x, this->mPos.y));
    
    //first, if go to right// second, if go to left
    if(this->mPos.x > CENTER_POINT.x || this->mPos.x < -CENTER_POINT.x ){
        //this->mFloor++;
        //this->mPos.y        = (int)(146.0f * (this->mFloor - 1)-30.0f);
        
        //this->mDirection    *= -1;
        this->mV            *= -1;
        
        //this->mCrash = false;
        
        //for(int i = 0; i < mChaserNum; i++)
        //{
        //    if(this->getChildByTag(i))
        //    {
        //        if(this->mDirection == CHASER_CONST::STATE_RUN_RIGHT)
        //            ((CCSprite*)this->getChildByTag(i)->getChildByTag(CHASER_CONST::ID_SPRITE))->setFlipX(true);
        //        else
        //            ((CCSprite*)this->getChildByTag(i)->getChildByTag(CHASER_CONST::ID_SPRITE))->setFlipX(false);
        //    }
        //}
        //if(this->mDirection == CHASER_CONST::STATE_RUN_RIGHT)
        //    this->mPos.x        = -CENTER_POINT.x;
        //else
        //    this->mPos.x        = CENTER_POINT.x;
    }
}

void Chaser::onExit()
{
    this->unscheduleUpdate();
    CCNode::onExit();
}

CCRect Chaser::getBounding()
{
    CCRect rect;
    rect.setRect(this->getPosition().x, this->getPosition().y, CHASER_WIDTH, CHASER_HEIGHT);
    return rect;
}

ChaseMonster* Chaser::addChaser()
{
    ChaseMonster* monster = ChaseMonster::create();
    //if(this->mDirection == CHASER_CONST::STATE_RUN_RIGHT)
    //    ((CCSprite*)monster->getChildByTag(CHASER_CONST::ID_SPRITE))->setFlipX(true);
    this->addChild(monster, 0, mChaserNum++);
    return monster;
}

