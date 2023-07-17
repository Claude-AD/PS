#include <bits/stdc++.h>
using namespace std;

int box[102][102][102];
int dist[102][102][102];
int dx[6] = { 0, 1, 0, -1, 0, 0 };
int dy[6] = { 1, 0, -1, 0, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };
int n, m, h;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> n >> h;
    queue<tuple<int, int, int>> q;
    int cnt = 0; // 저장될 때부터 모든 토마토가 익어있는지 확인하기 위한 변수
    int ans = 0; // 토마토가 모두 익을 때까지 걸리는 일 수
    for (int k = 0; k < h; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                dist[i][j][k] = -1;
                cin >> box[i][j][k];
                if (box[i][j][k] == 1) {
                    cnt++;
                    q.push({ i, j, k });
                    dist[i][j][k] = 0;
                }
                else if (box[i][j][k] == -1) {
                    cnt++;
                    dist[i][j][k] = 0;
                }
            }
        }
    }
    if (cnt == n * m * h) {
        cout << 0;
        return 0;
    }
    while (!q.empty()) {
        auto cur = q.front();
        int curX = get<0>(cur);
        int curY = get<1>(cur);
        int curZ = get<2>(cur);
        q.pop();
        for (int dir = 0; dir < 6; dir++) {

            int nx = curX + dx[dir];
            int ny = curY + dy[dir];
            int nz = curZ + dz[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h)
                continue;
            if (box[nx][ny][nz] == -1 || dist[nx][ny][nz] != -1) continue;
            q.push({ nx, ny, nz });
            dist[nx][ny][nz] = dist[curX][curY][curZ] + 1;
        }
    }
    for (int k = 0; k < h; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (dist[i][j][k] == -1) {
                    cout << -1;
                    return 0;
                }
                else ans = max(ans, dist[i][j][k]);
            }
        }
    }
    cout << ans;
    return 0;
}