/*2151294 信11 马威*/
#include <iostream>
#include <iomanip>
#include <Winsock2.h>
#include <Windows.h>
#include "cmd_console_tools.h"
#include "90-b2.h"
using namespace std;

/***************************************************************************
  函数名称：block_single_print
  功    能：打印一个包含着数字的有颜色的方块
  输入参数：const int num：方块中间的数字（只读）
            const int bg_color：方块背景色（只读）
			const int fg_color：方块前景色（只读）
  返 回 值：无
  说    明：1、本函数以光标当前位置为方块的左上角
            2、未对三位数及以上的数输出格式做处理
***************************************************************************/
void block_single_print(const int num, const int bg_color, const int fg_color)
{
	int X, Y;         /*横纵坐标*/
	cct_getxy(X, Y);  /*取光标当前坐标*/

	cct_showstr(X, Y, "┏━┓", bg_color, fg_color);  /*打印上边界*/
	cct_showstr(X, Y + 1, "┃", bg_color, fg_color);  /*打印左边界*/

	/*若num为一位数，输出该数及一个空格*/
	if (num < 10) {
		cct_showch(X + 2, Y + 1, char(num + '0'), bg_color, fg_color);
		cct_showch(X + 3, Y + 1, ' ', bg_color, fg_color);
	}
	/*若num为两位数，输出该数两个不同位上的数*/
	else {
		cct_showch(X + 2, Y + 1, char((num - num % 10) / 10 + '0'), bg_color, fg_color);
		cct_showch(X + 3, Y + 1, char(num % 10 + '0'), bg_color, fg_color);
	}

	cct_showstr(X + 4, Y + 1, "┃", bg_color, fg_color);  /*打印右边界*/
	cct_showstr(X, Y + 2, "┗━┛", bg_color, fg_color);  /*打印下边界*/
	cct_setcolor();  /*重置颜色*/
}

/***************************************************************************
  函数名称：console_print_background
  功    能：打印有色方块所在的白色背景
  输入参数：const int line：操作行数（只读）
            const int row：操作列数（只读）
			const int print_mode：打印模式（只读）
  返 回 值：无
  说    明：无
***************************************************************************/
void console_print_background(const int line, const int row, const int print_mode)
{
	char ch = 'A';  /*行标，初值为A*/
	int Y;          /*纵坐标*/

	background_number(row, print_mode);  /*按列数输出列标*/

	/*列标位于第一行，下面从第二行开始，逐行打印内容*/
	for (Y = 2; Y <= (3 + print_mode) * line + (3 - print_mode); Y++) {
		background_letter(Y, ch, print_mode);  /*输出行标*/

		if (Y % (3 + print_mode) == (1 - print_mode))  /*每打印一个行标，行标自增*/
			ch++;

		background_multiple_lines(line, row, print_mode);  /*输出不同形式的每一行*/

		cout << " ";  /*每行末尾的空格*/
	}
}

/***************************************************************************
  函数名称：background_number
  功    能：打印背景函数附件——按列数输出列标
  输入参数：const int row：操作列数（只读）
			const int print_mode：打印模式（只读）
  返 回 值：无
  说    明：无
***************************************************************************/
void background_number(const int row, const int print_mode)
{
	int i;
	cout << resetiosflags(ios::left);  /*解除输出左对齐*/

	for (i = 0; i < row; i++) {
		if (i)  /*i不为零时，按打印模式设置宽度*/
			cout << setw(6 + print_mode * 2) << setiosflags(ios::right) << i;
		else    /*i为零时，设置宽度为6*/
			cout << setw(6) << setiosflags(ios::right) << i;
	}

	cout << endl;
}

/***************************************************************************
  函数名称：background_letter
  功    能：打印背景函数附件——按列数输出列标
  输入参数：const int Y：光标当前纵坐标（只读）
            const char ch：当前待输出的列标（只读）
			const int print_mode：打印模式（只读）
  返 回 值：无
  说    明：无
***************************************************************************/
void background_letter(const int Y, const char ch, const int print_mode)
{
	if (Y % (3 + print_mode) == (1 - print_mode))  /*当前为指定位置，输出列标及一个空格*/
		cout << ch << " ";
	else  /*当前不为指定位置，输出两个空格*/
		cout << "  ";
}

/***************************************************************************
  函数名称：background_line
  功    能：打印背景函数附件——输出背景的某一行
  输入参数：int row：操作列数
			int Y：光标调用函数前的纵坐标
			const char firstch[]：该行第一个制表符（只读）
			const char midch[]：该行中间的制表符（只读）
			const char midspecialch[]：该行中间的特殊制表符（只读）
			const char lastch[]：该行最后一个制表符（只读）
			int print_mode：打印模式
  返 回 值：无
  说    明：1、每行都是从X=2处开始打印
            2、每输出一个制表符，X进行自增2的操作
***************************************************************************/
void background_line(int row, int Y, const char firstch[], const char midch[], const char midspecialch[], const char lastch[], int print_mode)
{
	int i;      /*计数变量*/
	int X = 2;  /*横坐标，初始为2*/

	/*1、输出第一个制表符*/
	cct_showstr(X, Y, firstch, COLOR_WHITE, COLOR_BLACK);
	X = X + 2;

	/*2、输出中间的多个制表符*/
	for (i = 0; i < 3 * row; i++) {

		/*2.1、输出中间的一般制表符*/
		cct_showstr(X, Y, midch, COLOR_WHITE, COLOR_BLACK);
		X = X + 2;

		/*2.2、在指定位置打印特殊制表符*/
		if (print_mode) {
			if (X % 8 == 2 && X != 2 + row * 8) {
				cct_showstr(X, Y, midspecialch, COLOR_WHITE, COLOR_BLACK);
				X = X + 2;
			}
		}

		/*2.3、每执行三次停止1，控制打印速度*/
		if (i % 3 == 1)
			Sleep(1);
	}

	/*3、输出最后一个制表符并重置颜色*/
	cct_showstr(X, Y, lastch, COLOR_WHITE, COLOR_BLACK);
	cct_setcolor();
}

/***************************************************************************
  函数名称：background_multiple_lines
  功    能：打印背景函数附件——输出背景的各行
  输入参数：const int line：操作行数（只读）
            const int row：操作列数（只读）
			const int print_mode：打印模式（只读）
  返 回 值：无
  说    明：本函数中一开始取当前光标的坐标，无需接收实参传值
***************************************************************************/
void background_multiple_lines(const int line, const int row, const int print_mode)
{
	int X, Y;         /*横纵坐标*/
	cct_getxy(X, Y);  /*取当前光标的坐标*/

	/*首行的输出*/
	if (Y == 2)
		background_line(row, Y, "┏", "━", "┳", "┓", print_mode);

	/*最后一行的输出*/
	else if (Y == (3 + print_mode) * line + (3 - print_mode))
		background_line(row, Y, "┗", "━", "┻", "┛", print_mode);

	/*特殊行的输出*/
	else if (Y % 4 == 2 && print_mode == 1)
		background_line(row, Y, "┣", "━", "╋", "┫", PRINT_WITH_LINE);

	/*一般行的输出*/
	else
		background_line(row, Y, "┃", "  ", "┃", "┃", print_mode);
}

/***************************************************************************
  函数名称：console_print_base
  功    能：图形化输出初始数组，包括背景和色块
  输入参数：MATRIX matrix[][ROW_MAX]：整个游戏中的结构体二维数组
            const int line：操作行数（只读）
			const int row：操作列数（只读）
			const int print_mode：打印模式（只读）
  返 回 值：无
  说    明：本函数中一开始取当前光标的坐标，无需接收实参传值
***************************************************************************/
void console_print_base(MATRIX matrix[][ROW_MAX], const int line, const int row, const int print_mode)
{
	const int LENGTH = row * (6 + print_mode * 2) + (7 - print_mode * 2);  /*根据列数取长度*/
	const int WIDTH = line * (3 + print_mode) + (8 - print_mode);          /*根据行数取宽度*/
	int i, j;  /*计数变量*/

	cct_setconsoleborder(LENGTH, WIDTH);  /*根据取得的长度及宽度，动态设置窗口大小*/
	cout << "屏幕当前设置为：" << LENGTH << "行" << WIDTH << "列" << endl << ' ';  /*输出屏幕设置信息*/
	console_print_background(line, row, print_mode);  /*打印白色背景*/

	/*通过访问结构体数组中的内容，逐个打印色块*/
	for (i = 0; i < line; i++) {
		for (j = 0; j < row; j++) {
			cct_gotoxy(j * (6 + print_mode * 2) + 4, i * (3 + print_mode) + 3);
			block_single_print(matrix[i][j].num, matrix[i][j].num, COLOR_BLACK);
		}
		Sleep(1);  /*每打印完一行停止1，控制打印速度*/
	}

	cout << "\n\n";  /*输出完成后调整光标位置*/
}

/***************************************************************************
  函数名称：block_single_activate
  功    能：将当前坐标下对应的色块设置高亮
  输入参数：MATRIX matrix[][ROW_MAX]：整个游戏中的结构体二维数组
			const char coordinate[]：存放目标色块坐标的数组（只读）
  返 回 值：无
  说    明：无
***************************************************************************/
void block_single_activate(MATRIX matrix[][ROW_MAX], const char coordinate[])
{
	const int I = coordinate[0] - 'A';  /*将行标转换为数字*/
	const int J = coordinate[1] - '0';  /*将列标转换为数字*/
	cct_gotoxy(J * 8 + 4, I * 4 + 3);   /*移动光标至指定位置，便于接下来重画色块*/
	block_single_print(matrix[I][J].num, matrix[I][J].num, COLOR_WHITE);  /*重画色块，底色不变，前景色为白色*/
	cct_setcolor();  /*重置颜色*/
}

