/*2151294 信11 马威*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <conio.h>
#include "cmd_console_tools.h"
#include "90-b2.h"
using namespace std;

/***************************************************************************
  函数名称：array_initialize
  功    能：初始化整个内部数组
  输入参数：MATRIX matrix[][ROW_MAX]：整个游戏中的结构体二维数组
            const int line：操作行数
			const int row：操作列数
  返 回 值：无
  说    明：1、本函数为最初的初始化，1-3等概率
            2、所有项的标记为零，表示未被标记
***************************************************************************/
void array_initialize(MATRIX matrix[][ROW_MAX], const int line, const int row)
{
	int i, j;  /*计数变量*/

	for (i = 0; i < line; i++) {
		for (j = 0; j < row; j++) {
			matrix[i][j].num = rand() % 3 + 1;  /*随机赋值*/
			matrix[i][j].mark = 0;              /*标记为零*/
		}
	}
}

/***************************************************************************
  函数名称：array_show
  功    能：显示整个内部数组
  输入参数：MATRIX matrix[][ROW_MAX]：整个游戏中的结构体二维数组
			const int line：操作行数
			const int row：操作列数
			const int show_mode：输出模式
  返 回 值：无
  说    明：1、本函数对于输出已做格式化处理
			2、输出模式为1时，被标记的元素输出为'*'，其余输出为'0'
***************************************************************************/
void array_show(MATRIX matrix[][ROW_MAX], const int line, const int row, const int show_mode)
{
	int i, j;  /*计数变量*/
	int X, Y;  /*横纵坐标*/
	cout << resetiosflags(ios::right);  /*解除输出右对齐*/

	/*1、输出首行的列标记（数字）*/
	cout << "  |  ";
	for (i = 0; i < row; i++)
		cout << setw(3) << setiosflags(ios::left) << i;

	/*2、输出第二行的分割线*/
	cout << endl << "--+--";
	for (i = 0; i < 3 * row - 1; i++)
		cout << "-";
	cout << endl;

	/*3、逐行输出元素*/
	for (i = 0; i < line; i++) {

		/*3.1、输出首列的行标记（字母）及分割线*/
		cout << char('A' + i) << " |  ";

		/*3.2、同一行内逐个输出元素*/
		for (j = 0; j < row; j++) {

			/*3.2.1、若为被标记元素*/
			if (matrix[i][j].mark) {
				if (show_mode == ARRAY_SHOW_CURRENT) {  /*输出当前数组模式：改变颜色后输出*/
					cct_getxy(X, Y);
					cct_showch(X, Y, char(matrix[i][j].num + '0'), COLOR_HYELLOW, COLOR_BLACK, 1);
					cct_setcolor();
					cout << "  ";
				}
				else  /*输出查找数组结果模式：输出星号*/
					cout << "*  ";
			}

			/*3.2.2、若为未标记元素*/
			else {
				if (show_mode == ARRAY_SHOW_CURRENT)  /*输出当前数组模式：输出元素数值*/
					cout << setw(3) << setiosflags(ios::left) << matrix[i][j].num;
				else  /*输出查找数组结果模式：输出字符零*/
					cout << "0  ";
			}

			/*3.2.3、输出完一行后换行*/
			if ((j + 1) % row == 0)
				cout << endl;
		}
	}
}

/***************************************************************************
  函数名称：array_single_scan
  功    能：检查数组元素[I][J]上下左右四个元素的情况，并做相应处理
  输入参数：MATRIX matrix[][ROW_MAX]：整个游戏中的结构体二维数组
            const int I：目标元素的行数
			const int J：目标元素的列数
			const int line：操作行数
			const int row：操作列数
  返 回 值：无
  说    明：相应处理为：若上下左右四个元素中存在与目标元素数值相同的元素，则将其标记
***************************************************************************/
void array_single_scan(MATRIX matrix[][ROW_MAX], const int I, const int J, const int line, const int row)
{
	if (matrix[I][J].mark) {  /*只有在目标元素也被标记的情况下才开始检查*/
		if (I) {  /*若目标元素不在第一列，检查其上面一个元素*/
			if (matrix[I][J].num == matrix[I - 1][J].num)
				matrix[I - 1][J].mark = 1;
		}

		if (J) {  /*若目标元素不在第一行，检查其左边一个元素*/
			if (matrix[I][J].num == matrix[I][J - 1].num)
				matrix[I][J - 1].mark = 1;
		}

		if (I < line - 1) {  /*若目标元素不在最后一行，检查其下面一个元素*/
			if (matrix[I][J].num == matrix[I + 1][J].num)
				matrix[I + 1][J].mark = 1;
		}

		if (J < row - 1) {  /*若目标元素不在最后一列，检查其右边一个元素*/
			if (matrix[I][J].num == matrix[I][J + 1].num)
				matrix[I][J + 1].mark = 1;
		}
	}
}

