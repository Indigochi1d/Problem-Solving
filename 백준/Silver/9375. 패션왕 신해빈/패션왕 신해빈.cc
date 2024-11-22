#include <bits/stdc++.h>
using namespace std;

// 문제 파악
//
// 문제를 읽어보면 경우의 수 문제임을 알 수 있음
// 따라서 각 카테고리(의상 종류)의 경우마다 +1(안입는 경우까지 포함) 한 후에 모두 안 입는경우(1)를 빼주면 될듯
//
// 문제 풀이 순서
//
// 1. map에 string,int형으로 저장
// 2. 따라서 각 카테고리(의상 종류)의 경우마다 +1(안입는 경우까지 포함) 함
// 3. 후에 모두 안 입는경우(1)를 빼주면 됨

typedef long long ll;
int main() {
    int testCase;
    int n;
    string name,category;

    cin >> testCase;
    for(int i=0;i<testCase;i++) {
        map<string,int> outfits;
        ll result = 1;
        cin >> n;
        for(int j=0;j<n;j++) {
            cin >> name >> category;
            outfits[category]++;
        }
        for(auto outfit : outfits) {
            result *= ((ll)outfit.second + 1);
        }
        result--;
        cout << result << "\n";
    }


    return 0;
}
