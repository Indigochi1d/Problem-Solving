#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> posts; 

    while (N--) {
        string cmd;
        cin >> cmd;

        if (cmd == "order") {
            int n, t;
            cin >> n >> t;
            posts.push_back({n, t});
        } 
        if (cmd == "sort") {
            sort(posts.begin(), posts.end(), [](auto &a, auto &b) {
                if (a.second == b.second) return a.first < b.first;
                return a.second < b.second;
            });
        } 
        if (cmd == "complete") {
            int n;
            cin >> n;
            posts.erase(remove_if(posts.begin(), posts.end(),
                                  [&](auto &p) { return p.first == n; }),
                        posts.end());
        }

        if (posts.empty()) {
            cout << "sleep\n";
        } 
        else {
            for (int i = 0; i < posts.size(); i++) {
                cout << posts[i].first;
                if (i != posts.size() - 1) cout << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}
