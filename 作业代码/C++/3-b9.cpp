/*2151294 信11 马威*/
#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int r, c;     /*定义所需变量，r是行数，c是列数*/

	/*从1到9，逐个输出每一行*/
	for (r = 1; r <= 9; r++) {

		/*从1到9，逐个输出r行的每一列对应的算式*/
		for (c = 1; c <= 9; c++) {
			if (c < r) {        /*列数小于行数，正常打印算式*/
				cout << c << "x" << r << "=" << setiosflags(ios::left) << setw(4) << c * r;
			}

			else if (c == r) {  /*列数等于行数，打印算式后换行*/
				cout << c << "x" << r << "=" << setiosflags(ios::left) << setw(4) << c * r << endl;
			}
		}
	}

	return 0;
}