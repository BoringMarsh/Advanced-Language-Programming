/*2151294 信11 马威*/
#include<iostream>
using namespace std;
int main()
{
	int wan, i, sum, j1, j2;     /*定义所需变量，wan是完数，i是因子，sum是各因子和，j1、j2是因子个数*/

	/*从2到1000，逐个实验wan是否为完数*/
	for (wan = 2; wan <= 1000; wan++) {
		sum = 0;
		j1 = 0;

		/*从1到wan-1，逐个实验i是否为因子，若是，则将其加到sum中，计数器j1自增*/
		for (i = 1; i < wan; i++) {
			if (wan % i == 0) {
				sum = sum + i;
				j1 = j1 + 1;
			}
		}

		/*若各因子和与该数相等，则该数为完数，按照格式输出*/
		if (sum == wan) {
			cout << wan << ",its factors are ";     /*输出提示语*/
			j2 = 1;                                 /*计数器j2初始化为1*/

			/*从1到wan-1，逐个实验i是否为因子，若是，打印因子i，j2自增*/
			for (i = 1; i < wan; i++) {
				if (wan % i == 0 && j2 < j1) {        /*j2<j1，此时打印的不是最后一个因子，打印因子及逗号*/
					cout << i << ",";
					j2 = j2 + 1;
				}

				else if (wan % i == 0 && j2 == j1) {  /*j2=j1，此时打印的是最后一个因子，打印因子及换行符*/
					cout << i << endl;
				}
			}
		}
	}

	return 0;
}