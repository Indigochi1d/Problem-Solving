#include <bits/stdc++.h>
using namespace std;


string input,bomb;
stack<char> st;
string tmp,asw;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> input >> bomb;
    for(char c:input){
        st.push(c);
        if(st.size() >= bomb.size() && c == bomb[bomb.size()-1]){
            tmp = "";

            for(int i=0;i<bomb.size();i++){
                tmp += st.top();
                st.pop();
            }
        
            reverse(tmp.begin(),tmp.end());

            if(tmp != bomb){
                for(char t:tmp){
                    st.push(t);
                }
            }
        }
    }
    
    if(!st.size()){
        cout << "FRULA";
    }
    else{
        while(!st.empty()){
            asw.push_back(st.top());
            st.pop();
        }
        reverse(asw.begin(),asw.end());
        cout << asw;
    }

    return 0;
}

// 1. 스택에 문자 넣음
// 2. 스택에 폭탄 문자열의 마지막 문자가 들어오면 폭탄 문자열의 크기만큼 스택에서 빼냄
// 3. 검사
// 4. 폭탄문자열이 맞으면 그대로 제거(아무것도 안해줌) , 틀리면 다시 스택에 넣어줌
