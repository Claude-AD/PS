#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    stack<int> S;
    string ans;
    int cnt = 1;
    while (n--) {
        int num;
        cin >> num;
        // �ּ��� num�� pop�ϱ� ���ؼ��� num������ ���� stack�� push�Ǿ� ����־����
        while (cnt <= num) { 
            S.push(cnt++);
            ans += "+\n";
        }
        // stack�� �̹� num�� ����������� �ұ��ϰ�, top�� ���� ���� �� ���ٸ� ����
        if (S.top() != num) {
            cout << "NO";
            return 0;
        }
        // stack���� �ش� ���� ����
        S.pop();
        ans += "-\n";
    }
    cout << ans;
}