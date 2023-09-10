#include <bits/stdc++.h>
using namespace std;

int dp[502][502];
int sum[502];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            int file_size;
            cin >> file_size;
            sum[i] = sum[i - 1] + file_size;
        }

        for (int k = 1; k < n; k++) {
            for (int i = 1; i + k <= n; i++) {
                int j = i + k;
                dp[i][j] = INT_MAX;
                for (int mid = i; mid < j; mid++)
                    dp[i][j] = min(dp[i][j], dp[i][mid] + dp[mid + 1][j] + sum[j] - sum[i - 1]);
            }
        }
        cout << dp[1][n] << '\n';
    }
}