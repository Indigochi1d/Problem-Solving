#include <bits/stdc++.h>

using namespace std;

int n;
int flowerbed[20][20];
bool visited[20][20];
int minValue = 10000;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

int groundValue(int y, int x)
{
    int value;
    value = flowerbed[y][x];

    visited[y][x] = true;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        value += flowerbed[ny][nx];
        visited[ny][nx] = true;
    }
    return value;
}

bool check(int y, int x)
{
    if (visited[y][x])
        return 0;
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= n || visited[ny][nx])
            return 0;
    }
    return 1;
}

void eraseFlower(int y, int x)
{
    visited[y][x] = 0;
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        visited[ny][nx] = 0;
    }
}

void solve(int cnt, int sum_)
{
    if (cnt == 3)
    {
        minValue = min(sum_, minValue);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (check(i, j))
            {
                solve(cnt + 1, sum_ + groundValue(i, j));
                eraseFlower(i, j);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> flowerbed[i][j];
        }
    }

    solve(0, 0);
    cout << minValue;
    return 0;
}
