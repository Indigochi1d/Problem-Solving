#include <bits/stdc++.h>

using namespace std;

// 문제상황
// N: 1~100,000
// K: 1~100,000 - 1
// 온도 : -100 ~ 100
// 연속된 날짜의 온도의 값이 최대가 되는 값 : 구간합
//
// 문제풀이방식
//
// 구간합으로 "최대값"을 구하는 문제
// 최솟값부터 선정 후 max로 비교해나간다.
//
// 최솟값은? -100도가 10만번 -> 10,000,001정도?
//
// 1. 구간합 구하기
// 2. 특정 구간합 구하기
//     2.1 특정 구간합을 구하는 방식은 (현재위치까지의 구간합 - 특정구간합의 크기)
//

int main() {
    int n,k,tmp,psum[100001]={0},result = -10000001;
    cin >> n >> k;
    for(int i=1;i<=n;i++) {
        cin >> tmp;
        psum[i] = psum[i-1] + tmp;
    }
    for(int i=k;i<=n;i++) {
        result = max(result,psum[i]-psum[i-k]);
    }
    cout << result;

    return 0;
}
