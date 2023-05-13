#define mod 1000000007
#define ll long long
class Solution {
public:
    ll int zero,one;
    ll int help(int &low,int &high,int num,vector<ll int> &dp){
        if(num>high) return 0;
        if(dp[num]!=-1){
            return dp[num];
        }
        ll int z=help(low,high,num+zero,dp);
        ll int o=help(low,high,num+one,dp);
        return dp[num]=(z+o+(num>=low && num<=high))%mod;
        // cout<<ans<<" ";
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        this->zero=zero;
        this->one=one;
        vector<ll int> dp(high+1,-1);
        return help(low,high,0,dp);
    }
};