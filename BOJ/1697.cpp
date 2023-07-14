#include <bits/stdc++.h>
using namespace std;

int pos[100002];
int n, k;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    fill(pos, pos + 100002, -1);
    queue<int> q;
    cin >> n >> k;
    pos[n] = 0;
    q.push(n);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        int bfs[3] = { cur - 1, cur + 1, cur * 2 };
        for (int i = 0; i < 3; i++) {
            if (bfs[i] < 0 || bfs[i] > 100000) continue;
            if (pos[bfs[i]] != -1) continue;
            pos[bfs[i]] = pos[cur] + 1;
            q.push(bfs[i]);
        }
    }
    cout << pos[k];
    return 0;
}