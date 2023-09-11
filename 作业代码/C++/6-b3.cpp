/*2151294 信11 马威*/
#include<iostream>
using namespace std;

/*输入i，返回2的i次方*/
unsigned int two_pow(const int i)
{
	int result = 1;
	int j;

	if (i != 0) {
		for (j = 0; j < i; j++)
			result = result * 2;
	}

	return result;
}

int main()
{
	char c[33], * p1 = c, * p2;  /*c为输入的字符数组，p1指向c首地址，再定义一个指针变量p2*/
	int i;  /*计数变量*/
	unsigned int result = 0;  /*转换结果*/

	/*数组的初始化*/
	for (i = 0; i < 33; i++)
		c[i] = 0;

	/*输入字符串*/
	cin >> c;

	/*使p1停在尾零前的最后一个字符，p2与p1指向一致*/
	while (*p1 != '\0')
		p1++;

	p1--, p2 = p1;

	while (1) {

		/*若p2指向字符为1，此时p1与p2的差值正好是2的次数，得出结果后加到result上*/
		if (*p2 == '1') {
			result = result + two_pow(p1 - p2);
		}

		/*若p2此时指向c首地址，结束循环*/
		if (p2 == c)
			break;

		/*p2再向前推进一位，计算下一位的数值*/
		p2--;
	}

	/*输出结果*/
	cout << result << endl;
	return 0;
}