/***************************************************************************
  函数名称：block_single_default
  功    能：将当前坐标下对应的色块高亮取消
  输入参数：MATRIX matrix[][ROW_MAX]：整个游戏中的结构体二维数组
			const char coordinate[]：存放目标色块坐标的数组（只读）
  返 回 值：无
  说    明：无
***************************************************************************/
void block_single_default(MATRIX matrix[][ROW_MAX], const char coordinate[])
{
	bool prime;  /*对应坐标是否为初始值*/
	if (coordinate[0] == '\0' && coordinate[1] == '\0')
		prime = false;
	else
		prime = true;

	/*若坐标为初始值（都为'\0'），则不执行重画操作，防止发生数组越界*/
	if (prime) {
		const int I = coordinate[0] - 'A';  /*将行标转换为数字*/
		const int J = coordinate[1] - '0';  /*将列标转换为数字*/
		cct_gotoxy(J * 8 + 4, I * 4 + 3);   /*移动光标至指定位置，便于接下来重画色块*/
		block_single_print(matrix[I][J].num, matrix[I][J].num, COLOR_BLACK);  /*重画色块，底色不变，前景色为白色*/
	}

	cct_setcolor();  /*重置颜色*/
}

/***************************************************************************
  函数名称：block_multiple_activate
  功    能：将整个数组中被标记的元素对应色块设置高亮
  输入参数：MATRIX matrix[][ROW_MAX]：整个游戏中的结构体二维数组
			const int line：操作行数（只读）
			const int row：操作列数（只读）
  返 回 值：无
  说    明：无
***************************************************************************/
void block_multiple_activate(MATRIX matrix[][ROW_MAX], const int line, const int row)
{
	int i, j;
	char coord[2];  /*存放元素坐标的字符数组*/

	/*根据数组中被标记元素总数取延时时长*/
	int count = array_mark_count(matrix, line, row);
	unsigned int delay;

	if (count <= 5)
		delay = 100;
	else
		delay = 25;

	/*逐个检查数组中元素，若被标记则设置高亮*/
	for (i = 0; i < line; i++) {
		for (j = 0; j < row; j++) {
			if (matrix[i][j].mark) {
				coord[0] = i + 'A';
				coord[1] = j + '0';
				block_single_activate(matrix, coord);
				Sleep(delay);  /*每设置一个色块的高亮就延时，控制速度*/
			}
		}
	}
}

/***************************************************************************
  函数名称：block_multiple_default
  功    能：将整个数组中对应所有色块的高亮取消
  输入参数：MATRIX matrix[][ROW_MAX]：整个游戏中的结构体二维数组
			const int line：操作行数（只读）
			const int row：操作列数（只读）
  返 回 值：无
  说    明：无
***************************************************************************/
void block_multiple_default(MATRIX matrix[][ROW_MAX], const int line, const int row)
{
	int i, j;
	char coord[2];  /*存放元素坐标的字符数组*/

	for (i = 0; i < line; i++) {
		for (j = 0; j < row; j++) {
			if (matrix[i][j].mark) {
				coord[0] = i + 'A';
				coord[1] = j + '0';
				block_single_default(matrix, coord);
				Sleep(1);  /*每取消一个色块的高亮就延时，控制速度*/
			}
		}
	}
}

/***************************************************************************
  函数名称：block_single_clear
  功    能：将当前坐标下对应的色块清除
  输入参数：无
  返 回 值：无
  说    明：无
***************************************************************************/
void block_single_clear()
{
	int X, Y;
	cct_getxy(X, Y);
	cct_showstr(X, Y, "      ", COLOR_WHITE);      /*用白色擦除第一行*/
	cct_showstr(X, Y + 1, "      ", COLOR_WHITE);  /*用白色擦除第二行*/
	cct_showstr(X, Y + 2, "      ", COLOR_WHITE);  /*用白色擦除第三行*/
	cct_setcolor();  /*重置颜色*/
}

/***************************************************************************
  函数名称：block_multiple_clear
  功    能：将整个数组中的色块进行合成
  输入参数：MATRIX matrix[][ROW_MAX]：整个游戏中的结构体二维数组
			const int line：操作行数（只读）
			const int row：操作列数（只读）
  返 回 值：无
  说    明：无
***************************************************************************/
void block_multiple_clear(MATRIX matrix[][ROW_MAX], const int line, const int row)
{
	int i, j;

	for (i = 0; i < line; i++) {
		for (j = 0; j < row; j++) {

			/*被标记且数值不为零，则为目标元素，重画当前色块*/
			if (matrix[i][j].mark == 1 && matrix[i][j].num != 0) {
				cct_gotoxy(8 * j + 4, 4 * i + 3);
				block_single_print(matrix[i][j].num, matrix[i][j].num, COLOR_BLACK);
				Sleep(1);  /*延时1，控制速度*/
			}

			/*被标记且数值为零，则为数值为零元素，清除当前色块*/
			else if (matrix[i][j].mark == 1 && matrix[i][j].num == 0) {
				cct_gotoxy(8 * j + 4, 4 * i + 3);
				block_single_clear();
				Sleep(1);  /*延时1，控制速度*/
			}
		}
	}
}

