//
//  GameScene.h
//  nyangame
//
//  Created by 中島信一郎 on 2014/03/31.
//
//

#ifndef nyangame_GameScene_h
#define nyangame_GameScene_h

#include "cocos2d.h"

#define PNG_BACKGROUND "background.png"

class GameScene : public cocos2d::CCLayer
{
protected:
    enum kTag
    {
        kTagBackground = 1, // 画像のタグ
    };
    
    enum kZOrder
    {
        kZOrderBackground,  // Zオーダー
    };
    
    // 2-2-3
    cocos2d::CCSprite* m_background;
    void showBackground();
    
public:
    virtual bool init();
    static cocos2d::CCScene* scene();
    CREATE_FUNC(GameScene);
};

#endif
