#include <bits/stdc++.h>
using namespace std;

typedef deque<int> DQI;
void parse(const string& str, DQI& dq) {
    string temp = str.substr(1, str.size()-2);
    string buf;
    istringstream iss;
    iss.str(temp);
    while(getline(iss, buf, ','))
        dq.push_back(stoi(buf));
}

void printResult(const DQI& dq) {
    cout << '[';
    for(int i=0; i<dq.size(); i++) {
        cout << dq[i];
        if(i < dq.size() - 1)
            cout << ',';
    }
    cout << "]\n";
}

int main(void)
{
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--) {
        DQI dq;
        string p, num;
        int n;
        cin >> p >> n >> num;
        parse(num, dq);
        bool rev = 0;
        for(auto c : p) {
            // reverse를 for문 안에 집어넣으면 O(n^2)가 되서 시간초과가 나오는듯
            if(c=='R') rev = 1 - rev;
            else {
                if(dq.empty()) {
                    cout << "error\n";
                    goto END;
                }
                if(!rev) dq.pop_front();
                else dq.pop_back();
            }
        }
        if(rev) reverse(dq.begin(), dq.end());
        printResult(dq);
        END:;
    }
}
