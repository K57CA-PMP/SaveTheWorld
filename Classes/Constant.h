﻿//
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
#define Z_MAP_CITIES          14

#define GAMEGUIDE "Thử thách đầu tiên của bạn chính là việc thể hiện những kiến thức về biến đổi khí hậu, đặc biệt là về thảm họa thiên nhiên\
Bốn bức tranh về cùng một chủ đề - một thảm họa thiên nhiên nào đấy sẽ được hiển thị một cách lần lượt.\
Vượt qua thử thách và chinh phục bước đầu tiên trong quãng đường cứu trái đất tương lai, vì đây chính là định mệnh của bạn"



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

#define DIALOG1 "Bạn ở trong khu vực sắp có bão xảy ra."
#define DIALOG2 "Bạn nhận được yêu cầu di dời ngay lập tức!"
#define DIALOG3 "BẠN SẼ PHẢI LÀM GÌ?"
#define DIALOG4 "HÃY CHỌN MANG THEO NHỮNG THỨ CẦN THIẾT NHẤT!"

#define ANSWER1 1
#define ANSWER2 1
#define ANSWER3 1
#define ANSWER4 3
#define ANSWER5 2

#define QUESTION1 "Trước khi đi bạn sẽ làm gì với ngôi nhà của mình?"
#define QUESTION2 "Thế còn đồ đạc của mình thì sao?"
#define QUESTION3 "Hãy lựa chọn loại thực phẩm mà bạn mang theo:"
#define QUESTION4 "Bạn sẽ sơ tán đến nơi nào?"
#define QUESTION5 "Bạn sẽ tới đó bằng đường nào?"

#endif
