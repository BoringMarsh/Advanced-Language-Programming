/*2151294 ��11 ����*/
#include <iostream>
using namespace std;

int main()
{
	int x;

	while (1) {
		cout << "������x��ֵ[0-100] : ";
		cin >> x;   //����x�ķ�ʽ������ cin>>int�ͱ�����������������ʽ
		if (x >= 0 && x <= 100 && cin.good() == 1) {
			break;
		}

		/*ֻʣ�Ƿ����룬����ֵ�����ͷ�Χ�Ĵ���*/
		else if ((x <= 0 || x > 100) && cin.good() == 0) {
			cin.clear();
			cin.ignore(100, '\n');
		}

		/*��Ϊ���û���Χ��+�Ƿ����룬�������ȡǰ���������ѭ��һ�Σ����������ڵķǷ��������*/
	}

	cout << "cin.good()=" << cin.good() << " x=" << x << endl; //�˾䲻׼��������Ҫ�����ʱgoodΪ1

	return 0;
}