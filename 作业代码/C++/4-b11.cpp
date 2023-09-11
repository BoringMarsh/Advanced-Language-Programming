/*2151294 ��11 ����*/
#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

/* -----------------------------------------------------------------------------------
		����   ��1����������һ�����������������������ӵĺ����в������κ���ʽ��ѭ��
				 2��������ų���
				 3������const�ͱ���

		������ ��1������ȫ�ֱ���
   ----------------------------------------------------------------------------------- */

   /***************************************************************************
	 �������ƣ�print_diamond_with_coordinate
	 ��    �ܣ����������ӡ����
	 ���������start_ch����ʼ��ĸ
	           end_ch����ֹ��ĸ
			   line������
			   location��ÿһ������ڼ�����ĸ
	 �� �� ֵ����
	 ˵    �����˺���Ϊ��1����Ӻ���
   ***************************************************************************/
void print_diamond_with_coordinate(char start_ch, char end_ch, int line, int location)
{
	/*1����һ�������޵��������*/
	if (line <= end_ch - start_ch + 1) {

		/*1.1���ڶ����޵��������*/
		if (location <= line) {

			/*1.1.1��ÿ������ĸ���������*/
			if (location == 1) {
				cout << setw(end_ch - start_ch + 2 - line) << char(start_ch + line - 1);
				print_diamond_with_coordinate(start_ch, end_ch, line, ++location);
			}

			/*1.1.3��������ĸ���������*/
			else {
				cout << char(start_ch + line - location);
				print_diamond_with_coordinate(start_ch, end_ch, line, ++location);
			}
		}

		/*1.2����һ���޵��������*/
		else {

			/*1.2.1�����з����������*/
			if (location > 2 * line - 1) {
				cout << endl;
				print_diamond_with_coordinate(start_ch, end_ch, ++line, 1);
			}

			/*1.2.2��������ĸ���������*/
			else {
				cout << char(start_ch - line + location);
				print_diamond_with_coordinate(start_ch, end_ch, line, ++location);
			}
		}
	}

	/*2�������������޵��������*/
	else if (line > end_ch - start_ch + 1 && line <= 2 * (end_ch - start_ch) + 1) {
		int chardistance = end_ch - start_ch;          /*��ʼ��ĸ����ֹ��ĸ�����ֵ*/
		int linedistance = line - (chardistance + 1);  /*�������������޵�ÿһ�������м�һ�е�������*/
		
		/*2.1���������޵��������*/
		if (location <= (chardistance + 1 - linedistance)) {  /*�ָ�λ=��ĸ��ֵ+1-������*/

			/*2.1.1��ÿ������ĸ���������*/
			if (location == 1) {
				cout << setw(linedistance + 1) << char(start_ch + chardistance - linedistance);  /*���=������+1������ĸ=��ʼ��ĸ+��ĸ��ֵ-������*/
				print_diamond_with_coordinate(start_ch, end_ch, line, ++location);
			}

			/*2.1.2��������ĸ���������*/
			else {
				cout << char(start_ch + chardistance - linedistance - location + 1);  /*������ĸ=����ĸ-location+1*/
				print_diamond_with_coordinate(start_ch, end_ch, line, ++location);
			}
		}

		/*2.2���������޵��������*/
		else {

			/*2.2.1�����з����������*/
			if (location > 2 * chardistance + 1 - 2 * linedistance) {  /*ÿ�������ĸ��=2*��ĸ��ֵ+1-2*������*/
				cout << endl;
				print_diamond_with_coordinate(start_ch, end_ch, ++line, 1);
			}

			/*2.2.2��������ĸ���������*/
			else {
				cout << char(start_ch + location - (2 * chardistance + 1 - 2 * linedistance + 1) / 2);  /*������ĸ=��ʼ��ĸ+location-(ÿ�������ĸ��+1)/2*/
				print_diamond_with_coordinate(start_ch, end_ch, line, ++location);
			}
		}
	}
}

   /***************************************************************************
	 �������ƣ�
	 ��    �ܣ���ӡ����
	 ���������
	 �� �� ֵ��
	 ˵    ����
   ***************************************************************************/
void print_diamond(char start_ch, char end_ch)
{
	print_diamond_with_coordinate(start_ch, end_ch, 1, 1);  /*����ʼ������Ϊ1��1������print_diamond_with_coordinate()����*/
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main����������...�����޸ģ�����λ�ò�׼�޸�
***************************************************************************/
int main()
{
	char end_ch;

	/* ������������ַ�(����д��Ч) */
	cout << "����������ַ�(A~Z)" << endl;
	end_ch = getchar();

	/* ����(�м�ΪA) */
	cout << setfill('=') << setw((end_ch - 'A') * 2 + 1) << "=" << endl; /* ��������������=(��������ѭ��) */
	cout << "����(" << end_ch << "->A)" << endl;
	cout << setfill('=') << setw((end_ch - 'A') * 2 + 1) << "=" << setfill(' ') << endl; /* ��������������=(��������ѭ��) */
	print_diamond('A', end_ch);
	cout << endl;

	return 0;
}