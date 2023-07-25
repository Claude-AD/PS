#include <bits/stdc++.h>
using namespace std;

int board[64][64];

bool check(int x, int y, int n) { // ������ ��� ���� ���� �Ǿ��ִ��� �˻�
    for (int i = x; i < x + n; i++) {
        for (int j = y; j < y + n; j++) {
            // ���� �ٸ� ���� ���� �ִٸ� false ����
            if (board[i][j] != board[x][y]) return false;
        }
    }
    return true; // ������ ��� ���� ���� �Ǿ� �ִٸ� true ����
}

void func(int x, int y, int n) {
    if (check(x, y, n)) { // ������ ��� ���� ���� �Ǿ��ִٸ� ����
        cout << board[x][y];
        return;
    }
    cout << '(';
    int nn = n / 2; // ������ 4���� ������ ���� ���� �ݺ�
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