/*2151294 ��11 ����*/
#include <iostream>
#include<iomanip>
using namespace std;
int main()
{
	float qian;                                /*�������������qian������ֵ*/
	int money;                                 /*�������������money��������qian��Ԥ����ֵ*/
	int yuan50, yuan20, yuan10, yuan5, yuan1;  /*��������������ֱ���50Ԫ��20Ԫ��10Ԫ��5Ԫ��1Ԫ����������*/
	int jiao5, jiao1;                          /*��������������ֱ���5�ǡ�1�ǵ���������*/
	int fen5, fen2, fen1;                      /*��������������ֱ���5�֡�2�֡�1�ֵ���������*/
	int total;                                 /*�������������total��������ֵ����������*/
	cout << "����������ֵ��" << endl;          /*�����ʾ��*/
	cin >> qian;                               /*�������ֵ*/
	money = int((qian + 1e-3) * 100);          /*������ֵ����һ���㹻С����������������������x��Ԥ����ֵ��Ȼ��תΪ����*/

	/*��ʼ��������ֵ��������Ϊ��*/
	yuan50 = 0, yuan20 = 0, yuan10 = 0, yuan5 = 0, yuan1 = 0;
	jiao5 = 0, jiao1 = 0;
	fen5 = 0, fen2 = 0, fen1 = 0;

	/*����50Ԫ����������*/
	if (money < 10000 && money >= 5000) {
		yuan50 = yuan50 + 1;
		money = money - 5000;
	}

	/*����20Ԫ����������*/
	if (money < 5000 && money >= 4000) {
		yuan20 = yuan20 + 2;
		money = money - 4000;
	}

	else if (money < 4000 && money >= 2000) {
		yuan20 = yuan20 + 1;
		money = money - 2000;
	}

	/*����10Ԫ����������*/
	if (money < 2000 && money >= 1000) {
		yuan10 = yuan10 + 1;
		money = money - 1000;
	}

	/*����5Ԫ����������*/
	if (money < 1000 && money >= 500) {
		yuan5 = yuan5 + 1;
		money = money - 500;
	}

	/*����1Ԫ����������*/
	if (money < 500 && money >= 400) {
		yuan1 = yuan1 + 4;
		money = money - 400;
	}

	else if (money < 500 && money >= 300) {
		yuan1 = yuan1 + 3;
		money = money - 300;
	}

	else if (money < 500 && money >= 200) {
		yuan1 = yuan1 + 2;
		money = money - 200;
	}

	else if (money < 500 && money >= 100) {
		yuan1 = yuan1 + 1;
		money = money - 100;
	}

	/*����5�ǵ���������*/
	if (money < 100 && money >= 50) {
		jiao5 = jiao5 + 1;
		money = money - 50;
	}

	/*����1�ǵ���������*/
	if (money < 50 && money >= 40) {
		jiao1 = jiao1 + 4;
		money = money - 40;
	}

	else if (money < 50 && money >= 30) {
		jiao1 = jiao1 + 3;
		money = money - 30;
	}

	else if (money < 50 && money >= 20) {
		jiao1 = jiao1 + 2;
		money = money - 20;
	}

	else if (money < 50 && money >= 10) {
		jiao1 = jiao1 + 1;
		money = money - 10;
	}

	/*����5�ֵ���������*/
	if (money < 10 && money >= 5) {
		fen5 = fen5 + 1;
		money = money - 5;
	}

	/*����2�ֵ���������*/
	if (money < 5 && money >= 4) {
		fen2 = fen2 + 2;
		money = money - 4;
	}

	else if (money < 5 && money >= 2) {
		fen2 = fen2 + 1;
		money = money - 2;
	}

	/*����1�ֵ���������*/
	if (money == 1) {
		fen1 = fen1 + 1;
		money = money - 1;
	}

	total = yuan50 + yuan20 + yuan10 + yuan5 + yuan1 + jiao5 + jiao1 + fen5 + fen2 + fen1;  /*����������ֵ����������*/
	cout << "��" << total << "�����㣬�������£�" << endl;                                  /*�����ʾ��*/

	/*�����ܿ��4������������ʾ�֣������������*/
	if (yuan50 != 0) {
		cout << setw(4) << "50Ԫ" << " : " << yuan50 << "��" << endl;
	}

	if (yuan20 != 0) {
		cout << setw(4) << "20Ԫ" << " : " << yuan20 << "��" << endl;
	}

	if (yuan10 != 0) {
		cout << setw(4) << "10Ԫ" << " : " << yuan10 << "��" << endl;
	}

	if (yuan5 != 0) {
		cout << setw(4) << "5Ԫ" << " : " << yuan5 << "��" << endl;
	}

	if (yuan1 != 0) {
		cout << setw(4) << "1Ԫ" << " : " << yuan1 << "��" << endl;
	}

	if (jiao5 != 0) {
		cout << setw(4) << "5��" << " : " << jiao5 << "��" << endl;
	}

	if (jiao1 != 0) {
		cout << setw(4) << "1��" << " : " << jiao1 << "��" << endl;
	}

	if (fen5 != 0) {
		cout << setw(4) << "5��" << " : " << fen5 << "��" << endl;
	}

	if (fen2 != 0) {
		cout << setw(4) << "2��" << " : " << fen2 << "��" << endl;
	}

	if (fen1 != 0) {
		cout << setw(4) << "1��" << " : " << fen1 << "��" << endl;
	}

	return 0;
}