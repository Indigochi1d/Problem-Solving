#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 100;
int N;
int area[MAX_N][MAX_N];
int visited[MAX_N][MAX_N] = {0};
int drownArea[MAX_N][MAX_N] = {0};
const int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
int nx, ny;
int maxheight = 0;
vector<int> resultVector;
void input()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> area[i][j];
            maxheight = max(area[i][j], maxheight);
        }
    }
}

void dfs(int Y, int X)
{
    visited[Y][X] = 1;
    for (int i = 0; i < 4; i++)
    {
        nx = X + dx[i];
        ny = Y + dy[i];
        if (0 > ny || N <= ny || 0 > nx || N <= nx || visited[ny][nx] || drownArea[ny][nx])
            continue;
        dfs(ny, nx);
    }
}

void simulation(int changingHeight)
{
    int result = 0;
    fill(&drownArea[0][0], &drownArea[0][0] + MAX_N * MAX_N, 0);
    fill(&visited[0][0], &visited[0][0] + MAX_N * MAX_N, 0);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (changingHeight >= area[i][j])
            {
                drownArea[i][j] = 1;
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (visited[i][j] == 0 && drownArea[i][j] == 0)
            {
                dfs(i, j);
                result++;
            }
        }
    }
    resultVector.push_back(result);
}
int main()
{
    int answer;
    input();
    for (int i = 0; i <= maxheight; i++)
    {
        simulation(i);
    }
    answer = *max_element(resultVector.begin(), resultVector.end());
    cout << answer;
    return 0;
}