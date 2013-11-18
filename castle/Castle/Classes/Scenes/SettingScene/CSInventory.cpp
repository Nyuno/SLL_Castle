//
//  CSInventory.cpp
//  SettingScene
//
//  Created by 신 현호 on 13. 11. 5..
//
//

#include "CSInventory.h"

bool CSInventory::init(){
    if(!CCNode::init()){
        return false;
    }
    
    this->setContentSize(CCSize(320.0f, 80.0f * (float)INDEX_Y_MAX));
    this->setAnchorPoint(ccp(0, 0));
    this->setPosition(ccp(0.0f, 44.0f));
    this->schedule(schedule_selector(CSInventory::update));
    
    this->mIndex        = INDEX_IS_NOT_SELECTED;
    
    CCSprite* sprite    = GetSprite(IMAGE_SETTING_SCENE::RESOURCE_IMAGE[IMAGE_SETTING_SCENE::IMG_INVENTORY_ITEM]);
    sprite->setPosition(ccp(120.0f, 320.0f - 40.0f + 1.0f));
    this->addChild(sprite);
    
    sprite              = GetSprite(IMAGE_SETTING_SCENE::RESOURCE_IMAGE[IMAGE_SETTING_SCENE::IMG_WASTEBASKET_CLOSE]);
    sprite->setPosition(ccp(240.0f + 40.0f, 320.0f - 40.0f));
    sprite->setTag(TAG_WASTEBASKET);
    this->addChild(sprite);
    
    for(int i = 0; i < INDEX_MAX; ++i){
        if(i < 3){
            this->mItem[i]  = INDEX_IS_NOT_SELECTED;
        }
        this->mInventory[i] = INDEX_IS_NOT_SELECTED;
            sprite = GetSprite(IMAGE_SETTING_SCENE::RESOURCE_IMAGE[IMAGE_SETTING_SCENE::IMG_INVENTORY_BASIC]);
            sprite->setPosition(ccp((80 * (i%4 + 1) - 40.0f), 240.0f - 40.0f - (80 * (i/4))));
            this->addChild(sprite);
    }
    
    // ITEM_TEST_1
    ITEM table = ITEM(IMAGE_SETTING_SCENE::RESOURCE_IMAGE[IMAGE_SETTING_SCENE::IMG_ITEM_ENCHANT_1], "", 0, 0, 1, ITEM_ENCHANT);
    this->mContainer.insert(pair<int, ITEM>(ITEM_TEST_1, table));
    
    //Add Sprite
    sprite = GetSprite(table.mSpriteName);
    sprite->setTag(ITEM_TEST_1);
    sprite->setPosition(ccp((80 * (0 + 1) - 40.0f), 240.0f - 40.0f - (80 * (0/4))));
    this->addChild(sprite);
    this->mInventory[0] = ITEM_TEST_1;
    
    CCLabelTTF* label = CCLabelTTF::create("+ 10~30%", "Munro Small", 18);
    label->setPosition(ccp((80 * (0 + 1) - 40.0f), 240.0f - 40.0f - (80 * (0/4))));
    this->addChild(label);
    
    // ITEM_TEST_2
    table = ITEM(IMAGE_SETTING_SCENE::RESOURCE_IMAGE[IMAGE_SETTING_SCENE::IMG_ITEM_HELMET_1], "", 0, 0, 1, ITEM_HELMET);
    this->mContainer.insert(pair<int, ITEM>(ITEM_TEST_2, table));
    
    //Add Sprite
    sprite = GetSprite(table.mSpriteName);
    sprite->setTag(ITEM_TEST_2);
    sprite->setPosition(ccp((80 * (1 + 1) - 40.0f), 240.0f - 40.0f - (80 * (1/4))));
    this->addChild(sprite);
    this->mInventory[1] = ITEM_TEST_2;
    
    
    
    return true;
}

void CSInventory::update(float dt){
    
}

void CSInventory::onExit(){
    this->unscheduleUpdate();
    
    CCNode::onExit();
}

