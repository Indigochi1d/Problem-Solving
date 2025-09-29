#include <bits/stdc++.h>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int s, n, m;
    int tmp;
    int arrSize = 0;
    cin >> s >> n >> m;

   for (int i = 0; i < n + m; i++) {
    cin >> tmp;
    if (tmp == 1) { 
        if (arrSize == s) { 
            s *= 2;
        }
        arrSize++;
    } else { 
        arrSize--;
    }
}

    cout << s;

    return 0;
}
