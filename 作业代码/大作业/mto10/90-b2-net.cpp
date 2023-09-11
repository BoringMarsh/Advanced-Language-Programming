/*2151294 ��11 ����*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "lib_mto10_net_tools.h"
#include "cmd_console_tools.h"
#include "90-b2.h"
using namespace std;

/***************************************************************************
  �������ƣ�map_trans
  ��    �ܣ������������صĵ�ͼת��Ϊ��ά�����е���ֵ
  ���������MATRIX matrix[][ROW_MAX]��������Ϸ�еĽṹ���ά����
            const char* get_map�����������صĵ�ͼ��ֻ����
			const int line������������ֻ����
			const int row������������ֻ����
			const int menu���˵���������ֵ��ֻ����
  �� �� ֵ����
  ˵    �������������ַ�������ת��Ϊ��ά�����е���������
***************************************************************************/
void map_trans(MATRIX matrix[][ROW_MAX], const char* get_map, const int line, const int row, const int menu)
{
	int i, j;

	for (i = 0; i < line; i++) {
		for (j = 0; j < row; j++) {
			if (*get_map >= '1' && *get_map <= '9')  /*1-9��ת��*/
				matrix[i][j].num = *get_map - '0';
			else if (*get_map >= 'A' && *get_map <= 'F')  /*A-F��ת��*/
				matrix[i][j].num = *get_map - 'A' + 10;

			if (menu == 'A' || menu == 'C')  /*��Ϊ�����з�ʽ����ʼ��ÿһ��Ԫ�صı��״̬Ϊ0*/
				matrix[i][j].mark = 0;

			get_map++;
		}
	}
}

/***************************************************************************
  �������ƣ�array_getmin
  ��    �ܣ�ȡ����������Ԫ�ص���С��ֵ
  ���������MATRIX matrix[][ROW_MAX]��������Ϸ�еĽṹ���ά����
			const int line������������ֻ����
			const int row������������ֻ����
  �� �� ֵ��int����С��ֵ
  ˵    ������
***************************************************************************/
int array_getmin(MATRIX matrix[][ROW_MAX], const int line, const int row)
{
	int i, j, min = matrix[0][0].num;  /*����ֵ����Ϊ��һ�е�һ��Ԫ�ص���ֵ*/

	for (i = 0; i < line; i++) {
		for (j = 0; j < row; j++) {
			if (min > matrix[i][j].num)  /*����ǰԪ�ص���ֵС��min��ǰֵ��������ֵ����min*/
				min = matrix[i][j].num;
		}
	}

	return min;
}

/***************************************************************************
  �������ƣ�find_best_solution
  ��    �ܣ����ݵ�ǰ��Ԫ�ص�ֵ���ҳ����Ž�Ԫ�ض�Ӧ����
  ���������MATRIX matrix[][ROW_MAX]��������Ϸ�еĽṹ���ά����
			const int line������������ֻ����
			const int row������������ֻ����
			char final_coord[]�����Ž�����
  �� �� ֵ����
  ˵    �����㷨��1�����϶��¡������Ҽ��
                  2�����Ž�Ϊ��ǰ���Ժϳɵ���ֵ��С��Ԫ��
***************************************************************************/
void find_best_solution(MATRIX matrix[][ROW_MAX], const int line, const int row, char final_coord[])
{
	/*����ʱ�޿ɺϳ����������Ϊ00����Ч���꣩*/
	if (if_end(matrix, line, row)) {
		final_coord[0] = '0';
		final_coord[1] = '0';
	}

	else {
		const int MAX = array_getmax(matrix, line, row);  /*ȡ��ǰ�������Ԫ��*/
		const int MIN = array_getmin(matrix, line, row);  /*ȡ��ǰ������СԪ��*/
		int i, j, k;
		bool loop = true;    /*���Ž��Ƿ����ҵ�*/
		MATRIX m[LINE_MAX][ROW_MAX];

		for (k = MIN; k <= MAX && loop; k++) {  /*����СԪ�ؿ�ʼ���*/
			for (i = 0; i < line && loop; i++) {  /*�ӵ�һ�п�ʼ���*/
				for (j = 0; j < row && loop; j++) {  /*�ӵ�һ�п�ʼ���*/

					/*���������뵱ǰk��ȵ�Ԫ�أ���matrix���Ƶ�m��ģ��һ��ɨ�裬�������Ƿ�Ϊ�ɺϳ���*/
					if (matrix[i][j].num == k) {
						array_copy(m, matrix, line, row);
						m[i][j].mark = 1;
						array_single_scan(m, i, j, line, row);

						/*��Ϊ�ɺϳ����ֵ��final_coord[]�������飬�õ����Ž�*/
						if (array_mark_count(m, line, row) > 1) {
							final_coord[0] = i + 'A';
							final_coord[1] = j + '0';
							loop = false;
						}
					}
				}//end of for (j = 0...)
			}//end of for (i = 0...)
		}//end of for(k = MIN...)
	}//end of else
}

