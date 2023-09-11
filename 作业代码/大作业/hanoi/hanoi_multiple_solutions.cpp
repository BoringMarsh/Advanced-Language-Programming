/*2151294 ��11 ����*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include<conio.h>
#include<Windows.h>
#include"cmd_console_tools.h"
#include"hanoi.h"
using namespace std;

/*�����õ�һ��ȫ�ֱ���*/
static int __stepnumber = 0;

/*��־�ƶ���ʱʱ���ı���*/
static int __delay_time;

/*�����������ӵ�һ��ȫ�ֶ�ά���飬��TOWER[0]ΪA����TOWER[1]ΪB����TOWER[2]ΪC��*/
int TOWER[3][PLATE_NUM_LIMIT];

/*��������ջ��ָ���һ��ȫ��һά���飬��MARK[0]ΪA��ջ��ָ�룬MARK[1]ΪB��ջ��ָ�룬MARK[2]ΪC��ջ��ָ��*/
int MARK[3];

/* ----------------------------------------------------------------------------------

     ���ļ����ܣ�
	1����ű� hanoi_main.cpp �и��ݲ˵�����ֵ���õĸ��˵����Ӧ��ִ�к���

     ���ļ�Ҫ��
	1�����������ⲿȫ�ֱ�����const��#define�������Ʒ�Χ�ڣ�
	2�������徲̬ȫ�ֱ�����������Ҫ��������Ҫ�����ĵ���ʾ��ȫ�ֱ�����ʹ��׼���ǣ����á����á��ܲ��þ������ã�
	3����̬�ֲ����������������ƣ���ʹ��׼��Ҳ�ǣ����á����á��ܲ��þ�������
	4���������ϵͳͷ�ļ����Զ���ͷ�ļ��������ռ��

   ----------------------------------------------------------------------------------- */

/***************************************************************************
  �������ƣ�hanoi
  ��    �ܣ���ӡ��ŵ�����ƶ�
  ���������int number_of_plates����������
			char source_tower����ʼ�����
			char temporary_tower���м������
			char destination_tower��Ŀ�������
			const int menu���˵���������ֵ��ֻ����
  �� �� ֵ����
  ˵    ����1��������������act()������ÿһ���ƶ�ʱ������ж�
            2��������Ϊ14��
***************************************************************************/
void hanoi(int number_of_plates, char source_tower, char temporary_tower, char destination_tower, const int menu)
{
	if (number_of_plates == 1) {/*����ŵ������Ϊ1�������̴���ʼ��ֱ������Ŀ����*/
		__stepnumber++;
		hanoi_act(number_of_plates, source_tower, destination_tower, menu);
	}

	else {  /*����ŵ��������Ϊ1*/
		hanoi(number_of_plates - 1, source_tower, destination_tower, temporary_tower, menu);  /*��n-1�����������м���*/
		__stepnumber++;  /*��������*/
		hanoi_act(number_of_plates, source_tower, destination_tower, menu);  /*����n������ֱ������Ŀ����*/
		hanoi(number_of_plates - 1, temporary_tower, source_tower, destination_tower, menu);  /*������n-1����������Ŀ����*/
	}
}

/***************************************************************************
  �������ƣ�hanoi_act
  ��    �ܣ��ۺ�������Ϣ�����������ŵݹ麯��ÿһ�����ж�
  ���������int number_of_plates����������
			char source_tower����ʼ�����
			char destination_tower��Ŀ�������
			const int menu���˵���������ֵ��ֻ����
  �� �� ֵ����
  ˵    ����1���ú������ݲ˵���������ֵ��ѡ����ò�ͬ���������������ŵݹ麯��ÿһ�����ж�
            2���ú���Ϊ17��
***************************************************************************/
void hanoi_act(int number_of_plates, char source_tower, char destination_tower, const int menu)
{
	hanoi_act_info(number_of_plates, source_tower, destination_tower, menu);    /*1�����ÿһ����������Ϣ*/
	hanoi_act_array(number_of_plates, source_tower, destination_tower, menu);  /*2����������в���*/

	/*3���˵���7��8��ͼ�����+�ٴθı�����ֵ*/
	/*ע���˵���7ֻ�����һ�����ƶ�*/
	if ((menu == 7 && __stepnumber == 1) || menu == 8) {
		console_show_move(number_of_plates, source_tower, destination_tower, menu);
		array_move_plates(source_tower, destination_tower);
	}

	/*4���˵���4��8��ÿһ�������ͣ����ʱ*/
	if (menu == 4 || menu == 8) {
		pause(__delay_time);  /*ÿһ�������ͣ����ʱ*/
	}
}

/***************************************************************************
  �������ƣ�hanoi_act_info
  ��    �ܣ�act����̨��������ӡÿһ����������Ϣ
  ���������int number_of_plates����������
			char source_tower����ʼ�����
			char destination_tower��Ŀ�������
			const int menu���˵���������ֵ��ֻ����
  �� �� ֵ����
  ˵    �����ú���Ϊ16��
***************************************************************************/
void hanoi_act_info(int number_of_plates, char source_tower, char destination_tower, const int menu)
{
	/*�˵���1����ӡÿһ���Ľ�*/
	if (menu == 1)
		cout << number_of_plates << "# " << source_tower << "---->" << destination_tower << endl;

	/*�˵���2��3����ӡÿһ���Ĳ���+��*/
	else if (menu == 2 || menu == 3) {
		cout << "��" << setw(4) << __stepnumber << " ��(" << setw(2) << number_of_plates << "#: "
			<< source_tower << "-->" << destination_tower << ")";

		/*���˵���Ϊ2��ֱ���ڴ˻���*/
		if (menu == 2)
			cout << endl;
	}
}

/***************************************************************************
  �������ƣ�hanoi_act_array
  ��    �ܣ�act����̨��������������в���
  ���������int number_of_plates����������
			char source_tower����ʼ�����
			char destination_tower��Ŀ�������
			const int menu���˵���������ֵ��ֻ����
  �� �� ֵ����
  ˵    �����ú���Ϊ16��
***************************************************************************/
void hanoi_act_array(int number_of_plates, char source_tower, char destination_tower, const int menu)
{
	/*�˵���3��4��8���ı�����ֵ+��ʽ��ӡ�ڲ�����*/
	if (menu == 3 || menu == 4 || menu == 8) {
		array_move_plates(source_tower, destination_tower);
		array_print_tower(number_of_plates, source_tower, destination_tower, menu);
	}

	/*�˵���4��8���ı���ֵλ��*/
	if (menu == 4 || menu == 8)
		array_show_move(source_tower, destination_tower, menu);

	/*�˵���8������һ������ֵ��λ���Ա���һ��ͼ�λ������ʹ���ƶ�ǰ���ڲ�����ֵ*/
	if (menu == 8)
		array_move_plates(destination_tower, source_tower);
}

