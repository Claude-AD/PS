#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	map<string, int> card;
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		string fruit; int num;
		cin >> fruit >> num;
		card[fruit] += num;
	}
	
	bool hit_the_bell = false;
	for (auto iter : card)
	{
		if (iter.second == 5)
		{
			hit_the_bell = true;
			break;
		}
	}

	if (hit_the_bell)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	return 0;
}