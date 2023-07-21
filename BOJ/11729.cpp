#include <bits/stdc++.h>
using namespace std;

void hanoi(int from, int mid, int to, int ring) {
    if (ring == 1) {
        cout << from << ' ' << to << '\n';
        return;
    }
    else {
        hanoi(from, to, mid, ring - 1);
        cout << from << ' ' << to << '\n';
        hanoi(mid, from, to, ring - 1);
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    cout << (1<<n) - 1 << '\n';
    hanoi(1, 2, 3, n);
}