#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    while(N--) {
        int a[26] = {};
        string s1, s2;
        cin >> s1 >> s2;

        // 첫 번째 문자열의 각 문자는 개수 + 1
        for(auto c : s1) a[c-'a']++;
        // 두 번째 문자열의 각 문자는 개수 - 1
        for(auto c : s2) a[c-'a']--;

        // 0이 아닌 배열의 원소가 있을 경우, 개수가 다른 문자가 존재한다는 뜻
        bool isPossible = true;
        for(int i : a) if(i != 0) isPossible = false;

        if(isPossible) cout << "Possible\n";
        else cout << "Impossible\n";
    }
}