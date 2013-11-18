//
//  TestResource.h
//  AnamTower
//
//  Created by 신 현호 on 13. 8. 13..
//
//

#ifndef __AnamTower__TestResource__
#define __AnamTower__TestResource__

#include "cocos2d.h"

using namespace cocos2d;

#define TAG_SPRITE      1
#define SCALE_RESOURCE  0.826
#define TIME_SCROLL     0.3
 #define CENTER_POINT    (CCPoint( CCDirector::sharedDirector()->getWinSize().width / 2, CCDirector::sharedDirector()->getWinSize().height / 2))


#define RUN_TIME (1.0f/60.0f)

enum{
    LOOP = 1,
    ONCE,
};

extern float ScrollY;
extern float ScrollTime;
extern int ScrollCurrentFloor;
extern int ScrollFloor;

inline void scrollInit(){
    ScrollY                 = 0.0f;
    ScrollTime              = 0.0f;
    ScrollCurrentFloor      = 0;
    ScrollFloor             = 0;
}

inline void scroll(int currentFloor, int transFloor){
    ScrollCurrentFloor      = currentFloor;
    ScrollFloor             = transFloor;
}
inline void scrollUpdate(float dt){
    if(!ScrollFloor)
        return;
    
    ScrollTime += dt;
    
    if(ScrollTime >= TIME_SCROLL){
        ScrollTime              = 0.0f;
        ScrollCurrentFloor      += ScrollFloor;
        ScrollFloor             = 0;
        ScrollY                 = -(146 * (ScrollCurrentFloor - 1));
    }
    else{
        if(ScrollTime < 0.3f){
            ScrollY             = -(146 * (ScrollCurrentFloor - 1)) -
                                    (146  * (ScrollFloor) * (ScrollTime / 0.3f) * 1.0f);
        }
//        else if(ScrollTime < 0.8f){
//            ScrollY             = -(200 * 0.826 * (ScrollCurrentFloor - 1)) -
//            (200 * 0.826 * (ScrollFloor) * 0.8) - (200 * 0.826 * (ScrollFloor) * ((ScrollTime - 0.5f) / 0.3f) * 0.1f);
//        }
//        else{
//            ScrollY             = -(200 * (ScrollCurrentFloor - 1)) -
//            (200 * (ScrollFloor) * 0.9f) - (200 * (ScrollFloor) * ((ScrollTime - 0.3f) / 0.7f) * 0.1f);
//        }
    }
}

inline CCSprite* GetSprite(const char* fileName){
    CCSprite* sprite = new CCSprite();
    sprite->autorelease();
    
    //Search in the cache, first
    CCSpriteFrameCache* frameCacheRef = CCSpriteFrameCache::sharedSpriteFrameCache();
    CCSpriteFrame* spriteFrameRef = frameCacheRef->spriteFrameByName(fileName);
    if(spriteFrameRef){
        sprite->initWithSpriteFrame(spriteFrameRef);
        return sprite;
    }
    else{
        CCLOG("WARNING : %s not in a PACK!", fileName);
        sprite->initWithFile(fileName);
        return sprite;
    }
}

namespace IMAGE_GAME_STAGE{
    namespace MONSTER{
        typedef enum{
            IMG_STAND = 0,
            IMG_CRASH_1,
            IMG_CRASH_2,
            IMG_CRASH_3,
            IMG_CRASH_4,
            IMG_CRASH_5,
            IMG_DIE_1,
            IMG_DIE_2,
            IMG_DIE_3,
            IMG_DIE_4,
            IMG_DIE_5,
            IMG_DIE_6,
            IMG_DIE_7,
            IMG_DIE_8,
            IMG_DIE_9,
            IMG_DIE_10,
            IMG_MAX,
        }ResourceID[IMG_MAX];
    };
    
