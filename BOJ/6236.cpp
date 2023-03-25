#include <bits/stdc++.h>
using namespace std;

int arr[100005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M, s = 0, e = 0;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        e += arr[i];
    }

    int ans;
    while (s <= e) { // 이분 탐색 탈출 조건
        int mid = (s + e) / 2;
        int cnt = 1, k = mid;
        bool pass = true;
        for (int i = 0; i < N; i++) {
            if (arr[i] > mid) { // *하루에 쓸 돈이 k보다 크면 성립x
                pass = false;
                break;
            }
            if (arr[i] > k) { // 하루에 쓸 돈이 남은 돈보다 큰 경우
                cnt++; // 인출 횟수 카운트
                k = mid; // 남은 돈을 넣고 다시 돈을 인출
            }
            k -= arr[i]; // 하루에 쓸 돈을 인출 k에서 빼줌
        }
        // 인출 횟수가 많거나 성립x -> 인출금액 늘림
        if (!pass || cnt > M) s = mid + 1; 
        else {
            // *정확히 M번을 맞추기 위해서 남은 금액이 그날 사용할 금액보다 많더라도
            // 남은 금액은 통장에 집어넣고 다시 K원을 인출할 수 있다.
            // -> 즉, 인출 횟수가 M보다 작아도 답이 된다는 뜻이다.
            ans = mid;
            e = mid - 1;
        }
    }
    cout << ans;
}