#include <bits/stdc++.h>
using namespace std;

void potion(double& v, const double& a) {
    v = 1 - (1 - v) * (1 - a);
}

int main(void)
{
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    double v = 0; int n;
    cin >> n;

    for(int i=0; i<n; i++) {
        double a;
        cin >> a;
        potion(v, a/100);
        cout << fixed; cout.precision(6);
        cout << v * 100 << '\n';
    }
}