#include <bits/stdc++.h>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    queue<pair<int, int>> bridge;  // (트럭 무게, 다리 위에서 머문 시간)
    int time = 0, bridge_weight = 0, index = 0;

    while (index < truck_weights.size() || !bridge.empty()) {
        time++;

        // (1) 다리에서 나갈 트럭 체크
        if (!bridge.empty() && bridge.front().second == time) {
            bridge_weight -= bridge.front().first;
            bridge.pop();
        }

        // (2) 새로운 트럭이 다리에 올라갈 수 있는지 체크
        if (index < truck_weights.size() && 
            bridge_weight + truck_weights[index] <= weight &&
            bridge.size() < bridge_length) {
            bridge.push({truck_weights[index], time + bridge_length});
            bridge_weight += truck_weights[index];
            index++;
        }
    }
    
    return time;
}
