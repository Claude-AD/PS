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
    vector<int> v;
    while(n--) {
        int w;
        cin >> w;
        v.push_back(w);
    }
    sort(v.begin(), v.end());
    ll ans = v[0] * v.size();
    for(int i=1; i<v.size(); i++) {
        if(v[i] * (v.size()-i) > ans)
            ans = v[i] * (v.size()-i);
    }
    cout << ans;
}