/***************************************************************************
  函数名称：array_multiple_scan1
  功    能：检查整个数组，将与目标元素相连的、数值相同元素全部标记
  输入参数：MATRIX matrix[][ROW_MAX]：整个游戏中的结构体二维数组
			const int line：操作行数
			const int row：操作列数
			char coord[]：存放目标元素坐标的数组
			const int menu：菜单函数返回值（只读）
  返 回 值：无
  说    明：1、该函数为菜单项1，以非递归方式完成
            2、后续菜单项使用此函数来标记，故参数中加入菜单函数返回值来控制提示语的输出
***************************************************************************/
void array_multiple_scan1(MATRIX matrix[][ROW_MAX], const int line, const int row, char coord[], const int menu)
{
	const int I = coord[0] - 'A';  /*将坐标由字符转换为数字*/
	const int J = coord[1] - '0';  /*将坐标由字符转换为数字*/
	matrix[I][J].mark = 1;  /*先标记目标元素*/
	array_single_scan(matrix, I, J, line, row);  /*再以目标元素为中心进行第一次检查*/

	/*若第一次处理完后，数组中被标记元素的个数仍为1，说明无连续相同值*/
	if (array_mark_count(matrix, line, row) == 1) {

		if (menu <= 4)  /*若菜单函数返回值不大于4，则此时为命令行方式完成，输出提示*/
			cout << "输入的矩阵坐标位置处无连续相同值，请重新输入" << endl;

		matrix[I][J].mark = 0;  /*取消目标元素标记，避免影响后续操作*/
	}

	/*若第一次处理完后，数组中被标记元素的个数不为1，说明有连续相同值，进行下一步检查*/
	else {
		int i, j;  /*计数变量*/
		int count1 = array_mark_count(matrix, line, row), count2 = 0;  /*每一次处理前后数组中被标记元素个数*/

		while (count1 != count2) {  /*若一次处理前后标记元素个数相等，则说明已检查出所有连续相同值，检查结束*/

			count1 = array_mark_count(matrix, line, row);  /*每次处理前的个数*/

			/*以所有数组中的元素为目标元素，每一项都进行单项检查*/
			for (i = 0; i < line; i++) {
				for (j = 0; j < row; j++) {
					array_single_scan(matrix, i, j, line, row);
				}
			}

			count2 = array_mark_count(matrix, line, row);  /*每次处理后的个数*/
		}
	}
}

