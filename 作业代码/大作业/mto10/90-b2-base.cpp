/*2151294 ��11 ����*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <conio.h>
#include "cmd_console_tools.h"
#include "90-b2.h"
using namespace std;

/***************************************************************************
  �������ƣ�array_initialize
  ��    �ܣ���ʼ�������ڲ�����
  ���������MATRIX matrix[][ROW_MAX]��������Ϸ�еĽṹ���ά����
            const int line����������
			const int row����������
  �� �� ֵ����
  ˵    ����1��������Ϊ����ĳ�ʼ����1-3�ȸ���
            2��������ı��Ϊ�㣬��ʾδ�����
***************************************************************************/
void array_initialize(MATRIX matrix[][ROW_MAX], const int line, const int row)
{
	int i, j;  /*��������*/

	for (i = 0; i < line; i++) {
		for (j = 0; j < row; j++) {
			matrix[i][j].num = rand() % 3 + 1;  /*�����ֵ*/
			matrix[i][j].mark = 0;              /*���Ϊ��*/
		}
	}
}

/***************************************************************************
  �������ƣ�array_show
  ��    �ܣ���ʾ�����ڲ�����
  ���������MATRIX matrix[][ROW_MAX]��������Ϸ�еĽṹ���ά����
			const int line����������
			const int row����������
			const int show_mode�����ģʽ
  �� �� ֵ����
  ˵    ����1���������������������ʽ������
			2�����ģʽΪ1ʱ������ǵ�Ԫ�����Ϊ'*'���������Ϊ'0'
***************************************************************************/
void array_show(MATRIX matrix[][ROW_MAX], const int line, const int row, const int show_mode)
{
	int i, j;  /*��������*/
	int X, Y;  /*��������*/
	cout << resetiosflags(ios::right);  /*�������Ҷ���*/

	/*1��������е��б�ǣ����֣�*/
	cout << "  |  ";
	for (i = 0; i < row; i++)
		cout << setw(3) << setiosflags(ios::left) << i;

	/*2������ڶ��еķָ���*/
	cout << endl << "--+--";
	for (i = 0; i < 3 * row - 1; i++)
		cout << "-";
	cout << endl;

	/*3���������Ԫ��*/
	for (i = 0; i < line; i++) {

		/*3.1��������е��б�ǣ���ĸ�����ָ���*/
		cout << char('A' + i) << " |  ";

		/*3.2��ͬһ����������Ԫ��*/
		for (j = 0; j < row; j++) {

			/*3.2.1����Ϊ�����Ԫ��*/
			if (matrix[i][j].mark) {
				if (show_mode == ARRAY_SHOW_CURRENT) {  /*�����ǰ����ģʽ���ı���ɫ�����*/
					cct_getxy(X, Y);
					cct_showch(X, Y, char(matrix[i][j].num + '0'), COLOR_HYELLOW, COLOR_BLACK, 1);
					cct_setcolor();
					cout << "  ";
				}
				else  /*�������������ģʽ������Ǻ�*/
					cout << "*  ";
			}

			/*3.2.2����Ϊδ���Ԫ��*/
			else {
				if (show_mode == ARRAY_SHOW_CURRENT)  /*�����ǰ����ģʽ�����Ԫ����ֵ*/
					cout << setw(3) << setiosflags(ios::left) << matrix[i][j].num;
				else  /*�������������ģʽ������ַ���*/
					cout << "0  ";
			}

			/*3.2.3�������һ�к���*/
			if ((j + 1) % row == 0)
				cout << endl;
		}
	}
}

