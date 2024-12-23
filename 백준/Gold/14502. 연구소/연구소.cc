#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int n, m;
int graph[8][8];
int tmp_graph[8][8];
int answer = 0;
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

void dfs(int x, int y)
{
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= n || ny < 0 || ny >= m)
            continue;
        if (tmp_graph[nx][ny] == 0)
        {
            tmp_graph[nx][ny] = 2;
            dfs(nx, ny);
        }
    }
}

void simulate()
{
    memcpy(tmp_graph, graph, sizeof(graph));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (tmp_graph[i][j] == 2)
            {
                dfs(i, j);
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (tmp_graph[i][j] == 0)
                cnt++;
        }
    }
    answer = max(answer, cnt);
}

void makeWall(int cnt)
{
    if (cnt == 3)
    {
        simulate();
        return;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (graph[i][j] == 0)
            {
                graph[i][j] = 1;
                makeWall(cnt + 1);
                graph[i][j] = 0;
            }
        }
    }
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> graph[i][j];
        }
    }

    makeWall(0);
    cout << answer << "\n";

    return 0;
}
