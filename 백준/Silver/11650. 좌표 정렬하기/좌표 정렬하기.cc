#include <bits/stdc++.h>

using namespace std;

int n;
vector<pair<int,int>> v;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int x,y;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> x >> y;
        v.push_back({x,y});
    }
    sort(v.begin(),v.end());
    for(pair<int,int> vv:v){
        cout << vv.first << " " << vv.second << "\n";
    }
    return 0;
}
