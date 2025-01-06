#include <bits/stdc++.h>

using namespace std;

const int MAX = 500000;
int n, k;
int visited[2][MAX + 1];
bool ok;
int step = 1;

void bfs(int node)
{
    queue<int> q;
    visited[0][node] = 1;
    q.push(node);
    while (q.size())
    {
        k += step;
        if (k > MAX)
            break;
        if (visited[step % 2][k])
        {
            ok = true;
            break;
        }
        int qSize = q.size();
        for (int i = 0; i < qSize; i++)
        {
            int now = q.front();
            q.pop();
            for (int next : {now + 1, now - 1, now * 2})
            {
                if (next < 0 || next > MAX || visited[step % 2][next])
                    continue;

                visited[step % 2][next] = visited[(step + 1) % 2][now] + 1;
                if (next == k)
                {
                    ok = true;
                    break;
                }
                q.push(next);
            }
            if (ok)
                break;
        }
        if (ok)
            break;
        step++;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    if (n == k)
    {
        cout << 0 << "\n";
        return 0;
    }
    bfs(n);
    if (ok)
        cout << step << "\n";
    else
        cout << "-1" << "\n";

    return 0;
}
