#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
using namespace std;

/*单品的结构体：编号、名称、价格*/
struct SPWRiceNoodle {
	char ID;
	char name[16];
	double price;
};

/*表示菜单的单品结构体数组*/
const struct SPWRiceNoodle list[] = {
	{'A' , "原汤牛肉粉(2两)" , 13.5 },
	{'B' , "牛三宝(2两)"     , 13.5 },
	{'C' , "麻辣牛肉粉(2两)" , 15   },
	{'D' , "酸菜牛肉粉(2两)" , 13.5 },
	{'E' , "番茄牛肉粉(2两)" , 15   },
	{'F' , "桂林卤菜粉(2两)" , 12   },
	{'G' , "柳州螺蛳粉(2两)" , 12.5 },
	{'H' , "豆角肉末粉(2两)" , 12   },
	{'I' , "卤牛腱"          , 6    },
	{'J' , "卤牛筋"          , 8    },
	{'K' , "卤牛肚"          , 12   },
	{'L' , "卤牛肉粒"        , 12   },
	{'M' , "卤鸡蛋"          , 3    },
	{'N' , "煎鸡蛋"          , 3    },
	{'O' , "豆腐干"          , 2.5  },
	{'P' , "螺味鸭脚(2个)"   , 3    },
	{'Q' , "牛肉丸(3个)"     , 6    },
	{'R' , "青菜"            , 2    },
	{'S' , "绿豆沙(大)"      , 4.5  },
	{'T' , "绿豆沙(中)"      , 3.5  },
	{'U' , "豆浆(大)"        , 5    },
	{'V' , "豆浆(中)"        , 4    },
	{'W' , "酸梅汤(大)"      , 4.5  },
	{'X' , "酸梅汤(中)"      , 3.5  },
	{'Y' , "柠檬红茶"        , 4.5  },
	{'Z' , "加一两粉"        , 0.5  }
};

/*优惠组合的结构体：编号组合、名称、价格*/
struct SPECIAL {
	char combine[8];
	char name[28];
	double price;
};

/*表示优惠菜单的优惠组合结构体数组*/
const struct SPECIAL special[] = {
	{"AMR"     , "经典原汤牛肉粉套餐"        , 15   },
	{"GPPFLMV" , "螺味飘香&特色卤味双享套餐" , 36.5 },
	{"ENO"     , "多C番茄套餐"               , 17   },
	{"BIJK"    , "三牛哥秘制牛三宝套餐"      , 26.5 }
};

const int LIST_NUM = sizeof(list) / sizeof(SPWRiceNoodle);
const int SPECIAL_NUM = sizeof(special) / sizeof(SPECIAL);

/***************************************************************************
  函数名称：total_price
  功    能：计算总价
  输入参数：const int single_count[]：除去套餐后各项单品数量的数组（只读）
			const int multiple_count：各项套餐数量的数组（只读）
  返 回 值：double：总价格
  说    明：无
***************************************************************************/
double total_price(const int single_count[], const int multiple_count[])
{
	double price = 0;
	int i = 0;  /*计数变量*/

	/*统计单品总价*/
	for (i = 0; i < LIST_NUM; i++)
		price = price + single_count[i] * list[i].price;

	/*统计套餐总价*/
	for (i = 0; i < SPECIAL_NUM; i++)
		price = price + multiple_count[i] * special[i].price;

	/*返回总价*/
	return price;
}

/***************************************************************************
  函数名称：print_menu
  功    能：打印价目表
  输入参数：无
  返 回 值：无
  说    明：该函数通过访问结构体数组中的内容，输出价目表
***************************************************************************/
void print_menu()
{
	int i;

	/*招牌*/
	cout << "=============================================================" << endl;
	cout << "                       欢迎光临三品王!                       " << endl;
	cout << "                      吃三品王,把汤喝光                      " << endl;
	cout << "=============================================================" << endl;

	/*价目表*/
	for (i = 0; i < LIST_NUM; i++) {
		cout << " " << list[i].ID << " ";
		cout << setw(16) << setiosflags(ios::left) << list[i].name << "    ";
		cout << setw(4) << setiosflags(ios::left) << list[i].price;

		if (i % 2 == 0)
			cout << "   |  ";

		else
			cout << endl;
	}

	cout << endl;
}

