#include <bits/stdc++.h>

using namespace std;

int visited[64][64][64];
int n, input[3];

int cases[6][3] = {
    {9, 3, 1},
    {9, 1, 3},
    {3, 1, 9},
    {3, 9, 1},
    {1, 3, 9},
    {1, 9, 3}};

struct A
{
    int a, b, c;
};

int solve(int a, int b, int c)
{
    queue<A> q;
    visited[a][b][c] = 1;
    q.push({a, b, c});
    while (q.size())
    {
        int a = q.front().a;
        int b = q.front().b;
        int c = q.front().c;
        q.pop();
        if (visited[0][0][0])
            break;
        for (int i = 0; i < 6; i++)
        {
            int na = max(0, a - cases[i][0]);
            int nb = max(0, b - cases[i][1]);
            int nc = max(0, c - cases[i][2]);
            if (visited[na][nb][nc])
                continue;
            visited[na][nb][nc] = visited[a][b][c] + 1;
            q.push({na, nb, nc});
        }
    }
    return visited[0][0][0] - 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }

    cout << solve(input[0], input[1], input[2]) << '\n';
    return 0;
}
