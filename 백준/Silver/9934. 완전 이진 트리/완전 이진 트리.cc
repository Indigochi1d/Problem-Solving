#include <bits/stdc++.h>

using namespace std;

int k;
int graph[1025];
int endValue;
vector<int> asw[14];

void solve(int s, int e, int level)
{
    if (s > e)
        return;
    if (s == e)
    {
        asw[level].push_back(graph[s]);
        return;
    }
    int mid = (s + e) / 2;
    asw[level].push_back(graph[mid]);
    solve(s, mid - 1, level + 1);
    solve(mid + 1, e, level + 1);

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> k;
    int endLine = pow(2, k) - 1;
    for (int i = 0; i < endLine; i++)
    {
        cin >> graph[i];
    }
    solve(0, endLine, 0);

    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < asw[i].size(); j++)
        {
            cout << asw[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
