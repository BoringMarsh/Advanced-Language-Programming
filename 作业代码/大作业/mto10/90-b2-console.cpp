/*2151294 ��11 ����*/
#include <iostream>
#include <iomanip>
#include <Winsock2.h>
#include <Windows.h>
#include "cmd_console_tools.h"
#include "90-b2.h"
using namespace std;

/***************************************************************************
  �������ƣ�block_single_print
  ��    �ܣ���ӡһ�����������ֵ�����ɫ�ķ���
  ���������const int num�������м�����֣�ֻ����
            const int bg_color�����鱳��ɫ��ֻ����
			const int fg_color������ǰ��ɫ��ֻ����
  �� �� ֵ����
  ˵    ����1���������Թ�굱ǰλ��Ϊ��������Ͻ�
            2��δ����λ�������ϵ��������ʽ������
***************************************************************************/
void block_single_print(const int num, const int bg_color, const int fg_color)
{
	int X, Y;         /*��������*/
	cct_getxy(X, Y);  /*ȡ��굱ǰ����*/

	cct_showstr(X, Y, "������", bg_color, fg_color);  /*��ӡ�ϱ߽�*/
	cct_showstr(X, Y + 1, "��", bg_color, fg_color);  /*��ӡ��߽�*/

	/*��numΪһλ�������������һ���ո�*/
	if (num < 10) {
		cct_showch(X + 2, Y + 1, char(num + '0'), bg_color, fg_color);
		cct_showch(X + 3, Y + 1, ' ', bg_color, fg_color);
	}
	/*��numΪ��λ�����������������ͬλ�ϵ���*/
	else {
		cct_showch(X + 2, Y + 1, char((num - num % 10) / 10 + '0'), bg_color, fg_color);
		cct_showch(X + 3, Y + 1, char(num % 10 + '0'), bg_color, fg_color);
	}

	cct_showstr(X + 4, Y + 1, "��", bg_color, fg_color);  /*��ӡ�ұ߽�*/
	cct_showstr(X, Y + 2, "������", bg_color, fg_color);  /*��ӡ�±߽�*/
	cct_setcolor();  /*������ɫ*/
}

/***************************************************************************
  �������ƣ�console_print_background
  ��    �ܣ���ӡ��ɫ�������ڵİ�ɫ����
  ���������const int line������������ֻ����
            const int row������������ֻ����
			const int print_mode����ӡģʽ��ֻ����
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void console_print_background(const int line, const int row, const int print_mode)
{
	char ch = 'A';  /*�б꣬��ֵΪA*/
	int Y;          /*������*/

	background_number(row, print_mode);  /*����������б�*/

	/*�б�λ�ڵ�һ�У�����ӵڶ��п�ʼ�����д�ӡ����*/
	for (Y = 2; Y <= (3 + print_mode) * line + (3 - print_mode); Y++) {
		background_letter(Y, ch, print_mode);  /*����б�*/

		if (Y % (3 + print_mode) == (1 - print_mode))  /*ÿ��ӡһ���б꣬�б�����*/
			ch++;

		background_multiple_lines(line, row, print_mode);  /*�����ͬ��ʽ��ÿһ��*/

		cout << " ";  /*ÿ��ĩβ�Ŀո�*/
	}
}

/***************************************************************************
  �������ƣ�background_number
  ��    �ܣ���ӡ��������������������������б�
  ���������const int row������������ֻ����
			const int print_mode����ӡģʽ��ֻ����
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void background_number(const int row, const int print_mode)
{
	int i;
	cout << resetiosflags(ios::left);  /*�����������*/

	for (i = 0; i < row; i++) {
		if (i)  /*i��Ϊ��ʱ������ӡģʽ���ÿ��*/
			cout << setw(6 + print_mode * 2) << setiosflags(ios::right) << i;
		else    /*iΪ��ʱ�����ÿ��Ϊ6*/
			cout << setw(6) << setiosflags(ios::right) << i;
	}

	cout << endl;
}

/***************************************************************************
  �������ƣ�background_letter
  ��    �ܣ���ӡ��������������������������б�
  ���������const int Y����굱ǰ�����ֻ꣨����
            const char ch����ǰ��������бֻ꣨����
			const int print_mode����ӡģʽ��ֻ����
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void background_letter(const int Y, const char ch, const int print_mode)
{
	if (Y % (3 + print_mode) == (1 - print_mode))  /*��ǰΪָ��λ�ã�����б꼰һ���ո�*/
		cout << ch << " ";
	else  /*��ǰ��Ϊָ��λ�ã���������ո�*/
		cout << "  ";
}

