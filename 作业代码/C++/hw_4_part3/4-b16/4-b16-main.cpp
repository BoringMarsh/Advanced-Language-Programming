/*2151294 ��11 ����*/
#include<iostream>
#include<cmath>
#include "4-b16.h"
using namespace std;

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