/***************************************************************************
  �������ƣ�array_tower_initialize
  ��    �ܣ����������鸳��ֵ����ɳ�ʼ��
  ���������const int number_of_plates�����ӵ�������ֻ����
			const char src����ʼ�����ţ�ֻ����
  �� �� ֵ����
  ˵    ����1���˺�����������������ʼ�����ţ�����ʼ���Ķ�ӦԪ�ظ���1-n��ֵ
			2���˺���Ϊ20��
***************************************************************************/
void array_tower_initialize(const int number_of_plates, const char source_tower)
{
	int i, j;

	/*������Ԫ�ظ���ֵ*/
	for (i = 0; i < 3; i++) {
		for (j = 0; j < PLATE_NUM_LIMIT; j++)
			TOWER[i][j] = 0;
	}

	/*������ʼ���Ĵ��ţ�����ʼ���Ķ�ӦԪ�ظ���1-n��ֵ�������ʼʱ�ĸ�������*/
	for (i = 0; i < number_of_plates; i++)
		TOWER[source_tower - 'A'][i] = number_of_plates - i;

	/*��ʼ��ջ��ָ��ĳ�ʼ��*/
	for (i = 0; i < 3; i++)
		MARK[i] = 0;

	MARK[source_tower - 'A'] = number_of_plates;
}

/***************************************************************************
  �������ƣ�array_print_base
  ��    �ܣ����������״���������������Լ��������ӵ�λ�ã����ڲ������ֵ
  ���������const int number_of_plates������������ֻ����
			const char source_tower����ʼ����ţ�ֻ����
			const int menu���˵���������ֵ��ֻ����
  �� �� ֵ����
  ˵    ����1��������������pause()�������˼�ϵ�
            2��������Ϊ33��
***************************************************************************/
void array_print_base(const int number_of_plates, const char source_tower, const int menu)
{
	int i, BASE_Y;  /*�������������BASE_Y���������*/

	if (menu == 4)
		BASE_Y = PLATE_NUM_LIMIT + 2;

	else
		BASE_Y = CONSOLE_BASE_Y + PLATE_NUM_LIMIT + 2;

	/*ѭ����������������ӵ���ĸ*/
	for (i = 0; i < 3; i++) {
		cct_gotoxy(ARRAY_BASE_X + (ARRAY_DISTANCE + 1) * i, BASE_Y + 1);
		cout << char('A' + i);
	}

	/*ѭ�����һ�ŵȺţ�ʹ��������������*/
	cct_gotoxy(ARRAY_BASE_X - 2, BASE_Y);
	for (i = 0; i < 6 + 2 * ARRAY_DISTANCE + 1; i++)
		cout << "=";

	/*��ָ����λ�ã��������ÿ�������ϵ����������ƶ�ǰ�����ƶ���ָ��λ��*/
	cct_gotoxy((ARRAY_DISTANCE + 1) * (source_tower - 'A') + ARRAY_BASE_X - 1, BASE_Y - 1);

	for (i = 0; i < PLATE_NUM_LIMIT; i++) {
		if (TOWER[source_tower - 'A'][i])
			cout << setw(2) << TOWER[source_tower - 'A'][i];
		
		cct_gotoxy((ARRAY_DISTANCE + 1) * (source_tower - 'A') + ARRAY_BASE_X - 1, BASE_Y - i - 2);
	}

	cct_gotoxy((ARRAY_DISTANCE + 1) * (source_tower - 'A') + ARRAY_BASE_X + 1, BASE_Y - number_of_plates);
}

/***************************************************************************
  �������ƣ�array_show_move
  ��    �ܣ�����������ڣ��������ӵ��ƶ����ƶ�����
  ���������const char source_tower����ʼ����ţ�ֻ����
            const char destination_tower��Ŀ������ţ�ֻ����
			const int menu���˵���������ֵ��ֻ����
  �� �� ֵ����
  ˵    ����1��������������pause()�������˼�ϵ�
            2��������Ϊ19��
***************************************************************************/
void array_show_move(const char source_tower, const char destination_tower, const int menu)
{
	int BASE_Y;  /*�������������BASE_Y���������*/

	/*���˵���������ֵ��������ֵ*/
	if (menu == 4)
		BASE_Y = PLATE_NUM_LIMIT + 2;

	else
		BASE_Y = CONSOLE_BASE_Y + PLATE_NUM_LIMIT + 2;

	/*����ԭ������*/
	cct_gotoxy((ARRAY_DISTANCE + 1) * (source_tower - 'A') + ARRAY_BASE_X + 1, BASE_Y - 1 - MARK[source_tower - 'A']);
	cout << "\010\010\040\040";

	/*�����������*/
	cct_gotoxy((ARRAY_DISTANCE + 1) * (destination_tower - 'A') + ARRAY_BASE_X - 1, BASE_Y - MARK[destination_tower - 'A']);
	cout << setw(2) << TOWER[destination_tower - 'A'][MARK[destination_tower - 'A'] - 1];
}

