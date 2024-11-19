#include <bits/stdc++.h>

using namespace std;

//문제풀이방식

//직접 문자열을 뒤집어 검증하는 방식

int main() {
    string input,tmpStr;
    cin >> input;
    tmpStr = input;

    reverse(tmpStr.begin(),tmpStr.end());

    tmpStr == input ? cout << 1 : cout << 0;
    return 0;
}