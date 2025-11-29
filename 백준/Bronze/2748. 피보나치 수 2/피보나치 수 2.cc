#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[91];

ll getFibo(int num){
    if(dp[num] != -1) return dp[num];

    if(num == 1) return 1;
    if(num == 0) return 0;

    dp[num] = getFibo(num - 2) + getFibo(num - 1);

    return dp[num];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;


    fill(dp,dp+n+1,-1);
    cout << getFibo(n);

    return 0;
}
