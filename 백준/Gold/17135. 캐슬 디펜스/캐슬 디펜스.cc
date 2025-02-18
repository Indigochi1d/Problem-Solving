#include <bits/stdc++.h>

using namespace std;

int n, m, d;
int field[20][20];
int maxValue = -1;
bool visited[20];

// 모든 적이 제거되었는지 확인하는 함수
bool isGameOver(int tmpField[20][20]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (tmpField[i][j] == 1) return false;
        }
    }
    return true;
}

// 궁수들의 공격과 적 이동을 시뮬레이션하는 함수
void simulation(vector<int> &archers) {
    int tmpField[20][20];
    memcpy(tmpField, field, sizeof(field));

    int rmEnemies = 0;

    while (true) {
        set<pair<int, int>> targets;  // 공격할 적들의 좌표를 저장하는 set

        // 각 궁수별로 적을 찾아서 공격 대상 선정
        for (int archer : archers) {
            int closestDist = d + 1;
            int targetX = -1;
            int targetY = -1;

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (tmpField[i][j] == 1) {  // 적이 있는 경우
                        int dist = abs(i - n) + abs(j - archer);  // 궁수와의 거리 계산
                        if (dist <= d) {  
                            // 더 가까운 적을 찾거나, 거리가 같다면 왼쪽에 있는 적을 선택
                            if (dist < closestDist || (dist == closestDist && j < targetX)) {
                                closestDist = dist;
                                targetX = j;
                                targetY = i;
                            }
                        }
                    }
                }
            }

            // 공격 대상이 결정된 경우 추가
            if (targetX != -1 && targetY != -1) {
                targets.insert({targetY, targetX});
            }
        }

        // 궁수들의 공격이 끝난 후, 적을 한꺼번에 제거
        for (auto t : targets) {
            if (tmpField[t.first][t.second] == 1) {
                tmpField[t.first][t.second] = 0;
                rmEnemies++;
            }
        }

        // 모든 적이 제거되었으면 종료
        if (isGameOver(tmpField)) break;

        // 적 이동 (아래로 한 칸 이동)
        for (int i = n - 1; i > 0; i--) {
            for (int j = 0; j < m; j++) {
                tmpField[i][j] = tmpField[i - 1][j];
            }
        }

        // 맨 윗줄(새로운 적이 생기는 줄)은 항상 0으로 초기화
        for (int j = 0; j < m; j++) {
            tmpField[0][j] = 0;
        }
    }

    maxValue = max(maxValue, rmEnemies);
}

// 궁수의 위치를 조합으로 선택하는 함수
void solve(int cnt, vector<int> &archers) {
    if (cnt == 3) {
        simulation(archers);
        return;
    }
    for (int i = 0; i < m; i++) {
        if (!visited[i]) {
            visited[i] = true;
            archers.push_back(i);
            solve(cnt + 1, archers);
            archers.pop_back();
            visited[i] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> d;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> field[i][j];
        }
    }

    vector<int> archers;
    solve(0, archers);

    cout << maxValue << "\n";

    return 0;
}

// 코드 쓰기 전 풀이 계획
// 재귀로 궁수의 위치에 대해 완전탐색 
// 초기의 상태 어느곳에 저장시켜놓고 궁수의 위치가 바뀔때 초기화
// 궁수의 위치가 특정되었을 때 적의 이동과 궁수의 활질을 시뮬레이션 한 후 제거한 적의 수를
// maxValue와 비교 후 업데이트