#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int d1, d2, d3, money;
    cin >> d1 >> d2 >> d3;
    
    if (d1 == d2 && d2 == d3) money = 10000 + d1 * 1000;
    else if (d1 == d2 || d1 == d3) money = 1000 + d1 * 100;
    else if (d2 == d3) money = 1000 + d2 * 100;
    else money = max({ d1,d2,d3 }) * 100;
    
    cout << money;
}