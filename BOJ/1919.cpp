#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a[26] = {};
    string s1, s2;
    cin >> s1 >> s2;

    for(int i=0; i<s1.size(); i++) a[s1[i]-'a']++;
    for(int i=0; i<s2.size(); i++) a[s2[i]-'a']--;

    int cnt = 0;
    for(int i=0; i<26; i++) cnt += abs(a[i]);
    cout << cnt;
}