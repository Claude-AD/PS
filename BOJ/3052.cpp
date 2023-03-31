#include <bits/stdc++.h>
using namespace std;

int r[42]; // 수 10개 42로 나눈 나머지를 저장할 배열

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 10; i++) {
        int n;
        cin >> n;
        r[n % 42]++;
    }
    int ans = 10;
    for (int i = 0; i < 42; i++) {
        if (r[i] != 0) {
            ans -= r[i]; // 같은 수 개수 10개에서 모두 빼주고
            ans++; // 한 개는 세야하니 1을 더해줌
        }
    }
    cout << ans;
}