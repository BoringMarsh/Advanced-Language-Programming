/*2151294 信11 马威*/
#include<iostream>
#include<cmath>  /*由于需使用正弦函数sin(x)，故include此头文件*/
#include<iomanip>
using namespace std;

int main()
{
	const float pi = 3.14159f;  /*定义常量pi*/
	int l, w, angle;            /*定义变量一边长l，另一边长w，两者夹角angle（角度制）*/
	float S, rad;               /*定义变量三角形的面积S、两者夹角rad（弧度制）*/

	cout << "请输入三角形的两边及其夹角(角度)" << endl;  /*输出提示语*/
	cin >> l >> w >> angle;                              /*输入变量值*/
	rad = angle / 180.0f * pi;                           /*计算夹角对应的弧度*/
	S = 1.0f / 2.0f * l * w * sin(rad);                  /*利用三角形的面积公式求解面积*/
	cout << "三角形面积为 : " << setiosflags(ios::fixed) << setprecision(3) << S << endl;  /*设置总宽度10，左对齐输出提示字，保留3位小数输出计算结果*/

	return 0;
}