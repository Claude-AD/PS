#include <bits/stdc++.h>
using namespace std;

int board[502][502]; // Paper
bool vis[502][502]; // Table that records which nodes visited
int dx[4] = {1, 0, -1, 0}; // coordinates for above,
// below, left, right of cur.X
int dy[4] = {0, 1, 0, -1}; // coordinates for " of cur.Y
int n, m; // row, column numbers

int main(void)
{
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<pair<int, int> > Q; // Store vertices visiting
    int pic_cnt = 0; // The count of pictures
    int biggest = 0; // The biggest picture's size

    cin >> n >> m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> board[i][j];
        }
    }

    for(int i=0; i < n; i++) {
        for(int j=0; j<m; j++) {
            if(vis[i][j] || board[i][j] != 1) continue;
            else
            {
                pic_cnt++;
                int size = 0;
                vis[i][j] = 1;
                Q.push(make_pair(i, j));
                while(!Q.empty()) // Until the queue becomes empty,
                {
                    auto cur = Q.front();
                    Q.pop(); // pop front node from queue
                    size++;
                    for(int dir=0; dir<4; dir++) // investigate 4 around vertices of cur
                    {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];
                        // if indexes are out of range, stop
                        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                        // if vertex was already visited or not a picture, stop
                        if(vis[nx][ny] || board[nx][ny] != 1) continue;
                        vis[nx][ny] = 1; // marked as visit
                        Q.push(make_pair(nx, ny));
                    }
                }
                if(size > biggest) biggest = size;
            }
        }
    }
    cout << pic_cnt << '\n' << biggest;
}