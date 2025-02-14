#include <bits/stdc++.h>

using namespace std;

int countArr[10001];  // 숫자 1~10,000의 등장 횟수를 저장

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, num;
    cin >> n;

    // 등장 횟수 저장
    for (int i = 0; i < n; i++) {
        cin >> num;
        countArr[num]++;
    }

    // 정렬된 결과 출력
    for (int i = 1; i <= 10000; i++) {
        while (countArr[i]--) {  // i가 등장한 횟수만큼 출력
            cout << i << '\n';
        }
    }

    return 0;
}
