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
    int ans = 0, max = 1, min = 100; // �ִ� �������� ����, �ִ�, �ּ� ����
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            if (board[i][j] > max) max = board[i][j];
            if (board[i][j] < min) min = board[i][j];
        }
    }
    for (int h = min; h <= max; h++) { // �ּ� ���̺��� �ִ� ���̱���
        for (int i = 0; i < n; i++) { // ���� ����� �ʴ� �κп� ���� ����
            for (int j = 0; j < n; j++) {
                if (board[i][j] >= h) 
                    dist[i][j] = -1;
            }
        }
        int res = 0; // �� �ش� ���̱��� ���� �� ���� ���� ����
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][j] == -1) {
                    res++;
                    bfs(i, j);
                }
            }
        }
        if (res > ans) ans = res; // �ִ� ���� ���� ���
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