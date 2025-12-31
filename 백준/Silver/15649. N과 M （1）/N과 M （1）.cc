#include <bits/stdc++.h>

using namespace std;

int n,m;
vector<int> asw;
vector<bool> visited;

void dfs(){
    if(asw.size() == m){
        for(int a:asw){
            cout << a << " ";
        }
        cout << "\n";
        return;
    }
    for(int i=1;i<n+1;i++){
        if(visited[i]) continue;
        visited[i] = true;
        asw.push_back(i);
        dfs();
        visited[i] = false;
        asw.pop_back();
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    visited.resize(n+1,false);
    cin >> n >> m;

    dfs();

    return 0;
}
