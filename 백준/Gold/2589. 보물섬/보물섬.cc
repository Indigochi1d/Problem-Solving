#include <bits/stdc++.h>

using namespace std;

int garo, sero;
char world[51][51];
int visited[51][51];
int maxValue = 0;

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
void bfs(int y, int x)
{
    memset(visited, 0, sizeof(visited));
    visited[y][x] = 1;
    queue<pair<int, int>> q;
    q.push({y, x});
    while (q.size())
    {
        tie(y, x) = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= garo || ny < 0 || ny >= sero)
                continue;
            if (visited[ny][nx])
                continue;
            if (world[ny][nx] == 'W')
                continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny, nx});
            maxValue = max(maxValue, visited[ny][nx]);
        }
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> sero >> garo;
    for (int i = 0; i < sero; i++)
    {
        for (int j = 0; j < garo; j++)
        {
            cin >> world[i][j];
        }
    }
    for (int i = 0; i < sero; i++)
    {
        for (int j = 0; j < garo; j++)
        {
            if (world[i][j] == 'L')
            {
                bfs(i, j);
            }
        }
    }
    cout << maxValue - 1 << "\n";
    return 0;
}
