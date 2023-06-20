#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int ans = 0;
    int num = 1; // 곱해질 값
    string str;
    cin >> str;
    stack<char> S;
    for(int i=0; i<str.length(); i++) {
        if(str[i] == '(') {
            num *= 2;
            S.push(str[i]);
        }
        else if(str[i] == '[') {
            num *= 3;
            S.push(str[i]);
        }
        else if(str[i] == ')') {
            if(S.empty() || S.top() != '(') {
                cout << 0;
                return 0;
            }
            // 이 조건 추가 안해주면 직전 괄호가 여는 괄호가 아니라
            // 다른 올바른 괄호문이 섞여있어도 ans에 더하게 되어버림
            if(str[i-1] == '(') ans += num;
            S.pop();
            num /= 2;
        }
        else {
            if(S.empty() || S.top() != '[') {
                cout << 0;
                return 0;
            }
            if(str[i-1] == '[') ans += num;
            S.pop();
            num /= 3;
        }
    }
    if(S.empty()) cout << ans;
    else cout << 0;
}