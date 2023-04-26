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

// 어떤 수의 약수는 제곱근을 기준으로 대칭이기 때문에 제곱근까지만 나눠보면
// 소수 판별 가능
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