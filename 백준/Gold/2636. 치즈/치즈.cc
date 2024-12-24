#include <bits/stdc++.h>

using namespace std;

int n, m;
int pan[100][100];
bool visited[100][100];
int timeSum = 0;
vector<int> remain;
int firstTime;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
vector<pair<int, int>> willMeltList;

void input()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> pan[i][j];
            if (pan[i][j] == 1)
                firstTime++;
        }
    }
}

void dfs(int y, int x)
{
    visited[y][x] = true;
    if (pan[y][x] == 1)
    {
        willMeltList.push_back({y, x});
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (0 > nx || nx >= m || 0 > ny || ny >= n || visited[ny][nx])
            continue;
        dfs(ny, nx);
    }
    return;
}

void doIteration()
{
    int tmp = 0;
    if (willMeltList.size())
    {
        for (pair<int, int> value : willMeltList)
        {
            pan[value.first][value.second] = 0;
        }
        timeSum++;
        for (int i = 1; i < n - 1; i++)
        {
            for (int j = 1; j < m - 1; j++)
            {
                if (pan[i][j] == 1)
                {
                    tmp++;
                }
            }
        }

        remain.push_back(tmp);
        willMeltList.clear();
    }
}

bool checkAllMelted()
{
    bool flag = true;
    for (int i = 1; i < n - 1; i++)
    {
        for (int j = 1; j < m - 1; j++)
        {
            if (pan[i][j] != 0)
            {
                flag = false;
                return flag;
            }
        }
    }
    return flag;
}

int main()
{
    input();
    while (!checkAllMelted())
    {
        fill(&visited[0][0], &visited[0][0] + 100 * 100, 0);
        willMeltList.clear();
        dfs(0, 0);
        doIteration();
    }

    cout << timeSum << "\n";

    if (timeSum == 1)
    {
        cout << firstTime << "\n";
    }
    else
    {
        remain.pop_back();
        cout << remain.back();
    }

    return 0;
}
