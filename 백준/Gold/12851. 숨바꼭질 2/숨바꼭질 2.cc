#include <bits/stdc++.h>

using namespace std;
const int MAX = 100000;
int n, k;
int visited[MAX + 1];
long long cnt[MAX + 1];
void bfs(int node)
{
    queue<int> q;
    q.push(node);
    visited[node] = 1;
    cnt[node] = 1;
    while (q.size())
    {
        int now = q.front();
        q.pop();
        for (int next : {now + 1, now - 1, now * 2})
        {
            if (0 <= next && next <= MAX)
            {
                if (!visited[next])
                {
                    q.push(next);
                    visited[next] = visited[now] + 1;
                    cnt[next] += cnt[now];
                }
                else if (visited[next] == visited[now] + 1)
                {
                    cnt[next] += cnt[now];
                }
            }
        }
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
        cout << 0 << "\n"
             << 1 << "\n";
        return 0;
    }
    bfs(n);
    cout << visited[k] - 1 << "\n"
         << cnt[k] << "\n";

    return 0;
}