/***************************************************************************
  �������ƣ�background_line
  ��    �ܣ���ӡ�������������������������ĳһ��
  ���������int row����������
			int Y�������ú���ǰ��������
			const char firstch[]�����е�һ���Ʊ����ֻ����
			const char midch[]�������м���Ʊ����ֻ����
			const char midspecialch[]�������м�������Ʊ����ֻ����
			const char lastch[]���������һ���Ʊ����ֻ����
			int print_mode����ӡģʽ
  �� �� ֵ����
  ˵    ����1��ÿ�ж��Ǵ�X=2����ʼ��ӡ
            2��ÿ���һ���Ʊ����X��������2�Ĳ���
***************************************************************************/
void background_line(int row, int Y, const char firstch[], const char midch[], const char midspecialch[], const char lastch[], int print_mode)
{
	int i;      /*��������*/
	int X = 2;  /*�����꣬��ʼΪ2*/

	/*1�������һ���Ʊ��*/
	cct_showstr(X, Y, firstch, COLOR_WHITE, COLOR_BLACK);
	X = X + 2;

	/*2������м�Ķ���Ʊ��*/
	for (i = 0; i < 3 * row; i++) {

		/*2.1������м��һ���Ʊ��*/
		cct_showstr(X, Y, midch, COLOR_WHITE, COLOR_BLACK);
		X = X + 2;

		/*2.2����ָ��λ�ô�ӡ�����Ʊ��*/
		if (print_mode) {
			if (X % 8 == 2 && X != 2 + row * 8) {
				cct_showstr(X, Y, midspecialch, COLOR_WHITE, COLOR_BLACK);
				X = X + 2;
			}
		}

		/*2.3��ÿִ������ֹͣ1�����ƴ�ӡ�ٶ�*/
		if (i % 3 == 1)
			Sleep(1);
	}

	/*3��������һ���Ʊ����������ɫ*/
	cct_showstr(X, Y, lastch, COLOR_WHITE, COLOR_BLACK);
	cct_setcolor();
}

/***************************************************************************
  �������ƣ�background_multiple_lines
  ��    �ܣ���ӡ������������������������ĸ���
  ���������const int line������������ֻ����
            const int row������������ֻ����
			const int print_mode����ӡģʽ��ֻ����
  �� �� ֵ����
  ˵    ������������һ��ʼȡ��ǰ�������꣬�������ʵ�δ�ֵ
***************************************************************************/
void background_multiple_lines(const int line, const int row, const int print_mode)
{
	int X, Y;         /*��������*/
	cct_getxy(X, Y);  /*ȡ��ǰ��������*/

	/*���е����*/
	if (Y == 2)
		background_line(row, Y, "��", "��", "��", "��", print_mode);

	/*���һ�е����*/
	else if (Y == (3 + print_mode) * line + (3 - print_mode))
		background_line(row, Y, "��", "��", "��", "��", print_mode);

	/*�����е����*/
	else if (Y % 4 == 2 && print_mode == 1)
		background_line(row, Y, "��", "��", "��", "��", PRINT_WITH_LINE);

	/*һ���е����*/
	else
		background_line(row, Y, "��", "  ", "��", "��", print_mode);
}

/***************************************************************************
  �������ƣ�console_print_base
  ��    �ܣ�ͼ�λ������ʼ���飬����������ɫ��
  ���������MATRIX matrix[][ROW_MAX]��������Ϸ�еĽṹ���ά����
            const int line������������ֻ����
			const int row������������ֻ����
			const int print_mode����ӡģʽ��ֻ����
  �� �� ֵ����
  ˵    ������������һ��ʼȡ��ǰ�������꣬�������ʵ�δ�ֵ
***************************************************************************/
void console_print_base(MATRIX matrix[][ROW_MAX], const int line, const int row, const int print_mode)
{
	const int LENGTH = row * (6 + print_mode * 2) + (7 - print_mode * 2);  /*��������ȡ����*/
	const int WIDTH = line * (3 + print_mode) + (8 - print_mode);          /*��������ȡ���*/
	int i, j;  /*��������*/

	cct_setconsoleborder(LENGTH, WIDTH);  /*����ȡ�õĳ��ȼ���ȣ���̬���ô��ڴ�С*/
	cout << "��Ļ��ǰ����Ϊ��" << LENGTH << "��" << WIDTH << "��" << endl << ' ';  /*�����Ļ������Ϣ*/
	console_print_background(line, row, print_mode);  /*��ӡ��ɫ����*/

	/*ͨ�����ʽṹ�������е����ݣ������ӡɫ��*/
	for (i = 0; i < line; i++) {
		for (j = 0; j < row; j++) {
			cct_gotoxy(j * (6 + print_mode * 2) + 4, i * (3 + print_mode) + 3);
			block_single_print(matrix[i][j].num, matrix[i][j].num, COLOR_BLACK);
		}
		Sleep(1);  /*ÿ��ӡ��һ��ֹͣ1�����ƴ�ӡ�ٶ�*/
	}

	cout << "\n\n";  /*�����ɺ�������λ��*/
}

/***************************************************************************
  �������ƣ�block_single_activate
  ��    �ܣ�����ǰ�����¶�Ӧ��ɫ�����ø���
  ���������MATRIX matrix[][ROW_MAX]��������Ϸ�еĽṹ���ά����
			const char coordinate[]�����Ŀ��ɫ����������飨ֻ����
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void block_single_activate(MATRIX matrix[][ROW_MAX], const char coordinate[])
{
	const int I = coordinate[0] - 'A';  /*���б�ת��Ϊ����*/
	const int J = coordinate[1] - '0';  /*���б�ת��Ϊ����*/
	cct_gotoxy(J * 8 + 4, I * 4 + 3);   /*�ƶ������ָ��λ�ã����ڽ������ػ�ɫ��*/
	block_single_print(matrix[I][J].num, matrix[I][J].num, COLOR_WHITE);  /*�ػ�ɫ�飬��ɫ���䣬ǰ��ɫΪ��ɫ*/
	cct_setcolor();  /*������ɫ*/
}

