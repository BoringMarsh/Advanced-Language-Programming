/*2151294 信11 马威*/
/*2151300 王蔚达 1853015 陈鑫 2150244 黄隽阳 2150245 沈谦 2153488 张梓乔 2153833 周睿彦 2151521 张志恒*/
#include <iostream>
#include <fstream>
using namespace std;

/***************************************************************************
  函数名称：hex_to_dec
  功    能：将字符形式的两位十六进制ASCII码转换成十进制
  输入参数：const char ASCII[]：存放待转换进制ASCII码的字符数组（只读）
  返 回 值：char：对应的十进制ASCII码（为了方便后续输出，返回为char型）
  说    明：无
***************************************************************************/
char hex_to_dec(const char ASCII[])
{
	int i, x[2];

	for (i = 0; i < 2; i++) {
		if (ASCII[i] >= 'a' && ASCII[i] <= 'f')  /*A-F的转换*/
			x[i] = ASCII[i] - 'a' + 10;
		else                              /*0-9的转换*/
			x[i] = ASCII[i] - '0';
	}

	return 16 * x[0] + x[1];  /*转换成十进制后返回*/
}

int main()
{
	ifstream reader;  /*读流对象*/
	ofstream writer;  /*写流对象*/
	char src[256];  /*存放待转换文件名的字符数组*/
	char dst[256];  /*存放转换后文件名的字符数组*/

	clog << "文件名以下形式均可以:" << endl
		<< "    a.hex                    : 不带路径形式" << endl
		<< "    ..\\data\\b.txt          : 相对路径形式" << endl
		<< "    C:\\Windows\\System32\\c.hex : 绝对相对路径形式" << endl
		<< "请输入文件名 : ";
	cin >> src;
	clog << "请输入转换后的文件名        :";
	cin >> dst;

	/*1、判断待转换文件打开状态*/
	reader.open(src, ios::in);
	if (!reader) {
		clog << "输入文件" << src << "打开失败!" << endl;
		return 0;
	}

	/*2、判断转换后文件打开状态*/
	writer.open(dst, ios::out | ios::binary);  /*使用ios::binary方式打开，遇到\x0A时只写入一个\x0A，不产生多余的\x0D*/
	if (!writer) {
		clog << "输出文件" << dst << "打开失败!" << endl;
		return 0;
	}

	int count = 0;  /*位置计数器，文件指针每移动一格，该变量自增*/
	int loop = 1;
	char ascii[2];  /*存放两位十六进制待转换的ASCII码的字符数组*/
	reader.seekg(0, ios::beg);  /*文件指针指向开始位置*/

	
	while (reader.peek() != EOF && loop != 0) {

		/*文件一行最多82个字符，若为一行的开始，移动指针使其忽略开头的偏移量以及空格*/
		if (count % 82 == 0) {
			count = count + 10;
			reader.seekg(count, ios::beg);
		}

		/*3、读每一行前八个字符*/
		while (1) {
			if (reader.peek() == ' ') {  /*如果遇到空格，说明这一行的字符未满8个，结束检查*/
				loop = 0;
				break;
			}

			else if (reader.peek() == '-')  /*如果遇到横杠，说明这一行前8个字符已读取，结束这部分的检查*/
				break;

			for (int i = 0; i < 2; i++) {  /*两位十六进制ASCII码一次读取，赋给数组ascii[]的对应元素*/
				ascii[i] = reader.peek();
				count++;  /*位置计数每读一位自增*/
				reader.seekg(count, ios::beg);  /*读完后移动文件指针至下一位置*/
			}

			count++;
			reader.seekg(count, ios::beg);  /*自增并移动指针，为了忽略每个字符两位ASCII后的空格*/
			writer << hex_to_dec(ascii);    /*将取得的两位十六进制ASCII码通过函数转换后写入转换后文件*/
		}
		
		/*4、若上一部分结束，文件指针指向横杠，说明这一行前8个字符已读取，忽略横杠及后面的一个空格*/
		if (reader.peek() == '-') {
			count = count + 2;
			reader.seekg(count, ios::beg);
		}

		/*5、若前8个字符读取没有中途停止，loop不为零，读取后8个字符*/
		if (loop) {
			for (int i = 0; i < 8; i++) {
				for (int j = 0; j < 2; j++) {  /*两位十六进制ASCII码一次读取，赋给数组ascii[]的对应元素*/
					ascii[j] = reader.peek();
					count++;  /*位置计数每读一位自增*/
					reader.seekg(count, ios::beg);  /*读完后移动文件指针至下一位置*/
				}

				count++;
				reader.seekg(count, ios::beg);  /*自增并移动指针，为了忽略每个字符两位ASCII后的空格*/
				writer << hex_to_dec(ascii);    /*将取得的两位十六进制ASCII码通过函数转换后写入转换后文件*/

				if (reader.peek() == ' ' && i != 7) {  /*若遇到了空格且i不为7，则说明这一行元素不足16个，结束检查*/
					loop = 0;
					break;
				}

				else if (reader.peek() == ' ' && i == 7) {  /*若遇到了空格且i为7，则说明这一行元素全部读取完毕*/
					count = count + 22;
					reader.seekg(count, ios::beg);  /*文件指针移动22位，忽略该行后面的所有内容，指向下一行首位*/
				}
			}
		}
	}

	reader.close();  /*关闭文件*/
	writer.close();  /*关闭转换后的文件*/
	return 0;
}