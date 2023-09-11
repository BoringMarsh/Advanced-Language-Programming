/*2151294 信11 马威*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include<conio.h>
#include<Windows.h>
#include"cmd_console_tools.h"
#include"hanoi.h"
using namespace std;

/*计数用的一个全局变量*/
static int __stepnumber = 0;

/*标志移动延时时长的变量*/
static int __delay_time;

/*代表三根柱子的一个全局二维数组，设TOWER[0]为A柱，TOWER[1]为B柱，TOWER[2]为C柱*/
int TOWER[3][PLATE_NUM_LIMIT];

/*代表三个栈顶指针的一个全局一维数组，设MARK[0]为A柱栈顶指针，MARK[1]为B柱栈顶指针，MARK[2]为C柱栈顶指针*/
int MARK[3];

/* ----------------------------------------------------------------------------------

     本文件功能：
	1、存放被 hanoi_main.cpp 中根据菜单返回值调用的各菜单项对应的执行函数

     本文件要求：
	1、不允许定义外部全局变量（const及#define不在限制范围内）
	2、允许定义静态全局变量（具体需要的数量不要超过文档显示，全局变量的使用准则是：少用、慎用、能不用尽量不用）
	3、静态局部变量的数量不限制，但使用准则也是：少用、慎用、能不用尽量不用
	4、按需加入系统头文件、自定义头文件、命名空间等

   ----------------------------------------------------------------------------------- */

/***************************************************************************
  函数名称：hanoi
  功    能：打印汉诺塔的移动
  输入参数：int number_of_plates：盘子数量
			char source_tower：起始柱编号
			char temporary_tower：中间柱编号
			char destination_tower：目标柱编号
			const int menu：菜单函数返回值（只读）
  返 回 值：无
  说    明：1、本函数调用了act()，决定每一步移动时伴随的行动
            2、本函数为14行
***************************************************************************/
void hanoi(int number_of_plates, char source_tower, char temporary_tower, char destination_tower, const int menu)
{
	if (number_of_plates == 1) {/*若汉诺塔层数为1，将该盘从起始柱直接移向目标柱*/
		__stepnumber++;
		hanoi_act(number_of_plates, source_tower, destination_tower, menu);
	}

	else {  /*若汉诺塔层数不为1*/
		hanoi(number_of_plates - 1, source_tower, destination_tower, temporary_tower, menu);  /*将n-1个盘子移向中间柱*/
		__stepnumber++;  /*步数自增*/
		hanoi_act(number_of_plates, source_tower, destination_tower, menu);  /*将第n个盘子直接移向目标柱*/
		hanoi(number_of_plates - 1, temporary_tower, source_tower, destination_tower, menu);  /*将其余n-1个盘子移向目标柱*/
	}
}

/***************************************************************************
  函数名称：hanoi_act
  功    能：综合所有信息，决定伴随着递归函数每一步的行动
  输入参数：int number_of_plates：盘子数量
			char source_tower：起始柱编号
			char destination_tower：目标柱编号
			const int menu：菜单函数返回值（只读）
  返 回 值：无
  说    明：1、该函数根据菜单函数返回值，选择调用不同函数，决定伴随着递归函数每一步的行动
            2、该函数为17行
***************************************************************************/
void hanoi_act(int number_of_plates, char source_tower, char destination_tower, const int menu)
{
	hanoi_act_info(number_of_plates, source_tower, destination_tower, menu);    /*1、输出每一步的文字信息*/
	hanoi_act_array(number_of_plates, source_tower, destination_tower, menu);  /*2、对数组进行操作*/

	/*3、菜单项7或8：图形输出+再次改变数组值*/
	/*注：菜单项7只输出第一步的移动*/
	if ((menu == 7 && __stepnumber == 1) || menu == 8) {
		console_show_move(number_of_plates, source_tower, destination_tower, menu);
		array_move_plates(source_tower, destination_tower);
	}

	/*4、菜单项4或8：每一步后的暂停或延时*/
	if (menu == 4 || menu == 8) {
		pause(__delay_time);  /*每一步后的暂停或延时*/
	}
}

/***************************************************************************
  函数名称：hanoi_act_info
  功    能：act控制台附件，打印每一步的文字信息
  输入参数：int number_of_plates：盘子数量
			char source_tower：起始柱编号
			char destination_tower：目标柱编号
			const int menu：菜单函数返回值（只读）
  返 回 值：无
  说    明：该函数为16行
***************************************************************************/
void hanoi_act_info(int number_of_plates, char source_tower, char destination_tower, const int menu)
{
	/*菜单项1：打印每一步的解*/
	if (menu == 1)
		cout << number_of_plates << "# " << source_tower << "---->" << destination_tower << endl;

	/*菜单项2或3：打印每一步的步数+解*/
	else if (menu == 2 || menu == 3) {
		cout << "第" << setw(4) << __stepnumber << " 步(" << setw(2) << number_of_plates << "#: "
			<< source_tower << "-->" << destination_tower << ")";

		/*若菜单项为2，直接在此换行*/
		if (menu == 2)
			cout << endl;
	}
}

/***************************************************************************
  函数名称：hanoi_act_array
  功    能：act控制台附件，对数组进行操作
  输入参数：int number_of_plates：盘子数量
			char source_tower：起始柱编号
			char destination_tower：目标柱编号
			const int menu：菜单函数返回值（只读）
  返 回 值：无
  说    明：该函数为16行
***************************************************************************/
void hanoi_act_array(int number_of_plates, char source_tower, char destination_tower, const int menu)
{
	/*菜单项3、4或8：改变数组值+横式打印内部数组*/
	if (menu == 3 || menu == 4 || menu == 8) {
		array_move_plates(source_tower, destination_tower);
		array_print_tower(number_of_plates, source_tower, destination_tower, menu);
	}

	/*菜单项4或8：改变数值位置*/
	if (menu == 4 || menu == 8)
		array_show_move(source_tower, destination_tower, menu);

	/*菜单项8：将这一步数组值复位，以便下一步图形化输出能使用移动前的内部数组值*/
	if (menu == 8)
		array_move_plates(destination_tower, source_tower);
}

