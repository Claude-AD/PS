#include <bits/stdc++.h>
using namespace std;

int d[1000005];
int n;

int main(void)
{
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=2; i<=n; i++) { // 이렇게 비교하면 자연스럽게 3가지 비교 가능
        d[i] = d[i-1]+1;
        if(i%2 == 0) d[i] = min(d[i], d[i/2]+1);
        if(i%3 == 0) d[i] = min(d[i], d[i/3]+1);
    }
    cout << d[n];
}