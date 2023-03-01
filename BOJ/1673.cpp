#include <iostream>
using namespace std;

int main(void) 
{
	int coupon, convert_cnt, stamp;
	// 문제에서 입력값의 범위가 주어지지 않았으므로 입력 파일의 끝(EOF)까지 입력받음
	// cin은 cin 객체를 반환하지만 iostream 헤더파일 내에 이를 bool 또는 다른 타입으로
	// 바꾸어 줄 수 있는 conversion operator가 정의되어 있어서
	// if나 while 안에 들어가면 예외적으로 operator에 의해 자동으로 bool로 바뀜
	// 만약 scanf를 사용한다면 파일의 끝을 만나지 않을 때 까지(!=EOF)로 조건을 바꿔야 함
	while (cin >> coupon >> convert_cnt) 
	{
		int stamp = 0, eatable_chicken = 0;
		while (coupon > 0) 
		{
			eatable_chicken += coupon; // 쿠폰의 개수만큼 치킨을 바꿔먹음
			stamp += coupon; // 쿠폰으로 바꿔먹은 치킨만큼 도장이 생김
			coupon = stamp / convert_cnt; // 생긴 도장으로 쿠폰을 바꿈
			stamp = stamp % convert_cnt; // 쿠폰을 바꾸고 남은 도장
			// 이후에는 도장으로 바꾼 쿠폰과 남은 도장을 모두 사용할 때까지 반복
		}
		cout << eatable_chicken << endl; // 총 먹을 수 있는 치킨의 수 출력
	}
	return 0;
}