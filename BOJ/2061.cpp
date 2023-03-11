#include <iostream>
#include <string>
using namespace std;

// 우리가 일반적으로 손으로 나눗셈할 때 사용하는 알고리즘 (C언어 큰 정수의 나눗셈, 나머지)
int longRemainder(const string& str, const int& divider)
{
    int ret = 0;
    for (int i = 0; i < str.length(); i++)
    {
        ret = (ret * 10 + (str[i] - '0')) % divider;
    }
    return ret;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string K; // 입력값의 범위가 longlong을 훨씬 벗어나기 때문에 문자열로 입력받아야 함
    int L;
    cin >> K >> L;

    for (int prime = 2; prime < L; prime++)
    {
        if (longRemainder(K, prime) == 0)
        {
            cout << "BAD " << prime;
            return 0;
        }
    }
    cout << "GOOD";
    return 0;
}