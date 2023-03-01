#include <iostream>
#include <string>
using namespace std;

int main(void) {
	int test_case;
	cin >> test_case;

	for (int i = 0; i < test_case; i++) {
		bool isExist[11] = { false }; // 겹치는 10진수를 체크하기 위한 배열 
		int beautyOfInt = 0; // 아름다운 수의 정도

		// 아름다운 정도를 알고 싶은 수를 입력받음
		string str; 
		cin >> str;

		// 수의 모든 자리의 10진수를 비교
		for (int j = 0; j < str.length(); j++) {
			// 만약 해당 수가 이전까지 한번도 등장하지 않았다면
			if (isExist[str[j] - '0'] == false) { 
				isExist[str[j] - '0'] = true; // 등장했다고 기록 후
				beautyOfInt++; // 수의 아름다운 정도를 하나 증가
			}
		}
		cout << beautyOfInt << endl; // 수의 아름다운 정도 출력
	}
	return 0;
}