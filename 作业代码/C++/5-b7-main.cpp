/*2151294 信11 马威*/
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <conio.h>
#include <windows.h>
#include "5-b7.h"
using namespace std;

/*计数用的一个全局变量*/
int stepnumber = 0;

/*代表三根柱子的三个全局一维数组*/
int A[10];
int B[10];
int C[10];

/*代表三个栈顶指针的三个全局变量*/
int ATOP = 0;
int BTOP = 0;
int CTOP = 0;

/*标志是否显示内部数组的变量*/
int if_array;

/*标志移动延时时长的变量*/
int delay_time;

/***************************************************************************
  函数名称：pause
  功    能：中断或延缓程序的进行
  输入参数：int d：移动速度
  返 回 值：无
  说    明：1、此为第1个添加函数
			2、此函数根据移动速度是否为零，决定中断还是延时
***************************************************************************/
void pause(int d)
{
	int c;

	if (d) {
		Sleep(delay_time);
	}

	else {
		while (1) {
			c = _getch();
			if (c == 13) {
				break;
			}
		}
	}
}

/***************************************************************************
  函数名称：delay
  功    能：通过正确性处理，输入并给标志延时时长的全局变量delay_time赋值
  输入参数：无
  返 回 值：int i：移动速度
  说    明：1、此为第2个添加函数
			2、若d为零，则返回0；若d不为零，延时时长的计算方法为1000除以移动速度的二次方
***************************************************************************/
int delay()
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
	if (i == 0) {
		delay_time = 0;
	}

	else {
		delay_time = 1000 / (i * i);
	}

	return i;
}

