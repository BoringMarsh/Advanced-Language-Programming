/*2151294 ��11 ����*/
#include<iostream>
using namespace std;

/*min����������ȱʡ��������ʼ��Ϊ0*/
int min(int num = 0, int a = 0, int b = 0, int c = 0, int d = 0)
{
	while (1) {
		cout << "���������num��num����������" << endl;
		cin >> num;

		/*��������ȷ�������*/
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

		/*�����������򷵻ظ���*/
		else if ((num < 2 || num>4) && cin.good() == 1) {
			cout << "�����������" << endl;
			return -1;
		}

		/*�����������������������*/
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

	/*ͨ������ֵ�ж���������Ƿ���ȷ*/
	if (ret > 0) {
		cout << "min=" << ret << endl;
	}

	return 0;
}