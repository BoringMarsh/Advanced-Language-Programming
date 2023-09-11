/*2151294 信11 马威*/
#include<iostream>
using namespace std;
int main()
{
	int a[20], b, i, j, limit;     /*定义所需数组与变量，a[20]为数组，b为待插入的正整数，limit为数组中数据的个数*/
	cout << "请输入任意个正整数（升序，最多20个），以-1结束" << endl;

	/*1、通过输入给数组赋值，若输入负数，则直接结束输入过程*/
	for (i = 0; i <= 19; i++) {
		cin >> a[i];
		if (a[i] < 0) {
			break;
		}
	}

	/*2、由于i在循环执行时多加了1，故减1后在赋给limit，然后清空缓冲区*/
	limit = i - 1;
	cin.clear();
	cin.ignore(INT_MAX, '\n');

	/*3、若数组第一个数为负，则输出提示后直接结束程序；若为正则继续*/
	if (a[0] >= 0) {

		/*3.1、输出原数组*/
		cout << "原数组为：" << endl;

		for (i = 0; i <= limit; i++) {
			cout << a[i] << " ";
		}
		cout << endl;

		/*3.2、输入待插入的正整数*/
		cout << "请输入要插入的正整数" << endl;
		cin >> b;

		/*3.3、输出插入后的数组*/
		cout << "插入后的数组为：" << endl;

		/*若a[i]小于等于b，先输出a[i]；若a[i]大于b，先输出b并结束循环*/
		for (i = 0; i <= limit; i++) {
			if (a[i] <= b) {
				cout << a[i] << " ";
			}

			else {
				cout << b << " ";
				break;
			}
		}

		/*由于上面的循环，变量i的值记录了b插入的位置，将其赋给j，接着输出后面的变量*/
		for (j = i; j <= limit; j++) {
			cout << a[j] << " ";
		}
		cout << endl;
	}

	else {
		cout << "无有效输入" << endl;
	}

	return 0;
}