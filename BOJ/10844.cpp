#include <bits/stdc++.h>
using namespace std;

#define mod 1000000000;
long long dp[102][10]; // dp[a][b] == 길이가 a일 때 마지막 수가 b인 계단수의 개수

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    long long ans = 0;
    cin >> N;

    dp[1][0] = 0;
    for (int i = 1; i <= 9; i++) dp[1][i] = 1;
    for (int i = 2; i <= N; i++) {
        for (int j = 0; j <= 9; j++) {
            if (j == 0) {
                dp[i][j] = dp[i - 1][1] % mod;
            }
            else if (j == 9) {
                dp[i][j] = dp[i - 1][8] % mod;
            }
            else dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1] % mod;
        }
    }
    for (int i = 0; i <= 9; i++) ans += dp[N][i];
    cout << ans % mod;
}