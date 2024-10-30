#include <bits/stdc++.h>

using namespace std;
vector<int> makeSplittedArray(vector<int>array,int start,int end){
    vector<int> splittedArray;
    for(int i=start-1;i<end;i++){
        splittedArray.push_back(array[i]);
    }
    return splittedArray;
}

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(vector<int> command : commands){
        vector<int> tmpArray;
        tmpArray = makeSplittedArray(array,command[0],command[1]);
        sort(tmpArray.begin(),tmpArray.end());
        answer.push_back(tmpArray[command[2]-1]); 
    }
    return answer;
}