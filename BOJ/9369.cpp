#include <iostream>
#include <string>
using namespace std;

int main(void) 
{
	int test_case;
	cin >> test_case;
	for (int i = 0; i < test_case; i++)
	{
		// ��ȣȭ�� ������ ���� �Է�
		int num_of_code_sen;
		cin >> num_of_code_sen;

		// ��ȣȭ�� ���� ��� �Է�
		string* code_sen_arr = new string[num_of_code_sen];
		for (int j = 0; j < num_of_code_sen; j++)
			cin >> code_sen_arr[j];

		// �ص��� ���� �� �ص��ϰ��� �ϴ� ��Ź� �Է�
		string encoded_sen, sen_to_encode;
		cin >> encoded_sen >> sen_to_encode;

		// �־��� �ص����� �����Ǵ� ��ȣ���� ã�� ����
		// 1. ���� �˻�

		// ���õ� ��ȣ������ ���� ����
		int* code_sen_len = new int[num_of_code_sen];
		for (int j = 0; j < num_of_code_sen; j++)
			code_sen_len[j] = code_sen_arr[j].length();

		int encoded_sen_len = encoded_sen.length();


	}
	return 0;
}