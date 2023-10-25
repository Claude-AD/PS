//
// Created by ¿±¡ÿ«ı on 10/25/23.
//
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll a, b, ans = 0;
    cin >> a >> b;
    while(b > a) {
        ans++;
        if(b % 2 == 0)
            b /= 2;
        else if(b % 10 == 1)
            b /= 10;
        else
            break;
    }
    if(b == a) cout << ans + 1;
    else cout << -1;
}
