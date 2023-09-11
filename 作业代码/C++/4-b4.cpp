/*2151294 信11 马威*/
#include <iostream>
#include <cstdio>
#include <conio.h>
#include <time.h>
#include <windows.h>
using namespace std;

const int MAX_X = 69;	//定义*组成的边框的宽度
const int MAX_Y = 17;	//定义*组成的边框的高度

/***************************************************************************
  函数名称：
  功    能：完成与system("cls")一样的功能，但效率高
  输入参数：
  返 回 值：
  说    明：清除整个屏幕缓冲区，不仅仅是可见窗口区域(使用当前颜色)
***************************************************************************/
void cls(const HANDLE hout)
{
	COORD coord = { 0, 0 };
	CONSOLE_SCREEN_BUFFER_INFO binfo; /* to get buffer info */
	DWORD num;

	/* 取当前缓冲区信息 */
	GetConsoleScreenBufferInfo(hout, &binfo);
	/* 填充字符 */
	FillConsoleOutputCharacter(hout, (TCHAR)' ', binfo.dwSize.X * binfo.dwSize.Y, coord, &num);
	/* 填充属性 */
	FillConsoleOutputAttribute(hout, binfo.wAttributes, binfo.dwSize.X * binfo.dwSize.Y, coord, &num);

	/* 光标回到(0,0) */
	SetConsoleCursorPosition(hout, coord);
	return;
}

/***************************************************************************
  函数名称：gotoxy
  功    能：将光标移动到指定位置
  输入参数：HANDLE hout ：输出设备句柄
			int X       ：指定位置的x坐标
			int Y       ：指定位置的y坐标
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void gotoxy(const HANDLE hout, const int X, const int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}

/***************************************************************************
  函数名称：showch
  功    能：在指定位置处打印一个指定的字符
  输入参数：HANDLE hout ：输出设备句柄
			int X       ：指定位置的x坐标
			int Y       ：指定位置的y坐标
			char ch     ：要打印的字符
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void showch(const HANDLE hout, const int X, const int Y, const char ch)
{
	gotoxy(hout, X, Y);
	putchar(ch);
}

/***************************************************************************
  函数名称：init_border
  功    能：显示初始的边框及随机字符
  输入参数：HANDLE hout：输出设备句柄
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void init_border(const HANDLE hout)
{
	gotoxy(hout, 0, 0);	//光标移回左上角(0,0)
	cout << "***********************************************************************" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "***********************************************************************" << endl;

	/* 随机显示20个大写字母，字母的值、XY坐标都随机显示
	   rand()函数的功能：随机生成一个在 0-32767 之间的整数
	   思考：在什么情况下，下面这个循环执行生成后，你看到的实际字母个数不足20个？ */
	int i;
	for (i = 0; i < 20; i++)
		showch(hout, rand() % MAX_X + 1, rand() % MAX_Y + 1, 'A' + rand() % 26);

	return;
}

/***************************************************************************
  函数名称：menu
  功    能：显示菜单以及菜单选择
  输入参数：无
  返 回 值：int b：所选菜单的序号
  说    明：1、此为第1个添加函数
            2、无输入参数，但函数内有_getch()，所以有输入
***************************************************************************/
int menu()
{
	int a, b;     /*定义所需变量，a是键盘输入键对应的ASCII，b是菜单函数的返回值*/

	/*输出提示语*/
	cout << "1.用I、J、K、L键控制上下左右(大小写均可，边界停止)" << endl
		 << "2.用I、J、K、L键控制上下左右(大小写均可，边界回绕)" << endl
		 << "3.用箭头键控制上下左右，边界停止" << endl
		 << "4.用箭头键控制上下左右，边界回绕" << endl
		 << "5.用I、J、K、L键控制上下左右，边界停止(按左箭头键向下移动)" << endl
		 << "6.用I、J、K、L键控制上下左右，边界回绕(按左箭头键向下移动)" << endl
		 << "0.退出" << endl
	     << "请选择[0-6] ";

	/*根据键盘输入键对应的ASCII，决定函数的返回值*/
	a = _getche();
	switch (a) {
	    case 48:
			b = 0;
			break;
		case 49:
			b = 1;
			break;
		case 50:
			b = 2;
			break;
		case 51:
			b = 3;
			break;
		case 52:
			b = 4;
			break;
		case 53:
			b = 5;
			break;
		case 54:
			b = 6;
			break;
	}

	return b;
}

/***************************************************************************
  函数名称：clear_letter
  功    能：清除字母
  输入参数：int a：通过_getch()返回值确定的ASCII
            int X：当前光标横坐标
			int Y：当前光标纵坐标
  返 回 值：无
  说    明：此为第2个添加函数
***************************************************************************/
void clear_letter(int a, int X, int Y)
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //取标准输出设备对应的句柄
	if (a == 32) {

		/*1、使光标移至字母左边*/
		X = X + 1;
		gotoxy(hout, X, Y);

		/*2、输出退格及空格*/
		cout << '\010';
		cout << '\040';

		/*3、使光标移回原位*/
		X = X - 1;
		gotoxy(hout, X, Y);
	}
}

/***************************************************************************
  函数名称：move_cursor
  功    能：移动光标
  输入参数：int a：通过menu()返回值确定的菜单序号
  返 回 值：无
  说    明：1、此为第3个添加函数
            2、所有控制方式、边界处理等情况都在此函数中
			3、此函数还处理了光标位置的初始化、退出和清除字母
***************************************************************************/
void move_cursor(int a)
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //取标准输出设备对应的句柄
	int key1, key2, X, Y;     /*定义所需变量，key1是第一个键码，key2是第二个键码，X是横坐标，Y是纵坐标*/

	/*使光标移至初始边框中心*/
	X = 35;
	Y = 9;
	gotoxy(hout, X, Y);

	while (1) {
		key1 = _getch();     /*得到第一个键码（用于控制退出、消除字母、i/j/k/l的移动）*/

		/*1、控制退出*/
		if (key1 == 113 || key1 == 81) {
			break;
		}

		/*2、控制字母的消除*/
		if (key1 == 32) {
			clear_letter(key1, X, Y);
			continue;
		}
		/*消除字母完成后，不执行第二个_getch()，达到使用效果*/

		/***************************************************************************************************************************/
		/*3、重现I、J、K、L控制光标移动时，按左方向键时光标也向下移动的问题*/
		/*3.1、控制K键的向下移动*/
		if ((key1 == 105 || key1 == 73) && (a == 5 || a == 6)) {
			if (Y == 1 && a == 5) {
				gotoxy(hout, X, Y);
			}

			else if (Y == 1 && a == 6) {
				Y = Y + 16;
				gotoxy(hout, X, Y);
			}

			else {
				Y = Y - 1;
				gotoxy(hout, X, Y);
			}
		}

		/*3.2、控制K键的向下移动*/
		else if ((key1 == 107 || key1 == 75) && (a == 5 || a == 6)) {
			if (Y == 17 && a == 5) {
				gotoxy(hout, X, Y);
			}

			else if (Y == 17 && a == 6) {
				Y = Y - 16;
				gotoxy(hout, X, Y);
			}

			else {
				Y = Y + 1;
				gotoxy(hout, X, Y);
			}
		}

		/*3.3、控制J键的向左移动*/
		else if ((key1 == 106 || key1 == 74) && (a == 5 || a == 6)) {
			if (X == 1 && a == 5) {
				gotoxy(hout, X, Y);
			}

			else if (X == 1 && a == 6) {
				X = X + 68;
				gotoxy(hout, X, Y);
			}

			else {
				X = X - 1;
				gotoxy(hout, X, Y);
			}
		}

		/*3.4控制L键的向右移动*/
		else if ((key1 == 108 || key1 == 76) && (a == 5 || a == 6)) {
			if (X == 69 && a == 5) {
				gotoxy(hout, X, Y);
			}

			else if (X == 69 && a == 6) {
				X = X - 68;
				gotoxy(hout, X, Y);
			}

			else {
				X = X + 1;
				gotoxy(hout, X, Y);
			}
		}

		/*若用I、J、K、L控制光标移动时，在此处回到循环始点，不调用第二个_getch()，达到使用效果*/
		if (a == 5 || a == 6) {
			continue;
		}
		/*问题演示结束*/
		/***************************************************************************************************************************/

		/*4、控制i/j/k/l的移动（通过a的值确定是边界停止还是边界回绕、每一次移动完成后continue，不执行第二个_getch()，达到使用效果）*/
		/*4.1、控制I键的向上移动*/
		if ((key1 == 105 || key1 == 73) && (a == 1 || a == 2)) {
			if (Y == 1 && a == 1) {
				gotoxy(hout, X, Y);
				continue;
			}

			else if (Y == 1 && a == 2) {
				Y = Y + 16;
				gotoxy(hout, X, Y);
				continue;
			}

			else {
				Y = Y - 1;
				gotoxy(hout, X, Y);
				continue;
			}
		}

		/*4.2、控制K键的向下移动*/
		else if ((key1 == 107 || key1 == 75) && (a == 1 || a == 2)) {
			if (Y == 17 && a == 1) {
				gotoxy(hout, X, Y);
				continue;
			}

			else if (Y == 17 && a == 2) {
				Y = Y - 16;
				gotoxy(hout, X, Y);
				continue;
			}

			else {
				Y = Y + 1;
				gotoxy(hout, X, Y);
				continue;
			}
		}

		/*4.3、控制J键的向左移动*/
		else if ((key1 == 106 || key1 == 74) && (a == 1 || a == 2)) {
			if (X == 1 && a == 1) {
				gotoxy(hout, X, Y);
				continue;
			}

			else if (X == 1 && a == 2) {
				X = X + 68;
				gotoxy(hout, X, Y);
				continue;
			}

			else {
				X = X - 1;
				gotoxy(hout, X, Y);
				continue;
			}
		}

		/*4.4控制L键的向右移动*/
		else if ((key1 == 108 || key1 == 76) && (a == 1 || a == 2)) {
			if (X == 69 && a == 1) {
				gotoxy(hout, X, Y);
				continue;
			}

			else if (X == 69 && a == 2) {
				X = X - 68;
				gotoxy(hout, X, Y);
				continue;
			}

			else {
				X = X + 1;
				gotoxy(hout, X, Y);
				continue;
			}
		}

		key2 = _getch();     /*得到第二个键码（用于方向键的移动）*/

		/*5、控制方向键的移动（通过a的值确定是边界停止还是边界回绕）*/
		/*5.1、控制UP键的向上移动*/
		if (key1 == 224 && key2 == 72 && (a == 3 || a == 4)) {
			if (Y == 1 && a == 3) {
				gotoxy(hout, X, Y);
			}

			else if (Y == 1 && a == 4) {
				Y = Y + 16;
				gotoxy(hout, X, Y);
			}

			else {
				Y = Y - 1;
				gotoxy(hout, X, Y);
			}
		}

		/*5.2、控制DOWN键的向下移动*/
		else if (key1 == 224 && key2 == 80 && (a == 3 || a == 4)) {
			if (Y == 17 && a == 3) {
				gotoxy(hout, X, Y);
			}

			else if (Y == 17 && a == 4) {
				Y = Y - 16;
				gotoxy(hout, X, Y);
			}

			else {
				Y = Y + 1;
				gotoxy(hout, X, Y);
			}
		}


		/*5.3、控制LEFT键的向左移动*/
		else if (key1 == 224 && key2 == 75 && (a == 3 || a == 4)) {
			if (X == 1 && a == 3) {
				gotoxy(hout, X, Y);
			}

			else if (X == 1 && a == 4) {
				X = X + 68;
				gotoxy(hout, X, Y);
			}

			else {
				X = X - 1;
				gotoxy(hout, X, Y);
			}
		}

		/*5.4、控制RIGHT键的向右移动*/
		else if (key1 == 224 && key2 == 77 && (a == 3 || a == 4)) {
			if (X == 69 && a == 3) {
				gotoxy(hout, X, Y);
			}

			else if (X == 69 && a == 4) {
				X = X - 68;
				gotoxy(hout, X, Y);
			}

			else {
				X = X + 1;
				gotoxy(hout, X, Y);
			}
		}
	}
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数仅用于初始演示，可以按题目要求全部推翻重写
***************************************************************************/
int main()
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //取标准输出设备对应的句柄

	/* 生成伪随机数的种子，只需在程序开始时执行一次即可 */
	srand((unsigned int)(time(0)));

	while (1) {
		/* 此句的作用是调用系统的cls命令清屏 */
		cls(hout);

		/*定义所需变量，a是menu()函数的返回值，a=0时直接退出*/
		int a = menu();
		if (a == 0) {
			break;
		}

		/* 显示初始的边框及其中的随机字符 */
		init_border(hout);

		/*光标的移动及字母的清除，根据a（menu()的返回值）确定控制类型及边界处理*/
		move_cursor(a);

		/*结束游戏*/
		gotoxy(hout, 0, 23);
		cout << "游戏结束，按回车键返回菜单." << endl;

		while (1) {
			//暂停(只有按回车才能退出，且任意键不会出现在屏幕上)
			int b;
			b = _getch();
			if (b == 13) {
				break;
			}
		}
	}

	/****************************************************************************************************************************
	  问题原因：将I、J、K、L控制光标移动的代码写在第二个_getch()前面，并且在所有键的语句写完后，再加一句continue
		        导致按左方向键时，返回第一个值224，未进入到任何一句判断语句，从上面一句continue回到循环开始
			    第二次_getch()得到左方向键返回的第二个值75，正好是大写K的返回值，进入到了控制光标向下的判断语句，导致光标向下移动
	  解决方案：将continue写到每一个gotoxy函数的后面，不要把continue直接露在外面
	*****************************************************************************************************************************
	  思考回答：边框内出现的字母不一定是20个
	  原因：输出随机数时可能会多次生成同一个坐标，使函数多次将字母输出在边框内的同一个位置
	        导致先前输出的字母被覆盖，只能看到一个字母
	****************************************************************************************************************************/
	return 0;
}