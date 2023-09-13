//
// Created by ¿±¡ÿ«ı on 2023/09/13.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
//#ifdef ONLINE_JUDGE
//  freopen("input.txt", "r", stdin);
//#endif

    ios::sync_with_stdio(0);
    cin.tie(0);

    int s, idx1, idx2;
    bool found = false;
    cin >> s;
    for(int i=0; i<31; i++) {
        for(int j=i; j<31; j++) {
            if(s == (i*i) + (j*j)) {
                found = true;
                idx1 = i;
                idx2 = j;
                break;
            }
        }
        if(found) break;
    }
    if(!found) {
        cout << "Impossible";
    }
    else {
        vector<pair<int, int>> vertices;
        int x = 3, y = 2;
        vertices.push_back({x-idx1, y+idx2});
        vertices.push_back({x, y});
        vertices.push_back({x+idx2-idx1, y+idx1+idx2});
        vertices.push_back({x+idx2, y+idx1});
        for(auto it : vertices) {
            cout << it.first << ' ' << it.second << '\n';
        }
    }
}
