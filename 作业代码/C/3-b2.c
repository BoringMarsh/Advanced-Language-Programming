/*2151294 信11 马威*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	short i, G, S, B, Q, W;                    /*定义要处理的整数与每个位数*/
	printf("请输入一个[1..30000]间的整数\n");  /*输出提示语*/
	scanf("%hd", &i);                          /*输入变量值，按short形式存储*/

	G = i % 10;
	S = (i % 100 - G) / 10;
	B = (i % 1000 - S * 10 - G) / 100;              /*按整型求模的方法取得各个位数*/
	Q = (i % 10000 - B * 100 - S * 10 - G) / 1000;
	W = (i - i % 10000) / 10000;

	printf("万位 : %hd\n", W);
	printf("千位 : %hd\n", Q);
	printf("百位 : %hd\n", B);  /*输出各个位数的取出结果*/
	printf("十位 : %hd\n", S);
	printf("个位 : %hd\n", G);

	return 0;
}