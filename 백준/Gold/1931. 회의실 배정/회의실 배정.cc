#include <bits/stdc++.h>

using namespace std;

int n;
vector<pair<int,int>> meeting;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a,b;
    cin >> n;
    
    for(int i=0;i<n;i++){
        cin >> a >> b;
        meeting.push_back({a,b});
    }
    sort(meeting.begin(),meeting.end(),[](pair<int,int> a,pair<int,int> b){
        if(a.second == b.second) return a.first < b.first;
        return a.second < b.second;
    });
    int time = meeting[0].second;
    int cnt = 1;
    for(int i=1;i<n;i++){
        if(meeting[i].first >= time){
            time = meeting[i].second;
            cnt++;
        }
    }
    cout << cnt << "\n";

    return 0;
}


// 그리디 유형의 이 문제를 풀며 가장 중요했던 건 
// <어떤 것을 "탐욕적" 으로 볼 것인가>
// 이 문제에선 <끝나는 시간> 이었음
// 왜냐하면 끝나는 시간이 짧아야 회의의 개수를 늘릴 수 있기 때문