/***************************************************************************
  �������ƣ�array_print_tower
  ��    �ܣ����ÿ�������ϵ������������
  ���������const int menu���˵���������ֵ
  �� �� ֵ����
  ˵    ����1���������ӣ�ֵ��Ϊ�㣩����������������ӣ�ֵΪ�㣩���������ֻ���ո�
			2������i��ֵ�ж�Ӧ������ĸ�����
			3��������Ϊ44��
***************************************************************************/
void array_print_tower(const int number_of_plates, const char source_tower, const char destination_tower, const int menu)
{
	int i, j, y = 0;

	if (menu == 4)
		y = PLATE_NUM_LIMIT + 7;  /*�˵���4��λ��*/

	else if (menu == 8 || menu == 9)
		y = CONSOLE_BASE_Y + PLATE_NUM_LIMIT + 7;  /*�˵���8���˵���9��λ��*/

	if (menu != 3) {  /*�˵���3����Ҫ���������*/
		cct_gotoxy(SCREEN_WIDTH - 1, y);

		/*����ԭ������*/
		for (i = 0; i < SCREEN_WIDTH; i++)
			cout << '\010';
		for (i = 0; i < SCREEN_WIDTH; i++)
			cout << '\040';

		/*���ݲ������������ʾ����*/
		cct_gotoxy(0, y);

		if (__stepnumber)  /*�Ѿ���ʼ�ƶ���������Ϊ�㣬����ƶ����*/
			cout << "��" << setw(4) << __stepnumber << "��(" << number_of_plates << "#: " << source_tower << "-->" << destination_tower << ") ";

		else  /*��δ�ƶ�������Ϊ�㣬�����ʼ���*/
			cout << "��ʼ: ";
	}

	/*��ʾ�ڲ�����ֵ*/
	for (i = 0; i < 3; i++) {
		cout << ' ' << char('A' + i) << ":";

		for (j = 0; j < PLATE_NUM_LIMIT; j++) {
			if (TOWER[i][j] != 0)
				cout << setw(2) << TOWER[i][j];

			else
				cout << "  ";
		}
	}

	cout << endl;
}

/***************************************************************************
  �������ƣ�array_move_plates
  ��    �ܣ�ͨ���ı������Լ�ջ��ָ���ֵ���ﵽ�ƶ����ӵ�Ч��
  ���������const char source_tower����ʼ����ţ�ֻ����
            const char destination_tower��Ŀ������ţ�ֻ����
  �� �� ֵ����
  ˵    ����1��ÿ���ƶ����裺��ջջ��ָ���½�����ֵ����ջԪ�أ���ջջ��ָ����������ջջ��Ԫ�ظ�0����������������
			2��������Ϊ5��
***************************************************************************/
void array_move_plates(const char source_tower, const char destination_tower)
{
	TOWER[destination_tower - 'A'][MARK[destination_tower - 'A']++] = TOWER[source_tower - 'A'][--MARK[source_tower - 'A']];
	TOWER[source_tower - 'A'][MARK[source_tower - 'A']] = 0;
}

/***************************************************************************
  �������ƣ�console_print_base
  ��    �ܣ�ͼ�λ������������
  �����������
  �� �� ֵ����
  ˵    ����1���������ò����������Ӹ߶ȡ���ȡ�λ�õ�
			2��������Ϊ26��
***************************************************************************/
void console_print_base()
{
	const int bg_color = COLOR_HYELLOW;	//����Ϊ����ɫ
	const int fg_color = COLOR_HBLUE;	//ǰ��Ϊ����ɫ
	int i, j;  /*��������*/

	/*���λ�ó�ʼ��*/
	cct_gotoxy(CONSOLE_BASE_X, CONSOLE_BASE_Y);

	/*�������*/
	for (i = 0; i < 3; i++) {
		Sleep(50);
		cct_showch(CONSOLE_BASE_X + i * (TOWER_WIDTH + TOWER_DISTANCE), CONSOLE_BASE_Y, ' ', bg_color, fg_color, TOWER_WIDTH);
	}

	/*�������*/
	for (i = 0; i < TOWER_HEIGHT; i++) {
		for (j = 0; j < 3; j++) {
			Sleep(50);
			cct_showch(CONSOLE_BASE_X + (TOWER_WIDTH - 1) / 2 + j * (TOWER_WIDTH + TOWER_DISTANCE), CONSOLE_BASE_Y - i - 1, ' ', bg_color, fg_color, 1);
		}
	}

	/*�����ɺ����ɫ����*/
	cct_setcolor();
}

/***************************************************************************
  �������ƣ�console_print_plates
  ��    �ܣ�����������������ʼ����ţ�ͼ�λ������������
  ���������const int number_of_plates������������ֻ����
            const char source_tower����ʼ����ţ�ֻ����
  �� �� ֵ����
  ˵    ����1�����������ݲ������Ƶ�����λ�ã������������
			2��������Ϊ26��
***************************************************************************/
void console_print_plates(const int number_of_plates, const char source_tower)
{
	const int mid = CONSOLE_BASE_X + (TOWER_WIDTH - 1) / 2 + (TOWER_WIDTH + TOWER_DISTANCE) * (source_tower - 'A'); /*ÿ�������м��λ��*/
	int X, Y;                /*�����ꡢ������*/
	int bg_color, fg_color;  /*����ɫ������ɫ*/
	int LENGTH;              /*���ӳ���*/
	int i = 0;               /*��������*/

	/*�������*/
	for (i = 0; i < number_of_plates; i++) {

		/*���ݲ�����ȷ������������ֵ*/
		X = mid - number_of_plates + i;
		Y = CONSOLE_BASE_Y - i - 1;
		bg_color = number_of_plates - i;
		fg_color = 7;
		LENGTH = 2 * number_of_plates + 1 - 2 * i;

		/*��ʱ�����*/
		Sleep(30);
		cct_showch(X, Y, ' ', bg_color, fg_color, LENGTH);
	}

	/*�����ɺ����ɫ����*/
	cct_setcolor();
}