void CSInventory::selectItem(int index){
    if(index < 3){
        this->mIndex = ITEM_HELMET + index;
    }
    else if(index < (INDEX_MAX + 4) &&
       index > 3){
        this->mIndex        = index - 4;
    }
    else{
        this->mIndex        = INDEX_IS_NOT_SELECTED;
    }
}

void CSInventory::moveItem(int index){
    int itemIndex;
    if(this->mIndex == INDEX_IS_NOT_SELECTED ||
       index        >= (INDEX_MAX + 4)){
        return;
    }
    else if(index < 3){
        itemIndex       = ITEM_HELMET + index;
    }
    else if(index == 3){
        itemIndex       = TAG_WASTEBASKET;
    }
    else{
        itemIndex       = index - 4;
    }
    
    
    if(this->mIndex == itemIndex){
        this->cancelItem();
        return;
    }
    
    // Select Item
    if(this->mIndex >= ITEM_HELMET){
        // Delete
        if(itemIndex == TAG_WASTEBASKET){
            if(this->getChildByTag(this->mItem[this->mIndex - ITEM_HELMET])){
                this->removeChildByTag(this->mItem[this->mIndex - ITEM_HELMET]);
            }
            this->mIndex    = INDEX_IS_NOT_SELECTED;
            this->closeWastebasket();
            return;
        }
        else if(itemIndex >= ITEM_HELMET){
            this->cancelItem();
            return;
        }
        else if(this->mInventory[itemIndex] == INDEX_IS_NOT_SELECTED){
            if(this->getChildByTag(this->mItem[this->mIndex - ITEM_HELMET])){
                this->getChildByTag(this->mItem[this->mIndex - ITEM_HELMET])->setPosition((ccp((80 * (itemIndex%4 + 1) - 40.0f), 240.0f - 40.0f - (80 * (itemIndex/4)))));
            }
            this->mInventory[itemIndex]             = this->mItem[this->mIndex - ITEM_HELMET];
            this->mItem[this->mIndex - ITEM_HELMET] = INDEX_IS_NOT_SELECTED;
        }
        else{
            CSInventory::ITEMTABLE::iterator itr2 = this->mContainer.find(this->mInventory[itemIndex]);
            if(this->mIndex == itr2->second.mType){
                if(this->getChildByTag(this->mItem[this->mIndex - ITEM_HELMET])){
                    this->getChildByTag(this->mItem[this->mIndex - ITEM_HELMET])->setPosition((ccp((80 * (itemIndex%4 + 1) - 40.0f), 240.0f - 40.0f - (80 * (itemIndex/4)))));
                }
                if(this->getChildByTag(this->mInventory[itemIndex])){
                    this->getChildByTag(this->mInventory[itemIndex])->setPosition((ccp((80 * ((this->mIndex - ITEM_HELMET) + 1) - 40.0f), 320.0f - 40.0f)));
                }
                int temp                                = this->mItem[this->mIndex - ITEM_HELMET];
                this->mItem[this->mIndex - ITEM_HELMET] = this->mInventory[itemIndex];
                this->mInventory[itemIndex]             = temp;
            }
            else{
                this->cancelItem();
                return;
            }
        }
    }
    // Select Inventory
    else{
        
        // Delete
        if(itemIndex == TAG_WASTEBASKET){
            if(this->getChildByTag(this->mInventory[this->mIndex])){
                this->removeChildByTag(this->mInventory[this->mIndex]);
            }
            this->mIndex    = INDEX_IS_NOT_SELECTED;
            this->closeWastebasket();
            return;
        }
        // Set Item
        else if(itemIndex >= ITEM_HELMET){
            CSInventory::ITEMTABLE::iterator itr = this->mContainer.find(this->mInventory[this->mIndex]);
            if(itr->second.mType == itemIndex){
                if(this->getChildByTag(this->mInventory[this->mIndex])){
                    this->getChildByTag(this->mInventory[this->mIndex])->setPosition((ccp((80 * ((itemIndex - ITEM_HELMET) + 1) - 40.0f), 320.0f - 40.0f)));
                }
                if(this->getChildByTag(this->mItem[itemIndex - ITEM_HELMET])){
                    this->getChildByTag(this->mItem[itemIndex - ITEM_HELMET])->setPosition((ccp((80 * (this->mIndex%4 + 1) - 40.0f), 240.0f - 40.0f - (80 * (this->mIndex/4)))));
                }
                int temp                                = this->mInventory[this->mIndex];
                this->mInventory[this->mIndex]          = this->mItem[itemIndex - ITEM_HELMET];
                this->mItem[itemIndex - ITEM_HELMET]    = temp;
            }
            else{
                this->cancelItem();
                return;
            }
        }
        // Change
        else{
            if(this->getChildByTag(this->mInventory[this->mIndex])){
                this->getChildByTag(this->mInventory[this->mIndex])->setPosition((ccp((80 * (itemIndex%4 + 1) - 40.0f), 240.0f - 40.0f - (80 * (itemIndex/4)))));
            }
            if(this->getChildByTag(this->mInventory[itemIndex])){
                this->getChildByTag(this->mInventory[itemIndex])->setPosition((ccp((80 * (this->mIndex%4 + 1) - 40.0f), 240.0f - 40.0f - (80 * (this->mIndex/4)))));
            }
            int temp                        = this->mInventory[this->mIndex];
            this->mInventory[this->mIndex]  = this->mInventory[itemIndex];
            this->mInventory[itemIndex]     = temp;
        }
    }
    
    this->mIndex                    = INDEX_IS_NOT_SELECTED;
    this->closeWastebasket();
}

