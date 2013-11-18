//
//  CSPlayer.cpp
//  Castle
//
//  Created by Lee Byung Cheol on 2013. 11. 10..
//
//

#include "CSPlayer.h"

#include "CSConstants.h"
#include "CSResources.h"

bool PlayerPiece::init(){
    if(!CCNode::init()){
        return false;
    }
    this->mIsRight = true;
    this->mFirstFrame = 0;
    
    return true;
}

void PlayerPiece::isRight(bool IsRight){
    this->mIsRight = IsRight;
}

void PlayerPiece::setFrame(int frame){
    SAFE_REMOVE_CHILD(TAG_SPRITE);
    CCSprite* sprite = GetSprite(IMAGE_GROUND_STAGE::RESOURCE_IMAGE[this->mFirstFrame + frame]);
    if(this->mIsRight){
        sprite->setRotationY(360.0f);
    }
    else{
        sprite->setRotationY(-180.0f);
    }
    sprite->setTag(TAG_SPRITE);
    this->addChild(sprite);
}

void PlayerPiece::initFrame(int frame){
    this->mFirstFrame = frame;
}


bool CSPlayer::init()
{
	if (!CCNode::init()) {
		return false;
	}
    
//    SimpleAudioEngine::sharedEngine()->preloadEffect(SOUND_TEST::RESOURCE_SOUND[SOUND_TEST::SOUND_JUMP]);
//    SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic(SOUND_TEST::RESOURCE_SOUND[SOUND_TEST::SOUND_BGM]);
//    SimpleAudioEngine::sharedEngine()->playBackgroundMusic(SOUND_TEST::RESOURCE_SOUND[SOUND_TEST::SOUND_BGM], true);
    
//    this->mTexCount = 0;
    
//    CCSprite* sprite = CCSprite::createWithTexture(this->mTex[0]);
//    sprite->setTag(ID_SPRITE);
//    this->addChild(sprite);
//    this->mSpriteRef = (CCSprite*)this->getChildByTag(ID_SPRITE);
    
//    this->setAnimation(STATE_RUN_RIGHT);
    
    PlayerPiece* Body = PlayerPiece::create();
    Body->initFrame(IMAGE_GROUND_STAGE::IMG_CHAR_BODY_01);
    Body->setTag(TAG_PIECE_BODY);
    this->addChild(Body);
    
    PlayerPiece* Boots = PlayerPiece::create();
    Boots->initFrame(IMAGE_GROUND_STAGE::IMG_CHAR_BOOTS_01);
    Boots->setTag(TAG_PIECE_BOOTS);
    this->addChild(Boots);
    
    PlayerPiece* Helmet = PlayerPiece::create();
    Helmet->initFrame(IMAGE_GROUND_STAGE::IMG_CHAR_HELMET_01);
    Helmet->setTag(TAG_PIECE_HELMET);
    this->addChild(Helmet);
    
    for(int i = 0; i < 3; ++i)
        this->mPieceRef[i] = (PlayerPiece*)this->getChildByTag(TAG_PIECE_BODY + i);
	
	this->mVelocity.x = 200;
    this->mFrameTime = 0.0f;
    this->mFrame = 0;
    this->mIsRight = true;
	
	this->schedule(schedule_selector(CSPlayer::update));
    
    return true;
}

void CSPlayer::update(float dt)
{
	updatePosition(dt);
    updateAnimation(dt);
}

void CSPlayer::onExit()
{
	this->unscheduleUpdate();
    CCNode::onExit();
}

void CSPlayer::updatePosition(float dt)
{
	switch (mState) {
		case STATE_RUN:

			break;
			
		case STATE_JUMP:
		case STATE_DOUBLE_JUMP:
			mVelocity.y -= 4000.0f * dt;
			
			break;
			
		default:
			
			break;
	}
	mPosition = mPosition + (mVelocity * dt);
	
	if (mPosition.y < 0) {
		mPosition.y = 0;
		mVelocity.y = 0;
		mVelocity.x = 200.0f;
		mState = STATE_RUN;
	}
    
    for(int i = 0; i < 3; ++i){
        this->mPieceRef[i]->setPosition(ccp(mPosition.x, 153.0f + 11.0f + 34.0f + mPosition.y));
    }
	
	if (mState == STATE_RUN && this->mPosition.x < -5.0f) {
		this->mVelocity.x = -this->mVelocity.x;
        if(this->mIsRight)
            this->mIsRight = false;
        else
            this->mIsRight = true;
        for(int i = 0; i < 3; ++i){
            this->mPieceRef[i]->isRight(this->mIsRight);
        }
        
        this->mPosition.y += 153.0f;
        CCNotificationCenter::sharedNotificationCenter()->postNotification(NOTIFICATION_SCROLL_DOWN);
	}
	
	if ((this->mPosition.x > 330.0f && this->mVelocity.x > 0) || (this->mPosition.x < -5.0f && this->mVelocity.x < 0)) {
		this->mVelocity.x = -this->mVelocity.x;
        if(this->mIsRight)
            this->mIsRight = false;
        else
            this->mIsRight = true;
        for(int i = 0; i < 3; ++i){
            this->mPieceRef[i]->isRight(this->mIsRight);
        }
        
        
        this->mPosition.y += 153.0f;
        CCNotificationCenter::sharedNotificationCenter()->postNotification(NOTIFICATION_SCROLL_DOWN);
	}
}

void CSPlayer::updateAnimation(float dt){
    this->mFrameTime += dt;
    if(this->mFrameTime >= TIME_ANIMATION){
        this->mFrameTime = 0.0f;
        for(int i = 0; i < 3; ++i){
            this->mPieceRef[i]->setFrame(this->mFrame);
        }
        this->mFrame++;
        if(this->mFrame == 10)
            this->mFrame = 0;
    }
}

void CSPlayer::jump()
{
	switch (mState) {
		case STATE_RUN:
			mState = STATE_JUMP;
			mVelocity.y = 800.0f;
			break;
			
		case STATE_JUMP:
			mState = STATE_DOUBLE_JUMP;
			mVelocity.y = 800.0f;
			mVelocity.x = 300.0f;
			break;
			
		default:
			break;
	}
}

CCRect CSPlayer::getBoundingBox()
{
	CCRect rect;
    
	rect.setRect(this->getPositionX(), this->getPositionY(), 77.0f, 68.0f);

	return rect;
}

bool CSPlayer::isDown()
{
	return mVelocity.y < 0;
}