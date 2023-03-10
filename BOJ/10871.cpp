#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    // freopen("C:\\Users\\YunJunHyeok\\source\\repos\\Algorithm\\Algorithm\\BOJ\\input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, X;
    cin >> N >> X;

    vector<int> A;
    A.reserve(N);

    int num;
    for (int i = 0; i < N; i++)
    {
        cin >> num;
        A.push_back(num);
    }

    for (auto iter : A)
    {
        if (iter < X)
            cout << iter << ' ';
    }
    cout << "\n";

    return 0;
}