#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    string str;
    cin >> str;
    int ans = 0;
    stack<char> S;
    for(int i=0; i<str.length(); i++) {
        if(str[i] == '(') S.push(str[i]);
        else {
            if (str[i-1] == '(') {
                S.pop();
                ans += S.size();
            }
            else {
                S.pop();
                ans++;
            }
        }
    }
    cout << ans;
}