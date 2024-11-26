#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int n;

int main() {
    while (scanf("%d", &n) != EOF) {
        ll number = 1, result = 1;
        while (true) {
            if (number % n == 0) {
                cout << result << "\n";
                break;
            } else {
                number = (number * 10 + 1) % n;
                result++;
            }
        }
    }

    return 0;
}