/***************************************************************************
  �������ƣ�console_show_move
  ��    �ܣ�����ÿһ���ƶ���Ϣ�Ͳ˵���������ֵ����ʾ�����ƶ��Ķ���
  ���������const int number_of_plates������������ֻ����
			const char source_tower����ʼ����ţ�ֻ����
			const char destination_tower��Ŀ������ţ�ֻ����
			const int menu���˵���������ֵ��ֻ����
  �� �� ֵ����
  ˵    ����1�����������ݲ������Ƽ�ϵ����ʱ���ж�
			2���������൱���ƶ����ܿ�̨�������˶����ʾ�����ƶ������ĺ���
			3��Ϊ��ʹ�������ݣ�����һ���ƶ�������Ĳ����ڱ���������ȡ��
			4��������Ϊ40��
***************************************************************************/
void console_show_move(const int number_of_plates, const char source_tower, const char destination_tower, const int menu)
{
	const int bg_color = number_of_plates;        /*����ɫ���������ӱ����ȡ����֤�ƶ����������Ӳ���ɫ��*/
	const int fg_color = COLOR_WHITE;             /*����ɫ*/
	const int LENGTH = 2 * number_of_plates + 1;  /*���ӳ���*/

	/*��ʼ���м�λ��*/
	const int src_mid = CONSOLE_BASE_X + (TOWER_WIDTH - 1) / 2 + (TOWER_WIDTH + TOWER_DISTANCE) * (source_tower - 'A');
	/*Ŀ�����м�λ��*/
	const int dst_mid = CONSOLE_BASE_X + (TOWER_WIDTH - 1) / 2 + (TOWER_WIDTH + TOWER_DISTANCE) * (destination_tower - 'A');

	const int START_X = src_mid - TOWER[source_tower - 'A'][MARK[source_tower - 'A'] - 1];  /*��ʼ������*/
	const int START_Y = CONSOLE_BASE_Y - MARK[source_tower - 'A'];                          /*��ʼ������*/
	const int END_X = dst_mid - number_of_plates;                          /*���պ�����*/
	const int END_Y = CONSOLE_BASE_Y - MARK[destination_tower - 'A'] - 1;  /*����������*/
	int time = 0;  /*��ʱ����*/

	/*ȡ��ʱ��������Ϊ�˵���7��8�еĵ�����ʾ����ʱ100����Ϊ�˵���8�е�������ʾ����ʱdelay_time����Ϊ�˵���9����ʱ1�����˲��Ч��*/
	if (menu == 7 || (menu == 8 && __delay_time == 0))
		time = 100;
	else if (menu == 8 && __delay_time != 0)
		time = __delay_time;
	else if (menu == 9)
		time = 1;

	/*�����ƶ�*/
	console_show_move_up(START_X, START_Y, bg_color, fg_color, src_mid, LENGTH, time);

	/*�����ƶ�*/
	if (destination_tower < source_tower)
		console_show_move_left(START_X, END_X, bg_color, fg_color, LENGTH, time);
	else
		console_show_move_right(START_X, END_X, bg_color, fg_color, LENGTH, time);

	/*�����ƶ�*/
	console_show_move_down(END_X, END_Y, bg_color, fg_color, dst_mid, LENGTH, time);

	/*�ƶ���ɺ����ɫ����*/
	cct_setcolor();
}

/***************************************************************************
  �������ƣ�console_show_move_up
  ��    �ܣ������ܿ�̨������ÿһ���ƶ���Ϣ����ʾ���������ƶ��Ķ���
  ���������int START_X����ʼ������
			int START_Y����ʼ������
			int bg_color������ɫ
			int fg_color������ɫ
			int src_mid����ʼ���м�λ��
			int LENGTH�����ӳ���
			int time����ʱ����
  �� �� ֵ����
  ˵    ����1�����������ݲ������Ƽ�ϵ����ʱ���ж�
			2���������������ܿ�̨�����Ĳ������������ε������ƶ�
			3��������Ϊ20��
***************************************************************************/
void console_show_move_up(int START_X, int START_Y, int bg_color, int fg_color, int src_mid, int LENGTH, int time)
{
	int Y;  /*��ʾ�����б䶯�ĵ�ǰ������*/

	for (Y = START_Y; Y >= 1; Y--) {
		cct_showch(START_X, Y, ' ', bg_color, fg_color, LENGTH);

		/*��������ʾ�ٶȲ�Ϊ5����������ʱ*/
		if (time != 1)
			Sleep(time);

		/*������ߵ�֮ǰ���ñ�׼ɫ����ԭ�����ݣ���ɶ���Ч��*/
		if (Y > 1)
			cct_showch(START_X, Y, ' ', COLOR_BLACK, COLOR_WHITE, LENGTH);

		/*��δ�뿪���ӣ������������м�λ��������ʾ���ӣ�����ᱻ��һ�������*/
		if (Y > TOWER_TOP)
			cct_showch(src_mid, Y, ' ', COLOR_HYELLOW, COLOR_WHITE, 1);
	}
}

/***************************************************************************
  �������ƣ�console_show_move_down
  ��    �ܣ������ܿ�̨������ÿһ���ƶ���Ϣ����ʾ���������ƶ��Ķ���
  ���������int END_X�����պ�����
			int END_Y������������
			int bg_color������ɫ
			int fg_color������ɫ
			int dst_mid��Ŀ�����м�λ��
			int LENGTH�����ӳ���
			int time����ʱ����
  �� �� ֵ����
  ˵    ����1�����������ݲ������Ƽ�ϵ����ʱ���ж�
			2���������������ܿ�̨�����Ĳ������������ε������ƶ�
			3��������Ϊ20��
***************************************************************************/
void console_show_move_down(int END_X, int END_Y, int bg_color, int fg_color, int dst_mid, int LENGTH, int time)
{
	int Y;  /*��ʾ�����б䶯�ĵ�ǰ������*/

	for (Y = 1; Y <= END_Y; Y++) {
		cct_showch(END_X, Y, ' ', bg_color, fg_color, LENGTH);

		/*��������ʾ�ٶȲ�Ϊ5����������ʱ*/
		if (time != 1)
			Sleep(time);

		/*������͵�֮ǰ���ñ�׼ɫ����ԭ�����ݣ���ɶ���Ч��*/
		if (Y < END_Y)
			cct_showch(END_X, Y, ' ', COLOR_BLACK, COLOR_WHITE, LENGTH);

		/*���������ӣ������������м�λ��������ʾ���ӣ�����ᱻ��һ�������*/
		if (Y > TOWER_TOP && Y < END_Y)
			cct_showch(dst_mid, Y, ' ', COLOR_HYELLOW, COLOR_WHITE, 1);
	}
}

/***************************************************************************
  �������ƣ�console_show_move_left
  ��    �ܣ������ܿ�̨������ÿһ���ƶ���Ϣ����ʾ���������ƶ��Ķ���
  ���������int START_X����ʼ������
            int END_X�����պ�����
			int bg_color������ɫ
			int fg_color������ɫ
			int LENGTH�����ӳ���
			int time����ʱ����
  �� �� ֵ����
  ˵    ����1�����������ݲ������Ƽ�ϵ����ʱ���ж�
			2���������������ܿ�̨�����Ĳ������������ε������ƶ�
			3��������Ϊ16��
***************************************************************************/
void console_show_move_left(int START_X, int END_X, int bg_color, int fg_color, int LENGTH, int time)
{
	int X;  /*��ʾ�����б䶯�ĵ�ǰ������*/

	for (X = START_X; X >= END_X; X--) {
		cct_showch(X, 1, ' ', bg_color, fg_color, LENGTH);

		/*��������ʾ�ٶȲ�Ϊ5����������ʱ*/
		if (time != 1)
			Sleep(time);

		/*���������֮ǰ���ñ�׼ɫ����ԭ�����ݣ���ɶ���Ч��*/
		if (X > END_X)
			cct_showch(X, 1, ' ', COLOR_BLACK, COLOR_WHITE, LENGTH);
	}
}

