#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

char board[1002][1002];
int dist[1002][1002];
int fdist[1002][1002];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        queue<pair<int, int>> q = {}, fq = {};
        bool escape = false;
        int n, m;
        cin >> m >> n;
        for (int i = 0; i < n; i++) {
            fill(dist[i], dist[i] + m, 0);
            fill(fdist[i], fdist[i] + m, 0);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> board[i][j];
                if (board[i][j] == '.') {
                    dist[i][j] = -1;
                    fdist[i][j] = -1;
                }
                else if (board[i][j] == '@') {
                    q.push({ i, j });
                    fdist[i][j] = -1;
                }
                else if (board[i][j] == '*') fq.push({ i, j });
            }
        }
        while (!fq.empty()) {
            auto cur = fq.front();
            fq.pop();
            for (int dir = 0; dir < 4; dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if (fdist[nx][ny] != -1) continue;
                fdist[nx][ny] = fdist[cur.X][cur.Y] + 1;
                fq.push({ nx, ny });
            }
        }
        while ((!q.empty()) && (!escape)) {
            auto cur = q.front();
            q.pop();
            for (int dir = 0; dir < 4; dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                    cout << dist[cur.X][cur.Y] + 1 << '\n';
                    escape = true;
                    break;
                }
                if (dist[nx][ny] != -1) continue;
                if (fdist[nx][ny] != -1 && dist[cur.X][cur.Y] + 1 >= fdist[nx][ny])
                    continue;
                dist[nx][ny] = dist[cur.X][cur.Y] + 1;
                q.push({ nx, ny });
            }
        }
        if(!escape) cout << "IMPOSSIBLE\n";        
    }
    return 0;
}