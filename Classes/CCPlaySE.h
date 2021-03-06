//
//  CCPlaySE.h
//  nyangame
//
//  Created by 中島信一郎 on 2014/03/23.
//
//

#ifndef nyangame_CCPlaySE_h
#define nyangame_CCPlaySE_h

#include "cocos2d.h"

class CCPlaySE : public cocos2d::CCActionInstant
{
public:
    CCPlaySE(std::string sound);
    virtual ~CCPlaySE(){}
    
    virtual void update(float time);
    virtual CCFiniteTimeAction* reverse(void);
    virtual CCObject* copyWithZone(cocos2d::CCZone* pZone);
    
public:
    static CCPlaySE* create(std::string sound);
    
protected:
    std::string m_sound;
};

#endif
