#include <bits/stdc++.h>

// 문제 풀이 순서
// 1. 입력받은 문자열 순회
// 2. 알파벳일 경우 + 13
//     2.1 대문자일때
//         2.1.1 오버플로우 되었을 때 -26
//     2.2 소문자일때
//         2.2.1 오버플로우 되었을 때 -26
// 3. 아닐경우 냅두기

using namespace std;
int main() {

    string input,result="";
    getline(cin,input);

    for(int i=0;i<input.size();i++) {
        //2.1 대문자일때
        if('A'<= input[i] && input[i] <= 'Z') {
            int tmpChar = input[i]+13;
            //2.1.1 오버플로우 되었을 때 -26
            if(tmpChar > 'Z') tmpChar -= 26;
            result += static_cast<char>(tmpChar);
        }
        //2.2 소문자일때
        if('a'<= input[i] && input[i] <= 'z') {
            int tmpChar = input[i]+13;
            // 2.2.1 오버플로우 되었을 때 -26
            if(tmpChar > 'z') tmpChar -= 26;
            result += static_cast<char>(tmpChar);
        }
        if(!isalpha(input[i])) result += input[i];
    }
    cout << result;

    return 0;
}