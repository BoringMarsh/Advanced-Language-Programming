/*2151294 ��11 ����*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	short i, G, S, B, Q, W;                    /*����Ҫ�����������ÿ��λ��*/
	printf("������һ��[1..30000]�������\n");  /*�����ʾ��*/
	scanf("%hd", &i);                          /*�������ֵ����short��ʽ�洢*/

	G = i % 10;
	S = (i % 100 - G) / 10;
	B = (i % 1000 - S * 10 - G) / 100;              /*��������ģ�ķ���ȡ�ø���λ��*/
	Q = (i % 10000 - B * 100 - S * 10 - G) / 1000;
	W = (i - i % 10000) / 10000;

	printf("��λ : %hd\n", W);
	printf("ǧλ : %hd\n", Q);
	printf("��λ : %hd\n", B);  /*�������λ����ȡ�����*/
	printf("ʮλ : %hd\n", S);
	printf("��λ : %hd\n", G);

	return 0;
}