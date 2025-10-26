#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    cin >> s;
    vector<char> st;

    for (char c : s) {
        st.push_back(c);
        int n = st.size();
        if (n >= 4 && st[n - 4] == 'P' && st[n - 3] == 'P' && st[n - 2] == 'A' && st[n - 1] == 'P') {
            for (int i = 0; i < 4;i++){
                st.pop_back();
            }
            st.push_back('P');
        }
    }

    if (st.size() == 1 && st[0] == 'P')
        cout << "PPAP\n";
    else
        cout << "NP\n";

    return 0;
}