/***************************************************************************
  �������ƣ�block_single_default
  ��    �ܣ�����ǰ�����¶�Ӧ��ɫ�����ȡ��
  ���������MATRIX matrix[][ROW_MAX]��������Ϸ�еĽṹ���ά����
			const char coordinate[]�����Ŀ��ɫ����������飨ֻ����
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void block_single_default(MATRIX matrix[][ROW_MAX], const char coordinate[])
{
	bool prime;  /*��Ӧ�����Ƿ�Ϊ��ʼֵ*/
	if (coordinate[0] == '\0' && coordinate[1] == '\0')
		prime = false;
	else
		prime = true;

	/*������Ϊ��ʼֵ����Ϊ'\0'������ִ���ػ���������ֹ��������Խ��*/
	if (prime) {
		const int I = coordinate[0] - 'A';  /*���б�ת��Ϊ����*/
		const int J = coordinate[1] - '0';  /*���б�ת��Ϊ����*/
		cct_gotoxy(J * 8 + 4, I * 4 + 3);   /*�ƶ������ָ��λ�ã����ڽ������ػ�ɫ��*/
		block_single_print(matrix[I][J].num, matrix[I][J].num, COLOR_BLACK);  /*�ػ�ɫ�飬��ɫ���䣬ǰ��ɫΪ��ɫ*/
	}

	cct_setcolor();  /*������ɫ*/
}

/***************************************************************************
  �������ƣ�block_multiple_activate
  ��    �ܣ������������б���ǵ�Ԫ�ض�Ӧɫ�����ø���
  ���������MATRIX matrix[][ROW_MAX]��������Ϸ�еĽṹ���ά����
			const int line������������ֻ����
			const int row������������ֻ����
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void block_multiple_activate(MATRIX matrix[][ROW_MAX], const int line, const int row)
{
	int i, j;
	char coord[2];  /*���Ԫ��������ַ�����*/

	/*���������б����Ԫ������ȡ��ʱʱ��*/
	int count = array_mark_count(matrix, line, row);
	unsigned int delay;

	if (count <= 5)
		delay = 100;
	else
		delay = 25;

	/*������������Ԫ�أ�������������ø���*/
	for (i = 0; i < line; i++) {
		for (j = 0; j < row; j++) {
			if (matrix[i][j].mark) {
				coord[0] = i + 'A';
				coord[1] = j + '0';
				block_single_activate(matrix, coord);
				Sleep(delay);  /*ÿ����һ��ɫ��ĸ�������ʱ�������ٶ�*/
			}
		}
	}
}

/***************************************************************************
  �������ƣ�block_multiple_default
  ��    �ܣ������������ж�Ӧ����ɫ��ĸ���ȡ��
  ���������MATRIX matrix[][ROW_MAX]��������Ϸ�еĽṹ���ά����
			const int line������������ֻ����
			const int row������������ֻ����
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void block_multiple_default(MATRIX matrix[][ROW_MAX], const int line, const int row)
{
	int i, j;
	char coord[2];  /*���Ԫ��������ַ�����*/

	for (i = 0; i < line; i++) {
		for (j = 0; j < row; j++) {
			if (matrix[i][j].mark) {
				coord[0] = i + 'A';
				coord[1] = j + '0';
				block_single_default(matrix, coord);
				Sleep(1);  /*ÿȡ��һ��ɫ��ĸ�������ʱ�������ٶ�*/
			}
		}
	}
}

/***************************************************************************
  �������ƣ�block_single_clear
  ��    �ܣ�����ǰ�����¶�Ӧ��ɫ�����
  �����������
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void block_single_clear()
{
	int X, Y;
	cct_getxy(X, Y);
	cct_showstr(X, Y, "      ", COLOR_WHITE);      /*�ð�ɫ������һ��*/
	cct_showstr(X, Y + 1, "      ", COLOR_WHITE);  /*�ð�ɫ�����ڶ���*/
	cct_showstr(X, Y + 2, "      ", COLOR_WHITE);  /*�ð�ɫ����������*/
	cct_setcolor();  /*������ɫ*/
}

/***************************************************************************
  �������ƣ�block_multiple_clear
  ��    �ܣ������������е�ɫ����кϳ�
  ���������MATRIX matrix[][ROW_MAX]��������Ϸ�еĽṹ���ά����
			const int line������������ֻ����
			const int row������������ֻ����
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void block_multiple_clear(MATRIX matrix[][ROW_MAX], const int line, const int row)
{
	int i, j;

	for (i = 0; i < line; i++) {
		for (j = 0; j < row; j++) {

			/*���������ֵ��Ϊ�㣬��ΪĿ��Ԫ�أ��ػ���ǰɫ��*/
			if (matrix[i][j].mark == 1 && matrix[i][j].num != 0) {
				cct_gotoxy(8 * j + 4, 4 * i + 3);
				block_single_print(matrix[i][j].num, matrix[i][j].num, COLOR_BLACK);
				Sleep(1);  /*��ʱ1�������ٶ�*/
			}

			/*���������ֵΪ�㣬��Ϊ��ֵΪ��Ԫ�أ������ǰɫ��*/
			else if (matrix[i][j].mark == 1 && matrix[i][j].num == 0) {
				cct_gotoxy(8 * j + 4, 4 * i + 3);
				block_single_clear();
				Sleep(1);  /*��ʱ1�������ٶ�*/
			}
		}
	}
}

