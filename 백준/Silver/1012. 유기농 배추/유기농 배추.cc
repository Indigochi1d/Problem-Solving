#include <bits/stdc++.h>

using namespace std;

// 문풀 방식
// 1. 입력받아 배추밭 채우기
// 2. 배추 component를 찾아서 dfs돌림
// 3. 테스트 케이스마다 달라져야하므로 초기화 진행

const int MAX_N = 50, MAX_M = 50;
bool cabageField[MAX_N][MAX_M];
bool visited[MAX_N][MAX_M] = {0};
int T;
int N, M, K;
int X, Y;
int worm = 0;
int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
int nx, ny;
void input()
{
    cin >> M >> N >> K;
    for (int i = 0; i < K; i++)
    {
        cin >> X >> Y;
        cabageField[Y][X] = 1;
    }
}

void dfs(int startY, int startX)
{
    visited[startY][startX] = 1;
    for (int i = 0; i < 4; i++)
    {
        nx = startX + dx[i];
        ny = startY + dy[i];
        if (nx < 0 || nx >= M || ny < 0 || ny >= N || visited[ny][nx] == 1 || cabageField[ny][nx] == 0)
            continue;
        dfs(ny, nx);
    }
}

int main()
{
    cin >> T;
    while (T--)
    {
        input();
        worm = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (visited[i][j] == 0 && cabageField[i][j] == 1)
                {
                    dfs(i, j);
                    worm++;
                }
            }
        }
        cout << worm << "\n";
        fill(&visited[0][0], &visited[0][0] + MAX_N * MAX_M, 0);
        fill(&cabageField[0][0], &cabageField[0][0] + MAX_N * MAX_M, 0);
    }

    return 0;
}