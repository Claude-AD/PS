#include <bits/stdc++.h>
using namespace std;

string ReverseString(const string str)
{
	string res = str;
	for (int i = 0; i < res.size() / 2; i++)
	{
		char temp = res[i];
		res[i] = res[res.size() - 1 - i];
		res[res.size() - 1 - i] = temp;
	}
	return res;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	vector<string> pw;
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		string word;
		cin >> word;
		pw.push_back(word);
	}

	bool breaker = false;
	for (auto iter : pw)
	{
		string reverse = ReverseString(iter);
		for (auto iter2 : pw)
		{
			if (reverse == iter2)
			{
				cout << iter2.size() << " " << iter2[iter2.size() / 2] << endl;
				breaker = true;
				break;
			}
		}
		if (breaker) break;
	}
	return 0;
}