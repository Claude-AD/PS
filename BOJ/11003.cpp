#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, L;
    cin >> N >> L;
    deque<pair<int, int>> dq;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;

        // 새로운 숫자가 덱에서 가장 큰 숫자고 마지막에 오도록 큰 숫자는 모두 제거
        // 어짜피 제일 작은수만 출력하므로 큰 숫자는 모두 제거해도 상관 x
        // 이렇게 하면 덱에는 숫자들이 오름차순으로 저장되며, 
        // 구간 내 가장 작은 값은 맨 앞에 있게됨
        while (!dq.empty() && dq.back().second >= num) {
            dq.pop_back();
        }
        // 새로운 숫자는 항상 push
        dq.push_back({ i, num });

        // 구간을 벗어나는 숫자는 삭제(하나씩 넣으니깐 하나씩 삭제해도 구간 유지 가능)
        if (dq.front().first <= i - L) dq.pop_front();

        // 최소값 출력
        cout << dq.front().second << ' ';
    }
}