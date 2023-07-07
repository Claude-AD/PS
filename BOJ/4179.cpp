#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
char maze[1002][1002];
int Jdist[1002][1002]; // Joe�� �Ÿ� ����
int Fdist[1002][1002]; // Fire�� �Ÿ� ����
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int r, c;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<pair<int, int>> Q;
    pair<int, int> J_start; // queue�� �ϳ��� ���� ���� J�� ������ġ�� ������
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> maze[i][j];
            if (maze[i][j] == '.') { // .�� ���� �� �� �����Ƿ� .�� ���� -1�� �ʱ�ȭ
                Jdist[i][j] = -1;
                Fdist[i][j] = -1;
            }
            else if (maze[i][j] == 'J') { // Fire ���� BFS ������ Joe�� ������ ���� ����
                J_start = { i, j };
                // Fdist[i][j] = -1;
            }
            else if (maze[i][j] == 'F') {
                Q.push({ i, j });
                // Jdist[i][j] = -1;
            }
        }
    }
    while (!Q.empty()) { // Fire ���� BFS����
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
    while (!Q.empty()) { // Fire�� �Ÿ����� Joe�� �Ÿ��� ũ�ų� ������ ���� �Ұ�
        auto cur = Q.front(); Q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            // Joe�� ��ġ�� ���� ������ ���� == Joe�� Fire�� ���� ������ Ż��
            if (nx < 0 || nx >= r || ny < 0 || ny >= c) { 
                cout << Jdist[cur.X][cur.Y] + 1;
                return 0;
            }
            if (Jdist[nx][ny] != -1) continue;
            // ��! Fire�� �湮�ߴ� ĭ�� ���ؼ��� �񱳸� ����� ��!!
            // �湮���� ���� ĭ�� -1�̹Ƿ� �׻� Joe�� �Ÿ��� ũ�� ������ ���� �߻�
            if (Fdist[nx][ny] != -1 && Jdist[cur.X][cur.Y] + 1 >= Fdist[nx][ny]) continue;
            Jdist[nx][ny] = Jdist[cur.X][cur.Y] + 1;
            Q.push({ nx, ny });
        }
    }
    cout << "IMPOSSIBLE";
}