void CSInventory::setItemPosition(cocos2d::CCPoint &position){
    if(this->mIndex != INDEX_IS_NOT_SELECTED &&
       this->getChildByTag(this->mInventory[this->mIndex])){
        this->getChildByTag(this->mInventory[this->mIndex])->setPosition(ccp(position.x, position.y - 40.0f));
    }
    
    int x = (int)(position.x / 80.0f);
    int y = abs(3 - (int)((position.y - 44.0f) / 80.0f));
    int index = x + (y * 4);
    if(index == 3){
        this->openWastebasket();
    }
    else{
        this->closeWastebasket();
    }
    
}

void CSInventory::openWastebasket(){
    if(this->getChildByTag(TAG_WASTEBASKET)){
        this->removeChildByTag(TAG_WASTEBASKET);
    }
    
    CCSprite* sprite = GetSprite(IMAGE_SETTING_SCENE::RESOURCE_IMAGE[IMAGE_SETTING_SCENE::IMG_WASTEBASKET_OPEN]);
    sprite->setPosition(ccp(240.0f + 40.0f, 320.0f - 40.0f));
    sprite->setTag(TAG_WASTEBASKET);
    this->addChild(sprite);
    
}

void CSInventory::closeWastebasket(){
    if(this->getChildByTag(TAG_WASTEBASKET)){
        this->removeChildByTag(TAG_WASTEBASKET);
    }
    
    CCSprite* sprite = GetSprite(IMAGE_SETTING_SCENE::RESOURCE_IMAGE[IMAGE_SETTING_SCENE::IMG_WASTEBASKET_CLOSE]);
    sprite->setPosition(ccp(240.0f + 40.0f, 320.0f - 40.0f));
    sprite->setTag(TAG_WASTEBASKET);
    this->addChild(sprite);
    
}

void CSInventory::cancelItem(){
    int index;
    if(this->mIndex >= ITEM_HELMET){
        index       = this->mIndex - ITEM_HELMET;
    }
    else{
        index       = this->mIndex + 4;
    }
    if(this->getChildByTag(this->mInventory[this->mIndex]))
        this->getChildByTag(this->mInventory[this->mIndex])->setPosition(ccp((80 * (index%4 + 1) - 40.0f), 320.0f - 40.0f - (80 * (index/4))));
    this->mIndex        = INDEX_IS_NOT_SELECTED;
    this->closeWastebasket();
}