/***************************************************************************
  函数名称：array_tower_initialize
  功    能：给所有数组赋初值，完成初始化
  输入参数：const int number_of_plates：盘子的数量（只读）
			const char src：起始柱代号（只读）
  返 回 值：无
  说    明：1、此函数根据盘子数及起始柱代号，给起始柱的对应元素赋上1-n的值
			2、此函数为20行
***************************************************************************/
void array_tower_initialize(const int number_of_plates, const char source_tower)
{
	int i, j;

	/*给所有元素赋初值*/
	for (i = 0; i < 3; i++) {
		for (j = 0; j < PLATE_NUM_LIMIT; j++)
			TOWER[i][j] = 0;
	}

	/*根据起始柱的代号，给起始柱的对应元素赋上1-n的值，代表初始时的各个盘子*/
	for (i = 0; i < number_of_plates; i++)
		TOWER[source_tower - 'A'][i] = number_of_plates - i;

	/*起始柱栈顶指针的初始化*/
	for (i = 0; i < 3; i++)
		MARK[i] = 0;

	MARK[source_tower - 'A'] = number_of_plates;
}

/***************************************************************************
  函数名称：array_print_base
  功    能：输出基本形状，包括三根柱子以及各个盘子的位置，和内部数组的值
  输入参数：const int number_of_plates：盘子数量（只读）
			const char source_tower：起始柱编号（只读）
			const int menu：菜单函数返回值（只读）
  返 回 值：无
  说    明：1、本函数调用了pause()，设置了间断点
            2、本函数为33行
***************************************************************************/
void array_print_base(const int number_of_plates, const char source_tower, const int menu)
{
	int i, BASE_Y;  /*定义所需变量，BASE_Y是坐标参数*/

	if (menu == 4)
		BASE_Y = PLATE_NUM_LIMIT + 2;

	else
		BASE_Y = CONSOLE_BASE_Y + PLATE_NUM_LIMIT + 2;

	/*循环输出代表三个柱子的字母*/
	for (i = 0; i < 3; i++) {
		cct_gotoxy(ARRAY_BASE_X + (ARRAY_DISTANCE + 1) * i, BASE_Y + 1);
		cout << char('A' + i);
	}

	/*循环输出一排等号，使输出结果更具形象化*/
	cct_gotoxy(ARRAY_BASE_X - 2, BASE_Y);
	for (i = 0; i < 6 + 2 * ARRAY_DISTANCE + 1; i++)
		cout << "=";

	/*在指定的位置，形象化输出每根柱子上的情况，光标移动前后都需移动到指定位置*/
	cct_gotoxy((ARRAY_DISTANCE + 1) * (source_tower - 'A') + ARRAY_BASE_X - 1, BASE_Y - 1);

	for (i = 0; i < PLATE_NUM_LIMIT; i++) {
		if (TOWER[source_tower - 'A'][i])
			cout << setw(2) << TOWER[source_tower - 'A'][i];
		
		cct_gotoxy((ARRAY_DISTANCE + 1) * (source_tower - 'A') + ARRAY_BASE_X - 1, BASE_Y - i - 2);
	}

	cct_gotoxy((ARRAY_DISTANCE + 1) * (source_tower - 'A') + ARRAY_BASE_X + 1, BASE_Y - number_of_plates);
}

/***************************************************************************
  函数名称：array_show_move
  功    能：在纵向输出内，随着盘子的移动而移动数字
  输入参数：const char source_tower：起始柱编号（只读）
            const char destination_tower：目标柱编号（只读）
			const int menu：菜单函数返回值（只读）
  返 回 值：无
  说    明：1、本函数调用了pause()，设置了间断点
            2、本函数为19行
***************************************************************************/
void array_show_move(const char source_tower, const char destination_tower, const int menu)
{
	int BASE_Y;  /*定义所需变量，BASE_Y是坐标参数*/

	/*按菜单函数返回值决定参数值*/
	if (menu == 4)
		BASE_Y = PLATE_NUM_LIMIT + 2;

	else
		BASE_Y = CONSOLE_BASE_Y + PLATE_NUM_LIMIT + 2;

	/*覆盖原有内容*/
	cct_gotoxy((ARRAY_DISTANCE + 1) * (source_tower - 'A') + ARRAY_BASE_X + 1, BASE_Y - 1 - MARK[source_tower - 'A']);
	cout << "\010\010\040\040";

	/*输出现有内容*/
	cct_gotoxy((ARRAY_DISTANCE + 1) * (destination_tower - 'A') + ARRAY_BASE_X - 1, BASE_Y - MARK[destination_tower - 'A']);
	cout << setw(2) << TOWER[destination_tower - 'A'][MARK[destination_tower - 'A'] - 1];
}

