#include <bits/stdc++.h>
using namespace std;

int board[130][130];
int cnt[2]; // 0(�Ͼ��), 1(�Ķ���) �������� ����

bool check(int x, int y, int n) { // ���̰� ��� ���� ������ �Ǿ��ִ��� �˻�
    for (int i = x; i < x + n; i++) {
        for (int j = y; j < y + n; j++) {
            // ���̿� �ٸ� ���� ���� �ִٸ� false ����
            if (board[i][j] != board[x][y]) return false; 
        }
    }
    return true; // ���̰� ��� ���� ������ �Ǿ� �ִٸ� true ����
}

void func(int x, int y, int n) {
    if (check(x, y, n)) { // ���̰� ��� ���� ������ �Ǿ��ִٸ� �״�� ���
        cnt[board[x][y]]++;
        return;
    }
    int nn = n / 2; // ���̸� ���� ũ���� ���� 4���� �ڸ��� ���� ���� �ݺ�
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