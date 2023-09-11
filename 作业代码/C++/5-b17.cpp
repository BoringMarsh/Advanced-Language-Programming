/*2151294 信11 马威*/
#include<iostream>
#include<Windows.h>
#include<time.h>
using namespace std;

#define CODE_LENGTH_MIN 12  /*密码长度下限*/
#define CODE_LENGTH_MAX 16  /*密码长度上限*/
#define UPPER_MIN  2  /*大写字母数量下限*/
#define LOWER_MIN  2  /*小写字母数量下限*/
#define NUMBER_MIN 2  /*数字数量下限*/
#define OTHER_MIN  2  /*其他字符数量下限*/

/*其他字符的数组*/
static const char other[] = "~!@#$%^&*()-_=+[],.?";

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

/***************************************************************************
  函数名称：print_error_info
  功    能：根据check_info()函数的错误返回值，选择输出错误提示
  输入参数：int code_length：密码长度
			int upper_num：大写字母最少数量
			int lower_num：小写字母最少数量
			int number_num：数字最少数量
			int other_num：其它字符最少数量
  返 回 值：无
  说    明：无
***************************************************************************/
void print_error_info(int ret, int code_length, int upper_num, int lower_num, int number_num, int other_num)
{
	/*输入非数字，第一类错误*/
	if (ret == 1)
		cout << "输入非法" << endl;

	/*密码长度不在指定范围内，第二类错误*/
	else if (ret == 2)
		cout << "密码长度[" << code_length << "]不正确" << endl;

	/*某类字符的最少数量不在指定范围内，第三类错误*/
	else if (ret == 3) {
		if (upper_num<UPPER_MIN || upper_num>code_length)
			cout << "大写字母个数[" << upper_num << "]不正确" << endl;

		else if (lower_num<LOWER_MIN || lower_num>code_length)
			cout << "小写字母个数[" << lower_num << "]不正确" << endl;

		else if (number_num<NUMBER_MIN || number_num>code_length)
			cout << "数字个数[" << number_num << "]不正确" << endl;

		else if (other_num<OTHER_MIN || other_num>code_length)
			cout << "其它符号个数[" << other_num << "]不正确" << endl;
	}

	/*所有类型的最少个数相加大于指定的密码长度，第四类错误*/
	else if (ret == 4)
		cout << "所有字符类型之和[" << upper_num << '+' << lower_num << '+' << number_num << '+' << other_num << "]大于总密码长度[" << code_length << "]" << endl;
}

int main()
{
	int code_length;  /*密码长度*/
	int upper_num, lower_num, number_num, other_num;  /*各种字符的最少数量*/
	int ret;  /*检查函数的返回值*/
	int i, j, k;  /*计数变量*/
	const char all[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789~!@#$%^&*()-_=+[],.?";  /*所有可用字符的数组*/

	srand((unsigned int)(time(0)));  /*随机数种子*/
	
	cout << "请输入密码长度(12-16)， 大写字母个数(≥" << UPPER_MIN
		<< ")， 小写字母个数(≥" << LOWER_MIN
		<< ")， 数字个数(≥" << NUMBER_MIN
		<< ")， 其它符号个数(≥" << OTHER_MIN << ")" << endl;
	cin >> code_length >> upper_num >> lower_num >> number_num >> other_num;  /*输入信息*/
	
	ret = check_info(code_length, upper_num, lower_num, number_num, other_num);  /*判断并返回值*/

	/*一、若输入正确，开始生成密码*/
	if (!ret) {
		cout << code_length << ' ' << upper_num << ' ' << lower_num << ' ' << number_num << ' ' << other_num << endl;  /*输出各项信息*/
		char code[CODE_LENGTH_MAX];  /*生成密码的字符数组*/
		int position;  /*字符输出的随机位置*/
		char upper, lower, number, OTHER;  /*输出的各类随机字符*/

		/*1、逐个输出10组密码*/
		for (k = 0; k < 10; k++) {

			/*2、每个密码中，逐个输出10个字符*/
			/*2.1、数组初始化*/
			for (i = 0; i < CODE_LENGTH_MAX; i++)
				code[i] = 0;

			/*2.2、输出大写字母（最少数量）*/
			for (i = 0; i < upper_num; i++) {
				upper = rand() % ('Z' - 'A' + 1) + 'A';  /*决定随机字母*/
				position = rand() % code_length;  /*决定随机位置*/

				/*若该位置已经有字符，不赋值，计数变量自减*/
				if (code[position])
					i--;

				/*若该位置为空，则赋值*/
				else
					code[position] = upper;
			}

			/*2.3、输出小写字母（最少数量）*/
			for (i = 0; i < lower_num; i++) {
				lower = rand() % ('z' - 'a' + 1) + 'a';  /*决定随机字母*/
				position = rand() % code_length;  /*决定随机位置*/

				/*若该位置已经有字符，不赋值，计数变量自减*/
				if (code[position])
					i--;

				/*若该位置为空，则赋值*/
				else
					code[position] = lower;
			}

			/*2.4、输出数字（最少数量）*/
			for (i = 0; i < number_num; i++) {
				number = rand() % 10 + '0';  /*决定随机数字*/
				position = rand() % code_length;  /*决定随机位置*/

				/*若该位置已经有字符，不赋值，计数变量自减*/
				if (code[position])
					i--;

				/*若该位置为空，则赋值*/
				else
					code[position] = number;
			}

			/*2.5、输出其他字符（最少数量）*/
			for (i = 0; i < other_num; i++) {
				OTHER = other[rand() % 20];  /*决定随机字符*/
				position = rand() % code_length;  /*决定随机位置*/

				/*若该位置已经有字符，不赋值，计数变量自减*/
				if (code[position])
					i--;

				/*若该位置为空，则赋值*/
				else
					code[position] = OTHER;
			}

			/*2.6、统计仍为空字符数*/
			j = 0;
			for (i = 0; i < code_length; i++) {
				if (code[i] == 0)
					j++;
			}

			/*2.7、保证各种字符的最少数量情况下，在所有可用字符的范围内随机输出字符，直到填满为止*/
			for (i = 0; i < j; i++) {
				OTHER = all[rand() % 82];  /*决定随机字符*/
				position = rand() % code_length;  /*决定随机位置*/

				/*若该位置已经有字符，不赋值，计数变量自减*/
				if (code[position])
					i--;

				/*若该位置为空，则赋值*/
				else
					code[position] = OTHER;
			}

			/*输出完成一组密码后输出*/
			for (i = 0; i < code_length; i++)
				cout << code[i];

			/*换行*/
			cout << endl;
		}
	}

	/*二、若输入错误，输出提示后退出程序*/
	else
		print_error_info(ret, code_length, upper_num, lower_num, number_num, other_num);

	return 0;
}