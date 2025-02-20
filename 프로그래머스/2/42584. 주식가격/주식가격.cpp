#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> prices) {
    int size = prices.size();
    vector<int> answer;
    
    for(int i=0;i<size;i++){
        int cnt=0;
        for(int j=i+1;j<size;j++){
            cnt++;
            if(prices[i] > prices[j]) break;
        }
        answer.push_back(cnt);
    }
    

    return answer;
}