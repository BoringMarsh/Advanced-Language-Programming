/*2151294 ��11 ����*/
#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int r, c;     /*�������������r��������c������*/

	/*��1��9��������ÿһ��*/
	for (r = 1; r <= 9; r++) {

		/*��1��9��������r�е�ÿһ�ж�Ӧ����ʽ*/
		for (c = 1; c <= 9; c++) {
			if (c < r) {        /*����С��������������ӡ��ʽ*/
				cout << c << "x" << r << "=" << setiosflags(ios::left) << setw(4) << c * r;
			}

			else if (c == r) {  /*����������������ӡ��ʽ����*/
				cout << c << "x" << r << "=" << setiosflags(ios::left) << setw(4) << c * r << endl;
			}
		}
	}

	return 0;
}