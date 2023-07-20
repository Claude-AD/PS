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
    q.push(s); // s������ ����
    floors[s] = 0; // ���� ��ġ�� ��ư�� �ȴ������Ƿ� 0
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