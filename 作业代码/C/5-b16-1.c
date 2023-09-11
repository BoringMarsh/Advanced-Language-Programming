/*2151294 信11 马威*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

#define STUDENT_NUMBER 10  /*学生数量*/
#define NAME_LIMIT 8       /*学生名字长度*/

/***************************************************************************
  函数名称：input_info
  功    能：输入每个学生的各项信息
  输入参数：char id[][8]：各个学生学号的二维字符数组
			char name[][NAME_LIMIT+1]：各个学生名字的二维字符数组
			int score[]：各个学生成绩的数组
  返 回 值：无
  说    明：无
***************************************************************************/
void input_info(char id[][8], char name[][NAME_LIMIT + 1], int score[])
{
	int i;

	for (i = 0; i < STUDENT_NUMBER; i++) {
		printf("请输入第%d个人的学号、姓名、成绩\n", i + 1);
		scanf("%s", id[i]);
		scanf("%s", name[i]);
		scanf("%d", &score[i]);
	}
}

/***************************************************************************
  函数名称：sort_info
  功    能：根据排序条件，使用选择法进行排序
  输入参数：char id[][8]：各个学生学号的二维字符数组
			char name[][NAME_LIMIT+1]：各个学生名字的二维字符数组
			int score[]：各个学生成绩的数组
  返 回 值：无
  说    明：无
***************************************************************************/
void sort_info(char id[][8], char name[][NAME_LIMIT + 1], int score[])
{
	int i, j, k, l;  /*计数变量*/
	int tscore;   /*分数中间变量*/
	char tid[8], tname[NAME_LIMIT + 1];  /*学号中间数组、名字中间数组*/

	/*使用选择法进行排序，交换交换时将学生的各项信息一次性全部交换*/
	for (i = 0; i < STUDENT_NUMBER; i++) {
		k = i;

		for (j = i + 1; j < STUDENT_NUMBER; j++) {
			if (strcmp(id[j], id[k]) > 0) {  /*排序条件为学号降序*/
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
  函数名称：print_selected_info
  功    能：根据筛选条件，选出符合条件的信息并输出
  输入参数：char id[][8]：各个学生学号的二维字符数组
			char name[][NAME_LIMIT+1]：各个学生名字的二维字符数组
			int score[]：各个学生成绩的数组
  返 回 值：无
  说    明：无
***************************************************************************/
void print_selected_info(char id[][8], char name[][NAME_LIMIT + 1], int score[])
{
	int i, j;
	printf("\n及格学生(学号降序):\n");

	for (i = 0; i < STUDENT_NUMBER; i++) {
		if (score[i] >= 60) {  /*判断条件为及格*/
			printf("%s ", name[i]);

			for (j = 0; j < 8; j++) {
				printf("%c", id[i][j]);
			}

			printf(" %d\n", score[i]);
		}
	}
}

int main()
{
	char id[STUDENT_NUMBER][8];  /*学号数组*/
	char name[STUDENT_NUMBER][NAME_LIMIT + 1];  /*名字数组*/
	int score[STUDENT_NUMBER];  /*成绩数组*/

	input_info(id, name, score);  /*输入信息*/
	sort_info(id, name, score);   /*排列信息*/
	print_selected_info(id, name, score);  /*筛选、输出信息*/

	return 0;
}