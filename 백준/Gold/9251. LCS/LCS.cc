#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
    cout.tie(NULL);

    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    s1 = " " + s1;
    s2 = " " + s2;

    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n, vector<int>(m, 0));

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (s1[i] == s2[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    cout << dp[n - 1][m - 1] << "\n";
    return 0;
}