/***************************************************************************
  函数名称：array_print_tower
  功    能：输出每根柱子上的盘子数量情况
  输入参数：const int menu：菜单函数返回值
  返 回 值：无
  说    明：1、若有盘子（值不为零），则输出；若无盘子（值为零），则不输出，只留空格
			2、根据i的值判断应该输出哪个数组
			3、本函数为44行
***************************************************************************/
void array_print_tower(const int number_of_plates, const char source_tower, const char destination_tower, const int menu)
{
	int i, j, y = 0;

	if (menu == 4)
		y = PLATE_NUM_LIMIT + 7;  /*菜单项4的位置*/

	else if (menu == 8 || menu == 9)
		y = CONSOLE_BASE_Y + PLATE_NUM_LIMIT + 7;  /*菜单项8、菜单项9的位置*/

	if (menu != 3) {  /*菜单项3不需要擦除再输出*/
		cct_gotoxy(SCREEN_WIDTH - 1, y);

		/*消除原有内容*/
		for (i = 0; i < SCREEN_WIDTH; i++)
			cout << '\010';
		for (i = 0; i < SCREEN_WIDTH; i++)
			cout << '\040';

		/*根据步数决定输出提示内容*/
		cct_gotoxy(0, y);

		if (__stepnumber)  /*已经开始移动，步数不为零，输出移动情况*/
			cout << "第" << setw(4) << __stepnumber << "步(" << number_of_plates << "#: " << source_tower << "-->" << destination_tower << ") ";

		else  /*还未移动，步数为零，输出初始情况*/
			cout << "初始: ";
	}

	/*显示内部数组值*/
	for (i = 0; i < 3; i++) {
		cout << ' ' << char('A' + i) << ":";

		for (j = 0; j < PLATE_NUM_LIMIT; j++) {
			if (TOWER[i][j] != 0)
				cout << setw(2) << TOWER[i][j];

			else
				cout << "  ";
		}
	}

	cout << endl;
}

/***************************************************************************
  函数名称：array_move_plates
  功    能：通过改变数组以及栈顶指针的值，达到移动盘子的效果
  输入参数：const char source_tower：起始柱编号（只读）
            const char destination_tower：目标柱编号（只读）
  返 回 值：无
  说    明：1、每次移动步骤：出栈栈顶指针下降，赋值给入栈元素，入栈栈顶指针上升，出栈栈顶元素赋0，代表盘子已移走
			2、本函数为5行
***************************************************************************/
void array_move_plates(const char source_tower, const char destination_tower)
{
	TOWER[destination_tower - 'A'][MARK[destination_tower - 'A']++] = TOWER[source_tower - 'A'][--MARK[source_tower - 'A']];
	TOWER[source_tower - 'A'][MARK[source_tower - 'A']] = 0;
}

/***************************************************************************
  函数名称：console_print_base
  功    能：图形化输出三根柱子
  输入参数：无
  返 回 值：无
  说    明：1、本函数用参数控制柱子高度、宽度、位置等
			2、本函数为26行
***************************************************************************/
void console_print_base()
{
	const int bg_color = COLOR_HYELLOW;	//背景为亮黄色
	const int fg_color = COLOR_HBLUE;	//前景为亮蓝色
	int i, j;  /*计数变量*/

	/*光标位置初始化*/
	cct_gotoxy(CONSOLE_BASE_X, CONSOLE_BASE_Y);

	/*输出底盘*/
	for (i = 0; i < 3; i++) {
		Sleep(50);
		cct_showch(CONSOLE_BASE_X + i * (TOWER_WIDTH + TOWER_DISTANCE), CONSOLE_BASE_Y, ' ', bg_color, fg_color, TOWER_WIDTH);
	}

	/*输出柱子*/
	for (i = 0; i < TOWER_HEIGHT; i++) {
		for (j = 0; j < 3; j++) {
			Sleep(50);
			cct_showch(CONSOLE_BASE_X + (TOWER_WIDTH - 1) / 2 + j * (TOWER_WIDTH + TOWER_DISTANCE), CONSOLE_BASE_Y - i - 1, ' ', bg_color, fg_color, 1);
		}
	}

	/*输出完成后的颜色重设*/
	cct_setcolor();
}

/***************************************************************************
  函数名称：console_print_plates
  功    能：根据盘子数量及起始柱编号，图形化输出所有盘子
  输入参数：const int number_of_plates：盘子数量（只读）
            const char source_tower：起始柱编号（只读）
  返 回 值：无
  说    明：1、本函数根据参数控制的柱子位置，输出各个盘子
			2、本函数为26行
***************************************************************************/
void console_print_plates(const int number_of_plates, const char source_tower)
{
	const int mid = CONSOLE_BASE_X + (TOWER_WIDTH - 1) / 2 + (TOWER_WIDTH + TOWER_DISTANCE) * (source_tower - 'A'); /*每根柱子中间的位置*/
	int X, Y;                /*横坐标、纵坐标*/
	int bg_color, fg_color;  /*背景色、字体色*/
	int LENGTH;              /*盘子长度*/
	int i = 0;               /*计数变量*/

	/*输出盘子*/
	for (i = 0; i < number_of_plates; i++) {

		/*根据参数，确定各个变量的值*/
		X = mid - number_of_plates + i;
		Y = CONSOLE_BASE_Y - i - 1;
		bg_color = number_of_plates - i;
		fg_color = 7;
		LENGTH = 2 * number_of_plates + 1 - 2 * i;

		/*延时、输出*/
		Sleep(30);
		cct_showch(X, Y, ' ', bg_color, fg_color, LENGTH);
	}

	/*输出完成后的颜色重设*/
	cct_setcolor();
}

