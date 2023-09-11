/*2151294 信11 马威*/
#include <iostream>
#include <cmath>
using namespace std;

class triangle;  //类的提前声明，思考一下，放在这里的目的是为什么
class point {
private:
	int x;
	int y;
public:
	/* 仅允许在此添加一个成员函数【仅限1个】,要求体内实现 */

	void set(const int point_x, const int point_y) {  //输入两个参数给该点坐标赋值
		x = point_x;
		y = point_y;
	}
	friend triangle;  //声明类triangle为友元

	/* 除上面允许的那个成员函数外，不再允许添加任何的数据成员和成员函数，但可以根据需要添加其它内容 */
};

class triangle {
private:
	point p1;
	point p2;
	point p3;
public:
	/* 根据需要补充相应的语句后完成area函数(形参为空，不准改)，要求：如果三点能构成三角形，则返回面积，否则返回 -1 */
	double area()
	{
		bool if_x, if_in_line;  /*p1、p2确定直线是否竖直，p1、p2、p3是否共线*/

		/*判断p1、p2确定直线是否竖直*/
		if (p1.x == p2.x)
			if_x = true;
		else
			if_x = false;

		/*若竖直，比较p3、p1横坐标*/
		if (if_x) {
			if (p3.x != p1.x)  /*相等则三点共线*/
				if_in_line = false;
			else               /*不等则三点不共线*/
				if_in_line = true;
		}

		/*若不竖直，判断p3是否在p1、p2确定的直线上*/
		else {
			if ((p3.y - p1.y) * (p1.x - p2.x) == (p1.y - p2.y) * (p3.x - p1.x))
				if_in_line = true;
			else
				if_in_line = false;
		}

		if (if_in_line)
			return -1.0;  /*三点共线，返回-1*/
		else {
			int s[3];
			s[0] = p1.x * p2.y - p1.y * p2.x;
			s[1] = p2.x * p3.y - p2.y * p3.x;
			s[2] = p3.x * p1.y - p3.y * p1.x;
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