/***************************************************************************
  函数名称：if_show_array
  功    能：通过正确性处理，输入并给标志是否显示内部数组值的全局变量if_array赋值
  输入参数：无
  返 回 值：无
  说    明：1、此为第3个添加函数
			2、若d为零，则返回0
***************************************************************************/
void if_show_array()
{
	int i;
	while (1) {
		cout << "请输入是否显示内部数组值(0-不显示 1-显示)" << endl;
		cin >> i;
		if (i >= 0 && i <= 1 && cin.good() == 1) {
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
		else if ((i < 0 || i > 1) && cin.good() == 1) {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}
	}

	/*根据i的输入值，给全局变量if_array赋值*/
	if_array = i;
}

/***************************************************************************
  函数名称：pillar_initialize
  功    能：给所有数组赋初值，完成初始化
  输入参数：int n：盘子的数量
			char src：起始柱代号
  返 回 值：无
  说    明：1、此为第4个添加函数
			2、此函数根据盘子数及起始柱代号，给起始柱的对应元素赋上1-n的值
***************************************************************************/
void pillar_initialize(int n, char src)
{
	int i;

	/*给所有元素赋初值*/
	for (i = 0; i < 10; i++) {
		A[i] = 0;
		B[i] = 0;
		C[i] = 0;
	}

	/*根据起始柱的代号，给起始柱的对应元素赋上1-n的值，代表初始时的各个盘子*/
	if (src == 'A') {
		for (i = 0; i < n; i++) {
			A[i] = n - i;
		}

		ATOP = n;
	}

	else if (src == 'B') {
		for (i = 0; i < n; i++) {
			B[i] = n - i;
		}

		BTOP = n;
	}

	else if (src == 'C') {
		for (i = 0; i < n; i++) {
			C[i] = n - i;
		}

		CTOP = n;
	}
}

/***************************************************************************
  函数名称：print_pillar
  功    能：输出每根柱子上的盘子数量情况
  输入参数：无
  返 回 值：无
  说    明：1、此为第5个添加函数
			2、若有盘子（值不为零），则输出；若无盘子（值为零），则不输出，只留空格
			3、已按要求将最后一个换行符去掉
***************************************************************************/
void print_pillar()
{
	int i;

	cout << "A:";
	for (i = 0; i < 10; i++) {
		if (A[i] != 0) {
			cout << setw(2) << A[i];
		}

		else {
			cout << "  ";
		}
	}
	cout << " ";

	cout << "B:";
	for (i = 0; i < 10; i++) {
		if (B[i] != 0) {
			cout << setw(2) << B[i];
		}

		else {
			cout << "  ";
		}
	}
	cout << " ";

	cout << "C:";
	for (i = 0; i < 10; i++) {
		if (C[i] != 0) {
			cout << setw(2) << C[i];
		}

		else {
			cout << "  ";
		}
	}
}

/***************************************************************************
  函数名称：print_base
  功    能：输出基本形状，包括三根柱子以及各个盘子的位置，和内部数组的值
  输入参数：int n：移动盘子的编号
            char src：这一步盘子的起始柱
  返 回 值：无
  说    明：1、此为第6个添加函数
			2、该函数调用了print_pillar()和pause()，以达到要求
			3、停顿点、输出结果的变化规律与demo基本保持一致
***************************************************************************/
void print_base(int n, char src)
{
	int j;
	int count = 0;

	/*根据全局变量if_array的值判断是否输出初始内部数组的值*/
	if (if_array) {
		cct_gotoxy(0, 17);
		cout << "初始:";

		for (j = 1; j <= 16; j++) {
			cout << " ";
		}

		print_pillar();
	}

	/*若为按回车单步演示模式，且显示内部数组的值，则在此停顿，否则不在此停顿*/
	if (delay_time == 0 && if_array != 0) {
		pause(delay_time);
	}

	/*循环输出代表三个柱子的字母*/
	for (j = 1; j <= 3; j++) {
		cct_gotoxy(1 + 10 * j, 13);
		cout << char(64 + j);
	}

	/*循环输出一排等号，使输出结果更具形象化*/
	cct_gotoxy(9, 12);
	for (j = 1; j <= 25; j++) {
		cout << "=";
	}

	/*在指定的位置，形象化输出每根柱子上的情况，光标移动前后都需移动到指定位置*/
	cct_gotoxy(10 * (src - 'A' + 1), 11);
	if (src == 'A') {
		for (j = 0; j <= 10; j++) {
			if (A[j] != 0) {
				cout << setw(2) << A[j];
				count++;
				cct_gotoxy(10 * (src - 'A' + 1), 11 - count);
			}
		}
	}

	else if (src == 'B') {
		for (j = 0; j <= 10; j++) {
			if (B[j] != 0) {
				cout << setw(2) << B[j];
				count++;
				cct_gotoxy(10 * (src - 'A' + 1), 11 - count);
			}
		}
	}

	else if (src == 'C') {
		for (j = 0; j <= 10; j++) {
			if (C[j] != 0) {
				cout << setw(2) << C[j];
				count++;
				cct_gotoxy(10 * (src - 'A' + 1), 11 - count);
			}
		}
	}

	cct_gotoxy(10 * (src - 'A' + 1) + 2, 11 - count + 1);

	/*输出基本形状后的中断或延缓*/
	pause(delay_time);
}

/***************************************************************************
  函数名称：act
  功    能：进行盘子的移动（数值的转移），以及每一步的输出
  输入参数：int n：移动盘子的编号
			char src：这一步盘子的起始柱
			char dst：这一步盘子的目标柱
  返 回 值：无
  说    明：1、此为第7个添加函数
			2、该函数调用了print_pillar，以达到每走一步打印三根柱子情况的效果
			3、该函数调用了pause()，以达到中断或延缓的效果
***************************************************************************/
void act(int n, char src, char dst)
{
	/*1、每次移动步骤：出栈栈顶指针下降，赋值给入栈元素，入栈栈顶指针上升，出栈栈顶元素赋0，代表盘子已移走*/
	if (src == 'A' && dst == 'B') {
		B[BTOP++] = A[--ATOP];
		A[ATOP] = 0;
	}

	else if (src == 'A' && dst == 'C') {
		C[CTOP++] = A[--ATOP];
		A[ATOP] = 0;
	}

	else if (src == 'B' && dst == 'A') {
		A[ATOP++] = B[--BTOP];
		B[BTOP] = 0;
	}

	else if (src == 'B' && dst == 'C') {
		C[CTOP++] = B[--BTOP];
		B[BTOP] = 0;
	}

	else if (src == 'C' && dst == 'A') {
		A[ATOP++] = C[--CTOP];
		C[CTOP] = 0;
	}

	else if (src == 'C' && dst == 'B') {
		B[BTOP++] = C[--CTOP];
		C[CTOP] = 0;
	}

	/*2、根据全局变量if_array的值，决定是否打印每一步的信息：盘子代号，去向，三根柱子的实时情况*/
	if (if_array) {

		/*2.1、消除原有内容*/
		int i;
		cct_gotoxy(89, 17);

		for (i = 1; i <= 89; i++) {
			cout << '\010';
		}

		for (i = 1; i <= 89; i++) {
			cout << '\040';
		}

		/*2.2、输出新内容*/
		cct_gotoxy(0, 17);
		cout << "第" << setw(4) << stepnumber << "步(" << n << "#: " << src << "-->" << dst << ")  ";
		print_pillar();
	}

	/*3、若为按回车单步演示模式，则在此停顿，否则不在此停顿*/
	if (delay_time == 0) {
		pause(delay_time);
	}

	/*4、根据起始柱的标号，决定光标移动的位置*/
	if (src == 'A') {
		cct_gotoxy(10 * (src - 'A' + 1) + 2, 11 - ATOP);
	}

	else if (src == 'B') {
		cct_gotoxy(10 * (src - 'A' + 1) + 2, 11 - BTOP);
	}

	else if (src == 'C') {
		cct_gotoxy(10 * (src - 'A' + 1) + 2, 11 - CTOP);
	}

	/*5、根据起始柱和目标柱的代号，决定光标的移动和数据的输出*/
	if (src == 'A' && dst == 'B') {
		cout << "\010\010\040\040";
		cct_gotoxy(10 * (dst - 'A' + 1), 11 - BTOP + 1);
		cout << setw(2) << B[BTOP - 1];
	}

	else if (src == 'A' && dst == 'C') {
		cout << "\010\010\040\040";
		cct_gotoxy(10 * (dst - 'A' + 1), 11 - CTOP + 1);
		cout << setw(2) << C[CTOP - 1];
	}

	else if (src == 'B' && dst == 'A') {
		cout << "\010\010\040\040";
		cct_gotoxy(10 * (dst - 'A' + 1), 11 - ATOP + 1);
		cout << setw(2) << A[ATOP - 1];
	}

	else if (src == 'B' && dst == 'C') {
		cout << "\010\010\040\040";
		cct_gotoxy(10 * (dst - 'A' + 1), 11 - CTOP + 1);
		cout << setw(2) << C[CTOP - 1];
	}

	else if (src == 'C' && dst == 'A') {
		cout << "\010\010\040\040";
		cct_gotoxy(10 * (dst - 'A' + 1), 11 - ATOP + 1);
		cout << setw(2) << A[ATOP - 1];
	}

	else if (src == 'C' && dst == 'B') {
		cout << "\010\010\040\040";
		cct_gotoxy(10 * (dst - 'A' + 1), 11 - BTOP + 1);
		cout << setw(2) << B[BTOP - 1];
	}

	/*6、进行完每一步后的中断或延缓*/
	pause(delay_time);
}

/***************************************************************************
  函数名称：hanoi
  功    能：打印n层汉诺塔的可视化移动
  输入参数：int n：层数
			char src：起始柱
			char tmp：中间柱
			char dst：目标柱
  返 回 值：无
  说    明：该函数要求与原先一致
***************************************************************************/
void hanoi(int n, char src, char tmp, char dst)
{
	/*若汉诺塔层数为1，将该盘从起始柱直接移向目标柱*/
	if (n == 1) {
		stepnumber++;
		act(n, src, dst);
	}

	/*若汉诺塔层数不为1*/
	else {

		/*1、递归调用hanoi(n - 1, src, dst, tmp)，将n-1个盘子移向中间柱*/
		hanoi(n - 1, src, dst, tmp);

		/*2、将第n个盘子直接移向目标柱*/
		stepnumber++;
		act(n, src, dst);

		/*3、递归调用hanoi(n - 1, tmp, src, dst)，将其余n-1个盘子移向目标柱*/
		hanoi(n - 1, tmp, src, dst);
	}
}

/***************************************************************************
  函数名称：number_of_plates
  功    能：通过正确性处理，输入并返回汉诺塔的层数
  输入参数：
  返 回 值：x：汉诺塔的层数
  说    明：1、此为第8个添加函数
			2、已按要求将输入正确范围控制在10以内
***************************************************************************/
int number_of_plates()
{
	int n;

	while (1) {
		cout << "请输入汉诺塔的层数(1-10)：" << endl;
		cin >> n;
		if (n >= 1 && n <= 10 && cin.good() == 1) {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			break;
		}

		/*只剩非法输入，或数值超类型范围的处理*/
		else if ((n < 1 || n > 10) && cin.good() == 0) {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}

		/*读取状态正常，超过用户范围时的处理*/
		else if ((n < 1 || n > 10) && cin.good() == 1) {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}
	}

	return n;
}

/***************************************************************************
  函数名称：start_tower
  功    能：通过正确性处理，输入并返回代表起始柱字母的ASCII
  输入参数：
  返 回 值：src：代表起始柱字母的ASCII
  说    明：1、此为第9个添加函数
			2、无论输入大写或小写，返回值统一为对应大写字母的ASCII
***************************************************************************/
char start_tower()
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
		return src - 32;
	}

	else {
		return src;
	}
}

