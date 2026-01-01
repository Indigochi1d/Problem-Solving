#include <bits/stdc++.h>

using namespace std;

int n;
int answer = 0;
vector<int> board;

bool check(int x){
    for(int i=0;i<x;i++){
        if(board[i] == board[x] || abs(board[x]-board[i]) == abs(x-i)) return false;
    }
    return true;
}

void solve(int x){
    if(x==n) {
        answer++;
        return;
    }
    for(int i=0;i<n;i++){
        board[x] = i;
        if(check(x)){
            solve(x+1);
        }
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    
    board.resize(n);

    solve(0);

    cout << answer << "\n";
    
    return 0;
}