/***************************************************************************
  �������ƣ�console_show_move_right
  ��    �ܣ������ܿ�̨������ÿһ���ƶ���Ϣ����ʾ���������ƶ��Ķ���
  ���������int START_X����ʼ������
			int END_X�����պ�����
			int bg_color������ɫ
			int fg_color������ɫ
			int LENGTH�����ӳ���
			int time����ʱ����
  �� �� ֵ����
  ˵    ����1�����������ݲ������Ƽ�ϵ����ʱ���ж�
			2���������������ܿ�̨�����Ĳ������������ε������ƶ�
			3��������Ϊ16��
***************************************************************************/
void console_show_move_right(int START_X, int END_X, int bg_color, int fg_color, int LENGTH, int time)
{
	int X;  /*��ʾ�����б䶯�ĵ�ǰ������*/

	for (X = START_X; X <= END_X; X++) {
		cct_showch(X, 1, ' ', bg_color, fg_color, LENGTH);

		/*��������ʾ�ٶȲ�Ϊ5����������ʱ*/
		if (time != 1)
			Sleep(time);

		/*�������Ҳ�֮ǰ���ñ�׼ɫ����ԭ�����ݣ���ɶ���Ч��*/
		if (X < END_X)
			cct_showch(X, 1, ' ', COLOR_BLACK, COLOR_WHITE, LENGTH);
	}
}

/***************************************************************************
  �������ƣ�game_command_center
  ��    �ܣ�����ÿһ������ָ��ƶ����ӣ��ﵽ��Ϸ��Ч��
  ���������const int total_number_of_plates������������ֻ����
			const char destination_tower��Ŀ������ţ�ֻ����
			const int menu���˵���������ֵ��ֻ����
  �� �� ֵ����
  ˵    ����1���������൱����Ϸ���ܿ�̨�������˶����Ϸ�йصĺ���
			2��Ϊ��ʹ�������ݣ�����һ���ƶ�������Ĳ����ڱ���������ȡ��
			3��������Ϊ48��
***************************************************************************/
void game_command_center(const int total_number_of_plates, const char destination_tower, const int menu)
{
	cct_setcursor(CURSOR_VISIBLE_NORMAL);  /*��ʾ���*/
	cct_gotoxy(0, GAME_TIP_Y);    /*�ƶ������ָ��λ��*/
	cout << "�������ƶ�������(������ʽ��AC=A���˵������ƶ���C��Q=�˳�) ��";  /*�����ʾ��ı���ʾ�ﳤ��ʱ����ͬ���ı�#define TIP_LENGTH*/

	while (1) {
		int i = 0;  /*����������ÿһ��ѭ����������*/
		char src = 0, dst = 0, c;  /*��ʼ����ţ�ÿһ��ѭ���������㣩��Ŀ������ţ�ÿһ��ѭ���������㣩����ȡ�ַ�*/

		/*1������ָ��*/
		while (1) {
			c = getchar();  /*�����ȡ�ַ�*/

			if (c == '\n' || c == 'q' || c == 'Q')  /*���л��з����˳�ָ���������*/
				break;

			if (i == 0)  /*������δ��������һ���ַ�����src*/
				src = c;

			if (i == 1)  /*������δ�������ڶ����ַ�����dst*/
				dst = c;

			i++;  /*ÿ����һ���ַ�����������������ͳ��������ַ���*/
		}

		/*2����cΪ�˳�ָ������ʾ�ﲢ������Ϸ*/
		if (c == 'q' || c == 'Q') {
			cout << "��Ϸ��ֹ!!!!!";
			break;
		}

		/*3�����պ������������ȵ��ַ���������Сд���ж��Ƿ�����ƶ����ƶ�����*/
		if (i == 2 && src != dst) {
			if (src >= 'a' && src <= 'c')
				src = src - 'a' + 'A';
			if (dst >= 'a' && dst <= 'c')
				dst = dst - 'a' + 'A';

			game_get_info_and_move(src, dst, menu);
		}

		/*4����1�����Ѿ���������λ�ã����ж���Ϸ����*/
		if (TOWER[destination_tower - 'A'][total_number_of_plates - 1] == 1) {
			cct_gotoxy(0, GAME_TIP_Y + 1);
			cout << "��Ϸ����!!!!!";
			break;
		}

		/*5������ָ����󣬻�����ÿ���һ���ƶ������ԭ��ָ�λ�ÿ��󣬲�������Ϸ�����������ʾʱ�����ԭ��ָ�*/
		else
			game_clear_input();
	}
}

/***************************************************************************
  �������ƣ�game_clear_input
  ��    �ܣ������Ϸ��ԭ�е�����ָ��
  �����������
  �� �� ֵ����
  ˵    ����1��������ֻ���������ʾ��ͬһ�е�ָ��������60���ַ�
			2��������Ϊ11��
***************************************************************************/
void game_clear_input()
{
	int j;

	cct_gotoxy(TIP_LENGTH, GAME_TIP_Y);

	for (j = 0; j < 60; j++)
		cout << '\040';

	cct_gotoxy(TIP_LENGTH, GAME_TIP_Y);
}

/***************************************************************************
  �������ƣ�game_get_info_and_move
  ��    �ܣ���������ָ�ȡ�ø�����Ϣ�����ж��Ƿ��ƶ�
  ���������const char source_tower����ʼ����ţ�ֻ����
            const char destination_tower��Ŀ������ţ�ֻ����
			const int menu���˵���������ֵ��ֻ����
  �� �� ֵ����
  ˵    ����1����һ�����漰���������ȡֵ���жϣ�����Ȼ���ܱȽ����ң�����дΪһ������
			2��������Ϊ22��
***************************************************************************/
void game_get_info_and_move(const char source_tower, const char destination_tower, const int menu)
{
	/*�������ӱ�ţ�ȡջ��Ԫ�ص�ֵ����Ϊ�㣬����Ϊ����*/
	int number_of_src = game_get_plate_num(source_tower);
	int number_of_dst = game_get_plate_num(destination_tower);

	/*ֻ�е�����ջ��Ԫ��ֵ����Ϊ��������ȷ����ʱ�򣬲Ž�����һ���ж�*/
	if (number_of_src >= 0 && number_of_dst >= 0) {

		/*��ʼ��Ϊ�յ����*/
		if (TOWER[source_tower - 'A'][0] == 0)
			game_err(EmptySourceTower);

		/*����ѹС�̵����*/
		else if (number_of_src > number_of_dst && number_of_dst != 0)
			game_err(BigOnSmall);

		/*׼�������������ƶ������*/
		else
			game_ok_move(number_of_src, source_tower, destination_tower, menu);
	}
}

/***************************************************************************
  �������ƣ�game_get_plate_num
  ��    �ܣ�������������ӱ�ţ�ȡ��ջ�����ӵı��
  ���������const char tower�����ӱ�ţ�ֻ����
  �� �� ֵ������
  ˵    ����1��������Ϊ�գ������㣻������ַ����󣬷��ظ���
			2��������Ϊ21��
***************************************************************************/
int game_get_plate_num(const char tower)
{
	/*���ӱ�ŷ�Χ��ȷ*/
	if (tower >= 'A' && tower <= 'C') {

		/*ʹ��ֻ���ַ��������ղ���tower������������ʾ*/
		const char Tower = tower;

		/*��ջ��Ԫ�ز�Ϊ�㣬˵��������Ϊ�գ�����ջ��Ԫ�ص�ֵ*/
		if (TOWER[Tower - 'A'][0])
			return TOWER[Tower - 'A'][MARK[Tower - 'A'] - 1];

		/*��ջ��Ԫ��Ϊ�㣬˵������Ϊ�գ�������*/
		else
			return 0;
	}

	/*�����ӱ�Ų���ȷ�����ظ���*/
	else
		return -1;
}

/***************************************************************************
  �������ƣ�game_err
  ��    �ܣ��ƶ���������ʱ�����������ʾ
  ���������const int err_info��������Ϣ��ֻ����
  �� �� ֵ����
  ˵    ����1�����������ݴ�����Ϣ��ӡ��ʾ��
            2��������������ʾ��ĳ��ȴ�ӡ��������Ŀո񣬴ﵽ���ǵ�Ч��
			3��������Ϊ23��
***************************************************************************/
void game_err(const int err_info)
{
	unsigned int i;  /*��������*/
	char c[128];     /*������ʾ����ַ�����*/

	/*���ݴ�����Ϣ�ƶ���ʾ��*/
	if (err_info == 1)
		strcpy(c, "Դ��Ϊ��!");
	else if (err_info == 2)
		strcpy(c, "����ѹС�̣��Ƿ��ƶ�!");

	/*�����ʾ�ﲢ��ͣ*/
	cout << c;
	Sleep(1000);

	/*������ʾ�ﲢʹ��긴λ*/
	cct_gotoxy(0, GAME_TIP_Y + 1);

	for (i = 0; i < strlen(c); i++)
		cout << '\040';

	cct_gotoxy(TIP_LENGTH, GAME_TIP_Y);
}

/***************************************************************************
  �������ƣ�game_ok_move
  ��    �ܣ��������ؼ��飬�ж������ƶ����ƶ�����
  ���������const in number_of_plates�����ӱ�ţ�ֻ����
            const char source_tower����ʼ����ţ�ֻ����
			const char destination_tower��Ŀ������ţ�ֻ����
			const int menu���˵���������ֵ��ֻ����
  �� �� ֵ����
  ˵    ����1��������������������к������ﵽ�ƶ����ӵ�Ч��
			2��������Ϊ11��
***************************************************************************/
void game_ok_move(const int number_of_plates, const char source_tower, const char destination_tower, const int menu)
{
	__stepnumber++;  /*��������*/
	array_move_plates(source_tower, destination_tower);  /*�ı�����ֵ���ڲ�����ﵽ�ƶ����ӵ�Ч��*/
	array_print_tower(number_of_plates, source_tower, destination_tower, menu);  /*��ʽ��ӡ�ڲ�����*/
	array_show_move(source_tower, destination_tower, menu);  /*�ı���ֵλ�ã���������ﵽ�ƶ����ӵ�Ч��*/

	array_move_plates(destination_tower, source_tower);  /*����һ������ֵ��λ���Ա���һ��ͼ�λ������ʹ���ƶ�ǰ���ڲ�����ֵ*/
	console_show_move(number_of_plates, source_tower, destination_tower, menu);  /*�ı�����λ�ã�ͼ������ﵽ�ƶ����ӵ�Ч��*/
	array_move_plates(source_tower, destination_tower);  /*�ı�����ֵ���ڲ�����ﵽ�ƶ����ӵ�Ч��*/
}

/***************************************************************************
  �������ƣ�input_info
  ��    �ܣ�ͨ����ȷ�Դ�������������Ĳ���
  ���������int* plate_number����������
			char* src_tower����ʼ�����
			char* dst_tower��Ŀ�������
			int* delay_time_set���ƶ��ٶȱ��
			const int menu���˵���������ֵ��ֻ����
  �� �� ֵ����
  ˵    ����1�������������˸�����ȷ�Դ�����
			2�����в�����Ϊָ�����ͣ����Ըı���ʵ��ֵ
			3��������Ϊ11��
***************************************************************************/
void input_info(int* number_of_plates, char* source_tower, char* destination_tower, int* delay_time_set, const int menu)
{
	if (menu != 5) {  /*�˵���5����Ҫ������Ϣ*/
		input_number_of_plates(number_of_plates);
		input_source_tower(source_tower);
		input_destination_tower(destination_tower, source_tower);
	}

	if (menu == 4 || menu == 8)  /*�˵���4�Ͳ˵���8��Ҫ������ʱ����*/
		input_delay(delay_time_set);
}

/***************************************************************************
  �������ƣ�input_number_of_plates
  ��    �ܣ�ͨ����ȷ�Դ������뺺ŵ���Ĳ���
  ���������int* number_of_plates����������
  �� �� ֵ����
  ˵    ����1������Ϊָ�����ͣ����Ըı�ʵ��ֵ
			2��������Ϊ28��
***************************************************************************/
void input_number_of_plates(int* number_of_plates)
{
	int n;

	while (1) {
		cout << "�����뺺ŵ���Ĳ���(1-" << PLATE_NUM_LIMIT << ")��" << endl;
		cin >> n;
		if (n >= 1 && n <= PLATE_NUM_LIMIT && cin.good() == 1) {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			break;
		}

		/*ֻʣ�Ƿ����룬����ֵ�����ͷ�Χ�Ĵ���*/
		else if ((n < 1 || n > PLATE_NUM_LIMIT) && cin.good() == 0) {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}

		/*��ȡ״̬�����������û���Χʱ�Ĵ���*/
		else if ((n < 1 || n > PLATE_NUM_LIMIT) && cin.good() == 1) {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}
	}

	*number_of_plates = n;
}

