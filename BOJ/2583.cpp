#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int dist[102][102];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int n, m, k;

int bfs(int i, int j); // bfs를 수행하고 영역의 넓이를 리턴

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) fill(dist[i], dist[i] + m, -1);
    while(k--) { // 압력된 직사각형의 좌표를 2차원 배열에 대응시킴
        int x1, y1, x2, y2;
        int i1, j1, i2, j2;
        cin >> x1 >> y1 >> x2 >> y2;
        i1 = n - y2;
        j1 = x1;
        i2 = n - y1 - 1;
        j2 = x2 - 1;
        for (int i = i1; i <= i2; i++) { // 직사각형에는 접근 불가
            for (int j = j1; j <= j2; j++) {
                dist[i][j] = 0;
            }
        }
    }
    int area_cnt = 0; // 영역의 개수
    vector<int> areas; // 영역 넓이를 저장할 벡터
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (dist[i][j] == -1) { // bfs를 시작할 때마다 영역 개수 증가
                area_cnt++;
                areas.push_back(bfs(i, j));
            }
        }
    }
    sort(areas.begin(), areas.end()); // 영역의 넓이 오름차순으로 정렬
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
            area++; // bfs 수행마다 영역 넓이 증가
        }
    }
    return area;
}