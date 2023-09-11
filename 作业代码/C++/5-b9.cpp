/*2151294 信11 马威*/
#include<iostream>
using namespace std;
int main()
{
	int s[9][9], block[9][9];  /*定义所需数组，s[9][9]是数独元素（按行按列排），block[9][9]是数独元素（按小九宫格排）*/
	int i, j, k, l, m;         /*定义所需变量，i、j、k、l都是计数用变量*/
	int ni, nj;                /*定义所需变量，ni、nj都是计数用变量*/
	bool proof = true;         /*定义所需变量，proof为判断该矩阵是否为数独的解的变量*/

	/*1、输入部分：逐行逐列逐个输入，若超范围，输出提示语+丢弃继续读；若输入状态错误，清空缓冲区+输出提示语*/
	cout << "请输入9*9的矩阵，值为1-9之间" << endl;
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {
			while (1) {
				cin >> s[i][j];

				if (s[i][j] >= 1 && s[i][j] <= 9 && cin.good() == 1) {
					break;
				}

				else if ((s[i][j] < 1 || s[i][j]>9) && cin.good() == 1) {
					cout << "请重新输入第" << i + 1 << "行" << j + 1 << "列(行列均从1开始计数)" << endl;
					continue;
				}

				else if (cin.good() == 0) {
					cout << "请重新输入第" << i + 1 << "行" << j + 1 << "列(行列均从1开始计数)" << endl;
					cin.clear();
					cin.ignore(INT_MAX, '\n');
				}
			}
		}
	}

	/*2、逐行比较，每一行内若有相同的两个元素，则proof的值为false*/
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {
			for (k = 0; k < 9; k++) {
				if (j != k&& s[i][j] == s[i][k]) {
					proof = false;
				}
			}
		}
	}

	/*3、逐列比较，每一列内若有相同的两个元素，则proof的值为false*/
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {
			for (k = 0; k < 9; k++) {
				if (j != k && s[j][i] == s[k][i]) {
					proof = false;
				}
			}
		}
	}

	/*4、将每个小九宫格内的元素赋到数组block[9][9]上，每个block[k]都是一个小九宫格*/
	k = 0, l = 0;
	for (ni = 0; ni < 3; ni++) {
		for (nj = 0; nj < 3; nj++) {

			for (i = 0 + 3 * ni; i < 3 + 3 * ni; i++) {
				for (j = 0 + 3 * nj; j < 3 + 3 * nj; j++) {
					block[k][l] = s[i][j];
					l++;  /*每赋值完一个元素，l自增，标志该九宫格的下一个元素*/
				}
			}

			/*每赋值完一个小九宫格，k自增，l归零，标志下一个小九宫格的第一个元素*/
			k++;
			l = 0;
		}
	}

	/*5、逐个小九宫格比较，每一小九宫格内若有相同的两个元素，则proof的值为false*/
	for (k = 0; k < 9; k++) {
		for (l = 0; l < 9; l++) {
			for (m = 0; m < 9; m++) {
				if (m != l && block[k][l] == block[k][m]) {
					proof = false;
				}
			}
		}
	}

	/*6、根据proof的值，决定矩阵的判断结果*/
	if (proof) {
		cout << "是数独的解" << endl;
	}

	else {
		cout << "不是数独的解" << endl;
	}

	return 0;
}