//
// Created by ¿±¡ÿ«ı on 2023/09/12.
//
#include <bits/stdc++.h>
using namespace std;

typedef pair<string, string> ps;

int arr[10];
bool isused[10];
vector<ps> solutions;

void func(int k) {
    if(k == 10) {
        string s1 = "", s2 = "";
        for(int i=0; i<5; i++)
            s1 += to_string(arr[i]);
        for(int i=5; i<10; i++)
            s2 += to_string(arr[i]);

        if(stoi(s1) / stoi(s2) == 9 && stoi(s1) % stoi(s2) == 0)
            solutions.push_back({s1, s2});
        return;
    }
    for(int i=0; i<=9; i++) {
        if(!isused[i]) {
            arr[k] = i;
            isused[i] = true;
            func(k+1);
            isused[i] = false;
        }
    }
}

int main() {
//#ifdef ONLINE_JUDGE
//  freopen("input.txt", "r", stdin);
//#endif

    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    func(0);
    cout << solutions[N-1].first << ' ' << solutions[N-1].second;
}
