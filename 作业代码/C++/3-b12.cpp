/*2151294 信11 马威*/
#include <iostream>
#include<iomanip>
using namespace std;

int main()
{
	/*第一部分：日期输入正确性处理*/
	int y, m, w;

	/*1、对年月的输入正确性处理*/
	while (1) {
		cout << "请输入年份(2000-2030)和月份(1-12) : ";
		cin >> y >> m;
		if ((y >= 2000 && y <= 2030) && (m >= 1 && m <= 12) && cin.good() == 1) {
			break;
		}

		/*有非法输入读取、超过数据范围时的处理*/
		else if (cin.good() == 0) {
			cout << "输入非法，请重新输入" << endl;
			cin.clear();
			cin.ignore(10, '\n');
		}

		/*读取状态正常，超过用户范围时（单个年月或多个年月都可解决）的处理*/
		else if ((y < 2000 || y > 2030) || (m < 1 || m > 12) && cin.good() == 1) {
			cout << "输入非法，请重新输入" << endl;
		}

	}

	/*2、对星期的输入正确性处理*/
	while (1) {
		cout << "请输入" << y << "年" << m << "月1日的星期(0 - 6表示星期日 - 星期六) : ";
		cin >> w;
		if (w >= 0 && w <= 6 && cin.good() == 1) {
			break;
		}

		/*有非法输入读取、超过数据范围时的处理*/
		else if ((w <= 0 || w > 6) && cin.good() == 0) {
			cout << "输入非法，请重新输入" << endl;
			cin.clear();
			cin.ignore(10, '\n');
		}

		/*读取状态正常，超过用户范围时的处理*/
		else if ((w < 0 || w > 6) && cin.good() == 1) {
			cout << "输入非法，请重新输入" << endl;
		}
	}


	/*第二部分：月历打印处理*/
	int j, limit, d1;
	cout << '\n' << y << "年" << m << "月的月历为:" << endl;
	cout << "星期日  星期一  星期二  星期三  星期四  星期五  星期六" << endl;

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
			cout << setw(4 + 8 * w) << j;
		}

		else if (d1 % 7 == 1) {
			cout << setw(4) << j;
		}

		else if (j != 1) {
			cout << setw(8) << j;
		}

		if (d1 % 7 == 0) {
			cout << endl;
		}

		d1++;
	}
	return 0;
}