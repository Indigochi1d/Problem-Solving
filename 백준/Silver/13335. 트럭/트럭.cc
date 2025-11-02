#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, w, l;
    cin >> n >> w >> l;

    vector<int> bus(n);
    for(int i = 0; i < n; i++) cin >> bus[i];

    queue<int> bridge;
    for(int i = 0; i < w; i++) bridge.push(0);

    long long weightSum = 0;
    int idx = 0;
    int time = 0;

    while(!bridge.empty()) {
        time++;

        weightSum -= bridge.front();
        bridge.pop();

        if(idx < n) {
            if(weightSum + bus[idx] <= l) {
                bridge.push(bus[idx]);
                weightSum += bus[idx];
                idx++;
            } else {
                bridge.push(0);
            }
        }
    }

    cout << time << "\n";
    return 0;
}
