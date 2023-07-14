#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int field[52][52];
bool vis[52][52];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, n, m, k, x, y;
    cin >> t;
    while (t--) {
        int ans = 0;
        cin >> m >> n >> k;
        for (int i = 0; i < n; i++) {
            fill(field[i], field[i] + m, 0);
            fill(vis[i], vis[i] + m, 0);
        }
        while (k--) {
            cin >> y >> x;
            field[x][y] = 1;
        }
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (field[i][j] == 1 && vis[i][j] == false) {
                    ans++;
                    q.push({ i, j });
                    vis[i][j] = true;
                    while (!q.empty()) {
                        auto cur = q.front();
                        q.pop();
                        for (int dir = 0; dir < 4; dir++) {
                            int nx = cur.X + dx[dir];
                            int ny = cur.Y + dy[dir];
                            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                            if (field[nx][ny] == 0 || vis[nx][ny] == true) continue;
                            q.push({ nx, ny });
                            vis[nx][ny] = true;
                        }
                    }
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}