/*2151294 ��11 ����*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int r, c;     /*�������������r��������c������*/

	/*��1��9��������ÿһ��*/
	for (r = 1; r <= 9; r++) {

		/*��1��9��������r�е�ÿһ�ж�Ӧ����ʽ*/
		for (c = 1; c <= 9; c++) {
			if (c < r) {        /*����С��������������ӡ��ʽ*/
				printf("%dx%d=%-4d", c, r, c * r);
			}

			else if (c == r) {  /*����������������ӡ��ʽ����*/
				printf("%dx%d=%-4d\n", c, r, c * r);
			}
		}
	}

	return 0;
}