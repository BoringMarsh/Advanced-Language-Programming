/*2151294 信11 马威*/
#include<iostream>
using namespace std;
int main()
{
	char str[3][128];   /*字符数组*/
	int i, j;           /*计数变量*/
	int uppercase = 0;  /*大写计数器*/
	int lowercase = 0;  /*小写计数器*/
	int number = 0;     /*数字计数器*/
	int space = 0;      /*空格计数器*/
	int other = 0;      /*其它计数器*/

	/*数组的初始化*/
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 128; j++) {
			str[i][j] = 0;
		}
	}

	/*用函数fgets()输入*/
	cout << "请输入第一行" << endl;
	fgets(str[0], 128, stdin);
	cout << "请输入第二行" << endl;
	fgets(str[1], 128, stdin);
	cout << "请输入第三行" << endl;
	fgets(str[2], 128, stdin);

	/*逐个检查三行字符，检查出换行符，替换成初始化值0*/
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 128; j++) {
			if (str[i][j] == '\n')
				str[i][j] = 0;
		}
	}

	/*逐个检查三行字符中不为0的字符，统计各种字符数*/
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 128; j++) {
			if (str[i][j]) {
				if (str[i][j] >= 'A' && str[i][j] <= 'Z')
					uppercase++;

				else if (str[i][j] >= 'a' && str[i][j] <= 'z')
					lowercase++;

				else if (str[i][j] >= '0' && str[i][j] <= '9')
					number++;

				else if (str[i][j] == ' ')
					space++;

				else
					other++;
			}
		}
	}

	/*输出统计结果*/
	cout << "大写 : " << uppercase << endl;
	cout << "小写 : " << lowercase << endl;
	cout << "数字 : " << number << endl;
	cout << "空格 : " << space << endl;
	cout << "其它 : " << other << endl;
	return 0;
}
