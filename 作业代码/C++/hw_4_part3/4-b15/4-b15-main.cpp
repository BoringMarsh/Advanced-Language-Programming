/*2151294 信11 马威*/
#include<iostream>
#include<cmath>
using namespace std;

void if_equation(double a);
void unequal_real_solution(double a, double b, double c);
void equal_real_solution(double a, double b, double c);
void imaginary_solution(double a, double b, double c);

int main()
{
	double a, b, c;
	cout << "请输入一元二次方程的三个系数abc" << endl;
	cin >> a >> b >> c;
	if_equation(a);
	equal_real_solution(a, b, c);
	unequal_real_solution(a, b, c);
	imaginary_solution(a, b, c);
	return 0;
}