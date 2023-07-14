#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

char board[102][102];
bool vis[102][102];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, h_res = 0, c_res = 0;
    queue<pair<int, int>> hq, cq;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cin >> board[i][j];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (vis[i][j] == false) {
                h_res++;
                char reg = board[i][j];
                hq.push({ i, j });
                vis[i][j] = true;
                while (!hq.empty()) {
                    auto cur = hq.front();
                    hq.pop();
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                        if (board[nx][ny] != reg || vis[nx][ny] == true) continue;
                        hq.push({ nx, ny });
                        vis[nx][ny] = true;
                    }
                }
            }
        }
    }
    cout << h_res;

    for (int i = 0; i < n; i++) fill(vis[i], vis[i] + n, 0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (vis[i][j] == false) {
                c_res++;
                char reg = board[i][j];
                cq.push({ i, j });
                vis[i][j] = true;
                while (!cq.empty()) {
                    auto cur = cq.front();
                    cq.pop();
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                        if (reg == 'R' || reg == 'G') {
                            if (board[nx][ny] == 'B' || vis[nx][ny] == true) continue;
                        }
                        else {
                            if (board[nx][ny] != 'B' || vis[nx][ny] == true) continue;
                        }
                        cq.push({ nx, ny });
                        vis[nx][ny] = true;
                    }
                }
            }
        }
    }
    cout << ' ' << c_res;
    return 0;
}