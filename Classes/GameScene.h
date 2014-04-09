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

#define MAX_BLOCK_X 8  // 縦のコマ数
#define MAX_BLOCK_Y 8  // 横のコマ数

#define PNG_BACKGROUND      "background.png"
#define PNG_GAMEOVER        "gameover.png"
#define MP3_REMOVE_BLOCK    "removeBlock.mp3"

#define FONT_RED    "redFont.fnt"
#define FONT_BLUE   "blueFont.fnt"
#define FONT_YELLOW "yellowFont.fnt"
#define FONT_GREEN  "greenFont.fnt"
#define FONT_GRAY   "grayFont.fnt"
#define FONT_WHITE  "whiteFont.fnt"

#define REMOVEING_TIME  0.1f
#define MOVING_TIME     0.2f

#define KEY_HIGHSCORE   "HighScore"

class GameScene : public cocos2d::CCLayer
{
protected:
    enum kTag
    {
        kTagBackground = 1, // 画像のタグ
        kTagRedLabel,
        kTagBlueLabel,
        kTagYellowLabel,
        kTagGreenLabel,
        kTagGrayLabel,
        kTagScoreLabel,
        kTagGameOver,
        kTagHighScoreLabel,
        kTagBaseBlock = 10000,  // コマの基準タグ
    };
    
    enum kZOrder
    {
        kZOrderBackground,  // Zオーダー
        kZOrderLabel,
        kZOrderBlock,       // コマの基準タグ
        kZOrderGameOver,
    };
    
    struct PositionIndex
    {
        PositionIndex(int x1, int y1)
        {
            x = x1;
            y = y1;
        }
        
        int x;
        int y;
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
    
    // 2-2-5
    void getTouchBlockTag(cocos2d::CCPoint touchPoint, int &tag, kBlock &blockType);
    std::list<int> getSameColorBlockTags(int baseTags, kBlock blockType);
    void removeBlock(std::list<int> blockTags, kBlock blockType);
    bool hasSameColorBlock(std::list<int> blockTagList, int searchBlockTag);
    
    // 2-3-1
    void removeingBlock(cocos2d::CCNode* block);
    
    // 2-3-2
    std::vector<kBlock> blockTypes;
    PositionIndex getPositionIndex(int tag);
    void setNewPosition1(int tag, PositionIndex posIndex);
    void searchNewPosition1(std::list<int> blocks);
    void moveBlock();
    void movingBlockAnimation1(std::list<int> blocks);
    
    // 2-3-3
    bool m_animating;
    void movedBlocks();
    std::map<int, bool> getExistsBlockColumn();
    void searchNewPosition2();
    void setNewPosition2(int tag, PositionIndex posIndex);
    void movingBlockAnimation2();
    
    // 2-4-1
    void showLabel();
    
    //2-4-2
    int m_score;
    
    // 2-4-3
    bool existsSameBlock();
    
    // 2-4-4
    void saveHighScore();
    void showHighScoreLabel();
    
public:
    virtual bool init();
    static cocos2d::CCScene* scene();
    CREATE_FUNC(GameScene);
    
    virtual bool ccTouchBegan(cocos2d::CCTouch* pTouch, cocos2d::CCEvent* pEvent);
    virtual void ccTouchEnded(cocos2d::CCTouch* pTouch, cocos2d::CCEvent* pEvent);
};

#endif
