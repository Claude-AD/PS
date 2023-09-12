#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;

void makeFrontHighest(deque<pi>& DQ) {
    bool isFrontHighest = true;
    int frontPrec = DQ.front().second;
    for(auto it : DQ) {
        if(it.second > frontPrec) {
            isFrontHighest = false;
            break;
        }
    }
    if(isFrontHighest) return;
    else {
        DQ.push_back(DQ.front());
        DQ.pop_front();
        makeFrontHighest(DQ);
    }
}

int main() {
//#ifdef ONLINE_JUDGE
//  freopen("input.txt", "r", stdin);
//#endif

    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        deque<pi> DQ;
        int n, m, order = 1;
        cin >> n >> m;
        for(int i=0; i<n; i++) {
            int prec;
            cin >> prec;
            DQ.push_back({i, prec});
        }
        while(1) {
            makeFrontHighest(DQ);
            if(DQ.front().first == m) break;
            DQ.pop_front();
            order++;
        }
        cout << order << '\n';
    }
}
