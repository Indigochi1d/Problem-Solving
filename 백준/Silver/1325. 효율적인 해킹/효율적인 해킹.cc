#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> graph[10001];
vector<int> result;
bool visited[10001];

int dfs(int node) {
    visited[node] = true;
    int size = 1;
    for (int next : graph[node]) {
        if (!visited[next]) {
            size += dfs(next);
        }
    }
    return size;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[b].push_back(a);
    }

    int max_size = 0;

    for (int i = 1; i <= n; i++) {
        fill(visited, visited + n + 1, false);
        int size = dfs(i);
        if (size > max_size) {
            max_size = size;
            result.clear();
            result.push_back(i);
        } else if (size == max_size) {
            result.push_back(i);
        }
    }

    sort(result.begin(), result.end());
    for (int node : result) {
        cout << node << " ";
    }

    return 0;
}