//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
     long long dp[55][55];
    long long solve(int l,int r,string s){
        if(s[l]=='0')return INT_MAX;
        if(dp[l][r]!=-1)return dp[l][r];//if already computed the answer for range l->r
        if(l==r)return 1;// case l==r and ==1
        long long a=0,cnt=0;
        for(int i=r;i>=l;i--,cnt++){
            if(s[i]=='0')continue;
            a+=pow(2,cnt);
        }
        //a=value of binary string from l to r
        bool yes=true;
        while(a>1){
            if(a%5){
                yes=false;
                break;
            }
            a/=5;
        }
        //check if a is a power of 5
        long long ans=INT_MAX;
        if(yes){//if a is a power of 5
            return dp[l][r]=1;
        }
        // else: continue cutting from l->i and i+1->r for each i
        for(int i=l;i<r;i++){
            if(s[i+1]=='1')ans=min(ans,solve(l,i,s)+solve(i+1,r,s));
        }
        return dp[l][r]=ans;
    }
    int cuts(string s){
        memset(dp,-1,sizeof dp);
        long long ans=0;
        ans=solve(0,s.size()-1,s);
        if(ans>=INT_MAX)return -1;
        return ans;
        
    }
};

//{ Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   string s;
   while(t--)
   {
    cin>>s;
    Solution obj;
    int res=obj.cuts(s);
    cout<<res<<endl;

   }


    return 0;
}

// } Driver Code Ends