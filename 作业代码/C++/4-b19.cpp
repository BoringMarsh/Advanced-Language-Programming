/*2151294 ��11 ����*/
#include<iostream>
using namespace std;

/*����������������*/
int max(int a, int b)
{
	return a > b ? a : b;
}

/*����������������*/
int max(int a, int b, int c)
{
	int d = max(a, b);
	return d > c ? d : c;
}

/*����ĸ����������*/
int max(int a, int b, int c, int d)
{
	int e = max(a, b, c);
	return e > d ? e : d;
}

int main()
{
	int num, a, b, c, d;
	while (1) {
		cout << "���������num��num����������" << endl;
		cin >> num;

		/*��������ȷ�������*/
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

		/*������������ֱ���˳�*/
		else {
			cout << "�����������" << endl;
			break;
		}
	}
	return 0;
}