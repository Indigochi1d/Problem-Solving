#include <bits/stdc++.h>

using namespace std;

int n, A, B, aSum, bSum, team;
string t, tmp;

string makeTimeStamp(int value)
{
    string m = "00" + to_string(value / 60);
    string s = "00" + to_string(value % 60);

    return m.substr(m.size() - 2, 2) + ":" + s.substr(s.size() - 2, 2);
}

int changeToInt(string s)
{
    return atoi(s.substr(0, 2).c_str()) * 60 + atoi(s.substr(3, 2).c_str());
}

void solve(int &sum, string s)
{
    sum += changeToInt(s) - changeToInt(tmp);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> team >> t;
        if (A > B)
            solve(aSum, t);
        else if (A < B)
            solve(bSum, t);
        team == 1 ? A++ : B++;
        tmp = t;
    }
    if (A > B)
        solve(aSum, "48:00");
    else if (A < B)
    {
        solve(bSum, "48:00");
    }

    cout << makeTimeStamp(aSum) << "\n";
    cout << makeTimeStamp(bSum);

    return 0;
}
