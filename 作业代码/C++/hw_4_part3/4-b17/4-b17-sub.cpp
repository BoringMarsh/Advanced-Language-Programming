/*2151294 信11 马威*/
#include<iostream>
#include<cmath>
using namespace std;

extern double a, b, c;

void if_equation()
{
	if (a == 0) {
		cout << "不是一元二次方程" << endl;
	}
}

void unequal_real_solution()
{
	if (b * b - 4 * a * c >= 1e-6 && a != 0) {
		double x1, x2;

		x1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
		x2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);

		cout << "有两个不等实根:" << endl;

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

void equal_real_solution()
{
	if (b * b - 4 * a * c < 1e-6 && b * b - 4 * a * c>-1e-6 && a != 0) {
		double x1, x2;

		x1 = -b / (2 * a);
		x2 = -b / (2 * a);

		cout << "有两个相等实根:" << endl;
		cout << "x1=x2=" << x1 << endl;
	}
}

void imaginary_solution()
{
	if (b * b - 4 * a * c < -1e-6 && a != 0) {
		double  delta, A;

		delta = sqrt(4 * a * c - b * b) / (2 * a);
		A = -b / (2 * a);

		cout << "有两个虚根:" << endl;

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