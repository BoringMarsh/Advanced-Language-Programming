/*2151294 ��11 ����*/
#include<iostream>
using namespace std;

/*����i������2��i�η�*/
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
	char c[33], * p1 = c, * p2;  /*cΪ������ַ����飬p1ָ��c�׵�ַ���ٶ���һ��ָ�����p2*/
	int i;  /*��������*/
	unsigned int result = 0;  /*ת�����*/

	/*����ĳ�ʼ��*/
	for (i = 0; i < 33; i++)
		c[i] = 0;

	/*�����ַ���*/
	cin >> c;

	/*ʹp1ͣ��β��ǰ�����һ���ַ���p2��p1ָ��һ��*/
	while (*p1 != '\0')
		p1++;

	p1--, p2 = p1;

	while (1) {

		/*��p2ָ���ַ�Ϊ1����ʱp1��p2�Ĳ�ֵ������2�Ĵ������ó������ӵ�result��*/
		if (*p2 == '1') {
			result = result + two_pow(p1 - p2);
		}

		/*��p2��ʱָ��c�׵�ַ������ѭ��*/
		if (p2 == c)
			break;

		/*p2����ǰ�ƽ�һλ��������һλ����ֵ*/
		p2--;
	}

	/*������*/
	cout << result << endl;
	return 0;
}