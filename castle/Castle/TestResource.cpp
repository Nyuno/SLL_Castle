//
//  TestResource.cpp
//  AnamTower
//
//  Created by 신 현호 on 13. 8. 13..
//
//

#include "TestResource.h"

float ScrollY                 = 0.0f;
float ScrollTime              = 0.0f;
int ScrollCurrentFloor      = 0;
int ScrollFloor             = 0;

namespace IMAGE_GAME_STAGE {
    const char* RESOURCE_IMAGE[OTHERS::IMG_MAX] = {
        "몬스터_01_01.png",
        "몬스터_01_02.png",
        "몬스터_01_03.png",
        "몬스터_01_04.png",
        "몬스터_01_05.png",
        "몬스터_01_06.png",
        "몬스터_01_07.png",
        "몬스터_01_08.png",
        "몬스터_01_09.png",
        "몬스터_01_10.png",
        "몬스터_01_11.png",
        "몬스터_01_12.png",
        "몬스터_01_13.png",
        "몬스터_01_14.png",
        "몬스터_01_15.png",
        "몬스터_01_16.png",
        "GameStage/01.bmp",
        "GameStage/02.bmp",
        "GameStage/03.bmp",
        "GameStage/04.bmp",
        "GameStage/05.bmp",
        "GameStage/06.bmp",
        "GameStage/07.bmp",
        "GameStage/08.bmp",
        "GameStage/09.bmp",
        "GameStage/10.bmp",
        "캐릭터_01_빛앞_01.png",
        "캐릭터_01_빛앞_02.png",
        "캐릭터_01_빛앞_03.png",
        "캐릭터_01_빛앞_04.png",
        "캐릭터_01_빛앞_05.png",
        "캐릭터_01_빛앞_06.png",
        "캐릭터_01_빛앞_07.png",
        "캐릭터_01_빛앞_08.png",
        "캐릭터_01_빛앞_09.png",
        "캐릭터_01_빛앞_10.png",
        "캐릭터_01_빛뒤_01.png",
        "캐릭터_01_빛뒤_02.png",
        "캐릭터_01_빛뒤_03.png",
        "캐릭터_01_빛뒤_04.png",
        "캐릭터_01_빛뒤_05.png",
        "캐릭터_01_빛뒤_06.png",
        "캐릭터_01_빛뒤_07.png",
        "캐릭터_01_빛뒤_08.png",
        "캐릭터_01_빛뒤_09.png",
        "캐릭터_01_빛뒤_10.png",
        "지하 물탕01.png",
        "지하 물탕02.png",
        "지하 물탕03.png",
        "지하 물탕04.png",
        "지하 물탕05.png",
        "지하 물탕06.png",
        "지하 물탕07.png",
        "지하 물탕08.png",
        "지하 물탕09.png",
        "지하 물탕10.png",
        "지하 물탕11.png",
        "지하 횃불.png",
        "지하 횃불씨1.png",
        "지하 횃불씨2.png",
        "지하배경1.png",
        "지하배경깜빡임알파값4-10퍼센트 랜덤.png"
    };
}

namespace IMAGE_TEST {
    const char* RESOURCE_IMAGE[OTHERS::RESOURCE_MAX] = {
        "캐릭터 달리기1.png",
        "캐릭터 달리기2.png",
        "캐릭터 달리기3.png",
        "캐릭터 달리기4.png",
        "캐릭터 달리기5.png",
        "캐릭터 달리기6.png",
        "캐릭터 달리기7.png",
        "캐릭터 멈추기1.png",
        "캐릭터 멈추기2.png",
        "캐릭터 멈추기3.png",
        "비상구문1.png",
        "비상구문2.png",
        "비상구문3.png",
        "비상구문4.png",
        "로고.png",
        "비상구DOWN.png",
        "비상구UP.png",
        "SOMA in ANAM/아남타워1층.png",
        "SOMA in ANAM/아남타워다층.png",
        "SOMA in ANAM/복도.png"
    };
}

namespace SOUND_TEST {
    const char* RESOURCE_SOUND[SOUND_MAX] = {
        "SOMA in ANAM/RUN.mp3",
        "SOMA in ANAM/DOOR.mp3",
        "SOMA in ANAM/BGM.mp3",
        "SOMA in ANAM/jump.wav",
        "SOMA in ANAM/coin.wav",
        "SOMA in ANAM/SelectEff.wav"
    };
}
