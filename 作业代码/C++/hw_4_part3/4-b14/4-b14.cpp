/*2151294 ��11 ����*/
#include<iostream>
#include<cmath>
using namespace std;

void if_equation(double a)
{
	if (a == 0) {
		cout << "����һԪ���η���" << endl;
	}
}

void unequal_real_solution(double a, double b, double c)
{
	if (b * b - 4 * a * c >= 1e-6 && a != 0) {
		double x1, x2;

		x1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
		x2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);

		cout << "����������ʵ��:" << endl;

		if (x1 > x2) {
			cout << "x1=" << x1 << endl;
			cout << "x2=" << x2 << endl;
		}

		else {
			cout << "x1=" << x2 << endl;
			cout << "x2=" << x1 << endl;
		}
	}
}

void equal_real_solution(double a, double b, double c)
{
	if (b * b - 4 * a * c < 1e-6 && b * b - 4 * a * c>-1e-6 && a != 0) {
		double x1, x2;

		x1 = -b / (2 * a);
		x2 = -b / (2 * a);

		cout << "���������ʵ��:" << endl;
		cout << "x1=x2=" << x1 << endl;
	}
}

void imaginary_solution(double a, double b, double c)
{
	if (b * b - 4 * a * c < -1e-6 && a != 0) {
		double  delta, A;

		delta = sqrt(4 * a * c - b * b) / (2 * a);
		A = -b / (2 * a);

		cout << "���������:" << endl;

		if (A >= 1e-6 || A <= -1e-6) {
			if (a > 0 && (delta >= 1 + 1e-6 || delta <= 1 - 1e-6) && (delta >= -1 + 1e-6 || delta <= -1 - 1e-6)) {
				cout << "x1=" << A << "+" << delta << "i" << endl;
				cout << "x2=" << A << "-" << delta << "i" << endl;
			}

			else if (a < 0 && (delta >= 1 + 1e-6 || delta <= 1 - 1e-6) && (delta >= -1 + 1e-6 || delta <= -1 - 1e-6)) {
				cout << "x1=" << A << "+" << -delta << "i" << endl;
				cout << "x2=" << A << "-" << -delta << "i" << endl;
			}

			else {
				cout << "x1=" << A << "+i" << endl;
				cout << "x2=" << A << "-i" << endl;
			}
		}

		else {
			if (a > 0 && (delta >= 1 + 1e-6 || delta <= 1 - 1e-6) && (delta >= -1 + 1e-6 || delta <= -1 - 1e-6)) {
				cout << "x1=" << delta << "i" << endl;
				cout << "x2=" << "-" << delta << "i" << endl;
			}

			else if (a < 0 && (delta >= 1 + 1e-6 || delta <= 1 - 1e-6) && (delta >= -1 + 1e-6 || delta <= -1 - 1e-6)) {
				cout << "x1=" << -delta << "i" << endl;
				cout << "x2=" << "-" << -delta << "i" << endl;
			}

			else {
				cout << "x1=i" << endl;
				cout << "x2=-i" << endl;
			}
		}
	}
}

int main()
{
	double a, b, c;
	cout << "������һԪ���η��̵�����ϵ��abc" << endl;
	cin >> a >> b >> c;
	if_equation(a);
	equal_real_solution(a, b, c);
	unequal_real_solution(a, b, c);
	imaginary_solution(a, b, c);
	return 0;
}