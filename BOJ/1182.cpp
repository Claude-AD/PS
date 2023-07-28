#include <bits/stdc++.h>
using namespace std;

int n, s, cnt = 0;
int arr[22];

void func(int cur, int tot) {
    if(cur == n) {
        if(tot == s) cnt++;
        return;
    }
    func(cur+1, tot); // 현재 보고 있는 수를 더하거나
    func(cur+1, tot+arr[cur]); // 더하지 않거나
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s;
    for(int i = 0; i < n; i++) cin >> arr[i];
    func(0, 0);
    if(s == 0) cnt--; // 크기가 양수인 부분수열만 구하므로 공집합의 경우를 빼줌
    cout << cnt;
}