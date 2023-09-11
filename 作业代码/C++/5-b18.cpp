/*2151294 ��11 ����*/
#include<iostream>
#include<Windows.h>
#include<time.h>
using namespace std;

/*�����ַ�������*/
static const char other[] = "~!@#$%^&*()-_=+[],.?";

#define CODE_LENGTH_MIN 12  /*���볤������*/
#define CODE_LENGTH_MAX 16  /*���볤������*/
#define UPPER_MIN  2  /*��д��ĸ��������*/
#define LOWER_MIN  2  /*Сд��ĸ��������*/
#define NUMBER_MIN 2  /*������������*/
#define OTHER_MIN  2  /*�����ַ���������*/

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

int main()
{
	char notice[200];  /*�����ʾ����ַ�����*/
	int i, j, k;       /*��������*/
	int code_length;   /*���볤��*/
	int upper_num, lower_num, number_num, other_num;    /*�����ַ�����������*/
	int ret;  /*��麯���ķ���ֵ*/
	char code[10][CODE_LENGTH_MAX];  /*��Ŵ��������Ķ�ά����*/
	bool prime = true;  /*��־�����Ƿ���ȷ�ı�������ʼΪ��*/

	fgets(notice, 200, stdin);  /*���롢��ȡ��ͷһ�е���ʾ������ض���*/

	cin >> code_length >> upper_num >> lower_num >> number_num >> other_num;  /*������Ϣ*/

	ret = check_info(code_length, upper_num, lower_num, number_num, other_num);  /*�жϲ�����ֵ*/

	/*һ����������ȷ����ʼ�ж�*/
	if (!ret) {

		/*�����ַ��ļ�����������ʼΪ0*/
		int upper_count = 0, lower_count = 0, number_count = 0, other_count = 0, length_count = 0;

		/*1��������10������*/
		for (i = 0; i < 10; i++) {

			/*2��ÿ�������У�������10���ַ�*/
			/*2.1��ÿһ������һ���ַ������ȼ�����������*/
			for (j = 0; j < code_length; j++) {
				cin >> code[i][j];
				length_count++;

				/*2.2��������д��ĸ����д��ĸ������������*/
				if (code[i][j] >= 'A' && code[i][j] <= 'Z')
					upper_count++;

				/*2.3������Сд��ĸ��Сд��ĸ������������*/
				else if (code[i][j] >= 'a' && code[i][j] <= 'z')
					lower_count++;

				/*2.4���������֣����ּ�����������*/
				else if (code[i][j] >= '0' && code[i][j] <= '9')
					number_count++;

				/*2.5�����������ַ��������ַ�������������*/
				else {
					for (k = 0; k < 20; k++) {
						if (code[i][j] == other[k]) {
							other_count++;
							break;
						}
					}
				}

				/*2.6��ÿһ����������ɣ��жϽ��*/
				if (j == code_length - 1) {

					/*2.6.1���������ַ�����С����С���������볤�ȴ��󡢸����ַ���֮�Ͳ���������Ϊ��*/
					if (upper_count < upper_num || lower_count < lower_num || number_count < number_num || other_count < other_num
						|| length_count != code_length
						|| upper_count + lower_count + number_count + other_count != code_length)
						prime = false;

					/*2.6.2���������ȷ����������������㣬׼����һ�μ��*/
					else {
						upper_count = 0;
						lower_count = 0;
						number_count = 0;
						other_count = 0;
						length_count = 0;
					}
				}
			}
		}

		/*3������10���������ռ����������ж�*/
		if (prime)
			cout << "��ȷ" << endl;
		else
			cout << "����" << endl;
	}

	/*�����������������жϣ���������*/
	else  {
		cout << "����" << endl;
	}

	return 0;
}