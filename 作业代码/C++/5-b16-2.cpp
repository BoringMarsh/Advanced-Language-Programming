/*2151294 信11 马威*/
#include<iostream>
#include<cstring>
using namespace std;

#define STUDENT_NUMBER 10  /*学生数量*/
#define NAME_LIMIT 8       /*学生名字长度*/

/***************************************************************************
  函数名称：input_info
  功    能：输入每个学生的各项信息
  输入参数：string id[]：各个学生学号的字符串数组
            string name[]：各个学生名字的字符串数组
			int score[]：各个学生成绩的数组
  返 回 值：无
  说    明：无
***************************************************************************/
void input_info(string id[], string name[], int score[])
{
	int i;
	for (i = 0; i < STUDENT_NUMBER; i++) {
		cout << "请输入第" << i + 1 << "个人的学号、姓名、成绩" << endl;
		cin >> id[i];
		cin >> name[i];
		cin >> score[i];
	}
}

/***************************************************************************
  函数名称：sort_info
  功    能：根据排序条件，使用选择法进行排序
  输入参数：string id[]：各个学生学号的字符串数组
			string name[]：各个学生名字的字符串数组
			int score[]：各个学生成绩的数组
  返 回 值：无
  说    明：交换时将学生的各项信息一次性全部交换
***************************************************************************/
void sort_info(string id[], string name[], int score[])
{
	int i, j, k;  /*计数变量*/
	int tscore;   /*分数中间变量*/
	string tid, tname;  /*学号中间变量、名字中间变量*/

	/*使用选择法进行排序，交换交换时将学生的各项信息一次性全部交换*/
	for (i = 0; i < STUDENT_NUMBER; i++) {
		k = i;

		for (j = i + 1; j < STUDENT_NUMBER; j++) {
			if (score[j] < score[k]) {  /*排序条件为成绩升序*/
				k = j;
			}
		}

		tscore = score[k];
		score[k] = score[i];
		score[i] = tscore;

		tid = id[k];
		id[k] = id[i];
		id[i] = tid;

		tname = name[k];
		name[k] = name[i];
		name[i] = tname;
	}
}

/***************************************************************************
  函数名称：print_selected_info
  功    能：根据筛选条件，选出符合条件的信息并输出
  输入参数：string id[]：各个学生学号的字符串数组
			string name[]：各个学生名字的字符串数组
			int score[]：各个学生成绩的数组
  返 回 值：无
  说    明：无
***************************************************************************/
void print_selected_info(string id[], string name[], int score[])
{
	int i;
	cout << endl << "不及格学生(成绩升序):" << endl;

	for (i = 0; i < STUDENT_NUMBER; i++) {
		if (score[i] < 60) {  /*判断条件为不及格*/
			cout << name[i];
			cout << " " << id[i];
			cout << " " << score[i] << endl;
		}
	}
}

int main()
{
	string id[STUDENT_NUMBER], name[STUDENT_NUMBER];  /*学号数组、名字数组*/
	int score[STUDENT_NUMBER];  /*成绩数组*/

	input_info(id, name, score);  /*输入信息*/
	sort_info(id, name, score);   /*排列信息*/
	print_selected_info(id, name, score);  /*筛选、输出信息*/

	return 0;
}