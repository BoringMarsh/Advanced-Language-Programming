/*2151294 信11 马威*/
#include<iostream>
#include<cmath>
using namespace std;

void imaginary_solution(double a, double b, double c)
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