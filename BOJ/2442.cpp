#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i=1; i<=n; i++) {
        for(int k=n; k>i; k--) cout << ' ';
        for(int j=0; j<2*i-1; j++) cout << '*';
        cout << '\n';
    }
}