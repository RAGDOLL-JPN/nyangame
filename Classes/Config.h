//
//  Config.h
//  nyangame
//
//  Created by NAKASHIMAshinichiro on 2014/04/01.
//
//

#ifndef nyangame_Config_h
#define nyangame_Config_h

// コマの種類の定義
enum kBlock
{
    kBlockRed,
    kBlockBlue,
    kBlockYellow,
    kBlockGreen,
    kBlockGray,
    kBlockCount,
};

#define ccsf(...) CCString::createWithFormat(__VA_ARGS__)->getCString()

#endif
