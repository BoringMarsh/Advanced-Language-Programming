/*2151294 ��11 ����*/
#include<iostream>
using namespace std;
int main()
{
	double i, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10;  /*�������������i������������Ԥ����ֵ��i1������ֵ��i2��i10�Ǹ���λ��*/
	double x, X, x3, x2, x1;                            /*�������������x������ֵ�еĸ�λ���ٷ�λ�Ĳ��֣�X��������x��Ԥ����ֵ��x3��x1�Ǹ���λ��*/
	cout << "������[0-100��)֮�������:" << endl;       /*�����ʾ��*/
	cin >> i1;                                          /*�������ֵ*/
	i = i1 + 1e-3;                                      /*������ֵ����һ���㹻С�������������*/

	/*��Ԥ����ֵ�ʵ���Сȡ�������ȡ�ø���λ����Ȼ����i / 1e+0�����ܻᳬ��int��Χ���������󣬹ʸ÷���ֻ��ȡ��ʮλ���޷�ȡ����λ*/
	i10 = int(i / 1e+9);  /*ȡʮ��λ*/
	i9 = int(i / 1e+8) - i10 * 1e+1;  /*ȡ��λ*/
	i8 = int(i / 1e+7) - i10 * 1e+2 - i9 * 1e+1;  /*ȡǧ��λ*/
	i7 = int(i / 1e+6) - i10 * 1e+3 - i9 * 1e+2 - i8 * 1e+1;  /*ȡ����λ*/
	i6 = int(i / 1e+5) - i10 * 1e+4 - i9 * 1e+3 - i8 * 1e+2 - i7 * 1e+1;  /*ȡʮ��λ*/
	i5 = int(i / 1e+4) - i10 * 1e+5 - i9 * 1e+4 - i8 * 1e+3 - i7 * 1e+2 - i6 * 1e+1;  /*ȡ��λ*/
	i4 = int(i / 1e+3) - i10 * 1e+6 - i9 * 1e+5 - i8 * 1e+4 - i7 * 1e+3 - i6 * 1e+2 - i5 * 1e+1;  /*ȡǧλ*/
	i3 = int(i / 1e+2) - i10 * 1e+7 - i9 * 1e+6 - i8 * 1e+5 - i7 * 1e+4 - i6 * 1e+3 - i5 * 1e+2 - i4 * 1e+1;  /*ȡ��λ*/
	i2 = int(i / 1e+1) - i10 * 1e+8 - i9 * 1e+7 - i8 * 1e+6 - i7 * 1e+5 - i6 * 1e+4 - i5 * 1e+3 - i4 * 1e+2 - i3 * 1e+1;  /*ȡʮλ*/

	x = i - i10 * 1e+9 - i9 * 1e+8 - i8 * 1e+7 - i7 * 1e+6 - i6 * 1e+5 - i5 * 1e+4 - i4 * 1e+3 - i3 * 1e+2 - i2 * 1e+1;  /*����ȡ�õ�λ����������ֵ�еĸ�λ���ٷ�λ�Ĳ���*/
	X = x * 100.0;  /*��������x��Ԥ����ֵ*/
	x3 = int(X / 1e+2);  /*ȡ��λ*/
	x2 = int(X / 1e+1) - x3 * 1e+1;  /*ȡʮ��λ*/
	x1 = int(X) - x3 * 1e+2 - x2 * 1e+1;  /*ȡ�ٷ�λ*/

	cout << "��д�����:" << endl;  /*�����ʾ��*/

	/*ȡλ����ɣ������������Ҵ�дת��*/
	/*��Ҫ˼·���ֿ�����λ����*/
	/*ÿһλ����ʱ����Ӧ�������*/
	/*ÿһλΪ��ʱ������λ��ǰ��λȫΪ�㣬���λҲ�����������λ��ǰ��λ��ȫΪ�㣬�򿴸�λ�Ƿ���Ҫ����һλ����"��"����Ҫ��������Բ���Ҫ���Ȳ�����������"��"�����񽻸���һλ����*/

	/*ʮ��λ����ĸ�ʽ����*/
	switch (int(i10)) {
		case 9:
			cout << "��ʰ";
			break;
		case 8:
			cout << "��ʰ";
			break;
		case 7:
			cout << "��ʰ";
			break;
		case 6:
			cout << "½ʰ";
			break;
		case 5:
			cout << "��ʰ";
			break;
		case 4:
			cout << "��ʰ";
			break;
		case 3:
			cout << "��ʰ";
			break;
		case 2:
			cout << "��ʰ";
			break;
		case 1:
			cout << "Ҽʰ";
			break;
		case 0:
			cout << "";
			break;
	}

	/*��λ����ĸ�ʽ����*/
	switch (int(i9)) {
		case 9:
			cout << "����";
			break;
		case 8:
			cout << "����";
			break;
		case 7:
			cout << "����";
			break;
		case 6:
			cout << "½��";
			break;
		case 5:
			cout << "����";
			break;
		case 4:
			cout << "����";
			break;
		case 3:
			cout << "����";
			break;
		case 2:
			cout << "����";
			break;
		case 1:
			cout << "Ҽ��";
			break;
		case 0:
			if (i10 == 0) {
				cout << "";
			}

			else {
				cout << "��";
			}

		break;
	}

	/*ǧ��λ����ĸ�ʽ����*/
	switch (int(i8)) {
		case 9:
			cout << "��Ǫ";
			break;
		case 8:
			cout << "��Ǫ";
			break;
		case 7:
			cout << "��Ǫ";
			break;
		case 6:
			cout << "½Ǫ";
			break;
		case 5:
			cout << "��Ǫ";
			break;
		case 4:
			cout << "��Ǫ";
			break;
		case 3:
			cout << "��Ǫ";
			break;
		case 2:
			cout << "��Ǫ";
			break;
		case 1:
			cout << "ҼǪ";
			break;
		case 0:
			if (i9 == 0 && i10 == 0) {
				cout << "";
			}

			else {
				if (i7 == 0) {
					cout << "";
				}

				else {
					cout << "��";
				}
			}

		break;
	}

	/*����λ����ĸ�ʽ����*/
	switch (int(i7)) {
		case 9:
			cout << "����";
			break;
		case 8:
			cout << "�ư�";
			break;
		case 7:
			cout << "���";
			break;
		case 6:
			cout << "½��";
			break;
		case 5:
			cout << "���";
			break;
		case 4:
			cout << "����";
			break;
		case 3:
			cout << "����";
			break;
		case 2:
			cout << "����";
			break;
		case 1:
			cout << "Ҽ��";
			break;
		case 0:
			if (i10 == 0 && i9 == 0 && i8 == 0) {
				cout << "";
			}

			else {
				if (i6 == 0) {
					cout << "";
				}

				else {
					cout << "��";
				}
			}

		break;
	}

	/*ʮ��λ����ĸ�ʽ����*/
	switch (int(i6)) {
		case 9:
			cout << "��ʰ";
			break;
		case 8:
			cout << "��ʰ";
			break;
		case 7:
			cout << "��ʰ";
			break;
		case 6:
			cout << "½ʰ";
			break;
		case 5:
			cout << "��ʰ";
			break;
		case 4:
			cout << "��ʰ";
			break;
		case 3:
			cout << "��ʰ";
			break;
		case 2:
			cout << "��ʰ";
			break;
		case 1:
			cout << "Ҽʰ";
			break;
		case 0:
			if (i10 == 0 && i9 == 0 && i8 == 0 && i7 == 0) {
				cout << "";
			}

			else {
				if (i5 == 0) {
					cout << "";
				}

				else {
					cout << "��";
				}
			}

		break;
	}

	/*��λ����ĸ�ʽ����*/
	switch (int(i5)) {
		case 9:
			cout << "����";
			break;
		case 8:
			cout << "����";
			break;
		case 7:
			cout << "����";
			break;
		case 6:
			cout << "½��";
			break;
		case 5:
			cout << "����";
			break;
		case 4:
			cout << "����";
			break;
		case 3:
			cout << "����";
			break;
		case 2:
			cout << "����";
			break;
		case 1:
			cout << "Ҽ��";
			break;
		case 0:
			if (i10 == 0 && i9 == 0 && i8 == 0 && i7 == 0 && i6 == 0) {
				cout << "";
			}

			else {
				if (i8 == 0 && i7 == 0 && i6 == 0) {
					cout << "";
				}

				else {
					cout << "��";
				}
			}

		break;
	}

	/*ǧλ����ĸ�ʽ����*/
	switch (int(i4)) {
		case 9:
			cout << "��Ǫ";
			break;
		case 8:
			cout << "��Ǫ";
			break;
		case 7:
			cout << "��Ǫ";
			break;
		case 6:
			cout << "½Ǫ";
			break;
		case 5:
			cout << "��Ǫ";
			break;
		case 4:
			cout << "��Ǫ";
			break;
		case 3:
			cout << "��Ǫ";
			break;
		case 2:
			cout << "��Ǫ";
			break;
		case 1:
			cout << "ҼǪ";
			break;
		case 0:
			if (i10 == 0 && i9 == 0 && i8 == 0 && i7 == 0 && i6 == 0 && i5 == 0) {
				cout << "";
			}

			else {
				if (i3 == 0) {
					cout << "";
				}

				else {
					cout << "��";
				}
			}

		break;
	}

	/*��λ����ĸ�ʽ����*/
	switch (int(i3)) {
		case 9:
			cout << "����";
			break;
		case 8:
			cout << "�ư�";
			break;
		case 7:
			cout << "���";
			break;
		case 6:
			cout << "½��";
			break;
		case 5:
			cout << "���";
			break;
		case 4:
			cout << "����";
			break;
		case 3:
			cout << "����";
			break;
		case 2:
			cout << "����";
			break;
		case 1:
			cout << "Ҽ��";
			break;
		case 0:
			if (i10 == 0 && i9 == 0 && i8 == 0 && i7 == 0 && i6 == 0 && i5 == 0 && i4 == 0) {
				cout << "";
			}

			else {
				if (i2 == 0) {
					cout << "";
				}

				else {
					cout << "��";
				}
			}

		break;
	}

	/*ʮλ����ĸ�ʽ����*/
	switch (int(i2)) {
		case 9:
			cout << "��ʰ";
			break;
		case 8:
			cout << "��ʰ";
			break;
		case 7:
			cout << "��ʰ";
			break;
		case 6:
			cout << "½ʰ";
			break;
		case 5:
			cout << "��ʰ";
			break;
		case 4:
			cout << "��ʰ";
			break;
		case 3:
			cout << "��ʰ";
			break;
		case 2:
			cout << "��ʰ";
			break;
		case 1:
			cout << "Ҽʰ";
			break;
		case 0:
			if (i10 == 0 && i9 == 0 && i8 == 0 && i7 == 0 && i6 == 0 && i5 == 0 && i4 == 0 && i3 == 0) {
				cout << "";
			}

			else {
				if (x3 == 0) {
					cout << "";
				}

				else {
					cout << "��";
				}
			}

		break;
	}

	/*��λ����ĸ�ʽ����*/
	switch (int(x3)) {
		case 9:
			cout << "��Բ";
			break;
		case 8:
			cout << "��Բ";
			break;
		case 7:
			cout << "��Բ";
			break;
		case 6:
			cout << "½Բ";
			break;
		case 5:
			cout << "��Բ";
			break;
		case 4:
			cout << "��Բ";
			break;
		case 3:
			cout << "��Բ";
			break;
		case 2:
			cout << "��Բ";
			break;
		case 1:
			cout << "ҼԲ";
			break;
		case 0:
			if (i10 == 0 && i9 == 0 && i8 == 0 && i7 == 0 && i6 == 0 && i5 == 0 && i4 == 0 && i3 == 0 && i2 == 0) {
				cout << "";
			}

			else {
				cout << "Բ";
			}

		break;
	}

	/*��һ��"��"����ĸ�ʽ����*/
	if (x2 == 0 && x1 == 0) {
		if (i10 == 0 && i9 == 0 && i8 == 0 && i7 == 0 && i6 == 0 && i5 == 0 && i4 == 0 && i3 == 0 && i2 == 0 && x3 == 0) {
			cout << "";
		}

		else {
			cout << "��";
		}
	}

	/*ʮ��λ����ĸ�ʽ����*/
	switch (int(x2)) {
		case 9:
			cout << "����";
			break;
		case 8:
			cout << "�ƽ�";
			break;
		case 7:
			cout << "���";
			break;
		case 6:
			cout << "½��";
			break;
		case 5:
			cout << "���";
			break;
		case 4:
			cout << "����";
			break;
		case 3:
			cout << "����";
			break;
		case 2:
			cout << "����";
			break;
		case 1:
			cout << "Ҽ��";
			break;
		case 0:
			if (i10 == 0 && i9 == 0 && i8 == 0 && i7 == 0 && i6 == 0 && i5 == 0 && i4 == 0 && i3 == 0 && i2 == 0 && x3 == 0) {
				cout << "";
			}

			else {
				if (x1 == 0) {
					cout << "";
				}

				else {
					cout << "��";
				}
			}

		break;
	}

	/*�ڶ���"��"����ĸ�ʽ����*/
	if (x2 != 0 && x1 == 0) {
		cout << "��";
	}

	/*�ٷ�λ����ĸ�ʽ����*/
	switch (int(x1)) {
		case 9:
			cout << "����";
			break;
		case 8:
			cout << "�Ʒ�";
			break;
		case 7:
			cout << "���";
			break;
		case 6:
			cout << "½��";
			break;
		case 5:
			cout << "���";
			break;
		case 4:
			cout << "����";
			break;
		case 3:
			cout << "����";
			break;
		case 2:
			cout << "����";
			break;
		case 1:
			cout << "Ҽ��";
			break;
		case 0:
			if (i10 == 0 && i9 == 0 && i8 == 0 && i7 == 0 && i6 == 0 && i5 == 0 && i4 == 0 && i3 == 0 && i2 == 0 && x3 == 0 && x2 == 0) {
				cout << "��Բ��";
			}

			else {
				cout << "";
			}

		break;
	}

	cout << endl;  /*�����Ϻ�Ļ��з�*/

	return 0;
}