/***************************************************************************
  函数名称：console_show_move
  功    能：根据每一步移动信息和菜单函数返回值，显示盘子移动的动画
  输入参数：const int number_of_plates：盘子数量（只读）
			const char source_tower：起始柱编号（只读）
			const char destination_tower：目标柱编号（只读）
			const int menu：菜单函数返回值（只读）
  返 回 值：无
  说    明：1、本函数根据参数控制间断点的延时或中断
			2、本函数相当于移动的总控台，调用了多个显示单向移动动画的函数
			3、为了使参数传递，所有一次移动中所需的参数在本函数中先取好
			4、本函数为40行
***************************************************************************/
void console_show_move(const int number_of_plates, const char source_tower, const char destination_tower, const int menu)
{
	const int bg_color = number_of_plates;        /*背景色（根据盘子编号来取，保证移动过程中盘子不变色）*/
	const int fg_color = COLOR_WHITE;             /*字体色*/
	const int LENGTH = 2 * number_of_plates + 1;  /*盘子长度*/

	/*起始柱中间位置*/
	const int src_mid = CONSOLE_BASE_X + (TOWER_WIDTH - 1) / 2 + (TOWER_WIDTH + TOWER_DISTANCE) * (source_tower - 'A');
	/*目标柱中间位置*/
	const int dst_mid = CONSOLE_BASE_X + (TOWER_WIDTH - 1) / 2 + (TOWER_WIDTH + TOWER_DISTANCE) * (destination_tower - 'A');

	const int START_X = src_mid - TOWER[source_tower - 'A'][MARK[source_tower - 'A'] - 1];  /*起始横坐标*/
	const int START_Y = CONSOLE_BASE_Y - MARK[source_tower - 'A'];                          /*起始纵坐标*/
	const int END_X = dst_mid - number_of_plates;                          /*最终横坐标*/
	const int END_Y = CONSOLE_BASE_Y - MARK[destination_tower - 'A'] - 1;  /*最终纵坐标*/
	int time = 0;  /*延时参数*/

	/*取延时参数，若为菜单项7、8中的单步演示，延时100；若为菜单项8中的连续演示，延时delay_time；若为菜单项9，延时1，造成瞬移效果*/
	if (menu == 7 || (menu == 8 && __delay_time == 0))
		time = 100;
	else if (menu == 8 && __delay_time != 0)
		time = __delay_time;
	else if (menu == 9)
		time = 1;

	/*向上移动*/
	console_show_move_up(START_X, START_Y, bg_color, fg_color, src_mid, LENGTH, time);

	/*左右移动*/
	if (destination_tower < source_tower)
		console_show_move_left(START_X, END_X, bg_color, fg_color, LENGTH, time);
	else
		console_show_move_right(START_X, END_X, bg_color, fg_color, LENGTH, time);

	/*向下移动*/
	console_show_move_down(END_X, END_Y, bg_color, fg_color, dst_mid, LENGTH, time);

	/*移动完成后的颜色重设*/
	cct_setcolor();
}

/***************************************************************************
  函数名称：console_show_move_up
  功    能：根据总控台传来的每一步移动信息，显示盘子向上移动的动画
  输入参数：int START_X：起始横坐标
			int START_Y：起始纵坐标
			int bg_color：背景色
			int fg_color：字体色
			int src_mid：起始柱中间位置
			int LENGTH：盘子长度
			int time：延时参数
  返 回 值：无
  说    明：1、本函数根据参数控制间断点的延时或中断
			2、本函数接收了总控台传来的参数，决定本次的向上移动
			3、本函数为20行
***************************************************************************/
void console_show_move_up(int START_X, int START_Y, int bg_color, int fg_color, int src_mid, int LENGTH, int time)
{
	int Y;  /*显示动画中变动的当前纵坐标*/

	for (Y = START_Y; Y >= 1; Y--) {
		cct_showch(START_X, Y, ' ', bg_color, fg_color, LENGTH);

		/*若连续演示速度不为5，则启动延时*/
		if (time != 1)
			Sleep(time);

		/*到达最高点之前，用标准色擦除原有内容，造成动画效果*/
		if (Y > 1)
			cct_showch(START_X, Y, ' ', COLOR_BLACK, COLOR_WHITE, LENGTH);

		/*若未离开柱子，则需在柱子中间位置重新显示柱子，否则会被上一句擦除掉*/
		if (Y > TOWER_TOP)
			cct_showch(src_mid, Y, ' ', COLOR_HYELLOW, COLOR_WHITE, 1);
	}
}

/***************************************************************************
  函数名称：console_show_move_down
  功    能：根据总控台传来的每一步移动信息，显示盘子向下移动的动画
  输入参数：int END_X：最终横坐标
			int END_Y：最终纵坐标
			int bg_color：背景色
			int fg_color：字体色
			int dst_mid：目标柱中间位置
			int LENGTH：盘子长度
			int time：延时参数
  返 回 值：无
  说    明：1、本函数根据参数控制间断点的延时或中断
			2、本函数接收了总控台传来的参数，决定本次的向下移动
			3、本函数为20行
***************************************************************************/
void console_show_move_down(int END_X, int END_Y, int bg_color, int fg_color, int dst_mid, int LENGTH, int time)
{
	int Y;  /*显示动画中变动的当前纵坐标*/

	for (Y = 1; Y <= END_Y; Y++) {
		cct_showch(END_X, Y, ' ', bg_color, fg_color, LENGTH);

		/*若连续演示速度不为5，则启动延时*/
		if (time != 1)
			Sleep(time);

		/*到达最低点之前，用标准色擦除原有内容，造成动画效果*/
		if (Y < END_Y)
			cct_showch(END_X, Y, ' ', COLOR_BLACK, COLOR_WHITE, LENGTH);

		/*若进入柱子，则需在柱子中间位置重新显示柱子，否则会被上一句擦除掉*/
		if (Y > TOWER_TOP && Y < END_Y)
			cct_showch(dst_mid, Y, ' ', COLOR_HYELLOW, COLOR_WHITE, 1);
	}
}

