#include <bits/stdc++.h>
using namespace std;

double score[1002];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        double sc;
        cin >> sc;
        score[i] = sc;
    }
    sort(score, score + n);

    double m = score[n - 1];
    double sum = 0;
    for (int i = 0; i < n; i++) {
        score[i] = score[i] / m * 100;
        sum += score[i];
    }
    cout << sum / n;
}