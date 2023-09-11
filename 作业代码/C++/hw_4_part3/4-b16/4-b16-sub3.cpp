/*2151294 信11 马威*/
#include<iostream>
#include<cmath>
using namespace std;

void equal_real_solution(double a, double b, double c)
{
	if (b * b - 4 * a * c < 1e-6 && b * b - 4 * a * c>-1e-6 && a != 0) {
		double x1, x2;

		x1 = -b / (2 * a);
		x2 = -b / (2 * a);

		cout << "有两个相等实根:" << endl;
		cout << "x1=x2=" << x1 << endl;
	}
}