#include <bits/stdc++.h>

using namespace std;

int main()
{
    int start = 666;
    int n;
    cin >> n;
    while(true){
        if(to_string(start).find("666") != string::npos){
            n--;
        }
        if(n==0) break;
        start++;
    }
    cout << start<<"\n";
    return 0;
}
