//
// Created by ¿±¡ÿ«ı on 10/25/23.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, l;
    cin >> n >> l;
    vector<int> v;
    for(int i=0; i<n; i++) {
        int fh;
        cin >> fh;
        v.push_back(fh);
    }
    sort(v.begin(), v.end());
    for(int i=0; i<v.size(); i++)
        if(l >= v[i]) l++;
    cout << l;
}
