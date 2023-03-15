#include <bits/stdc++.h>
using namespace std;

int ingred[15005], n, m, armor;

int main(void)
{
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i=0; i<n; i++) cin >> ingred[i];

    /* 방법 1 : 이중 for문
    for(int s=0; s<n-1; s++) {
        for(int e=s+1; e<n; e++)
            if(ingred[s] + ingred[e] == m) armor++;
    } */

    // 방법 2 : 투 포인터
    sort(ingred, ingred+n);
    int s=0, e=n-1;
    while(s<e) {
        int sum = ingred[s] + ingred[e];
        if(sum == m) {
            armor++;
            s++;
            e--;
        }
        else if (sum < m) s++;
        else e--;
    }
    cout << armor;
}