#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    int nice_cnt = 0;
    while(N--) {
        string str;
        cin >> str;
        stack<char> S;
        for(auto c : str) {
            if(S.empty() || c != S.top()) S.push(c);
            else S.pop();
        }
        if(S.empty()) nice_cnt++;
    }
    cout << nice_cnt;
}