#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b);

int main(void)
{
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n1, n2;
    cin >> n1 >> n2;
    int g = gcd(n1, n2);
    cout << g << '\n';
    cout << g * (n1 / g) * (n2 / g);
}

int gcd(int a, int b) {
    int r = a % b;
    if(r == 0) return b;
    else return gcd(b, r);
}