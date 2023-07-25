#include <bits/stdc++.h>
using namespace std;

int board[2190][2190];
int m_one, zero, one; // -1, 0, 1�θ� ä���� ������ ����

int check(int x, int y, int n) { // ���̰� ��� ���� ���� �Ǿ��ִ��� �˻�
    int crit = board[x][y]; // ������ �� ù ����
    for (int i = x; i < x + n; i++) {
        for (int j = y; j < y + n; j++) {
            if (board[i][j] != crit) return 2; // ���̿� �ٸ� ���Ұ� �ִٸ� 2 ����
        }
    }
    return crit; // ���̰� ��� ���� ���� �Ǿ� �ִٸ� �� ���� ����
}

void func(int x, int y, int n) {
    int res = check(x, y, n); // ���̰� ��� ���� ���� �Ǿ��ִ��� �˻�
    if (res != 2) { // ���̰� ��� ���� ���� �Ǿ��ִٸ� �״�� ���
        if (res == -1) m_one++;
        else if (res == 0) zero++;
        else if (res == 1) one++;
        return;
    }
    int nn = n / 3; // ���̸� ���� ũ���� ���� 9���� �ڸ��� ���� ���� �ݺ�
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