#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    list<char> str;
    for (auto it : s) str.push_back(it);
    auto cursor = str.end();
    int M;
    cin >> M;
    while (M--) {
        char inst;
        cin >> inst;
        if (inst == 'L') {
            if (cursor != str.begin()) cursor--;
        }
        else if (inst == 'D') {
            if (cursor != str.end()) cursor++;
        }
        else if (inst == 'B') {
            if (cursor != str.begin()) {
                cursor--;
                cursor = str.erase(cursor);
            }
        }
        else { // 'P'
            char add;
            cin >> add;
            str.insert(cursor, add);
        }
    }
    for (auto it : str) cout << it;
}