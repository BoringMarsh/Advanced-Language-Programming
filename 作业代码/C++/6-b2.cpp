/*2151294 信11 马威*/
#include<iostream>
using namespace std;

int main()
{
	char c[80], * p1 = c;  /*c[80]为待检测字符数组，p1指向c首地址*/
	char rev[80], * p2 = rev;  /*rev[80]为c反转后的字符数组，p2指向rev首地址*/
	int i;  /*计数变量*/

	/*两数组初始化*/
	for (i = 0; i < 80; i++)
		c[i] = 0;
	for (i = 0; i < 80; i++)
		rev[i] = 0;

	cout << "请输入一个长度小于80的字符串（回文串）" << endl;
	fgets(c, 80, stdin);

	/*让p1停在c中换行符的位置，将换行符变为尾零*/
	while (*p1 != '\n')
		p1++;
	*p1 = '\0';

	/*若p1此时不指向c首地址，让p1指向尾零前最后一个字符，否则停止，防止越界*/
	if (p1 != c)
		p1--;

	/*p1向后移动，p2向前移动，使得c反着赋值到C中*/
	while (1) {
		*p2 = *p1;
		
		/*若p1到达了c首地址，在C尾部添加尾零后跳出循环*/
		if (p1 == c) {
			p2++;
			*p2 = '\0';
			break;
		}

		p1--, p2++;
	}

	/*比较c、C，若两者仍相等，则c为回文串，输出yes，否则输出no*/
	if (!strcmp(c, rev))
		cout << "yes" << endl;

	else
		cout << "no" << endl;

	return 0;
}