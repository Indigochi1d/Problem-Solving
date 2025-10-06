#include <bits/stdc++.h>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    long long a, b;

    cin >> t;
    while(t--){
        cin >> a >> b;

        string result = to_string(a * b);
        string wrongResult = "";

        while(a && b){
            wrongResult = to_string((a % 10) * (b % 10)) + wrongResult;
            a /= 10;
            b /= 10;
        }
        while(a){
            wrongResult = to_string(a % 10) + wrongResult;
            a /= 10;
        }
        while(b){
            wrongResult = to_string(b % 10) + wrongResult;
            b /= 10;
        }

        cout << (result == wrongResult) << "\n";
    }

    return 0;
}