/***************************************************************************
  �������ƣ�block_single_fall
  ��    �ܣ���ʾ����ɫ������һ��Ķ���
  ���������MATRIX matrix[][ROW_MAX]��������Ϸ�еĽṹ���ά����
			const char coordinate[]����ŵ�ǰɫ���Ӧ������ַ����飨ֻ����
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void block_single_fall(MATRIX matrix[][ROW_MAX], const char coordinate[])
{
	const int I = coordinate[0] - 'A';  /*���б�ת��Ϊ����*/
	const int J = coordinate[1] - '0';  /*���б�ת��Ϊ����*/
	const int X = J * 8 + 4;  /*ȡ��ʼ������*/
	const int Y = I * 4 + 3;  /*ȡ��ʼ������*/

	/*�ܹ���������*/
	for (int i = 0; i < 5; i++) {

		/*ÿ����һ�оʹ�ӡ��ǰɫ��*/
		cct_gotoxy(X, Y + i);
		block_single_print(matrix[I][J].num, matrix[I][J].num, COLOR_BLACK);

		/*ÿ����һ�����ɫ�飬ѭ�����һ�β�ִ�У��������һ�λ�����ɫ�鱻���*/
		if (i < 4) {
			cct_gotoxy(X, Y + i);
			block_single_clear();
		}

		/*�ػ����¸���֮��ķָ���*/
		cct_showstr(X, Y + 3, "��", COLOR_WHITE, COLOR_BLACK, 3);

		/*ÿ����������ʱ1�������ٶ�*/
		if (i % 2 == 0)
			Sleep(1);
	}

	cct_setcolor();  /*������ɫ*/
}

/***************************************************************************
  �������ƣ�block_multiple_fall
  ��    �ܣ���ʾ����������ɫ��Խ���ո�����Ķ���
  ���������MATRIX matrix[][ROW_MAX]��������Ϸ�еĽṹ���ά����
			const int line������������ֻ����
			const int row������������ֻ����
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void block_multiple_fall(MATRIX matrix[][ROW_MAX], const int line, const int row)
{
	int i, j, t;    /*�����������м����*/
	char coord[2];  /*�������ɫ��������ַ�����*/

	/*���м�飬��������һ�п�ʼ���*/
	for (j = 0; j < row; j++) {
		for (i = line - 1; i >= 0; i--) {

			/*����������һɫ���ӦԪ����ֵΪ�㣨�����ڵ�һ�У��������Ϸ�ɫ���ӦԪ����ֵ��Ϊ�㣬��ִ���������*/
			if (matrix[i][j].num == 0 && matrix[i - 1][j].num != 0 && i != 0) {

				/*һֱ����ֱ��i��j��Ԫ�ز�Ϊ�㣨����Ԫ�ص�ǰλ�����·�û���㣩Ϊֹ*/
				while (matrix[i][j].num == 0) {
					coord[0] = i - 1 + 'A';  /*���б�ת��Ϊ�ַ�*/
					coord[1] = j + '0';      /*���б�ת��Ϊ�ַ�*/
					block_single_fall(matrix, coord);  /*ʹɫ������һ��*/

					/*������ֵ��ע�⣺����ǰ��i-1�в���Ҫ�����Ԫ�أ�i�������·���0*/
					matrix[i][j].num = matrix[i - 1][j].num;
					matrix[i - 1][j].num = 0;

					/*�������״̬��ע�⣺����ǰ��i-1�в���Ҫ�����Ԫ�أ�i�������·���0*/
					t = matrix[i - 1][j].mark;
					matrix[i - 1][j].mark = matrix[i][j].mark;
					matrix[i][j].mark = t;

					/*����û���䵽������һ�У�i�����������ٴ�����Ĳ���*/
					if (i < line - 1)
						i++;
				}
			}
		}
	}
}

/***************************************************************************
  �������ƣ�block_multiple_print
  ��    �ܣ����鲹����ֵ���ػ���һ��������������ɫ��
  ���������MATRIX matrix[][ROW_MAX]��������Ϸ�еĽṹ���ά����
			const int line������������ֻ����
			const int row������������ֻ����
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void block_multiple_print(MATRIX matrix[][ROW_MAX], const int line, const int row)
{
	int i, j;

	for (i = 0; i < line; i++) {
		for (j = 0; j < row; j++) {
			if (matrix[i][j].mark) {  /*��Ԫ�ر���ǲ��ػ���Ӧɫ�飬�������Ч��*/
				cct_gotoxy(8 * j + 4, 4 * i + 3);
				block_single_print(matrix[i][j].num, matrix[i][j].num, COLOR_BLACK);
				Sleep(1);  /*ÿ����һ��ɫ����ʱ1�������ٶ�*/
			}
		}
	}
}

