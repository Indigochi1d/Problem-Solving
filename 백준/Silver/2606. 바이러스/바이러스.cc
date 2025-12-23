#include <bits/stdc++.h>
using namespace std;

int n,m;
int cnt = 0;
vector<int> graph[101];
bool visited[101];

void DFS(int start){
    visited[start] = true;
    cnt++;
    for(int node: graph[start]){
        if(!visited[node]){
            DFS(node);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for(int i=1;i<m+1;i++){
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    DFS(1); 
    cout << cnt - 1 << "\n";


    return 0;
}
