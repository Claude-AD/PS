#include <bits/stdc++.h>
using namespace std;

int alpha[26]; // 전역 선언하면 자동으로 0으로 초기화

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) alpha[s[i] - 97]++;
    for (int i = 0; i < 26; i++) cout << alpha[i] << ' ';
}