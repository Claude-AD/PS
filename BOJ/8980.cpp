#include <bits/stdc++.h>
using namespace std;

typedef struct _boxInfo {
    int from, to, num;
} BoxInfo;

BoxInfo CreateBoxInfo(int v1, int v2, int n) {
    BoxInfo box;
    box.from = v1; box.to = v2; box.num = n;
    return box;
}

bool cmp(const BoxInfo& b1, const BoxInfo& b2) {
    if (b1.to == b2.to) return b1.from < b2.from;
    else return b1.to < b2.to;
}

BoxInfo arr[10005];
int truck[2005];
int ans;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, C, M;
    cin >> N >> C >> M;
    for (int i = 0; i < M; i++) {
        int from, to, num;
        cin >> from >> to >> num;
        arr[i] = CreateBoxInfo(from, to, num);
    }
    
    sort(arr, arr + M, cmp);
    
    for (int i = 0; i < M; i++) {
        // from���� to - 1�������� �ư��־�� �ϴ� �ڽ��� �ִ� ����
        int maxNumOfBox = 0; 
        for (int j = arr[i].from; j < arr[i].to; j++) {
            maxNumOfBox = max(truck[j], maxNumOfBox);
        }
        // ���� ���� ���� �� �ִ� �ڽ��� ����
        int boxToLoad = min(arr[i].num, C - maxNumOfBox);
        for (int j = arr[i].from; j < arr[i].to; j++) {
            truck[j] += boxToLoad;
        }
        ans += boxToLoad;
    }
    cout << ans;
}