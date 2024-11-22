#include <bits/stdc++.h>

using namespace std;

int main() {
    string input;
    string result;
    int alphabets[26] = {0};
    int flag = 0;

    cin >> input;
    for (char c: input) {
        alphabets[c - 'A']++;
    }
    for (int cnt: alphabets) {
        if (cnt % 2 != 0) flag++;
    }
    for (int i = 25; i >= 0; i--) {
        if (flag >= 2) {
            cout << "I'm Sorry Hansoo";
            break;
        }
        if (alphabets[i]) {
            if (alphabets[i] % 2 == 0) {
                for (int j = 0; j < alphabets[i]; j += 2) {
                    char word = (char) (i + 'A');
                    result = word + result;
                    result += word;
                }
            } else {
                if (alphabets[i] > 2) {
                    int k = 0;
                    for (int j = 0; j < alphabets[i]-1; j += 2) {
                        char word = (char) (i + 'A');
                        result = word + result;
                        result += word;
                        k = j;
                    }
                    alphabets[i] -= k;
                }
            }
        }
    }
    for (int i = 0; i < 26 && flag < 2; i++) {
        if (alphabets[i] % 2 == 1) {
            string newResult, tmp1, tmp2;
            tmp1 = result.substr(0, result.size() / 2);
            tmp2 = result.substr((result.size() / 2));
            newResult += tmp1;
            newResult += (char) (i + 'A');
            newResult += tmp2;
            result = newResult;
            break;
        }
    }
    if (flag < 2) cout << result << "\n";

    return 0;
}
