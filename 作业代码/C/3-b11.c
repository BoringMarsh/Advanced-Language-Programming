/*2151294 信11 马威*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int ret, x;

	while (1) {
		printf("请输入x的值[0-100] : ");
		ret = scanf("%d", &x); //读入x的方式必须是scanf且格式符为%d，不准用非scanf
		if (ret == 1 && (x >= 0 && x <= 100))
			break;

		/*超用户范围数，或超类型范围数的处理*/
		else if (ret == 1 && (x < 0 || x>100)) {
			rewind(stdin);
		}

		/*只剩非法输入的处理*/
		else if (ret == 0) {
			rewind(stdin);
		}
	}

	printf("x=%d\n", x);

	return 0;
}