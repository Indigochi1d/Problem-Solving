#include <bits/stdc++.h>

using namespace std;

const int MAX = 200000;
int n, k;
int visited[MAX + 1];
int traces[MAX + 1];
stack<int> moves;

void bfs(int node)
{
    queue<int> q;
    visited[node] = 1;
    q.push(node);
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
                    visited[next] = visited[now] + 1;
                    q.push(next);
                    traces[next] = now;
                }
            }
        }
        if (visited[k])
            break;
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
             << n << "\n";
        return 0;
    }
    bfs(n);

    int tmp = k;
    moves.push(tmp);
    while (tmp != n)
    {
        moves.push(traces[tmp]);
        tmp = traces[tmp];
    }
    cout << visited[k] - 1 << "\n";
    while (moves.size())
    {
        int out = moves.top();
        cout << out << " ";
        moves.pop();
    }
    return 0;
}
