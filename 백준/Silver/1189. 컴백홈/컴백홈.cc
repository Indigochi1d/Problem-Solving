#include <bits/stdc++.h>

using namespace std;

int r, c, k;
char _map[6][6];
bool visited[6][6];
int cnt;
int dest_x, dest_y;
int start_x, start_y;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

bool check(int y, int x)
{
    if (x < 0 || x >= c || y < 0 || y >= r)
        return false;
    if (visited[y][x])
        return false;
    if (_map[y][x] == 'T')
        return false;
    return true;
}

void solve(int y, int x, int move)
{
    if (y == dest_y && x == dest_x)
    {
        if (move == k)
        {
            cnt++;
        }
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (check(ny, nx))
        {
            visited[ny][nx] = true;
            solve(ny, nx, move + 1);
            visited[ny][nx] = false;
        }
    }
    return;
}

int main()
{
    cin >> r >> c >> k;
    dest_x = c - 1;
    dest_y = 0;
    start_x = 0;
    start_y = r - 1;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> _map[i][j];
        }
    }
    visited[start_y][start_x] = true;
    solve(start_y, start_x, 1);
    cout << cnt << "\n";

    return 0;
}
