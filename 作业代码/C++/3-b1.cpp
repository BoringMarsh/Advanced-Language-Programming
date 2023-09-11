/*2151294 信11 马威*/
#include <iostream>
#include<iomanip>
using namespace std;

int main()
{
    const double pi = 3.14159;            /*定义常量pi*/
    double r, h;                          /*定义变量半径r、高度h*/
    cout << "请输入半径和高度" << endl;   /*输出提示语*/
    cin >> r >> h;                        /*输入变量值*/
    cout << setiosflags(ios::fixed);      /*设置浮点数以固定的小数位数显示，为之后结果保留2位小数做铺垫*/

    cout << setw(10) << setiosflags(ios::left) << "圆周长";
    cout << " : " << setprecision(2) << 2 * pi * r << endl;

    cout << setw(10) << setiosflags(ios::left) << "圆面积";
    cout << " : " << setprecision(2) << pi * r * r << endl;

    cout << setw(10) << setiosflags(ios::left) << "圆球表面积";          /*设置总宽度10，左对齐输出提示字，保留2位小数输出各计算结果*/
    cout << " : " << setprecision(2) << 4 * pi * r * r << endl;

    cout << setw(10) << setiosflags(ios::left) << "圆球体积";
    cout << " : " << setprecision(2) << 4.0 / 3.0 * pi * r * r << endl;

    cout << setw(10) << setiosflags(ios::left) << "圆柱体积";
    cout << " : " << setprecision(2) << pi * r * r * h << endl;
    return 0;
}