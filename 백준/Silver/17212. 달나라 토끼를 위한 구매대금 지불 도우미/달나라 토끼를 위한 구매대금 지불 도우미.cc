#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MAX = INT_MAX;

int N, dp[100001];

int main()
{
    ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    dp[1]=1; dp[2]=1;
    dp[3]=2; dp[4]=2;
    dp[5]=1; dp[6]=2; dp[7]=1; 

    for(int i=8; i<=N; i++)
    {
        dp[i] = min({dp[i-1], dp[i-2], dp[i-5], dp[i-7]}) + 1; 
    }
    cout << dp[N];

    return 0;
}