/***************************************************************************
  函数名称：console_show_move_left
  功    能：根据总控台传来的每一步移动信息，显示盘子向左移动的动画
  输入参数：int START_X：起始横坐标
            int END_X：最终横坐标
			int bg_color：背景色
			int fg_color：字体色
			int LENGTH：盘子长度
			int time：延时参数
  返 回 值：无
  说    明：1、本函数根据参数控制间断点的延时或中断
			2、本函数接收了总控台传来的参数，决定本次的向左移动
			3、本函数为16行
***************************************************************************/
void console_show_move_left(int START_X, int END_X, int bg_color, int fg_color, int LENGTH, int time)
{
	int X;  /*显示动画中变动的当前横坐标*/

	for (X = START_X; X >= END_X; X--) {
		cct_showch(X, 1, ' ', bg_color, fg_color, LENGTH);

		/*若连续演示速度不为5，则启动延时*/
		if (time != 1)
			Sleep(time);

		/*到达最左侧之前，用标准色擦除原有内容，造成动画效果*/
		if (X > END_X)
			cct_showch(X, 1, ' ', COLOR_BLACK, COLOR_WHITE, LENGTH);
	}
}

/***************************************************************************
  函数名称：console_show_move_right
  功    能：根据总控台传来的每一步移动信息，显示盘子向右移动的动画
  输入参数：int START_X：起始横坐标
			int END_X：最终横坐标
			int bg_color：背景色
			int fg_color：字体色
			int LENGTH：盘子长度
			int time：延时参数
  返 回 值：无
  说    明：1、本函数根据参数控制间断点的延时或中断
			2、本函数接收了总控台传来的参数，决定本次的向右移动
			3、本函数为16行
***************************************************************************/
void console_show_move_right(int START_X, int END_X, int bg_color, int fg_color, int LENGTH, int time)
{
	int X;  /*显示动画中变动的当前横坐标*/

	for (X = START_X; X <= END_X; X++) {
		cct_showch(X, 1, ' ', bg_color, fg_color, LENGTH);

		/*若连续演示速度不为5，则启动延时*/
		if (time != 1)
			Sleep(time);

		/*到达最右侧之前，用标准色擦除原有内容，造成动画效果*/
		if (X < END_X)
			cct_showch(X, 1, ' ', COLOR_BLACK, COLOR_WHITE, LENGTH);
	}
}

/***************************************************************************
  函数名称：game_command_center
  功    能：根据每一步输入指令，移动盘子，达到游戏化效果
  输入参数：const int total_number_of_plates：盘子数量（只读）
			const char destination_tower：目标柱编号（只读）
			const int menu：菜单函数返回值（只读）
  返 回 值：无
  说    明：1、本函数相当于游戏的总控台，调用了多个游戏有关的函数
			2、为了使参数传递，所有一次移动中所需的参数在本函数中先取好
			3、本函数为48行
***************************************************************************/
void game_command_center(const int total_number_of_plates, const char destination_tower, const int menu)
{
	cct_setcursor(CURSOR_VISIBLE_NORMAL);  /*显示光标*/
	cct_gotoxy(0, GAME_TIP_Y);    /*移动光标至指定位置*/
	cout << "请输入移动的柱号(命令形式：AC=A顶端的盘子移动到C，Q=退出) ：";  /*输出提示语。改变提示语长度时，请同步改变#define TIP_LENGTH*/

	while (1) {
		int i = 0;  /*计数变量，每一次循环结束归零*/
		char src = 0, dst = 0, c;  /*起始柱编号（每一次循环结束归零）、目标柱编号（每一次循环结束归零）、提取字符*/

		/*1、输入指令*/
		while (1) {
			c = getchar();  /*逐个提取字符*/

			if (c == '\n' || c == 'q' || c == 'Q')  /*若有换行符或退出指令，结束输入*/
				break;

			if (i == 0)  /*若输入未结束，第一个字符赋给src*/
				src = c;

			if (i == 1)  /*若输入未结束，第二个字符赋给dst*/
				dst = c;

			i++;  /*每输入一个字符，计数变量自增，统计输入的字符数*/
		}

		/*2、若c为退出指令，输出提示语并结束游戏*/
		if (c == 'q' || c == 'Q') {
			cout << "游戏中止!!!!!";
			break;
		}

		/*3、若刚好输入两个不等的字符，调整大小写，判断是否可以移动并移动盘子*/
		if (i == 2 && src != dst) {
			if (src >= 'a' && src <= 'c')
				src = src - 'a' + 'A';
			if (dst >= 'a' && dst <= 'c')
				dst = dst - 'a' + 'A';

			game_get_info_and_move(src, dst, menu);
		}

		/*4、若1号盘已经到达最终位置，则判断游戏结束*/
		if (TOWER[destination_tower - 'A'][total_number_of_plates - 1] == 1) {
			cct_gotoxy(0, GAME_TIP_Y + 1);
			cout << "游戏结束!!!!!";
			break;
		}

		/*5、输入指令错误，或者是每完成一步移动后，清除原有指令（位置靠后，不会在游戏结束或错误提示时先清空原有指令）*/
		else
			game_clear_input();
	}
}

/***************************************************************************
  函数名称：game_clear_input
  功    能：清除游戏中原有的输入指令
  输入参数：无
  返 回 值：无
  说    明：1、本函数只能清除与提示语同一行的指令，最多可清除60个字符
			2、本函数为11行
***************************************************************************/
void game_clear_input()
{
	int j;

	cct_gotoxy(TIP_LENGTH, GAME_TIP_Y);

	for (j = 0; j < 60; j++)
		cout << '\040';

	cct_gotoxy(TIP_LENGTH, GAME_TIP_Y);
}

