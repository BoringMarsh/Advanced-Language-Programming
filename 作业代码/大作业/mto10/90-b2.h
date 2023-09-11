/*2151294 信11 马威*/
#pragma once
#include "lib_mto10_net_tools.h"

#define LINE_MIN 5    /*行数最小值*/
#define LINE_MAX 8    /*行数最大值*/
#define ROW_MIN  5    /*列数最小值*/
#define ROW_MAX  10   /*列数最大值*/
#define GOAL_MIN 5    /*合成目标最小值*/
#define GOAL_MAX 20   /*合成目标最大值*/

#define INPUT_LINE 0  /*输入模式：输入行数*/
#define INPUT_ROW  1  /*输入模式：输入列数*/
#define INPUT_GOAL 2  /*输入模式：输入合成目标*/

#define ARRAY_SHOW_CURRENT 10   /*显示内部数组模式：打印当前数组（被标记的用不同色标识）*/
#define ARRAY_SHOW_RESULT  11   /*显示内部数组模式：打印数组查找结果*/

#define PRINT_WITHOUT_LINE   0  /*显示初始数组模式：无分隔线*/
#define PRINT_WITH_LINE      1  /*显示初始数组模式：有分隔线*/

#define KEYBOARD_MOVE_UP    20  /*键盘控制时改变坐标方式：向上*/
#define KEYBOARD_MOVE_DOWN  21  /*键盘控制时改变坐标方式：向下*/
#define KEYBOARD_MOVE_LEFT  22  /*键盘控制时改变坐标方式：向左*/
#define KEYBOARD_MOVE_RIGHT 23  /*键盘控制时改变坐标方式：向右*/

#define INFO_RULES          30  /*提示：基本操作规则*/
#define INFO_NO_CLEAR       31  /*提示：周围无相同值*/
#define INFO_GOAL_ACHIEVED  32  /*提示：已达合成目标*/
#define INFO_MAKE_SURE      33  /*提示：按...合成，按...取消本次合成*/
#define INFO_END            34  /*提示：无可合成项，游戏结束*/
#define MENU8_FALL          35  /*提示：按...下落0*/
#define MENU8_FILL          36  /*提示：按...填充新值*/
#define MENU8_CONTINUE      37  /*提示：按...继续新的一次合成*/

#define MK_ENTER_CONTINUE 40  /*间断方式：按鼠标左键或回车键继续*/
#define MK_C_CONTINUE     41  /*间断方式：按鼠标左键或C键继续*/

#define MK_RET_MOUSE_LEFT     51  /*自定义读键鼠函数返回值：鼠标单击左键*/
#define MK_RET_MOUSE_RIGHT    52  /*自定义读键鼠函数返回值：鼠标单击右键*/
#define MK_RET_MOUSE_MOVE     53  /*自定义读键鼠函数返回值：鼠标移动*/
#define MK_RET_KEYBOARD_ENTER 54  /*自定义读键鼠函数返回值：按回车键*/
#define MK_RET_KEYBOARD_ARROW 55  /*自定义读键鼠函数返回值：按箭头键*/
#define MK_RET_KEYBOARD_C     56  /*自定义读键鼠函数返回值：按C键*/
#define MK_RET_KEYBOARD_Q     57  /*自定义读键鼠函数返回值：按Q键*/

struct MATRIX {  /*数组元素的结构体，每个元素包含数值和标记状态两个量*/
	int num;
	int mark;
};

/***************************************************************************

  90-b2-base.cpp

***************************************************************************/
void array_clear(MATRIX matrix[][ROW_MAX], const int line, const int row, const char coord[]);
void array_copy(MATRIX Destination[][ROW_MAX], const MATRIX Source[][ROW_MAX], const int line, const int row);
void array_initialize(MATRIX matrix[][ROW_MAX], const int line, const int row);
void array_mark_set(MATRIX matrix[][ROW_MAX], const int line, const int row);
void array_move_zero(MATRIX matrix[][ROW_MAX], const int line, const int row);
void array_single_scan(MATRIX matrix[][ROW_MAX], const int I, const int J, const int line, const int row);
void array_multiple_scan1(MATRIX matrix[][ROW_MAX], const int line, const int row, char coord[], const int menu);
void array_multiple_scan2(MATRIX matrix[][ROW_MAX], const int line, const int row, char coord[]);
void array_random(MATRIX matrix[][ROW_MAX], const int line, const int row, const int MaxNum);
void array_show(MATRIX matrix[][ROW_MAX], const int line, const int row, const int show_mode);
void command_end();
void command_goal_achieved(int& goal);
int array_getmax(MATRIX matrix[][ROW_MAX], const int line, const int row);
int array_getscore(MATRIX matrix[][ROW_MAX], const int line, const int row);
int array_mark_count(MATRIX matrix[][ROW_MAX], const int line, const int row);
bool array_compare(MATRIX matrix1[][ROW_MAX], MATRIX matrix2[][ROW_MAX], const int line, const int row);

