#include <bits/stdc++.h>
using namespace std;

int maze[102][102];
int dis[102][102];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<pair<int, int> > Q;
    int n, m, dist = 1;
    string row;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> row;
        for (int j = 0; j < m; j++) {
            maze[i][j] = row[j] - '0';
            dis[i][j] = -1;
        }
    }

    dis[0][0] = dist;
    Q.push(make_pair(0, 0));
    while (!Q.empty()) {
        pair<int, int> cur = Q.front();
        Q.pop();
        int curSize = Q.size();
        dist = dis[cur.first][cur.second] + 1;
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (dis[nx][ny] != -1 || maze[nx][ny] != 1) continue;
            dis[nx][ny] = dist;
            Q.push(make_pair(nx, ny));
        }
    }
    cout << dis[n-1][m-1];
}