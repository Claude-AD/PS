#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string text;
    while (getline(cin, text)) { // 입력 줄의 개수가 정해지지 않았을 때는 이렇게.
        cout << text << '\n'; // 알고리즘 문제는 출력과 입력의 순서는 무관하다.
    }
}