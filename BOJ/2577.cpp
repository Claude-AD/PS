#include <bits/stdc++.h>
using namespace std;

int freq[10];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c;
    string res;
    cin >> a >> b >> c;
    res = to_string(a * b * c);
    for (int i = 0; i < res.size(); i++) freq[res[i] - '0']++;

    /*
    string을 쓰지 않고 int로만 구현하고 싶다면
    int res = a*b*c;
    while(res>0) {
        freq[res%10]++;
        res/=10;
    }
    */
    for (int i = 0; i < 10; i++) cout << freq[i] << '\n';
}