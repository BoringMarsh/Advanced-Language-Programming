/*2151294 ��11 ����*/
#include<iostream>
using namespace std;
int main()
{
	int score[1000], number[101];  /*�������������������score[1000]Ϊ�������飬number[101]Ϊ��������*/
	int i, j, limit, rank;         /*�������������limitΪ���������ݵĸ�����rankΪ�ۼ�����*/
	cout << "������ɼ������1000��������-1����" << endl;

	/*1��0��100��������ʼ״̬Ϊ0����ֵΪ0*/
	for (i = 0; i <= 100; i++) {
		number[i] = 0;
	}

	/*2��ͨ����������鸳ֵ�������븺������ֱ�ӽ����������*/
	for (i = 0; i <= 999; i++) {
		cin >> score[i];
		if (score[i] < 0) {
			break;
		}
	}

	/*3������i��ѭ��ִ��ʱ�����1���ʼ�1���ڸ���limit��Ȼ����ջ�����*/
	limit = i - 1;
	cin.clear();
	cin.ignore(INT_MAX, '\n');

	/*4���������һ����Ϊ�����������ʾ��ֱ�ӽ���������Ϊ�������*/
	if (score[0] > 0) {

		/*4.1�����ԭ���飬������Ϊ10�ı�����ʱ����*/
		cout << "���������Ϊ:" << endl;

		for (i = 0; i <= limit; i++) {
			cout << score[i] << " ";
			if ((i + 1) % 10 == 0) {
				cout << endl;
			}
		}

		/*���еĴ���ʹ����������������ֻ��һ����*/
		if (i % 10 == 0) {
			cout << "";
		}

		else {
			cout << endl;
		}

		/*4.2����0�ֵ�100�֣�����������������ƥ�䣬ÿƥ���һ�����ݣ�number[i]����*/
		cout << "���������εĶ�Ӧ��ϵΪ:" << endl;
		for (i = 0; i <= 100; i++) {
			for (j = 0; j <= limit; j++) {
				if (score[j] == i) {
					number[i] = number[i] + 1;
				}
			}
		}

		/*4.3�������ӡ���������Σ����θ���ֵΪ1�����÷���������Ϊ0�����������Ϊ0����������ѭ��������������Σ��ٽ�number[i]�ۼӵ�������*/
		rank = 1;

		for (i = 100; i >= 0; i--) {
			if (number[i] == 0) {
				continue;
			}

			else {
				for (j = 1; j <= number[i]; j++) {
					cout << i << " " << rank << endl;
				}
			}

			rank = rank + number[i];
		}
	}

	else {
		cout << "����Ч����" << endl;
	}

	return 0;
}