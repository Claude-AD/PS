#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        for(int k=0; k<i; k++) cout << ' ';
        for(int j=n; j>i; j--) cout << '*';
        cout << '\n';
    }
}