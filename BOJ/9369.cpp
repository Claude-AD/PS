#include <iostream>
#include <string>
using namespace std;

int main(void) 
{
	int test_case;
	cin >> test_case;
	for (int i = 0; i < test_case; i++)
	{
		// 암호화된 문장의 개수 입력
		int num_of_code_sen;
		cin >> num_of_code_sen;

		// 암호화된 문장 목록 입력
		string* code_sen_arr = new string[num_of_code_sen];
		for (int j = 0; j < num_of_code_sen; j++)
			cin >> code_sen_arr[j];

		// 해독된 문장 및 해독하고자 하는 통신문 입력
		string encoded_sen, sen_to_encode;
		cin >> encoded_sen >> sen_to_encode;

		// 주어진 해독문에 대응되는 암호문을 찾는 과정
		// 1. 길이 검사

		// 제시된 암호문들의 길이 저장
		int* code_sen_len = new int[num_of_code_sen];
		for (int j = 0; j < num_of_code_sen; j++)
			code_sen_len[j] = code_sen_arr[j].length();

		int encoded_sen_len = encoded_sen.length();


	}
	return 0;
}