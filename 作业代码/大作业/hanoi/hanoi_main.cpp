/*2151294 信11 马威*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include "cmd_console_tools.h"
#include "hanoi.h"
using namespace std;

/* ----------------------------------------------------------------------------------

     本文件功能：
	1、放main函数
	2、初始化屏幕
	3、调用菜单函数（hanoi_menu.cpp中）并返回选项
	4、根据选项调用菜单各项对应的执行函数（hanoi_multiple_solutions.cpp中）

     本文件要求：
	1、不允许定义全局变量（含外部全局和静态全局，const及#define不在限制范围内）
	2、静态局部变量的数量不限制，但使用准则也是：少用、慎用、能不用尽量不用
	3、按需加入系统头文件、自定义头文件、命名空间等

   ----------------------------------------------------------------------------------- */

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main()
{
	/* demo中首先执行此句，将cmd窗口设置为40行x120列（缓冲区宽度120列，行数9000行，即cmd窗口右侧带有垂直滚动杆）*/
	cct_setconsoleborder(120, 40, 120, 9000);

	while (1) {
		int MENU = menu();         /*定义变量，接收菜单函数返回值*/
		cout << MENU << "\n\n\n";  /*回显，调整输出位置*/
		Sleep(200);                /*延时，改善观感*/

		/*菜单项为0，直接退出*/
		if (MENU == 0)
			break;

		int number_of_plates, * nop = &number_of_plates;  /*定义表示盘子数量的变量及其指针*/
		int delay_time_set = 0, * dts = &delay_time_set;  /*定义表示移动速度标号的变量及其指针*/
		char src_tower, * st = &src_tower;  /*定义表示起始柱编号的变量及其指针*/
		char dst_tower, * dt = &dst_tower;  /*定义表示目标柱编号的变量及其指针*/

		/*调用输入函数，正确输入各项参数*/
		input_info(nop, st, dt, dts, MENU);

		/*根据起始柱、目标柱的编号，确定中间柱的编号*/
		char tmp_tower = 'A' + 'B' + 'C' - src_tower - dst_tower;

		/*隐藏光标*/
		cct_setcursor(CURSOR_INVISIBLE);

		/*汇总所有参数，调用控制台，选择调用不同函数*/
		command_center(number_of_plates, src_tower, tmp_tower, dst_tower, delay_time_set, MENU);

		/*显示光标*/
		cct_setcursor(CURSOR_VISIBLE_NORMAL);

		/*每次执行完成后的暂停*/
		reset(MENU);
	}
	
	return 0;
}