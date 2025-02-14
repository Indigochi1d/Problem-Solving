#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll swapCnt;

int n;

void merge(vector<int> &arr,int left,int mid,int right){
    int i = left;
    int j = mid+1;
    int k = 0;

    vector<int> tmp(right-left+1);

    while(i <= mid && j <= right){
        if(arr[i] <= arr[j]) tmp[k++] = arr[i++];
        else {
            tmp[k++] = arr[j++];
            swapCnt += (mid-i+1);
        }
    }

    while(i <= mid) tmp[k++] = arr[i++];
    while(j <= right) tmp[k++] = arr[j++];

    for(int i=0;i<tmp.size();i++){
        arr[left+i] = tmp[i];
    }


}

void mergeSort(vector<int>& arr,int left,int right){
    if(left<right){
        int mid = (left+right)/2;
        mergeSort(arr,left,mid);
        mergeSort(arr,mid+1,right);
        merge(arr,left,mid,right);
    }

}

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    mergeSort(arr,0,n-1);
    
    cout << swapCnt << "\n";
    return 0;
}