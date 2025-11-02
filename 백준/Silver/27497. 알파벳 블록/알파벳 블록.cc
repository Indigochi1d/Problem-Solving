#include <bits/stdc++.h>
using namespace std;


// N=100,000 -> O(N) 이하로 에 해결해야할듯
deque<char> dq;
stack<char> stk;
int cnt = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    

    for(int i=0;i<n;i++){
        int a;
        char c;

        cin >> a;
        
        if(a == 1){
            cin >> c;
            dq.push_back(c);
            stk.push('1');
            cnt++;
            continue;
        }
        if(a == 2){
            cin >> c;
            dq.push_front(c);
            stk.push('2');
            cnt++;
            continue;
        }
        if(a == 3){
            if(!cnt){
                continue;
            }
            if(stk.top() == '1'){
                dq.pop_back();
            }
            else{
                dq.pop_front();
            }
            stk.pop();
            cnt--;
        }

        
    }
    if(!cnt){
        cout << "0";
    }
    while(cnt--){
        cout << dq.front();
        dq.pop_front();
    }
    

    return 0;
}
