/*2151294 ��11 ����*/
#include<iostream>
using namespace std;
int main()
{
	char str[3][128];   /*�ַ�����*/
	int i, j;           /*��������*/
	int uppercase = 0;  /*��д������*/
	int lowercase = 0;  /*Сд������*/
	int number = 0;     /*���ּ�����*/
	int space = 0;      /*�ո������*/
	int other = 0;      /*����������*/

	/*����ĳ�ʼ��*/
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 128; j++) {
			str[i][j] = 0;
		}
	}

	/*�ú���fgets()����*/
	cout << "�������һ��" << endl;
	fgets(str[0], 128, stdin);
	cout << "������ڶ���" << endl;
	fgets(str[1], 128, stdin);
	cout << "�����������" << endl;
	fgets(str[2], 128, stdin);

	/*�����������ַ����������з����滻�ɳ�ʼ��ֵ0*/
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 128; j++) {
			if (str[i][j] == '\n')
				str[i][j] = 0;
		}
	}

	/*�����������ַ��в�Ϊ0���ַ���ͳ�Ƹ����ַ���*/
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 128; j++) {
			if (str[i][j]) {
				if (str[i][j] >= 'A' && str[i][j] <= 'Z')
					uppercase++;

				else if (str[i][j] >= 'a' && str[i][j] <= 'z')
					lowercase++;

				else if (str[i][j] >= '0' && str[i][j] <= '9')
					number++;

				else if (str[i][j] == ' ')
					space++;

				else
					other++;
			}
		}
	}

	/*���ͳ�ƽ��*/
	cout << "��д : " << uppercase << endl;
	cout << "Сд : " << lowercase << endl;
	cout << "���� : " << number << endl;
	cout << "�ո� : " << space << endl;
	cout << "���� : " << other << endl;
	return 0;
}
