#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long a, b;
    cin >> a >> b;
    if(a > b) swap(a, b); // 예외 1
    if (a == b || b - a == 1) cout << 0; // 예외 2
    else {
        cout << b - a - 1 << '\n';
        for(long long i = a+1; i < b; i++)
            cout << i << ' ';
    }
}