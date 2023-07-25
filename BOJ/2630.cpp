#include <bits/stdc++.h>
using namespace std;

int board[130][130];
int cnt[2]; // 0(하얀색), 1(파란색) 색종이의 개수

bool check(int x, int y, int n) { // 종이가 모두 같은 색으로 되어있는지 검사
    for (int i = x; i < x + n; i++) {
        for (int j = y; j < y + n; j++) {
            // 종이에 다른 색이 섞여 있다면 false 리턴
            if (board[i][j] != board[x][y]) return false; 
        }
    }
    return true; // 종이가 모두 같은 색으로 되어 있다면 true 리턴
}

void func(int x, int y, int n) {
    if (check(x, y, n)) { // 종이가 모두 같은 색으로 되어있다면 그대로 사용
        cnt[board[x][y]]++;
        return;
    }
    int nn = n / 2; // 종이를 같은 크기의 종이 4개로 자르고 위의 과정 반복
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            func(x + i * nn, y + j * nn, nn);
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
    func(0, 0, n);
    for (auto i : cnt) cout << i << '\n';
}