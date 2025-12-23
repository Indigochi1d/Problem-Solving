#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int> arr;
vector<int> indc;

bool binarySearch(int value){
    int left = 0;
    int right = n-1;
    while(left<=right){
        int mid = (left+right)/2;
        if(arr[mid] == value){
            return true;
        }
        else if(arr[mid] < value){
            left = mid+1;
        }
        else{
            right = mid-1;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        arr.push_back(a);
    }
    sort(arr.begin(),arr.end());

    cin >> m;
    for(int i=0;i<m;i++){
        int b;
        cin >> b;
        indc.push_back(b);
    }

    for(int k:indc){
        if(binarySearch(k)){
            cout << "1" << "\n";
        }
        else{
            cout << "0" << "\n";
        }
    }
    return 0;
}


// 이 문제를 보고 이분탐색을 떠올려야하는 이유는 보통 탐색을 하려면 O(NxM) 이 드는데 이게 6자리 수를 넘어버림
// 그래서 반드시 한번 탐색에 O(N) 이하의 시간복잡도를 가지는 알고리즘을 써야함. -> 이분탐색
// 이분탐색 조건은 배열이 정렬되어있어야할것
// 정렬 하는데 (sort) -> O(NlogN), 탐색에 O(NlogN)
