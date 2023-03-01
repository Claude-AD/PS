#include <iostream>
using namespace std;

int HowManyLives(const int floor, const int room_number)
{
	if (floor == 0) return room_number; // 0층 i호에는 i명이 산다
	
	int people = 0;
	// a층의 b호에는 a-1층의 1호부터 b호까지 사람들의 수의 합만큼 살아야 한다
	for (int i = 1; i <= room_number; i++)
	{
		people += HowManyLives(floor - 1, i); 
	}
	return people;
}

int main(void) 
{
	int test_case;
	cin >> test_case;
	for (int i = 0; i < test_case; i++)
	{
		int floor, room_number;
		cin >> floor >> room_number;
		cout << HowManyLives(floor, room_number) << endl;
	}
	return 0;
}