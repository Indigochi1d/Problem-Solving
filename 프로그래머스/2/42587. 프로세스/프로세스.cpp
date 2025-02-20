#include <bits/stdc++.h>

using namespace std;

priority_queue<int> pq;
queue<pair<int,int>> q;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    int size = priorities.size();
    
    for(int i=0;i<size;i++){
        pq.push(priorities[i]);
        q.push({priorities[i],i}); // 우선순위, 인덱스
    }
    
    while(!q.empty()){
        int priority = q.front().first;
        int index = q.front().second;
        q.pop();
        
        if(pq.top() == priority){
            pq.pop();
            answer++;
            if(index == location) return answer;
        }
        else{
            q.push({priority,index});
        }
    }
    
    return answer;
}