#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n,m;
ll maxValue=-1;
vector<int> trees;

ll binary_Search(){
    ll low=0;
    ll high = trees[n-1];

    while(low<=high){
        ll sum=0;
        ll mid = (low+high)/2;
        for(int i=0;i<n;i++){
            if(trees[i] - mid > 0){
                sum+=trees[i]-mid;
            }
        }
        if(sum >= m){
            low = mid+1;
            if(mid > maxValue){
                maxValue = mid;
            }
        }
        else{
            high = mid-1;
        }
    }
    return maxValue;
}


int main(){
    cin >> n >> m;
    trees.resize(n);
    for(int i=0;i<n;i++){
        cin >> trees[i];
    }
    sort(trees.begin(),trees.end());
    ll answer = binary_Search();
    cout << answer;

    return 0;
}