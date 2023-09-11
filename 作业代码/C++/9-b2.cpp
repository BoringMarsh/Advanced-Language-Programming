/*2151294 ��11 ����*/

/* ���������ϵͳ�ĺ궨�塢��Ҫ��ͷ�ļ��� */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;

#define MAX_STU_NUM			256	//Լ���������Ϊ256�ˣ����ֵ��ܺͣ�������ѡ����ѡ��
#define MAX_NAME_LEN			32	//ѧ����������󳤶Ȳ�����16������
#define MAX_FILENAME_LEN		256	//�ļ�������󳤶�

/* stu_info ����ÿ��ѧ������Ϣ������ѧ�š�������������Ҫ��˽����Ϣ���������ݲ�׼�����ɼ����������Ҫ��������� */
class stu_list;  //��ǰ����������������Ԫ
class stu_info {
private:
	int  stu_no;			//ѧ��
	char stu_name[MAX_NAME_LEN];	//����
	char stu_id[8];         //ѧ�ţ��ַ���ʽ��
	bool first_choice = false;   //��һ���Ƿ�ѡ��
	bool second_choice = false;  //�ڶ����Ƿ�ѡ��

	friend stu_list;  //����stu_listΪ��Ԫ��

	void stu_no_trans();  //��char stu_id[8]ת��Ϊint stu_no
	/* ���������private���ݳ�Ա����Ա�����Լ�������Ҫ������ */

public:
	/* ���಻�������κεĹ������ݳ�Ա����Ա���� */
};

/* stu_list ������ѡ����Ϣ���������ݲ�׼�����ɼ����������Ҫ��������� */
class stu_list {
private:
	stu_info stu[MAX_STU_NUM + 1];
	stu_info* p;
	int first_stu_num = 0;   //��һ��ѡ������
	int second_stu_num = 0;  //�ڶ�����������
	/* ���������private���ݳ�Ա�ͳ�Ա���� */

public:
	int read(const char* filename, const int append = 0);	//���ļ��ж���ѡ����Ϣ�����д�����2������ֵΪ0��ʾ���Ƿ�ʽ��1��ʾ׷�ӷ�ʽ
	int print(const char *prompt = NULL);			//��ӡ��ǰ�����ѡ������
	void stu_order_set();             //��ѧ����Ϣ����
	/* �������������public��Ա���� */

};

/* --- �˴���������������ĳ�Ա����������ʵ�� --- */
/***************************************************************************
  �������ƣ�stu_no_trans
  ��    �ܣ����ַ���ʽ��ѧ��ת��Ϊ����
  �����������
  �� �� ֵ����
  �����ࣺstu_info
  ���ԣ�private
***************************************************************************/
void stu_info::stu_no_trans()
{
	int i, j;

	for (i = 0; i < 7; i++) {
		int ten_pow = 1;

		if (i != 6) {  /*��λʱ���ü���n�η�*/
			for (j = 0; j < 6 - i; j++)
				ten_pow = ten_pow * 10;  /*����10��6-i�η�*/
		}
		
		stu_no = stu_no + (stu_id[i] - '0') * ten_pow;  /*�ۼӵõ�����ѧ��*/
	}
}

