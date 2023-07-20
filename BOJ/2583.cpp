#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int dist[102][102];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int n, m, k;

int bfs(int i, int j); // bfs�� �����ϰ� ������ ���̸� ����

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) fill(dist[i], dist[i] + m, -1);
    while(k--) { // �зµ� ���簢���� ��ǥ�� 2���� �迭�� ������Ŵ
        int x1, y1, x2, y2;
        int i1, j1, i2, j2;
        cin >> x1 >> y1 >> x2 >> y2;
        i1 = n - y2;
        j1 = x1;
        i2 = n - y1 - 1;
        j2 = x2 - 1;
        for (int i = i1; i <= i2; i++) { // ���簢������ ���� �Ұ�
            for (int j = j1; j <= j2; j++) {
                dist[i][j] = 0;
            }
        }
    }
    int area_cnt = 0; // ������ ����
    vector<int> areas; // ���� ���̸� ������ ����
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (dist[i][j] == -1) { // bfs�� ������ ������ ���� ���� ����
                area_cnt++;
                areas.push_back(bfs(i, j));
            }
        }
    }
    sort(areas.begin(), areas.end()); // ������ ���� ������������ ����
    cout << area_cnt << '\n';
    for (auto i : areas) cout << i << ' ';
    return 0;
}

int bfs(int i, int j) {
    int area = 1;
    queue<pair<int, int>> q;
    q.push({ i, j });
    dist[i][j] = 1;
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (dist[nx][ny] != -1) continue;
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            q.push({ nx, ny });
            area++; // bfs ���ึ�� ���� ���� ����
        }
    }
    return area;
}