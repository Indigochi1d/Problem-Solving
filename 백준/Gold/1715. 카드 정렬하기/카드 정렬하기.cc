#include <bits/stdc++.h>

using namespace std;

int n;
int sum;
priority_queue<int,vector<int>,greater<int>> pq;

void merge(vector<int> &arr,int left,int mid,int right){
    int i = left;
    int j = mid+1;
    int k=0;

    vector<int> tmp(right-left+1);

    while(i<=mid && j <= right){
        if(arr[i] <= arr[j]) tmp[k++] = arr[i++];
        else tmp[k++] = arr[j++];
    }
    while(i<=mid) tmp[k++] = arr[i++];
    while(j<=right) tmp[k++] = arr[j++];

    for(int i=0;i<tmp.size();i++){
        arr[i+left] = tmp[i];
    }

}

void mergeSort(vector<int> &arr,int left,int right){
    if(left< right){
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
    vector<int> cards(n);

    for(int i=0;i<n;i++){
        cin >> cards[i];
    }

    for(int i=0;i<n;i++) pq.push(cards[i]);

    while(pq.size() > 1){
        int first = pq.top(); pq.pop();
        int second = pq.top(); pq.pop();

        int cost = first + second;
        sum += cost;

        pq.push(cost);
    }

    cout << sum;

    return 0;
}


 
// 정렬된 두 묶음의 숫자 카드 -> A - B  -> 합병정렬<O(nlogn)> + 그리디 탐색<O(n)>  or 우선순위큐(최소힙)
//
// 10 20 40
// 10 + 20 | 10 + 20 + 40