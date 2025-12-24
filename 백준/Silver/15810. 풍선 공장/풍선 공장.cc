#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<int> times;
int n,m;
ll result = 0;

ll countBallons(ll value){
    ll sum = 0;
    for(int time:times){
        sum += value / time;
    }

    return sum;
}

void binarySearch(){
    ll left = 0;
    ll right = 1000000000000;

    while(left<=right){
        ll mid = (left+right)/2;
        if(countBallons(mid) < m){
            left = mid + 1;
        }
        else{
            result = mid;
            right = mid -1;
        }   
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    times.resize(n);
    for(int i=0;i<n;i++){
        cin >> times[i];
    }
    binarySearch();

    cout << result << "\n";

    return 0;
}