/***************************************************************************
  函数名称：game_get_info_and_move
  功    能：根据输入指令，取得各项信息，并判断是否移动
  输入参数：const char source_tower：起始柱编号（只读）
            const char destination_tower：目标柱编号（只读）
			const int menu：菜单函数返回值（只读）
  返 回 值：无
  说    明：1、这一部分涉及多个参数的取值、判断，故虽然功能比较杂乱，但需写为一个函数
			2、本函数为22行
***************************************************************************/
void game_get_info_and_move(const char source_tower, const char destination_tower, const int menu)
{
	/*根据柱子编号，取栈顶元素的值（空为零，错误为负）*/
	int number_of_src = game_get_plate_num(source_tower);
	int number_of_dst = game_get_plate_num(destination_tower);

	/*只有当两个栈顶元素值都不为负（都正确）的时候，才进行下一步判断*/
	if (number_of_src >= 0 && number_of_dst >= 0) {

		/*起始柱为空的情况*/
		if (TOWER[source_tower - 'A'][0] == 0)
			game_err(EmptySourceTower);

		/*大盘压小盘的情况*/
		else if (number_of_src > number_of_dst && number_of_dst != 0)
			game_err(BigOnSmall);

		/*准备就绪，可以移动的情况*/
		else
			game_ok_move(number_of_src, source_tower, destination_tower, menu);
	}
}

/***************************************************************************
  函数名称：game_get_plate_num
  功    能：根据输入的柱子标号，取得栈顶盘子的编号
  输入参数：const char tower：柱子编号（只读）
  返 回 值：整数
  说    明：1、若该柱为空，返回零；若编号字符错误，返回负数
			2、本函数为21行
***************************************************************************/
int game_get_plate_num(const char tower)
{
	/*柱子编号范围正确*/
	if (tower >= 'A' && tower <= 'C') {

		/*使用只读字符变量接收参数tower，消除智能提示*/
		const char Tower = tower;

		/*若栈底元素不为零，说明该柱不为空，返回栈顶元素的值*/
		if (TOWER[Tower - 'A'][0])
			return TOWER[Tower - 'A'][MARK[Tower - 'A'] - 1];

		/*若栈底元素为零，说明该柱为空，返回零*/
		else
			return 0;
	}

	/*若柱子编号不正确，返回负数*/
	else
		return -1;
}

/***************************************************************************
  函数名称：game_err
  功    能：移动发生错误时，输出错误提示
  输入参数：const int err_info：错误信息（只读）
  返 回 值：无
  说    明：1、本函数根据错误信息打印提示语
            2、本函数根据提示语的长度打印相等数量的空格，达到覆盖的效果
			3、本函数为23行
***************************************************************************/
void game_err(const int err_info)
{
	unsigned int i;  /*计数变量*/
	char c[128];     /*接收提示语的字符数组*/

	/*根据错误信息制定提示语*/
	if (err_info == 1)
		strcpy(c, "源柱为空!");
	else if (err_info == 2)
		strcpy(c, "大盘压小盘，非法移动!");

	/*输出提示语并暂停*/
	cout << c;
	Sleep(1000);

	/*消除提示语并使光标复位*/
	cct_gotoxy(0, GAME_TIP_Y + 1);

	for (i = 0; i < strlen(c); i++)
		cout << '\040';

	cct_gotoxy(TIP_LENGTH, GAME_TIP_Y);
}

/***************************************************************************
  函数名称：game_ok_move
  功    能：经过多重检验，判定可以移动后，移动盘子
  输入参数：const in number_of_plates：盘子编号（只读）
            const char source_tower：起始柱编号（只读）
			const char destination_tower：目标柱编号（只读）
			const int menu：菜单函数返回值（只读）
  返 回 值：无
  说    明：1、本函数调用了许多已有函数，达到移动盘子的效果
			2、本函数为11行
***************************************************************************/
void game_ok_move(const int number_of_plates, const char source_tower, const char destination_tower, const int menu)
{
	__stepnumber++;  /*步数自增*/
	array_move_plates(source_tower, destination_tower);  /*改变数组值，内部数组达到移动盘子的效果*/
	array_print_tower(number_of_plates, source_tower, destination_tower, menu);  /*横式打印内部数组*/
	array_show_move(source_tower, destination_tower, menu);  /*改变数值位置，纵向输出达到移动盘子的效果*/

	array_move_plates(destination_tower, source_tower);  /*将这一步数组值复位，以便下一步图形化输出能使用移动前的内部数组值*/
	console_show_move(number_of_plates, source_tower, destination_tower, menu);  /*改变盘子位置，图形输出达到移动盘子的效果*/
	array_move_plates(source_tower, destination_tower);  /*改变数组值，内部数组达到移动盘子的效果*/
}

/***************************************************************************
  函数名称：input_info
  功    能：通过正确性处理，输入多个所需的参数
  输入参数：int* plate_number：盘子数量
			char* src_tower：起始柱编号
			char* dst_tower：目标柱编号
			int* delay_time_set：移动速度标号
			const int menu：菜单函数返回值（只读）
  返 回 值：无
  说    明：1、本函数调用了各类正确性处理函数
			2、所有参数均为指针类型，可以改变多个实参值
			3、本函数为11行
***************************************************************************/
void input_info(int* number_of_plates, char* source_tower, char* destination_tower, int* delay_time_set, const int menu)
{
	if (menu != 5) {  /*菜单项5不需要输入信息*/
		input_number_of_plates(number_of_plates);
		input_source_tower(source_tower);
		input_destination_tower(destination_tower, source_tower);
	}

	if (menu == 4 || menu == 8)  /*菜单项4和菜单项8需要输入延时参数*/
		input_delay(delay_time_set);
}

/***************************************************************************
  函数名称：input_number_of_plates
  功    能：通过正确性处理，输入汉诺塔的层数
  输入参数：int* number_of_plates：盘子数量
  返 回 值：无
  说    明：1、参数为指针类型，可以改变实参值
			2、本函数为28行
***************************************************************************/
void input_number_of_plates(int* number_of_plates)
{
	int n;

	while (1) {
		cout << "请输入汉诺塔的层数(1-" << PLATE_NUM_LIMIT << ")：" << endl;
		cin >> n;
		if (n >= 1 && n <= PLATE_NUM_LIMIT && cin.good() == 1) {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			break;
		}

		/*只剩非法输入，或数值超类型范围的处理*/
		else if ((n < 1 || n > PLATE_NUM_LIMIT) && cin.good() == 0) {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}

		/*读取状态正常，超过用户范围时的处理*/
		else if ((n < 1 || n > PLATE_NUM_LIMIT) && cin.good() == 1) {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}
	}

	*number_of_plates = n;
}

