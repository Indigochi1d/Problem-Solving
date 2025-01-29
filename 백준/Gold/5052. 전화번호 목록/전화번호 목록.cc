#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<string> s(n);

        for (int i = 0; i < n; i++) {
            cin >> s[i];
        }

        // 1. 사전순 정렬
        sort(s.begin(), s.end());

        // 2. 인접한 두 개만 비교하여 접두사 검사
        bool flag = true;
        for (int i = 0; i < n - 1; i++) {
            if (s[i + 1].substr(0, s[i].size()) == s[i]) { // 접두사 체크
                flag = false;
                break;
            }
        }

        cout << (flag ? "YES\n" : "NO\n");
    }

    return 0;
}
