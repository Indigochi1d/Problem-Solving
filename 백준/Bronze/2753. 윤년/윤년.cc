#include <bits/stdc++.h>

using namespace std;

int main()
{
    int k;
    cin >> k;
    if ((k % 4 == 0 && k % 100 != 0) || k % 400 == 0)
        cout << 1;
    else
        cout << 0;
    return 0;
}
