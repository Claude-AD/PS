#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string text;
    int blank_cnt = 0;
    getline(cin, text);

    /* ó���� ������ �߸��� ��� - ���� �ϳ��� �� �ԷµǸ� 0�� ���;ߵǴµ� 1�� ����
    for (int i = 1; i < text.size() - 1; i++) {
        if (text[i] == ' ') blank_cnt++;
    }
    cout << blank_cnt + 1 << "\n"; */

    // ��� 2
    for (int i = 0; i < text.size(); i++) {
        if (text[i] == ' ') blank_cnt++;
    }
    if (text[0] == ' ')blank_cnt--;
    if (text[text.size() - 1] == ' ')blank_cnt--;
    cout << blank_cnt + 1;
}