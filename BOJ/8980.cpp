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
        // from부터 to - 1구간까지 싣고있어야 하는 박스의 최대 개수
        int maxNumOfBox = 0; 
        for (int j = arr[i].from; j < arr[i].to; j++) {
            maxNumOfBox = max(truck[j], maxNumOfBox);
        }
        // 내가 지금 실을 수 있는 박스의 개수
        int boxToLoad = min(arr[i].num, C - maxNumOfBox);
        for (int j = arr[i].from; j < arr[i].to; j++) {
            truck[j] += boxToLoad;
        }
        ans += boxToLoad;
    }
    cout << ans;
}