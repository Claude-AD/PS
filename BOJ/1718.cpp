#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	string plaintext, key;
	getline(cin, plaintext);
	cin >> key;

	// �� ���̿� ��ȣȭ Ű�� ���̸� �����
	string same_length_key = "";
	for (int i = 0; i < plaintext.length() / key.length(); i++)
		same_length_key += key;

	for (int i = 0; i < plaintext.length() % key.length(); i++)
		same_length_key += key[i];

	// ��ȣȭ Ű�� ���� �ѱ��ھ� ���ϸ� ��ȣ������ �ٲ۴�
	for (int i = 0; i < plaintext.length(); i++)
	{
		// ���� �����̸� �׳� �Ѿ
		if (plaintext[i] == ' ')
			continue;

		// ��ȣȭ Ű�� �ش��ϴ� ���ĺ��� �� ��° ���ĺ����� �ľ�
		int convert_num = (int)same_length_key[i] - 97 + 1;
		// ������ ���ڰ� 'a' ������ ���ڰ� �Ǹ� 
		if ((int)plaintext[i] - convert_num < 97) 
		{
			// ���ĺ� �󿡼� �� �ڷ� ������ ������
			int k = (int)plaintext[i] - convert_num;
			plaintext[i] = 122 - (97 - k) + 1;
		}
		else  // �ƴ϶��
		{
			// �׳� ��ȯ
			plaintext[i] -= convert_num;
		}
	}
	// ��ȣ�� ���
	cout << plaintext << endl;
	return 0;
}