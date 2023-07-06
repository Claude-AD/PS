#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int box[1002][1002];
int dist[1002][1002];
int N, M;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> M >> N;
    queue<pair<int, int>> Q;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> box[i][j];
            if (box[i][j] == 1)
                Q.push({ i, j });
            if(box[i][j] == 0)
                dist[i][j] = -1;                
        }
    }
    while (!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (dist[nx][ny] != -1) continue;
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            Q.push({ nx, ny });
        }
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (dist[i][j] == -1) {
                cout << -1;
                return 0;
            }
            ans = max(ans, dist[i][j]);
        }
    }
    cout << ans;
}