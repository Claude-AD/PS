#include <iostream>
using namespace std;

int HowManyLives(const int floor, const int room_number)
{
	if (floor == 0) return room_number; // 0�� iȣ���� i���� ���
	
	int people = 0;
	// a���� bȣ���� a-1���� 1ȣ���� bȣ���� ������� ���� �ո�ŭ ��ƾ� �Ѵ�
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