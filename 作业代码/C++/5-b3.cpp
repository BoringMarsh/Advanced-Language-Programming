/*2151294 ��11 ����*/
#include<iostream>
using namespace std;

/***************************************************************************
  �������ƣ�if_run_years
  ��    �ܣ��ж�һ������Ƿ�Ϊ����
  ���������int year�����
  �� �� ֵ��1������������
            0�����겻������
  ˵    ������Ϊ��1����Ӻ���
***************************************************************************/
int if_run_years(int year)
{
	if ((year % 4 == 0) && (year % 100 != 0) || (year % 4 == 0) && (year % 400 == 0))
		return 1;

	else
		return 0;
}

/***************************************************************************
  �������ƣ�day_number
  ��    �ܣ����������գ��ж���һ���Ǹ���ĵڼ���
  ���������int year�����
            int month���·�
			int day����
  �� �� ֵ��int number+day������ĵڼ���
  ˵    ����1����Ϊ��2����Ӻ���
            2���ú��������ж�����Ĺ���
***************************************************************************/
int day_number(int year, int month, int day)
{
	int ret = if_run_years(year);
	int m[12];     /*�����������飬m[12]Ϊÿ���µ�����*/
	int i, number; /*�������������numberΪmonth-1���µ�������*/

	/*ֱ�Ӹ����鸳ֵ*/
	m[0] = m[2] = m[4] = m[6] = m[7] = m[9] = m[11] = 31;
	m[3] = m[5] = m[8] = m[10] = 30;
	m[1] = 28 + ret;

	/*�ۼ�month-1���µ�����������monthΪ1����ֱ�ӽ���ѭ��*/
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
	cout << "�������꣬�£���" << endl;
	cin >> year >> month >> day;
	cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << day_number(year, month, day) << "��" << endl;

	return 0;
}