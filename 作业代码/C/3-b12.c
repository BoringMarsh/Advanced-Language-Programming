/*2151294 ��11 ����*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	/*��һ���֣�����������ȷ�Դ���*/
	int ret1, ret2, y, m, w;

	/*1�������µ�������ȷ�Դ���*/
	while (1) {
		printf("���������(2000-2030)���·�(1-12) :");
		ret1 = scanf("%d %d", &y, &m);
		if (ret1 == 2 && (y >= 2000 && y <= 2030) && (m >= 1 && m <= 12))
			break;

		/*�Ѷ�ȡ�������û���Χʱ���������»������¶��ɽ�����Ĵ���*/
		else if (ret1 == 2 && ((y < 2000 || y > 2030) || (m < 1 || m > 12))) {
			printf("����Ƿ�������������\n");
			rewind(stdin);
		}

		/*�зǷ������ȡ���������ݷ�Χʱ�Ĵ���*/
		else if (ret1 == 0 || ret1 == 1) {
			printf("����Ƿ�������������\n");
			rewind(stdin);
		}
	}

	/*2�������ڵ�������ȷ�Դ���*/
	while (1) {
		printf("������%d��%d��1�յ�����(0 - 6��ʾ������ - ������) : ", y, m);
		ret2 = scanf("%d", &w);
		if (ret2 == 1 && (w >= 0 && w <= 6))
			break;

		/*��ȡ״̬�����������û���Χʱ�Ĵ���*/
		else if (ret2 == 1 && (w < 0 || w>6)) {
			printf("����Ƿ�������������\n");
			rewind(stdin);
		}

		/*�зǷ������ȡ���������ݷ�Χʱ�Ĵ���*/
		else if (ret2 == 0) {
			printf("����Ƿ�������������\n");
			rewind(stdin);
		}
	}


	/*�ڶ����֣�������ӡ����*/
	int j, limit, d1;
	printf("\n%d��%d�µ�����Ϊ:\n", y, m);
	printf("������  ����һ  ���ڶ�  ������  ������  ������  ������\n");

	/*1�������·�ȷ��limit����������ֵ����2�·��Ƿ�Ϊ�������ۣ�*/
	if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
		limit = 31;

	else if (m == 4 || m == 6 || m == 9 || m == 11)
		limit = 30;

	else if (m == 2) {
		if ((y % 4 == 0) && (y % 100 != 0) || (y % 4 == 0) && (y % 400 == 0))
			limit = 29;

		else
			limit = 28;
	}

	/*2����ӡ������jΪ�ڼ��գ�d1Ϊλ�ò�����d1Ϊ7�ı���ʱ���У�d1%7�Ľ��Ϊ1ʱ�趨������Ϊ4��*/
	d1 = w + 1;

	for (j = 1; j <= limit; j++) {
		if (j == 1) {    /*���ڸ�ʽ�����printf���ÿ��ʱ����Ϊ���ʽ���ʶ���w��ֵ�ֿ�����*/
			if (w == 0)
				printf("%4d", j);
			else if (w == 1)
				printf("%12d", j);
			else if (w == 2)
				printf("%20d", j);
			else if (w == 3)
				printf("%28d", j);
			else if (w == 4)
				printf("%36d", j);
			else if (w == 5)
				printf("%44d", j);
			else if (w == 6)
				printf("%52d", j);
		}

		else if (d1 % 7 == 1) {
			printf("%4d", j);
		}

		else if (j != 1) {
			printf("%8d", j);
		}

		if (d1 % 7 == 0) {
			printf("\n");
		}

		d1++;
	}

	return 0;
}