/***************************************************************************
  函数名称：destination_tower
  功    能：通过正确性处理，输入并返回代表目标柱字母的ASCII
  输入参数：src：代表起始柱字母的ASCII
  返 回 值：dst：代表目标柱字母的ASCII
  说    明：1、此为第10个添加函数
			2、无论输入大写或小写，返回值统一为对应大写字母的ASCII
			3、该函数通过输入参数src，判断dst与src是否相等
***************************************************************************/
char destination_tower(char src)
{
	char dst;
	while (1) {
		cout << "请输入目标柱(A-C)：" << endl;
		cin >> dst;
		if (((dst >= 'a' && dst <= 'c') || (dst >= 'A' && dst <= 'C')) && cin.good() == 1) {
			if (dst != src && dst != src + 32 && dst != src - 32) {
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

				cout << "目标柱(" << dst << ")不能与起始柱(" << src << ")相同" << endl;
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
		return dst - 32;
	}

	else {
		return dst;
	}
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：完成输入(或调用输入函数)、调用递归函数
***************************************************************************/
int main()
{
	int n;                   /*1.1、定义所需变量，n为汉诺塔的层数*/
	char src, tmp, dst;      /*1.2、定义所需变量，src是代表起始柱的字母，tmp是代表中间柱的字母，dst是代表目标柱的字母*/
	int d;                   /*1.3、定义所需变量，d是移动速度*/

	n = number_of_plates();             /*2.1、通过number_of_plates()给n赋值*/
	src = start_tower();                /*2.2、通过start_tower()给src赋值*/
	dst = destination_tower(src);       /*2.3、通过destination_tower(src)，判断dst与src是否相等的同时，给dst赋值*/
	tmp = 'A' + 'B' + 'C' - src - dst;  /*2.4、通过src、dst的值，确定tmp的值*/

	pillar_initialize(n, src);     /*3.1、通过pillar_initialize()给数组赋值，完成柱子的初始化*/
	d = delay();                   /*3.2、通过delay()给d和全局变量delay_time赋值，完成移动速度和延时时长的初始化*/
	if_show_array();               /*3.3、通过if_show_array()给全局变量if_array赋值，完成是否显示内部数组值标志的初始化*/
	
	/*4、所有数据准备完毕后，清理屏幕，输出所有信息的汇总提示语句*/
	cct_cls();
	cout << "从 " << src << " 移动到 " << dst << "，共 " << n << " 层，延时设置为 " << d << "，";

	/*5、根据全局变量if_array的值，决定提示语后半句的输出*/
	if (if_array) {
		cout << "显示内部数组值" << endl;
	}

	else {
		cout << "不显示内部数组值" << endl;
	}

	/*6、输出基本形状并可视化打印汉诺塔移动步骤*/
	print_base(n, src);
	hanoi(n, src, tmp, dst);

	/*7、程序最后的暂停*/
	cct_gotoxy(0, 27);
	cout << "请按任意键继续. . . ";
	int c = _getch();
	cout << '\n';

	return 0;
}