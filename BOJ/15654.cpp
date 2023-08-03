#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];
vector<int> v;
bool isused[10005];

void func(int k) {
    if(k == m) {
        for(int i=0; i<m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    for(int i=0; i<n; i++) {
        if(!isused[v[i]]) {
            arr[k] = v[i];
            isused[v[i]] = true;
            func(k+1);
            isused[v[i]] = false;
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