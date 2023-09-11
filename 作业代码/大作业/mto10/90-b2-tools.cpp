/*2151294 信11 马威*/
#include <iostream>
#include <conio.h>
#include <Winsock2.h>
#include <Windows.h>
#include "90-b2.h"
#include "cmd_console_tools.h"
using namespace std;

/***************************************************************************
  函数名称：command_center
  功    能：单机版控制台，选择调用不同函数完成功能的实现
  输入参数：MATRIX matrix[][ROW_MAX]：整个游戏中的结构体二维数组
            const int line：操作行数（只读）
			const int row：操作列数（只读）
			int goal：初始合成目标
			int score：得分
			char coord[]：可用来存放元素坐标的字符数组
			const int menu：菜单函数返回值（只读）
  返 回 值：无
  说    明：无
***************************************************************************/
void command_center(MATRIX matrix[][ROW_MAX], const int line, const int row, int goal, int score, char coord[], const int menu)
{
	/*******************************命令行方式*******************************/
	if (menu >= 1 && menu <= 4) {
		int loop = 1;

		while (loop) {

			if (menu != 4)  /*若不为菜单项4，只执行一次，loop置为0*/
				loop = 0;

			else {  /*若为菜单项4，先检查是否达到了当前合成目标*/
				if (array_getmax(matrix, line, row) == goal) {
					command_goal_achieved(goal);
					pause();
				}

				array_mark_set(matrix, line, row);  /*重置数组标记情况*/
			}

			/*显示当前数组值*/
			cout << endl << "当前数组：" << endl;
			array_show(matrix, line, row, ARRAY_SHOW_CURRENT);
			cout << endl;

			/*检查是否仍有可合成项，判断游戏是否继续*/
			if (if_end(matrix, line, row) == true) {
				command_end();
				break;
			}

			do {  /*输入坐标直到该坐标周围有相同值为止*/
				input_coord(line, row, coord);

				if (menu == 2)
					array_multiple_scan2(matrix, line, row, coord);  /*菜单项2用递归方式寻找可合成项*/
				else
					array_multiple_scan1(matrix, line, row, coord, menu);  /*其他项（包括菜单项1）用非递归方式寻找可合成项*/

			} while (array_mark_count(matrix, line, row) == 0);

			/*两种方式显示查找结果*/
			cout << endl << "查找结果数组：" << endl;
			array_show(matrix, line, row, ARRAY_SHOW_RESULT);
			cout << endl << endl << "当前数组(不同色标识)：" << endl;
			array_show(matrix, line, row, ARRAY_SHOW_CURRENT);

			/*菜单项3、4继续输入指令，确认是否进行本次合成*/
			if (menu == 3 || menu == 4) {
				char command = clear_command(coord);  /*输入指令*/

				/*输入Y*/
				if (command == 'Y') {

					/*归并相同值并显示归并后的数组*/
					array_clear(matrix, line, row, coord);
					cout << endl << "相同值归并后的数组(不同色标识)：" << endl;
					array_show(matrix, line, row, ARRAY_SHOW_CURRENT);

					/*计算得分、打印得分*/
					int _getscore = array_getscore(matrix, line, row);
					score = score + _getscore;
					print_score(_getscore, score, goal, menu);

					/*设置断点、除零、显示除零后的数组*/
					cout << endl << "按回车键进行数组下落除0操作...";
					pause();
					array_move_zero(matrix, line, row);
					cout << endl << "除0后的数组(不同色标识)：" << endl;
					array_show(matrix, line, row, ARRAY_SHOW_CURRENT);

					/*设置断点、新值填充、显示新值填充后的数组*/
					cout << endl << "按回车键进行新值填充...";
					pause();
					array_random(matrix, line, row, array_getmax(matrix, line, row));
					cout << endl << "新值填充后的数组(不同色标识)：" << endl;
					array_show(matrix, line, row, ARRAY_SHOW_CURRENT);
					cout << endl;

					if (menu == 4) {  /*菜单项4的特别提示*/
						cout << "本次合成结束，按回车键继续新一次的合成..." << endl;
						pause();
					}
				}

				/*菜单项3不为Y、菜单项4为Q则在此结束循环*/
				else if ((menu == 3 && command != 'Y') || (menu == 4 && command == 'Q'))
					break;
				/*菜单项4为N继续循环*/
				else
					continue;
			}
		}

		end();  /*本小题结束，请输入End继续...*/
	}

	/*******************************伪图形界面*******************************/

	else if (menu >= 5 && menu <= 9) {
		if (menu == 5)  /*菜单项5无分隔线*/
			console_print_base(matrix, line, row, PRINT_WITHOUT_LINE);
		else            /*其他项有分割线*/
			console_print_base(matrix, line, row, PRINT_WITH_LINE);

		int MK_RET1, MK_RET2, loop1 = 1;  /*两个读键鼠的返回值*/

		while (loop1) {
			if (menu == 5 || menu == 6)  /*菜单项5、6在此结束*/
				break;
			else if (menu == 7)  /*菜单项7在loop1内只执行1次，loop1置为0*/
				loop1 = 0;

			int loop2 = 1;

			/*若菜单项为9，判断是否结束*/
			if (if_end(matrix, line, row) == true && menu == 9) {
				special_info(line, goal, INFO_END);  /*结束提示*/

				while (1) {  /*按Q退出*/
					char c = _getch();
					if (c == 'q' || c == 'Q')
						break;
				}

				break;
			}

			/*若菜单项为9，达到合成目标*/
			if (array_getmax(matrix, line, row) == goal && menu == 9) {
				special_info(line, goal, INFO_GOAL_ACHIEVED);  /*达成提示*/

				while (1) {
					int MK_RET = mk_select();  /*单击鼠标左键或按回车键继续*/
					if (MK_RET == MK_RET_MOUSE_LEFT || MK_RET == MK_RET_KEYBOARD_ENTER) {

						/*清除原有内容*/
						cct_gotoxy(0, 4 * line + 3);
						for (int i = 0; i < 80; i++)
							cout << ' ';

						/*输出操作说明以及当前信息*/
						special_info(line, goal, INFO_RULES);
						cct_gotoxy(0, 0);
						print_score(0, score, goal, menu);
						break;
					}
				}
			}

			/*选择色块*/
			while (loop2) {
				MK_RET2 = mouse_and_keyboard(matrix, line, row, coord);

				if (menu == 7) {  /*菜单项7显示选中的色块坐标*/
					cct_gotoxy(0, 4 * line + 3);
					cout << "                           ";
					cct_gotoxy(0, 4 * line + 3);
					cout << "选中了" << coord[0] << "行" << coord[1] << "列";
					loop1 = 0;  /*跳出loop1*/
					break;      /*跳出loop2*/
				}

				if (!MK_RET2) {  /*若读键鼠返回值为零，标记所有可合成项并输出相应提示*/
					array_multiple_scan1(matrix, line, row, coord, menu);
					block_multiple_activate(matrix, line, row);
					special_info(line, goal, INFO_MAKE_SURE);
				}

				else {  /*若读键鼠返回值不为零（即鼠标单击右键或按Q键），则跳出所有循环，结束程序*/
					loop1 = 0;
					break;
				}

				if (array_mark_count(matrix, line, row)) {  /*若所选色块周围有相同值*/
					MK_RET1 = mk_select();  /*再读一次键鼠*/

					switch (MK_RET1) {
					case MK_RET_MOUSE_LEFT:
					case MK_RET_KEYBOARD_ENTER:
						loop2 = 0;  /*单击鼠标左键或按回车键就跳出loop2，往下进行合成操作*/
						break;
					case MK_RET_MOUSE_MOVE:
					case MK_RET_KEYBOARD_ARROW:
						block_multiple_default(matrix, line, row);  /*鼠标移动或按箭头键就取消所有色块的标记，回去重新选择色块*/
						array_mark_set(matrix, line, row);
						break;
					case MK_RET_MOUSE_RIGHT:
					case MK_RET_KEYBOARD_Q:
						loop1 = 0, loop2 = 0;  /*单击鼠标右键或按Q键就跳出所有循环，结束程序*/
						break;
					}
				}

				else  /*若所选色块周围无相同值，则输出相应提示，回去重新选择色块*/
					special_info(line, goal, INFO_NO_CLEAR);
			}

			/*若没有单击鼠标右键或按Q键，执行合成操作*/
			if (loop1) {

				/*归并相同值、计算得分、显示信息*/
				array_clear(matrix, line, row, coord);
				int _getscore = array_getscore(matrix, line, row);
				score = score + _getscore;
				cct_gotoxy(0, 0);
				print_score(_getscore, score, goal, menu);

				/*消除色块、使被选中的色块闪烁*/
				block_multiple_clear(matrix, line, row);
				console_blink_block(matrix, coord);

				if (menu == 8) {  //合成完成，回车键/单击左键下落0
					special_info(line, goal, MENU8_FALL);
					mk_pause(MK_ENTER_CONTINUE);
				}

				block_multiple_fall(matrix, line, row);  /*显示色块下落动画*/

				if (menu == 8) {  //下落0完成，回车键/单击左键填充新值
					special_info(line, goal, MENU8_FILL);
					mk_pause(MK_ENTER_CONTINUE);
				}

				/*补充新值、打印被消除的色块*/
				array_random(matrix, line, row, array_getmax(matrix, line, row));
				block_multiple_print(matrix, line, row);

				if (menu == 8) {  //本次合成结束，按C/单击左键继续新一次的合成
					special_info(line, goal, MENU8_CONTINUE);
					mk_pause(MK_C_CONTINUE);
				}

				array_mark_set(matrix, line, row);  /*重设所有元素标记情况*/

				if (menu == 8)  /*菜单项8在此结束*/
					break;
			}
		}

		if (menu == 8 || menu == 9) {  /*菜单项8、9擦除原有内容*/
			cct_gotoxy(0, 4 * line + 3);
			for (int i = 0; i < 80; i++)
				cout << ' ';
		}

		cct_gotoxy(0, 4 * line + 3);
		end();  /*本小题结束，请输入End继续...*/
	}
}

/***************************************************************************
  函数名称：pause
  功    能：设置一个程序的间断点
  输入参数：无
  返 回 值：无
  说    明：输入回车才继续，其他字符无回显
***************************************************************************/
void pause()
{
	char c;
	while (1) {
		c = _getch();
		if (c == '\r')
			break;
	}
}

/***************************************************************************
  函数名称：end
  功    能：设置间断点，输入End才继续
  输入参数：无
  返 回 值：无
  说    明：无
***************************************************************************/
void end()
{
	cct_setcursor(CURSOR_VISIBLE_NORMAL);  /*显示光标*/

	char c[4];  /*存放输入字符的字符数组*/
	int X, Y;   /*横纵坐标*/
	cout << endl << "本小题结束，请输入End继续...";

	while (1) {
		int i = 0;  /*计数变量，初值为零*/

		while (1) {
			char ch = getchar();  /*逐个提取字符*/
			if (ch == '\n')  /*若遇到换行符则结束赋值*/
				break;
			if (i < 4)  /*若i小于4，则字符数组未满，赋给i对应的元素后，i自增*/
				c[i] = ch, i++;
		}

		c[3] = '\0';  /*添加尾零，为了后续使用strcmp()*/

		/*若返回值不为零，则输入错误*/
		if (strcmp(c, "End")) {
			cout << "输入错误，请重新输入";  /*输出提示*/
			cct_getxy(X, Y);       /*取当前坐标*/
			Y = Y - 1, X = X + 8;  /*调整为目标位置*/
			cct_gotoxy(X, Y);      /*移动光标至目标位置*/

			for (i = 0; i < 20; i++)  /*擦除内容*/
				cout << " ";

			cct_gotoxy(X, Y);  /*光标复位*/
		}

		/*若返回值为零，则输入正确，结束输入*/
		else
			break;
	}
}

