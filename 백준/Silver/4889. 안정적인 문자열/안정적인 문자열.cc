#include <bits/stdc++.h>
using namespace std;

string s;
stack<char>st;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int index=1;
	while(cin>>s)
	{
		int cnt=0;
		if(s[0]=='-') break;
			for(int i=0;i<s.size();i++)
			{
				if(s[i]=='{') st.push(s[i]);
				else if(s[i]=='}')
				{
					if(!st.empty() && st.top()=='{') st.pop();
					else st.push(s[i]);
				}
			}
			while(!st.empty())
			{
				char c1 = st.top();
				st.pop();
				char c2 = st.top();
				st.pop();
				if(c1!=c2) cnt+=2;
				else cnt+=1;
				
			}
			cout<< index <<"."<<' '<<cnt<<'\n';
			index++;
		}


    return 0;
}