/***************************************************************************
  �������ƣ�print_info
  ��    �ܣ������ǰ��Ϸ����Ϣ
  ���������mto10_net_tools& client���û�����
            MATRIX matrix[][ROW_MAX]��������Ϸ�еĽṹ���ά����
  �� �� ֵ����
  ˵    �����������������ϷID���������÷֡���Ȩ�÷�
***************************************************************************/
void print_info(mto10_net_tools& client, MATRIX matrix[][ROW_MAX])
{
	double row = client.get_row();
	double col = client.get_col();
	double score = client.get_score();

	cout << "GameID = " << client.get_gameid()
		<< " Step = " << client.get_step()
		<< " Score = " << client.get_score()
		<< " Weight = " << score / (row * col);
}

/***************************************************************************
  �������ƣ�my_print_map
  ��    �ܣ������з�ʽ�´�ӡ��ǰ����
  ���������mto10_net_tools& client���û�����
			MATRIX matrix[][ROW_MAX]��������Ϸ�еĽṹ���ά����
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void my_print_map(mto10_net_tools& client, MATRIX matrix[][ROW_MAX])
{
	cout << endl << "��ǰ���飺" << endl;
	print_info(client, matrix);  /*ͬʱ�����Ϣ*/
	cout << endl;
	array_show(matrix, client.get_row(), client.get_col(), ARRAY_SHOW_CURRENT);
	cout << endl;
}

/***************************************************************************
  �������ƣ�my_console_move
  ��    �ܣ�αͼ�ν����£���ʾɫ���ƶ�
  ���������mto10_net_tools& client���û�����
			MATRIX matrix[][ROW_MAX]��������Ϸ�еĽṹ���ά����
			char coordinate[]����һ�����Ž�����
			const int menu���˵���������ֵ��ֻ����
  �� �� ֵ����
  ˵    ����1�����������ϴ����Ž����ꡢ���շ�����������Ϣ֮��
            2������֮����������matrix���Ƶ�m����m����ɫ���ƶ��Ȳ���
			3����������map_trans()����matrix����ֵ
***************************************************************************/
void my_console_move(mto10_net_tools& client, MATRIX matrix[][ROW_MAX], char coordinate[], const int menu)
{
	const int line = client.get_row();  /*ȡ����*/
	const int row = client.get_col();   /*ȡ����*/

	MATRIX m[LINE_MAX][ROW_MAX];
	array_copy(m, matrix, line, row);  /*��������*/

	array_multiple_scan1(m, line, row, coordinate, menu);  /*ɨ�衢������пɺϳ���*/
	array_clear(m, line, row, coordinate);  /*������ֵ*/
	block_multiple_clear(m, line, row);     /*����ɫ��*/
	console_blink_block(m, coordinate);     /*ɫ����˸*/

	cct_gotoxy(0, 0);
	print_info(client, matrix);  /*��ӡʵʱ��Ϣ*/
	
	block_multiple_fall(m, line, row);  /*ɫ������*/
	map_trans(m, client.get_map(), line, row, 'B');  /*����m����ֵ*/
	block_multiple_print(m, line, row);  /*�ø��º����ֵ��ȫ��һ����������ɫ��*/
}

/***************************************************************************
  �������ƣ�game_progress
  ��    �ܣ�������Ϸ����
  ���������mto10_net_tools& client���û�����
			MATRIX matrix[][ROW_MAX]��������Ϸ�еĽṹ���ά����
			const int menu���˵���������ֵ��ֻ����
  �� �� ֵ��int����Ϸ�Ƿ����
  ˵    ������
***************************************************************************/
int game_progress(mto10_net_tools& client, MATRIX matrix[][ROW_MAX], const int menu)
{
	char svrpack[RECVBUF_LEN];	//��Ŵ�Server���յ�������
	char coordinate[2];  /*���Ž�����*/

	if (menu == 'B') {  /*αͼ�ν����׼������*/
		map_trans(matrix, client.get_map(), client.get_row(), client.get_col(), 'B');     /*ת����ͼ*/
		console_print_base(matrix, client.get_row(), client.get_col(), PRINT_WITH_LINE);  /*��ӡ���̡�ɫ��*/
		cct_gotoxy(0, 0);
		print_info(client, matrix);  /*��ӡ��ʼ��Ϣ*/
	}

	while (1) {
		if (menu == 'A')
			Sleep(100);
		/* -------------------
			Client=>Server
		   ------------------- */
		   /* ���ݷ���˷����ĵ�ͼ������һ�������꣨ĿǰΪ�ֹ�������ʽ����Ҫ��Ϊ�Զ�����ѽ����꣩
			  ��ʾ�����Խ�client.get_map()�ķ���ֵ���Ƶ��ַ������У��ٻ�ԭΪ���Լ��Ķ�ά��������
		   */
		map_trans(matrix, client.get_map(), client.get_row(), client.get_col(), menu);  /*�����������صĵ�ͼת����matrix�е���ֵ*/
		array_mark_set(matrix, client.get_row(), client.get_col());  /*��������Ԫ�صı��״̬*/

		if (menu == 'A')  /*�����з�ʽ�µ���ʾ��ǰ�ڲ�����*/
			my_print_map(client, matrix);

		find_best_solution(matrix, client.get_row(), client.get_col(), coordinate);  /*������Ž�����*/

		/* ��Ϸ�ѽ������ٶ���*/
		if (client.is_gameover())
			break;

		if (menu == 'B')  /*αͼ�ν����£��ƶ������ָ��λ��*/
			cct_gotoxy(0, 4 * client.get_row() + 3);
		cout << "��������(A-J)��(0-9)���� : " << coordinate[0] << coordinate[1] << endl;  /*�����ʾ�����Ž�����*/

		client.send_coordinate(coordinate[0], coordinate[1] - '0');  /*�ϴ����Ž�����*/

		/* -------------------
			Server=>Client
		   ------------------- */
		   /* �ȴ�Server�˵�gameprogress */
		if (client.get_gameprogress_string(svrpack) < 0) {
			return -1;
		}

		if (menu == 'B')  /*αͼ�ν����£���ʾɫ����ƶ�*/
			my_console_move(client, matrix, coordinate, 'B');
	}//end of while(1)

	return 0;
}

/***************************************************************************
  �������ƣ�net_main
  ��    �ܣ����������в�����������������������
  ���������MATRIX matrix[][ROW_MAX]��������Ϸ�еĽṹ���ά����
			const int menu���˵���������ֵ��ֻ����
  �� �� ֵ��int����Ϸ�Ƿ����
  ˵    ������
***************************************************************************/
void net_main(MATRIX matrix[][ROW_MAX], const int menu)
{
	cct_cls();
	const char* my_no = "2151294";         /*ѧ��*/
	const char* my_pwd = "a1b2c3d4e5/";    /*����*/
	int wanted_line, * p1 = &wanted_line;  /*ϣ������*/
	int wanted_row, * p2 = &wanted_row;    /*ϣ������*/
	int wanted_id = -1;     /*ϣ����ϷID������Ϊ�����*/
	int wanted_delay = -1;  /*ϣ��ʱ�ӣ�����Ϊ-1��*/
	multiple_input(p1, p2, NULL, menu);  /*����ϣ����������������������ϳ�Ŀ�꣩*/

	mto10_net_tools client;  /*�����û�����*/

	/* ��client������е�debug���أ�����ʱ�ɴ򿪣���ͼ�ν���ʱ��رգ� */
	client.set_debug_switch(false);

	/* ���ӷ����� */
	if (client.connect() < 0) {
		/* ����ʧ����Ϣ����û��debug_switch����ӡ */
		cout << "���ӷ�����ʧ��!" << endl;
		return;
	}

	/* ��Server�˷�����֤��Ϣ������ */
	if (client.send_parameter(my_no, '*', my_pwd, wanted_line, wanted_row, wanted_id, wanted_delay) < 0) {
		cout << "������֤��������Ϣʧ��!" << endl;
		return;
	}

	/* �ȴ�Server���·���������Ϸ��ʼ��*/
	if (client.wait_for_game_start() < 0) {
		cout << "�ȴ�GameStartʧ��!" << endl;
		return;
	}

	/* ��ӡ�ӷ������յ��Ĳ�����������Ϸ�Դ˲���Ϊ׼����������6��6�У�����8��10�У��򱾴���Ϸ��8��10��Ϊ׼��
	   �����ӡ����Ϣ��ͼ�λ������������ȥ�� */
	if (menu - 'B') {
		cout << "������������Ϣ : " << endl;
		cout << "  ���� : " << client.get_row() << endl;
		cout << "  ���� : " << client.get_col() << endl;
		cout << "  ID�� : " << client.get_gameid() << endl;
		cout << "  ��ʱ : " << client.get_delay() / 1000.0 << "(��)" << endl;
		cout << "  ��ͼ : " << client.get_map() << endl;
	}

	/* ������Ϸ��������
	   1���յ�Server��GameOver�򷵻�0����Ϸ����
	   2���������������-1��������Ϣ����ȷ�ȴ��󣩣��������ٴ��ظ�	*/
	if (game_progress(client, matrix, menu) < 0) {
		client.close();
		return;
	}

	client.close();

	if (menu == 'B')  /*αͼ�ν����£��ƶ������ָ��λ��*/
		cct_gotoxy(0, 4 * client.get_row() + 4);

	cout << "��Ϸ����" << endl;

	if (menu == 'B') {  /*αͼ�ν����£�����������*/
		cout << "�������:";
		print_info(client, matrix);
	}
}

/***************************************************************************
  �������ƣ�competition_progress
  ��    �ܣ�������Ϸ�����������棩
  ���������mto10_net_tools& client���û�����
  �� �� ֵ��int����Ϸ�Ƿ����
  ˵    �����������̲�����κ�����
***************************************************************************/
int competition_progress(mto10_net_tools& client)
{
	char svrpack[RECVBUF_LEN];	//��Ŵ�Server���յ�������
	char coordinate[2];                /*���Ž�����*/
	MATRIX matrix[LINE_MAX][ROW_MAX];  /*���ܵ�ͼ�Ľṹ���ά����*/

	while (1) {
		/* -------------------
			Client=>Server
		   ------------------- */
		   /* ���ݷ���˷����ĵ�ͼ������һ�������꣨ĿǰΪ�ֹ�������ʽ����Ҫ��Ϊ�Զ�����ѽ����꣩
			  ��ʾ�����Խ�client.get_map()�ķ���ֵ���Ƶ��ַ������У��ٻ�ԭΪ���Լ��Ķ�ά��������
		   */
		map_trans(matrix, client.get_map(), client.get_row(), client.get_col(), 'C');  /*�����������صĵ�ͼת����matrix�е���ֵ*/
		find_best_solution(matrix, client.get_row(), client.get_col(), coordinate);  /*������Ž�����*/

		/* ��Ϸ�ѽ������ٶ���*/
		if (client.is_gameover())
			break;

		client.send_coordinate(coordinate[0], coordinate[1] - '0');  /*�ϴ����Ž�����*/

		/* -------------------
			Server=>Client
		   ------------------- */
		   /* �ȴ�Server�˵�gameprogress */
		if (client.get_gameprogress_string(svrpack) < 0) {
			return -1;
		}
	}//end of while(1)

	return 0;
}

/***************************************************************************
  �������ƣ�competition
  ��    �ܣ��������������
  �����������
  �� �� ֵ����
  ˵    �����ú�������net_main��Ϊ����ǿ�ɶ��ԣ�����Ϊ������дһ������
***************************************************************************/
void competition()
{
	cct_cls();
	const char* my_no = "2151294";         /*ѧ��*/
	const char* my_pwd = "a1b2c3d4e5/";    /*����*/
	int game_count = 1;      /*��Ϸ����������*/
	double final_score = 0;  /*���ξ����ܷ�*/

	/*������Ϣȫ����Ϊ-1*/
	int wanted_line = -1;
	int wanted_row = -1;
	int wanted_id = -1;
	int wanted_delay = -1;

	while (game_count <= 64) {
		mto10_net_tools client;  /*�����û�����*/

		cout << "��ʼ���е�" << game_count << "����Ϸ..." << endl;
		/* ��client������е�debug���أ�����ʱ�ɴ򿪣���ͼ�ν���ʱ��رգ� */
		client.set_debug_switch(false);

		/* ���ӷ����� */
		if (client.connect() < 0) {
			/* ����ʧ����Ϣ����û��debug_switch����ӡ */
			cout << "���ӷ�����ʧ��!" << endl;
			return;
		}

		/* ��Server�˷�����֤��Ϣ������ */
		if (client.send_parameter(my_no, '-', my_pwd, wanted_line, wanted_row, wanted_id, wanted_delay) < 0) {
			cout << "������֤��������Ϣʧ��!" << endl;
			return;
		}

		/* �ȴ�Server���·���������Ϸ��ʼ��*/
		if (client.wait_for_game_start() < 0) {
			cout << "�ȴ�GameStartʧ��!" << endl;
			return;
		}

		/* ������Ϸ��������
		   1���յ�Server��GameOver�򷵻�0����Ϸ����
		   2���������������-1��������Ϣ����ȷ�ȴ��󣩣��������ٴ��ظ�	*/
		if (competition_progress(client) < 0) {
			client.close();
			return;
		}

		/*���ֽ����󣬶�ȡ���ֵ������Ϣ*/
		double row = client.get_row();
		double col = client.get_col();
		double score = client.get_score();

		/*�����Ȩ�������ۼӵ����յ÷���*/
		double Getscore = score / (row * col);
		final_score = final_score + Getscore;

		/*��ӡ�����������*/
		cout << "��" << game_count << "�����������" << endl;
		cout << "Score = " << client.get_score()
			<< " Getscore = " << Getscore
			<< " Finalscore = " << final_score << endl << endl;

		client.close();
		game_count++;  /*���һ�֣�����������*/
	}
}