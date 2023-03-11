#include <iostream>
#include <string>
using namespace std;

// �츮�� �Ϲ������� ������ �������� �� ����ϴ� �˰��� (C��� ū ������ ������, ������)
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

    string K; // �Է°��� ������ longlong�� �ξ� ����� ������ ���ڿ��� �Է¹޾ƾ� ��
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