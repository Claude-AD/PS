#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t,s;
    cin >> t >> s;

    if(12<=t&&t<=16&&s==0) cout << 320;
    else cout << 280;
    return 0;
}