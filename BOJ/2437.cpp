#include <bits/stdc++.h>
using namespace std;

int a[1005];

int main(void)
{
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, sum = 1;
    cin >> N;
    for(int i=0; i<N; i++) cin >> a[i];
    sort(a, a+N);
    if(a[0] != 1) {
        cout << 1;
        return 0;
    }
    for(int i=1; i<N; i++) {
        if(a[i] > sum+1) break;
        sum += a[i];
    }
    cout << sum+1;
}