/***************************************************************************
  �������ƣ�console_blink_block
  ��    �ܣ�ʹ��ǰ�����µ�Ԫ�ض�Ӧɫ����˸
  ���������MATRIX matrix[][ROW_MAX]��������Ϸ�еĽṹ���ά����
			const char coordinate[]�������˸ɫ��������ַ����飨ֻ����
  �� �� ֵ����
  ˵    ��������������Ϊ��˸10��
***************************************************************************/
void console_blink_block(MATRIX matrix[][ROW_MAX], const char coordinate[])
{
	const int I = coordinate[0] - 'A';  /*���б�ת��Ϊ����*/
	const int J = coordinate[1] - '0';  /*���б�ת��Ϊ����*/
	const int rpt = 10;       /*�ظ�������10��*/

	for (int i = 0; i < rpt; i++) {
		block_single_activate(matrix, coordinate);  /*���ø���*/
		Sleep(10);  /*��ʱ10�������ٶ�*/

		block_single_default(matrix, coordinate);   /*����ȡ��*/
		Sleep(10);  /*��ʱ10�������ٶ�*/
	}
}

/***************************************************************************
  �������ƣ�special_info
  ��    �ܣ�αͼ�ν����£����������ʾ
  ���������const int line������������ֻ����
            int& goal���ϳ�Ŀ��
			const int info_name��������ʾ���ƣ�ֻ����
  �� �� ֵ����
  ˵    ����������������goal������ʱʹgoal����
***************************************************************************/
void special_info(const int line, int& goal, const int info_name)
{
	int X = 0;             /*ȡ��ʼ������*/
	int Y = 4 * line + 3;  /*ȡ��ʼ������*/

	/*����ԭ������*/
	cct_gotoxy(X, Y);
	for (int i = 0; i < 85; i++)
		cout << ' ';
	cct_gotoxy(X, Y);

	/*1����Ҫ�ı�������ɫ����ʾ*/
	switch (info_name) {
	case INFO_NO_CLEAR:
		cct_showstr(X, Y, "��Χ����ֵͬ��", COLOR_BLACK, COLOR_HYELLOW);
		break;
	case INFO_GOAL_ACHIEVED:
		cct_showstr(X, Y, "�Ѿ��ϳɵ�", COLOR_BLACK, COLOR_HYELLOW);
		cct_getxy(X, Y);
		cct_showch(X, Y, char(goal + '0'), COLOR_BLACK, COLOR_HYELLOW);
		cct_getxy(X, Y);
		cct_showstr(X, Y, "��", COLOR_BLACK, COLOR_HYELLOW);
		break;
	case INFO_END:
		cct_showstr(X, Y, "�޿ɺϲ������Ϸ����!", COLOR_BLACK, COLOR_HYELLOW);
		break;
	case MENU8_CONTINUE:
		cct_showstr(X, Y, "���κϳɽ�������C/�������������һ�εĺϳ�", COLOR_BLACK, COLOR_HYELLOW);
		break;
	}

	cct_setcolor();  /*������ɫ*/

	/*2��ʹ��������ɫ����ʾ*/
	switch (info_name) {
	case INFO_RULES:
		cout << "��ͷ��/����ƶ����س���/�������ѡ��Q/�����Ҽ�����";
		break;
	case INFO_NO_CLEAR:
		cout << "��ͷ��/����ƶ����س���/�������ѡ��Q/�����Ҽ�����";
		break;
	case INFO_GOAL_ACHIEVED:
		goal++;  /*�ϳ�Ŀ������*/
		cout << "���س���/����������������Ŀ�����";
		break;
	case INFO_MAKE_SURE:
		cout << "��ͷ��/����ƶ�ȡ����ǰѡ�񣬻س���/��������ϳ�";
		break;
	case INFO_END:
		cout << "��Q�˳�";
		break;
	case MENU8_FALL:
		cout << "�ϳ���ɣ��س���/�����������0";
		break;
	case MENU8_FILL:
		cout << "����0��ɣ��س���/������������ֵ";
		break;
	}
}

