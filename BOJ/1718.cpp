#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	string plaintext, key;
	getline(cin, plaintext);
	cin >> key;

	// 평문 길이와 암호화 키의 길이를 맞춘다
	string same_length_key = "";
	for (int i = 0; i < plaintext.length() / key.length(); i++)
		same_length_key += key;

	for (int i = 0; i < plaintext.length() % key.length(); i++)
		same_length_key += key[i];

	// 암호화 키와 평문을 한글자씩 비교하며 암호문으로 바꾼다
	for (int i = 0; i < plaintext.length(); i++)
	{
		// 평문이 공백이면 그냥 넘어감
		if (plaintext[i] == ' ')
			continue;

		// 암호화 키의 해당하는 알파벳이 몇 번째 알파벳인지 파악
		int convert_num = (int)same_length_key[i] - 97 + 1;
		// 변형된 문자가 'a' 이전의 문자가 되면 
		if ((int)plaintext[i] - convert_num < 97) 
		{
			// 알파벳 상에서 맨 뒤로 순서를 돌린다
			int k = (int)plaintext[i] - convert_num;
			plaintext[i] = 122 - (97 - k) + 1;
		}
		else  // 아니라면
		{
			// 그냥 변환
			plaintext[i] -= convert_num;
		}
	}
	// 암호문 출력
	cout << plaintext << endl;
	return 0;
}