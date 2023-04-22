#define ll long long
#define for(i, n) for(int i=0; i<n; i++)
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define F first
#define S second

class Solution {
public:
    int dp[501][501];
    int help(string &s1,string &s2,int m,int n){
        if(m==0 || n==0){
            return 0;
        }
        if(dp[m][n]!=-1){
            return dp[m][n];
        }
        if(s1[m-1]==s2[n-1]){
            return dp[m][n]=1+help(s1,s2,m-1,n-1);
        }
        return dp[m][n]=max(help(s1,s2,m-1,n),help(s1,s2,m,n-1));
    }
    int minInsertions(string s) {
        int n=s.size();
        string s1=s;
        reverse(all(s1));
        memset(dp,-1,sizeof(dp));
        // cout<<s1<<" "<<s2;
        return n-help(s,s1,n,n);
    }
};


