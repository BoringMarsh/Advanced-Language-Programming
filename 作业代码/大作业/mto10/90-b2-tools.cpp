/*2151294 ��11 ����*/
#include <iostream>
#include <conio.h>
#include <Winsock2.h>
#include <Windows.h>
#include "90-b2.h"
#include "cmd_console_tools.h"
using namespace std;

/***************************************************************************
  �������ƣ�command_center
  ��    �ܣ����������̨��ѡ����ò�ͬ������ɹ��ܵ�ʵ��
  ���������MATRIX matrix[][ROW_MAX]��������Ϸ�еĽṹ���ά����
            const int line������������ֻ����
			const int row������������ֻ����
			int goal����ʼ�ϳ�Ŀ��
			int score���÷�
			char coord[]�����������Ԫ��������ַ�����
			const int menu���˵���������ֵ��ֻ����
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void command_center(MATRIX matrix[][ROW_MAX], const int line, const int row, int goal, int score, char coord[], const int menu)
{
	/*******************************�����з�ʽ*******************************/
	if (menu >= 1 && menu <= 4) {
		int loop = 1;

		while (loop) {

			if (menu != 4)  /*����Ϊ�˵���4��ִֻ��һ�Σ�loop��Ϊ0*/
				loop = 0;

			else {  /*��Ϊ�˵���4���ȼ���Ƿ�ﵽ�˵�ǰ�ϳ�Ŀ��*/
				if (array_getmax(matrix, line, row) == goal) {
					command_goal_achieved(goal);
					pause();
				}

				array_mark_set(matrix, line, row);  /*�������������*/
			}

			/*��ʾ��ǰ����ֵ*/
			cout << endl << "��ǰ���飺" << endl;
			array_show(matrix, line, row, ARRAY_SHOW_CURRENT);
			cout << endl;

			/*����Ƿ����пɺϳ���ж���Ϸ�Ƿ����*/
			if (if_end(matrix, line, row) == true) {
				command_end();
				break;
			}

			do {  /*��������ֱ����������Χ����ֵͬΪֹ*/
				input_coord(line, row, coord);

				if (menu == 2)
					array_multiple_scan2(matrix, line, row, coord);  /*�˵���2�õݹ鷽ʽѰ�ҿɺϳ���*/
				else
					array_multiple_scan1(matrix, line, row, coord, menu);  /*����������˵���1���÷ǵݹ鷽ʽѰ�ҿɺϳ���*/

			} while (array_mark_count(matrix, line, row) == 0);

			/*���ַ�ʽ��ʾ���ҽ��*/
			cout << endl << "���ҽ�����飺" << endl;
			array_show(matrix, line, row, ARRAY_SHOW_RESULT);
			cout << endl << endl << "��ǰ����(��ͬɫ��ʶ)��" << endl;
			array_show(matrix, line, row, ARRAY_SHOW_CURRENT);

			/*�˵���3��4��������ָ�ȷ���Ƿ���б��κϳ�*/
			if (menu == 3 || menu == 4) {
				char command = clear_command(coord);  /*����ָ��*/

				/*����Y*/
				if (command == 'Y') {

					/*�鲢��ֵͬ����ʾ�鲢�������*/
					array_clear(matrix, line, row, coord);
					cout << endl << "��ֵͬ�鲢�������(��ͬɫ��ʶ)��" << endl;
					array_show(matrix, line, row, ARRAY_SHOW_CURRENT);

					/*����÷֡���ӡ�÷�*/
					int _getscore = array_getscore(matrix, line, row);
					score = score + _getscore;
					print_score(_getscore, score, goal, menu);

					/*���öϵ㡢���㡢��ʾ����������*/
					cout << endl << "���س����������������0����...";
					pause();
					array_move_zero(matrix, line, row);
					cout << endl << "��0�������(��ͬɫ��ʶ)��" << endl;
					array_show(matrix, line, row, ARRAY_SHOW_CURRENT);

					/*���öϵ㡢��ֵ��䡢��ʾ��ֵ���������*/
					cout << endl << "���س���������ֵ���...";
					pause();
					array_random(matrix, line, row, array_getmax(matrix, line, row));
					cout << endl << "��ֵ���������(��ͬɫ��ʶ)��" << endl;
					array_show(matrix, line, row, ARRAY_SHOW_CURRENT);
					cout << endl;

					if (menu == 4) {  /*�˵���4���ر���ʾ*/
						cout << "���κϳɽ��������س���������һ�εĺϳ�..." << endl;
						pause();
					}
				}

				/*�˵���3��ΪY���˵���4ΪQ���ڴ˽���ѭ��*/
				else if ((menu == 3 && command != 'Y') || (menu == 4 && command == 'Q'))
					break;
				/*�˵���4ΪN����ѭ��*/
				else
					continue;
			}
		}

		end();  /*��С�������������End����...*/
	}

	/*******************************αͼ�ν���*******************************/

	else if (menu >= 5 && menu <= 9) {
		if (menu == 5)  /*�˵���5�޷ָ���*/
			console_print_base(matrix, line, row, PRINT_WITHOUT_LINE);
		else            /*�������зָ���*/
			console_print_base(matrix, line, row, PRINT_WITH_LINE);

		int MK_RET1, MK_RET2, loop1 = 1;  /*����������ķ���ֵ*/

		while (loop1) {
			if (menu == 5 || menu == 6)  /*�˵���5��6�ڴ˽���*/
				break;
			else if (menu == 7)  /*�˵���7��loop1��ִֻ��1�Σ�loop1��Ϊ0*/
				loop1 = 0;

			int loop2 = 1;

			/*���˵���Ϊ9���ж��Ƿ����*/
			if (if_end(matrix, line, row) == true && menu == 9) {
				special_info(line, goal, INFO_END);  /*������ʾ*/

				while (1) {  /*��Q�˳�*/
					char c = _getch();
					if (c == 'q' || c == 'Q')
						break;
				}

				break;
			}

			/*���˵���Ϊ9���ﵽ�ϳ�Ŀ��*/
			if (array_getmax(matrix, line, row) == goal && menu == 9) {
				special_info(line, goal, INFO_GOAL_ACHIEVED);  /*�����ʾ*/

				while (1) {
					int MK_RET = mk_select();  /*�����������򰴻س�������*/
					if (MK_RET == MK_RET_MOUSE_LEFT || MK_RET == MK_RET_KEYBOARD_ENTER) {

						/*���ԭ������*/
						cct_gotoxy(0, 4 * line + 3);
						for (int i = 0; i < 80; i++)
							cout << ' ';

						/*�������˵���Լ���ǰ��Ϣ*/
						special_info(line, goal, INFO_RULES);
						cct_gotoxy(0, 0);
						print_score(0, score, goal, menu);
						break;
					}
				}
			}

			/*ѡ��ɫ��*/
			while (loop2) {
				MK_RET2 = mouse_and_keyboard(matrix, line, row, coord);

				if (menu == 7) {  /*�˵���7��ʾѡ�е�ɫ������*/
					cct_gotoxy(0, 4 * line + 3);
					cout << "                           ";
					cct_gotoxy(0, 4 * line + 3);
					cout << "ѡ����" << coord[0] << "��" << coord[1] << "��";
					loop1 = 0;  /*����loop1*/
					break;      /*����loop2*/
				}

				if (!MK_RET2) {  /*�������󷵻�ֵΪ�㣬������пɺϳ�������Ӧ��ʾ*/
					array_multiple_scan1(matrix, line, row, coord, menu);
					block_multiple_activate(matrix, line, row);
					special_info(line, goal, INFO_MAKE_SURE);
				}

				else {  /*�������󷵻�ֵ��Ϊ�㣨����굥���Ҽ���Q����������������ѭ������������*/
					loop1 = 0;
					break;
				}

				if (array_mark_count(matrix, line, row)) {  /*����ѡɫ����Χ����ֵͬ*/
					MK_RET1 = mk_select();  /*�ٶ�һ�μ���*/

					switch (MK_RET1) {
					case MK_RET_MOUSE_LEFT:
					case MK_RET_KEYBOARD_ENTER:
						loop2 = 0;  /*�����������򰴻س���������loop2�����½��кϳɲ���*/
						break;
					case MK_RET_MOUSE_MOVE:
					case MK_RET_KEYBOARD_ARROW:
						block_multiple_default(matrix, line, row);  /*����ƶ��򰴼�ͷ����ȡ������ɫ��ı�ǣ���ȥ����ѡ��ɫ��*/
						array_mark_set(matrix, line, row);
						break;
					case MK_RET_MOUSE_RIGHT:
					case MK_RET_KEYBOARD_Q:
						loop1 = 0, loop2 = 0;  /*��������Ҽ���Q������������ѭ������������*/
						break;
					}
				}

				else  /*����ѡɫ����Χ����ֵͬ���������Ӧ��ʾ����ȥ����ѡ��ɫ��*/
					special_info(line, goal, INFO_NO_CLEAR);
			}

			/*��û�е�������Ҽ���Q����ִ�кϳɲ���*/
			if (loop1) {

				/*�鲢��ֵͬ������÷֡���ʾ��Ϣ*/
				array_clear(matrix, line, row, coord);
				int _getscore = array_getscore(matrix, line, row);
				score = score + _getscore;
				cct_gotoxy(0, 0);
				print_score(_getscore, score, goal, menu);

				/*����ɫ�顢ʹ��ѡ�е�ɫ����˸*/
				block_multiple_clear(matrix, line, row);
				console_blink_block(matrix, coord);

				if (menu == 8) {  //�ϳ���ɣ��س���/�����������0
					special_info(line, goal, MENU8_FALL);
					mk_pause(MK_ENTER_CONTINUE);
				}

				block_multiple_fall(matrix, line, row);  /*��ʾɫ�����䶯��*/

				if (menu == 8) {  //����0��ɣ��س���/������������ֵ
					special_info(line, goal, MENU8_FILL);
					mk_pause(MK_ENTER_CONTINUE);
				}

				/*������ֵ����ӡ��������ɫ��*/
				array_random(matrix, line, row, array_getmax(matrix, line, row));
				block_multiple_print(matrix, line, row);

				if (menu == 8) {  //���κϳɽ�������C/�������������һ�εĺϳ�
					special_info(line, goal, MENU8_CONTINUE);
					mk_pause(MK_C_CONTINUE);
				}

				array_mark_set(matrix, line, row);  /*��������Ԫ�ر�����*/

				if (menu == 8)  /*�˵���8�ڴ˽���*/
					break;
			}
		}

		if (menu == 8 || menu == 9) {  /*�˵���8��9����ԭ������*/
			cct_gotoxy(0, 4 * line + 3);
			for (int i = 0; i < 80; i++)
				cout << ' ';
		}

		cct_gotoxy(0, 4 * line + 3);
		end();  /*��С�������������End����...*/
	}
}

