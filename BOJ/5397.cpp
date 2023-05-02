#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tc;
    cin >> tc;
    while(tc--) {
        string input;
        cin >> input;
        list<char> pw;
        auto cursor = pw.end();
        for(auto c : input) {
            if(c == '<') {
                if(cursor != pw.begin()) cursor--;
            }
            else if(c == '>') {
                if(cursor != pw.end()) cursor++;
            }
            else if(c == '-') {
                if(cursor != pw.begin()) {
                    cursor--;
                    cursor = pw.erase(cursor);
                }
            }
            else {
                // cursor가 가리키는 곳 앞에 c를 삽입
                pw.insert(cursor, c);
            }
        }
        for(auto c : pw) cout << c;
        cout << '\n';
    }
}