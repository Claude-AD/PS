//
// Created by ¿±¡ÿ«ı on 2023/09/12.
//
#include <bits/stdc++.h>
using namespace std;

string str;

int Palindromes(int i, int j) {
    if(i >= j) return true;
    if(str[i] == str[j])
        return Palindromes(i+1, j-1);
    else
        return false;
}

int main() {
//#ifdef ONLINE_JUDGE
//  freopen("input.txt", "r", stdin);
//#endif

    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> str;
    bool isPalindrome = Palindromes(0, str.length() - 1);
    cout << (isPalindrome ? "true" : "false");
}
