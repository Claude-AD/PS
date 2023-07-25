#include <bits/stdc++.h>
using namespace std;

int board[64][64];

bool check(int x, int y, int n) { // 영상이 모두 같은 수로 되어있는지 검사
    for (int i = x; i < x + n; i++) {
        for (int j = y; j < y + n; j++) {
            // 영상에 다른 수가 섞여 있다면 false 리턴
            if (board[i][j] != board[x][y]) return false;
        }
    }
    return true; // 영상이 모두 같은 수로 되어 있다면 true 리턴
}

void func(int x, int y, int n) {
    if (check(x, y, n)) { // 영상이 모두 같은 수로 되어있다면 압축
        cout << board[x][y];
        return;
    }
    cout << '(';
    int nn = n / 2; // 영상을 4개로 나누어 위의 과정 반복
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            func(x + i * nn, y + j * nn, nn);
        }
    }
    cout << ')';
    return;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    string str;
    for (int i = 0; i < n; i++) {
        cin >> str;
        for (int j = 0; j < n; j++) {
            board[i][j] = str[j] - '0';
        }
    }
    func(0, 0, n);
}