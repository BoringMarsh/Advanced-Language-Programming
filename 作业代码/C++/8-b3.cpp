/*2151294 ��11 ����*/
/*2151300 ��ε�� 1853015 ���� 2150244 ������ 2150245 ��ǫ 2153488 ������ 2153833 ����� 2151521 ��־��*/
#include <iostream>
#include <fstream>
using namespace std;

/***************************************************************************
  �������ƣ�hex_to_dec
  ��    �ܣ����ַ���ʽ����λʮ������ASCII��ת����ʮ����
  ���������const char ASCII[]����Ŵ�ת������ASCII����ַ����飨ֻ����
  �� �� ֵ��char����Ӧ��ʮ����ASCII�루Ϊ�˷���������������Ϊchar�ͣ�
  ˵    ������
***************************************************************************/
char hex_to_dec(const char ASCII[])
{
	int i, x[2];

	for (i = 0; i < 2; i++) {
		if (ASCII[i] >= 'a' && ASCII[i] <= 'f')  /*A-F��ת��*/
			x[i] = ASCII[i] - 'a' + 10;
		else                              /*0-9��ת��*/
			x[i] = ASCII[i] - '0';
	}

	return 16 * x[0] + x[1];  /*ת����ʮ���ƺ󷵻�*/
}

int main()
{
	ifstream reader;  /*��������*/
	ofstream writer;  /*д������*/
	char src[256];  /*��Ŵ�ת���ļ������ַ�����*/
	char dst[256];  /*���ת�����ļ������ַ�����*/

	clog << "�ļ���������ʽ������:" << endl
		<< "    a.hex                    : ����·����ʽ" << endl
		<< "    ..\\data\\b.txt          : ���·����ʽ" << endl
		<< "    C:\\Windows\\System32\\c.hex : �������·����ʽ" << endl
		<< "�������ļ��� : ";
	cin >> src;
	clog << "������ת������ļ���        :";
	cin >> dst;

	/*1���жϴ�ת���ļ���״̬*/
	reader.open(src, ios::in);
	if (!reader) {
		clog << "�����ļ�" << src << "��ʧ��!" << endl;
		return 0;
	}

	/*2���ж�ת�����ļ���״̬*/
	writer.open(dst, ios::out | ios::binary);  /*ʹ��ios::binary��ʽ�򿪣�����\x0Aʱֻд��һ��\x0A�������������\x0D*/
	if (!writer) {
		clog << "����ļ�" << dst << "��ʧ��!" << endl;
		return 0;
	}

	int count = 0;  /*λ�ü��������ļ�ָ��ÿ�ƶ�һ�񣬸ñ�������*/
	int loop = 1;
	char ascii[2];  /*�����λʮ�����ƴ�ת����ASCII����ַ�����*/
	reader.seekg(0, ios::beg);  /*�ļ�ָ��ָ��ʼλ��*/

	
	while (reader.peek() != EOF && loop != 0) {

		/*�ļ�һ�����82���ַ�����Ϊһ�еĿ�ʼ���ƶ�ָ��ʹ����Կ�ͷ��ƫ�����Լ��ո�*/
		if (count % 82 == 0) {
			count = count + 10;
			reader.seekg(count, ios::beg);
		}

		/*3����ÿһ��ǰ�˸��ַ�*/
		while (1) {
			if (reader.peek() == ' ') {  /*��������ո�˵����һ�е��ַ�δ��8�����������*/
				loop = 0;
				break;
			}

			else if (reader.peek() == '-')  /*���������ܣ�˵����һ��ǰ8���ַ��Ѷ�ȡ�������ⲿ�ֵļ��*/
				break;

			for (int i = 0; i < 2; i++) {  /*��λʮ������ASCII��һ�ζ�ȡ����������ascii[]�Ķ�ӦԪ��*/
				ascii[i] = reader.peek();
				count++;  /*λ�ü���ÿ��һλ����*/
				reader.seekg(count, ios::beg);  /*������ƶ��ļ�ָ������һλ��*/
			}

			count++;
			reader.seekg(count, ios::beg);  /*�������ƶ�ָ�룬Ϊ�˺���ÿ���ַ���λASCII��Ŀո�*/
			writer << hex_to_dec(ascii);    /*��ȡ�õ���λʮ������ASCII��ͨ������ת����д��ת�����ļ�*/
		}
		
		/*4������һ���ֽ������ļ�ָ��ָ���ܣ�˵����һ��ǰ8���ַ��Ѷ�ȡ�����Ժ�ܼ������һ���ո�*/
		if (reader.peek() == '-') {
			count = count + 2;
			reader.seekg(count, ios::beg);
		}

		/*5����ǰ8���ַ���ȡû����;ֹͣ��loop��Ϊ�㣬��ȡ��8���ַ�*/
		if (loop) {
			for (int i = 0; i < 8; i++) {
				for (int j = 0; j < 2; j++) {  /*��λʮ������ASCII��һ�ζ�ȡ����������ascii[]�Ķ�ӦԪ��*/
					ascii[j] = reader.peek();
					count++;  /*λ�ü���ÿ��һλ����*/
					reader.seekg(count, ios::beg);  /*������ƶ��ļ�ָ������һλ��*/
				}

				count++;
				reader.seekg(count, ios::beg);  /*�������ƶ�ָ�룬Ϊ�˺���ÿ���ַ���λASCII��Ŀո�*/
				writer << hex_to_dec(ascii);    /*��ȡ�õ���λʮ������ASCII��ͨ������ת����д��ת�����ļ�*/

				if (reader.peek() == ' ' && i != 7) {  /*�������˿ո���i��Ϊ7����˵����һ��Ԫ�ز���16�����������*/
					loop = 0;
					break;
				}

				else if (reader.peek() == ' ' && i == 7) {  /*�������˿ո���iΪ7����˵����һ��Ԫ��ȫ����ȡ���*/
					count = count + 22;
					reader.seekg(count, ios::beg);  /*�ļ�ָ���ƶ�22λ�����Ը��к�����������ݣ�ָ����һ����λ*/
				}
			}
		}
	}

	reader.close();  /*�ر��ļ�*/
	writer.close();  /*�ر�ת������ļ�*/
	return 0;
}