#include <bits/stdc++.h>

using namespace std;

int n;
stack<int> stk;
vector<int> v;
vector<char> ch_arr;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tmp_idx = 0 , i = 1;
    cin >> n;
    v.resize(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    while(true){
        if(tmp_idx == n) break;
        if(!stk.empty() && stk.top() == v[tmp_idx]){
            stk.pop();
            ch_arr.push_back('-');
            tmp_idx++;
        }
        else{
            if(i == n+1 && stk.top() != v[tmp_idx]) break;
            stk.push(i);
            i++;
            ch_arr.push_back('+');
        }

    }
    if(stk.size()) cout << "NO\n";
    else{
        for(char c:ch_arr) cout << c << "\n";
    }

    return 0;
}


