//
// Created by ¿±¡ÿ«ı on 2023/09/13.
//
#include <bits/stdc++.h>
using namespace std;

int arr[10];
int N;

bool isPrime(int n) {
    if(n <= 1) return false;
    for(int i=2; i<=sqrt(n); i++) {
        if(n % i == 0) return false;
    }
    return true;
}

void func(int k) {
    if(k == N + 1) {
        cout << arr[N] << '\n';
        return;
    }
    for(int i=1; i<=9; i++) {
        int temp = arr[k-1] * 10 + i;
        if(isPrime(temp)) {
            arr[k] = temp;
            func(k+1);
        }
    }
}

int main() {
//#ifdef ONLINE_JUDGE
//  freopen("input.txt", "r", stdin);
//#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    func(1);
}
