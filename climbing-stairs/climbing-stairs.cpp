class Solution {
public:
    int dp[46];
    int help(int n){
        if(n<=2){
            return n;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        return dp[n]=help(n-2)+help(n-1);
    }
    int climbStairs(int n) {
        memset(dp,-1,sizeof(dp));
        return help(n);
    }
};