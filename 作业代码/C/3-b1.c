/*2151294 信11 马威*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    const double pi = 3.14159;    /*定义常量pi*/
    double r, h;                  /*定义变量半径r、高度h*/
    printf("请输入半径和高度\n"); /*输出提示语*/
    scanf("%lf %lf", &r, &h);     /*输入变量值，按double形式存储*/

    printf("圆周长     : %.2lf\n", 2 * pi * r);
    printf("圆面积     : %.2lf\n", pi * r * r);
    printf("圆球表面积 : %.2lf\n", 4 * pi * r * r);          /*按指定形式（double型保留2位小数）输出各计算结果*/
    printf("圆球体积   : %.2lf\n", 4.0 / 3.0 * pi * r * r);
    printf("圆柱体积   : %.2lf\n", pi * r * r * h);

    return 0;
}