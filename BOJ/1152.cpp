#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string text;
    int blank_cnt = 0;
    getline(cin, text);

    /* 처음에 생각한 잘못된 방법 - 공백 하나만 딱 입력되면 0이 나와야되는데 1이 나옴
    for (int i = 1; i < text.size() - 1; i++) {
        if (text[i] == ' ') blank_cnt++;
    }
    cout << blank_cnt + 1 << "\n"; */

    // 방법 2
    for (int i = 0; i < text.size(); i++) {
        if (text[i] == ' ') blank_cnt++;
    }
    if (text[0] == ' ')blank_cnt--;
    if (text[text.size() - 1] == ' ')blank_cnt--;
    cout << blank_cnt + 1;
}