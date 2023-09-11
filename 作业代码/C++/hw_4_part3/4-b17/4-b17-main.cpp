/*2151294 信11 马威*/
#include<iostream>
#include<cmath>
using namespace std;

double a, b, c;

void if_equation();
void equal_real_solution();
void unequal_real_solution();
void imaginary_solution();

int main()
{
	cout << "请输入一元二次方程的三个系数abc" << endl;
	cin >> a >> b >> c;
	if_equation();
	equal_real_solution();
	unequal_real_solution();
	imaginary_solution();
	return 0;
}