/***************************************************************************
  函数名称：array_multiple_scan2
  功    能：检查整个数组，将与目标元素相连的、数值相同元素全部标记
  输入参数：MATRIX matrix[][ROW_MAX]：整个游戏中的结构体二维数组
			const int line：操作行数
			const int row：操作列数
			char coord[]：存放目标元素坐标的数组
  返 回 值：无
  说    明：该函数为菜单项2，以递归方式完成
***************************************************************************/
void array_multiple_scan2(MATRIX matrix[][ROW_MAX], const int line, const int row, char coord[])
{
	const int I = coord[0] - 'A';  /*将坐标由字符转换为数字*/
	const int J = coord[1] - '0';  /*将坐标由字符转换为数字*/
	matrix[I][J].mark = 1;  /*先标记目标元素*/
	array_single_scan(matrix, I, J, line, row);  /*再以目标元素为中心进行第一次检查*/

	/*若第一次处理完后，数组中被标记元素的个数仍为1，说明无连续相同值，输出提示*/
	if (array_mark_count(matrix, line, row) == 1) {
		cout << "输入的矩阵坐标位置处无连续相同值，请重新输入" << endl;
		matrix[I][J].mark = 0;
	}

	/*若第一次处理完后，数组中被标记元素的个数不为1，说明有连续相同值，进行下一步检查*/
	else {
		int i, j;  /*计数变量*/
		int count1 = array_mark_count(matrix, line, row), count2 = 0;  /*本次处理前数组中被标记元素个数，处理后个数先置为0*/

		/*以所有数组中的元素为目标元素，每一项都进行单项检查*/
		for (i = 0; i < line; i++) {
			for (j = 0; j < row; j++) {
				array_single_scan(matrix, i, j, line, row);
			}
		}

		count2 = array_mark_count(matrix, line, row);  /*统计本次处理后的个数*/

		if (count1 != count2)  /*若一次处理前后标记元素个数不等，则说明未检查出所有连续相同值，用递归方式继续检查*/
			array_multiple_scan2(matrix, line, row, coord);
	}
}

/***************************************************************************
  函数名称：array_clear
  功    能：将与目标元素相连的、数值相同元素全部清零，目标元素自增
  输入参数：MATRIX matrix[][ROW_MAX]：整个游戏中的结构体二维数组
			const int line：操作行数
			const int row：操作列数
			char coord[]：存放目标元素坐标的数组
  返 回 值：无
  说    明：无
***************************************************************************/
void array_clear(MATRIX matrix[][ROW_MAX], const int line, const int row, const char coord[])
{
	int i, j;  /*计数变量*/
	int num = matrix[coord[0] - 'A'][coord[1] - '0'].num;  /*取目标元素数值*/

	/*将数组中所有被标记的元素数值置0*/
	for (i = 0; i < line; i++) {
		for (j = 0; j < row; j++) {
			if (matrix[i][j].mark)
				matrix[i][j].num = 0;
		}
	}

	matrix[coord[0] - 'A'][coord[1] - '0'].num = num + 1;  /*将先前取好的值自增，赋给目标元素*/
}

/***************************************************************************
  函数名称：array_getscore
  功    能：统计每一次合并后的得分
  输入参数：MATRIX matrix[][ROW_MAX]：整个游戏中的结构体二维数组
			const int line：操作行数
			const int row：操作列数
  返 回 值：int：得分
  说    明：合并后已被标记的元素中，只有目标元素的数值不为零，可以通过这一点取消除值
***************************************************************************/
int array_getscore(MATRIX matrix[][ROW_MAX], const int line, const int row)
{
	int count = array_mark_count(matrix, line, row);  /*统计已被标记元素数量（消除数量）*/
	int num = 0, i, j;  /*num为目标元素数值-1（消除值）*/

	for (i = 0; i < line; i++) {
		for (j = 0; j < row; j++) {
			if (matrix[i][j].num != 0 && matrix[i][j].mark == 1) {  /*若某个元素既被标记又数值不为零，则其一定为目标元素*/
				num = matrix[i][j].num - 1;  /*消除值为当前目标元素数值-1*/
				matrix[i][j].mark = 0;  /*将目标元素的标记去除*/
				break;
			}
		}

		if (num)  /*若num不为零，说明已取到消除值，结束检查*/
			break;
	}

	return count * num * 3;  /*分数=消除值*消除数量*3*/
}

/***************************************************************************
  函数名称：array_getmax
  功    能：取数组中所有元素的最大数值
  输入参数：MATRIX matrix[][ROW_MAX]：整个游戏中的结构体二维数组
			const int line：操作行数
			const int row：操作列数
  返 回 值：int：最大数值
  说    明：无
***************************************************************************/
int array_getmax(MATRIX matrix[][ROW_MAX], const int line, const int row)
{
	int i, j, max = 0;  /*返回值先置为0*/

	for (i = 0; i < line; i++) {
		for (j = 0; j < row; j++) {
			if (max < matrix[i][j].num)  /*若当前元素的数值大于max当前值，将该数值赋给max*/
				max = matrix[i][j].num;
		}
	}

	return max;
}

