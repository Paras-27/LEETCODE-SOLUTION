//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	    string FirstNonRepeating(string s){
          queue<char>q;
          unordered_map<char,int>mp;
          q.push(s[0]);
          mp[s[0]]=1;
          string res(1,s[0]);
          for(int i=1;i<s.length();i++)
          {
              mp[s[i]]++;
              if(mp[s[i]]==1)
              {
                  q.push(s[i]);
              }
              while(mp[q.front()]!=1&&!q.empty())
              {
                  q.pop();
              }
              if(!q.empty())
              {
                  res+=q.front();
              }
              else
               {
                   res+="#";
               }
          }
          return res;
        }

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends