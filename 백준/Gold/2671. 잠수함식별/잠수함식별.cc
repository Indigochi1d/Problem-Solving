#include <bits/stdc++.h>

using namespace std;

string input;
int cur;
bool flag=true;



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> input;
    while(flag && cur < input.size()){
        if(input[cur] == '0'){      //0으로 시작했을 때
            if(input[cur+1] == '1' && cur + 1 <= input.size()){
                cur+=2;
            }
            else flag = false;
        }
        else{   // 1로 시작했을 때
            int zerocnt=0;
            while(cur<input.size() && input[++cur]=='0') zerocnt++; 
            if(zerocnt < 2 || cur == input.size()) flag = false; //100~
            else{   //100~1
                cur++;
                while(true){
                    if(cur >= input.size() || input[cur] == '0') break; // 0이 나오면 1번인지 2번인지 다시 검사 필요
                    if(cur+2 < input.size() && input.substr(cur,3) == "100") break;
                    cur++;
                }
            }
        }
    }

    string asw = flag == true ? "SUBMARINE" : "NOISE";
    cout << asw;

    return 0;
}


