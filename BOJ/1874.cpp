#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    stack<int> S;
    string ans;
    int cnt = 1;
    while (n--) {
        int num;
        cin >> num;
        // 최소한 num을 pop하기 위해서는 num까지의 수는 stack에 push되어 들어있어야함
        while (cnt <= num) { 
            S.push(cnt++);
            ans += "+\n";
        }
        // stack에 이미 num이 들어있음에도 불구하고, top에 없어 꺼낼 수 없다면 실패
        if (S.top() != num) {
            cout << "NO";
            return 0;
        }
        // stack에서 해당 수를 꺼냄
        S.pop();
        ans += "-\n";
    }
    cout << ans;
}