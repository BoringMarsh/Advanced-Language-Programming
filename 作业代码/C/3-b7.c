/*2151294 信11 马威*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	float qian;                                /*定义所需变量，qian是输入值*/
	int money;                                 /*定义所需变量，money是已扩大qian的预处理值*/
	int yuan50, yuan20, yuan10, yuan5, yuan1;  /*定义所需变量，分别是50元、20元、10元、5元、1元的找零数量*/
	int jiao5, jiao1;                          /*定义所需变量，分别是5角、1角的找零数量*/
	int fen5, fen2, fen1;                      /*定义所需变量，分别是5分、2分、1分的找零数量*/
	int total;                                 /*定义所需变量，total是所有面值的找零数量*/
	printf("请输入找零值：\n");                /*输出提示语*/
	scanf("%f", &qian);                        /*输入变量值，按double形式存储*/
	money = (int)((qian + 1e-3) * 100);        /*给输入值加上一个足够小的数，修正误差，并计算扩大x的预处理值，然后转为整型*/

	/*初始：所有面值找零数量为零*/
	yuan50 = 0, yuan20 = 0, yuan10 = 0, yuan5 = 0, yuan1 = 0;
	jiao5 = 0, jiao1 = 0;
	fen5 = 0, fen2 = 0, fen1 = 0;

	/*计算50元的找零数量*/
	if (money < 10000 && money >= 5000) {
		yuan50 = yuan50 + 1;
		money = money - 5000;
	}

	/*计算20元的找零数量*/
	if (money < 5000 && money >= 4000) {
		yuan20 = yuan20 + 2;
		money = money - 4000;
	}

	else if (money < 4000 && money >= 2000) {
		yuan20 = yuan20 + 1;
		money = money - 2000;
	}

	/*计算10元的找零数量*/
	if (money < 2000 && money >= 1000) {
		yuan10 = yuan10 + 1;
		money = money - 1000;
	}

	/*计算5元的找零数量*/
	if (money < 1000 && money >= 500) {
		yuan5 = yuan5 + 1;
		money = money - 500;
	}

	/*计算1元的找零数量*/
	if (money < 500 && money >= 400) {
		yuan1 = yuan1 + 4;
		money = money - 400;
	}

	else if (money < 500 && money >= 300) {
		yuan1 = yuan1 + 3;
		money = money - 300;
	}

	else if (money < 500 && money >= 200) {
		yuan1 = yuan1 + 2;
		money = money - 200;
	}

	else if (money < 500 && money >= 100) {
		yuan1 = yuan1 + 1;
		money = money - 100;
	}

	/*计算5角的找零数量*/
	if (money < 100 && money >= 50) {
		jiao5 = jiao5 + 1;
		money = money - 50;
	}

	/*计算1角的找零数量*/
	if (money < 50 && money >= 40) {
		jiao1 = jiao1 + 4;
		money = money - 40;
	}

	else if (money < 50 && money >= 30) {
		jiao1 = jiao1 + 3;
		money = money - 30;
	}

	else if (money < 50 && money >= 20) {
		jiao1 = jiao1 + 2;
		money = money - 20;
	}

	else if (money < 50 && money >= 10) {
		jiao1 = jiao1 + 1;
		money = money - 10;
	}

	/*计算5分的找零数量*/
	if (money < 10 && money >= 5) {
		fen5 = fen5 + 1;
		money = money - 5;
	}

	/*计算2分的找零数量*/
	if (money < 5 && money >= 4) {
		fen2 = fen2 + 2;
		money = money - 4;
	}

	else if (money < 5 && money >= 2) {
		fen2 = fen2 + 1;
		money = money - 2;
	}

	/*计算1分的找零数量*/
	if (money == 1) {
		fen1 = fen1 + 1;
		money = money - 1;
	}

	total = yuan50 + yuan20 + yuan10 + yuan5 + yuan1 + jiao5 + jiao1 + fen5 + fen2 + fen1;  /*计算所有面值的找零数量*/
	printf("共%d张找零，具体如下：\n", total);                                              /*输出提示语*/

	/*设置总宽度4，左对齐输出提示字，输出各计算结果*/
	if (yuan50 != 0) {
		printf("%-4s", "50元");
		printf(" : %d张\n", yuan50);
	}

	if (yuan20 != 0) {
		printf("%-4s", "20元");
		printf(" : %d张\n", yuan20);
	}

	if (yuan10 != 0) {
		printf("%-4s", "10元");
		printf(" : %d张\n", yuan10);
	}

	if (yuan5 != 0) {
		printf("%-4s", "5元");
		printf(" : %d张\n", yuan5);
	}

	if (yuan1 != 0) {
		printf("%-4s", "1元");
		printf(" : %d张\n", yuan1);
	}

	if (jiao5 != 0) {
		printf("%-4s", "5角");
		printf(" : %d张\n", jiao5);
	}

	if (jiao1 != 0) {
		printf("%-4s", "1角");
		printf(" : %d张\n", jiao1);
	}

	if (fen5 != 0) {
		printf("%-4s", "5分");
		printf(" : %d张\n", fen5);
	}

	if (fen2 != 0) {
		printf("%-4s", "2分");
		printf(" : %d张\n", fen2);
	}

	if (fen1 != 0) {
		printf("%-4s", "1分");
		printf(" : %d张\n", fen1);
	}

	return 0;
}