/***************************************************************************
  �������ƣ�mouse_and_keyboard
  ��    �ܣ�ͨ�����������̣���ɶ���ɫ���ѡ��
  ���������MATRIX matrix[][ROW_MAX]��������Ϸ�еĽṹ���ά����
			const int line������������ֻ����
			const int row������������ֻ����
			char final_coord[]���������ѡ��ɫ�����������
  �� �� ֵ����
  ˵    ������
***************************************************************************/
int mouse_and_keyboard(MATRIX matrix[][ROW_MAX], const int line, const int row, char final_coord[])
{
	int X = 0, Y = 0;        /*�������꣬��ʼ��Ϊ��*/
	int ret, maction;
	int keycode1, keycode2;
	int loop = 1;
	int count = 0;            /*����������������ļ�����*/
	int RET = 0;              /*�����ķ���ֵ*/
	char coord[2] = { 0,0 };  /*�����ơ������λ�÷Ƿ�ʱ���̿��Ƶ�ʱ�򣬵�ǰѡ��ɫ�������*/
	char keyboard_coord[2] = { 0,0 };  /*���λ�úϷ�ʱ���̿��Ƶ�ʱ�򣬵�ǰѡ��ɫ�������*/

	cct_enable_mouse();  /*�������*/
	cct_setcursor(CURSOR_INVISIBLE);  /*�رչ��*/

	while (loop) {
		ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);  /*�����/����*/
		bool BOOL = if_in_block(X, Y, line, row, coord);  /*�жϴ�ʱ����λ���Ƿ���ĳ��ɫ���У�������ǰ�������������*/

		/*1�������ص�������¼�*/
		if (ret == CCT_MOUSE_EVENT) {
			count = 0;                                     /*�������������������*/
			block_single_default(matrix, keyboard_coord);  /*����������±�ѡ�е�ɫ��ȡ������*/
			mouse_act(matrix, line, coord, BOOL);          /*��ӡ��굱ǰ���*/

			/*����굥��������ҵ�ǰλ����ĳ��ɫ���У������ѭ��*/
			if (maction == MOUSE_LEFT_BUTTON_CLICK && BOOL == true) {
				select_act(matrix, final_coord, coord);  /*���ѡ��Ԫ�أ���final_coord[]��ֵ*/
				loop = 0;
			}

			else if (maction == MOUSE_RIGHT_BUTTON_CLICK && BOOL == true) {
				final_coord[0] = coord[0];  /*����final_coord[]����Ϣ*/
				final_coord[1] = coord[1];  /*����final_coord[]����Ϣ*/
				RET = MK_RET_MOUSE_RIGHT;   /*�����Ҽ��������������������ֵ��Ϊ��*/
				loop = 0;
			}
		}

		/*2�������ص��Ǽ����¼���ͬʱ���λ�÷Ƿ�*/
		else if (ret == CCT_KEYBOARD_EVENT && BOOL == false) {
			count = 0;                                      /*�������������������*/
			block_single_default(matrix, keyboard_coord);  /*����������±�ѡ�е�ɫ��ȡ������*/

			/*����������²��������궼Ϊ��ʼֵ�������ΪA0�����ⷢ������Խ��*/
			if (coord[0] == '\0' && coord[1] == '\0') {
				coord[0] = 'A';
				coord[1] = '0';
			}

			/*���ݼ�����еĲ���*/
			switch (keycode1) {
			case 'Q':
			case 'q':
				RET = MK_RET_KEYBOARD_Q;  /*��Q���������������������ֵ��Ϊ��*/
			case '\r':
				select_act(matrix, final_coord, coord);  /*���ѡ��Ԫ�أ���final_coord[]��ֵ*/
				loop = 0;
				break;
			case 224:
				keyboard_multiple_act(matrix, line, row, coord, keycode2);  /*���ڶ������������һ���ж�*/
				break;
			}
		}

		/*3�������ص��Ǽ����¼���ͬʱ���λ�úϷ�*/
		else if (ret == CCT_KEYBOARD_EVENT && BOOL == true) {
			/*���������ÿ��keyboard_coord[]����coord[]��ֵʱ��count������ѭ��ֻ��countΪ��ʱ���У�ȷ��ֻ��һ��ֵ*/
			while (count == 0) {
				keyboard_coord[0] = coord[0];
				keyboard_coord[1] = coord[1];
				count++;
			}

			/*���ݼ�����еĲ���ͬ��һ�����������ֻ��keyboard_coord[]���в���*/
			switch (keycode1) {
			case 'Q':
			case 'q':
				RET = MK_RET_KEYBOARD_Q;  /*��Q���������������������ֵ��Ϊ��*/
			case '\r':
				select_act(matrix, final_coord, keyboard_coord);  /*���ѡ��Ԫ�أ���final_coord[]��ֵ*/
				loop = 0;
				break;
			case 224:
				keyboard_multiple_act(matrix, line, row, keyboard_coord, keycode2);  /*���ڶ������������һ���ж�*/
				break;
			}
		}
	}

	cct_disable_mouse();	//�������

	return RET;
}

/***************************************************************************
  �������ƣ�mk_select
  ��    �ܣ������ͼ��̲����ض�Ӧ���¼�
  �����������
  �� �� ֵ��int��������¼�
  ˵    ����1��������ֻ���ü�����в��ֲ���ʱ����ѭ��
            2������������������mouse_and_keyboard����û�иı�����ֵ�����Ԫ�صȲ���
***************************************************************************/
int mk_select()
{
	int X = 0, Y = 0;        /*�������꣬��ʼ��Ϊ��*/
	int ret, maction;
	int keycode1, keycode2;
	int loop = 1;
	int RET;  /*��������ֵ*/

	cct_enable_mouse();  /*�������*/
	cct_setcursor(CURSOR_INVISIBLE);  /*�رչ��*/

	while (loop) {
		ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);

		if (ret == CCT_MOUSE_EVENT) {
			switch (maction) {
			case MOUSE_LEFT_BUTTON_CLICK:   /*�������*/
				RET = MK_RET_MOUSE_LEFT;
				loop = 0;
				break;
			case MOUSE_RIGHT_BUTTON_CLICK:  /*�����Ҽ�*/
				RET = MK_RET_MOUSE_RIGHT;
				loop = 0;
				break;
			case MOUSE_ONLY_MOVED:          /*���ƶ�*/
				RET = MK_RET_MOUSE_MOVE;
				loop = 0;
				break;
			}
		}

		else if (ret == CCT_KEYBOARD_EVENT) {
			switch (keycode1) {
			case '\r':
				RET = MK_RET_KEYBOARD_ENTER;  /*���س�*/
				loop = 0;
				break;
			case 224:
				RET = MK_RET_KEYBOARD_ARROW;  /*����ͷ��*/
				loop = 0;
				break;
			case 'C':
			case 'c':
				RET = MK_RET_KEYBOARD_C;      /*��C��*/
				loop = 0;
				break;
			case 'Q':
			case 'q':
				RET = MK_RET_KEYBOARD_Q;      /*��Q��*/
				loop = 0;
				break;
			}
		}
	}

	return RET;
}

