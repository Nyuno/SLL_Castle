//
//  CSResources.h
//  Castle
//
//  Created by Lee Byung Cheol on 2013. 11. 10..
//
//

#ifndef __Castle__CSResources__
#define __Castle__CSResources__

#include "cocos2d.h"
#include "CSConstants.h"

using namespace cocos2d;

#define TAG_SPRITE      1
#define SCALE_RESOURCE  0.826
#define CENTER_POINT    (CCPoint( CCDirector::sharedDirector()->getWinSize().width / 2, CCDirector::sharedDirector()->getWinSize().height / 2))


#define RUN_TIME (1.0f/60.0f)

enum{
    LOOP = 1,
    ONCE,
};

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

namespace IMAGE_SETTING_SCENE {
    typedef enum{
        IMG_UI = 0,
        IMG_TITLE,
        IMG_PRINCESS_1,
        IMG_PRINCESS_2,
        IMG_PRINCESS_3,
        IMG_PRINCESS_4,
        IMG_TITLE_TEXT_JAPAN,
        IMG_ITEM_ENCHANT_1,
        IMG_ITEM_HELMET_1,
        IMG_INVENTORY_BASIC,
        IMG_INVENTORY_ITEM,
        IMG_PLAYER_TITLE,
        IMG_WASTEBASKET_OPEN,
        IMG_WASTEBASKET_CLOSE,
        IMG_MAX,
    }ResourceID[IMG_MAX];
    
    extern const char* RESOURCE_IMAGE[IMG_MAX];
};

namespace IMAGE_GROUND_STAGE {
    typedef enum{
        IMG_MONSTER_01 = 0,
        IMG_MONSTER_02,
        IMG_MONSTER_03,
        IMG_MONSTER_04,
        IMG_MONSTER_05,
        IMG_MONSTER_06,
        IMG_MONSTER_07,
        IMG_MONSTER_08,
        IMG_MONSTER_09,
        IMG_MONSTER_10,
        IMG_MONSTER_11,
        IMG_MONSTER_12,
        IMG_MONSTER_13,
        IMG_MONSTER_14,
        IMG_MONSTER_15,
        IMG_MONSTER_16,
        IMG_BG_DRAWER,
        IMG_BG_WARDROBE,
        IMG_BG_FLOOR_1,
        IMG_BG_FLOOR_2,
        IMG_BG_FLOOR_3,
        IMG_BG_FLOOR_4,
        IMG_BG_SKY,
        IMG_CHAR_BODY_01,
        IMG_CHAR_BODY_02,
        IMG_CHAR_BODY_03,
        IMG_CHAR_BODY_04,
        IMG_CHAR_BODY_05,
        IMG_CHAR_BODY_06,
        IMG_CHAR_BODY_07,
        IMG_CHAR_BODY_08,
        IMG_CHAR_BODY_09,
        IMG_CHAR_BODY_10,
        IMG_CHAR_BOOTS_01,
        IMG_CHAR_BOOTS_02,
        IMG_CHAR_BOOTS_03,
        IMG_CHAR_BOOTS_04,
        IMG_CHAR_BOOTS_05,
        IMG_CHAR_BOOTS_06,
        IMG_CHAR_BOOTS_07,
        IMG_CHAR_BOOTS_08,
        IMG_CHAR_BOOTS_09,
        IMG_CHAR_BOOTS_10,
        IMG_CHAR_HELMET_01,
        IMG_CHAR_HELMET_02,
        IMG_CHAR_HELMET_03,
        IMG_CHAR_HELMET_04,
        IMG_CHAR_HELMET_05,
        IMG_CHAR_HELMET_06,
        IMG_CHAR_HELMET_07,
        IMG_CHAR_HELMET_08,
        IMG_CHAR_HELMET_09,
        IMG_CHAR_HELMET_10,
        IMG_BG_DRESSING_TABLE,
        IMG_MAX,
    }ResourceID[IMG_MAX];
    
    extern const char* RESOURCE_IMAGE[IMG_MAX];
}

namespace SOUND_SETTING_SCENE {
    typedef enum{
        SOUND_BGM = 0,
        SOUND_MAX,
    }ResourceID[SOUND_MAX];
    
    extern const char* RESOURCE_SOUND[SOUND_MAX];
}

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

#endif /* defined(__Castle__CSResources__) */
