/*2151294 ��11 ����*/
#include <iostream>
#include<iomanip>
using namespace std;

int main()
{
    const double pi = 3.14159;            /*���峣��pi*/
    double r, h;                          /*��������뾶r���߶�h*/
    cout << "������뾶�͸߶�" << endl;   /*�����ʾ��*/
    cin >> r >> h;                        /*�������ֵ*/
    cout << setiosflags(ios::fixed);      /*���ø������Թ̶���С��λ����ʾ��Ϊ֮��������2λС�����̵�*/

    cout << setw(10) << setiosflags(ios::left) << "Բ�ܳ�";
    cout << " : " << setprecision(2) << 2 * pi * r << endl;

    cout << setw(10) << setiosflags(ios::left) << "Բ���";
    cout << " : " << setprecision(2) << pi * r * r << endl;

    cout << setw(10) << setiosflags(ios::left) << "Բ������";          /*�����ܿ��10������������ʾ�֣�����2λС�������������*/
    cout << " : " << setprecision(2) << 4 * pi * r * r << endl;

    cout << setw(10) << setiosflags(ios::left) << "Բ�����";
    cout << " : " << setprecision(2) << 4.0 / 3.0 * pi * r * r << endl;

    cout << setw(10) << setiosflags(ios::left) << "Բ�����";
    cout << " : " << setprecision(2) << pi * r * r * h << endl;
    return 0;
}