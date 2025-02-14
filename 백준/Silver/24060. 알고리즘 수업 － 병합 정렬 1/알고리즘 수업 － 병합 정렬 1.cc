#include <bits/stdc++.h>

using namespace std;

int cnt = 0;
int result = -1;

void merge(vector<int> &arr,int p,int q,int r,int k){
    int i = p;
    int j = q+1;
    int t = 0;
    vector<int> tmp(r-p+1);

    while(i<= q && j <= r){
        if(arr[i] <= arr[j]){
            tmp[t++] = arr[i++];
        }
        else{
            tmp[t++] = arr[j++];
        }
    }
    while(i<=q){
        tmp[t++] = arr[i++];
    }
    while(j<=r){
        tmp[t++] = arr[j++];
    }
    for(i=p,t=0;i<=r;i++,t++){
        arr[i] = tmp[t];
        cnt++;
        if(cnt == k){
            result = arr[i];
        }
    }
}

void merge_sort(vector<int> &arr,int p,int r,int k){
    if(p<r){

        int q = (p+r) /2;
        merge_sort(arr,p,q,k);
        merge_sort(arr,q+1,r,k);
        merge(arr,p,q,r,k);
    }
}



int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> arr;
    int n,k;

    cin >> n >> k;

    arr.resize(n);

    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    merge_sort(arr,0,n-1,k);

    cout << result << "\n";


    return 0;
}