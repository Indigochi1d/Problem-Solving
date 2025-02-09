#include <bits/stdc++.h>

using namespace std;

int n;
stack<int> st;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int order;
    int num;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> order;
        if(order == 1 ){
            cin >> num;
            st.push(num);
        }
        else if(order == 2){
            if(st.empty()){
                cout << -1 << "\n";
            }
            else{
                cout << st.top() << "\n";
                st.pop();
            }
        }
        else if(order == 3){
            cout << st.size() << "\n";
        }
        else if(order == 4){
            if(st.empty()){
                cout << 1 << "\n";
            }
            else{
                cout << 0 << "\n";
            }
        }
        else if(order == 5){
            if(st.empty()) cout << -1 << "\n";
            else cout << st.top()<<"\n";
        }
    }


    return 0;
}