/***************************************************************************
  �������ƣ�mk_pause
  ��    �ܣ�����һ������ļ�ϵ�
  ���������const int pause_mode����ͣ��ʽ��ֻ����
  �� �� ֵ����
  ˵    ����������ͨ������mk_select()�����̺���꣬���ض������²Ž���ѭ��
***************************************************************************/
void mk_pause(const int pause_mode)
{
	int loop = 1;

	while (loop) {
		int ret = mk_select();  /*��ret����mk_select()�ķ���ֵ*/

		switch (pause_mode) {
		case MK_ENTER_CONTINUE:  /*��굥���������̰��س�����*/
			if (ret == MK_RET_MOUSE_LEFT || ret == MK_RET_KEYBOARD_ENTER)
				loop = 0;
			break;
		case MK_C_CONTINUE:      /*��굥���������̰�C������*/
			if (ret == MK_RET_MOUSE_LEFT || ret == MK_RET_KEYBOARD_C)
				loop = 0;
			break;
		}
	}
}

/***************************************************************************
  �������ƣ�mouse_act
  ��    �ܣ���ӡ��굱ǰ���������ɫ������Ӧ����
  ���������MATRIX matrix[][ROW_MAX]��������Ϸ�еĽṹ���ά����
			const int line������������ֻ����
			const char coordinate[]����ǰѡ��ɫ������ֻ꣨����
			const bool prime����굱ǰλ���Ƿ���ĳ��ɫ���У�ֻ����
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void mouse_act(MATRIX matrix[][ROW_MAX], const int line, const char coordinate[], const bool prime)
{
	cct_gotoxy(0, 4 * line + 3);  /*���ݲ��������ƶ����λ��*/
	cout << "[��ǰ���] ";

	/*����굱ǰλ����ĳ��ɫ����*/
	if (prime) {

		/*����ԭ�����ݣ����������*/
		int X, Y;
		cct_getxy(X, Y);
		for (int i = 0; i < 100; i++)
			cout << ' ';
		cct_gotoxy(X, Y);
		cout << coordinate[0] << "��" << coordinate[1] << "��";

		/*ʹ��ǰѡ�е�ɫ�����*/
		block_single_activate(matrix, coordinate);
	}

	/*����굱ǰλ�ò���ĳ��ɫ����*/
	else {
		cout << "λ�÷Ƿ�";  /*�����ʾ*/
		block_single_default(matrix, coordinate);  /*ȡ����һ�α�ѡ��ɫ��ĸ���*/
	}
}

/***************************************************************************
  �������ƣ�select_act
  ��    �ܣ�����ѡ��ɫ��ʱ�Ĳ���
  ���������MATRIX matrix[][ROW_MAX]��������Ϸ�еĽṹ���ά����
			char final_coord[]���������ѡ��ɫ�����������
			const char source_coord[]��������ձ�ѡ��ɫ�����������
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void select_act(MATRIX matrix[][ROW_MAX], char final_coord[], const char selected_coord[])
{
	matrix[selected_coord[0] - 'A'][selected_coord[1] - '0'].mark = 1;  /*������ѡ�е�ɫ���Ӧ������Ԫ�������*/
	final_coord[0] = selected_coord[0];  /*����final_coord[]����Ϣ*/
	final_coord[1] = selected_coord[1];  /*����final_coord[]����Ϣ*/
}

/***************************************************************************
  �������ƣ�keyboard_single_act
  ��    �ܣ����̰������ʱĳһ������Ӧ�Ĳ���
  ���������MATRIX matrix[][ROW_MAX]��������Ϸ�еĽṹ���ά����
			const int line������������ֻ����
			const int row������������ֻ����
			char operate_coord[]����ǰ��������
			const int move_mode���ƶ���ʽ��ֻ����
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void keyboard_single_act(MATRIX matrix[][ROW_MAX], const int line, const int row, char operate_coord[], const int move_mode)
{
	block_single_default(matrix, operate_coord);  /*����ǰ���������Ӧ��ɫ�����ȡ��*/
	keyboard_coord_move(line, row, operate_coord, move_mode);  /*�����ƶ���ʽ�ı�����ֵ*/
	print_keyboard_info(line, operate_coord);       /*��ӡ���̵�ǰ״̬*/
	block_single_activate(matrix, operate_coord);  /*����ǰ���������Ӧ��ɫ������Ϊ����*/
}

