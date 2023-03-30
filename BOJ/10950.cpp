#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T, sum = 0; 
    string s;
    cin >> T >> s;
    for (int i = 0; i < T; i++) sum += s[i] - '0';
    cout << sum;
}