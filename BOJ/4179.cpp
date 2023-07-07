#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
char maze[1002][1002];
int Jdist[1002][1002]; // Joe의 거리 저장
int Fdist[1002][1002]; // Fire의 거리 저장
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int r, c;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<pair<int, int>> Q;
    pair<int, int> J_start; // queue를 하나만 쓰기 위해 J의 시작위치를 저장함
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> maze[i][j];
            if (maze[i][j] == '.') { // .인 곳만 갈 수 있으므로 .일 때만 -1로 초기화
                Jdist[i][j] = -1;
                Fdist[i][j] = -1;
            }
            else if (maze[i][j] == 'J') { // Fire 먼저 BFS 돌리고 Joe를 돌리기 위해 저장
                J_start = { i, j };
                // Fdist[i][j] = -1;
            }
            else if (maze[i][j] == 'F') {
                Q.push({ i, j });
                // Jdist[i][j] = -1;
            }
        }
    }
    while (!Q.empty()) { // Fire 먼저 BFS돌림
        auto cur = Q.front(); Q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if (Fdist[nx][ny] >= 0) continue;
            Fdist[nx][ny] = Fdist[cur.X][cur.Y] + 1;
            Q.push({ nx, ny });
        }
    }
    Q.push(J_start);
    while (!Q.empty()) { // Fire의 거리보다 Joe의 거리가 크거나 같으면 접근 불가
        auto cur = Q.front(); Q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            // Joe의 위치가 범위 밖으로 도달 == Joe가 Fire를 피해 무사히 탈출
            if (nx < 0 || nx >= r || ny < 0 || ny >= c) { 
                cout << Jdist[cur.X][cur.Y] + 1;
                return 0;
            }
            if (Jdist[nx][ny] != -1) continue;
            // 꼭! Fire가 방문했던 칸에 대해서만 비교를 해줘야 함!!
            // 방문하지 않은 칸은 -1이므로 항상 Joe의 거리가 크기 때문에 오류 발생
            if (Fdist[nx][ny] != -1 && Jdist[cur.X][cur.Y] + 1 >= Fdist[nx][ny]) continue;
            Jdist[nx][ny] = Jdist[cur.X][cur.Y] + 1;
            Q.push({ nx, ny });
        }
    }
    cout << "IMPOSSIBLE";
}