/***************************************************************************
  函数名称：print_special
  功    能：打印优惠信息
  输入参数：无
  返 回 值：无
  说    明：该函数通过访问结构体数组中的内容，输出优惠信息
***************************************************************************/
void print_special()
{
	unsigned int i;   /*计数变量*/
	char combine[8];  /*存放每种优惠组合的字符数组*/
	cout << "【优惠信息】：" << endl;
	cout << "=========================================" << endl;

	/*逐条输出优惠信息*/
	for (i = 0; i < SPECIAL_NUM; i++) {
		int combine_count[LIST_NUM] = { 0 };  /*存放每种优惠组合里各项单品数量的数组*/
		int j = 0, k = 0;               /*j是每种优惠组合中的单品种类数，k是计数变量*/

		/*1、输出优惠名称与等号*/
		cout << special[i].name << "=" << endl << endl;
		
		/*2、统计每种优惠组合中的单品数量*/
		strcpy(combine, special[i].combine);
		char* p1 = combine;  
		while (*p1 != '\0') {
			if (*p1)
				combine_count[*p1 - 'A']++;
			p1++;
		}

		/*3、统计每种优惠组合中的单品种类数*/
		int* p2 = combine_count;
		while (p2 - combine_count < LIST_NUM) {
			if (*p2)
				j++;
			p2++;
		}

		/*4、逐个输出每种优惠组合中的各项单品及其数量*/
		p2 = combine_count;  /*指针复位*/
		while (p2 - combine_count < LIST_NUM) {
			if (*p2) {

				if (k % 2 == 0)
					cout << "     ";
				cout << list[p2 - combine_count].name;  /*输出名称*/

				if (*p2 > 1)  /*若数量大于一，在后面加上*n*/
					cout << "*" << *p2;

				/*输出完一个，计数变量自增，最后一种单品后不输出加号*/
				k++;
				if (k < j)
					cout << "+";
				if (k % 2 == 0)
					cout << endl;
			}

			p2++;
		}

		cout <<endl<< "                                    =" << special[i].price << endl;
		cout << "=========================================" << endl;
	}
}

/***************************************************************************
  函数名称：order_check
  功    能：检查输入指令
  输入参数：char *order：输入指令的字符串
  返 回 值：bool：输入指令是否正确
  说    明：该函数确保输入指令中只有字母和尾零
***************************************************************************/
bool order_check(char *order)
{
	char* p = order;  /*指向指令字符串首地址的指针*/
	bool ret = true;  /*返回值*/

	/*处理最后一个换行符并使指针复位*/
	while (*p != '\n')
		p++;
	*p = '\0', p = order;

	/*逐个检查字符，直到指针指向尾零为止*/
	while (*p != '\0') {

		/*若检查出非字母字符，则返回值为假，结束检查*/
		if ((*p < 'a' || *p>'z') && (*p < 'A' || *p>'Z')) {
			ret = false;
			break;
		}
		
		p++;
	}

	return ret;
}

/***************************************************************************
  函数名称：order_count
  功    能：统计各项单品数量
  输入参数：const char *order：输入指令的字符串（只读）
            int single_count[]：各项单品数量的数组
  返 回 值：无
  说    明：single_count数组中元素与对应单品编号一一对应，如single_count[0]表示单品'A'的数量
***************************************************************************/
void order_count(const char* order, int single_count[])
{
	const char* p = order;
	int i = 0;

	while (*p != '\0') {
		single_count[*p - 'A']++;
		p++;
	}
}

/***************************************************************************
  函数名称：print_order
  功    能：打印点单情况
  输入参数：const int single_count[]：各项单品数量的数组
  返 回 值：无
  说    明：无
***************************************************************************/
void print_order(const int single_count[])
{
	int i, j = 0, k = 0;  /*计数变量*/
	const int* p1 = single_count;  /*指向single_count[]首地址的指针*/

	/*统计已点单品种类数*/
	for (i = 0; i < LIST_NUM; i++) {
		if (*p1)
			j++;
		p1++;
	}

	for (i = 0; i < LIST_NUM; i++) {

		/*若对应单品已点数量不为零，则输出该单品*/
		if (single_count[i]) {

			/*输出对应单品名称*/
			cout << list[i].name;

			/*若对应单品数量超过1，在后面加*n*/
			if (single_count[i] > 1)
				cout << "*" << single_count[i];

			/*输出完一个，计数变量自增，最后一种单品后不输出加号*/
			k++;
			if (k < j)
				cout << "+";
		}
	}
}

