#include <bits/stdc++.h>
using namespace std;

char dungeon[32][32][32];
int dist[32][32][32];
int dx[6] = { 0, 1, 0, -1, 0, 0 };
int dy[6] = { 1, 0, -1, 0, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };
int L, R, C;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (1) {
        queue<tuple<int, int, int>> q;
        cin >> L >> R >> C;
        if (L == 0 && R == 0 && C == 0) break;
        for (int k = 0; k < L; k++) {
            for (int i = 0; i < R; i++) {
                for (int j = 0; j < C; j++) {
                    char c;
                    cin >> c;
                    dungeon[i][j][k] = c;
                    if (c == 'S') {
                        q.push({ i, j, k });
                        dist[i][j][k] = 0;
                    }
                    else if (c == '.' || c == 'E') {
                        dist[i][j][k] = -1;
                    }
                }
            }
        }
        bool escape = false;
        while ((!q.empty()) && (!escape)) {
            auto cur = q.front(); q.pop();
            int curX, curY, curZ;
            tie(curX, curY, curZ) = cur;
            for (int dir = 0; dir < 6; dir++) {
                int nx = curX + dx[dir];
                int ny = curY + dy[dir];
                int nz = curZ + dz[dir];
                if (nx < 0 || nx >= R || ny < 0 || ny >= C || nz < 0 || nz >= L)
                    continue;
                if (dist[nx][ny][nz] != -1) continue;
                if (dungeon[nx][ny][nz] == 'E') {
                    escape = true;
                    cout << "Escaped in " << dist[curX][curY][curZ] + 1
                         << " minute(s).\n";
                    break;
                }
                dist[nx][ny][nz] = dist[curX][curY][curZ] + 1;
                q.push({ nx, ny, nz });
            }
        }
        if (!escape) cout << "Trapped!\n";
        fill(&dist[0][0][0], &dist[31][31][32], 0);
    }
    return 0;
}