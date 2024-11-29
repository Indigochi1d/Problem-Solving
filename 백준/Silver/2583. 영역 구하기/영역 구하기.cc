#include <bits/stdc++.h>

using namespace std;

const int MAX_V = 100;
int M, N, K;
bool visited[MAX_V][MAX_V] = {0};
int paper[MAX_V][MAX_V];
vector<pair<int, int>> left_top;
vector<pair<int, int>> right_down;
const int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
int nx, ny;
int cntOfArea = 0;
vector<int> results;

void input()
{
    cin >> M >> N >> K;
    int x1, y1, x2, y2;
    for (int i = 0; i < K; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        left_top.push_back({y1, x1});
        right_down.push_back({y2, x2});
    }
}
int dfs(int startY, int startX, int size)
{
    visited[startY][startX] = 1;
    for (int i = 0; i < 4; i++)
    {
        nx = startX + dx[i];
        ny = startY + dy[i];
        if (nx < 0 || nx >= N || ny < 0 || ny >= M || visited[ny][nx] || paper[ny][nx])
            continue;
        size = dfs(ny, nx, size + 1);
    }
    return size;
}
void paintSquare(int y1, int x1, int y2, int x2)
{
    for (int i = y1; i < y2; i++)
    {
        for (int j = x1; j < x2; j++)
        {
            paper[i][j] = 1;
        }
    }
}
void simulation()
{
    for (auto i = 0; i < left_top.size(); i++)
    {
        auto [lt_y, lt_x] = left_top[i];
        auto [rd_y, rd_x] = right_down[i];

        paintSquare(lt_y, lt_x, rd_y, rd_x);
    }
    // ---여기까지 완벽 ,출력도 확인----
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (visited[i][j] == 0 && paper[i][j] == 0)
            {
                int sizeofArea = dfs(i, j, 1);
                cntOfArea++;
                results.push_back(sizeofArea);
            }
        }
    }
    sort(results.begin(),results.end());
}
int main()
{
    input();
    simulation();

    cout << cntOfArea << "\n";
    for(int res:results){
        cout << res << " ";
    }
    cout << "\n";

    return 0;
}
