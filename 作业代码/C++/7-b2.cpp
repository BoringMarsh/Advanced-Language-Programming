#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
using namespace std;

/*��Ʒ�Ľṹ�壺��š����ơ��۸�*/
struct SPWRiceNoodle {
	char ID;
	char name[16];
	double price;
};

/*��ʾ�˵��ĵ�Ʒ�ṹ������*/
const struct SPWRiceNoodle list[] = {
	{'A' , "ԭ��ţ���(2��)" , 13.5 },
	{'B' , "ţ����(2��)"     , 13.5 },
	{'C' , "����ţ���(2��)" , 15   },
	{'D' , "���ţ���(2��)" , 13.5 },
	{'E' , "����ţ���(2��)" , 15   },
	{'F' , "����±�˷�(2��)" , 12   },
	{'G' , "�������Ϸ�(2��)" , 12.5 },
	{'H' , "������ĩ��(2��)" , 12   },
	{'I' , "±ţ��"          , 6    },
	{'J' , "±ţ��"          , 8    },
	{'K' , "±ţ��"          , 12   },
	{'L' , "±ţ����"        , 12   },
	{'M' , "±����"          , 3    },
	{'N' , "�弦��"          , 3    },
	{'O' , "������"          , 2.5  },
	{'P' , "��ζѼ��(2��)"   , 3    },
	{'Q' , "ţ����(3��)"     , 6    },
	{'R' , "���"            , 2    },
	{'S' , "�̶�ɳ(��)"      , 4.5  },
	{'T' , "�̶�ɳ(��)"      , 3.5  },
	{'U' , "����(��)"        , 5    },
	{'V' , "����(��)"        , 4    },
	{'W' , "��÷��(��)"      , 4.5  },
	{'X' , "��÷��(��)"      , 3.5  },
	{'Y' , "���ʺ��"        , 4.5  },
	{'Z' , "��һ����"        , 0.5  }
};

/*�Ż���ϵĽṹ�壺�����ϡ����ơ��۸�*/
struct SPECIAL {
	char combine[8];
	char name[28];
	double price;
};

/*��ʾ�Żݲ˵����Ż���Ͻṹ������*/
const struct SPECIAL special[] = {
	{"AMR"     , "����ԭ��ţ����ײ�"        , 15   },
	{"GPPFLMV" , "��ζƮ��&��ɫ±ζ˫���ײ�" , 36.5 },
	{"ENO"     , "��C�����ײ�"               , 17   },
	{"BIJK"    , "��ţ������ţ�����ײ�"      , 26.5 }
};

const int LIST_NUM = sizeof(list) / sizeof(SPWRiceNoodle);
const int SPECIAL_NUM = sizeof(special) / sizeof(SPECIAL);

/***************************************************************************
  �������ƣ�total_price
  ��    �ܣ������ܼ�
  ���������const int single_count[]����ȥ�ײͺ���Ʒ���������飨ֻ����
			const int multiple_count�������ײ����������飨ֻ����
  �� �� ֵ��double���ܼ۸�
  ˵    ������
***************************************************************************/
double total_price(const int single_count[], const int multiple_count[])
{
	double price = 0;
	int i = 0;  /*��������*/

	/*ͳ�Ƶ�Ʒ�ܼ�*/
	for (i = 0; i < LIST_NUM; i++)
		price = price + single_count[i] * list[i].price;

	/*ͳ���ײ��ܼ�*/
	for (i = 0; i < SPECIAL_NUM; i++)
		price = price + multiple_count[i] * special[i].price;

	/*�����ܼ�*/
	return price;
}

