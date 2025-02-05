#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> arr;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    int tmp;
    for(int i=0;i<n;i++){
        cin >> tmp;
        arr.push_back(tmp);
    }
    sort(arr.begin(),arr.end());
    for(int a:arr){
        cout << a << "\n";
    }

    return 0;
}
