//
// Created by ¿±¡ÿ«ı on 10/25/23.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int candy, box;
        vector<int> v;
        cin >> candy >> box;
        for(int i=0; i<box; i++) {
            int r, c;
            cin >> r >> c;
            v.push_back(r*c);
        }
        sort(v.rbegin(), v.rend());
        int ans = 0;
        while(candy > 0) {
            ans++;
            candy -= v.front();
            v.erase(v.begin());
        }
        cout << ans << '\n';
    }
}
