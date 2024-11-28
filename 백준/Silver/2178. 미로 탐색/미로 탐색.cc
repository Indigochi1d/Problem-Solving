#include <bits/stdc++.h>

// 문제 풀이 순서
//  1. 문자열로 입력받아 하나씩 정수로 maze에 넣기
//  2. 최단거리를 구하는 문제이므로 BFS
//  3. visited를 int로 선언해서 전칸 + 1 로직으로 문제 풀이
using namespace std;

const int MAX = 104;
const int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
int maze[MAX][MAX];
int visited[MAX][MAX] = {0};
int x, y, nx, ny;
int n, m;
// 1
void input()
{
    string tmp;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        for (int j = 0; j < m; j++)
        {
            maze[i][j] = tmp[j] - '0';
        }
    }
}

// 2
void bfs(int startY, int startX)
{
    queue<pair<int, int>> q;
    visited[startY][startX] = 1;
    q.push({startY, startX});
    while (q.size())
    {
        tie(y, x) = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            nx = x + dx[i];
            ny = y + dy[i];
            if (nx < 0 || nx >= m || ny < 0 || ny >= n || visited[ny][nx] || maze[ny][nx] == 0)
            {
                continue;
            }
            // 3
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny, nx});
        }
    }
}

int main()
{
    input();
    bfs(0, 0);
    cout << visited[n - 1][m - 1];

    return 0;
}