#include <bits/stdc++.h>
using namespace std;

char DQ[1000005]; // 중력 큐
int wall[1000005]; // 벽 위치 저장할 배열

int main() {
//#ifdef ONLINE_JUDGE
//  freopen("input.txt", "r", stdin);
//#endif

    ios::sync_with_stdio(0);
    cin.tie(0);

    /* 4가지 큐의 상태를 나타내는 상태 큐 */
    /* 0->기본, 1씩 증가할 때마다 시계방향으로 회전 */
    /* status.front()가 현재 상태 */
    deque<int> statusQ;
    for(int i=0; i<4; i++) statusQ.push_back(i);

    int q, f_idx = 0, b_idx = -1; // 중력 큐에서 사용할 idx
    int wall_f_idx = 0, wall_b_idx = -1; // 벽 배열에서 사용할 idx
    int ballCnt = 0, wallCnt = 0; // 공 개수, 벽 개수
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

        // 중력 큐가 세로방향일 때
        if(statusQ.front() == 1) { // 시계 방향으로 한 번 돌린 세로
            if(wallCnt == 0) { // 벽이 하나도 없을 때
                f_idx = 0;
                b_idx = -1;
                ballCnt = 0;
            }
            else {
                ballCnt -= wall[wall_f_idx] - f_idx;
                f_idx = wall[wall_f_idx];
            }
        }
        else if(statusQ.front() == 3) { // 반시계 방향으로 한 번 돌린 세로
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
