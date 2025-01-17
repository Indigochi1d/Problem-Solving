#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b;
    int result1, result2, result3, result4;

    cin >> a >> b;

    result4 = a * b;
    result1 = a * (b % 10);
    result2 = a * (b % 100 / 10);
    result3 = a * (b / 100);

    cout << result1 << "\n"
         << result2 << "\n"
         << result3 << "\n"
         << result4 << "\n";
    return 0;
}
