#include <bits/stdc++.h>

using namespace std;

int n, s;
vector<int> v;
int cnt;

void dfs(int idx, int sum, int cnt_elements) {
    if(idx == n) {
        if(sum == s && cnt_elements > 0) {
            cnt++;
        }
        return;
    }
    
    // 현재 원소를 포함
    dfs(idx + 1, sum + v[idx], cnt_elements + 1);
    
    // 현재 원소를 미포함
    dfs(idx + 1, sum, cnt_elements);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> s;
    v.resize(n);
    
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    
    dfs(0, 0, 0);
    
    cout << cnt << "\n";
    
    return 0;
}
