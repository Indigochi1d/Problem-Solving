#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, m;
    map<string, int> pocketMon1;
    map<int, string> pocketMon2;

    cin >> n >> m;
    
    // 포켓몬 이름과 번호를 저장
    string tmp;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        pocketMon1[tmp] = i+1;
        pocketMon2[i+1] = tmp;
    }

    // 문제 요청 처리
    for (int i = 0; i < m; i++) {
        cin >> tmp;
        if(atoi(tmp.c_str())==0) {
            cout << pocketMon1[tmp] << "\n";
        }
        else {
            cout << pocketMon2[atoi(tmp.c_str())] << "\n";
        }
    }

    return 0;
}
