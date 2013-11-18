//
//  CSConstants.h
//  Castle
//
//  Created by Lee Byung Cheol on 2013. 11. 10..
//
//

#ifndef __Castle__CSConstants__
#define __Castle__CSConstants__

#define SAFE_REMOVE_CHILD(tag) \
    if(this->getChildByTag(tag)){ \
        this->removeChildByTag(tag); \
    }

#define CREATE_WITH_UIDATA_INIT_FUNC(_type) \
static _type* create(const UIDATA &ui){ \
    _type *pRet = new _type(); \
    if (pRet && pRet->init()) \
    { \
        pRet->mUIRef->setGold(ui.mGold); \
        pRet->mUIRef->setHeart(ui.mHeart); \
        pRet->mUIRef->setPower(ui.mPower); \
        pRet->mUIRef->setLevel(ui.mLevel); \
        pRet->autorelease(); \
        return pRet; \
    } \
    else \
    { \
        delete pRet; \
        pRet = NULL; \
        return NULL; \
    } \
} \

#define CREATE_WITH_UIDATA_FUNC(_type) \
static _type* create(const UIDATA &ui){ \
    _type *pRet = new _type(); \
    if (pRet && pRet->init()) \
    { \
        pRet->mUIData = ui; \
        pRet->autorelease(); \
        return pRet; \
    } \
    else \
    { \
        delete pRet; \
        pRet = NULL; \
        return NULL; \
    } \
} \

#define SCENE_WITH_UIDATA_FUNC(_type) \
static CCScene* scene(const UIDATA& ui){ \
    CCScene* scene = CCScene::create(); \
    _type* layer = _type::create(ui); \
    scene->addChild(layer); \
    return scene; \
} \

// Time
#define TIME_ANIMATION      1.0f / 60.0f
#define TIME_SCROLL         0.5f

// Notification
#define NOTIFICATION_SCROLL_DOWN    "ScrollDown"
#define NOTIFICATION_SCROLL_UP      "ScrollUp"

enum {
    STATE_READY = 0,
    STATE_SETTING,
    STATE_GAMBLE,
    
    TAG_FLOOR_1 = 0,
    TAG_FLOOR_2,
    TAG_FLOOR_3,
    TAG_FLOOR_4,
    TAG_FLOOR_5,
    TAG_FLOOR_6,
    TAG_FLOOR_7,
    TAG_FLOOR_8,
    TAG_FLOOR_9,
    TAG_FURNITURE_1,
    TAG_FURNITURE_2,
    TAG_FURNITURE_3,
    
    TAG_SKY,
    TAG_BG,
    TAG_FURNITURE,
    TAG_LABEL,
    TAG_PLAYER,
    TAG_LOGO,
    TAG_SIT,
    TAG_UI,
    TAG_GAME_LAYER,
    TAG_INVEN,
    TAG_GAMBLE,
    TAG_GAMBLE_CLOSE,
    TAG_PIECE_BODY,
    TAG_PIECE_BOOTS,
    TAG_PIECE_HELMET,
    
    Z_ORDER_SKY,
    Z_ORDER_FLOOR,
    Z_ORDER_FURNITURE,
    Z_ORDER_LABEL,
};

enum{
    PATTERN_1 = 0,
    PATTERN_2,
    PATTERN_3,
    PATTERN_4,
    PATTERN_MAX,
    
    TAG_FLOOR = 0,
};

enum {/*
    STATE_RUN_LEFT = -1,
    STATE_JUMP_LEFT = -2,
    STATE_RUN_RIGHT = 1,
    STATE_JUMP_RIGHT,
    STATE_STOP,
    STATE_STAND,
    
    STATE_LIGHT_NULL,
    STATE_LIGHT_FRONT,
    STATE_LIGHT_BACK,
    */
    ID_SPRITE,
    ID_SPRITE_LIGHT,
    
    LOOP_LOOP,
    LOOP_ONCE,
    
    PALETTE_HEAD_GREEN = 0,
    PALETTE_HEAD_BLUE,
    PALETTE_BODY_GREEN,
    PALETTE_BODY_RED,
    PALETTE_LEG_RED,
    PALETTE_LEG_BLUE,
};

#define BACKGOUND_ERASE \
if(iData[i*4] == 255 && \
iData[i*4 + 1] == 255 && \
iData[i*4 + 2] == 255){ \
iData[i*4 + 3] = 0; \
}