/***************************************************************************
  �������ƣ�input_source_tower
  ��    �ܣ�ͨ����ȷ�Դ������������ʼ����ĸ��ASCII
  ���������char* source_tower����ʼ�����
  �� �� ֵ����
  ˵    ����1�����������д��Сд������ֵͳһΪ��Ӧ��д��ĸ��ASCII
			2������Ϊָ�����ͣ����Ըı�ʵ��ֵ
			3��������Ϊ33��
***************************************************************************/
void input_source_tower(char* source_tower)
{
	char src;
	while (1) {
		cout << "��������ʼ��(A-C)��" << endl;
		cin >> src;
		if (((src >= 'a' && src <= 'c') || (src >= 'A' && src <= 'C')) && cin.good() == 1) {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			break;
		}

		/*ֻʣ�Ƿ����룬����ֵ�����ͷ�Χ�Ĵ���*/
		else if (((src < 'a' || src > 'c') || (src < 'A' || src > 'C')) && cin.good() == 0) {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}

		/*��ȡ״̬�����������û���Χʱ�Ĵ���*/
		else if (((src < 'a' || src > 'c') || (src < 'A' || src > 'C')) && cin.good() == 1) {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}
	}

	if (src >= 'a' && src <= 'c') {
		*source_tower = src - 32;
	}

	else {
		*source_tower = src;
	}
}

/***************************************************************************
  �������ƣ�input_destination_tower
  ��    �ܣ�ͨ����ȷ�Դ����������Ŀ������ĸ��ASCII
  ���������char* destination_tower��Ŀ�������
            const char* source_tower����ʼ����ţ�ֻ����
  �� �� ֵ����
  ˵    ����1�����������д��Сд������ֵͳһΪ��Ӧ��д��ĸ��ASCII
			2���ú���ͨ���������*src_tower���ж�*dst_tower�����Ƿ����
			3������Ϊָ�����ͣ����Ըı�ʵ��ֵ����ֻ��������
			4��������Ϊ48��
***************************************************************************/
void input_destination_tower(char* destination_tower, const char* source_tower)
{
	char dst;
	while (1) {
		cout << "������Ŀ����(A-C)��" << endl;
		cin >> dst;
		if (((dst >= 'a' && dst <= 'c') || (dst >= 'A' && dst <= 'C')) && cin.good() == 1) {
			if (dst != *source_tower && dst != *source_tower + 32 && dst != *source_tower - 32) {
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				break;
			}

			/*dst��src���ʱ�Ĵ���*/
			else {

				/*Ϊ��ʹ��ʾ���е�dst���Ϊ��д����dst��ֵ���д���*/
				if (dst >= 'a' && dst <= 'c') {
					dst = dst - 32;
				}

				cout << "Ŀ����(" << dst << ")��������ʼ��(" << *source_tower << ")��ͬ" << endl;
				cin.clear();
				cin.ignore(INT_MAX, '\n');
			}
		}

		/*ֻʣ�Ƿ����룬����ֵ�����ͷ�Χ�Ĵ���*/
		else if (((dst < 'a' || dst > 'c') || (dst < 'A' || dst > 'C')) && cin.good() == 0) {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}

		/*��ȡ״̬�����������û���Χʱ�Ĵ���*/
		else if (((dst < 'a' || dst > 'c') || (dst < 'A' || dst > 'C')) && cin.good() == 1) {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}
	}

	if (dst >= 'a' && dst <= 'c') {
		*destination_tower = dst - 32;
	}

	else {
		*destination_tower = dst;
	}
}

/***************************************************************************
  �������ƣ�delay
  ��    �ܣ�ͨ����ȷ�Դ������벢����־��ʱʱ����ȫ�ֱ���delay_time��ֵ
  ���������int* delay_time_set���ƶ��ٶȱ��
  �� �� ֵ����
  ˵    ����1����dΪ�㣬�򷵻�0����d��Ϊ�㣬��ʱʱ���ļ��㷽��Ϊ1000�����ƶ��ٶȵĶ��η�
			2������Ϊָ�����ͣ����Ըı�ʵ��ֵ
			3��������Ϊ40��
***************************************************************************/
void input_delay(int* delay_time_set)
{
	int i;
	while (1) {
		cout << "�������ƶ��ٶ�(0-5: 0-���س�������ʾ 1-��ʱ� 5-��ʱ���)" << endl;
		cin >> i;
		if (i >= 0 && i <= 5 && cin.good() == 1) {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			break;
		}

		/*ֻʣ�Ƿ����룬����ֵ�����ͷ�Χ�Ĵ���*/
		else if (cin.good() == 0) {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}

		/*��ȡ״̬�����������û���Χʱ�Ĵ���*/
		else if ((i < 0 || i > 5) && cin.good() == 1) {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}
	}

	/*����i������ֵ����ȫ�ֱ���delay_time��ֵ*/
	if (i == 0)
		__delay_time = 0;

	else if (i >= 1 && i <= 3)
		__delay_time = 130 - 30 * i;

	else if (i == 4)
		__delay_time = 15;

	else if (i == 5)
		__delay_time = 1;

	*delay_time_set = i;
}

/***************************************************************************
  �������ƣ�pause
  ��    �ܣ��жϻ��ӻ�����Ľ���
  ���������const int delay_time_set���ƶ��ٶȱ�ţ�ֻ����
  �� �� ֵ����
  ˵    ����1��ֻ�в˵���4��8���õ��ú���
			2���˺��������ƶ��ٶ��Ƿ�Ϊ�㣬�����жϻ�����ʱ
			3���˺���Ϊ16��
***************************************************************************/
void pause(const int delay_time_set)
{
	int c;

	if (delay_time_set > 0 && delay_time_set != 5)
		Sleep(__delay_time);

	else {
		while (1) {
			c = _getch();

			if (c == '\r')
				break;
		}
	}
}