/***************************************************************************
  函数名称：array_move_zero
  功    能：将合并完成后数组剩余的0向上移动，造成非零数下落的效果
  输入参数：MATRIX matrix[][ROW_MAX]：整个游戏中的结构体二维数组
			const int line：操作行数
			const int row：操作列数
  返 回 值：无
  说    明：无
***************************************************************************/
void array_move_zero(MATRIX matrix[][ROW_MAX], const int line, const int row)
{
	int i, j, t;  /*计数变量、中间变量*/

	/*逐列判断，一列中从下往上判断*/
	for (j = 0; j < row; j++) {
		for (i = line - 1; i >= 0; i--) {

			/*若检查出数值为零的元素*/
			if (matrix[i][j].num == 0) {
				int I = i;  /*取元素所在行数*/
				MATRIX m[LINE_MAX][ROW_MAX];  /*中间数组*/
				array_copy(m, matrix, line, row);  /*将当前数组复制到中间数组去*/

				/*该元素不断与其上面的元素交换属性，直到该元素到达第一行为止*/
				while (I > 0) {
					t = matrix[I][j].num;
					matrix[I][j].num = matrix[I - 1][j].num;
					matrix[I - 1][j].num = t;
					t = matrix[I][j].mark;
					matrix[I][j].mark = matrix[I - 1][j].mark;
					matrix[I - 1][j].mark = t;
					I--;  /*每交换一次I自减*/
				}

				/*将处理前和处理后的数组比较，若有不同，则可能本列需继续处理，将i置为line，从本列的最后一行重新检查*/
				if (!array_compare(m, matrix, line, row))
					i = line;
			}
		}
	}
}

/***************************************************************************
  函数名称：array_compare
  功    能：比较两个结构体二维数组是否相同
  输入参数：MATRIX matrix1[][ROW_MAX]：待比较的结构体二维数组
            MATRIX matrix2[][ROW_MAX]：待比较的结构体二维数组
			const int line：操作行数
			const int row：操作列数
  返 回 值：bool：两个结构体数组是否相同
  说    明：无
***************************************************************************/
bool array_compare(MATRIX matrix1[][ROW_MAX], MATRIX matrix2[][ROW_MAX], const int line, const int row)
{
	int i, j;         /*计数变量*/
	bool ret = true;  /*返回值，初值为真*/

	for (i = 0; i < line; i++) {
		for (j = 0; j < row; j++) {
			if (matrix1[i][j].num != matrix2[i][j].num) {  /*数值不相等，返回值置为假后结束比较*/
				ret = false;
				break;
			}

			if (matrix1[i][j].mark != matrix2[i][j].mark) {  /*标记状态不相等，返回值置为假后结束比较*/
				ret = false;
				break;
			}
		}

		if (ret == false)  /*若返回值为假，结束比较*/
			break;
	}

	return ret;
}

/***************************************************************************
  函数名称：array_compare
  功    能：比较两个结构体二维数组是否相同
  输入参数：MATRIX Destination[][ROW_MAX]：待赋值的结构体二维数组
            MATRIX Source[][ROW_MAX]：元素来源的结构体二维数组
			const int line：操作行数
			const int row：操作列数
  返 回 值：无
  说    明：无
***************************************************************************/
void array_copy(MATRIX Destination[][ROW_MAX], const MATRIX Source[][ROW_MAX], const int line, const int row)
{
	int i, j;  /*计数变量*/
	for (i = 0; i < line; i++) {
		for (j = 0; j < row; j++) {
			Destination[i][j].num = Source[i][j].num;    /*复制元素数值*/
			Destination[i][j].mark = Source[i][j].mark;  /*复制元素标记状态*/
		}
	}
}

/***************************************************************************
  函数名称：array_mark_set
  功    能：去除数组中所有元素的标记
  输入参数：MATRIX matrix[][ROW_MAX]：整个游戏中的结构体二维数组
			const int line：操作行数
			const int row：操作列数
  返 回 值：无
  说    明：无
***************************************************************************/
void array_mark_set(MATRIX matrix[][ROW_MAX], const int line, const int row)
{
	int i, j;  /*计数变量*/
	for (i = 0; i < line; i++) {
		for (j = 0; j < row; j++) {
			matrix[i][j].mark = 0;  /*元素标记状态为0*/
		}
	}
}

