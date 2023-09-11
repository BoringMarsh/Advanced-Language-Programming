/*2151294 信11 马威*/
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main()
{
	ifstream file;
	char location[256];  /*存放文件名的字符数组*/

	clog << "文件名以下形式均可以:" << endl
		<< "    a.txt                    : 不带路径形式" << endl
		<< "    ..\\data\\b.dat          : 相对路径形式" << endl
		<< "    C:\\Windows\\System32\\c.dat : 绝对相对路径形式" << endl
		<< "请输入文件名 : ";

	cin >> location;  /*输入文件名*/
	file.open(location, ios::in | ios::binary);  /*以输入方式、二进制方式（可处理\x1A）打开文件*/

	/*1、判断文件打开状态*/
	if (!file) {
		cout << "输入文件" << location << "打开失败!" << endl;
		return 0;
	}

	int count = 0, line = 0;  /*字符数计数、行数计数*/
	int c[16];                /*存放当前行内16个字符ASCII的数组*/
	file.seekg(0, ios::beg);  /*将文件指针指向文件开始*/

	/*若当前指向文件结束符，则结束循环*/
	while (file.peek() != EOF) {

		/*2、打印该行首字符在文件中的位置*/
		if (count % 16 == 0) {
			cout << setw(7) << setfill('0') << line;
			cout << "0  ";
		}

		/*3、以十六进制输出当前指针指向字符的ASCII，若十六进制表示为一位数，则手动补字符0*/
		if (file.peek() < '\x10')
			cout << '0' << hex << file.peek();
		else
			cout << hex << file.peek();

		/*4、当前指针指向字符的ASCII对应赋给数组中的元素*/
		c[count % 16] = file.peek();
		
		/*5、输出一个字符完成，计数变量自增*/
		count++;

		/*6、若刚才输出完成的字符不在一行的中间或末尾，输出两个空格，控制宽度为4*/
		if (count % 8 != 0)
			cout << " ";

		/*7、移动文件指针*/
		file.seekg(count, ios::beg);

		/*8、输出每行中间的横杠*/
		if (count % 8 == 0 && count % 16 != 0) {
			if (file.peek() != EOF)  /*若每行第8个字符下一个不为结束符，则输出横杠，否则不输出*/
				cout << " - ";
		}

		/*9、若能输出到一行的末尾*/
		if (count % 16 == 0) {
			cout << "     ";
			for (int i = 0; i < 16; i++) {  /*按照数组中的ASCII输出字符*/
				if (c[i] >= 33 && c[i] <= 126)
					cout << char(c[i]);
				else
					cout << '.';
				c[i] = 0;  /*同时数组清空，准备接收下一行字符的ASCII*/
			}
			cout << endl;  /*每一行结束时的换行*/
			line++;  /*行计数变量自增*/
		}

		/*10、若未能输出到一行的末尾而遇到了结束符*/
		else if (count % 16 != 0 && file.peek() == EOF) {

			/*输出空格*/
			if (count % 16 < 8) {
				for (int i = 0; i < (-3) * (count % 16) + 54; i++)
					cout << ' ';
			}
			
			else {
				for (int i = 0; i < (-3) * (count % 16) + 52; i++)
					cout << ' ';
			}

			if (count % 8 == 0)
				cout << "   ";

			for (int i = 0; i < count % 16; i++) {  /*按照数组中的ASCII输出字符（防止数组越界）*/
				if (c[i] >= 33 && c[i] <= 126)
					cout << char(c[i]);
				else
					cout << '.';
			}
			cout << endl;  /*结束时的换行*/
		}
	}

	file.close();  /*关闭文件*/
	return 0;
}