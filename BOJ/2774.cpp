#include <iostream>
#include <string>
using namespace std;

int main(void) {
	int test_case;
	cin >> test_case;

	for (int i = 0; i < test_case; i++) {
		bool isExist[11] = { false }; // ��ġ�� 10������ üũ�ϱ� ���� �迭 
		int beautyOfInt = 0; // �Ƹ��ٿ� ���� ����

		// �Ƹ��ٿ� ������ �˰� ���� ���� �Է¹���
		string str; 
		cin >> str;

		// ���� ��� �ڸ��� 10������ ��
		for (int j = 0; j < str.length(); j++) {
			// ���� �ش� ���� �������� �ѹ��� �������� �ʾҴٸ�
			if (isExist[str[j] - '0'] == false) { 
				isExist[str[j] - '0'] = true; // �����ߴٰ� ��� ��
				beautyOfInt++; // ���� �Ƹ��ٿ� ������ �ϳ� ����
			}
		}
		cout << beautyOfInt << endl; // ���� �Ƹ��ٿ� ���� ���
	}
	return 0;
}