/***************************************************************************
  �������ƣ�array_single_scan
  ��    �ܣ��������Ԫ��[I][J]���������ĸ�Ԫ�ص������������Ӧ����
  ���������MATRIX matrix[][ROW_MAX]��������Ϸ�еĽṹ���ά����
            const int I��Ŀ��Ԫ�ص�����
			const int J��Ŀ��Ԫ�ص�����
			const int line����������
			const int row����������
  �� �� ֵ����
  ˵    ������Ӧ����Ϊ�������������ĸ�Ԫ���д�����Ŀ��Ԫ����ֵ��ͬ��Ԫ�أ�������
***************************************************************************/
void array_single_scan(MATRIX matrix[][ROW_MAX], const int I, const int J, const int line, const int row)
{
	if (matrix[I][J].mark) {  /*ֻ����Ŀ��Ԫ��Ҳ����ǵ�����²ſ�ʼ���*/
		if (I) {  /*��Ŀ��Ԫ�ز��ڵ�һ�У����������һ��Ԫ��*/
			if (matrix[I][J].num == matrix[I - 1][J].num)
				matrix[I - 1][J].mark = 1;
		}

		if (J) {  /*��Ŀ��Ԫ�ز��ڵ�һ�У���������һ��Ԫ��*/
			if (matrix[I][J].num == matrix[I][J - 1].num)
				matrix[I][J - 1].mark = 1;
		}

		if (I < line - 1) {  /*��Ŀ��Ԫ�ز������һ�У����������һ��Ԫ��*/
			if (matrix[I][J].num == matrix[I + 1][J].num)
				matrix[I + 1][J].mark = 1;
		}

		if (J < row - 1) {  /*��Ŀ��Ԫ�ز������һ�У�������ұ�һ��Ԫ��*/
			if (matrix[I][J].num == matrix[I][J + 1].num)
				matrix[I][J + 1].mark = 1;
		}
	}
}

/***************************************************************************
  �������ƣ�array_multiple_scan1
  ��    �ܣ�����������飬����Ŀ��Ԫ�������ġ���ֵ��ͬԪ��ȫ�����
  ���������MATRIX matrix[][ROW_MAX]��������Ϸ�еĽṹ���ά����
			const int line����������
			const int row����������
			char coord[]�����Ŀ��Ԫ�����������
			const int menu���˵���������ֵ��ֻ����
  �� �� ֵ����
  ˵    ����1���ú���Ϊ�˵���1���Էǵݹ鷽ʽ���
            2�������˵���ʹ�ô˺�������ǣ��ʲ����м���˵���������ֵ��������ʾ������
***************************************************************************/
void array_multiple_scan1(MATRIX matrix[][ROW_MAX], const int line, const int row, char coord[], const int menu)
{
	const int I = coord[0] - 'A';  /*���������ַ�ת��Ϊ����*/
	const int J = coord[1] - '0';  /*���������ַ�ת��Ϊ����*/
	matrix[I][J].mark = 1;  /*�ȱ��Ŀ��Ԫ��*/
	array_single_scan(matrix, I, J, line, row);  /*����Ŀ��Ԫ��Ϊ���Ľ��е�һ�μ��*/

	/*����һ�δ�����������б����Ԫ�صĸ�����Ϊ1��˵����������ֵͬ*/
	if (array_mark_count(matrix, line, row) == 1) {

		if (menu <= 4)  /*���˵���������ֵ������4�����ʱΪ�����з�ʽ��ɣ������ʾ*/
			cout << "����ľ�������λ�ô���������ֵͬ������������" << endl;

		matrix[I][J].mark = 0;  /*ȡ��Ŀ��Ԫ�ر�ǣ�����Ӱ���������*/
	}

	/*����һ�δ�����������б����Ԫ�صĸ�����Ϊ1��˵����������ֵͬ��������һ�����*/
	else {
		int i, j;  /*��������*/
		int count1 = array_mark_count(matrix, line, row), count2 = 0;  /*ÿһ�δ���ǰ�������б����Ԫ�ظ���*/

		while (count1 != count2) {  /*��һ�δ���ǰ����Ԫ�ظ�����ȣ���˵���Ѽ�������������ֵͬ��������*/

			count1 = array_mark_count(matrix, line, row);  /*ÿ�δ���ǰ�ĸ���*/

			/*�����������е�Ԫ��ΪĿ��Ԫ�أ�ÿһ����е�����*/
			for (i = 0; i < line; i++) {
				for (j = 0; j < row; j++) {
					array_single_scan(matrix, i, j, line, row);
				}
			}

			count2 = array_mark_count(matrix, line, row);  /*ÿ�δ����ĸ���*/
		}
	}
}

