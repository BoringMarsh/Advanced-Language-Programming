/*2151294 ��11 ����*/
#include<iostream>
#include<Windows.h>
#include<time.h>
using namespace std;

#define CODE_LENGTH_MIN 12  /*���볤������*/
#define CODE_LENGTH_MAX 16  /*���볤������*/
#define UPPER_MIN  2  /*��д��ĸ��������*/
#define LOWER_MIN  2  /*Сд��ĸ��������*/
#define NUMBER_MIN 2  /*������������*/
#define OTHER_MIN  2  /*�����ַ���������*/

/*�����ַ�������*/
static const char other[] = "~!@#$%^&*()-_=+[],.?";

/***************************************************************************
  �������ƣ�check_info
  ��    �ܣ��ۺ�����ĸ�����Ϣ���ж������Ƿ���ȷ
  ���������int code_length�����볤��
            int upper_num����д��ĸ��������
			int lower_num��Сд��ĸ��������
			int number_num��������������
			int other_num�������ַ���������
  �� �� ֵ������
  ˵    ��������ֵ���壺������-���������-������ȷ
***************************************************************************/
int check_info(int code_length, int upper_num, int lower_num, int number_num, int other_num)
{
	/*��������֣���һ����󣬷���1*/
	if (!cin.good())
		return 1;

	/*���볤�Ȳ���ָ����Χ�ڣ��ڶ�����󣬷���2*/
	else if (code_length<CODE_LENGTH_MIN || code_length>CODE_LENGTH_MAX)
		return 2;

	/*ĳ���ַ���������������ָ����Χ�ڣ���������󣬷���3*/
	else if (upper_num<UPPER_MIN || upper_num>code_length
		|| lower_num<LOWER_MIN || lower_num>code_length
		|| number_num<NUMBER_MIN || number_num>code_length
		|| other_num<OTHER_MIN || other_num>code_length)
		return 3;

	/*�������͵����ٸ�����Ӵ���ָ�������볤�ȣ���������󣬷���4*/
	else if (upper_num + lower_num + number_num + other_num > code_length)
		return 4;

	/*��ȷ������0*/
	else
		return 0;
}

/***************************************************************************
  �������ƣ�print_error_info
  ��    �ܣ�����check_info()�����Ĵ��󷵻�ֵ��ѡ�����������ʾ
  ���������int code_length�����볤��
			int upper_num����д��ĸ��������
			int lower_num��Сд��ĸ��������
			int number_num��������������
			int other_num�������ַ���������
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void print_error_info(int ret, int code_length, int upper_num, int lower_num, int number_num, int other_num)
{
	/*��������֣���һ�����*/
	if (ret == 1)
		cout << "����Ƿ�" << endl;

	/*���볤�Ȳ���ָ����Χ�ڣ��ڶ������*/
	else if (ret == 2)
		cout << "���볤��[" << code_length << "]����ȷ" << endl;

	/*ĳ���ַ���������������ָ����Χ�ڣ����������*/
	else if (ret == 3) {
		if (upper_num<UPPER_MIN || upper_num>code_length)
			cout << "��д��ĸ����[" << upper_num << "]����ȷ" << endl;

		else if (lower_num<LOWER_MIN || lower_num>code_length)
			cout << "Сд��ĸ����[" << lower_num << "]����ȷ" << endl;

		else if (number_num<NUMBER_MIN || number_num>code_length)
			cout << "���ָ���[" << number_num << "]����ȷ" << endl;

		else if (other_num<OTHER_MIN || other_num>code_length)
			cout << "�������Ÿ���[" << other_num << "]����ȷ" << endl;
	}

	/*�������͵����ٸ�����Ӵ���ָ�������볤�ȣ����������*/
	else if (ret == 4)
		cout << "�����ַ�����֮��[" << upper_num << '+' << lower_num << '+' << number_num << '+' << other_num << "]���������볤��[" << code_length << "]" << endl;
}

