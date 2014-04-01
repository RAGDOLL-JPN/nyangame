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
#include "Config.h"

#define MAX_BLOCK_X 8;  // 縦のコマ数
#define MAX_BLOCK_Y 8;  // 横のコマ数

#define PNG_BACKGROUND "background.png"

class GameScene : public cocos2d::CCLayer
{
protected:
    enum kTag
    {
        kTagBackground = 1, // 画像のタグ
        kTagBaseBlock = 10000,  // コマの基準タグ
    };
    
    enum kZOrder
    {
        kZOrderBackground,  // Zオーダー
        kZOrderBlock,       // コマの基準タグ
    };
    
    // 2-2-3
    cocos2d::CCSprite* m_background;
    void showBackground();
    
    // 2-2-4
    float m_blockSize;              // コマの一片のサイズを記録
    std::map<kBlock, std::list<int> > m_blockTags;   // コマの種類ごとのグループ
    void initForVariables();
    void showBlock();
    cocos2d::CCPoint getPosition(int posIndexX, int posIndexY);
    int getTag(int posIndexX, int posIndexY);
    
public:
    virtual bool init();
    static cocos2d::CCScene* scene();
    CREATE_FUNC(GameScene);
};

#endif
