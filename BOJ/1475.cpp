#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, ans = 0;
    cin >> n;
    int freq[10] = {};
    while (n > 0) {
        freq[n % 10]++;
        n /= 10;
    }
    for (int i = 0; i < 10; i++) {
        if (i == 6 || i == 9) continue;
        ans = max(ans, freq[i]);
    }
    // (freq[6]+freq[9])/2를 올림한 값이 6, 9에 대한 필요한 세트의 수이므로 
    // (freq[6]+freq[9]+1)/2을 계산
    ans = max(ans, (freq[6] + freq[9] + 1) / 2);
    cout << ans;
}