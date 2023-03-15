#include <bits/stdc++.h>
using namespace std;

/* 방법 1 : 유클리드 호제법 단 a>b여야함
int GetGCD(const int& a, const int& b) {
    return (a%b==0 ? b : GetGCD(b, a%b));
} */

int rings[100], n, gcd_val;

int main(void)
{
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0; i<n; i++) cin >> rings[i];
    for(int i=1; i<n; i++) {
        // 방법2 : <numeric> gcd함수 사용
        gcd_val = gcd(rings[0], rings[i]);
        cout << rings[0] / gcd_val << '/' << rings[i] / gcd_val << '\n';
    }
}