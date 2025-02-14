#include <bits/stdc++.h>

using namespace std;


int n,m,cnt;
int city[201][1001];
vector<int> trip;
vector<int> visited;

void dfs(int k){
    visited[k] = 1;
    for (int i = 0; i < n; i++) {
        if (city[k][i] == 1 && !visited[i]) {
            dfs(i);
        }
    }
    return;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    trip.resize(m);
    visited.resize(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> city[i][j];
        }
    }
    for(int i=0;i<m;i++){
        cin >> trip[i];
        trip[i]--;
    }

    for(int i=0;i<m;i++){
        if(!visited[trip[i]]){
            cnt++;
            dfs(trip[i]);
        }
    }

    cnt == 1 ? cout << "YES\n" : cout << "NO\n";
    return 0;
}


