#include <bits/stdc++.h>
using namespace std;

int students[2][6];
int room_cnt;

int main(void)
{
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    for(int i=0; i<n; i++) {
        int sex, year;
        cin >> sex >> year;
        students[sex][year-1]++;
    }

    // 필요한 방의 개수 계산
    for(int i=0; i<2; i++) {
        for(int j=0; j<6; j++) {
            if(students[i][j] % k == 0)
                room_cnt += students[i][j] / k;
            else
                room_cnt += (students[i][j] / k) + 1;
        }
    }
    cout << room_cnt;
}