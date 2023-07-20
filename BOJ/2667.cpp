#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int board[27][27];
int dist[27][27];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int n;

int bfs(int i, int j); // bfs�� �����ϰ� �� ������ ���� ���� ����

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        string str; // �Է¿� ������ �����Ƿ� ���ڿ��� ����
        cin >> str;
        for (int j = 0; j < n; j++) {
            board[i][j] = str[j] - '0';
            if (str[j] == '1') dist[i][j] = -1; // ���� �������� dist�迭 -1�� �ʱ�ȭ
        }
    }
    int area_cnt = 0; // ������ ����
    vector<int> areas; // ���� �� ���� ���� ������ ����
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == -1) { // bfs�� ������ ������ ���� ���� ����
                area_cnt++;
                areas.push_back(bfs(i, j));
            }
        }
    }
    sort(areas.begin(), areas.end());
    cout << area_cnt << '\n';
    for (auto i : areas) cout << i << '\n';
    return 0;
}

int bfs(int i, int j) {
    int area = 1;
    queue<pair<int, int>> q;
    q.push({ i, j });
    dist[i][j] = 0;
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (dist[nx][ny] != -1) continue;
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            q.push({ nx, ny });
            area++; // bfs ���ึ�� ���� �� ����
        }
    }
    return area;
}