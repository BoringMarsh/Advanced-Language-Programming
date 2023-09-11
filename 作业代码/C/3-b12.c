/*2151294 信11 马威*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	/*第一部分：日期输入正确性处理*/
	int ret1, ret2, y, m, w;

	/*1、对年月的输入正确性处理*/
	while (1) {
		printf("请输入年份(2000-2030)和月份(1-12) :");
		ret1 = scanf("%d %d", &y, &m);
		if (ret1 == 2 && (y >= 2000 && y <= 2030) && (m >= 1 && m <= 12))
			break;

		/*已读取，超过用户范围时（单个年月或多个年月都可解决）的处理*/
		else if (ret1 == 2 && ((y < 2000 || y > 2030) || (m < 1 || m > 12))) {
			printf("输入非法，请重新输入\n");
			rewind(stdin);
		}

		/*有非法输入读取、超过数据范围时的处理*/
		else if (ret1 == 0 || ret1 == 1) {
			printf("输入非法，请重新输入\n");
			rewind(stdin);
		}
	}

	/*2、对星期的输入正确性处理*/
	while (1) {
		printf("请输入%d年%d月1日的星期(0 - 6表示星期日 - 星期六) : ", y, m);
		ret2 = scanf("%d", &w);
		if (ret2 == 1 && (w >= 0 && w <= 6))
			break;

		/*读取状态正常，超过用户范围时的处理*/
		else if (ret2 == 1 && (w < 0 || w>6)) {
			printf("输入非法，请重新输入\n");
			rewind(stdin);
		}

		/*有非法输入读取、超过数据范围时的处理*/
		else if (ret2 == 0) {
			printf("输入非法，请重新输入\n");
			rewind(stdin);
		}
	}


	/*第二部分：月历打印处理*/
	int j, limit, d1;
	printf("\n%d年%d月的月历为:\n", y, m);
	printf("星期日  星期一  星期二  星期三  星期四  星期五  星期六\n");

	/*1、按照月份确定limit（天数）的值。（2月分是否为闰年讨论）*/
	if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
		limit = 31;

	else if (m == 4 || m == 6 || m == 9 || m == 11)
		limit = 30;

	else if (m == 2) {
		if ((y % 4 == 0) && (y % 100 != 0) || (y % 4 == 0) && (y % 400 == 0))
			limit = 29;

		else
			limit = 28;
	}

	/*2、打印月历，j为第几日，d1为位置参数（d1为7的倍数时换行，d1%7的结果为1时设定输出宽度为4）*/
	d1 = w + 1;

	for (j = 1; j <= limit; j++) {
		if (j == 1) {    /*由于格式化输出printf设置宽度时不能为表达式，故对于w的值分开讨论*/
			if (w == 0)
				printf("%4d", j);
			else if (w == 1)
				printf("%12d", j);
			else if (w == 2)
				printf("%20d", j);
			else if (w == 3)
				printf("%28d", j);
			else if (w == 4)
				printf("%36d", j);
			else if (w == 5)
				printf("%44d", j);
			else if (w == 6)
				printf("%52d", j);
		}

		else if (d1 % 7 == 1) {
			printf("%4d", j);
		}

		else if (j != 1) {
			printf("%8d", j);
		}

		if (d1 % 7 == 0) {
			printf("\n");
		}

		d1++;
	}

	return 0;
}