//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    // int help(int price[],int j,int i,int n,vector<vector<int>> &dp){
    //     if(i==n+1){
    //         return 0;
    //     }
    //     if(dp[j][i]!=-1){
    //         return dp[j][i];
    //     }
    //     int take=help(price,i,i+1,n,dp)+price[i-j-1];
    //     int notake=help(price,j,i+1,n,dp);
    //     return dp[j][i]=max(take,notake);
    // } 
    int cutRod(int price[], int n) {
        vector<int> prev(n+2,0);
        for(int i=n;i>=1;i--){
            vector<int> curr(n+2,0);
            for(int j=n;j>=0;j--){
                int take=prev[i]+price[i-j-1];
                int notake=prev[j];
                curr[j]=max(take,notake);
            }
            prev=curr;
        }
        return prev[0];
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends