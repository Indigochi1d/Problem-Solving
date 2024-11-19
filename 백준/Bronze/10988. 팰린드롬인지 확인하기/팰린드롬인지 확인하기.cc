#include <bits/stdc++.h>

using namespace std;

//문제 풀이 방식

//string으로 입력받은 문자열을 양 끝에서부터 한문자씩 비교해가는 방법을 사용


int main() {
    string input;
    bool status = true;
    cin >> input;

    for(int i=0;i<input.size();i++) {
        if(input[i] != input[input.size()-1-i]) status = false;
    }
    if(status) cout << 1;
    else cout << 0;

    return 0;
}