/*2151294 信11 马威*/
#include<iostream>
using namespace std;

/***************************************************************************
  函数名称：if_run_years
  功    能：判断一个年份是否为闰年
  输入参数：int year：年份
  返 回 值：1：该年是闰年
            0：该年不是闰年
  说    明：此为第1个添加函数
***************************************************************************/
int if_run_years(int year)
{
	if ((year % 4 == 0) && (year % 100 != 0) || (year % 4 == 0) && (year % 400 == 0))
		return 1;

	else
		return 0;
}

/***************************************************************************
  函数名称：day_number
  功    能：输入年月日，判断这一天是该年的第几天
  输入参数：int year：年份
            int month：月份
			int day：日
  返 回 值：int number+day：该年的第几天
  说    明：1、此为第2个添加函数
            2、该函数具有判断闰年的功能
***************************************************************************/
int day_number(int year, int month, int day)
{
	int ret = if_run_years(year);
	int m[12];     /*定义所需数组，m[12]为每个月的天数*/
	int i, number; /*定义所需变量，number为month-1个月的总天数*/

	/*直接给数组赋值*/
	m[0] = m[2] = m[4] = m[6] = m[7] = m[9] = m[11] = 31;
	m[3] = m[5] = m[8] = m[10] = 30;
	m[1] = 28 + ret;

	/*累计month-1个月的总天数，若month为1，则直接结束循环*/
	number = 0;

	for (i = 0; i <= month - 2; i++) {
		if (month == 1) {
			break;
		}

		number = number + m[i];
	}

	return number + day;
}

int main()
{
	int year, month, day;
	cout << "请输入年，月，日" << endl;
	cin >> year >> month >> day;
	cout << year << "-" << month << "-" << day << "是" << year << "年的第" << day_number(year, month, day) << "天" << endl;

	return 0;
}