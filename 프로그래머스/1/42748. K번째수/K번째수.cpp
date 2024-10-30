#include<bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(int i=0;i<commands.size();i++){
        vector<int> tmpArray = array;
        int start = commands[i][0]-1;
        int end = commands[i][1];
        int k = commands[i][2]-1;
        
        sort(tmpArray.begin()+start,tmpArray.begin()+end);
        answer.push_back(tmpArray[commands[i][0] + commands[i][2]-2]);
    }
    
    return answer;
}