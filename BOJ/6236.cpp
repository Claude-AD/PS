#include <bits/stdc++.h>
using namespace std;

int arr[100005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M, s = 0, e = 0;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        e += arr[i];
    }

    int ans;
    while (s <= e) { // �̺� Ž�� Ż�� ����
        int mid = (s + e) / 2;
        int cnt = 1, k = mid;
        bool pass = true;
        for (int i = 0; i < N; i++) {
            if (arr[i] > mid) { // *�Ϸ翡 �� ���� k���� ũ�� ����x
                pass = false;
                break;
            }
            if (arr[i] > k) { // �Ϸ翡 �� ���� ���� ������ ū ���
                cnt++; // ���� Ƚ�� ī��Ʈ
                k = mid; // ���� ���� �ְ� �ٽ� ���� ����
            }
            k -= arr[i]; // �Ϸ翡 �� ���� ���� k���� ����
        }
        // ���� Ƚ���� ���ų� ����x -> ����ݾ� �ø�
        if (!pass || cnt > M) s = mid + 1; 
        else {
            // *��Ȯ�� M���� ���߱� ���ؼ� ���� �ݾ��� �׳� ����� �ݾ׺��� ������
            // ���� �ݾ��� ���忡 ����ְ� �ٽ� K���� ������ �� �ִ�.
            // -> ��, ���� Ƚ���� M���� �۾Ƶ� ���� �ȴٴ� ���̴�.
            ans = mid;
            e = mid - 1;
        }
    }
    cout << ans;
}