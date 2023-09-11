/*2151294 信11 马威*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	double i, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10;  /*定义所需变量，i是已修正误差的预处理值，i1是输入值，i2至i10是各个位数*/
	double x, X, x3, x2, x1;                            /*定义所需变量，x是输入值中的个位至百分位的部分，X是已扩大x的预处理值，x3至x1是各个位数*/
	printf("请输入[0-100亿)之间的数字:\n");             /*输出提示语*/
	scanf("%lf", &i1);                                  /*输入变量值*/
	i = i1 + 1e-3;                                      /*给输入值加上一个足够小的数，修正误差*/

	/*将预处理值适当缩小取整，借此取得各个位数，然而（i / 1e+0）可能会超出int范围而产生错误，故该方法只能取到十位，无法取到个位*/
	i10 = (int)(i / 1e+9);  /*取十亿位*/
	i9 = (int)(i / 1e+8) - i10 * 1e+1;  /*取亿位*/
	i8 = (int)(i / 1e+7) - i10 * 1e+2 - i9 * 1e+1;  /*取千万位*/
	i7 = (int)(i / 1e+6) - i10 * 1e+3 - i9 * 1e+2 - i8 * 1e+1;  /*取百万位*/
	i6 = (int)(i / 1e+5) - i10 * 1e+4 - i9 * 1e+3 - i8 * 1e+2 - i7 * 1e+1;  /*取十万位*/
	i5 = (int)(i / 1e+4) - i10 * 1e+5 - i9 * 1e+4 - i8 * 1e+3 - i7 * 1e+2 - i6 * 1e+1;  /*取万位*/
	i4 = (int)(i / 1e+3) - i10 * 1e+6 - i9 * 1e+5 - i8 * 1e+4 - i7 * 1e+3 - i6 * 1e+2 - i5 * 1e+1;  /*取千位*/
	i3 = (int)(i / 1e+2) - i10 * 1e+7 - i9 * 1e+6 - i8 * 1e+5 - i7 * 1e+4 - i6 * 1e+3 - i5 * 1e+2 - i4 * 1e+1;  /*取百位*/
	i2 = (int)(i / 1e+1) - i10 * 1e+8 - i9 * 1e+7 - i8 * 1e+6 - i7 * 1e+5 - i6 * 1e+4 - i5 * 1e+3 - i4 * 1e+2 - i3 * 1e+1;  /*取十位*/

	x = i - i10 * 1e+9 - i9 * 1e+8 - i8 * 1e+7 - i7 * 1e+6 - i6 * 1e+5 - i5 * 1e+4 - i4 * 1e+3 - i3 * 1e+2 - i2 * 1e+1;  /*借助取得的位数计算输入值中的个位至百分位的部分*/
	X = x * 100.0;  /*计算扩大x的预处理值*/
	x3 = (int)(X / 1e+2);  /*取个位*/
	x2 = (int)(X / 1e+1) - x3 * 1e+1;  /*取十分位*/
	x1 = (int)(X) - x3 * 1e+2 - x2 * 1e+1;  /*取百分位*/

	printf("大写结果是:\n");  /*输出提示语*/

	/*取位数完成，下面进行人民币大写转化*/
	/*主要思路：分开各个位处理。*/
	/*每一位非零时按对应的数输出*/
	/*每一位为零时，若该位以前的位全为零，则该位也不输出；若该位以前的位不全为零，则看该位是否需要在这一位读出"零"，需要则输出；仍不需要就先不输出，把输出"零"的任务交给下一位处理*/

	/*十亿位输出的格式处理*/
	switch ((int)(i10)) {
		case 9:
			printf("玖拾");
			break;
		case 8:
			printf("捌拾");
			break;
		case 7:
			printf("柒拾");
			break;
		case 6:
			printf("陆拾");
			break;
		case 5:
			printf("伍拾");
			break;
		case 4:
			printf("肆拾");
			break;
		case 3:
			printf("叁拾");
			break;
		case 2:
			printf("贰拾");
			break;
		case 1:
			printf("壹拾");
			break;
		case 0:
			printf("");
			break;
	}

	/*亿位输出的格式处理*/
	switch ((int)(i9)) {
		case 9:
			printf("玖亿");
			break;
		case 8:
			printf("捌亿");
			break;
		case 7:
			printf("柒亿");
			break;
		case 6:
			printf("陆亿");
			break;
		case 5:
			printf("伍亿");
			break;
		case 4:
			printf("肆亿");
			break;
		case 3:
			printf("叁亿");
			break;
		case 2:
			printf("贰亿");
			break;
		case 1:
			printf("壹亿");
			break;
		case 0:
			if (i10 == 0) {
				printf("");
			}

			else {
				printf("亿");
			}

		break;
	}

	/*千万位输出的格式处理*/
	switch ((int)(i8)) {
		case 9:
			printf("玖仟");
			break;
		case 8:
			printf("捌仟");
			break;
		case 7:
			printf("柒仟");
			break;
		case 6:
			printf("陆仟");
			break;
		case 5:
			printf("伍仟");
			break;
		case 4:
			printf("肆仟");
			break;
		case 3:
			printf("叁仟");
			break;
		case 2:
			printf("贰仟");
			break;
		case 1:
			printf("壹仟");
			break;
		case 0:
			if (i9 == 0 && i10 == 0) {
				printf("");
			}

			else {
				if (i7 == 0) {
					printf("");
				}

				else {
					printf("零");
				}
			}

		break;
	}

	/*百万位输出的格式处理*/
	switch ((int)(i7)) {
		case 9:
			printf("玖佰");
			break;
		case 8:
			printf("捌佰");
			break;
		case 7:
			printf("柒佰");
			break;
		case 6:
			printf("陆佰");
			break;
		case 5:
			printf("伍佰");
			break;
		case 4:
			printf("肆佰");
			break;
		case 3:
			printf("叁佰");
			break;
		case 2:
			printf("贰佰");
			break;
		case 1:
			printf("壹佰");
			break;
		case 0:
			if (i10 == 0 && i9 == 0 && i8 == 0) {
				printf("");
			}

			else {
				if (i6 == 0) {
					printf("");
				}

				else {
					printf("零");
				}
			}

		break;
	}

	/*十万位输出的格式处理*/
	switch ((int)(i6)) {
		case 9:
			printf("玖拾");
			break;
		case 8:
			printf("捌拾");
			break;
		case 7:
			printf("柒拾");
			break;
		case 6:
			printf("陆拾");
			break;
		case 5:
			printf("伍拾");
			break;
		case 4:
			printf("肆拾");
			break;
		case 3:
			printf("叁拾");
			break;
		case 2:
			printf("贰拾");
			break;
		case 1:
			printf("壹拾");
			break;
		case 0:
			if (i10 == 0 && i9 == 0 && i8 == 0 && i7 == 0) {
				printf("");
			}

			else {
				if (i5 == 0) {
					printf("");
				}

				else {
					printf("零");
				}
			}

		break;
	}

	/*万位输出的格式处理*/
	switch ((int)(i5)) {
		case 9:
			printf("玖万");
			break;
		case 8:
			printf("捌万");
			break;
		case 7:
			printf("柒万");
			break;
		case 6:
			printf("陆万");
			break;
		case 5:
			printf("伍万");
			break;
		case 4:
			printf("肆万");
			break;
		case 3:
			printf("叁万");
			break;
		case 2:
			printf("贰万");
			break;
		case 1:
			printf("壹万");
			break;
		case 0:
			if (i10 == 0 && i9 == 0 && i8 == 0 && i7 == 0 && i6 == 0) {
				printf("");
			}

			else {
				if (i8 == 0 && i7 == 0 && i6 == 0) {
					printf("");
				}

				else {
					printf("万");
				}
			}

		break;
	}

	/*千位输出的格式处理*/
	switch ((int)(i4)) {
		case 9:
			printf("玖仟");
			break;
		case 8:
			printf("捌仟");
			break;
		case 7:
			printf("柒仟");
			break;
		case 6:
			printf("陆仟");
			break;
		case 5:
			printf("伍仟");
			break;
		case 4:
			printf("肆仟");
			break;
		case 3:
			printf("叁仟");
			break;
		case 2:
			printf("贰仟");
			break;
		case 1:
			printf("壹仟");
			break;
		case 0:
			if (i10 == 0 && i9 == 0 && i8 == 0 && i7 == 0 && i6 == 0 && i5 == 0) {
				printf("");
			}

			else {
				if (i3 == 0) {
					printf("");
				}

				else {
					printf("零");
				}
			}

		break;
	}

	/*百位输出的格式处理*/
	switch ((int)(i3)) {
		case 9:
			printf("玖佰");
			break;
		case 8:
			printf("捌佰");
			break;
		case 7:
			printf("柒佰");
			break;
		case 6:
			printf("陆佰");
			break;
		case 5:
			printf("伍佰");
			break;
		case 4:
			printf("肆佰");
			break;
		case 3:
			printf("叁佰");
			break;
		case 2:
			printf("贰佰");
			break;
		case 1:
			printf("壹佰");
			break;
		case 0:
			if (i10 == 0 && i9 == 0 && i8 == 0 && i7 == 0 && i6 == 0 && i5 == 0 && i4 == 0) {
				printf("");
			}

			else {
				if (i2 == 0) {
					printf("");
				}

				else {
					printf("零");
				}
			}

		break;
	}

	/*十位输出的格式处理*/
	switch ((int)(i2)) {
		case 9:
			printf("玖拾");
			break;
		case 8:
			printf("捌拾");
			break;
		case 7:
			printf("柒拾");
			break;
		case 6:
			printf("陆拾");
			break;
		case 5:
			printf("伍拾");
			break;
		case 4:
			printf("肆拾");
			break;
		case 3:
			printf("叁拾");
			break;
		case 2:
			printf("贰拾");
			break;
		case 1:
			printf("壹拾");
			break;
		case 0:
			if (i10 == 0 && i9 == 0 && i8 == 0 && i7 == 0 && i6 == 0 && i5 == 0 && i4 == 0 && i3 == 0) {
				printf("");
			}

			else {
				if (x3 == 0) {
					printf("");
				}

				else {
					printf("零");
				}
			}

		break;
	}

	/*个位输出的格式处理*/
	switch ((int)(x3)) {
		case 9:
			printf("玖圆");
			break;
		case 8:
			printf("捌圆");
			break;
		case 7:
			printf("柒圆");
			break;
		case 6:
			printf("陆圆");
			break;
		case 5:
			printf("伍圆");
			break;
		case 4:
			printf("肆圆");
			break;
		case 3:
			printf("叁圆");
			break;
		case 2:
			printf("贰圆");
			break;
		case 1:
			printf("壹圆");
			break;
		case 0:
			if (i10 == 0 && i9 == 0 && i8 == 0 && i7 == 0 && i6 == 0 && i5 == 0 && i4 == 0 && i3 == 0 && i2 == 0) {
				printf("");
			}

			else {
				printf("圆");
			}

		break;
	}

	/*第一个"整"输出的格式处理*/
	if (x2 == 0 && x1 == 0) {
		if (i10 == 0 && i9 == 0 && i8 == 0 && i7 == 0 && i6 == 0 && i5 == 0 && i4 == 0 && i3 == 0 && i2 == 0 && x3 == 0) {
			printf("");
		}

		else {
			printf("整");
		}
	}

	/*十分位输出的格式处理*/
	switch ((int)(x2)) {
		case 9:
			printf("玖角");
			break;
		case 8:
			printf("捌角");
			break;
		case 7:
			printf("柒角");
			break;
		case 6:
			printf("陆角");
			break;
		case 5:
			printf("伍角");
			break;
		case 4:
			printf("肆角");
			break;
		case 3:
			printf("叁角");
			break;
		case 2:
			printf("贰角");
			break;
		case 1:
			printf("壹角");
			break;
		case 0:
			if (i10 == 0 && i9 == 0 && i8 == 0 && i7 == 0 && i6 == 0 && i5 == 0 && i4 == 0 && i3 == 0 && i2 == 0 && x3 == 0) {
				printf("");
			}

			else {
				if (x1 == 0) {
					printf("");
				}

				else {
					printf("零");
				}
			}

		break;
	}

	/*第二个"整"输出的格式处理*/
	if (x2 != 0 && x1 == 0) {
		printf("整");
	}

	/*百分位输出的格式处理*/
	switch ((int)(x1)) {
		case 9:
			printf("玖分");
			break;
		case 8:
			printf("捌分");
			break;
		case 7:
			printf("柒分");
			break;
		case 6:
			printf("陆分");
			break;
		case 5:
			printf("伍分");
			break;
		case 4:
			printf("肆分");
			break;
		case 3:
			printf("叁分");
			break;
		case 2:
			printf("贰分");
			break;
		case 1:
			printf("壹分");
			break;
		case 0:
			if (i10 == 0 && i9 == 0 && i8 == 0 && i7 == 0 && i6 == 0 && i5 == 0 && i4 == 0 && i3 == 0 && i2 == 0 && x3 == 0 && x2 == 0) {
				printf("零圆整");
			}

			else {
				printf("");
			}

		break;
	}

	printf("\n");  /*输出完毕后的换行符*/

	return 0;
}