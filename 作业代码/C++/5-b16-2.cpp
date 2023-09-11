/*2151294 ��11 ����*/
#include<iostream>
#include<cstring>
using namespace std;

#define STUDENT_NUMBER 10  /*ѧ������*/
#define NAME_LIMIT 8       /*ѧ�����ֳ���*/

/***************************************************************************
  �������ƣ�input_info
  ��    �ܣ�����ÿ��ѧ���ĸ�����Ϣ
  ���������string id[]������ѧ��ѧ�ŵ��ַ�������
            string name[]������ѧ�����ֵ��ַ�������
			int score[]������ѧ���ɼ�������
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void input_info(string id[], string name[], int score[])
{
	int i;
	for (i = 0; i < STUDENT_NUMBER; i++) {
		cout << "�������" << i + 1 << "���˵�ѧ�š��������ɼ�" << endl;
		cin >> id[i];
		cin >> name[i];
		cin >> score[i];
	}
}

/***************************************************************************
  �������ƣ�sort_info
  ��    �ܣ���������������ʹ��ѡ�񷨽�������
  ���������string id[]������ѧ��ѧ�ŵ��ַ�������
			string name[]������ѧ�����ֵ��ַ�������
			int score[]������ѧ���ɼ�������
  �� �� ֵ����
  ˵    ��������ʱ��ѧ���ĸ�����Ϣһ����ȫ������
***************************************************************************/
void sort_info(string id[], string name[], int score[])
{
	int i, j, k;  /*��������*/
	int tscore;   /*�����м����*/
	string tid, tname;  /*ѧ���м�����������м����*/

	/*ʹ��ѡ�񷨽������򣬽�������ʱ��ѧ���ĸ�����Ϣһ����ȫ������*/
	for (i = 0; i < STUDENT_NUMBER; i++) {
		k = i;

		for (j = i + 1; j < STUDENT_NUMBER; j++) {
			if (score[j] < score[k]) {  /*��������Ϊ�ɼ�����*/
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
  �������ƣ�print_selected_info
  ��    �ܣ�����ɸѡ������ѡ��������������Ϣ�����
  ���������string id[]������ѧ��ѧ�ŵ��ַ�������
			string name[]������ѧ�����ֵ��ַ�������
			int score[]������ѧ���ɼ�������
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void print_selected_info(string id[], string name[], int score[])
{
	int i;
	cout << endl << "������ѧ��(�ɼ�����):" << endl;

	for (i = 0; i < STUDENT_NUMBER; i++) {
		if (score[i] < 60) {  /*�ж�����Ϊ������*/
			cout << name[i];
			cout << " " << id[i];
			cout << " " << score[i] << endl;
		}
	}
}

int main()
{
	string id[STUDENT_NUMBER], name[STUDENT_NUMBER];  /*ѧ�����顢��������*/
	int score[STUDENT_NUMBER];  /*�ɼ�����*/

	input_info(id, name, score);  /*������Ϣ*/
	sort_info(id, name, score);   /*������Ϣ*/
	print_selected_info(id, name, score);  /*ɸѡ�������Ϣ*/

	return 0;
}