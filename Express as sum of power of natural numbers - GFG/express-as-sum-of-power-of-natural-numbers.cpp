//{ Driver Code Starts
// Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    long long tabulate(int n, vector<int>& power, vector<vector<int>>& dp) {
        int m=power.size();
        
        for(int i=0; i<=m; ++i) {
            dp[0][i]=1;
        }
        
        for(int i=1; i<=n; ++i) {
            for(int j=m-1; j>=0; --j) {
                long long pick=0,non_pick=0;
                if(i-power[j]>=0) {
                    pick=dp[i-power[j]][j+1];
                }
                non_pick=dp[i][j+1];
                dp[i][j]=(pick+non_pick)%1000000007;
            }
        }
        return dp[n][0];
    }
    long long memoize(int n, vector<int>& power, int i, vector<vector<int>>& dp) {
        
        if(n==0) {
            return 1;
        }
        if(n<0 or i==power.size()) {
            return 0;
        }
        if(dp[n][i]!=-1) {
            return dp[n][i];
        }
        
        long long pick=memoize(n-power[i],power,i+1,dp);
        long long non_pick=memoize(n,power,i+1,dp);
        
        return dp[n][i]=(pick+non_pick)%1000000007;
    }
    int numOfWays(int n, int x)
    {
        // code here
        vector<int> power;
        int i=1, p=pow(i,x);
        while(p<=n) {
            power.push_back(p);
            i++;
            p=pow(i,x);
        }
        vector<vector<int>> dp(n+1,vector<int>(power.size()+1,0));
        return tabulate(n,power,dp);
        return memoize(n,power,0,dp);
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int  n, x;
        cin >> n >> x;
        Solution ob;
        cout<<ob.numOfWays(n, x)<<endl;
    }
    return 0;
}

// } Driver Code Ends