#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int board[102][102];
int dist[102][102];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int n;

void bfs(int i, int j);

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int ans = 0, max = 1, min = 100; // 최대 안전영역 개수, 최대, 최소 높이
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            if (board[i][j] > max) max = board[i][j];
            if (board[i][j] < min) min = board[i][j];
        }
    }
    for (int h = min; h <= max; h++) { // 최소 높이부터 최대 높이까지
        for (int i = 0; i < n; i++) { // 물에 잠기지 않는 부분에 접근 가능
            for (int j = 0; j < n; j++) {
                if (board[i][j] >= h) 
                    dist[i][j] = -1;
            }
        }
        int res = 0; // 비가 해당 높이까지 내릴 때 안전 영역 개수
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][j] == -1) {
                    res++;
                    bfs(i, j);
                }
            }
        }
        if (res > ans) ans = res; // 최대 안전 영역 계산
    }
    cout << ans;
}

void bfs(int i, int j) {
    queue<pair<int, int>> q;
    q.push({ i, j });
    dist[i][j] = 0;
    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (dist[nx][ny] != -1) continue;
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            q.push({ nx, ny });
        }
    }
}