/***************************************************************************
  函数名称：special_count
  功    能：统计各项套餐数量
  输入参数：int single_count[]：各项单品数量的数组
			int multiple_count[]：各项套餐数量的数组
  返 回 值：无
  说    明：无
***************************************************************************/
void special_count(int single_count[], int multiple_count[])
{
	unsigned int i, j, k;  /*计数变量*/
	char combine[8];       /*接收对应菜单编号组合的字符数组*/

	for (i = 0; i < SPECIAL_NUM; i++) {
		strcpy(combine, special[i].combine);

		/*检查组合中的每一种单品在点单中是否都有，若检查出一项没有，结束检查*/
		for (j = 0; j < strlen(combine); j++) {
			if (single_count[combine[j] - 'A'] == 0)
				break;
		}

		/*若都有，组合中的各项数量在点单中全部-1，该套餐数量+1*/
		if (j == strlen(combine)) {  /*若j与combine长度相等，说明没有在上一步提前结束检查，各项单品齐全*/
			for (k = 0; k < strlen(combine); k++)
				single_count[combine[k] - 'A']--;

			multiple_count[i]++;
			i--;  /*i--使得继续检查当前套餐是否存在*/
		}
	}
}

/***************************************************************************
  函数名称：print_order_rule
  功    能：显示输入规则说明
  输入参数：无
  返 回 值：无
  说    明：无
***************************************************************************/
void print_order_rule()
{
	int example_count1[LIST_NUM] = { 0 };  /*存放样例组合1中各项单品数量的数组*/
	int example_count2[LIST_NUM] = { 0 };  /*存放样例组合2中各项单品数量的数组*/
	char ex1[10] = "AMR", ex2[10] = "bmkkl";  /*两个样例组合，大小写都有*/

	cout << "【输入规则说明】：" << endl;

	cout << ex1 << "=";
	order_count(_strupr(ex1), example_count1);  /*统计样例1*/
	print_order(example_count1);  /*输出样例1*/
	cout << " / ";

	cout << ex2 << "=";
	order_count(_strupr(ex2), example_count2);  /*统计样例2*/
	print_order(example_count2);  /*输出样例2*/

	cout << endl << "字母不分大小写，不限顺序，单独输入0则退出程序" << endl;
}

int main()
{
	while (1) {
		system("cls");                         /*清空屏幕*/
		system("mode con cols=120 lines=60");  /*调整窗口大小*/
		print_menu();        /*打印价目表*/
		print_special();     /*打印优惠信息*/
		print_order_rule();  /*输入说明*/

		char order[256];           /*表示点单的字符数组*/
		cout << endl << "请点单:";
		fgets(order, 256, stdin);  /*输入点单组合*/

		bool ret = order_check(order);  /*处理掉最后一个换行符，检查剩余字符是否全为字母和\0*/

		/*若全为字母和\0，进入下一步判断*/
		if (ret) {

			/*第一个字符为尾零，输入为空，直接结束本次循环*/
			if (order[0] == '\0')
				continue;

			/*若输入不为空*/
			else {  
				_strupr(order);  /*大写处理*/
				int single_count[LIST_NUM] = { 0 };
				int multiple_count[SPECIAL_NUM] = { 0 };

				order_count(order, single_count);  /*统计所有单品数量*/
				cout << "您的点餐=";
				print_order(single_count);  /*打印点单情况*/
				cout << endl;
				special_count(single_count, multiple_count);  /*统计套餐数量*/
				cout << "共计：" << total_price(single_count, multiple_count) << "元" << endl;  /*计算总价*/

				cout << "点单完成，按任意键继续." << endl;
				char c = getchar();
			}
		}

		/*若有其他字符，则判断输入错误，输出提示*/
		else {
			cout << "输入错误，按任意键继续." << endl;
			char c = getchar();
		}
	}

	return 0;
}