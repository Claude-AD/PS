#include <bits/stdc++.h>
using namespace std;

int freq[205];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, v;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        freq[num + 100]++;
    }
    cin >> v;
    cout << freq[v + 100];
}