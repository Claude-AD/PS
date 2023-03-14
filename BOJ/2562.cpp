#include <bits/stdc++.h>
using namespace std;

int n, max_value, idx;

int main(void)
{
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i=0; i<9; i++) {
        cin >> n;
        // 전역변수의 초기값은 0이므로 바로 비교 가능
        if(n>max_value) {
            max_value = n;
            idx = i+1;
        }
    }
    cout << max_value << '\n' << idx;

    /* 혹은 max_element 함수를 이용한 풀이
    int arr[9];
    for(int i=0; i<9; i++) cin >> arr[i];
    cout << *max_element(arr, arr+9) << '\n';
    cout << max_element(arr, arr+9) - arr + 1; */
}