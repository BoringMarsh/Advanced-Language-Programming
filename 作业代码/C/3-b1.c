/*2151294 ��11 ����*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    const double pi = 3.14159;    /*���峣��pi*/
    double r, h;                  /*��������뾶r���߶�h*/
    printf("������뾶�͸߶�\n"); /*�����ʾ��*/
    scanf("%lf %lf", &r, &h);     /*�������ֵ����double��ʽ�洢*/

    printf("Բ�ܳ�     : %.2lf\n", 2 * pi * r);
    printf("Բ���     : %.2lf\n", pi * r * r);
    printf("Բ������ : %.2lf\n", 4 * pi * r * r);          /*��ָ����ʽ��double�ͱ���2λС���������������*/
    printf("Բ�����   : %.2lf\n", 4.0 / 3.0 * pi * r * r);
    printf("Բ�����   : %.2lf\n", pi * r * r * h);

    return 0;
}