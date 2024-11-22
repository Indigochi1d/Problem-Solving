#include <bits/stdc++.h>

using namespace std;

// 문제 접근 방식
//
//
// 불가능한 경우를 먼저 찾아보자.
// 불가능한 경우는 AAA BBB 이렇게 알파벳의 길이가 홀수인게 2번 생기면 불가능하다.
// 반대로 가능한 경우는 2번 미만으로 생기면 된다.
//
// 문제 풀이 방식
// 1. 입력받은 문자열을 순회하며 알파벳의 등장 빈도 배열을 저장
// 2. 불가능한 경우 판별 -> 등장 빈도배열을 순회하며 홀수면 flag++;
// 3. 사전순으로 출력해야하므로 배열의 뒤에서부터 앞으로 순회
//     3.1 flag가 2보다 크다면 바로 I'm Sorry Hansoo 출력
//     3.2 알파벳이 등장한다면 
//         3.2.1 짝수번 등장
//             해당 알파벳을 아스키 코드상 값으로 찾아냄
//             result 문자열에 앞뒤로 해당 알파벳을 붙임
//         3.2.2 홀수번 등장
//             해당 알파벳을 아스키 코드상 값으로 찾아냄
//             result 문자열에 앞뒤로 해당 알파벳을 붙임
//             이때 한개의 알파벳은 무조건 남는데 이 알파벳은 가운데위치로 들어가야함
//             따라서 그 알파벳을 다음 반복문에서 순회하며 찾을 수 있게 한개만 남기고 다 빼줌
// 4. 알파벳 등장 빈도 배열을 순회하며 3.2.2 에서 남긴 알파벳이 있다면 그 알파벳을 가운데에 넣어줌
// 5. 출력 





int main() {
    string input;
    string result;
    int alphabets[26] = {0};
    int flag = 0;

    cin >> input;
    for (char c: input) {
        alphabets[c - 'A']++;
    }
    for (int cnt: alphabets) {
        if (cnt % 2 != 0) flag++;
    }
    for (int i = 25; i >= 0; i--) {
        if (flag >= 2) {
            cout << "I'm Sorry Hansoo";
            break;
        }
        if (alphabets[i]) {
            if (alphabets[i] % 2 == 0) {
                for (int j = 0; j < alphabets[i]; j += 2) {
                    char word = (char) (i + 'A');
                    result = word + result;
                    result += word;
                }
            } else {
                if (alphabets[i] > 2) {
                    int k = 0;
                    for (int j = 0; j < alphabets[i]-1; j += 2) {
                        char word = (char) (i + 'A');
                        result = word + result;
                        result += word;
                        k = j;
                    }
                    alphabets[i] -= k;
                }
            }
        }
    }
    for (int i = 0; i < 26 && flag < 2; i++) {
        if (alphabets[i] % 2 == 1) {
            string newResult, tmp1, tmp2;
            tmp1 = result.substr(0, result.size() / 2);
            tmp2 = result.substr((result.size() / 2));
            newResult += tmp1;
            newResult += (char) (i + 'A');
            newResult += tmp2;
            result = newResult;
            break;
        }
    }
    if (flag < 2) cout << result << "\n";

    return 0;
}