/***************************************************************************
  函数名称：input_source_tower
  功    能：通过正确性处理，输入代表起始柱字母的ASCII
  输入参数：char* source_tower：起始柱编号
  返 回 值：无
  说    明：1、无论输入大写或小写，返回值统一为对应大写字母的ASCII
			2、参数为指针类型，可以改变实参值
			3、本函数为33行
***************************************************************************/
void input_source_tower(char* source_tower)
{
	char src;
	while (1) {
		cout << "请输入起始柱(A-C)：" << endl;
		cin >> src;
		if (((src >= 'a' && src <= 'c') || (src >= 'A' && src <= 'C')) && cin.good() == 1) {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			break;
		}

		/*只剩非法输入，或数值超类型范围的处理*/
		else if (((src < 'a' || src > 'c') || (src < 'A' || src > 'C')) && cin.good() == 0) {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}

		/*读取状态正常，超过用户范围时的处理*/
		else if (((src < 'a' || src > 'c') || (src < 'A' || src > 'C')) && cin.good() == 1) {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}
	}

	if (src >= 'a' && src <= 'c') {
		*source_tower = src - 32;
	}

	else {
		*source_tower = src;
	}
}

/***************************************************************************
  函数名称：input_destination_tower
  功    能：通过正确性处理，输入代表目标柱字母的ASCII
  输入参数：char* destination_tower：目标柱编号
            const char* source_tower：起始柱编号（只读）
  返 回 值：无
  说    明：1、无论输入大写或小写，返回值统一为对应大写字母的ASCII
			2、该函数通过输入参数*src_tower，判断*dst_tower与其是否相等
			3、参数为指针类型，可以改变实参值（除只读变量）
			4、本函数为48行
***************************************************************************/
void input_destination_tower(char* destination_tower, const char* source_tower)
{
	char dst;
	while (1) {
		cout << "请输入目标柱(A-C)：" << endl;
		cin >> dst;
		if (((dst >= 'a' && dst <= 'c') || (dst >= 'A' && dst <= 'C')) && cin.good() == 1) {
			if (dst != *source_tower && dst != *source_tower + 32 && dst != *source_tower - 32) {
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				break;
			}

			/*dst与src相等时的处理*/
			else {

				/*为了使提示语中的dst输出为大写，对dst的值进行处理*/
				if (dst >= 'a' && dst <= 'c') {
					dst = dst - 32;
				}

				cout << "目标柱(" << dst << ")不能与起始柱(" << *source_tower << ")相同" << endl;
				cin.clear();
				cin.ignore(INT_MAX, '\n');
			}
		}

		/*只剩非法输入，或数值超类型范围的处理*/
		else if (((dst < 'a' || dst > 'c') || (dst < 'A' || dst > 'C')) && cin.good() == 0) {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}

		/*读取状态正常，超过用户范围时的处理*/
		else if (((dst < 'a' || dst > 'c') || (dst < 'A' || dst > 'C')) && cin.good() == 1) {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}
	}

	if (dst >= 'a' && dst <= 'c') {
		*destination_tower = dst - 32;
	}

	else {
		*destination_tower = dst;
	}
}

/***************************************************************************
  函数名称：delay
  功    能：通过正确性处理，输入并给标志延时时长的全局变量delay_time赋值
  输入参数：int* delay_time_set：移动速度标号
  返 回 值：无
  说    明：1、若d为零，则返回0；若d不为零，延时时长的计算方法为1000除以移动速度的二次方
			2、参数为指针类型，可以改变实参值
			3、本函数为40行
***************************************************************************/
void input_delay(int* delay_time_set)
{
	int i;
	while (1) {
		cout << "请输入移动速度(0-5: 0-按回车单步演示 1-延时最长 5-延时最短)" << endl;
		cin >> i;
		if (i >= 0 && i <= 5 && cin.good() == 1) {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			break;
		}

		/*只剩非法输入，或数值超类型范围的处理*/
		else if (cin.good() == 0) {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}

		/*读取状态正常，超过用户范围时的处理*/
		else if ((i < 0 || i > 5) && cin.good() == 1) {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}
	}

	/*根据i的输入值，给全局变量delay_time赋值*/
	if (i == 0)
		__delay_time = 0;

	else if (i >= 1 && i <= 3)
		__delay_time = 130 - 30 * i;

	else if (i == 4)
		__delay_time = 15;

	else if (i == 5)
		__delay_time = 1;

	*delay_time_set = i;
}

/***************************************************************************
  函数名称：pause
  功    能：中断或延缓程序的进行
  输入参数：const int delay_time_set：移动速度标号（只读）
  返 回 值：无
  说    明：1、只有菜单第4、8项用到该函数
			2、此函数根据移动速度是否为零，决定中断还是延时
			3、此函数为16行
***************************************************************************/
void pause(const int delay_time_set)
{
	int c;

	if (delay_time_set > 0 && delay_time_set != 5)
		Sleep(__delay_time);

	else {
		while (1) {
			c = _getch();

			if (c == '\r')
				break;
		}
	}
}

