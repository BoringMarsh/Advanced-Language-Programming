/*2151294 ��11 ����*/
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main()
{
	ifstream file;
	char location[256];  /*����ļ������ַ�����*/

	clog << "�ļ���������ʽ������:" << endl
		<< "    a.txt                    : ����·����ʽ" << endl
		<< "    ..\\data\\b.dat          : ���·����ʽ" << endl
		<< "    C:\\Windows\\System32\\c.dat : �������·����ʽ" << endl
		<< "�������ļ��� : ";

	cin >> location;  /*�����ļ���*/
	file.open(location, ios::in | ios::binary);  /*�����뷽ʽ�������Ʒ�ʽ���ɴ���\x1A�����ļ�*/

	/*1���ж��ļ���״̬*/
	if (!file) {
		cout << "�����ļ�" << location << "��ʧ��!" << endl;
		return 0;
	}

	int count = 0, line = 0;  /*�ַ�����������������*/
	int c[16];                /*��ŵ�ǰ����16���ַ�ASCII������*/
	file.seekg(0, ios::beg);  /*���ļ�ָ��ָ���ļ���ʼ*/

	/*����ǰָ���ļ��������������ѭ��*/
	while (file.peek() != EOF) {

		/*2����ӡ�������ַ����ļ��е�λ��*/
		if (count % 16 == 0) {
			cout << setw(7) << setfill('0') << line;
			cout << "0  ";
		}

		/*3����ʮ�����������ǰָ��ָ���ַ���ASCII����ʮ�����Ʊ�ʾΪһλ�������ֶ����ַ�0*/
		if (file.peek() < '\x10')
			cout << '0' << hex << file.peek();
		else
			cout << hex << file.peek();

		/*4����ǰָ��ָ���ַ���ASCII��Ӧ���������е�Ԫ��*/
		c[count % 16] = file.peek();
		
		/*5�����һ���ַ���ɣ�������������*/
		count++;

		/*6�����ղ������ɵ��ַ�����һ�е��м��ĩβ����������ո񣬿��ƿ��Ϊ4*/
		if (count % 8 != 0)
			cout << " ";

		/*7���ƶ��ļ�ָ��*/
		file.seekg(count, ios::beg);

		/*8�����ÿ���м�ĺ��*/
		if (count % 8 == 0 && count % 16 != 0) {
			if (file.peek() != EOF)  /*��ÿ�е�8���ַ���һ����Ϊ���������������ܣ��������*/
				cout << " - ";
		}

		/*9�����������һ�е�ĩβ*/
		if (count % 16 == 0) {
			cout << "     ";
			for (int i = 0; i < 16; i++) {  /*���������е�ASCII����ַ�*/
				if (c[i] >= 33 && c[i] <= 126)
					cout << char(c[i]);
				else
					cout << '.';
				c[i] = 0;  /*ͬʱ������գ�׼��������һ���ַ���ASCII*/
			}
			cout << endl;  /*ÿһ�н���ʱ�Ļ���*/
			line++;  /*�м�����������*/
		}

		/*10����δ�������һ�е�ĩβ�������˽�����*/
		else if (count % 16 != 0 && file.peek() == EOF) {

			/*����ո�*/
			if (count % 16 < 8) {
				for (int i = 0; i < (-3) * (count % 16) + 54; i++)
					cout << ' ';
			}
			
			else {
				for (int i = 0; i < (-3) * (count % 16) + 52; i++)
					cout << ' ';
			}

			if (count % 8 == 0)
				cout << "   ";

			for (int i = 0; i < count % 16; i++) {  /*���������е�ASCII����ַ�����ֹ����Խ�磩*/
				if (c[i] >= 33 && c[i] <= 126)
					cout << char(c[i]);
				else
					cout << '.';
			}
			cout << endl;  /*����ʱ�Ļ���*/
		}
	}

	file.close();  /*�ر��ļ�*/
	return 0;
}