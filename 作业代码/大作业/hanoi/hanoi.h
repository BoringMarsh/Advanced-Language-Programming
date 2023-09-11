/*2151294 ��11 ����*/
#pragma once

/* ------------------------------------------------------------------------------------------------------

     ���ļ����ܣ�
	1��Ϊ�˱�֤ hanoi_main.cpp/hanoi_menu.cpp/hanoi_multiple_solutions.cpp ���໥���ʺ����ĺ�������
	2��һ�����ϵ�cpp���õ��ĺ궨�壨#define����ȫ��ֻ����const����������������
	3�����Բο� cmd_console_tools.h ��д���������Ķ�����ᣩ
   ------------------------------------------------------------------------------------------------------ */
#define PLATE_NUM_LIMIT 10    /*������������ default:10*/
#define SCREEN_WIDTH    120   /*���ڿ�� default:120*/

#define CONSOLE_BASE_X  1  /*������ default:1*/
#define CONSOLE_BASE_Y  PLATE_NUM_LIMIT + 5      /*������ default:15*/
#define TOWER_WIDTH     PLATE_NUM_LIMIT * 2 + 3  /*���̿�� default:23*/
#define TOWER_HEIGHT    PLATE_NUM_LIMIT + 2      /*���Ӹ߶� default:12*/
#define TOWER_DISTANCE  9  /*���Ӽ�� default:9*/
#define TOWER_TOP       2  /*����λ�� default:2*/

#define ARRAY_BASE_X    11    /*A������Ļ�ұ߿���� default:11*/
#define ARRAY_DISTANCE  9     /*���Ӽ�� default:9*/

#define GAME_TIP_Y       CONSOLE_BASE_Y + PLATE_NUM_LIMIT + 9   /*��Ϸ��ʾ�������� default:34*/
#define TIP_LENGTH       60   /*��Ϸ��ʾ��ĳ��� default:60*/
#define EmptySourceTower 1    /*����1��Դ��Ϊ��*/
#define BigOnSmall       2    /*����2������ѹС��*/

/* �˵����� */
int menu();

/* ���ڵݹ麯�� */
void hanoi(int number_of_plates, char source_tower, char temporary_tower, char destination_tower, const int menu);
void hanoi_act(int number_of_plates, char source_tower, char destination_tower, const int menu);
void hanoi_act_info(int number_of_plates, char source_tower, char destination_tower, const int menu);
void hanoi_act_array(int number_of_plates, char source_tower, char destination_tower, const int menu);

/* ��������ĺ��� */
void array_tower_initialize(const int number_of_plates, const char source_tower);
void array_print_base(const int number_of_plates, const char source_tower, const int menu);
void array_show_move(const char source_tower, const char destination_tower, const int menu);
void array_print_tower(const int number_of_plates, const char source_tower, const char destination_tower, const int menu);
void array_move_plates(const char source_tower, const char destination_tower);

/* ����ͼ�λ�����ĺ��� */
void console_print_base();
void console_print_plates(const int number_of_plates, const char source_tower);
void console_show_move(const int number_of_plates, const char source_tower, const char destination_tower, const int menu);
void console_show_move_up(int START_X, int START_Y, int bg_color, int fg_color, int src_mid, int LENGTH, int time);
void console_show_move_down(int END_X, int END_Y, int bg_color, int fg_color, int dst_mid, int LENGTH, int time);
void console_show_move_left(int START_X, int END_X, int bg_color, int fg_color, int LENGTH, int time);
void console_show_move_right(int START_X, int END_X, int bg_color, int fg_color, int LENGTH, int time);

/* ������Ϸ�ĺ��� */
void game_command_center(const int total_number_of_plates, const char destination_tower, const int menu);
void game_clear_input();
void game_get_info_and_move(const char source_tower, const char destination_tower, const int menu);
void game_err(const int err_info);
void game_ok_move(const int number_of_plates, const char source_tower, const char destination_tower, const int menu);
int game_get_plate_num(const char tower);

/* ��������ĺ��� */
void input_info(int* number_of_plates, char* source_tower, char* destination_tower, int* delay_time_set, const int menu);
void input_number_of_plates(int* number_of_plates);
void input_source_tower(char* source_tower);
void input_destination_tower(char* destination_tower, const char* source_tower);
void input_delay(int* delay_time_set);

/* ����ͨ�ú��� */
void pause(const int delay_time_set);
void reset(const int menu);

/* ���ڿ���̨�ĺ��� */
void command_center(int number_of_plates, char source_tower, char temporary_tower, char destination_tower, int delay_time_set, int menu);
void command_info(const int number_of_plates, const char source_tower, const char destination_tower, const int delay_time_set, const int menu);
void command_array_base(const int number_of_plates, const  char source_tower, const char destination_tower, const int menu);
void command_console_base(const int number_of_plates, const  char source_tower, const int menu);
void command_delay(const int menu);