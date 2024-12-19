#include <bits/stdc++.h>

using namespace std;

int n;
long long c;
long long arr[1000];
map<int, int> mp, ordered_mp;
vector<pair<int, int>> vec;
void input()
{
    cin >> n >> c;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        mp[arr[i]]++;
        if (ordered_mp[arr[i]] == 0)
        {
            ordered_mp[arr[i]] = i + 1;
        }
    }
}

bool compare(pair<int, int> a, pair<int, int> b)
{
    if (a.first == b.first)
    {
        return ordered_mp[a.second] < ordered_mp[b.second];
    }
    return a.first > b.first;
}

void solve()
{
    for (auto v : mp)
    {
        vec.push_back({v.second, v.first});
    }
    sort(vec.begin(), vec.end(), compare);
    for (auto v : vec)
    {
        for (int i = 0; i < v.first; i++)
        {
            cout << v.second << " ";
        }
    }
}
int main()
{
    input();
    solve();
    return 0;
}
