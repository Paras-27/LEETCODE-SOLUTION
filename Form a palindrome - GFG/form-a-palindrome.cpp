//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
  int help(string str,int i,int j,vector<vector<int>> &dp){
      if(i>j){
          return 0;
      }
      if(dp[i][j]!=-1){
          return dp[i][j];
      }
      int left=INT_MAX;
      int right=INT_MAX;
      int both=INT_MAX;
      int take=INT_MAX;
      if(str[i]!=str[j]){
          left=help(str,i,j-1,dp)+1;
          right=help(str,i+1,j,dp)+1;
          both=2+help(str,i+1,j-1,dp)+2;
      }
      else{
          take=help(str,i+1,j-1,dp);
      }
      return dp[i][j]=min({left,right,both,take});
  }
    int findMinInsertions(string str){
        vector<vector<int>> dp(str.size(),vector<int> (str.size(),-1));
        return help(str,0,str.size()-1,dp);
    }
};

//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.findMinInsertions(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends