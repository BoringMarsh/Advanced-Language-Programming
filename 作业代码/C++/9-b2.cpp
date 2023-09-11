/*2151294 信11 马威*/

/* 允许按需加入系统的宏定义、需要的头文件等 */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;

#define MAX_STU_NUM			256	//约定最大人数为256人（两轮的总和，包括退选、补选）
#define MAX_NAME_LEN			32	//学生姓名的最大长度不超过16个汉字
#define MAX_FILENAME_LEN		256	//文件名的最大长度

/* stu_info 类存放每个学生的信息，包括学号、姓名、其它需要的私有信息，已有内容不准动，可加入符合限制要求的新内容 */
class stu_list;  //提前声明，用于声明友元
class stu_info {
private:
	int  stu_no;			//学号
	char stu_name[MAX_NAME_LEN];	//姓名
	char stu_id[8];         //学号（字符形式）
	bool first_choice = false;   //第一轮是否选课
	bool second_choice = false;  //第二轮是否选课

	friend stu_list;  //声明stu_list为友元类

	void stu_no_trans();  //将char stu_id[8]转换为int stu_no
	/* 允许按需加入private数据成员、成员函数以及其它需要的内容 */

public:
	/* 本类不允许定义任何的公有数据成员、成员函数 */
};

/* stu_list 类整个选课信息，已有内容不准动，可加入符合限制要求的新内容 */
class stu_list {
private:
	stu_info stu[MAX_STU_NUM + 1];
	stu_info* p;
	int first_stu_num = 0;   //第一轮选课人数
	int second_stu_num = 0;  //第二轮新增人数
	/* 允许按需加入private数据成员和成员函数 */

public:
	int read(const char* filename, const int append = 0);	//从文件中读入选课信息并进行处理，第2个参数值为0表示覆盖方式，1表示追加方式
	int print(const char *prompt = NULL);			//打印当前读入的选课名单
	void stu_order_set();             //将学生信息排序
	/* 允许按需加入其它public成员函数 */

};

/* --- 此处给出上面两个类的成员函数的体外实现 --- */
/***************************************************************************
  函数名称：stu_no_trans
  功    能：将字符形式的学号转换为整型
  输入参数：无
  返 回 值：无
  属于类：stu_info
  属性：private
***************************************************************************/
void stu_info::stu_no_trans()
{
	int i, j;

	for (i = 0; i < 7; i++) {
		int ten_pow = 1;

		if (i != 6) {  /*个位时不用计算n次方*/
			for (j = 0; j < 6 - i; j++)
				ten_pow = ten_pow * 10;  /*计算10的6-i次方*/
		}
		
		stu_no = stu_no + (stu_id[i] - '0') * ten_pow;  /*累加得到整型学号*/
	}
}

/***************************************************************************
  函数名称：read
  功    能：从文件中读取学生信息，并赋给对象数组
  输入参数：const char* filename：文件名（只读）
            const int append：保存方式（只读）
  返 回 值：int：文件打开是否正常
  属于类：stu_list
  属性：public
***************************************************************************/
int stu_list::read(const char* filename, const int append)
{
	ifstream reader(filename, ios::in | ios::binary);  /*读流对象*/

	if (!reader) {
		cout << "文件[" << filename << "]打开失败";
		return -1;
	}

	int count = 0;
	int i;
	reader.seekg(count, ios::beg);

	/*覆盖方式*/
	if (append == 0) {
		p = stu;  /*类指针指向对象数组首地址*/

		while (1) {
			i = 0;  /*读学号*/
			while (1) {
				if (reader.peek() == '\x09') {
					p->stu_id[i] = '\0';  /*补上尾零，方便后续strcmp*/
					break;
				}

				p->stu_id[i] = reader.peek();   /*将读到的字符赋给字符数组*/
				i++, count++;
				reader.seekg(count, ios::beg);  /*移动文件指针*/
			}
			p->stu_no_trans();  /*转换为整型学号*/

			/*跳过\x09*/
			count++;
			reader.seekg(count, ios::beg);

			i = 0;  /*读姓名*/
			while (1) {
				if (reader.peek() == '\r') {
					p->stu_name[i] = '\0';  /*补上尾零，方便后续strcmp*/
					break;
				}

				p->stu_name[i] = reader.peek();  /*将读到的字符赋给字符数组*/
				i++, count++;
				reader.seekg(count, ios::beg);   /*移动文件指针*/
			}

			/*跳过\r、\n*/
			count = count + 2;
			reader.seekg(count, ios::beg);

			p->first_choice = true;  /*标记该生为第一轮已选课*/

			if (reader.peek() != EOF) {  /*若未遇到文件结束符，类指针移动，第一轮选课人数自增*/
				p++, first_stu_num++;
			}

			else  /*若遇到文件结束符则停止读取*/
				break;
		}
	}

	/*追加方式*/
	else {
		int new_student_num = 0;  /*第二轮新增人数，初始为零*/

		while(1) {
			int student_number = 0;  /*当前学生整型学号*/
			char student_id[8];      /*当前学生字符型学号*/
			char student_name[MAX_NAME_LEN];  /*当前学生姓名*/

			i = 0;  /*读学号*/
			while (1) {
				if (reader.peek() == '\x09') {
					student_id[i] = '\0';  /*补上尾零，方便后续strcmp*/
					break;
				}

				student_id[i] = reader.peek();  /*将读到的字符赋给字符数组*/
				i++, count++;
				reader.seekg(count, ios::beg);  /*移动文件指针*/
			}
			
			/*跳过\x09*/
			count++;
			reader.seekg(count, ios::beg);

			i = 0;  /*读姓名*/
			while (1) {
				if (reader.peek() == '\r') {
					student_name[i] = '\0';  /*补上尾零，方便后续strcmp*/
					break;
				}

				student_name[i] = reader.peek();  /*将读到的字符赋给字符数组*/
				i++, count++;
				reader.seekg(count, ios::beg);    /*移动文件指针*/
			}

			/*跳过\r、\n*/
			count = count + 2;
			reader.seekg(count, ios::beg);
			
			/*判断该生是否在第一轮选课中出现*/
			p = stu;
			bool prime = false;

			while (p - stu <= first_stu_num) {
				if (strcmp(student_id, p->stu_id) == 0) {  /*若与第一轮的学生有学号相同的，prime设为真*/
					prime = true;
					break;
				}

				else
					p++;
			}

			/*若为真，只需设置第一轮中那个学生的第二轮选课情况即可*/
			if (prime)
				p->second_choice = true;

			/*若为假，则该生为补选，添加新学生*/
			else {
				p = stu + first_stu_num + new_student_num + 1;  /*移动类指针到所有已有学生的后面*/

				/*转换学号*/
				for (int i = 0; i < 7; i++) {
					int ten_pow = 1;

					if (i != 6) {
						for (int j = 0; j < 6 - i; j++)
							ten_pow = ten_pow * 10;
					}

					student_number = student_number + (student_id[i] - '0') * ten_pow;
				}
				/*end of转换学号*/

				/*将所有信息赋给当前对象*/
				p->stu_no = student_number;
				strcpy(p->stu_name, student_name);
				p->first_choice = false;
				p->second_choice = true;

				new_student_num++;  /*新增学生数量自增*/
				second_stu_num++;   /*第二轮新增人数自增*/
			}

			if (reader.peek() == EOF)  /*若遇到文件结束符则停止读入*/
				break;
		}
	}

	reader.close();  /*关闭文件*/
	return 0;
}

