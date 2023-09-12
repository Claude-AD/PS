//
// Created by ¿±¡ÿ«ı on 2023/09/12.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
//#ifdef ONLINE_JUDGE
//  freopen("input.txt", "r", stdin);
//#endif

    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> divisor;
    for(int i=1; i<=n; i++) {
        if(n % i == 0) divisor.push_back(i);
    }
    if(divisor.size() < k) cout << 0;
    else cout << divisor[k-1];
}
