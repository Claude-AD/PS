#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K, A[10];
    cin >> N >> K;

    int pos = N-1, cnt = 0;
    for(int i=0; i<N; i++) {
        int num;
        cin >> num;
        A[i] = num;
        if(num > K) {
            pos = i-1;
            break;
        }
    }
    while(K > 0 && pos >= 0) {
        cnt += K / A[pos];
        K %= A[pos--];
    }
    cout << cnt;
}