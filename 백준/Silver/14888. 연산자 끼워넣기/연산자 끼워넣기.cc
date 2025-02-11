#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> A;
vector<int> oper;
int myMin = 1000000001;
int myMax = -1000000001;

void solve(int result, int idx){
    if(idx == n){
        myMax = max(myMax,result);
        myMin = min(myMin,result);
        return ;
    }

    for(int i=0;i<4;i++){
        if(oper[i] > 0){
            oper[i]--;
            if(i ==0){
                solve(result+A[idx],idx+1);
            }
            else if(i ==1){
                solve(result-A[idx],idx+1);
            }
            else if(i ==2){
                solve(result*A[idx],idx+1);
            }
            else if(i ==3){
                solve(result/A[idx],idx+1);
            }
            oper[i]++;
        }
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    A.resize(n);
    for(int i=0;i<n;i++){
        cin >> A[i];
    }
    oper.resize(4);
    for(int i=0;i<4;i++){
        cin >> oper[i];
    }
    solve(A[0],1);

    cout << myMax << "\n" << myMin <<"\n";



    return 0;
}


