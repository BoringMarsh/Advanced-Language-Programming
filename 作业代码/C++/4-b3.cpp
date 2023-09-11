/*2151294 信11 马威*/
#include<iostream>
#include<iomanip>
using namespace std;

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
	W = y + int(y / 4) + int(c / 4) - 2 * c + int(13 * (m + 1) / 5) + d - 1;     /*用算式算出W*/

	while (W < 0) {     /*若W为负数，反复加7直到其为正数为止*/
		W = W + 7;
	}

	w = W % 7;     /*用处理后的W除以7取余数，得到真正的w值*/
	return w;
}

/*定义y年n月（1日星期值为w）的月历打印函数*/
void calendar(int y, int m, int w)
{
	int j, limit, d1;
	cout << '\n' << y << "年" << m << "月" << endl;
	cout << "======================================================" << endl;
	cout << "星期日  星期一  星期二  星期三  星期四  星期五  星期六" << endl;
	cout << "======================================================" << endl;

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
		if (j == 1) {
			cout << setw(4 + 8 * w) << j << "    ";
		}

		else if (d1 % 7 == 1) {
			cout << setw(4) << j << "    ";
		}

		else if (j != 1) {
			cout << setw(4) << j << "    ";
		}

		if (d1 % 7 == 0) {
			cout << endl;
		}

		d1++;
	}
}

int main()
{
	int y, m, w;     /*定义所需变量，y是年份，m是月份，w是该月1日星期值*/

	/*日期输入正确性处理*/
	while (1) {
		cout << "请输入年[1900-2100]、月" << endl;
		cin >> y >> m;

		/*有非法输入读取、超过数据类型范围时的处理*/
		if (cin.good() == 0) {
			cout << "输入错误，请重新输入" << endl;
			cin.clear();
			cin.ignore(99, '\n');
		}

		/*读取状态正常，超过用户范围时的处理*/
		else {
			/*年份超用户范围时的处理*/
			if (y < 1900 || y>2100) {
				cout << "年份不正确，请重新输入" << endl;
				cin.clear();
				cin.ignore(99, '\n');
			}

			/*月份超用户范围时的处理*/
			else if (m < 1 || m>12) {
				cout << "月份不正确，请重新输入" << endl;
				cin.clear();
				cin.ignore(99, '\n');
			}
		}

		/*若读取状态正常，且所有数据范围合理，则跳出循环*/
		if ((y >= 1900 && y <= 2100) && (m >= 1 && m <= 12)) {
			break;
		}
	}

	w = zeller(y, m, 1);      /*使用zeller公式，将日期转变而来的1日星期值赋给变量w*/
	calendar(y, m, w);        /*使用calendar函数，根据年份y、月份m、1日星期值w，打印该月的月份*/
	cout << endl << endl;     /*调整格式与demo一致的换行符输出*/

	return 0;
}