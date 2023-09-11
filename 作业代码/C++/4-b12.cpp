/*2151294 信11 马威*/
#include <iostream>
#include <iomanip>
using namespace std;

/* ----具体要求----
   1、不允许添加其它头文件
   2、不允许定义全局变量、静态局部变量
   3、允许添加用于输入层数、起始/目标柱的函数，函数中允许使用循环处理错误输入
   4、如果输入用函数进行，则main中不允许出现任何形式的循环
      如果输入在main中进行，则main中允许出现循环
   --------------------------------------------------------------------- */

   /***************************************************************************
     函数名称：
     功    能：打印n层汉诺塔的移动顺序
     输入参数：int n：层数
               char src：起始柱
               char tmp：中间柱
               char dst：目标柱
     返 回 值：
     说    明：1、函数名、形参、返回类型均不准动
               2、本函数不允许出现任何形式的循环
   ***************************************************************************/
void hanoi(int n, char src, char tmp, char dst)
{
	/*若汉诺塔层数为1，将该盘从起始柱直接移向目标柱*/
	if (n == 1) {
		cout << setw(2) << 1 << "# " << src << "-->" << dst << endl;
	}

	/*若汉诺塔层数不为1*/
	else {

		/*1、递归调用hanoi(n - 1, src, dst, tmp)，将n-1个盘子移向中间柱*/
		hanoi(n - 1, src, dst, tmp);

		/*2、将第n个盘子直接移向目标柱*/
		cout << setw(2) << n << "# " << src << "-->" << dst << endl;

		/*3、递归调用hanoi(n - 1, tmp, src, dst)，将其余n-1个盘子移向目标柱*/
		hanoi(n - 1, tmp, src, dst);
	}
}

/***************************************************************************
  函数名称：number_of_plates
  功    能：通过正确性处理，输入并返回汉诺塔的层数
  输入参数：
  返 回 值：x：汉诺塔的层数
  说    明：1、此为第1个添加函数
***************************************************************************/
int number_of_plates()
{
	int n;

	while (1) {
		cout << "请输入汉诺塔的层数(1-16)" << endl;
		cin >> n;
		if (n >= 1 && n <= 16 && cin.good() == 1) {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			break;
		}

		/*只剩非法输入，或数值超类型范围的处理*/
		else if ((n < 1 || n > 16) && cin.good() == 0) {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}

		/*读取状态正常，超过用户范围时的处理*/
		else if ((n < 1 || n > 16) && cin.good() == 1) {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}
	}

	return n;
}

/***************************************************************************
  函数名称：start_tower
  功    能：通过正确性处理，输入并返回代表起始柱字母的ASCII
  输入参数：
  返 回 值：src：代表起始柱字母的ASCII
  说    明：1、此为第2个添加函数
            2、无论输入大写或小写，返回值统一为对应大写字母的ASCII
***************************************************************************/
char start_tower()
{
	char src;
	while (1) {
		cout << "请输入起始柱(A-C)" << endl;
		cin >> src;
		if ((src >= 97 && src <= 99) || (src >= 65 && src <= 67) && cin.good() == 1) {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			break;
		}

		/*只剩非法输入，或数值超类型范围的处理*/
		else if ((src < 97 || src > 99) || (src < 65 || src > 67) && cin.good() == 0) {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}

		/*读取状态正常，超过用户范围时的处理*/
		else if ((src < 97 || src > 99) || (src < 65 || src > 67) && cin.good() == 1) {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}
	}

	if (src >= 97 && src <= 99) {
		return src - 32;
	}

	else {
		return src;
	}
}

/***************************************************************************
  函数名称：destination_tower
  功    能：通过正确性处理，输入并返回代表目标柱字母的ASCII
  输入参数：src：代表起始柱字母的ASCII
  返 回 值：dst：代表目标柱字母的ASCII
  说    明：1、此为第3个添加函数
			2、无论输入大写或小写，返回值统一为对应大写字母的ASCII
			3、该函数通过输入参数src，判断dst与src是否相等
***************************************************************************/
char destination_tower(char src)
{
	char dst;
	while (1) {
		cout << "请输入目标柱(A-C)" << endl;
		cin >> dst;
		if (((dst >= 97 && dst <= 99) || (dst >= 65 && dst <= 67)) && cin.good() == 1) {
			if (dst != src && dst != src + 32 && dst != src - 32) {
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				break;
			}

			/*dst与src相等时的处理*/
			else {

				/*为了使提示语中的dst输出为大写，对dst的值进行处理*/
				if (dst >= 97 && dst <= 99) {
					dst = dst - 32;
				}

				cout << "目标柱(" << dst << ")不能与起始柱(" << src << ")相同" << endl;
				cin.clear();
				cin.ignore(INT_MAX, '\n');
			}
		}

		/*只剩非法输入，或数值超类型范围的处理*/
		else if ((dst < 97 || dst > 99) || (dst < 65 || dst > 67) && cin.good() == 0) {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}

		/*读取状态正常，超过用户范围时的处理*/
		else if ((dst < 97 || dst > 99) || (dst < 65 || dst > 67) && cin.good() == 1) {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}
	}

	if (dst >= 97 && dst <= 99) {
		return dst - 32;
	}

	else {
		return dst;
	}
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：完成输入(或调用输入函数)、调用递归函数
***************************************************************************/
int main()
{
    int n;                   /*定义所需变量，n为汉诺塔的层数*/
    char src, tmp, dst;      /*定义所需变量，src是代表起始柱的字母，tmp是代表中间柱的字母，dst是代表目标柱的字母*/

	n = number_of_plates();        /*通过number_of_plates()给n赋值*/
	src = start_tower();           /*通过start_tower()给src赋值*/
	dst = destination_tower(src);  /*通过destination_tower(src)，判断dst与src是否相等的同时，给dst赋值*/
	tmp = 198 - src - dst;         /*通过src、dst的值，确定tmp的值*/

	cout << "移动步骤为:" << endl;  /*输出提示语*/
	hanoi(n, src, tmp, dst);        /*打印汉诺塔移动步骤*/

	return 0;
}