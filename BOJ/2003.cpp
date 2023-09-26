#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;

    vector<int> v;
    while(n--) {
        int e;
        cin >> e;
        v.push_back(e);
    }
    int l=0, r=-1;
    int sum = 0, ans = 0;
    while(1) {
        if(sum < m) {
            if(r+1 > v.size()) break;
            sum += v[++r];
        }
        else if(sum > m) {
            sum -= v[l++];
        }
        else {
            ans++;
            sum -= v[l++];
        }
    }
    cout << ans;
}