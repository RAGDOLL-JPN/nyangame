//
//  BlockSprite.h
//  nyangame
//
//  Created by NAKASHIMAshinichiro on 2014/04/01.
//
//

#ifndef __nyangame__BlockSprite__
#define __nyangame__BlockSprite__

#include "cocos2d.h"
#include "Config.h"

class BlockSprite : public cocos2d::CCSprite
{
protected:
    const char* getBlockImageFileName(kBlock blockType);
    
public:
    // コマの種類を返すアクセッサ
    CC_SYNTHESIZE_READONLY(kBlock, m_blockType, BlockType);
    
    BlockSprite();
    virtual ~BlockSprite();
    virtual bool initWithBlockType(kBlock blockType);
    
    // create関数
    static BlockSprite* createWithBlockType(kBlock blockType);
};

#endif /* defined(__nyangame__BlockSprite__) */