/***************************************************************************
  函数名称：reset
  功    能：程序运行完一次后，重设所有参数，并使程序暂停
  输入参数：const int menu：菜单函数返回值（只读）
  返 回 值：无
  说    明：1、根据菜单函数返回值，决定是否移动光标后再输出提示语
			2、重置stepnumber、delay_time等静态全局变量
			3、暂停后，再按回车继续时，清理屏幕
			4、此函数为23行
***************************************************************************/
void reset(const int menu)
{
	/*菜单项1-3输出完成后不需要移动光标，输出换行符即可*/
	if (menu >= 1 && menu <= 3)
		cout << endl;

	/*重置颜色*/
	cct_setcolor();

	/*菜单项4-9输出完成后需要移动光标，根据菜单函数返回值调整参数*/
	if (menu >= 4 && menu <= 8)
		cct_gotoxy(0, CONSOLE_BASE_Y + PLATE_NUM_LIMIT + 9);

	else if (menu == 9)
		cct_gotoxy(0, CONSOLE_BASE_Y + PLATE_NUM_LIMIT + 13);

	cout << "按回车键继续"; /*输出提示语*/
	__stepnumber = 0;         /*重置记录步数的静态全局变量*/
	__delay_time = 0;         /*重置标志延时时长的静态全局变量*/

	pause(0);   /*所有重置项完成后的中断*/
	cct_cls();  /*清理屏幕*/
}

/***************************************************************************
  函数名称：command_center
  功    能：根据菜单函数返回值，选择调用不同函数，充当控制台的作用
  输入参数：int number_of_plates：盘子数量
            char source_tower：起始柱编号
			char temporary_tower：中间柱编号
			char destination_tower：目标柱编号
			int delay_time_set：移动速度标号
			int menu：菜单函数返回值
  返 回 值：无
  说    明：1、根据菜单函数返回值，选择调用不同附件或函数
			2、此函数为23行
***************************************************************************/
void command_center(int number_of_plates, char source_tower, char temporary_tower, char destination_tower, int delay_time_set, int menu)
{
	/*清空屏幕*/
	if (menu >= 4 && menu <= 9)
		cct_cls();

	/*内部数组初始化*/
	if (menu == 3 || menu == 4 || menu == 7 || menu == 8 || menu == 9)
		array_tower_initialize(number_of_plates, source_tower);

	command_info(number_of_plates, source_tower, destination_tower, delay_time_set, menu);  /*输出提示语*/
	command_array_base(number_of_plates, source_tower, destination_tower, menu);  /*输出纵向数组*/
	command_console_base(number_of_plates, source_tower, menu);  /*输出柱子和盘子*/
	command_delay(menu);  /*控制中断或延时*/

	/*调用递归函数*/
	if (menu != 5 && menu != 6 && menu != 9)
		hanoi(number_of_plates, source_tower, temporary_tower, destination_tower, menu);

	/*运行游戏*/
	if (menu == 9)
		game_command_center(number_of_plates, destination_tower, menu);
}

/***************************************************************************
  函数名称：command_info
  功    能：控制台附件，根据菜单函数返回值打印提示信息
  输入参数：const int number_of_plates：盘子数量（只读）
			const char source_tower：起始柱编号（只读）
			const char destination_tower：目标柱编号（只读）
			const int delay_time_set：移动速度标号（只读）
			const int menu：菜单函数返回值（只读）
  返 回 值：无
  说    明：1、根据菜单函数返回值，在按要求共用函数的情况下，选择调用不同函数
			2、此函数为8行
***************************************************************************/
void command_info(const int number_of_plates, const char source_tower, const char destination_tower, const int delay_time_set, const int menu)
{
	if (menu == 4 || menu == 6 || menu == 7 || menu == 8 || menu == 9)
		cout << "从 " << source_tower << " 移动到 " << destination_tower << "，共 " << number_of_plates << " 层";

	if (menu == 4 || menu == 8)
		cout << " ，延时设置为 " << delay_time_set;
}

/***************************************************************************
  函数名称：command_array_base
  功    能：控制台附件，根据菜单函数返回值打印纵向数组
  输入参数：const int number_of_plates：盘子数量（只读）
			const char source_tower：起始柱编号（只读）
			const char destination_tower：目标柱编号（只读）
			const int menu：菜单函数返回值（只读）
  返 回 值：无
  说    明：1、根据菜单函数返回值，在按要求共用函数的情况下，选择调用不同函数
			2、此函数为14行
***************************************************************************/
void command_array_base(const int number_of_plates, const  char source_tower, const char destination_tower, const int menu)
{
	if (menu == 4 || menu == 8 || menu == 9) {
		array_print_tower(number_of_plates, source_tower, destination_tower, menu);
		array_print_base(number_of_plates, source_tower, menu);
	}
}

/***************************************************************************
  函数名称：command_console_base
  功    能：控制台附件，根据菜单函数返回值图形化柱子与盘子
  输入参数：const int number_of_plates：盘子数量（只读）
			const char source_tower：起始柱编号（只读）
			const int menu：菜单函数返回值（只读）
  返 回 值：无
  说    明：1、根据菜单函数返回值，在按要求共用函数的情况下，选择调用不同函数
			2、此函数为8行
***************************************************************************/
void command_console_base(const int number_of_plates, const  char source_tower, const int menu)
{
	if (menu >= 5 && menu <= 9)
		console_print_base();

	if (menu >= 6 && menu <= 9)
		console_print_plates(number_of_plates, source_tower);
}

/***************************************************************************
  函数名称：command_delay
  功    能：控制台附件，根据菜单函数返回值，控制初始工作完成后的中断或延时
  输入参数：const int menu：菜单函数返回值（只读）
  返 回 值：无
  说    明：1、根据菜单函数返回值，在按要求共用函数的情况下，选择调用不同函数
			2、此函数为11行
***************************************************************************/
void command_delay(const int menu)
{
	if (menu == 4 || menu == 8)
		pause(__delay_time);

	else if (menu == 7)
		Sleep(1000);

	else if (menu == 9)
		Sleep(100);
}