#include <bits/stdc++.h>
using namespace std;

int n, m, r;
int visited[100001];       
vector<int> graph[100001];
int order = 1;             

void DFS(int start) {
    visited[start] = order++; 

    for (int node : graph[start]) {
        if (visited[node] == 0) {
            DFS(node);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> r;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // 인접 정점 오름차순 정렬
    for (int i = 1; i <= n; i++) {
        sort(graph[i].begin(), graph[i].end());
    }

    DFS(r);   

    // 문제에서 요구하는 출력
    for (int i = 1; i <= n; i++) {
        cout << visited[i] << '\n';
    }

    return 0;
}