int main()
{
	int code_length;  /*���볤��*/
	int upper_num, lower_num, number_num, other_num;  /*�����ַ�����������*/
	int ret;  /*��麯���ķ���ֵ*/
	int i, j, k;  /*��������*/
	const char all[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789~!@#$%^&*()-_=+[],.?";  /*���п����ַ�������*/

	srand((unsigned int)(time(0)));  /*���������*/
	
	cout << "���������볤��(12-16)�� ��д��ĸ����(��" << UPPER_MIN
		<< ")�� Сд��ĸ����(��" << LOWER_MIN
		<< ")�� ���ָ���(��" << NUMBER_MIN
		<< ")�� �������Ÿ���(��" << OTHER_MIN << ")" << endl;
	cin >> code_length >> upper_num >> lower_num >> number_num >> other_num;  /*������Ϣ*/
	
	ret = check_info(code_length, upper_num, lower_num, number_num, other_num);  /*�жϲ�����ֵ*/

	/*һ����������ȷ����ʼ��������*/
	if (!ret) {
		cout << code_length << ' ' << upper_num << ' ' << lower_num << ' ' << number_num << ' ' << other_num << endl;  /*���������Ϣ*/
		char code[CODE_LENGTH_MAX];  /*����������ַ�����*/
		int position;  /*�ַ���������λ��*/
		char upper, lower, number, OTHER;  /*����ĸ�������ַ�*/

		/*1��������10������*/
		for (k = 0; k < 10; k++) {

			/*2��ÿ�������У�������10���ַ�*/
			/*2.1�������ʼ��*/
			for (i = 0; i < CODE_LENGTH_MAX; i++)
				code[i] = 0;

			/*2.2�������д��ĸ������������*/
			for (i = 0; i < upper_num; i++) {
				upper = rand() % ('Z' - 'A' + 1) + 'A';  /*���������ĸ*/
				position = rand() % code_length;  /*�������λ��*/

				/*����λ���Ѿ����ַ�������ֵ�����������Լ�*/
				if (code[position])
					i--;

				/*����λ��Ϊ�գ���ֵ*/
				else
					code[position] = upper;
			}

			/*2.3�����Сд��ĸ������������*/
			for (i = 0; i < lower_num; i++) {
				lower = rand() % ('z' - 'a' + 1) + 'a';  /*���������ĸ*/
				position = rand() % code_length;  /*�������λ��*/

				/*����λ���Ѿ����ַ�������ֵ�����������Լ�*/
				if (code[position])
					i--;

				/*����λ��Ϊ�գ���ֵ*/
				else
					code[position] = lower;
			}

			/*2.4��������֣�����������*/
			for (i = 0; i < number_num; i++) {
				number = rand() % 10 + '0';  /*�����������*/
				position = rand() % code_length;  /*�������λ��*/

				/*����λ���Ѿ����ַ�������ֵ�����������Լ�*/
				if (code[position])
					i--;

				/*����λ��Ϊ�գ���ֵ*/
				else
					code[position] = number;
			}

			/*2.5����������ַ�������������*/
			for (i = 0; i < other_num; i++) {
				OTHER = other[rand() % 20];  /*��������ַ�*/
				position = rand() % code_length;  /*�������λ��*/

				/*����λ���Ѿ����ַ�������ֵ�����������Լ�*/
				if (code[position])
					i--;

				/*����λ��Ϊ�գ���ֵ*/
				else
					code[position] = OTHER;
			}

			/*2.6��ͳ����Ϊ���ַ���*/
			j = 0;
			for (i = 0; i < code_length; i++) {
				if (code[i] == 0)
					j++;
			}

			/*2.7����֤�����ַ���������������£������п����ַ��ķ�Χ���������ַ���ֱ������Ϊֹ*/
			for (i = 0; i < j; i++) {
				OTHER = all[rand() % 82];  /*��������ַ�*/
				position = rand() % code_length;  /*�������λ��*/

				/*����λ���Ѿ����ַ�������ֵ�����������Լ�*/
				if (code[position])
					i--;

				/*����λ��Ϊ�գ���ֵ*/
				else
					code[position] = OTHER;
			}

			/*������һ����������*/
			for (i = 0; i < code_length; i++)
				cout << code[i];

			/*����*/
			cout << endl;
		}
	}

	/*������������������ʾ���˳�����*/
	else
		print_error_info(ret, code_length, upper_num, lower_num, number_num, other_num);

	return 0;
}