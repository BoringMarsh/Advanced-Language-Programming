/*2151294 信11 马威*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "lib_mto10_net_tools.h"
#include "cmd_console_tools.h"
#include "90-b2.h"
using namespace std;

/***************************************************************************
  函数名称：map_trans
  功    能：将服务器发回的地图转换为二维数组中的数值
  输入参数：MATRIX matrix[][ROW_MAX]：整个游戏中的结构体二维数组
            const char* get_map：服务器发回的地图（只读）
			const int line：操作行数（只读）
			const int row：操作列数（只读）
			const int menu：菜单函数返回值（只读）
  返 回 值：无
  说    明：本函数将字符型数据转换为二维数组中的整型数据
***************************************************************************/
void map_trans(MATRIX matrix[][ROW_MAX], const char* get_map, const int line, const int row, const int menu)
{
	int i, j;

	for (i = 0; i < line; i++) {
		for (j = 0; j < row; j++) {
			if (*get_map >= '1' && *get_map <= '9')  /*1-9的转换*/
				matrix[i][j].num = *get_map - '0';
			else if (*get_map >= 'A' && *get_map <= 'F')  /*A-F的转换*/
				matrix[i][j].num = *get_map - 'A' + 10;

			if (menu == 'A' || menu == 'C')  /*若为命令行方式，初始化每一个元素的标记状态为0*/
				matrix[i][j].mark = 0;

			get_map++;
		}
	}
}

/***************************************************************************
  函数名称：array_getmin
  功    能：取数组中所有元素的最小数值
  输入参数：MATRIX matrix[][ROW_MAX]：整个游戏中的结构体二维数组
			const int line：操作行数（只读）
			const int row：操作列数（只读）
  返 回 值：int：最小数值
  说    明：无
***************************************************************************/
int array_getmin(MATRIX matrix[][ROW_MAX], const int line, const int row)
{
	int i, j, min = matrix[0][0].num;  /*返回值先置为第一行第一列元素的数值*/

	for (i = 0; i < line; i++) {
		for (j = 0; j < row; j++) {
			if (min > matrix[i][j].num)  /*若当前元素的数值小于min当前值，将该数值赋给min*/
				min = matrix[i][j].num;
		}
	}

	return min;
}

/***************************************************************************
  函数名称：find_best_solution
  功    能：根据当前各元素的值，找出最优解元素对应坐标
  输入参数：MATRIX matrix[][ROW_MAX]：整个游戏中的结构体二维数组
			const int line：操作行数（只读）
			const int row：操作列数（只读）
			char final_coord[]：最优解坐标
  返 回 值：无
  说    明：算法：1、自上而下、从左到右检查
                  2、最优解为当前可以合成的数值最小的元素
***************************************************************************/
void find_best_solution(MATRIX matrix[][ROW_MAX], const int line, const int row, char final_coord[])
{
	/*若此时无可合成项，返回坐标为00（无效坐标）*/
	if (if_end(matrix, line, row)) {
		final_coord[0] = '0';
		final_coord[1] = '0';
	}

	else {
		const int MAX = array_getmax(matrix, line, row);  /*取当前数组最大元素*/
		const int MIN = array_getmin(matrix, line, row);  /*取当前数组最小元素*/
		int i, j, k;
		bool loop = true;    /*最优解是否已找到*/
		MATRIX m[LINE_MAX][ROW_MAX];

		for (k = MIN; k <= MAX && loop; k++) {  /*从最小元素开始检查*/
			for (i = 0; i < line && loop; i++) {  /*从第一行开始检查*/
				for (j = 0; j < row && loop; j++) {  /*从第一列开始检查*/

					/*若检查出了与当前k相等的元素，将matrix复制到m，模拟一次扫描，看该项是否为可合成项*/
					if (matrix[i][j].num == k) {
						array_copy(m, matrix, line, row);
						m[i][j].mark = 1;
						array_single_scan(m, i, j, line, row);

						/*若为可合成项，赋值给final_coord[]后结束检查，得到最优解*/
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
  函数名称：print_info
  功    能：输出当前游戏的信息
  输入参数：mto10_net_tools& client：用户对象
            MATRIX matrix[][ROW_MAX]：整个游戏中的结构体二维数组
  返 回 值：无
  说    明：本函数输出了游戏ID、步数、得分、加权得分
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
  函数名称：my_print_map
  功    能：命令行方式下打印当前数组
  输入参数：mto10_net_tools& client：用户对象
			MATRIX matrix[][ROW_MAX]：整个游戏中的结构体二维数组
  返 回 值：无
  说    明：无
***************************************************************************/
void my_print_map(mto10_net_tools& client, MATRIX matrix[][ROW_MAX])
{
	cout << endl << "当前数组：" << endl;
	print_info(client, matrix);  /*同时输出信息*/
	cout << endl;
	array_show(matrix, client.get_row(), client.get_col(), ARRAY_SHOW_CURRENT);
	cout << endl;
}

/***************************************************************************
  函数名称：my_console_move
  功    能：伪图形界面下，演示色块移动
  输入参数：mto10_net_tools& client：用户对象
			MATRIX matrix[][ROW_MAX]：整个游戏中的结构体二维数组
			char coordinate[]：这一步最优解坐标
			const int menu：菜单函数返回值（只读）
  返 回 值：无
  说    明：1、本函数在上传最优解坐标、接收服务器返回信息之后
            2、换言之，本函数将matrix复制到m，对m进行色块移动等操作
			3、后续才用map_trans()更新matrix的数值
***************************************************************************/
void my_console_move(mto10_net_tools& client, MATRIX matrix[][ROW_MAX], char coordinate[], const int menu)
{
	const int line = client.get_row();  /*取行数*/
	const int row = client.get_col();   /*取列数*/

	MATRIX m[LINE_MAX][ROW_MAX];
	array_copy(m, matrix, line, row);  /*复制数组*/

	array_multiple_scan1(m, line, row, coordinate, menu);  /*扫描、标记所有可合成项*/
	array_clear(m, line, row, coordinate);  /*消除数值*/
	block_multiple_clear(m, line, row);     /*消除色块*/
	console_blink_block(m, coordinate);     /*色块闪烁*/

	cct_gotoxy(0, 0);
	print_info(client, matrix);  /*打印实时信息*/
	
	block_multiple_fall(m, line, row);  /*色块下落*/
	map_trans(m, client.get_map(), line, row, 'B');  /*更新m的数值*/
	block_multiple_print(m, line, row);  /*用更新后的数值补全这一步被消除的色块*/
}

/***************************************************************************
  函数名称：game_progress
  功    能：进行游戏交互
  输入参数：mto10_net_tools& client：用户对象
			MATRIX matrix[][ROW_MAX]：整个游戏中的结构体二维数组
			const int menu：菜单函数返回值（只读）
  返 回 值：int：游戏是否结束
  说    明：无
***************************************************************************/
int game_progress(mto10_net_tools& client, MATRIX matrix[][ROW_MAX], const int menu)
{
	char svrpack[RECVBUF_LEN];	//存放从Server端收到的数据
	char coordinate[2];  /*最优解坐标*/

	if (menu == 'B') {  /*伪图形界面的准备工作*/
		map_trans(matrix, client.get_map(), client.get_row(), client.get_col(), 'B');     /*转换地图*/
		console_print_base(matrix, client.get_row(), client.get_col(), PRINT_WITH_LINE);  /*打印底盘、色块*/
		cct_gotoxy(0, 0);
		print_info(client, matrix);  /*打印初始信息*/
	}

	while (1) {
		if (menu == 'A')
			Sleep(100);
		/* -------------------
			Client=>Server
		   ------------------- */
		   /* 根据服务端发来的地图，返回一个解坐标（目前为手工输入形式，需要改为自动求最佳解坐标）
			  提示：可以将client.get_map()的返回值复制到字符数组中，再还原为你自己的二维数组后求解
		   */
		map_trans(matrix, client.get_map(), client.get_row(), client.get_col(), menu);  /*将服务器发回的地图转换到matrix中的数值*/
		array_mark_set(matrix, client.get_row(), client.get_col());  /*重置所有元素的标记状态*/

		if (menu == 'A')  /*命令行方式下的显示当前内部数组*/
			my_print_map(client, matrix);

		find_best_solution(matrix, client.get_row(), client.get_col(), coordinate);  /*求解最优解坐标*/

		/* 游戏已结束则不再读键*/
		if (client.is_gameover())
			break;

		if (menu == 'B')  /*伪图形界面下，移动光标至指定位置*/
			cct_gotoxy(0, 4 * client.get_row() + 3);
		cout << "请输入行(A-J)列(0-9)坐标 : " << coordinate[0] << coordinate[1] << endl;  /*输出提示及最优解坐标*/

		client.send_coordinate(coordinate[0], coordinate[1] - '0');  /*上传最优解坐标*/

		/* -------------------
			Server=>Client
		   ------------------- */
		   /* 等待Server端的gameprogress */
		if (client.get_gameprogress_string(svrpack) < 0) {
			return -1;
		}

		if (menu == 'B')  /*伪图形界面下，演示色块的移动*/
			my_console_move(client, matrix, coordinate, 'B');
	}//end of while(1)

	return 0;
}

/***************************************************************************
  函数名称：net_main
  功    能：网络版的所有操作，类似于网络版的主函数
  输入参数：MATRIX matrix[][ROW_MAX]：整个游戏中的结构体二维数组
			const int menu：菜单函数返回值（只读）
  返 回 值：int：游戏是否结束
  说    明：无
***************************************************************************/
void net_main(MATRIX matrix[][ROW_MAX], const int menu)
{
	cct_cls();
	const char* my_no = "2151294";         /*学号*/
	const char* my_pwd = "a1b2c3d4e5/";    /*密码*/
	int wanted_line, * p1 = &wanted_line;  /*希望行数*/
	int wanted_row, * p2 = &wanted_row;    /*希望列数*/
	int wanted_id = -1;     /*希望游戏ID（已设为随机）*/
	int wanted_delay = -1;  /*希望时延（已设为-1）*/
	multiple_input(p1, p2, NULL, menu);  /*输入希望行数和列数（无需输入合成目标）*/

	mto10_net_tools client;  /*定义用户对象*/

	/* 打开client类对象中的debug开关（调试时可打开，到图形界面时需关闭） */
	client.set_debug_switch(false);

	/* 连接服务器 */
	if (client.connect() < 0) {
		/* 连接失败信息，有没有debug_switch都打印 */
		cout << "连接服务器失败!" << endl;
		return;
	}

	/* 向Server端发送认证信息及参数 */
	if (client.send_parameter(my_no, '*', my_pwd, wanted_line, wanted_row, wanted_id, wanted_delay) < 0) {
		cout << "发送认证及参数信息失败!" << endl;
		return;
	}

	/* 等待Server端下发参数（游戏开始）*/
	if (client.wait_for_game_start() < 0) {
		cout << "等待GameStart失败!" << endl;
		return;
	}

	/* 打印从服务器收到的参数，本次游戏以此参数为准（例：发送6行6列，返回8行10列，则本次游戏以8行10列为准）
	   下面打印的信息，图形化界面可以自行去除 */
	if (menu - 'B') {
		cout << "服务器返回信息 : " << endl;
		cout << "  行数 : " << client.get_row() << endl;
		cout << "  列数 : " << client.get_col() << endl;
		cout << "  ID号 : " << client.get_gameid() << endl;
		cout << "  超时 : " << client.get_delay() / 1000.0 << "(秒)" << endl;
		cout << "  地图 : " << client.get_map() << endl;
	}

	/* 进入游戏交互环节
	   1、收到Server的GameOver则返回0，游戏结束
	   2、其它错误均返回-1（报文信息不正确等错误），重连，再次重复	*/
	if (game_progress(client, matrix, menu) < 0) {
		client.close();
		return;
	}

	client.close();

	if (menu == 'B')  /*伪图形界面下，移动光标至指定位置*/
		cct_gotoxy(0, 4 * client.get_row() + 4);

	cout << "游戏结束" << endl;

	if (menu == 'B') {  /*伪图形界面下，输出最终情况*/
		cout << "最终情况:";
		print_info(client, matrix);
	}
}

/***************************************************************************
  函数名称：competition_progress
  功    能：进行游戏交互（竞赛版）
  输入参数：mto10_net_tools& client：用户对象
  返 回 值：int：游戏是否结束
  说    明：交互过程不输出任何内容
***************************************************************************/
int competition_progress(mto10_net_tools& client)
{
	char svrpack[RECVBUF_LEN];	//存放从Server端收到的数据
	char coordinate[2];                /*最优解坐标*/
	MATRIX matrix[LINE_MAX][ROW_MAX];  /*接受地图的结构体二维数组*/

	while (1) {
		/* -------------------
			Client=>Server
		   ------------------- */
		   /* 根据服务端发来的地图，返回一个解坐标（目前为手工输入形式，需要改为自动求最佳解坐标）
			  提示：可以将client.get_map()的返回值复制到字符数组中，再还原为你自己的二维数组后求解
		   */
		map_trans(matrix, client.get_map(), client.get_row(), client.get_col(), 'C');  /*将服务器发回的地图转换到matrix中的数值*/
		find_best_solution(matrix, client.get_row(), client.get_col(), coordinate);  /*求解最优解坐标*/

		/* 游戏已结束则不再读键*/
		if (client.is_gameover())
			break;

		client.send_coordinate(coordinate[0], coordinate[1] - '0');  /*上传最优解坐标*/

		/* -------------------
			Server=>Client
		   ------------------- */
		   /* 等待Server端的gameprogress */
		if (client.get_gameprogress_string(svrpack) < 0) {
			return -1;
		}
	}//end of while(1)

	return 0;
}

/***************************************************************************
  函数名称：competition
  功    能：竞赛版的主函数
  输入参数：无
  返 回 值：无
  说    明：该函数类似net_main，为了增强可读性，单独为竞赛版写一个函数
***************************************************************************/
void competition()
{
	cct_cls();
	const char* my_no = "2151294";         /*学号*/
	const char* my_pwd = "a1b2c3d4e5/";    /*密码*/
	int game_count = 1;      /*游戏局数计数器*/
	double final_score = 0;  /*本次竞赛总分*/

	/*下列信息全部设为-1*/
	int wanted_line = -1;
	int wanted_row = -1;
	int wanted_id = -1;
	int wanted_delay = -1;

	while (game_count <= 64) {
		mto10_net_tools client;  /*定义用户对象*/

		cout << "开始进行第" << game_count << "局游戏..." << endl;
		/* 打开client类对象中的debug开关（调试时可打开，到图形界面时需关闭） */
		client.set_debug_switch(false);

		/* 连接服务器 */
		if (client.connect() < 0) {
			/* 连接失败信息，有没有debug_switch都打印 */
			cout << "连接服务器失败!" << endl;
			return;
		}

		/* 向Server端发送认证信息及参数 */
		if (client.send_parameter(my_no, '-', my_pwd, wanted_line, wanted_row, wanted_id, wanted_delay) < 0) {
			cout << "发送认证及参数信息失败!" << endl;
			return;
		}

		/* 等待Server端下发参数（游戏开始）*/
		if (client.wait_for_game_start() < 0) {
			cout << "等待GameStart失败!" << endl;
			return;
		}

		/* 进入游戏交互环节
		   1、收到Server的GameOver则返回0，游戏结束
		   2、其它错误均返回-1（报文信息不正确等错误），重连，再次重复	*/
		if (competition_progress(client) < 0) {
			client.close();
			return;
		}

		/*本局结束后，读取本局的相关信息*/
		double row = client.get_row();
		double col = client.get_col();
		double score = client.get_score();

		/*计算加权分数，累加到最终得分上*/
		double Getscore = score / (row * col);
		final_score = final_score + Getscore;

		/*打印本局最终情况*/
		cout << "第" << game_count << "局最终情况：" << endl;
		cout << "Score = " << client.get_score()
			<< " Getscore = " << Getscore
			<< " Finalscore = " << final_score << endl << endl;

		client.close();
		game_count++;  /*完成一局，计数器自增*/
	}
}