    namespace PLAYER{
        typedef enum{
            IMG_STAND = MONSTER::IMG_MAX,
            IMG_RUN_1,
            IMG_RUN_2,
            IMG_RUN_3,
            IMG_RUN_4,
            IMG_RUN_5,
            IMG_RUN_6,
            IMG_RUN_7,
            IMG_RUN_8,
            IMG_RUN_9,
            IMG_RUN_MAX,
            IMG_LIGHT_FRONT_STAND = IMG_RUN_MAX,
            IMG_LIGHT_FRONT_1,
            IMG_LIGHT_FRONT_2,
            IMG_LIGHT_FRONT_3,
            IMG_LIGHT_FRONT_4,
            IMG_LIGHT_FRONT_5,
            IMG_LIGHT_FRONT_6,
            IMG_LIGHT_FRONT_7,
            IMG_LIGHT_FRONT_8,
            IMG_LIGHT_FRONT_9,
            IMG_LIGHT_BACK_STAND,
            IMG_LIGHT_BACK_1,
            IMG_LIGHT_BACK_2,
            IMG_LIGHT_BACK_3,
            IMG_LIGHT_BACK_4,
            IMG_LIGHT_BACK_5,
            IMG_LIGHT_BACK_6,
            IMG_LIGHT_BACK_7,
            IMG_LIGHT_BACK_8,
            IMG_LIGHT_BACK_9,
            IMG_MAX,
        }ResourceID[IMG_MAX];
    };
    
    namespace OTHERS{
        typedef enum{
            IMG_WATER_1 = PLAYER::IMG_MAX,
            IMG_WATER_2,
            IMG_WATER_3,
            IMG_WATER_4,
            IMG_WATER_5,
            IMG_WATER_6,
            IMG_WATER_7,
            IMG_WATER_8,
            IMG_WATER_9,
            IMG_WATER_10,
            IMG_WATER_11,
            IMG_FIRE_1,
            IMG_FIRE_2,
            IMG_FIRE_3,
            IMG_BG_1,
            IMG_BG_2,
            IMG_MAX,
        }ResourceID[IMG_MAX];
    };
    
    
    extern const char* RESOURCE_IMAGE[];
};

namespace IMAGE_TEST {
    namespace RUN{
        typedef enum{
            IMG_RUN_1 = 0,
            IMG_RUN_2,
            IMG_RUN_3,
            IMG_RUN_4,
            IMG_RUN_5,
            IMG_RUN_6,
            IMG_RUN_7,
            IMG_MAX,
        }ResourceID[IMG_MAX];
    };
    namespace STOP{
        typedef enum{
            IMG_STOP_1 = RUN::IMG_MAX,
            IMG_STOP_2,
            IMG_STOP_3,
            RESOURCE_MAX,
            IMG_MAX = RESOURCE_MAX - RUN::IMG_MAX,
        }ResourceID[IMG_MAX];
    };
    namespace DOOR{
        typedef enum{
            IMG_DOOR_1 = STOP::RESOURCE_MAX,
            IMG_DOOR_2,
            IMG_DOOR_3,
            IMG_DOOR_4,
            RESOURCE_MAX,
            IMG_MAX = RESOURCE_MAX - STOP::IMG_MAX,
        }ResourceID[IMG_MAX];
    }
    namespace OTHERS{
        typedef enum{
            IMG_LOGO = DOOR::RESOURCE_MAX,
            IMG_DOOR_DOWN,
            IMG_DOOR_UP,
            IMG_FLOOR_1,
            IMG_FLOOR_N,
            IMG_HALL,
            RESOURCE_MAX,
            IMG_MAX = RESOURCE_MAX - DOOR::IMG_MAX,
        }ResourceID[IMG_MAX];
    }
    
    extern const char* RESOURCE_IMAGE[];
};

namespace SOUND_TEST {
    typedef enum{
        SOUND_RUN = 0,
        SOUND_DOOR,
        SOUND_BGM,
        SOUND_JUMP,
        SOUND_COIN,
        SOUND_CRASH,
        SOUND_MAX,
    }ResourceID[SOUND_MAX];
    
    extern const char* RESOURCE_SOUND[];
}

#endif /* defined(__AnamTower__TestResource__) */
