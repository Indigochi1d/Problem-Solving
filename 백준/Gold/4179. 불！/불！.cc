#include <bits/stdc++.h>

using namespace std;

const int INF = 90909090;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};

int x, y;
int r, c;
char maze[1001][1001];
int fire[1001][1001], person[1001][1001];
int startX, startY;
int answer;

bool in(int y, int x)
{
    return 0 <= x && x < c && 0 <= y && y < r;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    queue<pair<int, int>> q;

    cin >> r >> c;
    fill(&fire[0][0], &fire[0][0] + 1001 * 1001, INF);
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> maze[i][j];
            if (maze[i][j] == 'F')
            {
                fire[i][j] = 1;
                q.push({i, j});
            }
            else if (maze[i][j] == 'J')
            {
                startX = j;
                startY = i;
            }
        }
    }

    while (q.size())
    {
        tie(y, x) = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (!in(ny, nx))
                continue;
            if (fire[ny][nx] != INF || maze[ny][nx] == '#')
                continue;
            fire[ny][nx] = fire[y][x] + 1;
            q.push({ny, nx});
        }
    }

    person[startY][startX] = 1;
    q.push({startY, startX});
    while (q.size())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        if (y == 0 || y == r - 1 || x == 0 || x == c - 1)
        {
            answer = person[y][x];
            break;
        }
        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (!in(ny, nx))
                continue;
            if (person[ny][nx] > 0 || maze[ny][nx] == '#')
                continue;
            if (fire[ny][nx] <= person[y][x] + 1)
                continue;
            person[ny][nx] = person[y][x] + 1;
            q.push({ny, nx});
        }
    }

    if (answer == 0)
    {
        cout << "IMPOSSIBLE\n";
    }
    else
    {
        cout << answer << "\n";
    }
    return 0;
}
