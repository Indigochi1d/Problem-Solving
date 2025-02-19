#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    int check=0;
    int idx = 0;
    int size = progresses.size();
    bool flag=false;
    vector<int> answer;
    
    while(idx < size){
        for(int i=0;i<size;i++){
            progresses[i] += speeds[i];
        }
        while(progresses[idx] >= 100){
            if(idx == size) break;
            idx++;
            check++;
            flag = true;
        }
        
        if(flag){
            answer.push_back(check);
            check = 0;
            for(int a:answer){
                cout << a << " ";
            }
            flag = false;
        }  
    }
    
    
    return answer;
}