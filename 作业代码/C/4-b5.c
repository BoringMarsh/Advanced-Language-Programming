/*2151294 信11 马威*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/* ----具体要求----
   1、不允许添加其它头文件
   2、不允许定义全局变量、静态局部变量
   3、不允许添加其它函数
   4、整个程序不允许出现任何形式的循环
   --------------------------------------------------------------------- */

   /***************************************************************************
	 函数名称：
	 功    能：返回n的阶乘
	 输入参数：
	 返 回 值：
	 说    明：函数名、形参、返回类型均不准动
   ***************************************************************************/
int fac(int n)
{
	int result;     /*定义所需变量，result是最后的返回值*/
	if (n > 1) {    /*若n不为1，递归调用fac(n-1)，使result等于fac(n-1)乘以n*/
		result = fac(n - 1) * n;
	}

	else {          /*若n为1，fac(1)返回值为1*/
		return 1;
	}
	return result;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：完成输入、调用递归函数、输出
***************************************************************************/
int main()
{
	printf("计算a!+b!+c!，请输入a,b,c的值(非负整数)\n");       /*输出提示语*/
	int a, b, c;                                                   /*定义所需变量，a、b、c是三个变量*/
	scanf("%d %d %d", &a, &b, &c);                                 /*输入a、b、c*/
	printf("%d!+%d!+%d!=%d\n", a, b, c, fac(a) + fac(b) + fac(c)); /*按格式输出结果*/
	return 0;
}