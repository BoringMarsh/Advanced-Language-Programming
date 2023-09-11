/*2151294 信11 马威*/
/*1853015 陈鑫 2150244 黄隽阳 2150245 沈谦 2151300 王蔚达 2153488 张梓乔 2151521 张志恒 2153833 周睿彦*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	const int X_MAX = 26;     /*定义所需常量，X_MAX为长*/
	const int Y_MAX = 10;     /*定义所需常量，Y_MAX为宽*/
	const int BOMB_NUM = 50;  /*定义所需常量，BOMB_NUM为雷的个数*/

	char src[10][26];         /*定义所需数组，src[10][26]是待检测的字符数组*/
	char result[10][26];      /*定义所需数组，result[10][26]是通过检测生成的字符数组，用于和原字符数组比对*/
	char c;                   /*定义所需变量，c是从原字符数组中取样时用的字符数组*/

	int i, j, k, l;           /*定义所需变量，i、j、k、l都为计数变量*/
	int bomb = 0;             /*定义所需变量，bomb为雷数的检测值*/
	int prime = 1;            /*定义所需变量，prime为标志错误2是否成立的量*/

	/*1、数组result的初始化*/
	for (i = 0; i < Y_MAX; i++) {
		for (j = 0; j < X_MAX; j++) {
			result[i][j] = '0';
		}
	}

	/*2、从原数组中取出对应的字符，放入src中：用c逐个取样，若为空格或换行符，则计数-1并重新取样；若为雷或数字，则放入src的对应元素里*/
	for (i = 0; i < Y_MAX; i++) {
		for (j = 0; j < X_MAX; j++) {
			scanf("%c", &c);
			if (c != ' ' && c != '\n') {
				src[i][j] = c;
			}

			else {
				j--;
			}
		}
	}

	/*3、检查雷的数量：逐个检查src中的元素，若检查出雷，bomb自增，同时在result对应位置埋雷*/
	for (i = 0; i < Y_MAX; i++) {
		for (j = 0; j < X_MAX; j++) {
			if (src[i][j] == '*') {
				bomb++;
				result[i][j] = '*';
			}
		}
	}

	int limit1, limit2, limit3, limit4;  /*定义所需变量，都是在使用循环时，根据不同情况指定的上下限*/

	/*4、若雷数的检测值等于预期值，则进行错误2的检查*/
	if (bomb == BOMB_NUM) {

		/*5、逐个判断雷的情况*/
		for (i = 0; i < Y_MAX; i++) {
			for (j = 0; j < X_MAX; j++) {

				/*5.1、最上方、最下方一行（除顶点）的判断*/
				/*由于判断条件已经把雷排除在外面，故不会以某颗雷为中心判断周围雷的数量*/
				if ((i == 0 || i == Y_MAX - 1) && j != 0 && j != X_MAX - 1 && src[i][j] != '*') {

					/*5.1.1、根据最上方一行的情况取定上下限*/
					if (i == 0) {
						limit1 = i, limit2 = i + 1;
					}

					/*5.1.2、根据最下方一行的情况取定上下限*/
					else {
						limit1 = i - 1, limit2 = i;
					}

					/*5.1.3、根据取得的上下限检查雷的数量，只要检查出雷，该位置的元素自增*/
					for (k = limit1; k <= limit2; k++) {
						for (l = j - 1; l <= j + 1; l++) {
							if (src[k][l] == '*') {
								result[i][j]++;
							}
						}
					}
				}

				/*5.2、最左侧、最右侧一列（除顶点）的判断*/
				/*由于判断条件已经把雷排除在外面，故不会以某颗雷为中心判断周围雷的数量*/
				else if ((j == 0 || j == X_MAX - 1) && i != 0 && i != Y_MAX - 1 && src[i][j] != '*') {

					/*5.2.1、根据最左侧一列的情况取定上下限*/
					if (j == 0) {
						limit1 = j, limit2 = j + 1;
					}

					/*5.2.2、根据最右侧一列的情况取定上下限*/
					else {
						limit1 = j - 1, limit2 = j;
					}

					/*5.2.3、根据取得的上下限检查雷的数量，只要检查出雷，该位置的元素自增*/
					for (k = i - 1; k <= i + 1; k++) {
						for (l = limit1; l <= limit2; l++) {
							if (src[k][l] == '*') {
								result[i][j]++;
							}
						}
					}
				}

				/*5.3、四个顶点的判断*/
				/*由于判断条件已经把雷排除在外面，故不会以某颗雷为中心判断周围雷的数量*/
				else if (((i == 0 && j == 0) || (i == 0 && j == X_MAX - 1) || (i == Y_MAX - 1 && j == 0) || (i == Y_MAX - 1 && j == X_MAX - 1)) && src[i][j] != '*') {

					/*5.3.1、根据左上角的情况取定上下限*/
					if (i == 0 && j == 0) {
						limit1 = 0, limit2 = 1;
						limit3 = 0; limit4 = 1;
					}

					/*5.3.2、根据右上角的情况取定上下限*/
					else if (i == 0 && j == X_MAX - 1) {
						limit1 = 0, limit2 = 1;
						limit3 = X_MAX - 2, limit4 = X_MAX - 1;
					}

					/*5.3.3、根据左下角的情况取定上下限*/
					else if (i == Y_MAX - 1 && j == 0) {
						limit1 = Y_MAX - 2, limit2 = Y_MAX - 1;
						limit3 = 0, limit4 = 1;
					}

					/*5.3.4、根据右下角的情况取定上下限*/
					else {
						limit1 = Y_MAX - 2, limit2 = Y_MAX - 1;
						limit3 = X_MAX - 2, limit4 = X_MAX - 1;
					}

					/*5.3.5、根据取得的上下限检查雷的数量，只要检查出雷，该位置的元素自增*/
					for (k = limit1; k <= limit2; k++) {
						for (l = limit3; l <= limit4; l++) {
							if (src[k][l] == '*') {
								result[i][j]++;
							}
						}
					}
				}

				/*5.4、其他位置的判断*/
				/*由于判断条件已经把雷排除在外面，故不会以某颗雷为中心判断周围雷的数量*/
				else if (src[i][j] != '*') {

					/*5.4.1、上下限都是固定的，直接在循环语句中取定，再检查雷的数量*/
					for (k = i - 1; k <= i + 1; k++) {
						for (l = j - 1; l <= j + 1; l++) {
							if (src[k][l] == '*') {
								result[i][j]++;
							}
						}
					}
				}
			}
		}

		/*5.5、逐个比较得出的result数组和src数组的每个元素*/
		/*由于雷的位置一定相等，只需判断数字是否相等，故只要检查出字符不相等，标志变为0，跳出所有循环*/
		for (i = 0; i < Y_MAX; i++) {
			for (j = 0; j < X_MAX; j++) {
				if (src[i][j] != result[i][j]) {
					prime = 0;
					break;
				}
			}

			if (prime == 0) {
				break;
			}
		}

		/*5.6、根据prime的值输出最终结果*/
		if (prime) {
			printf("正确\n");
		}

		else {
			printf("错误2\n");
		}
	}

	/*6、若雷数的检测值不等于预期值，则输出对应的错误提示*/
	else {
	    printf("错误1\n");
    }
	
	return 0;
}