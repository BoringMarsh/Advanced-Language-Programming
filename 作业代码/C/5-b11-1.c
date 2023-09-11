/*2151294 信11 马威*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//可按需增加需要的头文件

const char chnstr[] = "零壹贰叁肆伍陆柒捌玖"; /* 所有输出大写 "零" ~ "玖" 的地方，只允许从这个数组中取值 */
char result[256];  /* 除result外，不再允许定义任何形式的全局变量 */

const char otherstr[] = "拾佰仟万亿圆角分整";

/* --允许添加需要的函数 --*/

/***************************************************************************
  函数名称：daxie
  功    能：根据这一位的数值及单位，将这一位转大写结果添加至result上
  输入参数：int m：数值
            int n：单位
			int p：指针
  返 回 值：int p+2：将指针向后移2得到的指针值
  说    明：1、此为第1个添加函数
            2、每赋值完一次，指针值自增，通过返回值将最终的指针值赋回给指针变量
			3、“指针变量”只是一个主函数中的int型局部变量！
			4、chnstr[]="零壹贰叁肆伍陆柒捌玖"
			5、otherstr[]="拾佰仟万亿圆角分整"
***************************************************************************/
int daxie(int m, int n, int p)
{
	result[p] = chnstr[2 * m];
	result[p + 1] = chnstr[2 * m + 1];

	p = p + 2;

	result[p] = otherstr[2 * n];
	result[p + 1] = otherstr[2 * n + 1];

	return p + 2;
}

/***************************************************************************
  函数名称：add_zero
  功    能：将"零"添加至result上
  输入参数：int p：指针
  返 回 值：int p+2：将指针向后移2得到的指针值
  说    明：1、此为第2个添加函数
			2、中文字符为全角，一次需添加两个字符
			3、每赋值完一次，指针值自增，通过返回值将最终的指针值赋回给指针变量
			4、“指针变量”只是一个主函数中的int型局部变量！
***************************************************************************/
int add_zero(int p)
{
	result[p] = chnstr[0];
	result[p + 1] = chnstr[1];
	return p + 2;
}

/***************************************************************************
  函数名称：add_other
  功    能：将数字以外的其他字单独添加至result上
  输入参数：int n：其他字编号
            int p：指针
  返 回 值：int p+2：将指针向后移2得到的指针值
  说    明：1、此为第3个添加函数
			2、中文字符为全角，一次需添加两个字符
			3、每赋值完一次，指针值自增，通过返回值将最终的指针值赋回给指针变量
			4、“指针变量”只是一个主函数中的int型局部变量！
			5、otherstr[]="拾佰仟万亿圆角分整"
***************************************************************************/
int add_other(int n, int p)
{
	result[p] = otherstr[2 * n];
	result[p + 1] = otherstr[2 * n + 1];
	return p + 2;
}

int main()
{
    /* --允许添加需要的内容 --*/
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

	int p = 0;  /*定义所需变量，p是指针变量，指示字符数组栈顶位置+1*/

	/*使用方法：先调用各类函数，将p单项传值过去，再将函数返回值设为操作结束后p的值，重新赋值给p*/

	/*十亿位输出的格式处理*/
	if ((int)(i10)) {
		p = daxie((int)(i10), 0, p);
	}

	/*亿位输出的格式处理*/
	if ((int)(i9)) {
		p = daxie((int)(i9), 4, p);
	}

	else {
		if (i10 == 0) {}

		else {
			p = add_other(4, p);
		}
	}

	/*千万位输出的格式处理*/
	if ((int)(i8)) {
		p = daxie((int)(i8), 2, p);
	}

	else {
		if (i9 == 0 && i10 == 0) {}

		else {
			if (i7 == 0) {}

			else {
				p = add_zero(p);
			}
		}
	}

	/*百万位输出的格式处理*/
	if ((int)(i7)) {
		p = daxie((int)(i7), 1, p);
	}

	else {
		if (i10 == 0 && i9 == 0 && i8 == 0) {}

		else {
			if (i6 == 0) {}

			else {
				p = add_zero(p);
			}
		}
	}

	/*十万位输出的格式处理*/
	if ((int)(i6)) {
		p = daxie((int)(i6), 0, p);
	}

	else {
		if (i10 == 0 && i9 == 0 && i8 == 0 && i7 == 0) {}

		else {
			if (i5 == 0) {}

			else {
				p = add_zero(p);
			}
		}
	}

	/*万位输出的格式处理*/
	if ((int)(i5)) {
		p = daxie((int)(i5), 3, p);
	}

	else {
		if (i10 == 0 && i9 == 0 && i8 == 0 && i7 == 0 && i6 == 0) {}

		else {
			if (i8 == 0 && i7 == 0 && i6 == 0) {}

			else {
				p = add_other(3, p);
			}
		}
	}

	/*千位输出的格式处理*/
	if ((int)(i4)) {
		p = daxie((int)(i4), 2, p);
	}

	else {
		if (i10 == 0 && i9 == 0 && i8 == 0 && i7 == 0 && i6 == 0 && i5 == 0) {}

		else {
			if (i3 == 0) {}

			else {
				p = add_zero(p);
			}
		}
	}

	/*百位输出的格式处理*/
	if ((int)(i3)) {
		p = daxie((int)(i3), 1, p);
	}

	else {
		if (i10 == 0 && i9 == 0 && i8 == 0 && i7 == 0 && i6 == 0 && i5 == 0 && i4 == 0) {}

		else {
			if (i2 == 0) {}

			else {
				p = add_zero(p);
			}
		}
	}

	/*十位输出的格式处理*/
	if ((int)(i2)) {
		p = daxie((int)(i2), 0, p);
	}

	else {
		if (i10 == 0 && i9 == 0 && i8 == 0 && i7 == 0 && i6 == 0 && i5 == 0 && i4 == 0 && i3 == 0) {}

		else {
			if (x3 == 0) {}

			else {
				p = add_zero(p);
			}
		}
	}

	/*个位输出的格式处理*/
	if ((int)(x3)) {
		p = daxie((int)(x3), 5, p);
	}

	else {
		if (i10 == 0 && i9 == 0 && i8 == 0 && i7 == 0 && i6 == 0 && i5 == 0 && i4 == 0 && i3 == 0 && i2 == 0) {}

		else {
			p = add_other(5, p);
		}
	}

	/*第一个"整"输出的格式处理*/
	if (x2 == 0 && x1 == 0) {
		if (i10 == 0 && i9 == 0 && i8 == 0 && i7 == 0 && i6 == 0 && i5 == 0 && i4 == 0 && i3 == 0 && i2 == 0 && x3 == 0) {}

		else {
			p = add_other(8, p);
		}
	}

	/*十分位输出的格式处理*/
	if ((int)(x2)) {
		p = daxie((int)(x2), 6, p);
	}

	else {
		if (i10 == 0 && i9 == 0 && i8 == 0 && i7 == 0 && i6 == 0 && i5 == 0 && i4 == 0 && i3 == 0 && i2 == 0 && x3 == 0) {}

		else {
			if (x1 == 0) {}

			else {
				p = add_zero(p);
			}
		}
	}

	/*第二个"整"输出的格式处理*/
	if (x2 != 0 && x1 == 0) {
		p = add_other(8, p);
	}

	/*百分位输出的格式处理*/
	if ((int)(x1)) {
		p = daxie((int)(x1), 7, p);
	}

	else {
		if (i10 == 0 && i9 == 0 && i8 == 0 && i7 == 0 && i6 == 0 && i5 == 0 && i4 == 0 && i3 == 0 && i2 == 0 && x3 == 0 && x2 == 0) {
			p = add_zero(p);
			p = add_other(5, p);
			p = add_other(8, p);
		}
	}

	result[p] = '\0';

    printf("%s\n", result);  /* 转换得到的大写结果，只允许用本语句输出，之前不允许任何形式的部分输出 */
    return 0;
}