#include<bits/stdc++.h>
 
using namespace std;
 
int n, m;
long long ans = LLONG_MAX;
 
vector<int> input;
 
long long calc(int mid) {
    long long sum = 0;
    for(int i = 0; i < n; i++) {
        if(input[i] > mid)
            sum += input[i] - mid;
    }
    return sum;
}
 
long long binarySearch() {
    int low = 0;
    int high = input[n - 1];
    int mid;
 
    while(low <= high) {
        mid = (low + high) / 2;
 
        long long temp = calc(mid);
 
        if(temp >= m) {
            low = mid+1;
        }
        else {
            high = mid-1;
        }
    }
 
    return high;
}
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        input.push_back(a);
    }
 
    sort(input.begin(), input.end());
 
    cout << binarySearch();
}