#define HEAD_BLUE  \
if(iData[i*4] == 137 && \
iData[i*4 + 1] == 0 && \
iData[i*4 + 2] == 0){ \
iData[i*4]      = 13; \
iData[i*4 + 1]  = 64; \
iData[i*4 + 2]  = 85; \
} \
else if(iData[i*4] == 255 && \
iData[i*4 + 1] == 76 && \
iData[i*4 + 2] == 22){ \
iData[i*4]      = 58; \
iData[i*4 + 1]  = 144; \
iData[i*4 + 2]  = 238; \
} \
else if(iData[i*4]      == 255 && \
iData[i*4 + 1]  == 32 && \
iData[i*4 + 2]  == 32){ \
iData[i*4]      = 58; \
iData[i*4 + 1]  = 144; \
iData[i*4 + 2]  = 255; \
}

#define HEAD_GREEN  \
if(iData[i*4] == 137 && \
iData[i*4 + 1] == 0 && \
iData[i*4 + 2] == 0){ \
iData[i*4]      = 19; \
iData[i*4 + 1]  = 67; \
iData[i*4 + 2]  = 2; \
} \
else if(iData[i*4] == 255 && \
iData[i*4 + 1] == 76 && \
iData[i*4 + 2] == 22){ \
iData[i*4]      = 57; \
iData[i*4 + 1]  = 210; \
iData[i*4 + 2]  = 53; \
} \
else if(iData[i*4]      == 255 && \
iData[i*4 + 1]  == 32 && \
iData[i*4 + 2]  == 32){ \
iData[i*4]      = 57; \
iData[i*4 + 1]  = 220; \
iData[i*4 + 2]  = 53; \
}

#define BODY_RED  \
if(iData[i*4] == 13 && \
iData[i*4 + 1] == 64 && \
iData[i*4 + 2] == 85){ \
iData[i*4]      = 137; \
iData[i*4 + 1]  = 0; \
iData[i*4 + 2]  = 0; \
} \
else if(iData[i*4] == 58 && \
iData[i*4 + 1] == 144 && \
iData[i*4 + 2] == 238){ \
iData[i*4]      = 255; \
iData[i*4 + 1]  = 76; \
iData[i*4 + 2]  = 22; \
} \
else if(iData[i*4]      == 7 && \
iData[i*4 + 1]  == 43 && \
iData[i*4 + 2]  == 45){ \
}

#define BODY_GREEN  \
if(iData[i*4] == 13 && \
iData[i*4 + 1] == 64 && \
iData[i*4 + 2] == 85){ \
iData[i*4]      = 57; \
iData[i*4 + 1]  = 150; \
iData[i*4 + 2]  = 53; \
} \
else if(iData[i*4] == 58 && \
iData[i*4 + 1] == 144 && \
iData[i*4 + 2] == 238){ \
iData[i*4]      = 57; \
iData[i*4 + 1]  = 250; \
iData[i*4 + 2]  = 53; \
} \
else if(iData[i*4]      == 7 && \
iData[i*4 + 1]  == 43 && \
iData[i*4 + 2]  == 45){ \
}

#define LEG_RED \
if(iData[i*4]      == 19 && \
iData[i*4 + 1]  == 67 && \
iData[i*4 + 2]  == 2){ \
iData[i*4]      = 137; \
iData[i*4 + 1]  = 0; \
iData[i*4 + 2]  = 0; \
} \
else if(iData[i*4]      == 57 && \
iData[i*4 + 1]  == 197 && \
iData[i*4 + 2]  == 53){ \
iData[i*4]      = 255; \
iData[i*4 + 1]  = 76; \
iData[i*4 + 2]  = 22; \
}

#define LEG_BLUE \
if(iData[i*4]      == 19 && \
iData[i*4 + 1]  == 67 && \
iData[i*4 + 2]  == 2){ \
iData[i*4]      = 7; \
iData[i*4 + 1]  = 43; \
iData[i*4 + 2]  = 45; \
} \
else if(iData[i*4]      == 57 && \
iData[i*4 + 1]  == 197 && \
iData[i*4 + 2]  == 53){ \
iData[i*4]      = 58; \
iData[i*4 + 1]  = 144; \
iData[i*4 + 2]  = 238; \
}

#endif /* defined(__Castle__CSConstants__) */