/***************************************************************************
  函数名称：print_score
  功    能：输出分数情况及合成目标
  输入参数：const int getscore：本次得分（只读）
            const int score：总分（只读）
			const int goal：合成目标（只读）
			const int menu：菜单函数返回值（只读）
  返 回 值：无
  说    明：无
***************************************************************************/
void print_score(const int getscore, const int score, const int goal, const int menu)
{
	if (menu == 3 || menu == 4)
		cout << endl;

	cout << "本次得分：" << getscore << " ";
	cout << "总得分：" << score << " ";
	cout << "合成目标：" << goal << " " << endl;
}

/***************************************************************************
  函数名称：clear_command
  功    能：输入指令，决定每次检查结束后是否进行数值合并
  输入参数：const char coord[]：存放目标元素坐标的数组
  返 回 值：char：指令代号
  说    明：无
***************************************************************************/
char clear_command(const char coord[])
{
	char c;
	cout << endl << "请确认是否把相邻的相同值合并到" << coord[0] << coord[1] << "中(Y/N/Q)：";

	/*键盘输入指令，不需按回车，直到输入为合理的三种指令才结束输出*/
	while (1) {
		c = _getch();
		if (c == 'y' || c == 'Y' || c == 'n' || c == 'N' || c == 'q' || c == 'Q')
			break;
	}

	cout << c << endl;  /*回显指令*/
	if (c >= 'a' && c <= 'z')   /*调整为大写*/
		c = c - 'a' + 'A';

	return c;
}