/***************************************************************************
  函数名称：array_mark_count
  功    能：统计数组中已标记的元素个数
  输入参数：MATRIX matrix[][ROW_MAX]：整个游戏中的结构体二维数组
			const int line：操作行数
			const int row：操作列数
  返 回 值：int：已标记的元素个数
  说    明：无
***************************************************************************/
int array_mark_count(MATRIX matrix[][ROW_MAX], const int line, const int row)
{
	int i, j, count = 0;

	for (i = 0; i < line; i++) {
		for (j = 0; j < row; j++) {
			if (matrix[i][j].mark)  /*若已被标记，计数变量自增*/
				count++;
		}
	}

	return count;
}

/***************************************************************************
  函数名称：array_random
  功    能：对合并后的数组进行新值填充
  输入参数：MATRIX matrix[][ROW_MAX]：整个游戏中的结构体二维数组
			const int line：操作行数
			const int row：操作列数
			const int MaxNum：填充前数组中的最大数值
  返 回 值：无
  说    明：本函数根据最大数的值，调整各项新值的概率
***************************************************************************/
void array_random(MATRIX matrix[][ROW_MAX], const int line, const int row, const int MaxNum)
{
	int i, j;  /*计数变量*/

	/*逐个检查数组中元素的数值*/
	for (i = 0; i < line; i++) {
		for (j = 0; j < row; j++) {

			/*若检查出数值为零的元素*/
			if (matrix[i][j].num == 0) {
				int random = rand();  /*随机等概率生成一个0-32767之间的数*/

				switch (MaxNum) {
				case 3:
					random = rand() % 3 + 1;
					break;
				case 4:
					if (random > 0 && random <= 3277)
						random = 4;
					else
						random = rand() % 3 + 1;
					break;
				case 5:
					if (random > 0 && random <= 3277)
						random = 5;
					else if (random > 3277 && random <= 8192)
						random = 4;
					else
						random = rand() % 3 + 1;
					break;
				case 6:
					if (random > 0 && random <= 1638)
						random = 6;
					else if (random > 1638 && random <= 6554)
						random = 5;
					else
						random = rand() % 4 + 1;
					break;
				default:
					if (random > 0 && random <= 1638)
						random = MaxNum;
					else if (random > 1638 && random <= 3277)
						random = MaxNum - 1;
					else if (random > 3277 && random <= 6554)
						random = MaxNum - 2;
					else
						random = rand() % (MaxNum - 3) + 1;
					break;
				}

				matrix[i][j].num = random;
			}
		}  //end of for(1)
	}  //end of for(2)
}

/***************************************************************************
  函数名称：command_goal_achieved
  功    能：命令行模式下，输出达到合成目标时的特殊提示
  输入参数：int& goal：合成目标
  返 回 值：无
  说    明：本函数引用了goal，结束时使goal自增
***************************************************************************/
void command_goal_achieved(int& goal)
{
	int X, Y;
	cout << endl;
	cct_getxy(X, Y);
	cct_showstr(X, Y, "已经合成到", COLOR_HYELLOW, COLOR_RED);
	cct_getxy(X, Y);
	cct_showch(X, Y, char(goal + '0'), COLOR_HYELLOW, COLOR_RED);

	cct_setcolor();
	cout << endl << "按回车键继续向更高目标进发..." << endl;

	goal++;  /*goal自增，合成目标上升*/
}

/***************************************************************************
  函数名称：command_end
  功    能：命令行模式下，输出无可合并的项、游戏结束时的特殊提示
  输入参数：无
  返 回 值：无
  说    明：无
***************************************************************************/
void command_end()
{
	int X, Y;
	cct_getxy(X, Y);
	cct_showstr(X, Y, "无可合并的项，游戏结束!", COLOR_HYELLOW, COLOR_RED);
	cct_setcolor();
	cout << endl;
}