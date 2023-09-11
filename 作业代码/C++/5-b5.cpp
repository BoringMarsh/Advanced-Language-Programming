/*2151294 信11 马威*/
#include<iostream>
using namespace std;
int main()
{
	int score[1000], number[101];  /*定义所需数组与变量，score[1000]为分数数组，number[101]为计数数组*/
	int i, j, limit, rank;         /*定义所需变量，limit为数组中数据的个数，rank为累计排名*/
	cout << "请输入成绩（最多1000个），以-1结束" << endl;

	/*1、0到100分人数初始状态为0，赋值为0*/
	for (i = 0; i <= 100; i++) {
		number[i] = 0;
	}

	/*2、通过输入给数组赋值，若输入负数，则直接结束输入过程*/
	for (i = 0; i <= 999; i++) {
		cin >> score[i];
		if (score[i] < 0) {
			break;
		}
	}

	/*3、由于i在循环执行时多加了1，故减1后在赋给limit，然后清空缓冲区*/
	limit = i - 1;
	cin.clear();
	cin.ignore(INT_MAX, '\n');

	/*4、若数组第一个数为负，则输出提示后直接结束程序；若为正则继续*/
	if (score[0] > 0) {

		/*4.1、输出原数组，计数器为10的倍数的时候换行*/
		cout << "输入的数组为:" << endl;

		for (i = 0; i <= limit; i++) {
			cout << score[i] << " ";
			if ((i + 1) % 10 == 0) {
				cout << endl;
			}
		}

		/*换行的处理，使得无论哪种情况最后只换一次行*/
		if (i % 10 == 0) {
			cout << "";
		}

		else {
			cout << endl;
		}

		/*4.2、从0分到100分，将分数与所有数据匹配，每匹配成一个数据，number[i]自增*/
		cout << "分数与名次的对应关系为:" << endl;
		for (i = 0; i <= 100; i++) {
			for (j = 0; j <= limit; j++) {
				if (score[j] == i) {
					number[i] = number[i] + 1;
				}
			}
		}

		/*4.3、降序打印分数与名次，名次赋初值为1，若该分数的人数为0则不输出；若不为0，按照人数循环输出分数与名次，再将number[i]累加到名次上*/
		rank = 1;

		for (i = 100; i >= 0; i--) {
			if (number[i] == 0) {
				continue;
			}

			else {
				for (j = 1; j <= number[i]; j++) {
					cout << i << " " << rank << endl;
				}
			}

			rank = rank + number[i];
		}
	}

	else {
		cout << "无有效输入" << endl;
	}

	return 0;
}