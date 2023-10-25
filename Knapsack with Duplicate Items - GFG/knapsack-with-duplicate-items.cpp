//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int solve(int index,int N, int W, int val[], int wt[],vector<vector<int>>&dp)
    {
        if(index>=N)
        {
            return 0;
        }
        
        if(dp[index][W]!=-1)
        {
            return  dp[index][W];
        }
        
        int take = INT_MIN;
        
        if(W-wt[index]>=0)
        {
            take = val[index]+solve(index,N,W-wt[index],val,wt,dp);
        }
        
        int nottake = solve(index+1,N,W,val,wt,dp);
        
        return dp[index][W] = max(take,nottake);
    }
    
    int solveTab(int N, int W, int val[], int wt[])
    {
        
        vector<vector<int>>dp(N+1,vector<int>(W+1,0));
        
        
        for(int index = N-1;index>=0;index--)
        {
            for(int w=0;w<=W;w++)
            {
                int take = INT_MIN;
        
                if(w-wt[index]>=0)
                {
                    take = val[index]+dp[index][w-wt[index]];
                }
                
                int nottake = dp[index+1][w];
                
                dp[index][w] = max(take,nottake);
            }
        }
        
        return dp[0][W];
       
    }
    
    
    int solveTabOptimal(int N, int W, int val[], int wt[])
    {
        
        vector<int>curr(W+1,0);
        vector<int>next(W+1,0);
        
        
        for(int index = N-1;index>=0;index--)
        {
            for(int w=0;w<=W;w++)
            {
                int take = INT_MIN;
        
                if(w-wt[index]>=0)
                {
                    take = val[index]+curr[w-wt[index]];
                }
                
                int nottake = next[w];
                
                curr[w] = max(take,nottake);
            }
            next = curr;
        }
        
        return next[W];
       
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        
        // vector<vector<int>>dp(N+1,vector<int>(W+1,-1));
        // return solve(0,N,W,val,wt,dp);
        
         return solveTabOptimal(N,W,val,wt);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends