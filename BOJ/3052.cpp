#include <bits/stdc++.h>
using namespace std;

int r[42]; // �� 10�� 42�� ���� �������� ������ �迭

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 10; i++) {
        int n;
        cin >> n;
        r[n % 42]++;
    }
    int ans = 10;
    for (int i = 0; i < 42; i++) {
        if (r[i] != 0) {
            ans -= r[i]; // ���� �� ���� 10������ ��� ���ְ�
            ans++; // �� ���� �����ϴ� 1�� ������
        }
    }
    cout << ans;
}