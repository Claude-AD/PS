#include <bits/stdc++.h>
using namespace std;

int board[2190][2190];
int m_one, zero, one; // -1, 0, 1로만 채워진 종이의 개수

int check(int x, int y, int n) { // 종이가 모두 같은 수로 되어있는지 검사
    int crit = board[x][y]; // 종이의 맨 첫 원소
    for (int i = x; i < x + n; i++) {
        for (int j = y; j < y + n; j++) {
            if (board[i][j] != crit) return 2; // 종이에 다른 원소가 있다면 2 리턴
        }
    }
    return crit; // 종이가 모두 같은 수로 되어 있다면 그 수를 리턴
}

void func(int x, int y, int n) {
    int res = check(x, y, n); // 종이가 모두 같은 수로 되어있는지 검사
    if (res != 2) { // 종이가 모두 같은 수로 되어있다면 그대로 사용
        if (res == -1) m_one++;
        else if (res == 0) zero++;
        else if (res == 1) one++;
        return;
    }
    int nn = n / 3; // 종이를 같은 크기의 종이 9개로 자르고 위의 과정 반복
    func(x, y, nn); func(x, y + nn, nn); func(x, y + 2 * nn, nn);
    func(x + nn, y, nn); func(x + nn, y + nn, nn); func(x + nn, y + 2 * nn, nn);
    func(x + 2 * nn, y, nn); func(x + 2 * nn, y + nn, nn); func(x + 2 * nn, y + 2 * nn, nn);
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
    cout << m_one << '\n' << zero << '\n' << one;
}