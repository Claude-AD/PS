#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M, cnt = 0;
    deque<int> DQ;
    cin >> N >> M;
    for(int i=1; i<=N; i++) DQ.push_back(i);
    while(M--) {
        int th;
        cin >> th;
        int idx = find(DQ.begin(), DQ.end(), th) - DQ.begin();
        while(DQ.front() != th) {
            if(idx <= DQ.size() / 2) {
                DQ.push_back(DQ.front());
                DQ.pop_front();
            }
            else {
                DQ.push_front(DQ.back());
                DQ.pop_back();
            }
            cnt++;
        }
        DQ.pop_front();
    }
    cout << cnt;
}