/*2151294 信11 马威*/
#include <iostream>
using namespace std;

int main()
{
	int x;

	while (1) {
		cout << "请输入x的值[0-100] : ";
		cin >> x;   //读入x的方式必须是 cin>>int型变量，不允许其他方式
		if (x >= 0 && x <= 100 && cin.good() == 1) {
			break;
		}

		/*只剩非法输入，或数值超类型范围的处理*/
		else if ((x <= 0 || x > 100) && cin.good() == 0) {
			cin.clear();
			cin.ignore(100, '\n');
		}

		/*若为超用户范围数+非法输入，给程序读取前面的数后，再循环一次，将缓冲区内的非法输入清空*/
	}

	cout << "cin.good()=" << cin.good() << " x=" << x << endl; //此句不准动，并且要求输出时good为1

	return 0;
}