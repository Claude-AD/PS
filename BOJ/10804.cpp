#include <bits/stdc++.h>
using namespace std;

void Reverse(int arr[], int a, int b) {
    while(a<b) {
        int temp;
        temp = arr[a];
        arr[a++] = arr[b];
        arr[b--] = temp;
    }
}

/* 또는 swap 사용
void Reverse(int a, int b) {
    for(int i=0; i<(b-a+1)/2; i++)
        swap(num[a+i], num[b-i]);
}*/

int main(void)
{
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int arr[21];
    for(int i=0; i<21; i++) arr[i] = i;
    for(int j=0; j<10; j++) {
        int a, b;
        cin >> a >> b;
        Reverse(arr, a, b);
        // 또는 STL reverse 사용
        // reverse(num+a, num+b+1);
    }
    for(int j=1; j<21; j++) cout << arr[j] << ' ';
}