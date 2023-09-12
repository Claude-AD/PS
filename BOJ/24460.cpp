//
// Created by ¿±¡ÿ«ı on 2023/09/12.
//
#include <bits/stdc++.h>
using namespace std;

int board[1025][1025];
int N;

int func(int x, int y, int size) {
    if(size == 1) {
        return board[x][y];
    }
    int arr[4];
    int div_size = size / 2;
    arr[0] = func(x, y, div_size);
    arr[1] = func(x, y + div_size, div_size);
    arr[2] = func(x + div_size, y, div_size);
    arr[3] = func(x + div_size, y + div_size, div_size);
    sort(arr, arr+4);
    return arr[1];

}

int main() {
//#ifdef ONLINE_JUDGE
//  freopen("input.txt", "r", stdin);
//#endif

    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++)
            cin >> board[i][j];
    }
    cout << func(0, 0, N);
}
