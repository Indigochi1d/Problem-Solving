#include <bits/stdc++.h>

using namespace std;

int k;
char sign[9];
int visited[10];
vector<string> ret;

bool isTrue(char a,char b, char op){
    if(a < b && op == '<') return true;
    if(a > b && op == '>') return true;
    return false;
}

void solve(int idx,string num){
    if(idx == k+1){
        ret.push_back(num);
        return;
    }
    for(int i=0;i<10;i++){
        if(visited[i]) continue;
        if(idx == 0 ||  isTrue(num[idx-1],i+'0',sign[idx-1])){
            visited[i] = 1;
            solve(idx+1,num+to_string(i));
            visited[i] = 0;
        }
    }
    return ;
}


int main()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> k;
    for(int i=0;i<k;i++){
        cin >> sign[i];
    }
    solve(0,"");
    sort(ret.begin(),ret.end());
    cout << ret[ret.size()-1] << "\n" << ret[0]<<"\n";
    return 0;
}
