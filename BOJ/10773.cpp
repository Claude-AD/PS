#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<int> S;
    int K, sum = 0;
    cin >> K;
    while(K--) {
        int num;
        cin >> num;
        if(num == 0) S.pop();
        else S.push(num);
    }
    while(!S.empty()) {
        sum += S.top();
        S.pop();
    }
    cout << sum;
}