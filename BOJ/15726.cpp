#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    double a, b, c;
    // 결과값은 소수점을 버린다고 하지만
    // 곱하고 나누는 과정에서 소수점에 따라 값이 달라질 수 있으므로
    // a, b, c는 double로 선언해야 한다.
    int ans1, ans2;
    cin >> a >> b >> c;

    ans1 = a * b / c;
    ans2 = a / b * c;
    cout << (ans1 < ans2 ? ans2 : ans1);
}