/***************************************************************************
  �������ƣ�array_multiple_scan2
  ��    �ܣ�����������飬����Ŀ��Ԫ�������ġ���ֵ��ͬԪ��ȫ�����
  ���������MATRIX matrix[][ROW_MAX]��������Ϸ�еĽṹ���ά����
			const int line����������
			const int row����������
			char coord[]�����Ŀ��Ԫ�����������
  �� �� ֵ����
  ˵    �����ú���Ϊ�˵���2���Եݹ鷽ʽ���
***************************************************************************/
void array_multiple_scan2(MATRIX matrix[][ROW_MAX], const int line, const int row, char coord[])
{
	const int I = coord[0] - 'A';  /*���������ַ�ת��Ϊ����*/
	const int J = coord[1] - '0';  /*���������ַ�ת��Ϊ����*/
	matrix[I][J].mark = 1;  /*�ȱ��Ŀ��Ԫ��*/
	array_single_scan(matrix, I, J, line, row);  /*����Ŀ��Ԫ��Ϊ���Ľ��е�һ�μ��*/

	/*����һ�δ�����������б����Ԫ�صĸ�����Ϊ1��˵����������ֵͬ�������ʾ*/
	if (array_mark_count(matrix, line, row) == 1) {
		cout << "����ľ�������λ�ô���������ֵͬ������������" << endl;
		matrix[I][J].mark = 0;
	}

	/*����һ�δ�����������б����Ԫ�صĸ�����Ϊ1��˵����������ֵͬ��������һ�����*/
	else {
		int i, j;  /*��������*/
		int count1 = array_mark_count(matrix, line, row), count2 = 0;  /*���δ���ǰ�����б����Ԫ�ظ�����������������Ϊ0*/

		/*�����������е�Ԫ��ΪĿ��Ԫ�أ�ÿһ����е�����*/
		for (i = 0; i < line; i++) {
			for (j = 0; j < row; j++) {
				array_single_scan(matrix, i, j, line, row);
			}
		}

		count2 = array_mark_count(matrix, line, row);  /*ͳ�Ʊ��δ����ĸ���*/

		if (count1 != count2)  /*��һ�δ���ǰ����Ԫ�ظ������ȣ���˵��δ��������������ֵͬ���õݹ鷽ʽ�������*/
			array_multiple_scan2(matrix, line, row, coord);
	}
}

/***************************************************************************
  �������ƣ�array_clear
  ��    �ܣ�����Ŀ��Ԫ�������ġ���ֵ��ͬԪ��ȫ�����㣬Ŀ��Ԫ������
  ���������MATRIX matrix[][ROW_MAX]��������Ϸ�еĽṹ���ά����
			const int line����������
			const int row����������
			char coord[]�����Ŀ��Ԫ�����������
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void array_clear(MATRIX matrix[][ROW_MAX], const int line, const int row, const char coord[])
{
	int i, j;  /*��������*/
	int num = matrix[coord[0] - 'A'][coord[1] - '0'].num;  /*ȡĿ��Ԫ����ֵ*/

	/*�����������б���ǵ�Ԫ����ֵ��0*/
	for (i = 0; i < line; i++) {
		for (j = 0; j < row; j++) {
			if (matrix[i][j].mark)
				matrix[i][j].num = 0;
		}
	}

	matrix[coord[0] - 'A'][coord[1] - '0'].num = num + 1;  /*����ǰȡ�õ�ֵ����������Ŀ��Ԫ��*/
}

/***************************************************************************
  �������ƣ�array_getscore
  ��    �ܣ�ͳ��ÿһ�κϲ���ĵ÷�
  ���������MATRIX matrix[][ROW_MAX]��������Ϸ�еĽṹ���ά����
			const int line����������
			const int row����������
  �� �� ֵ��int���÷�
  ˵    �����ϲ����ѱ���ǵ�Ԫ���У�ֻ��Ŀ��Ԫ�ص���ֵ��Ϊ�㣬����ͨ����һ��ȡ����ֵ
***************************************************************************/
int array_getscore(MATRIX matrix[][ROW_MAX], const int line, const int row)
{
	int count = array_mark_count(matrix, line, row);  /*ͳ���ѱ����Ԫ������������������*/
	int num = 0, i, j;  /*numΪĿ��Ԫ����ֵ-1������ֵ��*/

	for (i = 0; i < line; i++) {
		for (j = 0; j < row; j++) {
			if (matrix[i][j].num != 0 && matrix[i][j].mark == 1) {  /*��ĳ��Ԫ�ؼȱ��������ֵ��Ϊ�㣬����һ��ΪĿ��Ԫ��*/
				num = matrix[i][j].num - 1;  /*����ֵΪ��ǰĿ��Ԫ����ֵ-1*/
				matrix[i][j].mark = 0;  /*��Ŀ��Ԫ�صı��ȥ��*/
				break;
			}
		}

		if (num)  /*��num��Ϊ�㣬˵����ȡ������ֵ���������*/
			break;
	}

	return count * num * 3;  /*����=����ֵ*��������*3*/
}

