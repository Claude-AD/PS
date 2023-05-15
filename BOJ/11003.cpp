#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, L;
    cin >> N >> L;
    deque<pair<int, int>> dq;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;

        // ���ο� ���ڰ� ������ ���� ū ���ڰ� �������� ������ ū ���ڴ� ��� ����
        // ��¥�� ���� �������� ����ϹǷ� ū ���ڴ� ��� �����ص� ��� x
        // �̷��� �ϸ� ������ ���ڵ��� ������������ ����Ǹ�, 
        // ���� �� ���� ���� ���� �� �տ� �ְԵ�
        while (!dq.empty() && dq.back().second >= num) {
            dq.pop_back();
        }
        // ���ο� ���ڴ� �׻� push
        dq.push_back({ i, num });

        // ������ ����� ���ڴ� ����(�ϳ��� �����ϱ� �ϳ��� �����ص� ���� ���� ����)
        if (dq.front().first <= i - L) dq.pop_front();

        // �ּҰ� ���
        cout << dq.front().second << ' ';
    }
}