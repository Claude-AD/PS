//
// Created by ¿±¡ÿ«ı on 2023/09/20.
//
#include <bits/stdc++.h>
using namespace std;

int SumOfDigit(string& str) {
    int sum = 0;
    for(auto c : str) {
        if(isdigit(c)) sum += c - '0';
    }
    return sum;
}

bool comp(string& a, string& b) {
    if(a.length() != b.length()) return a.length() < b.length();
    else if(SumOfDigit(a) != SumOfDigit(b)) return SumOfDigit(a) < SumOfDigit(b);
    else return a < b;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    vector<string> v;
    while(t--) {
        string str;
        cin >> str;
        v.push_back(str);
    }
    sort(v.begin(), v.end(), comp);
    for(auto it : v)
        cout << it << '\n';
}
