#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (1) {
        int a, b;
        cin >> a >> b;
        if (a == 0 && b == 0) return 0;
        else cout << a + b << '\n';
    }
}