/***************************************************************************
  �������ƣ�print_menu
  ��    �ܣ���ӡ��Ŀ��
  �����������
  �� �� ֵ����
  ˵    �����ú���ͨ�����ʽṹ�������е����ݣ������Ŀ��
***************************************************************************/
void print_menu()
{
	int i;

	/*����*/
	cout << "=============================================================" << endl;
	cout << "                       ��ӭ������Ʒ��!                       " << endl;
	cout << "                      ����Ʒ��,�����ȹ�                      " << endl;
	cout << "=============================================================" << endl;

	/*��Ŀ��*/
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
  �������ƣ�print_special
  ��    �ܣ���ӡ�Ż���Ϣ
  �����������
  �� �� ֵ����
  ˵    �����ú���ͨ�����ʽṹ�������е����ݣ�����Ż���Ϣ
***************************************************************************/
void print_special()
{
	unsigned int i;   /*��������*/
	char combine[8];  /*���ÿ���Ż���ϵ��ַ�����*/
	cout << "���Ż���Ϣ����" << endl;
	cout << "=========================================" << endl;

	/*��������Ż���Ϣ*/
	for (i = 0; i < SPECIAL_NUM; i++) {
		int combine_count[LIST_NUM] = { 0 };  /*���ÿ���Ż��������Ʒ����������*/
		int j = 0, k = 0;               /*j��ÿ���Ż�����еĵ�Ʒ��������k�Ǽ�������*/

		/*1������Ż�������Ⱥ�*/
		cout << special[i].name << "=" << endl << endl;
		
		/*2��ͳ��ÿ���Ż�����еĵ�Ʒ����*/
		strcpy(combine, special[i].combine);
		char* p1 = combine;  
		while (*p1 != '\0') {
			if (*p1)
				combine_count[*p1 - 'A']++;
			p1++;
		}

		/*3��ͳ��ÿ���Ż�����еĵ�Ʒ������*/
		int* p2 = combine_count;
		while (p2 - combine_count < LIST_NUM) {
			if (*p2)
				j++;
			p2++;
		}

		/*4��������ÿ���Ż�����еĸ��Ʒ��������*/
		p2 = combine_count;  /*ָ�븴λ*/
		while (p2 - combine_count < LIST_NUM) {
			if (*p2) {

				if (k % 2 == 0)
					cout << "     ";
				cout << list[p2 - combine_count].name;  /*�������*/

				if (*p2 > 1)  /*����������һ���ں������*n*/
					cout << "*" << *p2;

				/*�����һ���������������������һ�ֵ�Ʒ������Ӻ�*/
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
  �������ƣ�order_check
  ��    �ܣ��������ָ��
  ���������char *order������ָ����ַ���
  �� �� ֵ��bool������ָ���Ƿ���ȷ
  ˵    �����ú���ȷ������ָ����ֻ����ĸ��β��
***************************************************************************/
bool order_check(char *order)
{
	char* p = order;  /*ָ��ָ���ַ����׵�ַ��ָ��*/
	bool ret = true;  /*����ֵ*/

	/*�������һ�����з���ʹָ�븴λ*/
	while (*p != '\n')
		p++;
	*p = '\0', p = order;

	/*�������ַ���ֱ��ָ��ָ��β��Ϊֹ*/
	while (*p != '\0') {

		/*����������ĸ�ַ����򷵻�ֵΪ�٣��������*/
		if ((*p < 'a' || *p>'z') && (*p < 'A' || *p>'Z')) {
			ret = false;
			break;
		}
		
		p++;
	}

	return ret;
}

/***************************************************************************
  �������ƣ�order_count
  ��    �ܣ�ͳ�Ƹ��Ʒ����
  ���������const char *order������ָ����ַ�����ֻ����
            int single_count[]�����Ʒ����������
  �� �� ֵ����
  ˵    ����single_count������Ԫ�����Ӧ��Ʒ���һһ��Ӧ����single_count[0]��ʾ��Ʒ'A'������
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
  �������ƣ�print_order
  ��    �ܣ���ӡ�㵥���
  ���������const int single_count[]�����Ʒ����������
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void print_order(const int single_count[])
{
	int i, j = 0, k = 0;  /*��������*/
	const int* p1 = single_count;  /*ָ��single_count[]�׵�ַ��ָ��*/

	/*ͳ���ѵ㵥Ʒ������*/
	for (i = 0; i < LIST_NUM; i++) {
		if (*p1)
			j++;
		p1++;
	}

	for (i = 0; i < LIST_NUM; i++) {

		/*����Ӧ��Ʒ�ѵ�������Ϊ�㣬������õ�Ʒ*/
		if (single_count[i]) {

			/*�����Ӧ��Ʒ����*/
			cout << list[i].name;

			/*����Ӧ��Ʒ��������1���ں����*n*/
			if (single_count[i] > 1)
				cout << "*" << single_count[i];

			/*�����һ���������������������һ�ֵ�Ʒ������Ӻ�*/
			k++;
			if (k < j)
				cout << "+";
		}
	}
}

/***************************************************************************
  �������ƣ�special_count
  ��    �ܣ�ͳ�Ƹ����ײ�����
  ���������int single_count[]�����Ʒ����������
			int multiple_count[]�������ײ�����������
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void special_count(int single_count[], int multiple_count[])
{
	unsigned int i, j, k;  /*��������*/
	char combine[8];       /*���ն�Ӧ�˵������ϵ��ַ�����*/

	for (i = 0; i < SPECIAL_NUM; i++) {
		strcpy(combine, special[i].combine);

		/*�������е�ÿһ�ֵ�Ʒ�ڵ㵥���Ƿ��У�������һ��û�У��������*/
		for (j = 0; j < strlen(combine); j++) {
			if (single_count[combine[j] - 'A'] == 0)
				break;
		}

		/*�����У�����еĸ��������ڵ㵥��ȫ��-1�����ײ�����+1*/
		if (j == strlen(combine)) {  /*��j��combine������ȣ�˵��û������һ����ǰ������飬���Ʒ��ȫ*/
			for (k = 0; k < strlen(combine); k++)
				single_count[combine[k] - 'A']--;

			multiple_count[i]++;
			i--;  /*i--ʹ�ü�����鵱ǰ�ײ��Ƿ����*/
		}
	}
}

/***************************************************************************
  �������ƣ�print_order_rule
  ��    �ܣ���ʾ�������˵��
  �����������
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void print_order_rule()
{
	int example_count1[LIST_NUM] = { 0 };  /*����������1�и��Ʒ����������*/
	int example_count2[LIST_NUM] = { 0 };  /*����������2�и��Ʒ����������*/
	char ex1[10] = "AMR", ex2[10] = "bmkkl";  /*����������ϣ���Сд����*/

	cout << "���������˵������" << endl;

	cout << ex1 << "=";
	order_count(_strupr(ex1), example_count1);  /*ͳ������1*/
	print_order(example_count1);  /*�������1*/
	cout << " / ";

	cout << ex2 << "=";
	order_count(_strupr(ex2), example_count2);  /*ͳ������2*/
	print_order(example_count2);  /*�������2*/

	cout << endl << "��ĸ���ִ�Сд������˳�򣬵�������0���˳�����" << endl;
}

int main()
{
	while (1) {
		system("cls");                         /*�����Ļ*/
		system("mode con cols=120 lines=60");  /*�������ڴ�С*/
		print_menu();        /*��ӡ��Ŀ��*/
		print_special();     /*��ӡ�Ż���Ϣ*/
		print_order_rule();  /*����˵��*/

		char order[256];           /*��ʾ�㵥���ַ�����*/
		cout << endl << "��㵥:";
		fgets(order, 256, stdin);  /*����㵥���*/

		bool ret = order_check(order);  /*��������һ�����з������ʣ���ַ��Ƿ�ȫΪ��ĸ��\0*/

		/*��ȫΪ��ĸ��\0��������һ���ж�*/
		if (ret) {

			/*��һ���ַ�Ϊβ�㣬����Ϊ�գ�ֱ�ӽ�������ѭ��*/
			if (order[0] == '\0')
				continue;

			/*�����벻Ϊ��*/
			else {  
				_strupr(order);  /*��д����*/
				int single_count[LIST_NUM] = { 0 };
				int multiple_count[SPECIAL_NUM] = { 0 };

				order_count(order, single_count);  /*ͳ�����е�Ʒ����*/
				cout << "���ĵ��=";
				print_order(single_count);  /*��ӡ�㵥���*/
				cout << endl;
				special_count(single_count, multiple_count);  /*ͳ���ײ�����*/
				cout << "���ƣ�" << total_price(single_count, multiple_count) << "Ԫ" << endl;  /*�����ܼ�*/

				cout << "�㵥��ɣ������������." << endl;
				char c = getchar();
			}
		}

		/*���������ַ������ж�������������ʾ*/
		else {
			cout << "������󣬰����������." << endl;
			char c = getchar();
		}
	}

	return 0;
}