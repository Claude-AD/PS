//
// Created by ¿±¡ÿ«ı on 10/25/23.
//
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    ll ans = 0;
    for(int i=0; i<n; i++) {
        int h;
        cin >> h;
        ans += h;
    }
    vector<int> v;
    for(int i=0; i<n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    for(int i=0; i<v.size(); i++) {
        ans += v[i] * i;
    }
    cout << ans;
}
