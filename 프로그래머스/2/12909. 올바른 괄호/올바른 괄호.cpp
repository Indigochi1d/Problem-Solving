#include <bits/stdc++.h>

using namespace std;

stack<int> stk;

bool solution(string s)
{
    bool answer = false;
    
    for(int i=0;i<s.size();i++){
        if(s[i] == '(') stk.push(0);
        else if(stk.size()){
            stk.pop();
        }
        else return answer;
    }
    if(!stk.size()) answer = true;


    return answer;
}