/***************************************************************************
  函数名称：stu_order_set
  功    能：将学生信息排序
  输入参数：无
  返 回 值：无
  属于类：stu_list
  属性：public
***************************************************************************/
void stu_list::stu_order_set()
{
	int i, j, k;
	stu_info t;  /*中间对象*/

	for (i = 0; i < first_stu_num + second_stu_num; i++) {
		k = i;

		for (j = i + 1; j <= first_stu_num + second_stu_num; j++) {
			if (stu[j].stu_no < stu[k].stu_no)  /*按学号升序排列*/
				k = j;
		}

		/*t <=> stu[k]*/
		t.first_choice = stu[k].first_choice;
		t.second_choice = stu[k].second_choice;
		strcpy(t.stu_id, stu[k].stu_id);
		strcpy(t.stu_name, stu[k].stu_name);
		t.stu_no = stu[k].stu_no;

		/*stu[k] <=> stu[i]*/
		stu[k].first_choice = stu[i].first_choice;
		stu[k].second_choice = stu[i].second_choice;
		strcpy(stu[k].stu_id, stu[i].stu_id);
		strcpy(stu[k].stu_name, stu[i].stu_name);
		stu[k].stu_no = stu[i].stu_no;

		/*stu[i] <=> t*/
		stu[i].first_choice = t.first_choice;
		stu[i].second_choice = t.second_choice;
		strcpy(stu[i].stu_id, t.stu_id);
		strcpy(stu[i].stu_name, t.stu_name);
		stu[i].stu_no = t.stu_no;
	}
}

/***************************************************************************
  函数名称：print
  功    能：输出选课情况
  输入参数：const char* prompt：提示语（只读）
  返 回 值：int：提示语是否为空指针
  属于类：stu_list
  属性：public
***************************************************************************/
int stu_list::print(const char* prompt)
{
	if (prompt == NULL)  /*若提示语为空指针，则不输出*/
		return -1;

	p = stu;  /*类指针指向对象数组首地址*/

	stu_order_set();  /*对所有学生信息进行排序*/

	cout << prompt << endl
		<< "===========================================================" << endl
		<< "序号 学号    姓名                             第一轮 第二轮" << endl
		<< "===========================================================" << endl;

	/*逐个输出所有学生的信息*/
	while (p - stu < first_stu_num + second_stu_num + 1) {
		cout << setw(5) << setiosflags(ios::left) << p - stu + 1   /*序号*/
			<< setw(8) << setiosflags(ios::left) << p->stu_no      /*学号*/
			<< setw(33) << setiosflags(ios::left) << p->stu_name;  /*姓名*/

		/*第一轮选课情况*/
		if (p->first_choice == true)
			cout << setw(7) << setiosflags(ios::left) << 'Y';
		else
			cout << setw(7) << setiosflags(ios::left) << '/';

		/*第二轮选课情况*/
		if (p->second_choice == true) {
			if (p->first_choice == false)
				cout << "补选" << endl;
			else
				cout << 'Y' << endl;
		}
		else
			cout << "退课" << endl;

		p++;  /*移动类指针*/
	}

	cout << "===========================================================" << endl;
	return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数不准动
***************************************************************************/
int main()
{
	char file1[MAX_FILENAME_LEN], file2[MAX_FILENAME_LEN];

	cout << "请输入前一轮选课的数据文件 : ";
	cin >> file1;
	cout << "请输入后一轮选课的数据文件 : ";
	cin >> file2;

	stu_list list;

	/* 读入第一个数据文件 */
	if (list.read(file1) < 0)
		return -1;

	/* 读入第二个数据文件，参数2的值为1表示追加方式 */
	if (list.read(file2, 1) < 0)
		return -1;

	list.print("最终选课名单");

	return 0;
}