/***************************************************************************
  函数名称：block_single_fall
  功    能：显示单个色块下落一格的动画
  输入参数：MATRIX matrix[][ROW_MAX]：整个游戏中的结构体二维数组
			const char coordinate[]：存放当前色块对应坐标的字符数组（只读）
  返 回 值：无
  说    明：无
***************************************************************************/
void block_single_fall(MATRIX matrix[][ROW_MAX], const char coordinate[])
{
	const int I = coordinate[0] - 'A';  /*将行标转换为数字*/
	const int J = coordinate[1] - '0';  /*将列标转换为数字*/
	const int X = J * 8 + 4;  /*取起始横坐标*/
	const int Y = I * 4 + 3;  /*取起始纵坐标*/

	/*总共下落五行*/
	for (int i = 0; i < 5; i++) {

		/*每下移一行就打印当前色块*/
		cct_gotoxy(X, Y + i);
		block_single_print(matrix[I][J].num, matrix[I][J].num, COLOR_BLACK);

		/*每下移一行清除色块，循环最后一次不执行，避免最后一次画出的色块被清除*/
		if (i < 4) {
			cct_gotoxy(X, Y + i);
			block_single_clear();
		}

		/*重画上下格子之间的分割线*/
		cct_showstr(X, Y + 3, "━", COLOR_WHITE, COLOR_BLACK, 3);

		/*每下移两行延时1，控制速度*/
		if (i % 2 == 0)
			Sleep(1);
	}

	cct_setcolor();  /*重设颜色*/
}

/***************************************************************************
  函数名称：block_multiple_fall
  功    能：显示数组中所有色块越过空格下落的动画
  输入参数：MATRIX matrix[][ROW_MAX]：整个游戏中的结构体二维数组
			const int line：操作行数（只读）
			const int row：操作列数（只读）
  返 回 值：无
  说    明：无
***************************************************************************/
void block_multiple_fall(MATRIX matrix[][ROW_MAX], const int line, const int row)
{
	int i, j, t;    /*计数变量、中间变量*/
	char coord[2];  /*存放下落色块坐标的字符数组*/

	/*逐列检查，从最下面一行开始检查*/
	for (j = 0; j < row; j++) {
		for (i = line - 1; i >= 0; i--) {

			/*若数组中这一色块对应元素数值为零（它不在第一行），其正上方色块对应元素数值不为零，则执行下落操作*/
			if (matrix[i][j].num == 0 && matrix[i - 1][j].num != 0 && i != 0) {

				/*一直下落直到i行j列元素不为零（即该元素当前位置正下方没有零）为止*/
				while (matrix[i][j].num == 0) {
					coord[0] = i - 1 + 'A';  /*将行标转换为字符*/
					coord[1] = j + '0';      /*将列标转换为字符*/
					block_single_fall(matrix, coord);  /*使色块下落一格*/

					/*交换数值，注意：交换前，i-1行才是要下落的元素，i行是其下方的0*/
					matrix[i][j].num = matrix[i - 1][j].num;
					matrix[i - 1][j].num = 0;

					/*交换标记状态，注意：交换前，i-1行才是要下落的元素，i行是其下方的0*/
					t = matrix[i - 1][j].mark;
					matrix[i - 1][j].mark = matrix[i][j].mark;
					matrix[i][j].mark = t;

					/*若还没下落到最下面一行，i自增，进行再次下落的操作*/
					if (i < line - 1)
						i++;
				}
			}
		}
	}
}

/***************************************************************************
  函数名称：block_multiple_print
  功    能：数组补充新值后，重画上一步被消除的所有色块
  输入参数：MATRIX matrix[][ROW_MAX]：整个游戏中的结构体二维数组
			const int line：操作行数（只读）
			const int row：操作列数（只读）
  返 回 值：无
  说    明：无
***************************************************************************/
void block_multiple_print(MATRIX matrix[][ROW_MAX], const int line, const int row)
{
	int i, j;

	for (i = 0; i < line; i++) {
		for (j = 0; j < row; j++) {
			if (matrix[i][j].mark) {  /*该元素被标记才重画对应色块，提高运行效率*/
				cct_gotoxy(8 * j + 4, 4 * i + 3);
				block_single_print(matrix[i][j].num, matrix[i][j].num, COLOR_BLACK);
				Sleep(1);  /*每画完一个色块延时1，控制速度*/
			}
		}
	}
}

/***************************************************************************
  函数名称：console_blink_block
  功    能：使当前坐标下的元素对应色块闪烁
  输入参数：MATRIX matrix[][ROW_MAX]：整个游戏中的结构体二维数组
			const char coordinate[]：存放闪烁色块坐标的字符数组（只读）
  返 回 值：无
  说    明：本函数设置为闪烁10次
***************************************************************************/
void console_blink_block(MATRIX matrix[][ROW_MAX], const char coordinate[])
{
	const int I = coordinate[0] - 'A';  /*将行标转换为数字*/
	const int J = coordinate[1] - '0';  /*将列标转换为数字*/
	const int rpt = 10;       /*重复次数：10次*/

	for (int i = 0; i < rpt; i++) {
		block_single_activate(matrix, coordinate);  /*设置高亮*/
		Sleep(10);  /*延时10，控制速度*/

		block_single_default(matrix, coordinate);   /*高亮取消*/
		Sleep(10);  /*延时10，控制速度*/
	}
}

/***************************************************************************
  函数名称：special_info
  功    能：伪图形界面下，输出特殊提示
  输入参数：const int line：操作行数（只读）
            int& goal：合成目标
			const int info_name：特殊提示名称（只读）
  返 回 值：无
  说    明：本函数引用了goal，结束时使goal自增
***************************************************************************/
void special_info(const int line, int& goal, const int info_name)
{
	int X = 0;             /*取起始横坐标*/
	int Y = 4 * line + 3;  /*取起始纵坐标*/

	/*擦除原有内容*/
	cct_gotoxy(X, Y);
	for (int i = 0; i < 85; i++)
		cout << ' ';
	cct_gotoxy(X, Y);

	/*1、需要改变文字颜色的提示*/
	switch (info_name) {
	case INFO_NO_CLEAR:
		cct_showstr(X, Y, "周围无相同值，", COLOR_BLACK, COLOR_HYELLOW);
		break;
	case INFO_GOAL_ACHIEVED:
		cct_showstr(X, Y, "已经合成到", COLOR_BLACK, COLOR_HYELLOW);
		cct_getxy(X, Y);
		cct_showch(X, Y, char(goal + '0'), COLOR_BLACK, COLOR_HYELLOW);
		cct_getxy(X, Y);
		cct_showstr(X, Y, "，", COLOR_BLACK, COLOR_HYELLOW);
		break;
	case INFO_END:
		cct_showstr(X, Y, "无可合并的项，游戏结束!", COLOR_BLACK, COLOR_HYELLOW);
		break;
	case MENU8_CONTINUE:
		cct_showstr(X, Y, "本次合成结束，按C/单击左键继续新一次的合成", COLOR_BLACK, COLOR_HYELLOW);
		break;
	}

	cct_setcolor();  /*重设颜色*/

	/*2、使用正常颜色的提示*/
	switch (info_name) {
	case INFO_RULES:
		cout << "箭头键/鼠标移动，回车键/单击左键选择，Q/单击右键结束";
		break;
	case INFO_NO_CLEAR:
		cout << "箭头键/鼠标移动，回车键/单击左键选择，Q/单击右键结束";
		break;
	case INFO_GOAL_ACHIEVED:
		goal++;  /*合成目标自增*/
		cout << "按回车键/单击左键继续向更高目标进发";
		break;
	case INFO_MAKE_SURE:
		cout << "箭头键/鼠标移动取消当前选择，回车键/单击左键合成";
		break;
	case INFO_END:
		cout << "按Q退出";
		break;
	case MENU8_FALL:
		cout << "合成完成，回车键/单击左键下落0";
		break;
	case MENU8_FILL:
		cout << "下落0完成，回车键/单击左键填充新值";
		break;
	}
}

/***************************************************************************
  函数名称：mouse_and_keyboard
  功    能：通过读鼠标与键盘，完成对于色块的选择
  输入参数：MATRIX matrix[][ROW_MAX]：整个游戏中的结构体二维数组
			const int line：操作行数（只读）
			const int row：操作列数（只读）
			char final_coord[]：存放最终选中色块坐标的数组
  返 回 值：无
  说    明：无
***************************************************************************/
int mouse_and_keyboard(MATRIX matrix[][ROW_MAX], const int line, const int row, char final_coord[])
{
	int X = 0, Y = 0;        /*横纵坐标，初始均为零*/
	int ret, maction;
	int keycode1, keycode2;
	int loop = 1;
	int count = 0;            /*用来处理特殊情况的计数器*/
	int RET = 0;              /*函数的返回值*/
	char coord[2] = { 0,0 };  /*鼠标控制、或鼠标位置非法时键盘控制的时候，当前选中色块的坐标*/
	char keyboard_coord[2] = { 0,0 };  /*鼠标位置合法时键盘控制的时候，当前选中色块的坐标*/

	cct_enable_mouse();  /*启用鼠标*/
	cct_setcursor(CURSOR_INVISIBLE);  /*关闭光标*/

	while (loop) {
		ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);  /*读鼠标/键盘*/
		bool BOOL = if_in_block(X, Y, line, row, coord);  /*判断此时鼠标的位置是否在某个色块中，并处理当前读出的鼠标坐标*/

		/*1、若返回的是鼠标事件*/
		if (ret == CCT_MOUSE_EVENT) {
			count = 0;                                     /*正常情况，计数器置零*/
			block_single_default(matrix, keyboard_coord);  /*将特殊情况下被选中的色块取消高亮*/
			mouse_act(matrix, line, coord, BOOL);          /*打印鼠标当前情况*/

			/*若鼠标单击左键，且当前位置在某个色块中，则结束循环*/
			if (maction == MOUSE_LEFT_BUTTON_CLICK && BOOL == true) {
				select_act(matrix, final_coord, coord);  /*标记选中元素，给final_coord[]赋值*/
				loop = 0;
			}

			else if (maction == MOUSE_RIGHT_BUTTON_CLICK && BOOL == true) {
				final_coord[0] = coord[0];  /*赋给final_coord[]行信息*/
				final_coord[1] = coord[1];  /*赋给final_coord[]列信息*/
				RET = MK_RET_MOUSE_RIGHT;   /*单击右键是特殊情况，函数返回值不为零*/
				loop = 0;
			}
		}

		/*2、若返回的是键盘事件，同时鼠标位置非法*/
		else if (ret == CCT_KEYBOARD_EVENT && BOOL == false) {
			count = 0;                                      /*正常情况，计数器置零*/
			block_single_default(matrix, keyboard_coord);  /*将特殊情况下被选中的色块取消高亮*/

			/*若正常情况下操作的坐标都为初始值，则将其变为A0，避免发生数组越界*/
			if (coord[0] == '\0' && coord[1] == '\0') {
				coord[0] = 'A';
				coord[1] = '0';
			}

			/*根据键码进行的操作*/
			switch (keycode1) {
			case 'Q':
			case 'q':
				RET = MK_RET_KEYBOARD_Q;  /*按Q键是特殊情况，函数返回值不为零*/
			case '\r':
				select_act(matrix, final_coord, coord);  /*标记选中元素，给final_coord[]赋值*/
				loop = 0;
				break;
			case 224:
				keyboard_multiple_act(matrix, line, row, coord, keycode2);  /*按第二个键码决定下一步行动*/
				break;
			}
		}

		/*3、若返回的是键盘事件，同时鼠标位置合法*/
		else if (ret == CCT_KEYBOARD_EVENT && BOOL == true) {
			/*特殊情况，每次keyboard_coord[]接收coord[]的值时，count自增，循环只在count为零时进行，确保只赋一次值*/
			while (count == 0) {
				keyboard_coord[0] = coord[0];
				keyboard_coord[1] = coord[1];
				count++;
			}

			/*根据键码进行的操作同上一种情况，不过只对keyboard_coord[]进行操作*/
			switch (keycode1) {
			case 'Q':
			case 'q':
				RET = MK_RET_KEYBOARD_Q;  /*按Q键是特殊情况，函数返回值不为零*/
			case '\r':
				select_act(matrix, final_coord, keyboard_coord);  /*标记选中元素，给final_coord[]赋值*/
				loop = 0;
				break;
			case 224:
				keyboard_multiple_act(matrix, line, row, keyboard_coord, keycode2);  /*按第二个键码决定下一步行动*/
				break;
			}
		}
	}

	cct_disable_mouse();	//禁用鼠标

	return RET;
}

/***************************************************************************
  函数名称：mk_select
  功    能：读鼠标和键盘并返回对应的事件
  输入参数：无
  返 回 值：int：键鼠的事件
  说    明：1、本函数只有用键鼠进行部分操作时结束循环
            2、本函数功能类似于mouse_and_keyboard，但没有改变坐标值、标记元素等操作
***************************************************************************/
int mk_select()
{
	int X = 0, Y = 0;        /*横纵坐标，初始均为零*/
	int ret, maction;
	int keycode1, keycode2;
	int loop = 1;
	int RET;  /*函数返回值*/

	cct_enable_mouse();  /*启用鼠标*/
	cct_setcursor(CURSOR_INVISIBLE);  /*关闭光标*/

	while (loop) {
		ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);

		if (ret == CCT_MOUSE_EVENT) {
			switch (maction) {
			case MOUSE_LEFT_BUTTON_CLICK:   /*单击左键*/
				RET = MK_RET_MOUSE_LEFT;
				loop = 0;
				break;
			case MOUSE_RIGHT_BUTTON_CLICK:  /*单击右键*/
				RET = MK_RET_MOUSE_RIGHT;
				loop = 0;
				break;
			case MOUSE_ONLY_MOVED:          /*仅移动*/
				RET = MK_RET_MOUSE_MOVE;
				loop = 0;
				break;
			}
		}

		else if (ret == CCT_KEYBOARD_EVENT) {
			switch (keycode1) {
			case '\r':
				RET = MK_RET_KEYBOARD_ENTER;  /*按回车*/
				loop = 0;
				break;
			case 224:
				RET = MK_RET_KEYBOARD_ARROW;  /*按箭头键*/
				loop = 0;
				break;
			case 'C':
			case 'c':
				RET = MK_RET_KEYBOARD_C;      /*按C键*/
				loop = 0;
				break;
			case 'Q':
			case 'q':
				RET = MK_RET_KEYBOARD_Q;      /*按Q键*/
				loop = 0;
				break;
			}
		}
	}

	return RET;
}

/***************************************************************************
  函数名称：mk_pause
  功    能：设置一个程序的间断点
  输入参数：const int pause_mode：暂停方式（只读）
  返 回 值：无
  说    明：本函数通过调用mk_select()读键盘和鼠标，在特定条件下才结束循环
***************************************************************************/
void mk_pause(const int pause_mode)
{
	int loop = 1;

	while (loop) {
		int ret = mk_select();  /*用ret接收mk_select()的返回值*/

		switch (pause_mode) {
		case MK_ENTER_CONTINUE:  /*鼠标单击左键或键盘按回车继续*/
			if (ret == MK_RET_MOUSE_LEFT || ret == MK_RET_KEYBOARD_ENTER)
				loop = 0;
			break;
		case MK_C_CONTINUE:      /*鼠标单击左键或键盘按C键继续*/
			if (ret == MK_RET_MOUSE_LEFT || ret == MK_RET_KEYBOARD_C)
				loop = 0;
			break;
		}
	}
}

/***************************************************************************
  函数名称：mouse_act
  功    能：打印鼠标当前情况，并对色块做相应处理
  输入参数：MATRIX matrix[][ROW_MAX]：整个游戏中的结构体二维数组
			const int line：操作行数（只读）
			const char coordinate[]：当前选中色块的坐标（只读）
			const bool prime：鼠标当前位置是否在某个色块中（只读）
  返 回 值：无
  说    明：无
***************************************************************************/
void mouse_act(MATRIX matrix[][ROW_MAX], const int line, const char coordinate[], const bool prime)
{
	cct_gotoxy(0, 4 * line + 3);  /*根据操作行数移动光标位置*/
	cout << "[当前鼠标] ";

	/*若鼠标当前位置在某个色块中*/
	if (prime) {

		/*擦除原有内容，输出新内容*/
		int X, Y;
		cct_getxy(X, Y);
		for (int i = 0; i < 100; i++)
			cout << ' ';
		cct_gotoxy(X, Y);
		cout << coordinate[0] << "行" << coordinate[1] << "列";

		/*使当前选中的色块高亮*/
		block_single_activate(matrix, coordinate);
	}

	/*若鼠标当前位置不在某个色块中*/
	else {
		cout << "位置非法";  /*输出提示*/
		block_single_default(matrix, coordinate);  /*取消上一次被选中色块的高亮*/
	}
}

/***************************************************************************
  函数名称：select_act
  功    能：最终选定色块时的操作
  输入参数：MATRIX matrix[][ROW_MAX]：整个游戏中的结构体二维数组
			char final_coord[]：存放最终选中色块坐标的数组
			const char source_coord[]：存放最终被选定色块坐标的数组
  返 回 值：无
  说    明：无
***************************************************************************/
void select_act(MATRIX matrix[][ROW_MAX], char final_coord[], const char selected_coord[])
{
	matrix[selected_coord[0] - 'A'][selected_coord[1] - '0'].mark = 1;  /*对最终选中的色块对应的数组元素做标记*/
	final_coord[0] = selected_coord[0];  /*赋给final_coord[]行信息*/
	final_coord[1] = selected_coord[1];  /*赋给final_coord[]列信息*/
}

/***************************************************************************
  函数名称：keyboard_single_act
  功    能：键盘按方向键时某一个键对应的操作
  输入参数：MATRIX matrix[][ROW_MAX]：整个游戏中的结构体二维数组
			const int line：操作行数（只读）
			const int row：操作列数（只读）
			char operate_coord[]：当前操作坐标
			const int move_mode：移动方式（只读）
  返 回 值：无
  说    明：无
***************************************************************************/
void keyboard_single_act(MATRIX matrix[][ROW_MAX], const int line, const int row, char operate_coord[], const int move_mode)
{
	block_single_default(matrix, operate_coord);  /*将当前操作坐标对应的色块高亮取消*/
	keyboard_coord_move(line, row, operate_coord, move_mode);  /*根据移动方式改变坐标值*/
	print_keyboard_info(line, operate_coord);       /*打印键盘当前状态*/
	block_single_activate(matrix, operate_coord);  /*将当前操作坐标对应的色块设置为高亮*/
}

/***************************************************************************
  函数名称：keyboard_multiple_act
  功    能：键盘按方向键时进行操作
  输入参数：MATRIX matrix[][ROW_MAX]：整个游戏中的结构体二维数组
			const int line：操作行数（只读）
			const int row：操作列数（只读）
			char operate_coord[]：当前操作坐标
			const int keycode：键盘返回的第二键码（只读）
  返 回 值：无
  说    明：无
***************************************************************************/
void keyboard_multiple_act(MATRIX matrix[][ROW_MAX], const int line, const int row, char operate_coord[], const int keycode)
{
	switch (keycode) {
	case KB_ARROW_UP:     /*向上，以上移方式进行操作*/
		keyboard_single_act(matrix, line, row, operate_coord, KEYBOARD_MOVE_UP);
		break;
	case KB_ARROW_DOWN:   /*向下，以下移方式进行操作*/
		keyboard_single_act(matrix, line, row, operate_coord, KEYBOARD_MOVE_DOWN);
		break;
	case KB_ARROW_LEFT:   /*向左，以左移方式进行操作*/
		keyboard_single_act(matrix, line, row, operate_coord, KEYBOARD_MOVE_LEFT);
		break;
	case KB_ARROW_RIGHT:  /*向右，以右移方式进行操作*/
		keyboard_single_act(matrix, line, row, operate_coord, KEYBOARD_MOVE_RIGHT);
		break;
	}
}

/***************************************************************************
  函数名称：keyboard_coord_move
  功    能：根据移动方式，改变当前操作坐标的值
  输入参数：const int line：操作行数（只读）
			const int row：操作列数（只读）
			char coordinate[]：存放当前操作坐标的数组
			const int move_mode：移动方式（只读）
  返 回 值：无
  说    明：坐标改变规则为边界回绕
***************************************************************************/
void keyboard_coord_move(const int line, const int row, char coordinate[], const int move_mode)
{
	const int I = coordinate[0] - 'A';  /*将行标转换为数字*/
	const int J = coordinate[1] - '0';  /*将列标转换为数字*/

	switch (move_mode) {
	case KEYBOARD_MOVE_UP:     /*向上移动：若为上边界，边界回绕；否则行标自减*/
		if (I == 0)
			coordinate[0] = line - 1 + 'A';
		else
			coordinate[0]--;
		break;
	case KEYBOARD_MOVE_DOWN:   /*向下移动：若为下边界，边界回绕；否则行标自增*/
		if (I == line - 1)
			coordinate[0] = 'A';
		else
			coordinate[0]++;
		break;
	case KEYBOARD_MOVE_LEFT:   /*向左移动：若为左边界，边界回绕；否则列标自减*/
		if (J == 0)
			coordinate[1] = row - 1 + '0';
		else
			coordinate[1]--;
		break;
	case KEYBOARD_MOVE_RIGHT:  /*向右移动：若为右边界，边界回绕；否则列标自增*/
		if (J == row - 1)
			coordinate[1] = '0';
		else
			coordinate[1]++;
		break;
	}
}

/***************************************************************************
  函数名称：if_in_block
  功    能：根据鼠标当前位置的坐标，判断其是否在某个色块中
  输入参数：const int X：鼠标横坐标（只读）
			const int Y：鼠标纵坐标（只读）
			const int line：操作行数（只读）
			const int row：操作列数（只读）
			char coordinate[]：由鼠标坐标转换而来的色块坐标
  返 回 值：无
  说    明：若鼠标位置非法，则不改变coordinate[]的值
***************************************************************************/
bool if_in_block(const int X, const int Y, const int line, const int row, char coordinate[])
{
	int i, j;  /*计数变量*/
	bool if_x = false, if_y = false;  /*横、纵坐标是否在某个色块中，初始均为假*/

	/*对横坐标检查，若横坐标在任意一个色块中，则为真并停止检查*/
	for (j = 0; j < row; j++) {
		if (X >= 8 * j + 4 && X <= 8 * j + 9) {
			if_x = true;
			break;
		}
	}

	/*对纵坐标检查，若纵坐标在任意一个色块中，则为真并停止检查*/
	for (i = 0; i < line; i++) {
		if (Y >= 4 * i + 3 && Y <= 4 * i + 5) {
			if_y = true;
			break;
		}
	}

	/*若横、纵坐标都在某一色块中，则位置合法*/
	if (if_x == true && if_y == true) {
		coordinate[0] = i + 'A';  /*将转换后的色块行标赋给coordinate[]*/
		coordinate[1] = j + '0';  /*将转换后的色块列标赋给coordinate[]*/
		return true;  /*位置合法，返回真*/
	}

	/*若横、纵坐标有一个不在某一色块中，则位置非法*/
	else
		return false;  /*位置非法，返回假*/
}

/***************************************************************************
  函数名称：print_keyboard_info
  功    能：输出键盘当前情况
  输入参数：const int line：操作行数（只读）
			char coordinate[]：当前选中色块的坐标（只读）
  返 回 值：无
  说    明：若鼠标位置非法，则不改变coordinate[]的值
***************************************************************************/
void print_keyboard_info(const int line, const char coordinate[])
{
	cct_gotoxy(0, 4 * line + 3);  /*根据操作行数移动光标位置*/
	cout << "[当前键盘] ";

	/*擦除原有内容，输出新内容*/
	int X, Y;
	cct_getxy(X, Y);
	for (int i = 0; i < 100; i++)
		cout << ' ';

	cct_gotoxy(X, Y);
	cout << coordinate[0] << "行" << coordinate[1] << "列";
}