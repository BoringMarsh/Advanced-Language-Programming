/*2151294 信11 马威*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

/*计数用的一个全局变量*/
int stepnumber = 0;

/*代表三根柱子的一个全局二维数组，设TOWER[0]为A柱，TOWER[1]为B柱，TOWER[2]为C柱*/
int TOWER[3][10];

/*代表三个栈顶指针的一个全局一维数组，设MARK[0]为A柱栈顶指针，MARK[1]为B柱栈顶指针，MARK[2]为C柱栈顶指针*/
int MARK[3];

/***************************************************************************
  函数名称：pillar_initialize
  功    能：给所有数组赋初值，完成初始化
  输入参数：int n：盘子的数量
			char src：起始柱代号
  返 回 值：无
  说    明：1、此为第1个添加函数
			2、此函数根据盘子数及起始柱代号，给起始柱的对应元素赋上1-n的值
***************************************************************************/
void pillar_initialize(int n, char src)
{
	int i, j;

	/*给所有元素赋初值*/
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 10; j++) {
			TOWER[i][j] = 0;
		}
	}

	/*根据起始柱的代号，给起始柱的对应元素赋上1-n的值，代表初始时的各个盘子*/
	for (i = 0; i < n; i++) {
		TOWER[src - 65][i] = n - i;
	}

	/*起始柱栈顶指针的初始化*/
	MARK[src - 65] = n;
}

/***************************************************************************
  函数名称：print_pillar
  功    能：输出每根柱子上的盘子数量情况
  输入参数：无
  返 回 值：无
  说    明：1、此为第2个添加函数
			2、若有盘子（值不为零），则输出；若无盘子（值为零），则不输出，只留空格
			3、根据i的值判断应该输出哪个数组
***************************************************************************/
void print_pillar()
{
	int i, j;

	for (i = 0; i < 3; i++) {
		if (i == 0) {
			printf("A:");
		}

		else if (i == 1) {
			printf(" B:");
		}

		else {
			printf(" C:");
		}

		for (j = 0; j < 10; j++) {
			if (TOWER[i][j] != 0) {
				printf("%2d", TOWER[i][j]);
			}

			else {
				printf("  ");
			}
		}
	}

	printf("\n");
}

/***************************************************************************
  函数名称：act
  功    能：进行盘子的移动（数值的转移），以及每一步的输出
  输入参数：int n：移动盘子的编号
			char src：这一步盘子的起始柱
			char dst：这一步盘子的目标柱
  返 回 值：无
  说    明：1、此为第3个添加函数
			2、该函数调用了print_pillar，以达到每走一步打印三根柱子情况的效果
***************************************************************************/
void act(int n, char src, char dst)
{
	/*每次移动步骤：出栈栈顶指针下降，赋值给入栈元素，入栈栈顶指针上升，出栈栈顶元素赋0，代表盘子已移走*/
	TOWER[dst - 'A'][MARK[dst - 'A']++] = TOWER[src - 'A'][--MARK[src - 'A']];
	TOWER[src - 'A'][MARK[src - 'A']] = 0;

	/*打印每一步的信息：盘子代号，去向，三根柱子的实时情况*/
	printf("第%4d 步(%2d): %c-->%c ", stepnumber, n, src, dst);
	print_pillar();
}

/***************************************************************************
  函数名称：hanoi
  功    能：打印n层汉诺塔的移动顺序
  输入参数：int n：层数
			char src：起始柱
			char tmp：中间柱
			char dst：目标柱
  返 回 值：无
  说    明：该函数要求与原先一致
***************************************************************************/
void hanoi(int n, char src, char tmp, char dst)
{
	/*若汉诺塔层数为1，将该盘从起始柱直接移向目标柱*/
	if (n == 1) {
		stepnumber++;
		act(n, src, dst);
	}

	/*若汉诺塔层数不为1*/
	else {

		/*1、递归调用hanoi(n - 1, src, dst, tmp)，将n-1个盘子移向中间柱*/
		hanoi(n - 1, src, dst, tmp);

		/*2、将第n个盘子直接移向目标柱*/
		stepnumber++;
		act(n, src, dst);

		/*3、递归调用hanoi(n - 1, tmp, src, dst)，将其余n-1个盘子移向目标柱*/
		hanoi(n - 1, tmp, src, dst);
	}
}

