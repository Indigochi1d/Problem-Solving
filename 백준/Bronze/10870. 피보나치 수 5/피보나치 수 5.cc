#include <bits/stdc++.h>
using namespace std;


int getFibo(int num){
    if(num == 0) return 0;
    if(num == 1) return 1;

    return getFibo(num - 1) + getFibo(num - 2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    cout << getFibo(n);
   
    return 0;
}
