/*2151294 信11 马威*/
#include <iostream>
#include <conio.h>
#include <Winsock2.h>
#include <Windows.h>
#include "cmd_console_tools.h"
#include "90-b2.h"
using namespace std;

/***************************************************************************
  函数名称：menu
  功    能：显示各菜单项，读入正确的选项后返回
  输入参数：无
  返 回 值：int：菜单项对应的编号
  说    明：已按要求控制读入正确选项，若编号为字母则返回对应大写字母的ASCII码
***************************************************************************/
int menu()
{
	int ret;
	cout << "---------------------------------------\n"
		<< "1.命令行找出可合成项并标识（非递归）\n"
		<< "2.命令行找出可合成项并标识（递归）\n"
		<< "3.命令行完成一次合成（分步骤显示）\n"
		<< "4.命令行完整版（分步骤显示）\n"
		<< "5.伪图形界面显示初始数组（无分隔线）\n"
		<< "6.伪图形界面显示初始数组（有分隔线）\n"
		<< "7.伪图形界面下用箭头键/鼠标选择当前色块\n"
		<< "8.伪图形界面完成一次合成（分步骤）\n"
		<< "9.伪图形界面完整版（支持鼠标）\n"
		<< "---------------------------------------\n"
		<< "A.命令行界面（网络自动解-基本版）\n"
		<< "B.伪图形界面（网络自动解-基本版）\n"
		<< "C.命令行方式（网络自动解-竞赛版）\n"
		<< "---------------------------------------\n"
		<< "0.退出\n"
		<< "---------------------------------------\n"
		<< "[请选择]: ";

	while (1) {
		ret = _getch();

		if ((ret >= '0' && ret <= '9') || (ret >= 'A' && ret <= 'C'))
			break;

		else if (ret >= 'a' && ret <= 'c') {
			ret = ret - 'a' + 'A';
			break;
		}
	}

	/*若输入1-9，回显所选菜单项编号，返回对应数值*/
	if (ret >= '0' && ret <= '9') {
		cout << ret - '0' << endl;
		return ret - '0';
	}

	/*若输入字母，回显所选菜单项编号，返回对应字母的ASCII码*/
	else {
		cout << char(ret) << endl;
		return ret;
	}
}

/***************************************************************************
  函数名称：single_input
  功    能：在正确性处理的前提下，输入一个变量的值
  输入参数：int* num：待输入数值的变量
            const int input_mode：输入模式（只读，就是指输入哪个变量）
  返 回 值：无
  说    明：本函数按输入模式设置提示内容和正确性处理的上下限
***************************************************************************/
void single_input(int* num, const int input_mode)
{
	int n, min = 0, max = 0;  /*输入值、上下限*/

	while (1) {
		cout << "请输入";

		switch (input_mode) {  /*根据输入的变量设置上下限*/
			case INPUT_LINE:   /*输入操作行数*/
				cout << "行数";
				min = LINE_MIN;
				max = LINE_MAX;
				break;
			case INPUT_ROW:    /*输入操作列数*/
				cout << "列数";
				min = ROW_MIN;
				max = ROW_MAX;
				break;
			case INPUT_GOAL:   /*输入合成目标*/
				cout << "合成目标";
				min = GOAL_MIN;
				max = GOAL_MAX;
				break;
		}

		cout << "(" << min << "-" << max << ")：" << endl;
		cin >> n;  /*输入变量值*/

		if (n >= min && n <= max && cin.good() == 1) {
			cin.ignore(INT_MAX, '\n');
			break;
		}

		else if ((n < min || n > max) && cin.good() == 0) {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}

		else if ((n < min || n > max) && cin.good() == 1)
			cin.ignore(INT_MAX, '\n');
	}

	*num = n;  /*改变对应的实参值*/
}

/***************************************************************************
  函数名称：multiple_input
  功    能：在正确性处理的前提下，输入多个变量的值
  输入参数：int* line：操作行数
            int* row：操作列数
			int* goal：合成目标
			const int menu：菜单函数返回值（只读）
  返 回 值：无
  说    明：无
***************************************************************************/
void multiple_input(int* line, int* row, int* goal, const int menu)
{
	single_input(line, INPUT_LINE);  /*输入操作行数*/
	single_input(row, INPUT_ROW);    /*输入操作列数*/

	if (menu == 3 || menu == 4 || menu == 9)
		single_input(goal, INPUT_GOAL);  /*输入合成目标*/
}

/***************************************************************************
  函数名称：main
  功    能：主函数
  输入参数：无
  返 回 值：0
  说    明：无
***************************************************************************/
int main()
{
	cct_cls();       /*清空屏幕*/
	cct_setcolor();  /*重设颜色，避免上次退出时未重设颜色而导致界面颜色不对*/
	srand((unsigned int)(time(0)));    /*生成伪随机数的种子*/

	/*整个游戏中的结构体二维数组。由于无法动态定义，故设为行和列的最大值*/
	/*为避免发生数组越界，后续程序需输入操作行数和列数*/
	MATRIX matrix[LINE_MAX][ROW_MAX];

	while (1) {
		int MENU = menu();  /*输入菜单项*/
		Sleep(200);         /*延时，改善观感*/

		/*菜单项为0，直接退出；否则清屏*/
		if (MENU == 0)
			break;
		else
			cct_cls();

		int line, * p1 = &line;      /*操作行数及其对应指针*/
		int row, * p2 = &row;        /*操作列数及其对应指针*/
		int goal = 5, * p3 = &goal;  /*合成目标及其对应指针*/
		int score = 0;  /*得分*/
		char coord[2];  /*某一元素的坐标*/

		/*调用输入函数，正确输入各项参数*/
		if (MENU >= 1 && MENU <= 9)
			multiple_input(p1, p2, p3, MENU);

		/*根据行数和列数对数组进行初始化*/
		if (MENU >= 1 && MENU <= 9)
			array_initialize(matrix, line, row);

		/*伪图形界面下隐藏光标及清屏*/
		if (MENU >= 5 && MENU <= 9) {
			cct_setcursor(CURSOR_INVISIBLE);
			cct_cls();
		}

		/*单机版控制台*/
		if (MENU >= 1 && MENU <= 9)
			command_center(matrix, line, row, goal, score, coord, MENU);
		/*网络版--基本版*/
		else if (MENU == 'A' || MENU == 'B') {
			net_main(matrix, MENU);
			end();
		}
		/*网络版--竞赛版*/
		else {
			competition();
			end();
		}

		/*每次执行完成后的清屏、重设颜色*/
		cct_cls();
		cct_setcolor();
	}

	return 0;
}