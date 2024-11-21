#include <bits/stdc++.h>

using namespace std;

// 생각해볼 문제 분기
// 1. 문자열임
// 2. 문자열이므로 크기에 따라 상황이 달라질 수 있음
// 3. pattern 문자열의 크기보다 입력문자열의 크기가 작을때는? ( ababab*cdcdcd 와 abcd)
//
// 문제 풀이 순서
//
// 1. "*" 위치 찾기
// 2. "*"가 나오기전 문자열과 나온 후 문자열을 분리(substr)
// 3. 분리한 문자열을 각각 pre, suf라고 함
// 4. pre.size + suf.size > s.size 면 "NE"출력
// 5. 아니라면 분리한 문자열의 크기만큼 입력받은 문자열에서 substr을 떼내서 비교
//     5.1 문자열.substr(0,pre.size) == pre && 문자열.substr(문자열.size()-suf.size()) == suf -> DA
//     5.2 ! -> NE

int main() {
    int n, pos;
    string pattern;
    string pre, suf;

    cin >> n;
    cin >> pattern;
    pos = pattern.find("*");
    pre = pattern.substr(0, pos);
    suf = pattern.substr(pos + 1);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (pre.size() + suf.size() > s.size()) cout << "NE\n";
        else {
            if (s.substr(0, pre.size()) == pre && s.substr(s.size() - suf.size()) == suf) cout << "DA\n";
            else cout << "NE\n";
        }
    }

    return 0;
}
