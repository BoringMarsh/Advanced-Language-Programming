/*2151294 ��11 ����*/
#include<iostream>
#include<cmath>  /*������ʹ�����Һ���sin(x)����include��ͷ�ļ�*/
#include<iomanip>
using namespace std;

int main()
{
	const float pi = 3.14159f;  /*���峣��pi*/
	int l, w, angle;            /*�������һ�߳�l����һ�߳�w�����߼н�angle���Ƕ��ƣ�*/
	float S, rad;               /*������������ε����S�����߼н�rad�������ƣ�*/

	cout << "�����������ε����߼���н�(�Ƕ�)" << endl;  /*�����ʾ��*/
	cin >> l >> w >> angle;                              /*�������ֵ*/
	rad = angle / 180.0f * pi;                           /*����нǶ�Ӧ�Ļ���*/
	S = 1.0f / 2.0f * l * w * sin(rad);                  /*���������ε������ʽ������*/
	cout << "���������Ϊ : " << setiosflags(ios::fixed) << setprecision(3) << S << endl;  /*�����ܿ��10������������ʾ�֣�����3λС�����������*/

	return 0;
}