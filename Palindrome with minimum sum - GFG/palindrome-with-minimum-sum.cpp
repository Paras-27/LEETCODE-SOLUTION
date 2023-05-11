//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumSum(string s) {
        // code here
        int n=s.size();
        int l=0;
        int r=n-1;
        while(l<=r)
        {
            if(s[l]==s[r])
            {
                l++;
                r--;
            }
            else if(s[l]=='?'&&s[r]!='?')
            {
                s[l]=s[r];
                l++;
                r--;
            }
            else if(s[l]!='?'&&s[r]=='?')
            {
                s[r]=s[l];
                l++;
                r--;
            }
            else
            {
                return -1;
            }
        }
        string ns="";
        for(int i=0;i<n/2;i++)
        {
            if(s[i]!='?')
            {
               ns+=s[i];
            }
        }
        int ans=0;
        if(ns.size()>0){
        for(int i=0;i<ns.size()-1;i++)
        {
               ans+=abs(ns[i+1]-ns[i]);
        }
        }
        return ans*2;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        int ans = ob.minimumSum(s);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends