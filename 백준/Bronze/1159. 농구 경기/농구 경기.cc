#include <bits/stdc++.h>

using namespace std;
int main() {
    int N;
    int cnt[26]={0};
    string input,result="";
    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> input;
        cnt[input[0]-'a']++;
    }
    for(int i=0;i<26;i++) {
        if(cnt[i] >= 5) result+= i + 'a';
    }
    if(result.size()) {
        cout << result;
    }
    else {
        cout << "PREDAJA";
    }



    return 0;
}