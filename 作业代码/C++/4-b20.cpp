/*2151294 信11 马威*/
#include<iostream>
using namespace std;

/*min函数，带有缺省参数，初始都为0*/
int min(int num = 0, int a = 0, int b = 0, int c = 0, int d = 0)
{
	while (1) {
		cout << "请输入个数num及num个正整数：" << endl;
		cin >> num;

		/*若个数正确，则继续*/
		if (num >= 2 && num <= 4 && cin.good() == 1) {
			if (num == 2) {
				cin >> a >> b;

				if (a > 0 && b > 0 && cin.good() == 1) {
					cin.clear();
					cin.ignore(INT_MAX, '\n');
					return a < b ? a : b;
				}

				else if ((a <= 0 || b <= 0) && cin.good() == 1) {
					cin.clear();
					cin.ignore(INT_MAX, '\n');
				}

				else {
					cin.clear();
					cin.ignore(INT_MAX, '\n');
				}
			}

			else if (num == 3) {
				cin >> a >> b >> c;

				if (a > 0 && b > 0 && c > 0 && cin.good() == 1) {
					cin.clear();
					cin.ignore(INT_MAX, '\n');
					d = a < b ? a : b;
					return d < c ? d : c;
				}

				else if ((a <= 0 || b <= 0 || c <= 0) && cin.good() == 1) {
					cin.clear();
					cin.ignore(INT_MAX, '\n');
				}

				else {
					cin.clear();
					cin.ignore(INT_MAX, '\n');
				}
			}

			else {
				cin >> a >> b >> c >> d;

				if (a > 0 && b > 0 && c > 0 && d > 0 && cin.good() == 1) {
					cin.clear();
					cin.ignore(INT_MAX, '\n');
					int e = a < b ? a : b;
					int f = e < c ? e : c;
					return f < d ? f : d;
				}

				else if ((a <= 0 || b <= 0 || c <= 0 || d <= 0) && cin.good() == 1) {
					cin.clear();
					cin.ignore(INT_MAX, '\n');
				}

				else if ((a <= 0 || b <= 0 || c <= 0 || d <= 0) && cin.good() == 0) {
					cin.clear();
					cin.ignore(INT_MAX, '\n');
				}
			}
		}

		/*若个数错误，则返回负数*/
		else if ((num < 2 || num>4) && cin.good() == 1) {
			cout << "个数输入错误" << endl;
			return -1;
		}

		/*若个数输入错误，则重新输入*/
		else {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}
	}
}

int main()
{
	int ret;
	ret = min();

	/*通过返回值判断输入个数是否正确*/
	if (ret > 0) {
		cout << "min=" << ret << endl;
	}

	return 0;
}