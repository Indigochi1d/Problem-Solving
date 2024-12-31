#include <bits/stdc++.h>

using namespace std;

int n, m;
int adj[50][50];
int result = 9999999;
vector<pair<int, int>> houseLoc, chickenLoc;
vector<vector<int>> chickenIdxList;

int getDistance(int y1, int x1, int y2, int x2)
{
    return abs(x1 - x2) + abs(y1 - y2);
}

void combination(int start, vector<int> v)
{
    if (v.size() == m)
    {
        chickenIdxList.push_back(v);
        return;
    }
    for (int i = start + 1; i < chickenLoc.size(); i++)
    {
        v.push_back(i);
        combination(i, v);
        v.pop_back();
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> adj[i][j];
            if (adj[i][j] == 1)
            {
                houseLoc.push_back({i, j});
            }
            if (adj[i][j] == 2)
            {
                chickenLoc.push_back({i, j});
            }
        }
    }
    vector<int> v;
    combination(-1, v);
    for (vector<int> cList : chickenIdxList)
    {
        int sum = 0;
        for (pair<int, int> house : houseLoc)
        {
            int answer = 9999999;
            for (int c : cList)
            {
                int distance = getDistance(house.first, house.second, chickenLoc[c].first, chickenLoc[c].second);
                answer = min(answer, distance);
            }
            sum += answer;
        }
        result = min(result, sum);
    }
    cout << result << "\n";

    return 0;
}
