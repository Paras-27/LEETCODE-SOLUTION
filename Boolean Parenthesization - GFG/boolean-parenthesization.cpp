//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

const int mod=1003;
class Solution{
public:
    int help(string &s,int i,int j,int isTrue,vector<vector<vector<int>>>&dp){
        if(i>j){
            return 0;
        }
        if(dp[i][j][isTrue]!=-1){
            return dp[i][j][isTrue];
        }
        if(i==j){
            if(isTrue)
                return s[i]=='T';
            else
                return s[i]=='F';
        }
        int ans=0;
        for(int k=i+1;k<j;k+=2){
            int leftT=help(s,i,k-1,1,dp);
            int leftF=help(s,i,k-1,0,dp);
            int rightT=help(s,k+1,j,1,dp);
            int rightF=help(s,k+1,j,0,dp);
            if(s[k]=='&'){
                if(isTrue)
                    ans=(ans+ (leftT*rightT) %mod)%mod;
                else
                    ans=(ans+((leftF*rightF)%mod + (rightT*leftF)%mod + (rightF*leftT)%mod))%mod;
            }
            else if(s[k]=='|'){
                if(isTrue)
                    ans=(ans+((leftT*rightT)%mod + (rightT*leftF)%mod + (rightF*leftT)%mod))%mod;
                else
                    ans=(ans+ (leftF*rightF) %mod)%mod;
            }
            else{
                if(isTrue)
                    ans=(ans+((leftF*rightT)%mod + (rightF*leftT)%mod))%mod;
                else
                    ans=(ans+((leftT*rightT)%mod + (rightF*leftF)%mod))%mod;
            }
        }
        return dp[i][j][isTrue]=ans;
    }
    int countWays(int N, string S){
        int cnt=0;
        vector<vector<vector<int>>> dp(N,vector<vector<int>>(N,vector<int>(2,-1)));
        return help(S,0,N-1,1,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends