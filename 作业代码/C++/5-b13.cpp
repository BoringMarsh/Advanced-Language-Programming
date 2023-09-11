/*2151294 信11 马威*/
#include<iostream>
#include<iomanip>
#include<time.h>
#include<windows.h>
using namespace std;

int main()
{
	/*生成伪随机数的种子*/
	srand((unsigned int)(time(0)));
	
	const int X_MAX = 26;     /*定义所需常量，X_MAX为长*/
	const int Y_MAX = 10;     /*定义所需常量，Y_MAX为宽*/
	const int BOMB_NUM = 50;  /*定义所需常量，BOMB_NUM为雷的个数*/

	char a[Y_MAX][X_MAX];  /*定义所需数组，a[Y_MAX][X_MAX]是表示各个格子的字符数组*/
	int i, j, k, l;        /*定义所需变量，i、j、k、l都为计数变量*/

	/*1、数组初始化，将所有元素初始化为字符'0'*/
	for (i = 0; i < Y_MAX; i++) {
		for (j = 0; j < X_MAX; j++) {
			a[i][j] = '0';
		}
	}

	int x, y;  /*定义所需变量，x、y都为随机产生的坐标*/

	/*2、埋雷，每次随机取定一个坐标，将该坐标上的元素变为'*'，若该坐标上已经是雷，则i自减，重新取定坐标，保证有50颗雷*/
	for (i = 0; i < BOMB_NUM; i++) {
		x = rand() % X_MAX;
		y = rand() % Y_MAX;

		if (a[y][x] == '*') {
			i--;
		}

		else {
			a[y][x] = '*';
		}
	}

	int limit1, limit2, limit3, limit4;  /*定义所需变量，都是在使用循环时，根据不同情况指定的上下限*/

	/*3、逐个判断雷的情况*/
	for (i = 0; i < Y_MAX; i++) {
		for (j = 0; j < X_MAX; j++) {

			/*3.1、最上方、最下方一行（除顶点）的判断*/
			/*由于判断条件已经把雷排除在外面，故不会以某颗雷为中心判断周围雷的数量*/
			if ((i == 0 || i == Y_MAX - 1) && j != 0 && j != X_MAX - 1 && a[i][j] != '*') {

				/*3.1.1、根据最上方一行的情况取定上下限*/
				if (i == 0) {
					limit1 = i, limit2 = i + 1;
				}

				/*3.1.2、根据最下方一行的情况取定上下限*/
				else {
					limit1 = i - 1, limit2 = i;
				}

				/*3.1.3、根据取得的上下限检查雷的数量，只要检查出雷，该位置的元素自增*/
				for (k = limit1; k <= limit2; k++) {
					for (l = j - 1; l <= j + 1; l++) {
						if (a[k][l] == '*') {
							a[i][j]++;
						}
					}
				}
			}

			/*3.2、最左侧、最右侧一列（除顶点）的判断*/
			/*由于判断条件已经把雷排除在外面，故不会以某颗雷为中心判断周围雷的数量*/
			else if ((j == 0 || j == X_MAX - 1) && i != 0 && i != Y_MAX - 1 && a[i][j] != '*') {

				/*3.2.1、根据最左侧一列的情况取定上下限*/
				if (j == 0) {
					limit1 = j, limit2 = j + 1;
				}

				/*3.2.2、根据最右侧一列的情况取定上下限*/
				else {
					limit1 = j - 1, limit2 = j;
				}

				/*3.2.3、根据取得的上下限检查雷的数量，只要检查出雷，该位置的元素自增*/
				for (k = i - 1; k <= i + 1; k++) {
					for (l = limit1; l <= limit2; l++) {
						if (a[k][l] == '*') {
							a[i][j]++;
						}
					}
				}
			}

			/*3.3、四个顶点的判断*/
			/*由于判断条件已经把雷排除在外面，故不会以某颗雷为中心判断周围雷的数量*/
			else if (((i == 0 && j == 0) || (i == 0 && j == X_MAX - 1) || (i == Y_MAX - 1 && j == 0) || (i == Y_MAX - 1 && j == X_MAX - 1)) && a[i][j] != '*') {

				/*3.3.1、根据左上角的情况取定上下限*/
				if (i == 0 && j == 0) {
					limit1 = 0, limit2 = 1;
					limit3 = 0; limit4 = 1;
				}

				/*3.3.2、根据右上角的情况取定上下限*/
				else if (i == 0 && j == X_MAX - 1) {
					limit1 = 0, limit2 = 1;
					limit3 = X_MAX - 2, limit4 = X_MAX - 1;
				}

				/*3.3.3、根据左下角的情况取定上下限*/
				else if (i == Y_MAX - 1 && j == 0) {
					limit1 = Y_MAX - 2, limit2 = Y_MAX - 1;
					limit3 = 0, limit4 = 1;
				}

				/*3.3.4、根据右下角的情况取定上下限*/
				else {
					limit1 = Y_MAX - 2, limit2 = Y_MAX - 1;
					limit3 = X_MAX - 2, limit4 = X_MAX - 1;
				}

				/*3.3.5、根据取得的上下限检查雷的数量，只要检查出雷，该位置的元素自增*/
				for (k = limit1; k <= limit2; k++) {
					for (l = limit3; l <= limit4; l++) {
						if (a[k][l] == '*') {
							a[i][j]++;
						}
					}
				}
			}

			/*3.4、其他位置的判断*/
			/*由于判断条件已经把雷排除在外面，故不会以某颗雷为中心判断周围雷的数量*/
			else if (a[i][j] != '*') {

				/*3.4.1、上下限都是固定的，直接在循环语句中取定，再检查雷的数量*/
				for (k = i - 1; k <= i + 1; k++) {
					for (l = j - 1; l <= j + 1; l++) {
						if (a[k][l] == '*') {
							a[i][j]++;
						}
					}
				}
			}
		}
	}

	/*4、打印所有格子的情况，有空格和换行*/
	for (i = 0; i < Y_MAX; i++) {
		for (j = 0; j < X_MAX; j++) {
			cout << setw(2) << setiosflags(ios::left) << a[i][j];

			if (j == X_MAX - 1) {
				cout << endl;
			}
		}
	}

	return 0;
}