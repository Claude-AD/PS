#include <bits/stdc++.h>
using namespace std;

void ChangePos(int arr[], const int idx1, const int idx2)
{
    int temp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = temp;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int arr[3];
    for (int i = 0; i < 3; i++)
        cin >> arr[i];

    if (arr[0] > arr[1])
        ChangePos(arr, 0, 1);

    if (arr[1] > arr[2])
        ChangePos(arr, 1, 2);

    if (arr[0] > arr[1])
        ChangePos(arr, 0, 1);

    for (int i = 0; i < 3; i++)
        cout << arr[i] << ' ';

    return 0;
}