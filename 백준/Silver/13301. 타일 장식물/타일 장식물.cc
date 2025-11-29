#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
ll dp[81];

ll fillFibo(int num){
    if(dp[num] != -1) return dp[num];

    if(num == 1 || num == 0) return 1;

    dp[num] = fillFibo(num-2) + fillFibo(num-1);

    return dp[num];
}

ll getPerimeter(ll small,ll big){
    return (small + big) * 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    fill(dp, dp+n+1,-1);

    fillFibo(n);
    dp[0] = 1;
    dp[1] = 1;

    if(n == 1){
        cout << getPerimeter(1,1);
        return 0;
    }

    cout << getPerimeter(dp[n-1],dp[n-2]+dp[n-1]);

    return 0;
}
