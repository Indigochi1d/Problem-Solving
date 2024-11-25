#include <bits/stdc++.h>

using namespace std;

//문제 변수 범위 상황
//N: 1~15,000
//M: 1~10,000,000
//
//어떤 알고리즘을 사용해야할까?
//
//문제 풀이 방식
//
//        input: 2 7 4 1 5 3
//N개중에 2개를 뽑아서 M이 되는지 확인
//중복을 피해야함
//i로 for문돌때 내 앞까지만 검사하면 중복피할 수 있음
//
//1. 입력
//2. for문을 순회하며 내 앞까지의 값들중에 "나"와 "내 앞까지의 값"을 더했을 때 M이 나오면 cnt++;

int main() {
    int n,m;
    int cnt = 0;
    vector<int> items;
    cin >> n;
    cin >> m;

    for(int i=0;i<n;i++){
        int tmp;
        cin >> tmp;
        items.push_back(tmp);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(items[i]+items[j] == m){
                cnt++;
            }
        }
    }
    cout << cnt << "\n";
    return 0;
}