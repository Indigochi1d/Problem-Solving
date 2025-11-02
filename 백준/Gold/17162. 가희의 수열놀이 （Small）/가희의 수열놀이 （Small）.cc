#include <bits/stdc++.h>
using namespace std;

int Q,mod;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> Q >> mod;

    vector<int> arr[100];
    for(int i=0;i<Q;i++){
        int a;
        cin >> a;
        if(a==1){
            int num;
            cin >> num;
            arr[num%mod].push_back(i);
        }
        else if(a==2){
            int max = -1, position=-1;
            for(int j=0;j<mod;j++){
                if(arr[j].empty()){
                    continue;
                }
                if(arr[j].back() > max){
                    max = arr[j].back();
                    position = j;
                }
            }
            if(position != -1){
                arr[position].pop_back();
            }
            continue;
        }
        else{
            bool flag=false;
            int min = INT_MAX;
            for(int j=0;j<mod;j++){
                if(arr[j].empty()){
                    flag = true;
                    break;
                }
                if(arr[j].back() < min){
                    min = arr[j].back();
                }
            }
            if(flag){
                cout << -1 << "\n";
                continue;
            }
            int cnt = 0;
			for (int j = 0; j < mod; j++)
				cnt += arr[j].end() - lower_bound(arr[j].begin(), arr[j].end(), min);

			cout << cnt << '\n';
        }
    }
    
   
    return 0;
}
