//
//  CSInventory.h
//  SettingScene
//
//  Created by 신 현호 on 13. 11. 5..
//
//

#ifndef __SettingScene__CSInventory__
#define __SettingScene__CSInventory__

#include "cocos2d.h"
#include <map>
using namespace cocos2d;
using namespace std;

#include "CSResources.h"

#define INDEX_X_MAX             3
#define INDEX_Y_MAX             4
#define INDEX_MAX               INDEX_X_MAX * INDEX_Y_MAX
#define INDEX_IS_NOT_SELECTED   100

enum{
    ITEM_TEST_1 = 0,
    ITEM_TEST_2,
    ITEM_MAX,
    
    ITEM_HELMET = INDEX_MAX,
    ITEM_ARMOR,
    ITEM_BOOTS,
    ITEM_ENCHANT,
    
    TAG_WASTEBASKET,
};

typedef struct _item{
    const char* mSpriteName;
    const char* mDescription;
    int mCurrentEnchant;
    int mMaxEnchant;
    int mNum;
    int mType;
    
    _item(const char* spriteName, const char* description, int currentEnchant, int maxEnchant, int num, int type){
        mSpriteName     = spriteName;
        mDescription    = description;
        mCurrentEnchant = currentEnchant;
        mMaxEnchant     = maxEnchant;
        mNum            = num;
        mType           = type;
    }
}ITEM;

class CSInventory : public CCNode{
public:
    virtual bool init();
    virtual void update(float dt);
    virtual void onExit();
    CREATE_FUNC(CSInventory);
    
    void selectItem(int index);
    void moveItem(int index);
    void cancelItem();
    void setItemPosition(CCPoint& position);
    
    typedef map<int, ITEM> ITEMTABLE;
    
private:
    int         mInventory[INDEX_MAX];
    int         mItem[3];
    int         mIndex;
    ITEMTABLE   mContainer;
    
    void openWastebasket();
    void closeWastebasket();
};

#endif /* defined(__SettingScene__CSInventory__) */
