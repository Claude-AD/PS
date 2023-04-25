#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    string A, B;
    cin >> A >> B;

    char temp;
    temp = A[0];
    A[0] = A[2];
    A[2] = temp;

    temp = B[0];
    B[0] = B[2];
    B[2] = temp;

    if(stoi(A) >= stoi(B)) cout << A;
    else cout << B;
}