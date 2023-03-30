#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int note[8], order;
    for (int i = 0; i < 8; i++) cin >> note[i];
    for (int i = 0; i < 7; i++) {
        if (abs(note[i] - note[i + 1]) > 1) {
            cout << "mixed";
            return 0;
        }
    }
    if (note[0] > note[1]) cout << "descending";
    else cout << "ascending";
}