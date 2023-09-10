#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int board[10][10];
int n, m;
vector<pair<int, int>> cctv;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j] != 0 && board[i][j] != 6)
                cctv.push_back({ i, j });
        }
    }
    for (auto p : cctv) {
        int curX = p.X;
        int curY = p.Y;
    }
    int res = 0;
    cout << res;
    return 0;
}