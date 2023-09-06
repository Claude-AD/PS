#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;

int main() {
//#ifdef ONLINE_JUDGE
//    freopen("input.txt", "r", stdin);
//#endif

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    deque<pi> DQ;
    for(int i=1; i<=n; i++) {
        int num;
        cin >> num;
        DQ.push_back({i, num});
    }
    while(!DQ.empty()) {
        cout << DQ.front().first << ' ';
        int val = DQ.front().second;
        DQ.pop_front();
        if(val < 0) {
            for(int i=val; i<0; i++) {
                DQ.push_front(DQ.back());
                DQ.pop_back();
            }
        }
        // 양수라 오른쪽으로 가는 것은 if문 진입 전에
        // pop_front를 수행하면서 이미 한 칸 오른쪽으로 갔으므로
        // 한 칸 적게 수행해야 함
        else {
            for(int i=1; i<val; i++) {
                DQ.push_back(DQ.front());
                DQ.pop_front();
            }
        }
    }
}
