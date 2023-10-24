//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
vector<int>memo;
    bool isPalindrome(string str, int i, int j) 
    {
        while (i <= j) 
        {
            if (str[i] != str[j]) 
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    int dp(string str, int i) 
    {
        int n = str.size();
        if (i == n) {
            return 0;
        }
        
        if(memo[i]!=-1)
        {
            return memo[i];
        }
        int ans = INT_MAX;
        for (int j = i; j < n; j++) 
        {
            if (isPalindrome(str, i, j)) 
            {
                ans= min(ans,dp(str, j + 1));
            }
        }
        ans+=1;
        return memo[i]=ans;
    }

    int palindromicPartition(string str) 
    {
        memo.resize(str.size(),-1);
        return dp(str, 0)-1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends