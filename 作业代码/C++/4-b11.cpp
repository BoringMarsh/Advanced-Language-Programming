/*2151294 信11 马威*/
#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

/* -----------------------------------------------------------------------------------
		允许   ：1、按需增加一个或多个函数，但是所有增加的函数中不允许任何形式的循环
				 2、定义符号常量
				 3、定义const型变量

		不允许 ：1、定义全局变量
   ----------------------------------------------------------------------------------- */

   /***************************************************************************
	 函数名称：print_diamond_with_coordinate
	 功    能：借助坐标打印菱形
	 输入参数：start_ch：起始字母
	           end_ch：终止字母
			   line：行数
			   location：每一行输出第几个字母
	 返 回 值：无
	 说    明：此函数为第1个添加函数
   ***************************************************************************/
void print_diamond_with_coordinate(char start_ch, char end_ch, int line, int location)
{
	/*1、第一、二象限的输出处理*/
	if (line <= end_ch - start_ch + 1) {

		/*1.1、第二象限的输出处理*/
		if (location <= line) {

			/*1.1.1、每行首字母的输出处理*/
			if (location == 1) {
				cout << setw(end_ch - start_ch + 2 - line) << char(start_ch + line - 1);
				print_diamond_with_coordinate(start_ch, end_ch, line, ++location);
			}

			/*1.1.3、其余字母的输出处理*/
			else {
				cout << char(start_ch + line - location);
				print_diamond_with_coordinate(start_ch, end_ch, line, ++location);
			}
		}

		/*1.2、第一象限的输出处理*/
		else {

			/*1.2.1、换行符的输出处理*/
			if (location > 2 * line - 1) {
				cout << endl;
				print_diamond_with_coordinate(start_ch, end_ch, ++line, 1);
			}

			/*1.2.2、其余字母的输出处理*/
			else {
				cout << char(start_ch - line + location);
				print_diamond_with_coordinate(start_ch, end_ch, line, ++location);
			}
		}
	}

	/*2、第三、四象限的输出处理*/
	else if (line > end_ch - start_ch + 1 && line <= 2 * (end_ch - start_ch) + 1) {
		int chardistance = end_ch - start_ch;          /*起始字母与终止字母的相差值*/
		int linedistance = line - (chardistance + 1);  /*第三、第四象限的每一行与最中间一行的行数差*/
		
		/*2.1、第三象限的输出处理*/
		if (location <= (chardistance + 1 - linedistance)) {  /*分割位=字母差值+1-行数差*/

			/*2.1.1、每行首字母的输出处理*/
			if (location == 1) {
				cout << setw(linedistance + 1) << char(start_ch + chardistance - linedistance);  /*设宽=行数差+1、首字母=起始字母+字母差值-行数差*/
				print_diamond_with_coordinate(start_ch, end_ch, line, ++location);
			}

			/*2.1.2、其余字母的输出处理*/
			else {
				cout << char(start_ch + chardistance - linedistance - location + 1);  /*其余字母=首字母-location+1*/
				print_diamond_with_coordinate(start_ch, end_ch, line, ++location);
			}
		}

		/*2.2、第四象限的输出处理*/
		else {

			/*2.2.1、换行符的输出处理*/
			if (location > 2 * chardistance + 1 - 2 * linedistance) {  /*每行输出字母数=2*字母差值+1-2*行数差*/
				cout << endl;
				print_diamond_with_coordinate(start_ch, end_ch, ++line, 1);
			}

			/*2.2.2、其余字母的输出处理*/
			else {
				cout << char(start_ch + location - (2 * chardistance + 1 - 2 * linedistance + 1) / 2);  /*其余字母=起始字母+location-(每行输出字母数+1)/2*/
				print_diamond_with_coordinate(start_ch, end_ch, line, ++location);
			}
		}
	}
}

   /***************************************************************************
	 函数名称：
	 功    能：打印菱形
	 输入参数：
	 返 回 值：
	 说    明：
   ***************************************************************************/
void print_diamond(char start_ch, char end_ch)
{
	print_diamond_with_coordinate(start_ch, end_ch, 1, 1);  /*将起始坐标设为1，1，调用print_diamond_with_coordinate()函数*/
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数中两处...允许修改，其余位置不准修改
***************************************************************************/
int main()
{
	char end_ch;

	/* 键盘输入结束字符(仅大写有效) */
	cout << "请输入结束字符(A~Z)" << endl;
	end_ch = getchar();

	/* 菱形(中间为A) */
	cout << setfill('=') << setw((end_ch - 'A') * 2 + 1) << "=" << endl; /* 按菱形最大宽度输出=(不允许用循环) */
	cout << "菱形(" << end_ch << "->A)" << endl;
	cout << setfill('=') << setw((end_ch - 'A') * 2 + 1) << "=" << setfill(' ') << endl; /* 按菱形最大宽度输出=(不允许用循环) */
	print_diamond('A', end_ch);
	cout << endl;

	return 0;
}