/***************************************************************************
  �������ƣ�array_getmax
  ��    �ܣ�ȡ����������Ԫ�ص������ֵ
  ���������MATRIX matrix[][ROW_MAX]��������Ϸ�еĽṹ���ά����
			const int line����������
			const int row����������
  �� �� ֵ��int�������ֵ
  ˵    ������
***************************************************************************/
int array_getmax(MATRIX matrix[][ROW_MAX], const int line, const int row)
{
	int i, j, max = 0;  /*����ֵ����Ϊ0*/

	for (i = 0; i < line; i++) {
		for (j = 0; j < row; j++) {
			if (max < matrix[i][j].num)  /*����ǰԪ�ص���ֵ����max��ǰֵ��������ֵ����max*/
				max = matrix[i][j].num;
		}
	}

	return max;
}

/***************************************************************************
  �������ƣ�array_move_zero
  ��    �ܣ����ϲ���ɺ�����ʣ���0�����ƶ�����ɷ����������Ч��
  ���������MATRIX matrix[][ROW_MAX]��������Ϸ�еĽṹ���ά����
			const int line����������
			const int row����������
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void array_move_zero(MATRIX matrix[][ROW_MAX], const int line, const int row)
{
	int i, j, t;  /*�����������м����*/

	/*�����жϣ�һ���д��������ж�*/
	for (j = 0; j < row; j++) {
		for (i = line - 1; i >= 0; i--) {

			/*��������ֵΪ���Ԫ��*/
			if (matrix[i][j].num == 0) {
				int I = i;  /*ȡԪ����������*/
				MATRIX m[LINE_MAX][ROW_MAX];  /*�м�����*/
				array_copy(m, matrix, line, row);  /*����ǰ���鸴�Ƶ��м�����ȥ*/

				/*��Ԫ�ز������������Ԫ�ؽ������ԣ�ֱ����Ԫ�ص����һ��Ϊֹ*/
				while (I > 0) {
					t = matrix[I][j].num;
					matrix[I][j].num = matrix[I - 1][j].num;
					matrix[I - 1][j].num = t;
					t = matrix[I][j].mark;
					matrix[I][j].mark = matrix[I - 1][j].mark;
					matrix[I - 1][j].mark = t;
					I--;  /*ÿ����һ��I�Լ�*/
				}

				/*������ǰ�ʹ���������Ƚϣ����в�ͬ������ܱ��������������i��Ϊline���ӱ��е����һ�����¼��*/
				if (!array_compare(m, matrix, line, row))
					i = line;
			}
		}
	}
}

/***************************************************************************
  �������ƣ�array_compare
  ��    �ܣ��Ƚ������ṹ���ά�����Ƿ���ͬ
  ���������MATRIX matrix1[][ROW_MAX]�����ȽϵĽṹ���ά����
            MATRIX matrix2[][ROW_MAX]�����ȽϵĽṹ���ά����
			const int line����������
			const int row����������
  �� �� ֵ��bool�������ṹ�������Ƿ���ͬ
  ˵    ������
***************************************************************************/
bool array_compare(MATRIX matrix1[][ROW_MAX], MATRIX matrix2[][ROW_MAX], const int line, const int row)
{
	int i, j;         /*��������*/
	bool ret = true;  /*����ֵ����ֵΪ��*/

	for (i = 0; i < line; i++) {
		for (j = 0; j < row; j++) {
			if (matrix1[i][j].num != matrix2[i][j].num) {  /*��ֵ����ȣ�����ֵ��Ϊ�ٺ�����Ƚ�*/
				ret = false;
				break;
			}

			if (matrix1[i][j].mark != matrix2[i][j].mark) {  /*���״̬����ȣ�����ֵ��Ϊ�ٺ�����Ƚ�*/
				ret = false;
				break;
			}
		}

		if (ret == false)  /*������ֵΪ�٣������Ƚ�*/
			break;
	}

	return ret;
}

