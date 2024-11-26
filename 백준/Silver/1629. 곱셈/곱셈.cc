#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
ull a, b, c;

ull go(ull a, ull b) {
    if (b == 1) {
        return a % c;
    }
    ull result = go(a, b / 2);
    result = result * result % c;
    if (b % 2 == 1) {
        result = result * a % c;
    }
    return result;
}

int main() {
    cin >> a >> b >> c;
    ull result = go(a,b);
    cout << result << "\n";

    return 0;
}
