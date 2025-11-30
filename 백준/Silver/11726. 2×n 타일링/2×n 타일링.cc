#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    const int MOD = 10007;
    vector<int> dp(n + 1, 0);

    dp[1] = 1;
    if (n >= 2)
        dp[2] = 2;

    for (int i = 3; i <= n; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
    }

    cout << dp[n] << "\n";
    return 0;
}
