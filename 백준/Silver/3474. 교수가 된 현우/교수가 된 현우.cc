#include <bits/stdc++.h>

using namespace std;

int t;
int n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int cnt_2 = 0, cnt_5 = 0;
        cin >> n;
        for (int d2 = 2; d2 <= n; d2 *= 2)
        {
            cnt_2 += n / d2;
        }
        for (int d5 = 5; d5 <= n; d5 *= 5)
        {
            cnt_5 += n / d5;
        }

        cout << min(cnt_2, cnt_5) << "\n";
    }

    return 0;
}
