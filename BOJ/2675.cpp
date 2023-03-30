#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int t, r;
    cin >> t;
    while (t--) {
        string s, p = "";
        cin >> r >> s;
        for (int i = 0; i < s.size(); i++) {
            for (int j = 0; j < r; j++) p += s[i];
        }
        cout << p << '\n';
    }
}