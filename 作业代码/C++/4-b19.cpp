/*2151294 信11 马威*/
#include<iostream>
using namespace std;

/*输出两个数的最大数*/
int max(int a, int b)
{
	return a > b ? a : b;
}

/*输出三个数的最大数*/
int max(int a, int b, int c)
{
	int d = max(a, b);
	return d > c ? d : c;
}

/*输出四个数的最大数*/
int max(int a, int b, int c, int d)
{
	int e = max(a, b, c);
	return e > d ? e : d;
}

int main()
{
	int num, a, b, c, d;
	while (1) {
		cout << "请输入个数num及num个正整数：" << endl;
		cin >> num;

		/*若个数正确，则继续*/
		if (num == 2 || num == 3 || num == 4) {
			if (num == 2) {
				cin >> a >> b;

				if (a > 0 && b > 0 && cin.good() == 1) {
					cout << "max=" << max(a, b) << endl;
					cin.clear();
					cin.ignore(INT_MAX, '\n');
					break;
				}

				else if ((a <= 0 || b <= 0) && cin.good() == 1) {
					cin.clear();
					cin.ignore(INT_MAX, '\n');
					continue;
				}

				else if ((a <= 0 || b <= 0) && cin.good() == 0) {
					cin.clear();
					cin.ignore(INT_MAX, '\n');
					continue;
				}
			}

			else if (num == 3) {
				cin >> a >> b >> c;

				if (a > 0 && b > 0 && c > 0 && cin.good() == 1) {
					cout << "max=" << max(a, b, c) << endl;
					cin.clear();
					cin.ignore(INT_MAX, '\n');
					break;
				}

				else if ((a <= 0 || b <= 0 || c <= 0) && cin.good() == 1) {
					cin.clear();
					cin.ignore(INT_MAX, '\n');
					continue;
				}

				else if ((a <= 0 || b <= 0 || c <= 0) && cin.good() == 0) {
					cin.clear();
					cin.ignore(INT_MAX, '\n');
					continue;
				}
			}

			else if (num == 4) {
				cin >> a >> b >> c >> d;

				if (a > 0 && b > 0 && c > 0 && d > 0 && cin.good() == 1) {
					cout << "max=" << max(a, b, c, d) << endl;
					cin.clear();
					cin.ignore(INT_MAX, '\n');
					break;
				}

				else if ((a <= 0 || b <= 0 || c <= 0 || d <= 0) && cin.good() == 1) {
					cin.clear();
					cin.ignore(INT_MAX, '\n');
					continue;
				}

				else if ((a <= 0 || b <= 0 || c <= 0 || d <= 0) && cin.good() == 0) {
					cin.clear();
					cin.ignore(INT_MAX, '\n');
					continue;
				}
			}
		}

		/*若个数错误，则直接退出*/
		else {
			cout << "个数输入错误" << endl;
			break;
		}
	}
	return 0;
}