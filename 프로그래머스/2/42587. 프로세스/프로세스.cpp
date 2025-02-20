#include <bits/stdc++.h>

using namespace std;

queue<pair<int,int>> q;         //{우선순위, 인덱스}
priority_queue<int> pq;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    
    for(int i=0;i<priorities.size();i++){
        q.push({priorities[i],i});
        pq.push(priorities[i]);
    }
    
    while(q.size()){
        int priority = q.front().first;
        int idx = q.front().second;
        q.pop();
        
        if(pq.top() == priority){
            pq.pop();
            answer++;
            if(idx == location) return answer;
        }
        else{
            q.push({priority,idx});
        }
    }
    
    
    return answer;
}