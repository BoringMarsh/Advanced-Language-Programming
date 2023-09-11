/*2151294 ��11 ����*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include "cmd_console_tools.h"
#include "hanoi.h"
using namespace std;

/* ----------------------------------------------------------------------------------

     ���ļ����ܣ�
	1����main����
	2����ʼ����Ļ
	3�����ò˵�������hanoi_menu.cpp�У�������ѡ��
	4������ѡ����ò˵������Ӧ��ִ�к�����hanoi_multiple_solutions.cpp�У�

     ���ļ�Ҫ��
	1����������ȫ�ֱ��������ⲿȫ�ֺ;�̬ȫ�֣�const��#define�������Ʒ�Χ�ڣ�
	2����̬�ֲ����������������ƣ���ʹ��׼��Ҳ�ǣ����á����á��ܲ��þ�������
	3���������ϵͳͷ�ļ����Զ���ͷ�ļ��������ռ��

   ----------------------------------------------------------------------------------- */

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int main()
{
	/* demo������ִ�д˾䣬��cmd��������Ϊ40��x120�У����������120�У�����9000�У���cmd�����Ҳ���д�ֱ�����ˣ�*/
	cct_setconsoleborder(120, 40, 120, 9000);

	while (1) {
		int MENU = menu();         /*������������ղ˵���������ֵ*/
		cout << MENU << "\n\n\n";  /*���ԣ��������λ��*/
		Sleep(200);                /*��ʱ�����ƹ۸�*/

		/*�˵���Ϊ0��ֱ���˳�*/
		if (MENU == 0)
			break;

		int number_of_plates, * nop = &number_of_plates;  /*�����ʾ���������ı�������ָ��*/
		int delay_time_set = 0, * dts = &delay_time_set;  /*�����ʾ�ƶ��ٶȱ�ŵı�������ָ��*/
		char src_tower, * st = &src_tower;  /*�����ʾ��ʼ����ŵı�������ָ��*/
		char dst_tower, * dt = &dst_tower;  /*�����ʾĿ������ŵı�������ָ��*/

		/*�������뺯������ȷ����������*/
		input_info(nop, st, dt, dts, MENU);

		/*������ʼ����Ŀ�����ı�ţ�ȷ���м����ı��*/
		char tmp_tower = 'A' + 'B' + 'C' - src_tower - dst_tower;

		/*���ع��*/
		cct_setcursor(CURSOR_INVISIBLE);

		/*�������в��������ÿ���̨��ѡ����ò�ͬ����*/
		command_center(number_of_plates, src_tower, tmp_tower, dst_tower, delay_time_set, MENU);

		/*��ʾ���*/
		cct_setcursor(CURSOR_VISIBLE_NORMAL);

		/*ÿ��ִ����ɺ����ͣ*/
		reset(MENU);
	}
	
	return 0;
}