#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> cards, M;

void input() {
    cin >> n;
    cards.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> cards[i];
    }
    cin >> m;
    M.resize(m);
    for (int i = 0; i < m; i++) {
        cin >> M[i];
    }
}

int count_by_binary_search(int k) {
    int left_idx = lower_bound(cards.begin(), cards.end(), k) - cards.begin();
    int right_idx = upper_bound(cards.begin(), cards.end(), k) - cards.begin();
    return right_idx - left_idx; // k의 개수
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    sort(cards.begin(), cards.end());

    for (int i = 0; i < m; i++) {
        cout << count_by_binary_search(M[i]) << " ";
    }
    cout << "\n";
    return 0;
}
