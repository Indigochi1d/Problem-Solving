#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> dp(n, 0);
    dp[0] = arr[0];

    for (int i = 1; i < n; i++) {
        if (dp[i] > dp[i - 1]) {
            dp[i] = arr[i];
        } else {
            dp[i] = dp[i - 1] + arr[i];
        }
    }

    cout << *max_element(dp.begin(), dp.end()) << "\n"; 
    return 0;
}
