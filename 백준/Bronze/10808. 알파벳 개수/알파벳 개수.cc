#include <bits/stdc++.h>

using namespace std;

int main() {
    string input;
    int cnt[26] = {0};

    cin >> input;
    for(char c : input) {
        char root = 'a';
        cnt[c-root] += 1;
    }

    for(int value : cnt) {
        cout << value << " ";
    }
    return 0;
}