#include <bits/stdc++.h>
using namespace std;

int arr[100005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x, ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    cin >> x;

    sort(arr, arr + n);

    int s = 0, e = n - 1;
    while (s < e) {
        int sum = arr[s] + arr[e];
        if (sum < x) s++;
        else if (sum == x) {
            ans++;
            s++;
            e--;
        }
        else if (sum > x) e--;
    }
    cout << ans;
}