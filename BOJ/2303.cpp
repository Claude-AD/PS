#include <bits/stdc++.h>
using namespace std;

int LargeNumber(int arr[])
{
    int max = (arr[0] + arr[1] + arr[2]) % 10;
    for(int a=0; a<4; a++) {
        for(int b=a+1; b<5; b++) {
            int sum=0;
            for(int c=0; c<5; c++)
                if(c!=a && c!=b) sum+=arr[c];

            if(sum%10 > max) max = sum%10;
        }
    }
    return max;
}

int main(void)
{
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, win_val = 0, winner;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        int tmp[5];
        for(int j=0; j<5; j++) cin >> tmp[j];
        if(LargeNumber(tmp) >= win_val) {
            win_val = LargeNumber(tmp);
            winner = i+1;
        }
    }
    cout << winner;
}