#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    string board, ans = "";
    cin >> board;

    int xCnt = 0;
    for(int j=0; j<board.size(); j++) {
        if(board[j] == 'X') xCnt++;
        // .이 연달아 나올 때
        else if(board[j] == '.' && xCnt == 0) {
            ans += '.';
            continue;
        }
        else if(board[j] == '.') {
            if(xCnt % 2 == 1) {
                cout << -1;
                return 0;
            }
            else {
                for(int i=0; i<(xCnt/4); i++)
                    ans += "AAAA";
                xCnt -= (xCnt / 4) * 4;
                for(int i=0; i<(xCnt/2); i++)
                    ans += "BB";
                xCnt -= (xCnt / 2) * 2;
                ans += '.';
            }
        }
    }
    // .없이 보드가 끝났을 때
    if(xCnt) {
        if(xCnt % 2 == 1) {
            cout << -1;
            return 0;
        }
        for(int i=0; i<(xCnt/4); i++)
            ans += "AAAA";
        xCnt -= (xCnt / 4) * 4;
        for(int i=0; i<(xCnt/2); i++)
            ans += "BB";
        xCnt -= (xCnt / 2) * 2;
    }
    cout << ans << '\n';
}