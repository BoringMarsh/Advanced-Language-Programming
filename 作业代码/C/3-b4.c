/*2151294 ��11 ����*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>  /*������ʹ�����Һ���sin(x)����include��ͷ�ļ�*/

int main()
{
	const float pi = 3.14159f;  /*���峣��pi*/
	int l, w, angle;            /*�������һ�߳�l����һ�߳�w�����߼н�angle���Ƕ��ƣ�*/
	float S, rad;               /*������������ε����S�����߼н�rad�������ƣ�*/

	printf("�����������ε����߼���н�(�Ƕ�)\n");  /*�����ʾ��*/
	scanf("%d %d %d", &l, &w, &angle);             /*�������ֵ����int��ʽ�洢*/
	rad = angle / 180.0f * pi;                     /*����нǶ�Ӧ�Ļ���*/
	S = 1.0f / 2.0f * l * w * (float)(sin(rad));   /*���������ε������ʽ������*/
	printf("���������Ϊ : %.3f\n", S);            /*��ָ����ʽ��float�ͱ���3λС�������������*/

	return 0;
}