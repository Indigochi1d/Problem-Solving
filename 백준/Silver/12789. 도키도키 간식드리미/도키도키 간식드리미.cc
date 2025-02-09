#include <bits/stdc++.h>

using namespace std;

int n;
stack<int> store;
queue<int> students;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int order = 1;
    int tmp;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> tmp;
        students.push(tmp);
    }
    while(order != n+1){
        if(students.size() && students.front() == order){
            students.pop();
            order++;
        }
        else{
            if(!store.empty() && store.top() == order){
                store.pop();
                order++;
            }
            else{
                if(!students.empty()){
                    store.push(students.front());
                    students.pop();
                }                    
                else
                    break;
            }
        }
    }
    if(store.size()) cout << "Sad\n";
    else cout << "Nice\n";    

    return 0;
}
