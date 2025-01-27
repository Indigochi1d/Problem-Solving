#include <bits/stdc++.h>

using namespace std;

string s,t;


void solve(){

    while(cin >> s >> t){
        int s_idx = 0;
        string answer = "";
        for(int i=0;i<t.size();i++){
            if(s_idx == s.size()) break;
            if(s[s_idx] == t[i]){
                answer+= t[i];
                s_idx++;
            }
        }
        if(s.compare(answer) == 0){
            cout << "Yes\n";
        }
        else{
            cout << "No\n";
        }
    }
}

int main(){
    
    solve();

    return 0;
}