/***************************************************************************
  函数名称：input_coord
  功    能：输入待检查的元素坐标
  输入参数：const int line：操作行数
			const int row：操作列数
			char coordinate[]：存放坐标的数组
  返 回 值：无
  说    明：无
***************************************************************************/
void input_coord(const int line, const int row, char coordinate[])
{
	cout << "请以字母+数字形式[例：c2]输入矩阵坐标：";
	int X, Y, j;    /*横纵坐标、计数变量*/
	char coord[2];  /*存放坐标的数组*/

	while (1) {
		coord[0] = coord[1] = 0;  /*坐标初始化*/
		int i = 0;  /*计数归零*/

		/*1、输入坐标*/
		while (1) {
			char c = getchar();  /*逐个提取字符*/
			if (c == '\n')    /*若有换行符，结束输入*/
				break;
			if (i == 0)       /*若输入未结束，第一个字符赋给coord[0]*/
				coord[0] = c;
			else if (i == 1)  /*若输入未结束，第二个字符赋给coord[1]*/
				coord[1] = c;
			i++;    /*每输入一个字符，计数变量自增，统计输入的字符数*/
		}

		/*2、调整coord[0]的大小写*/
		if (coord[0] >= 'a' && coord[0] <= 'z')
			coord[0] = coord[0] - 'a' + 'A';

		/*3、若坐标符合要求，输出结果并结束本次输入*/
		if (coord[0] - 'A' >= 0 && coord[0] - 'A' <= line && coord[1] - '0' >= 0 && coord[1] - '0' <= row) {
			cout << "输入为" << coord[0] << "行" << coord[1] << "列" << endl;
			break;
		}

		/*4、若坐标不符合要求，输出提示、擦除原有内容并重新输入*/
		else {
			cout << "输入错误，请重新输入.";

			cct_getxy(X, Y);   /*取当前坐标*/
			Y--, X = X + 18;   /*调整为目标位置*/
			cct_gotoxy(X, Y);  /*移动光标至目标位置*/

			for (j = 0; j < 20; j++)  /*擦除内容*/
				cout << " ";

			cct_gotoxy(X, Y);  /*光标复位*/
		}
	}

	coordinate[0] = coord[0], coordinate[1] = coord[1];  /*将已处理好的坐标赋给参数*/
}

/***************************************************************************
  函数名称：if_end
  功    能：根据当前数组值，判断游戏是否结束
  输入参数：MATRIX matrix[][ROW_MAX]：整个游戏中的结构体二维数组
            const int line：操作行数（只读）
			const int row：操作列数（只读）
  返 回 值：bool：游戏是否结束（结束返回true，未结束返回false）
  说    明：无
***************************************************************************/
bool if_end(MATRIX matrix[][ROW_MAX], const int line, const int row)
{
	int i, j, count = 0;  /*count为统计周围无相同值元素数量的变量*/

	for (i = 0; i < line; i++) {
		for (j = 0; j < row; j++) {
			matrix[i][j].mark = 1;  /*标记当前元素*/
			array_single_scan(matrix, i, j, line, row);    /*检查该元素周围有无相同值*/
			if (array_mark_count(matrix, line, row) == 1)  /*若整个数组被标记元素数量仍为1，说明该元素周围无相同值*/
				count++;  /*计数器自增*/
			array_mark_set(matrix, line, row);  /*重设所有元素的标记情况*/
		}
	}
	if (count == line * row)  /*若周围无相同值元素数量=行数*列数，说明所有元素都不可合成，游戏结束*/
		return true;
	else                      /*若不等，说明仍有元素可以合成，游戏继续*/
		return false;
}