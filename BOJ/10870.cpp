//
// Created by ¿±¡ÿ«ı on 2023/09/12.
//
#include <bits/stdc++.h>
using namespace std;

int N;

int func(int n) {
    if(n==0) return 0;
    if(n==1) return 1;
    return func(n-2) + func(n-1);
}

int main() {
//#ifdef ONLINE_JUDGE
//  freopen("input.txt", "r", stdin);
//#endif

    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    cout << func(N);
}
