/*2151294 信11 马威*/
#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	double i, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10;  /*定义所需变量，i是已修正误差的预处理值，i1是输入值，i2至i10是各个位数*/
	double x, X, x3, x2, x1;                            /*定义所需变量，x是输入值中的个位至百分位的部分，X是已扩大x的预处理值，x3至x1是各个位数*/
	cout << "请输入[0..100 亿)之间的数字 : " << endl;   /*输出提示语*/
	cin >> i1;                                          /*输入变量值*/
	i = i1 + 1e-3;                                      /*给输入值加上一个足够小的数，修正误差*/

	/*将预处理值适当缩小取整，借此取得各个位数，然而（i / 1e+0）可能会超出int范围而产生错误，故该方法只能取到十位，无法取到个位*/
	i10 = int(i / 1e+9);  /*取十亿位*/
	i9 = int(i / 1e+8) - i10 * 1e+1;  /*取亿位*/
	i8 = int(i / 1e+7) - i10 * 1e+2 - i9 * 1e+1;  /*取千万位*/
	i7 = int(i / 1e+6) - i10 * 1e+3 - i9 * 1e+2 - i8 * 1e+1;  /*取百万位*/
	i6 = int(i / 1e+5) - i10 * 1e+4 - i9 * 1e+3 - i8 * 1e+2 - i7 * 1e+1;  /*取十万位*/
	i5 = int(i / 1e+4) - i10 * 1e+5 - i9 * 1e+4 - i8 * 1e+3 - i7 * 1e+2 - i6 * 1e+1;  /*取万位*/
	i4 = int(i / 1e+3) - i10 * 1e+6 - i9 * 1e+5 - i8 * 1e+4 - i7 * 1e+3 - i6 * 1e+2 - i5 * 1e+1;  /*取千位*/
	i3 = int(i / 1e+2) - i10 * 1e+7 - i9 * 1e+6 - i8 * 1e+5 - i7 * 1e+4 - i6 * 1e+3 - i5 * 1e+2 - i4 * 1e+1;  /*取百位*/
	i2 = int(i / 1e+1) - i10 * 1e+8 - i9 * 1e+7 - i8 * 1e+6 - i7 * 1e+5 - i6 * 1e+4 - i5 * 1e+3 - i4 * 1e+2 - i3 * 1e+1;  /*取十位*/

	x = i - i10 * 1e+9 - i9 * 1e+8 - i8 * 1e+7 - i7 * 1e+6 - i6 * 1e+5 - i5 * 1e+4 - i4 * 1e+3 - i3 * 1e+2 - i2 * 1e+1;  /*借助取得的位数计算输入值中的个位至百分位的部分*/
	X = x * 100.0;  /*计算扩大x的预处理值*/
	x3 = int(X / 1e+2);  /*取个位*/
	x2 = int(X / 1e+1) - x3 * 1e+1;  /*取十分位*/
	x1 = int(X) - x3 * 1e+2 - x2 * 1e+1;  /*取百分位*/

	/*设置总宽度6，左对齐输出提示字，输出各个位数的取出结果*/
	cout << setw(6) << setiosflags(ios::left) << "十亿位";
	cout << " : " << i10 << endl;

	cout << setw(6) << setiosflags(ios::left) << "亿位";
	cout << " : " << i9 << endl;

	cout << setw(6) << setiosflags(ios::left) << "千万位";
	cout << " : " << i8 << endl;

	cout << setw(6) << setiosflags(ios::left) << "百万位";
	cout << " : " << i7 << endl;

	cout << setw(6) << setiosflags(ios::left) << "十万位";
	cout << " : " << i6 << endl;

	cout << setw(6) << setiosflags(ios::left) << "万位";
	cout << " : " << i5 << endl;

	cout << setw(6) << setiosflags(ios::left) << "千位";
	cout << " : " << i4 << endl;

	cout << setw(6) << setiosflags(ios::left) << "百位";
	cout << " : " << i3 << endl;

	cout << setw(6) << setiosflags(ios::left) << "十位";
	cout << " : " << i2 << endl;

	cout << setw(6) << setiosflags(ios::left) << "圆";
	cout << " : " << x3 << endl;

	cout << setw(6) << setiosflags(ios::left) << "角";
	cout << " : " << x2 << endl;

	cout << setw(6) << setiosflags(ios::left) << "分";
	cout << " : " << x1 << endl;

	return 0;
}