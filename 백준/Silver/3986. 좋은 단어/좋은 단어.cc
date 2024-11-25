#include <bits/stdc++.h>

using namespace std;

// 문제 접근 방식1: 경우 찾아보기
//
// 아치형 곡선이 생기는 경우와 안생기는 경우의 분기를 알아본다.
// 1. A,B의 개수가 홀수일때 반드시 생김
// 2. A,B의 개수가 짝수일때
//     2.1.1 AABBAA - 이렇게 끝과 끝이 같으며 동일한 글자가 연속될때
//     2.1.2 ABBAAA - 하나의 글자가 붙어있으며 다른 글자와 2칸 띄워져있을때
//     2.1.3 근데 경우의 수에 따른 분기가 너무 많지 않나..? 이 방법은 아닌듯..?
//
// 문제 접근 방식2: 스택 - 채택(스택 채택 라이밍 지렸고)
//
// 테트리스처럼 같은거 만나면 터지게 하면 되려나
//
// 1. 단어의 앞에서부터 하나의 글자씩 스택에 넣음.
//     1.1.1 같은 거 오면 pop해줌
//     1.1.2 다른 거 오면 push해줌
// 2. 스택 길이가 0이면 cnt ++ 아니면 그대로 유지

int n ,cnt=0;

string word;
int main() {
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> word;
        stack<char> s;
        for(char w:word) {
            if(s.size() == 0) {
                s.push(w);
            }
            else {
                if(s.top() == w) {
                    s.pop();
                }
                else {
                    s.push(w);
                }
            }
        }
        if(!s.size()) {
            cnt++;
        }
    }
    cout << cnt << "\n";

    return 0;
}
