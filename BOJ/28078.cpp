#include <bits/stdc++.h>
using namespace std;

char DQ[1000005]; // �߷� ť
int wall[1000005]; // �� ��ġ ������ �迭

int main() {
//#ifdef ONLINE_JUDGE
//  freopen("input.txt", "r", stdin);
//#endif

    ios::sync_with_stdio(0);
    cin.tie(0);

    /* 4���� ť�� ���¸� ��Ÿ���� ���� ť */
    /* 0->�⺻, 1�� ������ ������ �ð�������� ȸ�� */
    /* status.front()�� ���� ���� */
    deque<int> statusQ;
    for(int i=0; i<4; i++) statusQ.push_back(i);

    int q, f_idx = 0, b_idx = -1; // �߷� ť���� ����� idx
    int wall_f_idx = 0, wall_b_idx = -1; // �� �迭���� ����� idx
    int ballCnt = 0, wallCnt = 0; // �� ����, �� ����
    cin >> q;
    cin.ignore();
    while(q--) {
        string inst;
        getline(cin, inst, '\n');
        if(inst == "push b") {
            ballCnt++;
            DQ[++b_idx] = 'b';
        }
        else if(inst == "push w") {
            wallCnt++;
            DQ[++b_idx] = 'w';
            wall[++wall_b_idx] = b_idx;
        }
        else if(inst == "pop") {
            if(b_idx >= f_idx) {
                if(DQ[f_idx] == 'w') {
                    wallCnt--;
                    wall_f_idx++;
                }
                else if(DQ[f_idx] == 'b'){
                    ballCnt--;
                }
                f_idx++;
            }
        }
        else if(inst == "rotate l") {
            statusQ.push_front(statusQ.back());
            statusQ.pop_back();
        }
        else if(inst == "rotate r") {
            statusQ.push_back(statusQ.front());
            statusQ.pop_front();
        }
        else if(inst == "count b") {
            cout << ballCnt << '\n';
        }
        else if(inst == "count w") {
            cout << wallCnt << '\n';
        }

        // �߷� ť�� ���ι����� ��
        if(statusQ.front() == 1) { // �ð� �������� �� �� ���� ����
            if(wallCnt == 0) { // ���� �ϳ��� ���� ��
                f_idx = 0;
                b_idx = -1;
                ballCnt = 0;
            }
            else {
                ballCnt -= wall[wall_f_idx] - f_idx;
                f_idx = wall[wall_f_idx];
            }
        }
        else if(statusQ.front() == 3) { // �ݽð� �������� �� �� ���� ����
            if(wallCnt == 0) {
                f_idx = 0;
                b_idx = -1;
                ballCnt = 0;
            }
            else {
                ballCnt -= b_idx - wall[wall_b_idx];
                b_idx = wall[wall_b_idx];
            }
        }
    }
}
