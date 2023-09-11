/*2151294 信11 马威*/
#pragma once

/* ------------------------------------------------------------------------------------------------------

     本文件功能：
	1、为了保证 hanoi_main.cpp/hanoi_menu.cpp/hanoi_multiple_solutions.cpp 能相互访问函数的函数声明
	2、一个以上的cpp中用到的宏定义（#define）或全局只读（const）变量，个数不限
	3、可以参考 cmd_console_tools.h 的写法（认真阅读并体会）
   ------------------------------------------------------------------------------------------------------ */
#define PLATE_NUM_LIMIT 10    /*盘子总数上限 default:10*/
#define SCREEN_WIDTH    120   /*窗口宽度 default:120*/

#define CONSOLE_BASE_X  1  /*横坐标 default:1*/
#define CONSOLE_BASE_Y  PLATE_NUM_LIMIT + 5      /*纵坐标 default:15*/
#define TOWER_WIDTH     PLATE_NUM_LIMIT * 2 + 3  /*底盘宽度 default:23*/
#define TOWER_HEIGHT    PLATE_NUM_LIMIT + 2      /*柱子高度 default:12*/
#define TOWER_DISTANCE  9  /*柱子间距 default:9*/
#define TOWER_TOP       2  /*柱顶位置 default:2*/

#define ARRAY_BASE_X    11    /*A柱与屏幕右边框距离 default:11*/
#define ARRAY_DISTANCE  9     /*柱子间距 default:9*/

#define GAME_TIP_Y       CONSOLE_BASE_Y + PLATE_NUM_LIMIT + 9   /*游戏提示语纵坐标 default:34*/
#define TIP_LENGTH       60   /*游戏提示语的长度 default:60*/
#define EmptySourceTower 1    /*错误1：源柱为空*/
#define BigOnSmall       2    /*错误2：大盘压小盘*/

/* 菜单函数 */
int menu();

/* 关于递归函数 */
void hanoi(int number_of_plates, char source_tower, char temporary_tower, char destination_tower, const int menu);
void hanoi_act(int number_of_plates, char source_tower, char destination_tower, const int menu);
void hanoi_act_info(int number_of_plates, char source_tower, char destination_tower, const int menu);
void hanoi_act_array(int number_of_plates, char source_tower, char destination_tower, const int menu);

/* 关于数组的函数 */
void array_tower_initialize(const int number_of_plates, const char source_tower);
void array_print_base(const int number_of_plates, const char source_tower, const int menu);
void array_show_move(const char source_tower, const char destination_tower, const int menu);
void array_print_tower(const int number_of_plates, const char source_tower, const char destination_tower, const int menu);
void array_move_plates(const char source_tower, const char destination_tower);

/* 关于图形化界面的函数 */
void console_print_base();
void console_print_plates(const int number_of_plates, const char source_tower);
void console_show_move(const int number_of_plates, const char source_tower, const char destination_tower, const int menu);
void console_show_move_up(int START_X, int START_Y, int bg_color, int fg_color, int src_mid, int LENGTH, int time);
void console_show_move_down(int END_X, int END_Y, int bg_color, int fg_color, int dst_mid, int LENGTH, int time);
void console_show_move_left(int START_X, int END_X, int bg_color, int fg_color, int LENGTH, int time);
void console_show_move_right(int START_X, int END_X, int bg_color, int fg_color, int LENGTH, int time);

/* 关于游戏的函数 */
void game_command_center(const int total_number_of_plates, const char destination_tower, const int menu);
void game_clear_input();
void game_get_info_and_move(const char source_tower, const char destination_tower, const int menu);
void game_err(const int err_info);
void game_ok_move(const int number_of_plates, const char source_tower, const char destination_tower, const int menu);
int game_get_plate_num(const char tower);

/* 关于输入的函数 */
void input_info(int* number_of_plates, char* source_tower, char* destination_tower, int* delay_time_set, const int menu);
void input_number_of_plates(int* number_of_plates);
void input_source_tower(char* source_tower);
void input_destination_tower(char* destination_tower, const char* source_tower);
void input_delay(int* delay_time_set);

/* 关于通用函数 */
void pause(const int delay_time_set);
void reset(const int menu);

/* 关于控制台的函数 */
void command_center(int number_of_plates, char source_tower, char temporary_tower, char destination_tower, int delay_time_set, int menu);
void command_info(const int number_of_plates, const char source_tower, const char destination_tower, const int delay_time_set, const int menu);
void command_array_base(const int number_of_plates, const  char source_tower, const char destination_tower, const int menu);
void command_console_base(const int number_of_plates, const  char source_tower, const int menu);
void command_delay(const int menu);