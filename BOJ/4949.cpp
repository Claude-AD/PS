#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (1) {
        string str;
        getline(cin, str);
        if (str == ".") break;
        stack<char> S;
        bool balance = true;
        for (auto c : str) {
            if (c == '(' || c == '[') S.push(c);
            else if (c == ')') {
                if (S.empty() || S.top() != '(') {
                    balance = false;
                    break;
                }
                else S.pop();
            }
            else if (c == ']') {
                if (S.empty() || S.top() != '[') {
                    balance = false;
                    break;
                }
                else S.pop();
            }
        }
        if (!S.empty()) balance = false;
        if (balance) cout << "yes\n";
        else cout << "no\n";
    }
}