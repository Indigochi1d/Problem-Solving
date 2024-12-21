#include <bits/stdc++.h>

using namespace std;

int T;
string s;

int main()
{
    cin >> T;
    for(int i=0;i<T;i++){
        cin >> s;
        vector<char> v;
        for(int j=0;j<s.size();j++){
            if(s[j] == '('){
                v.push_back(s[j]);
            }
            if(s[j] == ')'){
                if(v.size()){
                    v.pop_back();
                }
                else{
                    v.push_back(s[j]);
                    break;
                }
            }
        }
        if(v.size()) cout << "NO" << "\n";
        else cout << "YES" << "\n";    
        v.clear();

    }

    return 0;
}
