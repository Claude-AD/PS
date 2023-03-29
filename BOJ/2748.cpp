#include <bits/stdc++.h>
using namespace std;

long long arr[92];

int main(void)
{
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    arr[0] = 0; arr[1] = 1;
    for(int i=2; i<=N; i++) arr[i] = arr[i-1] + arr[i-2];
    cout << arr[N];
}