/***************************************************************************
  �������ƣ�reset
  ��    �ܣ�����������һ�κ��������в�������ʹ������ͣ
  ���������const int menu���˵���������ֵ��ֻ����
  �� �� ֵ����
  ˵    ����1�����ݲ˵���������ֵ�������Ƿ��ƶ������������ʾ��
			2������stepnumber��delay_time�Ⱦ�̬ȫ�ֱ���
			3����ͣ���ٰ��س�����ʱ��������Ļ
			4���˺���Ϊ23��
***************************************************************************/
void reset(const int menu)
{
	/*�˵���1-3�����ɺ���Ҫ�ƶ���꣬������з�����*/
	if (menu >= 1 && menu <= 3)
		cout << endl;

	/*������ɫ*/
	cct_setcolor();

	/*�˵���4-9�����ɺ���Ҫ�ƶ���꣬���ݲ˵���������ֵ��������*/
	if (menu >= 4 && menu <= 8)
		cct_gotoxy(0, CONSOLE_BASE_Y + PLATE_NUM_LIMIT + 9);

	else if (menu == 9)
		cct_gotoxy(0, CONSOLE_BASE_Y + PLATE_NUM_LIMIT + 13);

	cout << "���س�������"; /*�����ʾ��*/
	__stepnumber = 0;         /*���ü�¼�����ľ�̬ȫ�ֱ���*/
	__delay_time = 0;         /*���ñ�־��ʱʱ���ľ�̬ȫ�ֱ���*/

	pause(0);   /*������������ɺ���ж�*/
	cct_cls();  /*������Ļ*/
}

/***************************************************************************
  �������ƣ�command_center
  ��    �ܣ����ݲ˵���������ֵ��ѡ����ò�ͬ�������䵱����̨������
  ���������int number_of_plates����������
            char source_tower����ʼ�����
			char temporary_tower���м������
			char destination_tower��Ŀ�������
			int delay_time_set���ƶ��ٶȱ��
			int menu���˵���������ֵ
  �� �� ֵ����
  ˵    ����1�����ݲ˵���������ֵ��ѡ����ò�ͬ��������
			2���˺���Ϊ23��
***************************************************************************/
void command_center(int number_of_plates, char source_tower, char temporary_tower, char destination_tower, int delay_time_set, int menu)
{
	/*�����Ļ*/
	if (menu >= 4 && menu <= 9)
		cct_cls();

	/*�ڲ������ʼ��*/
	if (menu == 3 || menu == 4 || menu == 7 || menu == 8 || menu == 9)
		array_tower_initialize(number_of_plates, source_tower);

	command_info(number_of_plates, source_tower, destination_tower, delay_time_set, menu);  /*�����ʾ��*/
	command_array_base(number_of_plates, source_tower, destination_tower, menu);  /*�����������*/
	command_console_base(number_of_plates, source_tower, menu);  /*������Ӻ�����*/
	command_delay(menu);  /*�����жϻ���ʱ*/

	/*���õݹ麯��*/
	if (menu != 5 && menu != 6 && menu != 9)
		hanoi(number_of_plates, source_tower, temporary_tower, destination_tower, menu);

	/*������Ϸ*/
	if (menu == 9)
		game_command_center(number_of_plates, destination_tower, menu);
}

/***************************************************************************
  �������ƣ�command_info
  ��    �ܣ�����̨���������ݲ˵���������ֵ��ӡ��ʾ��Ϣ
  ���������const int number_of_plates������������ֻ����
			const char source_tower����ʼ����ţ�ֻ����
			const char destination_tower��Ŀ������ţ�ֻ����
			const int delay_time_set���ƶ��ٶȱ�ţ�ֻ����
			const int menu���˵���������ֵ��ֻ����
  �� �� ֵ����
  ˵    ����1�����ݲ˵���������ֵ���ڰ�Ҫ���ú���������£�ѡ����ò�ͬ����
			2���˺���Ϊ8��
***************************************************************************/
void command_info(const int number_of_plates, const char source_tower, const char destination_tower, const int delay_time_set, const int menu)
{
	if (menu == 4 || menu == 6 || menu == 7 || menu == 8 || menu == 9)
		cout << "�� " << source_tower << " �ƶ��� " << destination_tower << "���� " << number_of_plates << " ��";

	if (menu == 4 || menu == 8)
		cout << " ����ʱ����Ϊ " << delay_time_set;
}

/***************************************************************************
  �������ƣ�command_array_base
  ��    �ܣ�����̨���������ݲ˵���������ֵ��ӡ��������
  ���������const int number_of_plates������������ֻ����
			const char source_tower����ʼ����ţ�ֻ����
			const char destination_tower��Ŀ������ţ�ֻ����
			const int menu���˵���������ֵ��ֻ����
  �� �� ֵ����
  ˵    ����1�����ݲ˵���������ֵ���ڰ�Ҫ���ú���������£�ѡ����ò�ͬ����
			2���˺���Ϊ14��
***************************************************************************/
void command_array_base(const int number_of_plates, const  char source_tower, const char destination_tower, const int menu)
{
	if (menu == 4 || menu == 8 || menu == 9) {
		array_print_tower(number_of_plates, source_tower, destination_tower, menu);
		array_print_base(number_of_plates, source_tower, menu);
	}
}

/***************************************************************************
  �������ƣ�command_console_base
  ��    �ܣ�����̨���������ݲ˵���������ֵͼ�λ�����������
  ���������const int number_of_plates������������ֻ����
			const char source_tower����ʼ����ţ�ֻ����
			const int menu���˵���������ֵ��ֻ����
  �� �� ֵ����
  ˵    ����1�����ݲ˵���������ֵ���ڰ�Ҫ���ú���������£�ѡ����ò�ͬ����
			2���˺���Ϊ8��
***************************************************************************/
void command_console_base(const int number_of_plates, const  char source_tower, const int menu)
{
	if (menu >= 5 && menu <= 9)
		console_print_base();

	if (menu >= 6 && menu <= 9)
		console_print_plates(number_of_plates, source_tower);
}

/***************************************************************************
  �������ƣ�command_delay
  ��    �ܣ�����̨���������ݲ˵���������ֵ�����Ƴ�ʼ������ɺ���жϻ���ʱ
  ���������const int menu���˵���������ֵ��ֻ����
  �� �� ֵ����
  ˵    ����1�����ݲ˵���������ֵ���ڰ�Ҫ���ú���������£�ѡ����ò�ͬ����
			2���˺���Ϊ11��
***************************************************************************/
void command_delay(const int menu)
{
	if (menu == 4 || menu == 8)
		pause(__delay_time);

	else if (menu == 7)
		Sleep(1000);

	else if (menu == 9)
		Sleep(100);
}