/***************************************************************************
  �������ƣ�array_compare
  ��    �ܣ��Ƚ������ṹ���ά�����Ƿ���ͬ
  ���������MATRIX Destination[][ROW_MAX]������ֵ�Ľṹ���ά����
            MATRIX Source[][ROW_MAX]��Ԫ����Դ�Ľṹ���ά����
			const int line����������
			const int row����������
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void array_copy(MATRIX Destination[][ROW_MAX], const MATRIX Source[][ROW_MAX], const int line, const int row)
{
	int i, j;  /*��������*/
	for (i = 0; i < line; i++) {
		for (j = 0; j < row; j++) {
			Destination[i][j].num = Source[i][j].num;    /*����Ԫ����ֵ*/
			Destination[i][j].mark = Source[i][j].mark;  /*����Ԫ�ر��״̬*/
		}
	}
}

/***************************************************************************
  �������ƣ�array_mark_set
  ��    �ܣ�ȥ������������Ԫ�صı��
  ���������MATRIX matrix[][ROW_MAX]��������Ϸ�еĽṹ���ά����
			const int line����������
			const int row����������
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void array_mark_set(MATRIX matrix[][ROW_MAX], const int line, const int row)
{
	int i, j;  /*��������*/
	for (i = 0; i < line; i++) {
		for (j = 0; j < row; j++) {
			matrix[i][j].mark = 0;  /*Ԫ�ر��״̬Ϊ0*/
		}
	}
}

/***************************************************************************
  �������ƣ�array_mark_count
  ��    �ܣ�ͳ���������ѱ�ǵ�Ԫ�ظ���
  ���������MATRIX matrix[][ROW_MAX]��������Ϸ�еĽṹ���ά����
			const int line����������
			const int row����������
  �� �� ֵ��int���ѱ�ǵ�Ԫ�ظ���
  ˵    ������
***************************************************************************/
int array_mark_count(MATRIX matrix[][ROW_MAX], const int line, const int row)
{
	int i, j, count = 0;

	for (i = 0; i < line; i++) {
		for (j = 0; j < row; j++) {
			if (matrix[i][j].mark)  /*���ѱ���ǣ�������������*/
				count++;
		}
	}

	return count;
}

/***************************************************************************
  �������ƣ�array_random
  ��    �ܣ��Ժϲ�������������ֵ���
  ���������MATRIX matrix[][ROW_MAX]��������Ϸ�еĽṹ���ά����
			const int line����������
			const int row����������
			const int MaxNum�����ǰ�����е������ֵ
  �� �� ֵ����
  ˵    ���������������������ֵ������������ֵ�ĸ���
***************************************************************************/
void array_random(MATRIX matrix[][ROW_MAX], const int line, const int row, const int MaxNum)
{
	int i, j;  /*��������*/

	/*������������Ԫ�ص���ֵ*/
	for (i = 0; i < line; i++) {
		for (j = 0; j < row; j++) {

			/*��������ֵΪ���Ԫ��*/
			if (matrix[i][j].num == 0) {
				int random = rand();  /*����ȸ�������һ��0-32767֮�����*/

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
  �������ƣ�command_goal_achieved
  ��    �ܣ�������ģʽ�£�����ﵽ�ϳ�Ŀ��ʱ��������ʾ
  ���������int& goal���ϳ�Ŀ��
  �� �� ֵ����
  ˵    ����������������goal������ʱʹgoal����
***************************************************************************/
void command_goal_achieved(int& goal)
{
	int X, Y;
	cout << endl;
	cct_getxy(X, Y);
	cct_showstr(X, Y, "�Ѿ��ϳɵ�", COLOR_HYELLOW, COLOR_RED);
	cct_getxy(X, Y);
	cct_showch(X, Y, char(goal + '0'), COLOR_HYELLOW, COLOR_RED);

	cct_setcolor();
	cout << endl << "���س������������Ŀ�����..." << endl;

	goal++;  /*goal�������ϳ�Ŀ������*/
}

/***************************************************************************
  �������ƣ�command_end
  ��    �ܣ�������ģʽ�£�����޿ɺϲ������Ϸ����ʱ��������ʾ
  �����������
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void command_end()
{
	int X, Y;
	cct_getxy(X, Y);
	cct_showstr(X, Y, "�޿ɺϲ������Ϸ����!", COLOR_HYELLOW, COLOR_RED);
	cct_setcolor();
	cout << endl;
}