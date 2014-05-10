//
//  Constant.h
//  UberJump_v3
//
//  Created by Giap Nguyen on 5/4/14.
//
//

#ifndef UberJump_v3_Constant_h
#define UberJump_v3_Constant_h

#define NUMBER_BACKGROUND_IMG 20
#define SCREEN_SIZE           cocos2d::Director::getInstance()->getWinSize()

//  CollectItems
#define ROTATE 0
#define LAUNCH 1
#define RETRIEVE 2
#define ITEM_COLLECTED 3
#define GAME_OVER 4
#define NEXT_LEVEL 5
#define WIN 6
#define HOOK_POSITION Point(SCREEN_SIZE.width/2 - 20, SCREEN_SIZE.height - 30)
#define ITEM_DST_POS Point(SCREEN_SIZE.width/2 - 20, SCREEN_SIZE.height - 100)
#define LIMITED_ANGLE 80
#define ROTATION_DELAY 1
#define LAUNCHING_DELAY 1
#define RETRIEVING_DELAY 1
#define PI 3.14159265

#define NUM_OF_ITEMS 7
#define ITEM1_POS Point(150, 250)
#define ITEM4_POS Point(85, 140)
#define ITEM3_POS Point(220, 80)
#define ITEM7_POS Point(360, 110)
#define ITEM2_POS Point(540, 60)
#define ITEM6_POS Point(640, 220)
#define ITEM5_POS Point(740, 80)

#define SCORE_LBL_POS Point(150, 400)
#define TIME_LBL_POS Point(50, 400)

#endif
