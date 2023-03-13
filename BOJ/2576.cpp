#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int num, sum=0, min=100;
    for(int i=0; i<7; i++) {
        cin >> num;
        if(num & 1) {
            sum += num;
            if(num < min)
                min = num;
        }
    }
    if(sum) cout << sum << '\n' << min;
    else cout << -1;
}