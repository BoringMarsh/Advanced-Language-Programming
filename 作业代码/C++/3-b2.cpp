/*2151294 信11 马威*/
#include<iostream>
using namespace std;

int main()
{
	short i, G, S, B, Q, W;                           /*定义要处理的整数与每个位数*/
	cout << "请输入一个[1..30000]间的整数:" << endl;  /*输出提示语*/
	cin >> i;                                         /*输入变量值*/

	G = i % 10;
	S = (i % 100 - G) / 10;
	B = (i % 1000 - S * 10 - G) / 100;              /*按整型求模的方法取得各个位数*/
	Q = (i % 10000 - B * 100 - S * 10 - G) / 1000;
	W = (i - i % 10000) / 10000;

	cout << "万位 : " << W << endl;
	cout << "千位 : " << Q << endl;
	cout << "百位 : " << B << endl;  /*输出各个位数的取出结果*/
	cout << "十位 : " << S << endl;
	cout << "个位 : " << G << endl;

	return 0;
}