/***************************************************************************
  �������ƣ�pause
  ��    �ܣ�����һ������ļ�ϵ�
  �����������
  �� �� ֵ����
  ˵    ��������س��ż����������ַ��޻���
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
  �������ƣ�end
  ��    �ܣ����ü�ϵ㣬����End�ż���
  �����������
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void end()
{
	cct_setcursor(CURSOR_VISIBLE_NORMAL);  /*��ʾ���*/

	char c[4];  /*��������ַ����ַ�����*/
	int X, Y;   /*��������*/
	cout << endl << "��С�������������End����...";

	while (1) {
		int i = 0;  /*������������ֵΪ��*/

		while (1) {
			char ch = getchar();  /*�����ȡ�ַ�*/
			if (ch == '\n')  /*���������з��������ֵ*/
				break;
			if (i < 4)  /*��iС��4�����ַ�����δ��������i��Ӧ��Ԫ�غ�i����*/
				c[i] = ch, i++;
		}

		c[3] = '\0';  /*���β�㣬Ϊ�˺���ʹ��strcmp()*/

		/*������ֵ��Ϊ�㣬���������*/
		if (strcmp(c, "End")) {
			cout << "�����������������";  /*�����ʾ*/
			cct_getxy(X, Y);       /*ȡ��ǰ����*/
			Y = Y - 1, X = X + 8;  /*����ΪĿ��λ��*/
			cct_gotoxy(X, Y);      /*�ƶ������Ŀ��λ��*/

			for (i = 0; i < 20; i++)  /*��������*/
				cout << " ";

			cct_gotoxy(X, Y);  /*��긴λ*/
		}

		/*������ֵΪ�㣬��������ȷ����������*/
		else
			break;
	}
}

/***************************************************************************
  �������ƣ�print_score
  ��    �ܣ��������������ϳ�Ŀ��
  ���������const int getscore�����ε÷֣�ֻ����
            const int score���ܷ֣�ֻ����
			const int goal���ϳ�Ŀ�ֻ꣨����
			const int menu���˵���������ֵ��ֻ����
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void print_score(const int getscore, const int score, const int goal, const int menu)
{
	if (menu == 3 || menu == 4)
		cout << endl;

	cout << "���ε÷֣�" << getscore << " ";
	cout << "�ܵ÷֣�" << score << " ";
	cout << "�ϳ�Ŀ�꣺" << goal << " " << endl;
}

/***************************************************************************
  �������ƣ�clear_command
  ��    �ܣ�����ָ�����ÿ�μ��������Ƿ������ֵ�ϲ�
  ���������const char coord[]�����Ŀ��Ԫ�����������
  �� �� ֵ��char��ָ�����
  ˵    ������
***************************************************************************/
char clear_command(const char coord[])
{
	char c;
	cout << endl << "��ȷ���Ƿ�����ڵ���ֵͬ�ϲ���" << coord[0] << coord[1] << "��(Y/N/Q)��";

	/*��������ָ����谴�س���ֱ������Ϊ���������ָ��Ž������*/
	while (1) {
		c = _getch();
		if (c == 'y' || c == 'Y' || c == 'n' || c == 'N' || c == 'q' || c == 'Q')
			break;
	}

	cout << c << endl;  /*����ָ��*/
	if (c >= 'a' && c <= 'z')   /*����Ϊ��д*/
		c = c - 'a' + 'A';

	return c;
}

/***************************************************************************
  �������ƣ�input_coord
  ��    �ܣ����������Ԫ������
  ���������const int line����������
			const int row����������
			char coordinate[]��������������
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void input_coord(const int line, const int row, char coordinate[])
{
	cout << "������ĸ+������ʽ[����c2]����������꣺";
	int X, Y, j;    /*�������ꡢ��������*/
	char coord[2];  /*������������*/

	while (1) {
		coord[0] = coord[1] = 0;  /*�����ʼ��*/
		int i = 0;  /*��������*/

		/*1����������*/
		while (1) {
			char c = getchar();  /*�����ȡ�ַ�*/
			if (c == '\n')    /*���л��з�����������*/
				break;
			if (i == 0)       /*������δ��������һ���ַ�����coord[0]*/
				coord[0] = c;
			else if (i == 1)  /*������δ�������ڶ����ַ�����coord[1]*/
				coord[1] = c;
			i++;    /*ÿ����һ���ַ�����������������ͳ��������ַ���*/
		}

		/*2������coord[0]�Ĵ�Сд*/
		if (coord[0] >= 'a' && coord[0] <= 'z')
			coord[0] = coord[0] - 'a' + 'A';

		/*3�����������Ҫ����������������������*/
		if (coord[0] - 'A' >= 0 && coord[0] - 'A' <= line && coord[1] - '0' >= 0 && coord[1] - '0' <= row) {
			cout << "����Ϊ" << coord[0] << "��" << coord[1] << "��" << endl;
			break;
		}

		/*4�������겻����Ҫ�������ʾ������ԭ�����ݲ���������*/
		else {
			cout << "�����������������.";

			cct_getxy(X, Y);   /*ȡ��ǰ����*/
			Y--, X = X + 18;   /*����ΪĿ��λ��*/
			cct_gotoxy(X, Y);  /*�ƶ������Ŀ��λ��*/

			for (j = 0; j < 20; j++)  /*��������*/
				cout << " ";

			cct_gotoxy(X, Y);  /*��긴λ*/
		}
	}

	coordinate[0] = coord[0], coordinate[1] = coord[1];  /*���Ѵ���õ����긳������*/
}

/***************************************************************************
  �������ƣ�if_end
  ��    �ܣ����ݵ�ǰ����ֵ���ж���Ϸ�Ƿ����
  ���������MATRIX matrix[][ROW_MAX]��������Ϸ�еĽṹ���ά����
            const int line������������ֻ����
			const int row������������ֻ����
  �� �� ֵ��bool����Ϸ�Ƿ��������������true��δ��������false��
  ˵    ������
***************************************************************************/
bool if_end(MATRIX matrix[][ROW_MAX], const int line, const int row)
{
	int i, j, count = 0;  /*countΪͳ����Χ����ֵͬԪ�������ı���*/

	for (i = 0; i < line; i++) {
		for (j = 0; j < row; j++) {
			matrix[i][j].mark = 1;  /*��ǵ�ǰԪ��*/
			array_single_scan(matrix, i, j, line, row);    /*����Ԫ����Χ������ֵͬ*/
			if (array_mark_count(matrix, line, row) == 1)  /*���������鱻���Ԫ��������Ϊ1��˵����Ԫ����Χ����ֵͬ*/
				count++;  /*����������*/
			array_mark_set(matrix, line, row);  /*��������Ԫ�صı�����*/
		}
	}
	if (count == line * row)  /*����Χ����ֵͬԪ������=����*������˵������Ԫ�ض����ɺϳɣ���Ϸ����*/
		return true;
	else                      /*�����ȣ�˵������Ԫ�ؿ��Ժϳɣ���Ϸ����*/
		return false;
}