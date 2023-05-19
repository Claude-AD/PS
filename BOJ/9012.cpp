#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--) {
        string str;
        cin >> str;
        stack<char> S;
        bool isValid = true;
        for(auto c : str) {
            if(c == '(') S.push(c);
            else {
                if(S.empty() || S.top() != '(') {
                    isValid = false;
                    break;
                }
                else S.pop();
            }
        }
        if(!S.empty()) isValid = false;
        if(isValid) cout << "YES\n";
        else cout << "NO\n";
    }
}