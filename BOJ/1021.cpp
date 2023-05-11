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
        for(int i=0; i<DQ.size(); i++) {
            if(DQ[i] == th) {
                if(i <= DQ.size() / 2) {
                    for(int j=0; j<i; j++) {
                        DQ.push_back(DQ.front());
                        DQ.pop_front();
                        cnt++;
                    }
                }
                else {
                    for(int j=DQ.size()-1; j>=i; j--) {
                        DQ.push_front(DQ.back());
                        DQ.pop_back();
                        cnt++;
                    }
                }
                DQ.pop_front();
            }
        }
    }
    cout << cnt;
}