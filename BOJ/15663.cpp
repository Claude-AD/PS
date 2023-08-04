#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];
vector<int> v;
bool isused[10];

void func(int k) {
    if(k == m) {
        for(int i=0; i<m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    int tmp = 0; // 중복 수열인지 확인 하기 위한 변수
    for(int i=0; i<n; i++) {
        if(!isused[i] && tmp != v[i]) {
            isused[i] = true; // 어짜피 i와 v[i]가 일대일 대응이므로 isused에 i를 사용해도 됨
            arr[k] = v[i];
            tmp = arr[k];
            func(k+1);
            isused[i] = false;
        }
    }
}

int main(void)
{
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());
    func(0);
}