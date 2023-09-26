#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& v) {
    int n = v.size();
    if(n==1) return v[0];

    vector<int> left(v.begin(), v.begin()+n/2);
    vector<int> right(v.begin()+n/2, v.end());

    int rst = max(solve(left), solve(right));

    int lit = n/2-1;
    int rit = n/2;

    int height = min(v[lit], v[rit]);
    rst = max(rst, height * 2);

    while(1) {
        bool l = lit-1 >= 0;
        bool r = rit+1 < n;

        if(l && r) {
            if(v[lit-1] >= v[rit+1]) {
                height = min(height, v[--lit]);
                rst = max(rst, height * (rit - lit + 1));
            }
            else {
                height = min(height, v[++rit]);
                rst = max(rst, height * (rit - lit + 1));
            }
        }
        else if(l) {
            height = min(height, v[--lit]);
            rst = max(rst, height * (rit - lit + 1));
        }
        else if(r) {
            height = min(height, v[++rit]);
            rst = max(rst, height * (rit - lit + 1));
        }
        else break;
    }
    return rst;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> v;
    while(n--) {
        int e;
        cin >> e;
        v.push_back(e);
    }
    cout << solve(v);
}
