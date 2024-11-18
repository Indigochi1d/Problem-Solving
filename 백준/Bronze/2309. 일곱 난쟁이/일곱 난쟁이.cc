#include <bits/stdc++.h>

using namespace std;

// 문제 접근 사고
//
// 어떻게 난쟁이 키의 합을 100으로 만들지?
// 9명중에 7명을 "뽑아야"함
// 순서? 상관 없어 -> 조합으로 만들 수 있겠다
// 조합 combination
// 9C7 일 때 sum = 100을 찾자
// 정답이 여러가지인 경우에 아무거나 출력하라고 했으니 순열도 가능하겠구나


// 문제 풀이 순서
// 1. 입력
// 2. 오름차순으로 아홉 난쟁이 정렬
// 3. 순열을 만들고 키의 합이 100일때까지 순열을 찾음
// 4. 키의 합이 100이라면 break되었으니 n->7까지 출력

int main() {
    int n = 9;
    int height[n];
    // 1. 입력
    for(int i =0; i<n;i++) {
        cin >> height[i];
    }
    // 2. 오름차순으로 아홉 난쟁이 정렬
    sort(height,height+9);
    // 3. 순열을 만들고 키의 합이 100일때까지 순열을 찾음
    do {
        int sum = 0;
        for(int i = 0; i< 7; i++) {
            sum += height[i];
        }
        if(sum == 100) break;
    }while(next_permutation(height,height+9));
    // 4. 키의 합이 100이라면 break되었으니 n->7까지 출력
    for(int i=0;i<7;i++) {
        cout << height[i] << endl;
    }


    return 0;
}
