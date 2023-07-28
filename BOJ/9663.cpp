#include <bits/stdc++.h>
using namespace std;

int n, cnt = 0;
bool isused1[16]; // 같은 열
bool isused2[30]; // 오른쪽 대각선
bool isused3[30]; // 왼쪽 대각선

void func(int cur) {
    if(cur == n) {
        cnt++;
        return;
    }
    for(int i = 1; i <= n; i++) {
        if(!isused1[i] && !isused2[cur+i] && !isused3[cur-i+n-1]) {
            isused1[i] = true;
            isused2[cur + i] = true;
            isused3[cur - i + n - 1] = true;
            func(cur + 1);
            isused1[i] = false;
            isused2[cur + i] = false;
            isused3[cur - i + n - 1] = false;
        }
    }
}

int main(void)
{
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    func(0);
    cout << cnt;
}