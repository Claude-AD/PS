#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];
vector<int> v;
// bool isused[10005];

void func(int k) {
    if(k == m) {
        for(int i=0; i<m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    for(int i=0; i<n; i++) {
        if(k == 0 || v[i] >= arr[k-1]) {
            arr[k] = v[i];
            func(k+1);
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