#include <bits/stdc++.h>
using namespace std;

int tree[1000005];

int main(void)
{
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    for(int i=0; i<N; i++) cin >> tree[i];

    int start = 0;
    int end = *max_element(tree, tree+N);

    while(start+1 < end) {
        long long sum = 0;
        int mid = (start + end) / 2;
        for(int i=0; i<N; i++) {
            if(tree[i] > mid) sum += tree[i] - mid;
        }
        if(sum >= M) start = mid;
        else end = mid;
    }
    cout << start;
}