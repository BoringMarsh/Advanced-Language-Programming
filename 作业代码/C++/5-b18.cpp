/*2151294 信11 马威*/
#include<iostream>
#include<Windows.h>
#include<time.h>
using namespace std;

/*其他字符的数组*/
static const char other[] = "~!@#$%^&*()-_=+[],.?";

#define CODE_LENGTH_MIN 12  /*密码长度下限*/
#define CODE_LENGTH_MAX 16  /*密码长度上限*/
#define UPPER_MIN  2  /*大写字母数量下限*/
#define LOWER_MIN  2  /*小写字母数量下限*/
#define NUMBER_MIN 2  /*数字数量下限*/
#define OTHER_MIN  2  /*其他字符数量下限*/

/***************************************************************************
  函数名称：check_info
  功    能：综合输入的各项信息，判断输入是否正确
  输入参数：int code_length：密码长度
			int upper_num：大写字母最少数量
			int lower_num：小写字母最少数量
			int number_num：数字最少数量
			int other_num：其它字符最少数量
  返 回 值：整数
  说    明：返回值含义：非零数-输入错误；零-输入正确
***************************************************************************/
int check_info(int code_length, int upper_num, int lower_num, int number_num, int other_num)
{
	/*输入非数字，第一类错误，返回1*/
	if (!cin.good())
		return 1;

	/*密码长度不在指定范围内，第二类错误，返回2*/
	else if (code_length<CODE_LENGTH_MIN || code_length>CODE_LENGTH_MAX)
		return 2;

	/*某类字符的最少数量不在指定范围内，第三类错误，返回3*/
	else if (upper_num<UPPER_MIN || upper_num>code_length
		|| lower_num<LOWER_MIN || lower_num>code_length
		|| number_num<NUMBER_MIN || number_num>code_length
		|| other_num<OTHER_MIN || other_num>code_length)
		return 3;

	/*所有类型的最少个数相加大于指定的密码长度，第四类错误，返回4*/
	else if (upper_num + lower_num + number_num + other_num > code_length)
		return 4;

	/*正确，返回0*/
	else
		return 0;
}

int main()
{
	char notice[200];  /*存放提示语的字符数组*/
	int i, j, k;       /*计数变量*/
	int code_length;   /*密码长度*/
	int upper_num, lower_num, number_num, other_num;    /*各种字符的最少数量*/
	int ret;  /*检查函数的返回值*/
	char code[10][CODE_LENGTH_MAX];  /*存放待检测密码的二维数组*/
	bool prime = true;  /*标志密码是否正确的变量，初始为真*/

	fgets(notice, 200, stdin);  /*输入、读取开头一行的提示语，方便重定向*/

	cin >> code_length >> upper_num >> lower_num >> number_num >> other_num;  /*输入信息*/

	ret = check_info(code_length, upper_num, lower_num, number_num, other_num);  /*判断并返回值*/

	/*一、若输入正确，开始判断*/
	if (!ret) {

		/*各种字符的计数变量，初始为0*/
		int upper_count = 0, lower_count = 0, number_count = 0, other_count = 0, length_count = 0;

		/*1、逐个检测10组密码*/
		for (i = 0; i < 10; i++) {

			/*2、每个密码中，逐个检测10个字符*/
			/*2.1、每一次输入一个字符，长度计数变量自增*/
			for (j = 0; j < code_length; j++) {
				cin >> code[i][j];
				length_count++;

				/*2.2、检测出大写字母，大写字母计数变量自增*/
				if (code[i][j] >= 'A' && code[i][j] <= 'Z')
					upper_count++;

				/*2.3、检测出小写字母，小写字母计数变量自增*/
				else if (code[i][j] >= 'a' && code[i][j] <= 'z')
					lower_count++;

				/*2.4、检测出数字，数字计数变量自增*/
				else if (code[i][j] >= '0' && code[i][j] <= '9')
					number_count++;

				/*2.5、检测出其他字符，其他字符计数变量自增*/
				else {
					for (k = 0; k < 20; k++) {
						if (code[i][j] == other[k]) {
							other_count++;
							break;
						}
					}
				}

				/*2.6、每一组密码检测完成，判断结果*/
				if (j == code_length - 1) {

					/*2.6.1、若各项字符数量小于最小数量、密码长度错误、各项字符数之和不符，变量为假*/
					if (upper_count < upper_num || lower_count < lower_num || number_count < number_num || other_count < other_num
						|| length_count != code_length
						|| upper_count + lower_count + number_count + other_count != code_length)
						prime = false;

					/*2.6.2、若结果正确，各项计数变量归零，准备下一次检测*/
					else {
						upper_count = 0;
						lower_count = 0;
						number_count = 0;
						other_count = 0;
						length_count = 0;
					}
				}
			}
		}

		/*3、根据10组密码最终检测结果，输出判断*/
		if (prime)
			cout << "正确" << endl;
		else
			cout << "错误" << endl;
	}

	/*二、若输入错误，输出判断，结束程序*/
	else  {
		cout << "错误" << endl;
	}

	return 0;
}