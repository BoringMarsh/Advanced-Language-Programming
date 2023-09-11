/*2151294 信11 马威*/
#include<iostream>
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

int main()
{
	int y, m, d, w, limit;     /*定义所需变量，y是年份，m是月份，d是日，w是星期值，limit是根据y、m推断出来的月天数*/
	/*第一部分：日期输入正确性处理*/
	while (1) {
		cout << "请输入年[1900-2100]、月、日：" << endl;
		cin >> y >> m >> d;

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
					cout << "日不正确，请重新输入" << endl;
					cin.clear();
					cin.ignore(99, '\n');
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
	cout << "星期";
	switch (w) {     /*根据星期值w，输出日期对应的星期以及换行符*/
		case 0:
			cout << "日" << endl;
			break;
		case 1:
			cout << "一" << endl;
			break;
		case 2:
			cout << "二" << endl;
			break;
		case 3:
			cout << "三" << endl;
			break;
		case 4:
			cout << "四" << endl;
			break;
		case 5:
			cout << "五" << endl;
			break;
		case 6:
			cout << "六" << endl;
			break;
	}

	return 0;
}