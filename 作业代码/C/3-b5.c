/*2151294 信11 马威*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int y, m, d;                    /*定义所需变量，y是年份，m是月份，d是日*/
	printf("请输入年，月，日\n");   /*输出提示语*/
	scanf("%d %d %d", &y, &m, &d);  /*输入变量值，按int形式存储*/

	/*取日期完成，下面进行天数转化*/
	/*主要思路：分开各个月处理。*/
	/*若月份不正确，则报错；若月份正确，判断日与月的关系*/
	/*若关系合理，则输出变量d+该月之前的月总天数；若关系非法，则报错*/

	/*闰年的天数转化*/
	if ((y % 4 == 0) && (y % 100 != 0) || (y % 4 == 0) && (y % 400 == 0)) {

		/*闰年1月的天数转化*/
		if (1 == m) {
			if (d <= 31) {
				printf("%d-%d-%d是%d年的第%d天", y, m, d, y, d);
			}

			else {
				printf("输入错误-日与月的关系非法");
			}
		}

		/*闰年2月的天数转化*/
		else if (2 == m) {
			if (d <= 29) {
				printf("%d-%d-%d是%d年的第%d天", y, m, d, y, d + 31);
			}

			else {
				printf("输入错误-日与月的关系非法");
			}
		}

		/*闰年3月的天数转化*/
		else if (3 == m) {
			if (d <= 31) {
				printf("%d-%d-%d是%d年的第%d天", y, m, d, y, d + 60);
			}

			else {
				printf("输入错误-日与月的关系非法");
			}
		}

		/*闰年4月的天数转化*/
		else if (4 == m) {
			if (d <= 30) {
				printf("%d-%d-%d是%d年的第%d天", y, m, d, y, d + 91);
			}

			else {
				printf("输入错误-日与月的关系非法");
			}
		}

		/*闰年5月的天数转化*/
		else if (5 == m) {
			if (d <= 31) {
				printf("%d-%d-%d是%d年的第%d天", y, m, d, y, d + 121);
			}

			else {
				printf("输入错误-日与月的关系非法");
			}
		}

		/*闰年6月的天数转化*/
		else if (6 == m) {
			if (d <= 30) {
				printf("%d-%d-%d是%d年的第%d天", y, m, d, y, d + 152);
			}

			else {
				printf("输入错误-日与月的关系非法");
			}
		}

		/*闰年7月的天数转化*/
		else if (7 == m) {
			if (d <= 31) {
				printf("%d-%d-%d是%d年的第%d天", y, m, d, y, d + 182);
			}

			else {
				printf("输入错误-日与月的关系非法");
			}
		}

		/*闰年8月的天数转化*/
		else if (8 == m) {
			if (d <= 31) {
				printf("%d-%d-%d是%d年的第%d天", y, m, d, y, d + 213);
			}

			else {
				printf("输入错误-日与月的关系非法");
			}
		}

		/*闰年9月的天数转化*/
		else if (9 == m) {
			if (d <= 30) {
				printf("%d-%d-%d是%d年的第%d天", y, m, d, y, d + 244);
			}

			else {
				printf("输入错误-日与月的关系非法");
			}
		}

		/*闰年10月的天数转化*/
		else if (10 == m) {
			if (d <= 31) {
				printf("%d-%d-%d是%d年的第%d天", y, m, d, y, d + 274);
			}

			else {
				printf("输入错误-日与月的关系非法");
			}
		}

		/*闰年11月的天数转化*/
		else if (11 == m) {
			if (d <= 30) {
				printf("%d-%d-%d是%d年的第%d天", y, m, d, y, d + 305);
			}

			else {
				printf("输入错误-日与月的关系非法");
			}
		}

		/*闰年12月的天数转化*/
		else if (12 == m) {
		    if (d <= 31) {
				printf("%d-%d-%d是%d年的第%d天", y, m, d, y, d + 335);
			}

			else {
				printf("输入错误-日与月的关系非法");
			}
        }

		/*闰年不正确月份的报错*/
		else
		    printf("输入错误-月份不正确");
	}

	/*非闰年的天数转化*/
	else {

	    /*非闰年1月的天数转化*/
	    if (1 == m) {
			if (d <= 31) {
				printf("%d-%d-%d是%d年的第%d天", y, m, d, y, d);
			}

			else {
				printf("输入错误-日与月的关系非法");
			}
		}

		/*非闰年2月的天数转化*/
		else if (2 == m) {
			if (d <= 28) {
				printf("%d-%d-%d是%d年的第%d天", y, m, d, y, d + 30);
			}

			else {
				printf("输入错误-日与月的关系非法");
			}
		}

		/*非闰年3月的天数转化*/
		else if (3 == m) {
			if (d <= 31) {
				printf("%d-%d-%d是%d年的第%d天", y, m, d, y, d + 59);
			}

			else {
				printf("输入错误-日与月的关系非法");
			}
		}

		/*非闰年4月的天数转化*/
		else if (4 == m) {
			if (d <= 30) {
				printf("%d-%d-%d是%d年的第%d天", y, m, d, y, d + 90);
			}

			else {
				printf("输入错误-日与月的关系非法");
			}
		}

		/*非闰年5月的天数转化*/
		else if (5 == m) {
			if (d <= 31) {
				printf("%d-%d-%d是%d年的第%d天", y, m, d, y, d + 120);
			}

			else {
				printf("输入错误-日与月的关系非法");
			}
		}

		/*非闰年6月的天数转化*/
		else if (6 == m) {
			if (d <= 30) {
				printf("%d-%d-%d是%d年的第%d天", y, m, d, y, d + 151);
			}

			else {
				printf("输入错误-日与月的关系非法");
			}
		}

		/*非闰年7月的天数转化*/
		else if (7 == m) {
			if (d <= 31) {
				printf("%d-%d-%d是%d年的第%d天", y, m, d, y, d + 181);
			}

			else {
				printf("输入错误-日与月的关系非法");
			}
		}

		/*非闰年8月的天数转化*/
		else if (8 == m) {
			if (d <= 31) {
				printf("%d-%d-%d是%d年的第%d天", y, m, d, y, d + 212);
			}

			else {
				printf("输入错误-日与月的关系非法");
			}
		}

		/*非闰年9月的天数转化*/
		else if (9 == m) {
			if (d <= 30) {
				printf("%d-%d-%d是%d年的第%d天", y, m, d, y, d + 243);
			}

			else {
				printf("输入错误-日与月的关系非法");
			}
		}

		/*非闰年10月的天数转化*/
		else if (10 == m) {
			if (d <= 31) {
				printf("%d-%d-%d是%d年的第%d天", y, m, d, y, d + 273);
			}

			else {
				printf("输入错误-日与月的关系非法");
			}
		}

		/*非闰年11月的天数转化*/
		else if (11 == m) {
			if (d <= 30) {
				printf("%d-%d-%d是%d年的第%d天", y, m, d, y, d + 304);
			}

			else {
				printf("输入错误-日与月的关系非法");
			}
		}

		/*非闰年12月的天数转化*/
		else if (12 == m) {
		    if (d <= 31) {
				printf("%d-%d-%d是%d年的第%d天", y, m, d, y, d + 334);
			}

			else {
				printf("输入错误-日与月的关系非法");
			}
        }

		/*非闰年不正确月份的报错*/
		else
		    printf("输入错误-月份不正确");
	}

	return 0;
}