/***************************************************************************
  �������ƣ�read
  ��    �ܣ����ļ��ж�ȡѧ����Ϣ����������������
  ���������const char* filename���ļ�����ֻ����
            const int append�����淽ʽ��ֻ����
  �� �� ֵ��int���ļ����Ƿ�����
  �����ࣺstu_list
  ���ԣ�public
***************************************************************************/
int stu_list::read(const char* filename, const int append)
{
	ifstream reader(filename, ios::in | ios::binary);  /*��������*/

	if (!reader) {
		cout << "�ļ�[" << filename << "]��ʧ��";
		return -1;
	}

	int count = 0;
	int i;
	reader.seekg(count, ios::beg);

	/*���Ƿ�ʽ*/
	if (append == 0) {
		p = stu;  /*��ָ��ָ����������׵�ַ*/

		while (1) {
			i = 0;  /*��ѧ��*/
			while (1) {
				if (reader.peek() == '\x09') {
					p->stu_id[i] = '\0';  /*����β�㣬�������strcmp*/
					break;
				}

				p->stu_id[i] = reader.peek();   /*���������ַ������ַ�����*/
				i++, count++;
				reader.seekg(count, ios::beg);  /*�ƶ��ļ�ָ��*/
			}
			p->stu_no_trans();  /*ת��Ϊ����ѧ��*/

			/*����\x09*/
			count++;
			reader.seekg(count, ios::beg);

			i = 0;  /*������*/
			while (1) {
				if (reader.peek() == '\r') {
					p->stu_name[i] = '\0';  /*����β�㣬�������strcmp*/
					break;
				}

				p->stu_name[i] = reader.peek();  /*���������ַ������ַ�����*/
				i++, count++;
				reader.seekg(count, ios::beg);   /*�ƶ��ļ�ָ��*/
			}

			/*����\r��\n*/
			count = count + 2;
			reader.seekg(count, ios::beg);

			p->first_choice = true;  /*��Ǹ���Ϊ��һ����ѡ��*/

			if (reader.peek() != EOF) {  /*��δ�����ļ�����������ָ���ƶ�����һ��ѡ����������*/
				p++, first_stu_num++;
			}

			else  /*�������ļ���������ֹͣ��ȡ*/
				break;
		}
	}

	/*׷�ӷ�ʽ*/
	else {
		int new_student_num = 0;  /*�ڶ���������������ʼΪ��*/

		while(1) {
			int student_number = 0;  /*��ǰѧ������ѧ��*/
			char student_id[8];      /*��ǰѧ���ַ���ѧ��*/
			char student_name[MAX_NAME_LEN];  /*��ǰѧ������*/

			i = 0;  /*��ѧ��*/
			while (1) {
				if (reader.peek() == '\x09') {
					student_id[i] = '\0';  /*����β�㣬�������strcmp*/
					break;
				}

				student_id[i] = reader.peek();  /*���������ַ������ַ�����*/
				i++, count++;
				reader.seekg(count, ios::beg);  /*�ƶ��ļ�ָ��*/
			}
			
			/*����\x09*/
			count++;
			reader.seekg(count, ios::beg);

			i = 0;  /*������*/
			while (1) {
				if (reader.peek() == '\r') {
					student_name[i] = '\0';  /*����β�㣬�������strcmp*/
					break;
				}

				student_name[i] = reader.peek();  /*���������ַ������ַ�����*/
				i++, count++;
				reader.seekg(count, ios::beg);    /*�ƶ��ļ�ָ��*/
			}

			/*����\r��\n*/
			count = count + 2;
			reader.seekg(count, ios::beg);
			
			/*�жϸ����Ƿ��ڵ�һ��ѡ���г���*/
			p = stu;
			bool prime = false;

			while (p - stu <= first_stu_num) {
				if (strcmp(student_id, p->stu_id) == 0) {  /*�����һ�ֵ�ѧ����ѧ����ͬ�ģ�prime��Ϊ��*/
					prime = true;
					break;
				}

				else
					p++;
			}

			/*��Ϊ�棬ֻ�����õ�һ�����Ǹ�ѧ���ĵڶ���ѡ���������*/
			if (prime)
				p->second_choice = true;

			/*��Ϊ�٣������Ϊ��ѡ�������ѧ��*/
			else {
				p = stu + first_stu_num + new_student_num + 1;  /*�ƶ���ָ�뵽��������ѧ���ĺ���*/

				/*ת��ѧ��*/
				for (int i = 0; i < 7; i++) {
					int ten_pow = 1;

					if (i != 6) {
						for (int j = 0; j < 6 - i; j++)
							ten_pow = ten_pow * 10;
					}

					student_number = student_number + (student_id[i] - '0') * ten_pow;
				}
				/*end ofת��ѧ��*/

				/*��������Ϣ������ǰ����*/
				p->stu_no = student_number;
				strcpy(p->stu_name, student_name);
				p->first_choice = false;
				p->second_choice = true;

				new_student_num++;  /*����ѧ����������*/
				second_stu_num++;   /*�ڶ���������������*/
			}

			if (reader.peek() == EOF)  /*�������ļ���������ֹͣ����*/
				break;
		}
	}

	reader.close();  /*�ر��ļ�*/
	return 0;
}

/***************************************************************************
  �������ƣ�stu_order_set
  ��    �ܣ���ѧ����Ϣ����
  �����������
  �� �� ֵ����
  �����ࣺstu_list
  ���ԣ�public
***************************************************************************/
void stu_list::stu_order_set()
{
	int i, j, k;
	stu_info t;  /*�м����*/

	for (i = 0; i < first_stu_num + second_stu_num; i++) {
		k = i;

		for (j = i + 1; j <= first_stu_num + second_stu_num; j++) {
			if (stu[j].stu_no < stu[k].stu_no)  /*��ѧ����������*/
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
  �������ƣ�print
  ��    �ܣ����ѡ�����
  ���������const char* prompt����ʾ�ֻ����
  �� �� ֵ��int����ʾ���Ƿ�Ϊ��ָ��
  �����ࣺstu_list
  ���ԣ�public
***************************************************************************/
int stu_list::print(const char* prompt)
{
	if (prompt == NULL)  /*����ʾ��Ϊ��ָ�룬�����*/
		return -1;

	p = stu;  /*��ָ��ָ����������׵�ַ*/

	stu_order_set();  /*������ѧ����Ϣ��������*/

	cout << prompt << endl
		<< "===========================================================" << endl
		<< "��� ѧ��    ����                             ��һ�� �ڶ���" << endl
		<< "===========================================================" << endl;

	/*����������ѧ������Ϣ*/
	while (p - stu < first_stu_num + second_stu_num + 1) {
		cout << setw(5) << setiosflags(ios::left) << p - stu + 1   /*���*/
			<< setw(8) << setiosflags(ios::left) << p->stu_no      /*ѧ��*/
			<< setw(33) << setiosflags(ios::left) << p->stu_name;  /*����*/

		/*��һ��ѡ�����*/
		if (p->first_choice == true)
			cout << setw(7) << setiosflags(ios::left) << 'Y';
		else
			cout << setw(7) << setiosflags(ios::left) << '/';

		/*�ڶ���ѡ�����*/
		if (p->second_choice == true) {
			if (p->first_choice == false)
				cout << "��ѡ" << endl;
			else
				cout << 'Y' << endl;
		}
		else
			cout << "�˿�" << endl;

		p++;  /*�ƶ���ָ��*/
	}

	cout << "===========================================================" << endl;
	return 0;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main������׼��
***************************************************************************/
int main()
{
	char file1[MAX_FILENAME_LEN], file2[MAX_FILENAME_LEN];

	cout << "������ǰһ��ѡ�ε������ļ� : ";
	cin >> file1;
	cout << "�������һ��ѡ�ε������ļ� : ";
	cin >> file2;

	stu_list list;

	/* �����һ�������ļ� */
	if (list.read(file1) < 0)
		return -1;

	/* ����ڶ��������ļ�������2��ֵΪ1��ʾ׷�ӷ�ʽ */
	if (list.read(file2, 1) < 0)
		return -1;

	list.print("����ѡ������");

	return 0;
}
