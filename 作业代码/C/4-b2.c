/*2151294 信11 马威*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

/*定义zeller公式*/
int zeller(int y, int m, int d)
{
	int W, w, c;     /*定义所需变量，W是通过算式算出来的所谓w值，w是W处理后的真正表示星期的数，c是年份的前两位*/

	if (m == 1 || m == 2) {     /*如果月份为1、2月，按上一年的13、14月处理*/
		m = m + 12;
		y = y - 1;
	}

	c = (y - y % 100) / 100;     /*取年份前两位*/
	y = y % 100;                 /*取年份后两位*/
	W = y + (int)(y / 4) + (int)(c / 4) - 2 * c + (int)(13 * (m + 1) / 5) + d - 1;     /*用算式算出W*/

	while (W < 0) {     /*若W为负数，反复加7直到其为正数为止*/
		W = W + 7;
	}

	w = W % 7;     /*用处理后的W除以7取余数，得到真正的w值*/
	return w;
}

int main()
{
	int y, m, d, w, limit, ret;     /*定义所需变量，y是年份，m是月份，d是日，w是星期值，limit是根据y、m推断出来的月天数，ret是scanf返回值*/
	/*第一部分：日期输入正确性处理*/
	while (1) {
		printf("请输入年[1900-2100]、月、日：\n");
		ret = scanf("%d %d %d", &y, &m, &d);

		/*有非法输入读取时的处理*/
		if (ret != 3) {
			printf("输入错误，请重新输入\n");
			scanf("%*[^\n]%*c");
		}

		/*读取状态正常，超过范围（用户或类型）时的处理*/
		else {
			/*年份超用户范围时的处理*/
		    if (y < 1900 || y>2100) {
				printf("年份不正确，请重新输入\n");
				scanf("%*[^\n]%*c");
			}

			/*月份超用户范围时的处理*/
			else if (m < 1 || m>12) {
				printf("月份不正确，请重新输入\n");
				scanf("%*[^\n]%*c");
			}

			/*日超用户范围时的处理*/
			else {
				/*根据y、m确定该月的天数*/
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

				/*如果日超用户范围，则提示重新输入*/
				if (d<1 || d>limit) {
					printf("日不正确，请重新输入\n");
					scanf("%*[^\n]%*c");
				}
			}

			/*若读取状态正常，且所有数据范围合理，则跳出循环*/
			if ((y >= 1900 && y <= 2100) && (m >= 1 && m <= 12) && (d >= 1 && d <= limit)) {
				break;
			}
		}
	}

	/*第二部分：星期打印处理*/
	w = zeller(y, m, d);     /*使用zeller公式，将日期转变而来的星期值赋给变量w*/
	printf("星期");
	switch (w) {     /*根据星期值w，输出日期对应的星期以及换行符*/
	case 0:
		printf("日\n");
		break;
	case 1:
		printf("一\n");
		break;
	case 2:
		printf("二\n");
		break;
	case 3:
		printf("三\n");
		break;
	case 4:
		printf("四\n");
		break;
	case 5:
		printf("五\n");
		break;
	case 6:
		printf("六\n");
		break;
	}

	return 0;
}