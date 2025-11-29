#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k;
    cin >> k;

    long long A[46], B[46];

    A[0] = 1; B[0] = 0; // "A"
    A[1] = 0; B[1] = 1; // "B"

    for (int i = 2; i <= k; i++) {
        A[i] = A[i - 1] + A[i - 2];
        B[i] = B[i - 1] + B[i - 2];
    }

    cout << A[k] << " " << B[k];
    return 0;
}
