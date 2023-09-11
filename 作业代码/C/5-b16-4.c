/*2151294 ��11 ����*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#define STUDENT_NUMBER 10  /*ѧ������*/
#define NAME_LIMIT 8       /*ѧ�����ֳ���*/

/***************************************************************************
  �������ƣ�input_info
  ��    �ܣ�����ÿ��ѧ���ĸ�����Ϣ
  ���������char id[][8]������ѧ��ѧ�ŵĶ�ά�ַ�����
			char name[][NAME_LIMIT+1]������ѧ�����ֵĶ�ά�ַ�����
			int score[]������ѧ���ɼ�������
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void input_info(char id[][8], char name[][NAME_LIMIT + 1], int score[])
{
	int i;

	for (i = 0; i < STUDENT_NUMBER; i++) {
		printf("�������%d���˵�ѧ�š��������ɼ�\n", i + 1);
		scanf("%s", id[i]);
		scanf("%s", name[i]);
		scanf("%d", &score[i]);
	}
}

/***************************************************************************
  �������ƣ�sort_info
  ��    �ܣ���������������ʹ��ѡ�񷨽�������
  ���������char id[][8]������ѧ��ѧ�ŵĶ�ά�ַ�����
			char name[][NAME_LIMIT+1]������ѧ�����ֵĶ�ά�ַ�����
			int score[]������ѧ���ɼ�������
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void sort_info(char id[][8], char name[][NAME_LIMIT + 1], int score[])
{
	int i, j, k, l;  /*��������*/
	int tscore;   /*�����м����*/
	char tid[8], tname[NAME_LIMIT + 1];  /*ѧ���м����顢�����м�����*/

	/*ʹ��ѡ�񷨽������򣬽�������ʱ��ѧ���ĸ�����Ϣһ����ȫ������*/
	for (i = 0; i < STUDENT_NUMBER; i++) {
		k = i;

		for (j = i + 1; j < STUDENT_NUMBER; j++) {
			if (score[j] > score[k]) {  /*��������Ϊ�ɼ�����*/
				k = j;
			}
		}

		tscore = score[k];
		score[k] = score[i];
		score[i] = tscore;

		for (l = 0; l < NAME_LIMIT + 1; l++) {
			tname[l] = name[k][l];
			name[k][l] = name[i][l];
			name[i][l] = tname[l];
		}

		for (l = 0; l < NAME_LIMIT; l++) {
			tid[l] = id[k][l];
			id[k][l] = id[i][l];
			id[i][l] = tid[l];
		}
	}
}

/***************************************************************************
  �������ƣ�print_selected_info
  ��    �ܣ�����ɸѡ������ѡ��������������Ϣ�����
  ���������char id[][8]������ѧ��ѧ�ŵĶ�ά�ַ�����
			char name[][NAME_LIMIT+1]������ѧ�����ֵĶ�ά�ַ�����
			int score[]������ѧ���ɼ�������
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void print_selected_info(char id[][8], char name[][NAME_LIMIT + 1], int score[])
{
	int i, j;
	printf("\nȫ��ѧ��(�ɼ�����):\n");

	for (i = 0; i < STUDENT_NUMBER; i++) {  /*���ж��������������ѧ������Ϣ*/
		printf("%s ", name[i]);

		for (j = 0; j < 8; j++) {
			printf("%c", id[i][j]);
		}

		printf(" %d\n", score[i]);
	}
}

int main()
{
	char id[STUDENT_NUMBER][8];  /*ѧ������*/
	char name[STUDENT_NUMBER][NAME_LIMIT + 1];  /*��������*/
	int score[STUDENT_NUMBER];  /*�ɼ�����*/

	input_info(id, name, score);  /*������Ϣ*/
	sort_info(id, name, score);   /*������Ϣ*/
	print_selected_info(id, name, score);  /*ɸѡ�������Ϣ*/

	return 0;
}