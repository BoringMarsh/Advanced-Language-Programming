/*2151294 信11 马威*/
#include <iostream>
#include <cmath>
using namespace std;

class point {
private:
	int x;
	int y;
	//除上面的两个private数据成员外，不再允许添加任何类型的数据成员
public:
	int getx() const
	{
		return x;
	}
	int gety() const
	{
		return y;
	}
	void set(const int point_x, const int point_y) {  //输入两个参数给该点坐标赋值
		x = point_x;
		y = point_y;
	}
	/* 可以定义需要的成员函数，数量不限，并以体内方式实现，不允许添加数据成员 */

};

class triangle {
private:
	point p1;
	point p2;
	point p3;
	//除上面的三个private数据成员外，不再允许添加任何类型的数据成员
public:
	/* 根据需要补充相应的语句后完成area函数(形参为空，不准改)，要求：如果三点能构成三角形，则返回面积，否则返回 -1 */
	double area()
	{
		bool if_x, if_in_line;  /*p1、p2确定直线是否竖直，p1、p2、p3是否共线*/

		/*取好各点横纵坐标*/
		int p1_x = p1.getx();
		int p1_y = p1.gety();
		int p2_x = p2.getx();
		int p2_y = p2.gety();
		int p3_x = p3.getx();
		int p3_y = p3.gety();

		/*判断p1、p2确定直线是否竖直*/
		if (p1_x == p2_x)
			if_x = true;
		else
			if_x = false;

		/*若竖直，比较p3、p1横坐标*/
		if (if_x) {
			if (p3_x != p1_x)  /*相等则三点共线*/
				if_in_line = false;
			else               /*不等则三点不共线*/
				if_in_line = true;
		}

		/*若不竖直，判断p3是否在p1、p2确定的直线上*/
		else {
			if ((p3_y - p1_y) * (p1_x - p2_x) == (p1_y - p2_y) * (p3_x - p1_x))
				if_in_line = true;
			else
				if_in_line = false;
		}

		if (if_in_line)
			return -1.0;  /*三点共线，返回-1*/
		else {
			int s[3];
			s[0] = p1_x * p2_y - p1_y * p2_x;
			s[1] = p2_x * p3_y - p2_y * p3_x;
			s[2] = p3_x * p1_y - p3_y * p1_x;
			int sum = s[0] + s[1] + s[2];
			return fabs(double(sum)) / 2.0;  /*三点不共线，返回面积*/
		}

	}
	/* 构造函数 */
	triangle(int p1_x, int p1_y, int p2_x, int p2_y, int p3_x, int p3_y)
	{
		/* 给p1/p2/p3三个点分别赋x,y坐标值 */
		p1.set(p1_x, p1_y);
		p2.set(p2_x, p2_y);
		p3.set(p3_x, p3_y);
	}
	/* 可以定义需要的成员函数，数量不限，并以体内方式实现，不允许添加数据成员 */

};

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数不准动
***************************************************************************/
int main()
{
	if (1) {
		triangle tr(0, 0, 0, 1, 1, 0);  //三角形为(0,0) (0,1) (1,0)三点组成
		cout << "三角形面积应该是：0.5，实际是：" << tr.area() << endl;
		}

	if (1) {
		triangle tr(0, 2, -1, -1, 1, -1);  //三角形为(0,2) (-1,-1) (1,-1)三点组成
		cout << "三角形面积应该是：3，  实际是：" << tr.area() << endl;
		}

	if (1) {
		triangle tr(5, 5, -3, 1, 9, -2);  //三角形为(5,5) (-3,1) (9,-2)三点组成
		cout << "三角形面积应该是：36， 实际是：" << tr.area() << endl;
		}

	if (1) {
		triangle tr(0, 0, 1, 1, 2, 2);  //三点共线
		cout << "三角形面积应该是：-1， 实际是：" << tr.area() << endl;
	}

	return 0;
}

