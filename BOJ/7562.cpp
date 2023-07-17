#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int dist[302][302];
int dx[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int dy[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int I, srcX, srcY, dstX, dstY;
        cin >> I >> srcX >> srcY >> dstX >> dstY;
        for (int i = 0; i < I; i++) fill(dist[i], dist[i] + I, -1);
        queue<pair<int, int>> q;
        q.push({ srcX, srcY });
        dist[srcX][srcY] = 0;
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            for (int dir = 0; dir < 8; dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if (nx < 0 || nx >= I || ny < 0 || ny >= I) continue;
                if (dist[nx][ny] != -1) continue;
                dist[nx][ny] = dist[cur.X][cur.Y] + 1;
                q.push({ nx, ny });
            }
        }
        cout << dist[dstX][dstY] << '\n';
    }
    return 0;
}