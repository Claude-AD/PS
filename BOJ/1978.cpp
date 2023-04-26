#include <bits/stdc++.h>
using namespace std;

bool isPrime(int num);

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, primeCnt = 0;
    cin >> N;
    while (N--) {
        int num;
        cin >> num;
        if (isPrime(num)) primeCnt++;
    }
    cout << primeCnt;
}

// � ���� ����� �������� �������� ��Ī�̱� ������ �����ٱ����� ��������
// �Ҽ� �Ǻ� ����
bool isPrime(int num) { 
    if (num == 1) return false;
    else if (num == 2) return true;
    else {
        for (int i = 2; i < sqrt(num) + 1; i++) {
            if (num % i == 0) return false;
        }
        return true;
    }
}