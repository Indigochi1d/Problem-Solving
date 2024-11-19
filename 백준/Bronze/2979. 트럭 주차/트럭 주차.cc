#include <bits/stdc++.h>

using namespace std;
//문제 풀이 순서
// 1.
//  트럭이 도착해 있는 수 배열 정립
// 2.
//  배열의 값에 따라 cost 값 정립

int main() {
    int countingTrucks[100] ={0};
    int A,B,C;
    int cost = 0;
    int arrive,left;

    cin >> A >> B >> C;
    for(int i=0;i<3;i++) {
        cin >> arrive >> left;
        for(int j=arrive;j<left;j++) countingTrucks[j]++;
    }
    for(int i=0;i<100;i++) {
        if(countingTrucks[i] == 1) cost += A;
        if(countingTrucks[i] == 2) cost += B * 2;
        if(countingTrucks[i] == 3) cost += C * 3;
    }

    cout << cost;
    return 0;
}