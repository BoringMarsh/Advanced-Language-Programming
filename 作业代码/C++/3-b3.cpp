/*2151294 ��11 ����*/
#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	double i, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10;  /*�������������i������������Ԥ����ֵ��i1������ֵ��i2��i10�Ǹ���λ��*/
	double x, X, x3, x2, x1;                            /*�������������x������ֵ�еĸ�λ���ٷ�λ�Ĳ��֣�X��������x��Ԥ����ֵ��x3��x1�Ǹ���λ��*/
	cout << "������[0..100 ��)֮������� : " << endl;   /*�����ʾ��*/
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

	/*�����ܿ��6������������ʾ�֣��������λ����ȡ�����*/
	cout << setw(6) << setiosflags(ios::left) << "ʮ��λ";
	cout << " : " << i10 << endl;

	cout << setw(6) << setiosflags(ios::left) << "��λ";
	cout << " : " << i9 << endl;

	cout << setw(6) << setiosflags(ios::left) << "ǧ��λ";
	cout << " : " << i8 << endl;

	cout << setw(6) << setiosflags(ios::left) << "����λ";
	cout << " : " << i7 << endl;

	cout << setw(6) << setiosflags(ios::left) << "ʮ��λ";
	cout << " : " << i6 << endl;

	cout << setw(6) << setiosflags(ios::left) << "��λ";
	cout << " : " << i5 << endl;

	cout << setw(6) << setiosflags(ios::left) << "ǧλ";
	cout << " : " << i4 << endl;

	cout << setw(6) << setiosflags(ios::left) << "��λ";
	cout << " : " << i3 << endl;

	cout << setw(6) << setiosflags(ios::left) << "ʮλ";
	cout << " : " << i2 << endl;

	cout << setw(6) << setiosflags(ios::left) << "Բ";
	cout << " : " << x3 << endl;

	cout << setw(6) << setiosflags(ios::left) << "��";
	cout << " : " << x2 << endl;

	cout << setw(6) << setiosflags(ios::left) << "��";
	cout << " : " << x1 << endl;

	return 0;
}