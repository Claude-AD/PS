#include <bits/stdc++.h>
using namespace std;

int floors[1000002];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int f, s, g, u, d;
    cin >> f >> s >> g >> u >> d;
    fill(floors + 1, floors + f + 1, -1);

    queue<int> q;
    q.push(s); // s층에서 시작
    floors[s] = 0; // 현재 위치는 버튼을 안눌렀으므로 0
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (auto nx : {cur + u, cur - d}) {
            if (nx > f || nx < 1) continue;
            if (floors[nx] != -1) continue;
            floors[nx] = floors[cur] + 1;
            q.push(nx);
        }
    }
    if (floors[g] == -1) cout << "use the stairs";
    else cout << floors[g];
}