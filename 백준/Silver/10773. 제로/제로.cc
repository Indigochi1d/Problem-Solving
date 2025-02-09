#include <bits/stdc++.h>

using namespace std;

int k;
stack<int> stk;
int sum=0;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> k;
    for(int i=0;i<k;i++){
        cin >> t;
        if(t==0){
            stk.pop();
        }
        else stk.push(t);
    }
    while(!stk.empty()){
        sum += stk.top();
        stk.pop();
    }

    cout << sum << "\n";

    return 0;
}
