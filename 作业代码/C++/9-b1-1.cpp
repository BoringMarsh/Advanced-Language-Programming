/*2151294 ��11 ����*/
#include <iostream>
#include <cmath>
using namespace std;

class point {
private:
	int x;
	int y;
	//�����������private���ݳ�Ա�⣬������������κ����͵����ݳ�Ա
public:
	int getx() const
	{
		return x;
	}
	int gety() const
	{
		return y;
	}
	void set(const int point_x, const int point_y) {  //���������������õ����긳ֵ
		x = point_x;
		y = point_y;
	}
	/* ���Զ�����Ҫ�ĳ�Ա�������������ޣ��������ڷ�ʽʵ�֣�������������ݳ�Ա */

};

class triangle {
private:
	point p1;
	point p2;
	point p3;
	//�����������private���ݳ�Ա�⣬������������κ����͵����ݳ�Ա
public:
	/* ������Ҫ������Ӧ���������area����(�β�Ϊ�գ���׼��)��Ҫ����������ܹ��������Σ��򷵻���������򷵻� -1 */
	double area()
	{
		bool if_x, if_in_line;  /*p1��p2ȷ��ֱ���Ƿ���ֱ��p1��p2��p3�Ƿ���*/

		/*ȡ�ø����������*/
		int p1_x = p1.getx();
		int p1_y = p1.gety();
		int p2_x = p2.getx();
		int p2_y = p2.gety();
		int p3_x = p3.getx();
		int p3_y = p3.gety();

		/*�ж�p1��p2ȷ��ֱ���Ƿ���ֱ*/
		if (p1_x == p2_x)
			if_x = true;
		else
			if_x = false;

		/*����ֱ���Ƚ�p3��p1������*/
		if (if_x) {
			if (p3_x != p1_x)  /*��������㹲��*/
				if_in_line = false;
			else               /*���������㲻����*/
				if_in_line = true;
		}

		/*������ֱ���ж�p3�Ƿ���p1��p2ȷ����ֱ����*/
		else {
			if ((p3_y - p1_y) * (p1_x - p2_x) == (p1_y - p2_y) * (p3_x - p1_x))
				if_in_line = true;
			else
				if_in_line = false;
		}

		if (if_in_line)
			return -1.0;  /*���㹲�ߣ�����-1*/
		else {
			int s[3];
			s[0] = p1_x * p2_y - p1_y * p2_x;
			s[1] = p2_x * p3_y - p2_y * p3_x;
			s[2] = p3_x * p1_y - p3_y * p1_x;
			int sum = s[0] + s[1] + s[2];
			return fabs(double(sum)) / 2.0;  /*���㲻���ߣ��������*/
		}

	}
	/* ���캯�� */
	triangle(int p1_x, int p1_y, int p2_x, int p2_y, int p3_x, int p3_y)
	{
		/* ��p1/p2/p3������ֱ�x,y����ֵ */
		p1.set(p1_x, p1_y);
		p2.set(p2_x, p2_y);
		p3.set(p3_x, p3_y);
	}
	/* ���Զ�����Ҫ�ĳ�Ա�������������ޣ��������ڷ�ʽʵ�֣�������������ݳ�Ա */

};

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main������׼��
***************************************************************************/
int main()
{
	if (1) {
		triangle tr(0, 0, 0, 1, 1, 0);  //������Ϊ(0,0) (0,1) (1,0)�������
		cout << "���������Ӧ���ǣ�0.5��ʵ���ǣ�" << tr.area() << endl;
		}

	if (1) {
		triangle tr(0, 2, -1, -1, 1, -1);  //������Ϊ(0,2) (-1,-1) (1,-1)�������
		cout << "���������Ӧ���ǣ�3��  ʵ���ǣ�" << tr.area() << endl;
		}

	if (1) {
		triangle tr(5, 5, -3, 1, 9, -2);  //������Ϊ(5,5) (-3,1) (9,-2)�������
		cout << "���������Ӧ���ǣ�36�� ʵ���ǣ�" << tr.area() << endl;
		}

	if (1) {
		triangle tr(0, 0, 1, 1, 2, 2);  //���㹲��
		cout << "���������Ӧ���ǣ�-1�� ʵ���ǣ�" << tr.area() << endl;
	}

	return 0;
}

