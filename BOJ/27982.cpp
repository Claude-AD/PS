#include <bits/stdc++.h>
using namespace std;

int space[6][6][6];
int dx[6] = { 1, -1, 0, 0, 0, 0 };
int dy[6] = { 0, 0, 1, -1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    while (m--) {
        int x, y, z;
        cin >> x >> y >> z;
        space[x][y][z] = 1;
    }
    int ans = 0;
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                int cnt = 0;
                for (int dir = 0; dir < 6; dir++) {
                    if (space[i][j][k] != 1) break;
                    int nx = i + dx[dir];
                    int ny = j + dy[dir];
                    int nz = k + dz[dir];
                    if (nx < 1 || nx > n || ny < 1 || ny > n || nz < 1 || nz > n)
                        break;
                    if (space[nx][ny][nz] == 1) cnt++;
                }
                if (cnt == 6) ans++;
            }
        }
    }
    cout << ans;
}