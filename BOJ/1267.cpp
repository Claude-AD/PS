#include <bits/stdc++.h>
using namespace std;

int YoungSick(int time) {
    return (time / 30 + 1) * 10;
}

int MinSick(int time) {
    return (time / 60 + 1) * 15;
}

int main(void)
{
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, y_bill=0, m_bill=0;
    cin >> n;

    for(int j=0; j<n; j++) {
        int time;
        cin >> time;
        y_bill += YoungSick(time);
        m_bill += MinSick(time);
    }
    if(y_bill == m_bill) cout << "Y M " << y_bill;
    else if(y_bill < m_bill) cout << "Y " << y_bill;
    else cout << "M " << m_bill;
    cout << '\n';
}