/***************************************************************************

  90-b2-console.cpp

***************************************************************************/
void background_letter(const int Y, const char ch, const int print_mode);
void background_line(int row, int Y, const char firstch[], const char midch[], const char midspecialch[], const char lastch[], int print_mode);
void background_multiple_lines(const int line, const int row, const int print_mode);
void background_number(const int row, const int print_mode);
void block_single_activate(MATRIX matrix[][ROW_MAX], const char coordinate[]);
void block_single_clear();
void block_single_default(MATRIX matrix[][ROW_MAX], const char coordinate[]);
void block_single_fall(MATRIX matrix[][ROW_MAX], const char coordinate[]);
void block_single_print(const int num, const int bg_color, const int fg_color);
void block_multiple_activate(MATRIX matrix[][ROW_MAX], const int line, const int row);
void block_multiple_clear(MATRIX matrix[][ROW_MAX], const int line, const int row);
void block_multiple_default(MATRIX matrix[][ROW_MAX], const int line, const int row);
void block_multiple_fall(MATRIX matrix[][ROW_MAX], const int line, const int row);
void block_multiple_print(MATRIX matrix[][ROW_MAX], const int line, const int row);
void console_blink_block(MATRIX matrix[][ROW_MAX], const char coordinate[]);
void console_print_background(const int line, const int row, const int print_mode);
void console_print_base(MATRIX matrix[][ROW_MAX], const int line, const int row, const int print_mode);
void keyboard_coord_move(const int line, const int row, char coordinate[], const int move_mode);
void keyboard_single_act(MATRIX matrix[][ROW_MAX], const int line, const int row, char operate_coord[], const int move_mode);
void keyboard_multiple_act(MATRIX matrix[][ROW_MAX], const int line, const int row, char operate_coord[], const int keycode);
void mk_pause(const int pause_mode);
void mouse_act(MATRIX matrix[][ROW_MAX], const int line, const char coordinate[], const bool prime);
void print_keyboard_info(const int line, const char coordinate[]);
void select_act(MATRIX matrix[][ROW_MAX], char final_coord[], const char selected_coord[]);
void special_info(const int line, int& goal, const int info_name);
int mk_select();
int mouse_and_keyboard(MATRIX matrix[][ROW_MAX], const int line, const int row, char final_coord[]);
bool if_in_block(const int X, const int Y, const int line, const int row, char coordinate[]);

/***************************************************************************

  90-b2-tools.cpp

***************************************************************************/
void command_center(MATRIX matrix[][ROW_MAX], const int line, const int row, int goal, int score, char coord[], const int menu);
void end();
void input_coord(const int line, const int row, char coordinate[]);
void pause();
void print_score(const int getscore, const int score, const int goal, const int menu);
char clear_command(const char coord[]);
bool if_end(MATRIX matrix[][ROW_MAX], const int line, const int row);


/***************************************************************************

  90-b2-main.cpp

***************************************************************************/
void single_input(int* num, const int input_mode);
void multiple_input(int* line, int* row, int* goal, const int menu);
int menu();

/***************************************************************************

  90-b2-net.cpp

***************************************************************************/
void map_trans(MATRIX matrix[][ROW_MAX], const char* get_map, const int line, const int row, const int menu);
void find_best_solution(MATRIX matrix[][ROW_MAX], const int line, const int row, char final_coord[]);
void net_main(MATRIX matrix[][ROW_MAX], const int menu);
void print_info(mto10_net_tools& client, MATRIX matrix[][ROW_MAX]);
void my_print_map(mto10_net_tools& client, MATRIX matrix[][ROW_MAX]);
void my_console_move(mto10_net_tools& client, MATRIX matrix[][ROW_MAX], char coordinate[], const int menu);
void competition();
int array_getmin(MATRIX matrix[][ROW_MAX], const int line, const int row);
int game_progress(mto10_net_tools& client, MATRIX matrix[][ROW_MAX], const int menu);
int competition_progress(mto10_net_tools& client);