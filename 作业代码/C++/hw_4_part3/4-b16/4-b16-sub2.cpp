/*2151294 信11 马威*/
#include<iostream>
#include<cmath>
using namespace std;

void unequal_real_solution(double a, double b, double c)
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