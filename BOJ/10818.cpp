#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> v;
    int N;
    cin >> N;
    for(int i=0; i<N; i++) {
        int elem;
        cin >> elem;
        v.push_back(elem);
    }
    cout << *min_element(v.begin(), v.end())
    << ' ' << *max_element(v.begin(), v.end());
}