/***************************************************************************
  函数名称：number_of_plates
  功    能：通过正确性处理，输入并返回汉诺塔的层数
  输入参数：
  返 回 值：x：汉诺塔的层数
  说    明：1、此为第4个添加函数
			2、已按要求将输入正确范围控制在10以内
***************************************************************************/
int number_of_plates()
{
	int n, ret;
	char c;

	while (1) {
		printf("请输入汉诺塔的层数(1-10)：\n");
		ret = scanf("%d", &n);
		if (n >= 1 && n <= 10 && ret == 1) {
			while ((c = getchar()) != EOF && c != '\n');
			break;
		}

		/*超用户范围数，或超类型范围数的处理*/
		else if ((n < 1 || n > 10) && ret == 1) {
			while ((c = getchar()) != EOF && c != '\n');
		}

		/*只剩非法输入的处理*/
		else if (ret == 0) {
			while ((c = getchar()) != EOF && c != '\n');
		}
	}

	return n;
}

/***************************************************************************
  函数名称：start_tower
  功    能：通过正确性处理，输入并返回代表起始柱字母的ASCII
  输入参数：
  返 回 值：src：代表起始柱字母的ASCII
  说    明：1、此为第5个添加函数
			2、无论输入大写或小写，返回值统一为对应大写字母的ASCII
***************************************************************************/
char start_tower()
{
	char src, ret, c;
	while (1) {
		printf("请输入起始柱(A-C)：\n");
		ret = scanf("%c", &src);
		if (((src >= 'a' && src <= 'c') || (src >= 'A' && src <= 'C')) && ret == 1) {
			while ((c = getchar()) != EOF && c != '\n');
			break;
		}

		/*超用户范围数，或超类型范围数的处理*/
		else if (((src < 'a' || src > 'c') || (src < 'A' || src > 'C')) && ret == 1) {
			while ((c = getchar()) != EOF && c != '\n');
		}

		/*只剩非法输入的处理*/
		else if (ret == 0) {
			while ((c = getchar()) != EOF && c != '\n');
		}
	}

	if (src >= 'a' && src <= 'c') {
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
  说    明：1、此为第6个添加函数
			2、无论输入大写或小写，返回值统一为对应大写字母的ASCII
			3、该函数通过输入参数src，判断dst与src是否相等
***************************************************************************/
char destination_tower(char src)
{
	char dst, ret, c;
	while (1) {
		printf("请输入目标柱(A-C)：\n");
		ret = scanf("%c", &dst);
		if (((dst >= 'a' && dst <= 'c') || (dst >= 'A' && dst <= 'C')) && ret == 1) {
			if (dst != src && dst != src + 32 && dst != src - 32) {
				while ((c = getchar()) != EOF && c != '\n');
				break;
			}

			/*dst与src相等时的处理*/
			else {

				/*为了使提示语中的dst输出为大写，对dst的值进行处理*/
				if (dst >= 'a' && dst <= 'c') {
					dst = dst - 32;
				}

				printf("目标柱(%c)不能与起始柱(%c)相同\n", dst, src);
				while ((c = getchar()) != EOF && c != '\n');
			}
		}

		/*超用户范围数，或超类型范围数的处理*/
		else if (((dst < 'a' || dst > 'c') || (dst < 'A' || dst > 'C')) && ret == 1) {
			while ((c = getchar()) != EOF && c != '\n');
		}

		/*只剩非法输入的处理*/
		else if (((dst < 'a' || dst > 'c') || (dst < 'A' || dst > 'C')) && ret == 0) {
			while ((c = getchar()) != EOF && c != '\n');
		}
	}

	if (dst >= 'a' && dst <= 'c') {
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
	tmp = 'A' + 'B' + 'C' - src - dst;         /*通过src、dst的值，确定tmp的值*/

	pillar_initialize(n, src);     /*通过pillar_initialize()给数组赋值，完成柱子的初始化*/

	printf("初始:                ");      /*按规定格式，通过print_pillar()输出各柱子的初始情况*/
	print_pillar();

	hanoi(n, src, tmp, dst);        /*打印汉诺塔移动步骤*/

	return 0;
}