//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    void solve(int start, string &str, vector<string> &ans){
        if(start==str.size()){
            ans.push_back(str);
            return;
        }
        
        for(int i=start; i<str.size(); i++){
            swap(str[i],str[start]);
            solve( start+1, str, ans );
            swap(str[i],str[start]);         //backtracking
        }
    }
        
    vector<string> permutation(string str)
    {
        vector<string> ans;
        solve(0,str,ans);
        sort(ans.begin(),ans.end());
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends