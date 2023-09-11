/*2151294 信11 马威*/
#include<iostream>
using namespace std;
int main()
{
	int light[101], i, people;     /*定义所需数组和变量，为标号方便，定义为light[101]，people是人的编号*/

	/*1到100号灯初始状态为熄灭，赋值为-1*/
	for (i = 1; i <= 100; i++) {
		light[i] = -1;
	}

	/*1号到100号循环操作，每操作一次，people倍数的light[i]乘以-1，代表状态变动*/
	for (people = 1; people <= 100; people++) {
		for (i = people; i <= 100; i) {
			light[i] = light[i] * (-1);
			i = i + people;
		}
	}

	/*操作完成后，逐个判断灯的状态，若为1，则该灯还在亮，输出编号*/
	for (i = 1; i <= 100; i++) {
		if (light[i] == 1) {
			cout << i << " ";
		}
	}

	/*去掉空格并换行*/
	cout << '\010' << endl;
	return 0;
}