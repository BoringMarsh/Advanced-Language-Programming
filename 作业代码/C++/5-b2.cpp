/*2151294 ��11 ����*/
#include<iostream>
using namespace std;
int main()
{
	int light[101], i, people;     /*������������ͱ�����Ϊ��ŷ��㣬����Ϊlight[101]��people���˵ı��*/

	/*1��100�ŵƳ�ʼ״̬ΪϨ�𣬸�ֵΪ-1*/
	for (i = 1; i <= 100; i++) {
		light[i] = -1;
	}

	/*1�ŵ�100��ѭ��������ÿ����һ�Σ�people������light[i]����-1������״̬�䶯*/
	for (people = 1; people <= 100; people++) {
		for (i = people; i <= 100; i) {
			light[i] = light[i] * (-1);
			i = i + people;
		}
	}

	/*������ɺ�����жϵƵ�״̬����Ϊ1����õƻ�������������*/
	for (i = 1; i <= 100; i++) {
		if (light[i] == 1) {
			cout << i << " ";
		}
	}

	/*ȥ���ո񲢻���*/
	cout << '\010' << endl;
	return 0;
}