/***************************************************************************
  �������ƣ�keyboard_multiple_act
  ��    �ܣ����̰������ʱ���в���
  ���������MATRIX matrix[][ROW_MAX]��������Ϸ�еĽṹ���ά����
			const int line������������ֻ����
			const int row������������ֻ����
			char operate_coord[]����ǰ��������
			const int keycode�����̷��صĵڶ����루ֻ����
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void keyboard_multiple_act(MATRIX matrix[][ROW_MAX], const int line, const int row, char operate_coord[], const int keycode)
{
	switch (keycode) {
	case KB_ARROW_UP:     /*���ϣ������Ʒ�ʽ���в���*/
		keyboard_single_act(matrix, line, row, operate_coord, KEYBOARD_MOVE_UP);
		break;
	case KB_ARROW_DOWN:   /*���£������Ʒ�ʽ���в���*/
		keyboard_single_act(matrix, line, row, operate_coord, KEYBOARD_MOVE_DOWN);
		break;
	case KB_ARROW_LEFT:   /*���������Ʒ�ʽ���в���*/
		keyboard_single_act(matrix, line, row, operate_coord, KEYBOARD_MOVE_LEFT);
		break;
	case KB_ARROW_RIGHT:  /*���ң������Ʒ�ʽ���в���*/
		keyboard_single_act(matrix, line, row, operate_coord, KEYBOARD_MOVE_RIGHT);
		break;
	}
}

/***************************************************************************
  �������ƣ�keyboard_coord_move
  ��    �ܣ������ƶ���ʽ���ı䵱ǰ���������ֵ
  ���������const int line������������ֻ����
			const int row������������ֻ����
			char coordinate[]����ŵ�ǰ�������������
			const int move_mode���ƶ���ʽ��ֻ����
  �� �� ֵ����
  ˵    ��������ı����Ϊ�߽����
***************************************************************************/
void keyboard_coord_move(const int line, const int row, char coordinate[], const int move_mode)
{
	const int I = coordinate[0] - 'A';  /*���б�ת��Ϊ����*/
	const int J = coordinate[1] - '0';  /*���б�ת��Ϊ����*/

	switch (move_mode) {
	case KEYBOARD_MOVE_UP:     /*�����ƶ�����Ϊ�ϱ߽磬�߽���ƣ������б��Լ�*/
		if (I == 0)
			coordinate[0] = line - 1 + 'A';
		else
			coordinate[0]--;
		break;
	case KEYBOARD_MOVE_DOWN:   /*�����ƶ�����Ϊ�±߽磬�߽���ƣ������б�����*/
		if (I == line - 1)
			coordinate[0] = 'A';
		else
			coordinate[0]++;
		break;
	case KEYBOARD_MOVE_LEFT:   /*�����ƶ�����Ϊ��߽磬�߽���ƣ������б��Լ�*/
		if (J == 0)
			coordinate[1] = row - 1 + '0';
		else
			coordinate[1]--;
		break;
	case KEYBOARD_MOVE_RIGHT:  /*�����ƶ�����Ϊ�ұ߽磬�߽���ƣ������б�����*/
		if (J == row - 1)
			coordinate[1] = '0';
		else
			coordinate[1]++;
		break;
	}
}

/***************************************************************************
  �������ƣ�if_in_block
  ��    �ܣ�������굱ǰλ�õ����꣬�ж����Ƿ���ĳ��ɫ����
  ���������const int X���������ֻ꣨����
			const int Y����������ֻ꣨����
			const int line������������ֻ����
			const int row������������ֻ����
			char coordinate[]�����������ת��������ɫ������
  �� �� ֵ����
  ˵    ���������λ�÷Ƿ����򲻸ı�coordinate[]��ֵ
***************************************************************************/
bool if_in_block(const int X, const int Y, const int line, const int row, char coordinate[])
{
	int i, j;  /*��������*/
	bool if_x = false, if_y = false;  /*�ᡢ�������Ƿ���ĳ��ɫ���У���ʼ��Ϊ��*/

	/*�Ժ������飬��������������һ��ɫ���У���Ϊ�沢ֹͣ���*/
	for (j = 0; j < row; j++) {
		if (X >= 8 * j + 4 && X <= 8 * j + 9) {
			if_x = true;
			break;
		}
	}

	/*���������飬��������������һ��ɫ���У���Ϊ�沢ֹͣ���*/
	for (i = 0; i < line; i++) {
		if (Y >= 4 * i + 3 && Y <= 4 * i + 5) {
			if_y = true;
			break;
		}
	}

	/*���ᡢ�����궼��ĳһɫ���У���λ�úϷ�*/
	if (if_x == true && if_y == true) {
		coordinate[0] = i + 'A';  /*��ת�����ɫ���б긳��coordinate[]*/
		coordinate[1] = j + '0';  /*��ת�����ɫ���б긳��coordinate[]*/
		return true;  /*λ�úϷ���������*/
	}

	/*���ᡢ��������һ������ĳһɫ���У���λ�÷Ƿ�*/
	else
		return false;  /*λ�÷Ƿ������ؼ�*/
}

/***************************************************************************
  �������ƣ�print_keyboard_info
  ��    �ܣ�������̵�ǰ���
  ���������const int line������������ֻ����
			char coordinate[]����ǰѡ��ɫ������ֻ꣨����
  �� �� ֵ����
  ˵    ���������λ�÷Ƿ����򲻸ı�coordinate[]��ֵ
***************************************************************************/
void print_keyboard_info(const int line, const char coordinate[])
{
	cct_gotoxy(0, 4 * line + 3);  /*���ݲ��������ƶ����λ��*/
	cout << "[��ǰ����] ";

	/*����ԭ�����ݣ����������*/
	int X, Y;
	cct_getxy(X, Y);
	for (int i = 0; i < 100; i++)
		cout << ' ';

	cct_gotoxy(X, Y);
	cout << coordinate[0] << "��" << coordinate[1] << "��";
}